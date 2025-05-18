#ifndef NXOR_GATE_H
#define NXOR_GATE_H
#include "Gate.h"
class NxorGate : public Gate{
public:
    NxorGate():Gate(){}
    NxorGate(string theName, Node* LN, Node* RN):Gate(theName, "Nxor", LN, RN){}
    int evaluate(map<string,Gate*> allGate)override;
};
#endif