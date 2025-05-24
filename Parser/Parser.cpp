#include "Parser.h"
#include "allGate.h"
void Parser::ParseNetlist(ifstream& netlist_fin, map<string,Node*>& InputNode, map<string,Node*>& OutputNode, map<string,Node*>& allNode){
    string str;

    // module FA(A, B, Cin, S, Cout);
    getline(netlist_fin,str); 
    // netlist_fin.ignore(10,'\n');

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
            // can i igore this part??
            bool finish = false;
            while(1){
                netlist_fin>>str;
                if(str[str.length()-1] == ';'){
                    str = str.substr(0,str.length()-1);  //ignore ';' 
                    Node* the_node = new Node(str);
                    // add to allNode
                    allNode[str] = the_node;
                    finish = true;
                    break;
                }else{
                    str = str.substr(0,str.length()-1);  //ignore ',' 
                    Node* the_node = new Node(str);
                    // add to allNode
                    allNode[str] = the_node;
                }
            }
            if(finish)  break;
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
        // first check if the gate has been set before
        if(allNode[gate_name]->get_type() != ""){
            cout<<"Error: there are multi-driver nets!!!"<<endl;
        }
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
                // delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
            allNode[LName]->set_out(the_gate);
            allNode[RName]->set_out(the_gate);
        }else if(gate_type == "buf"){
            netlist_fin>>str;
            // ignore ',' and ';'
            LName = str.substr(0,str.length()-2);
            // new a BufGate ptr then delete the old ones in allNode and OutputNode if there is one
            Node* the_gate = new BufGate(gate_name,allNode[LName]);
            delete allNode[gate_name];
            allNode[gate_name] = the_gate;
            if(OutputNode.find(gate_name) != OutputNode.end()){
                // delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
            allNode[LName]->set_out(the_gate);
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
                // delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
            allNode[LName]->set_out(the_gate);
            allNode[RName]->set_out(the_gate);
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
                // delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
            allNode[LName]->set_out(the_gate);
            allNode[RName]->set_out(the_gate);
        }else if(gate_type == "not"){
            netlist_fin>>str;
            // ignore ',' and ';'
            LName = str.substr(0,str.length()-2);
            // new a NotGate ptr then delete the old ones in allNode and OutputNode if there is one
            Node* the_gate = new NotGate(gate_name,allNode[LName]);
            delete allNode[gate_name];
            allNode[gate_name] = the_gate;
            if(OutputNode.find(gate_name) != OutputNode.end()){
                // delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
            allNode[LName]->set_out(the_gate);
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
                // delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
            allNode[LName]->set_out(the_gate);
            allNode[RName]->set_out(the_gate);
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
                // delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
            allNode[LName]->set_out(the_gate);
            allNode[RName]->set_out(the_gate);
        }else if(gate_type == "xor"){
            netlist_fin>>str;
            // ignore ','
            LName = str.substr(0,str.length()-1);
            netlist_fin>>str;
            // ignore ')' and ';'
            RName = str.substr(0,str.length()-2);
            // new a XorGate ptr then delete the old ones in allNode and OutputNode if there is one
            Node* the_gate = new XorGate(gate_name,allNode[LName],allNode[RName]);
            delete allNode[gate_name];
            allNode[gate_name] = the_gate;
            if(OutputNode.find(gate_name) != OutputNode.end()){
                // delete OutputNode[gate_name];
                OutputNode[gate_name] = the_gate;
            }
            allNode[LName]->set_out(the_gate);
            allNode[RName]->set_out(the_gate);
        }
    }
    netlist_fin.close();
}
bool Parser::ParsePattern(ifstream& pattern_fin, map<string,Node*>& InputNode, const vector<string>& InputOrder){
    // the first line will be read before the function is called
    string str;
    for(auto name : InputOrder){
        pattern_fin>>str;
        if(str == ".end"){
            return false;
        }
        else if(str == "0"){
            InputNode[name]->set_val(0);
        }else if(str == "1"){
            InputNode[name]->set_val(1);
        }else if(str == "X"){
            InputNode[name]->set_val(2);
        }
        else{
            cout<<"invalid input value!!!"<<endl;
            return false;
        }
    }
    return true;
}