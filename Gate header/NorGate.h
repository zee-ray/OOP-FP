#ifndef NOR_GATE_H
#define NOR_GATE_H
#include "Gate.h"
class NorGate : public Gate{
public:
    NorGate():Gate(){}
    NorGate(string theName, Node* LN, Node* RN):Gate(theName, "Nor", LN, RN){}
    int evaluate(map<string,Gate*> allGate)override;
};
#endif