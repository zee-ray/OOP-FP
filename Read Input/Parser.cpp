#include "Parser.h"
#include "NotGate.h"
void Parser::ParseNetlist(ifstream& netlist_fin, map<string,Node*>& InputNode, map<string,Node*>& OutputNode, map<string,Node*>& allNode){
    string str;

    // module FA(A, B, Cin, S, Cout);
    getline(netlist_fin,str); 
    cin.ignore(10,'\n');

    // inside the block
    while(!netlist_fin.eof()){
        netlist_fin>>str;
        if(str == "input"){
            // read the name of the node (A,B,Cin)
            netlist_fin>>str;
            // ignore ';'
            str = str.substr(0,str.length()-1);
            // new a Node ptr with its name
            Node* the_node = new Node(str);
            // add to allNode and InputNode
            allNode[str] = the_node;
            InputNode[str] = the_node;
        }else if(str == "output"){
            // read the name of the node (S,Cout)
            netlist_fin>>str;
            // ignore ';'
            str = str.substr(0,str.length()-1);
            // new a Node ptr with its name
            Node* the_node = new Node(str);
            // add to allNode and OutputNode
            allNode[str] = the_node;
            OutputNode[str] = the_node;
        }else if(str == "wire"){
            /*
            bool wiredone = false;
            while(wiredone){
                netlist_fin>>str;
                if(str[str.length()-1] == ';')  wiredone = true;
                str = str.substr(0,str.length()-1);
                Node* the_node = new Node(str);  // name of the node
                allNode.push_back(the_node);
            }
            */

            // can i igore this part??
            getline(netlist_fin,str);
            netlist_fin.ignore(10,'\n');  
            break;
        }else{
            // useless part???
            cout<<"start reading gates"<<endl;
            break;
        }
    }
    while(!netlist_fin.eof()){
        // first read in gate type
        string gate_type;
        if(!netlist_fin.eof())  netlist_fin>>gate_type;
        // check if the netlist is over
        if(gate_type == "endmodule"){
            cout<<"finish parsing netlist"<<endl;
            break;
        }
        // then read in the output nodes (i call it a gate here)
        netlist_fin>>str;
        // ignore '(' and ','
        str = str.substr(1,str.length()-2);
        // new a gate ptr and delete the one in OutputNode and allNode
        string gate_name = str;
        string LName, RName;
        if(gate_type == "and"){
            netlist_fin>>str;
            // ignore ','
            LName = str.substr(0,str.length()-1);
            netlist_fin>>str;
            // ignore ',' and ';'
            RName = str.substr(0,str.length()-2);

            // new a AndGate ptr then delete the old ones in allNode and OutputNode if there is one
            Node* the_gate = new AndGate(gate_name,allNode[LName],allNode[RName]);
            delete allNode[gate_name];
            allNode[gate_name] = the_gate;
            if(OutputNode.find(gate_name) != OutputNode.end()){
                delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
        }else if(gate_type == "buf"){
            netlist_fin>>str;
            // ignore ',' and ';'
            LName = str.substr(0,str.length()-2);
            // new a BufGate ptr then delete the old ones in allNode and OutputNode if there is one
            Node* the_gate = new BufGate(gate_name,allNode[LName]);
            delete allNode[gate_name];
            allNode[gate_name] = the_gate;
            if(OutputNode.find(gate_name) != OutputNode.end()){
                delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
        }else if(gate_type == "nand"){
            netlist_fin>>str;
            // ignore ','
            LName = str.substr(0,str.length()-1);
            netlist_fin>>str;
            // ignore ',' and ';'
            RName = str.substr(0,str.length()-2);
            // new a NandGate ptr then delete the old ones in allNode and OutputNode if there is one
            Node* the_gate = new NandGate(gate_name,allNode[LName],allNode[RName]);
            delete allNode[gate_name];
            allNode[gate_name] = the_gate;
            if(OutputNode.find(gate_name) != OutputNode.end()){
                delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
        }else if(gate_type == "nor"){
            netlist_fin>>str;
            // ignore ','
            LName = str.substr(0,str.length()-1);
            netlist_fin>>str;
            // ignore ',' and ';'
            RName = str.substr(0,str.length()-2);
            // new a NordGate ptr then delete the old ones in allNode and OutputNode if there is one
            Node* the_gate = new NorGate(gate_name,allNode[LName],allNode[RName]);
            delete allNode[gate_name];
            allNode[gate_name] = the_gate;
            if(OutputNode.find(gate_name) != OutputNode.end()){
                delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
        }else if(gate_type == "not"){
            netlist_fin>>str;
            // ignore ',' and ';'
            LName = str.substr(0,str.length()-2);
            // new a NotGate ptr then delete the old ones in allNode and OutputNode if there is one
            Node* the_gate = new NotGate(gate_name,allNode[LName]);
            delete allNode[gate_name];
            allNode[gate_name] = the_gate;
            if(OutputNode.find(gate_name) != OutputNode.end()){
                delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
        }else if(gate_type == "nxor"){
            netlist_fin>>str;
            // ignore ','
            LName = str.substr(0,str.length()-1);
            netlist_fin>>str;
            // ignore ',' and ';'
            RName = str.substr(0,str.length()-2);
            // new a NxorGate ptr then delete the old ones in allNode and OutputNode if there is one
            Node* the_gate = new NxorGate(gate_name,allNode[LName],allNode[RName]);
            delete allNode[gate_name];
            allNode[gate_name] = the_gate;
            if(OutputNode.find(gate_name) != OutputNode.end()){
                delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
        }else if(gate_type == "or"){
            netlist_fin>>str;
            // ignore ','
            LName = str.substr(0,str.length()-1);
            netlist_fin>>str;
            // ignore ',' and ';'
            RName = str.substr(0,str.length()-2);
            // new a OrGate ptr then delete the old ones in allNode and OutputNode if there is one
            Node* the_gate = new OrGate(gate_name,allNode[LName],allNode[RName]);
            delete allNode[gate_name];
            allNode[gate_name] = the_gate;
            if(OutputNode.find(gate_name) != OutputNode.end()){
                delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
        }else if(gate_type == "xor"){
            netlist_fin>>str;
            // ignore ','
            LName = str.substr(0,str.length()-1);
            netlist_fin>>str;
            // ignore ',' and ';'
            RName = str.substr(0,str.length()-2);
            // new a XorGate ptr then delete the old ones in allNode and OutputNode if there is one
            Node* the_gate = new XorGate(gate_name,allNode[LName],allNode[RName]);
            delete allNode[gate_name];
            allNode[gate_name] = the_gate;
            if(OutputNode.find(gate_name) != OutputNode.end()){
                delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
        }else{
            cout<<"wtf is this"<<endl;
            break;
        }
    }
    netlist_fin.close();
}
// bool Parser::ParsePattern(ifstream& pat_fin, vector<Node*>& allNode){

// }