#ifndef NOR_GATE_H
#define NOR_GATE_H
#include "Node.h"
class NorGate : public Node{
public:
    NorGate():Node(){}
    NorGate(string theName):Node(theName){}
    NorGate(string theName, Node* LN, Node* RN):Node(theName, "Not", LN, RN){}
    ~NorGate()override{/* do nothing */}
    int evaluate(map<string,Node*> allNode)override;
};
#endif