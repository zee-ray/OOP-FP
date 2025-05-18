#include "Parser.h"
void Parser::ParseNetlist(ifstream& netlist_fin, vector<Node*>& allNode, vector<Node*>& OutputNode, map<string,Gate*>& allGate){
    string str;
    getline(netlist_fin,str); // module FA(A, B, Cin, S, Cout);
    while(!netlist_fin.eof()){
        netlist_fin>>str;
        if(str == "input"){
            netlist_fin>>str;
            str = str.substr(0,str.length()-1);
            Node* the_node = new Node(str);  // name of the node
            allNode.push_back(the_node);
        }else if(str == "output"){
            netlist_fin>>str;
            str = str.substr(0,str.length()-1);
            Node* the_node = new Node(str);  // name of the node
            allNode.push_back(the_node);
            OutputNode.push_back(the_node);
        }else if(str == "wire"){
            bool wiredone = false;
            while(wiredone){
                netlist_fin>>str;
                if(str[str.length()-1] == ';')  wiredone = true;
                str = str.substr(0,str.length()-1);
                Node* the_node = new Node(str);  // name of the node
                allNode.push_back(the_node);
            }
        }else{
            cout<<"start reading gates"<<endl;
            break;  // start reading gates, the first gate type has been read here
        }
    }
    while(!netlist_fin.eof()){
        if(str == "and"){
            netlist_fin>>str;
            if(str[0] == '(')   str = str.substr(1);  // ignore '('
            str = str.substr(0,str.length()-1);  // ignore ','
            ****************start here*****************
        }else if(str == "buf"){

        }else if(str == "nand"){
            
        }else if(str == "nor"){
            
        }else if(str == "not"){
            
        }else if(str == "nxor"){
            
        }else if(str == "or"){
            
        }else if(str == "xor"){
            
        }else{
            cout<<"it's not a gate!"<<endl;
            break;
        }
        if(!netlist_fin.eof())  netlist_fin>>str;
    }
}
bool Parser::ParsePattern(ifstream& pat_fin, vector<Node*>& allNode){

}