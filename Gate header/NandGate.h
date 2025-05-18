#ifndef NAND_GATE_H 
#define NAND_GATE_H
#include "Gate.h"
class NandGate : public Gate{
public:
    NandGate():Gate(){}
    NandGate(string theName, Node* LN, Node* RN):Gate(theName, "Nand", LN, RN){}
    int evaluate(map<string,Gate*> allGate)override;
};
#endif