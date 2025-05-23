#ifndef NOT_GATE_H
#define NOT_GATE_H
#include "Node.h"
class NotGate : public Node{
public:
    NotGate():Node(){}
    NotGate(string theName):Node(theName){}
    NotGate(string theName, Node* LN):Node(theName, "Not", LN, nullptr){}
    ~NotGate()override{/* do nothing */}
    int evaluate(map<string,Node*> allNode)override;
};
#endif