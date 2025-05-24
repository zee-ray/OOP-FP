#ifndef XOR_GATE_H
#define XOR_GATE_H
#include "Node.h"
class XorGate : public Node{
public:
    XorGate():Node(){}
    XorGate(string theName):Node(theName){}
    XorGate(string theName, Node* LN, Node* RN):Node(theName, "Xor", LN, RN){}
    ~XorGate(){/* do nothing */}
    void evaluate()override;
};
#endif