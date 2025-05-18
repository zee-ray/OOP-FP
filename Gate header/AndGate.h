#ifndef AND_GATE_H
#define AND_GATE_H
#include "Gate.h"
class AndGate : public Gate{
public:
    AndGate():Gate(){}
    AndGate(string theName, Node* LN, Node* RN):Gate(theName, "And", LN, RN){}
    int evaluate(map<string,Gate*> allGate) override;
};
#endif