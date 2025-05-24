#ifndef NAND_GATE_H 
#define NAND_GATE_H
#include "Node.h"
class NandGate : public Node{
public:
    NandGate():Node(){}
    NandGate(string theName):Node(theName){}
    NandGate(string theName, Node* LN, Node* RN):Node(theName, "Nand", LN, RN){}
    ~NandGate(){/* do nothing */}
    void evaluate()override;
};
#endif