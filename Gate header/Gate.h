#include "Node.h"
#include <map>
#include <vector>
class Gate{
protected:
    int val;
    string type;
    string name;
    Node *left = NULL, *right = NULL;
public:
    Gate();
    Gate(string theName, string theType, Node* LN, Node* RN);
    // Gate(const Gate& to_copy);
    virtual int evaluate(map<string,Gate*> allGate);
};

const int AND[4][4] = {{0,0,0,0},
                       {0,1,2,2},
                       {0,2,2,2},
                       {0,2,2,2}};

const int XOR[4][4] = {{0,1,2,2},
                       {1,0,2,2},
                       {2,2,2,2},
                       {2,2,2,2}};

const int OR[4][4]  = {{0,1,2,2},
                       {1,1,1,1},
                       {2,1,2,2},
                       {2,1,2,2}};