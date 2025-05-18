#ifndef NOT_GATE_H
#define NOT_GATE_H
#include "Gate.h"
class NotGate : public Gate{
public:
    NotGate():Gate(){}
    NotGate(string theName, Node* LN):Gate(theName, "Not", LN, nullptr){}
    int evaluate(map<string,Gate*> allGate)override;
};
#endif