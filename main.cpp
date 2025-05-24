#include "allGate.h"
#include "Parser.h"
#include <queue>
vector<Node*> TopoSort(map<string,Node*>& allNode);
void writeOutput(ofstream& output, const map<string,Node*>& OutputNode);
void deleteAllNode(map<string,Node*>& allNode);
int main(int argc, char** argv){
    // 0. set all the files and containers
    ifstream netlist_fin(argv[2]);
    ifstream pattern_fin(argv[4]);
    ofstream output(argv[6]);
    Parser parser;

    map<string,Node*> allNode;
    map<string,Node*> InputNode;
    map<string,Node*> OutputNode;

    // 1. Parse netlist
    // first add constant into allNode
    allNode["1'b0"] = new Node("1'b0", 0);
    allNode["1'b1"] = new Node("1'b1", 1);
    parser.ParseNetlist(netlist_fin,InputNode,OutputNode,allNode);
    
    // write the first line of output file
    output<<"output ";
    for(auto it=OutputNode.begin(); it != OutputNode.end();){
        output<<it->first;
        if(++it != OutputNode.end()){
            output<<", ";
        }else{
            output<<endl;
        }
    }
    // 2. TopoSort
    vector<Node*> TopoOrder = TopoSort(allNode);
    
    /*
    cout<<"topo: ";
    for(auto n : TopoOrder){
        cout<<n->get_name()<<" ";
    }
    cout<<endl;
    */

    // 3. Store the order of input
    vector<string> OrderOfInput;
    string str;
    pattern_fin>>str;  // ignore "input "
    for(int i=0; i<InputNode.size()-1; i++){
        pattern_fin>>str;
        str = str.substr(0,str.length()-1);
        OrderOfInput.push_back(str);
    }
    //read the last one
    pattern_fin>>str;
    OrderOfInput.push_back(str);

    // 4. Parse pattern & Set input wire values
    while(parser.ParsePattern(pattern_fin,InputNode,OrderOfInput)){
        // 5. Evaluate in TopoOrder
        for(int i=0; i<TopoOrder.size(); i++){
            TopoOrder[i]->evaluate();
        }

        // 6. Store output values
        // 7. write output file
        writeOutput(output,OutputNode);
    }
    
    // finish writing output file
    output<<".end";
    deleteAllNode(allNode);
    cout<<"program over"<<endl;
}

vector<Node*> TopoSort(map<string,Node*>& allNode){
    map<Node*,int> inDegree;
    queue<Node*> q;
    vector<Node*> sorted_nodes;
    int numofconst=0;
    // initialize to 0
    for (auto& node : allNode){
        if(node.second == nullptr){
          numofconst++;
          cout<<"const found";
          continue; // skip constant
        }
        inDegree[node.second] = 0;
    }
    
    // count inDegree
    for (auto& node : allNode){
        if(!node.second)  continue; // skip constant
        Node* l = node.second->get_left();
        Node* r = node.second->get_right();
        if (l != nullptr){
            inDegree[node.second]++;
        }
        if (r != nullptr){
            inDegree[node.second]++;
        }
    }
    
    // push all nodes with 0 inDegree into queue
    for (auto& node : allNode){
        if(!node.second)  continue; // skip constant
        if (inDegree[node.second] == 0){
            q.push(node.second);
        }
    }
    
    // topological sort
    while (!q.empty()){
        Node* current = q.front();
        q.pop();
        sorted_nodes.push_back(current);
        for (Node* out : current->get_out()){
            if (--inDegree[out] == 0) {
                q.push(out);
            }
        }
    }
    
    // cycle check
    if (sorted_nodes.size() != allNode.size()-numofconst){
        cout<<"Error: circuit contains a cycle!!!"<<endl;
    }
    return sorted_nodes;
}

void writeOutput(ofstream& output, const map<string,Node*>& OutputNode){
    output<<"    ";
    for(auto it=OutputNode.begin(); it != OutputNode.end();){
        if(it->second->get_val() == 2){
            output<<"X";
        }else{
            output<<it->second->get_val();
        }
        
        if(++it != OutputNode.end()){
            output<<" ";
        }else{
            output<<endl;
        }
    }
}
void deleteAllNode(map<string,Node*>& allNode){
    for(auto& node : allNode){
        delete node.second;
        node.second = nullptr;
    }
    allNode.clear();
}