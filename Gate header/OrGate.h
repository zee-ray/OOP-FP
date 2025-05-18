#ifndef OR_GATE_H
#define OR_GATE_H
#include "Gate.h"
class OrGate : public Gate{
public:
    OrGate():Gate(){}
    OrGate(string theName, Node* LN, Node* RN):Gate(theName, "Or", LN, RN){}
    int evaluate(map<string,Gate*> allGate) override;
};
#endif