#ifndef BUF_GATE_H
#define BUF_GATE_H
#include "Node.h"
class BufGate : public Node{
public:
    BufGate():Node(){}
    BufGate(string theName):Node(theName){}
    BufGate(string theName, Node* LN):Node(theName, "Buf", LN, nullptr){}
    ~BufGate(){/* do nothing */}
    void evaluate()override;
};
#endif