#include "allGate.h"
#include "Parser.h"
#include <regex>
#include <queue>
vector<Node*> TopoSort(map<string,Node*>& allNode);
void writeOutput(ofstream& output, map<string,Node*>& allNode, const vector<string>& OutputOrder);
void deleteAllNode(map<string,Node*>& allNode);
int main(int argc, char** argv){
    // 0. set all the files and containers
    ifstream netlist_fin(argv[2]);
    ifstream pattern_fin(argv[4]);
    ofstream output(argv[6]);
    Parser parser;

    map<string,Node*> allNode;
    map<string,Node*> InputNode;
    vector<string> OutputOrder;

    // 1. Parse netlist
    // first add constant into allNode
    allNode["1'b0"] = new Node("1'b0", 0);
    allNode["1'b1"] = new Node("1'b1", 1);
    parser.ParseNetlist(netlist_fin,InputNode,allNode, OutputOrder);
    
    // write the first line of output file
    output<<"output ";
    for(int i=0; i<OutputOrder.size();){
        output<<OutputOrder[i];
        if(++i != OutputOrder.size()){
            output<<", ";
        }else{
            output<<endl;
        }
    }
    // 2. TopoSort
    vector<Node*> TopoOrder = TopoSort(allNode);
    
    /* ====================here for test==================== */
    /*
    cout<<"topo: ";
    for(auto n : TopoOrder){
        cout<<n->get_name()<<" ";
    }
    cout<<endl;
    /* ====================here for test==================== */

    // 3. Store the order of input
    vector<string> OrderOfInput;
    string line;
    pattern_fin>>line;
    getline(pattern_fin, line);
    int start = line.find(" ");
    string input_list = line.substr(start);
    regex split("\\s*,\\s*");
    sregex_token_iterator it(input_list.begin(), input_list.end(), split, -1);
    sregex_token_iterator end;

    while(it != end){
        string nodeName = *it;
        nodeName.erase(0, nodeName.find_first_not_of(" \t\r\n"));
        nodeName.erase(nodeName.find_last_not_of(" \t\r\n") + 1);
        OrderOfInput.push_back(nodeName);
        it++;
    }
    
    // 4. Parse pattern & Set input wire values
    while(parser.ParsePattern(pattern_fin,InputNode,OrderOfInput)){
        // 5. Evaluate in TopoOrder
        for(int i=0; i<TopoOrder.size(); i++){
            TopoOrder[i]->evaluate();
        }
        // 6. Store output values
        // 7. write output file
        writeOutput(output,allNode,OutputOrder);
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
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        sorted_nodes.push_back(current);
        for(Node* out : current->get_out()){
            if(--inDegree[out] == 0){
                q.push(out);
            }
        }
    }
    
    // cycle check
    if(sorted_nodes.size() != allNode.size()-numofconst){
        cout<<"Error: circuit contains a cycle!!!"<<endl;
    }
    return sorted_nodes;
}

void writeOutput(ofstream& output, map<string,Node*>& allNode, const vector<string>& OutputOrder){
    output<<"    ";
    for(int i=0; i<OutputOrder.size();){
        string name = OutputOrder[i];
        if(allNode[name]->get_val() == 2){
            output<<"X";
        }else{
            output<<allNode[name]->get_val();
        }
        
        if(++i != OutputOrder.size()){
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