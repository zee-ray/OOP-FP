#ifndef NXOR_GATE_H
#define NXOR_GATE_H
#include "Node.h"
class NxorGate : public Node{
public:
    NxorGate():Node(){}
    NxorGate(string theName):Node(theName){}
    NxorGate(string theName, Node* LN, Node* RN):Node(theName, "Nxor", LN, RN){}
    ~NxorGate(){/* do nothing*/}
    void evaluate()override;
};
#endif