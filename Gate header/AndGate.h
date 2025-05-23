#ifndef AND_GATE_H
#define AND_GATE_H
#include "Node.h"
class AndGate : public Node{
public:
    AndGate():Node(){}
    AndGate(string theName):Node(theName){}
    AndGate(string theName, Node* LN, Node* RN):Node(theName, "And", LN, RN){}
    ~AndGate() override{ /* do nothing */};
    int evaluate(map<string,Node*> allNode) override;
};
#endif