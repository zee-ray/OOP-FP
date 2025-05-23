#ifndef OR_GATE_H
#define OR_GATE_H
#include "Node.h"
class OrGate : public Node{
public:
    OrGate():Node(){}
    OrGate(string theName):Node(theName){}
    OrGate(string theName, Node* LN, Node* RN):Node(theName, "Or", LN, RN){}
    ~OrGate(){/* do nothing */}
    int evaluate(map<string,Node*> allNode) override;
};
#endif