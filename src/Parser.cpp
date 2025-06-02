#include "Parser.h"
#include "allGate.h"
#include <regex>
#include <sstream>
void nodeUpdate(string gate_name, Node* new_gate,map<string,Node*>& allNode){
    Node* old = allNode[gate_name];
    // let output point to new node
    for(Node* out : old->get_out()){
        if (out->get_left() == old){
            out->set_left(new_gate);
        }
        if (out->get_right() == old){
            out->set_right(new_gate);
        }
        new_gate->set_out(out);
    }
    // update to allNode
    allNode[gate_name] = new_gate;
    // delete the old node
    delete old;
    old = nullptr;
}
void Parser::ParseNetlist(ifstream& netlist_fin, map<string,Node*>& InputNode, map<string,Node*>& allNode, vector<string>& OutputOrder){
    string str;
    // module line -> module FA(A, B, Cin, S, Cout);
    getline(netlist_fin,str); 
    
    while(!netlist_fin.eof()){
        // read input, output, wire
        netlist_fin >> str;
        if(str == "input" || str == "output" || str == "wire"){
            bool is_input = (str == "input");
            bool is_output = (str == "output");
            string line;
            getline(netlist_fin, line, ';');  // G1,G2,G3,G4,G5 no ';'

            // remove space
            int start = line.find(" ");
            if(start == -1) continue; // space missing 不可能這麼噁心吧
            string node_list = line.substr(start);
            // read node_list
                    //   G1  ,   G2
            regex split("\\s*,\\s*");
            sregex_token_iterator it(node_list.begin(), node_list.end(), split, -1);
            sregex_token_iterator end;

            while(it != end){
                string nodeName = *it;
                nodeName.erase(0, nodeName.find_first_not_of(" \t\r\n"));
                nodeName.erase(nodeName.find_last_not_of(" \t\r\n") + 1);
                /* here for test */
                /*
                if (!nodeName.empty())
                    cout<<"Node = "<<nodeName << endl;
                */
                
                // new a Node ptr with its name
                Node* the_node = new Node(nodeName);
                allNode[nodeName] = the_node;
                if(is_input){
                    InputNode[nodeName] = the_node;
                }
                if(is_output){
                    OutputOrder.push_back(nodeName); // for output order
                }
                it++;
            }
        }else{
            if(str.find('(') == -1){
              string rest;
              getline(netlist_fin, rest);
              str += rest;
            }
            break; // start readnig gates
        }
    }
    
    do{
        str.erase(0, str.find_first_not_of(" \t\r\n"));
       // cout<<"cleaned str: "<<str<<endl;
        if(str.empty()) continue;  // empty line 到底會不會出現呢
        // check if the netlist is over
        if(str.substr(0, 9) == "endmodule"){
            cout<<"netlist OK"<<endl;
            break;
        }
                    //   nand          (net14,G3,G4)     ;
        regex format("(\\w+)\\s*\\(\\s*([^\\)]+)\\s*\\)\\s*;\\s?\\t?\\r?\\n?");
        smatch match;
        if(!regex_match(str, match, format)){
            cout<<"not a gate -> "<<str<<endl;
            continue;
        }
        string gate_type = match[1];
        string argv = match[2];
        /* ====================here for test==================== */
        /*
        cout<<"gate_type: "<<gate_type<<endl
            <<"argv: "<<argv<<endl;
        /* ====================here for test==================== */
        
        regex split("\\s*,\\s*");
        sregex_token_iterator it(argv.begin(), argv.end(), split, -1);
        sregex_token_iterator end;

        vector<string> argvs;
        while(it != end){
            string s = *it;
            s.erase(0, s.find_first_not_of(" \t\r\n"));
            s.erase(s.find_last_not_of(" \t\r\n") + 1);
            argvs.push_back(s);
            it++;
        } 
        string gate_name = argvs[0];
        // first check if the gate has been set already
        if(allNode[gate_name]->get_type() != ""){
            cout<<"Error: there are multi-driver nets!!!"<<endl
                <<"Original: "<<gate_name<<"->("<<allNode[gate_name]->get_left()->get_name();
            if(allNode[gate_name]->get_right()){
                cout<<","<<allNode[gate_name]->get_right()->get_name()<<")"<<endl;
            }else{
                cout<<")"<<endl;
            }
        }

        Node* the_gate;
        if(gate_type == "not"){
            the_gate = new NotGate(gate_name, allNode[argvs[1]]);
        }else if(gate_type == "buf"){
            the_gate = new BufGate(gate_name, allNode[argvs[1]]);
        }else if(gate_type == "and"){
            the_gate = new AndGate(gate_name, allNode[argvs[1]], allNode[argvs[2]]);
        }else if(gate_type == "nand"){
            the_gate = new NandGate(gate_name, allNode[argvs[1]], allNode[argvs[2]]);
        }else if(gate_type == "or"){
            the_gate = new OrGate(gate_name, allNode[argvs[1]], allNode[argvs[2]]);
        }else if(gate_type == "nor"){
            the_gate = new NorGate(gate_name, allNode[argvs[1]], allNode[argvs[2]]);
        }else if(gate_type == "xor"){
            the_gate = new XorGate(gate_name, allNode[argvs[1]], allNode[argvs[2]]);
        }else if(gate_type == "nxor"){
            the_gate = new NxorGate(gate_name, allNode[argvs[1]], allNode[argvs[2]]);
        }else{
            cout<<"what is this gate???"<<endl
                <<"->"<<gate_type<<endl;
            continue;
        }
        // replace new ptr the_gate with the old one
        nodeUpdate(gate_name, the_gate, allNode);
    }while(getline(netlist_fin,str));

    /* ====================here for test==================== */
    /*
    cout<<"All node check:"<<endl;
    for(auto& n : allNode){
        if(n.second == nullptr){
            cout<<"null for "<<n.first << endl;
            continue;
        }
        cout<<"node: "<<n.first <<" with ";
        if(n.second->get_left()){
            cout<< n.second->get_left()->get_name();
        }
        if(n.second->get_right()){
            cout<<" "<<n.second->get_right()->get_name();
        }
        cout<< endl;
    }
    /* ====================here for test==================== */
    
    netlist_fin.close();
}

bool Parser::ParsePattern(ifstream& pattern_fin, map<string,Node*>& InputNode, const vector<string>& InputOrder){
    // the first line will be read before the function is called
    string str;
    for(auto name : InputOrder){
        pattern_fin>>str;
        if(str == ".end"){
            cout<<"pattern OK"<<endl;
            return false;
        }
        else if(str == "0"){
            InputNode[name]->set_val(0);
        }else if(str == "1"){
            InputNode[name]->set_val(1);
        }else if(str == "X" || str == "x"){
            InputNode[name]->set_val(2);
        }
        else{
            cout<<"invalid input value!!!"<<endl;
            return false;
        }
    }
    cout<<"parsing pattern"<<endl;
    return true;
}
