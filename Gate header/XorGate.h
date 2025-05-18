#ifndef XOR_GATE_H
#define XOR_GATE_H
#include "Gate.h"
class XorGate : public Gate{
public:
    XorGate():Gate(){}
    XorGate(string theName, Node* LN, Node* RN):Gate(theName, "Xor", LN, RN){}
    int evaluate(map<string,Gate*> allGate)override;
};
#endif