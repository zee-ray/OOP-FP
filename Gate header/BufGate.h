#ifndef BUF_GATE_H
#define BUF_GATE_H
#include "Gate.h"
class BufGate : public Gate{
public:
    BufGate():Gate(){}
    BufGate(string theName, Node* LN):Gate(theName, "Buf", LN, nullptr){}
    int evaluate(map<string,Gate*> allGate)override;
};
#endif