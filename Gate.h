#include<string>
using namespace std;
struct Node
{
    int value = 2;
    // 0,1,2(X),3(Z)
    string name = "";
};

class Gate
{
private:
    string name;
    string type;
    Node *input1, *input2;
public:
    Gate();
    int gate_val();
    friend int and(const Gate& gate);
    friend int or(const Gate& gate);
    friend int xor(const Gate& gate);
    friend int not(const Gate& gate);
    friend int buf(const Gate& gate);
};

// Truth Table
const int AND[4][4] = {{0,0,0,0},
                       {0,1,2,2},
                       {0,2,2,2},
                       {0,2,2,2}};
const int OR[4][4] = { {0,1,2,2},
                       {1,1,1,1},
                       {2,1,2,2},
                       {2,1,2,2}};
const int XOR[4][4] = {{0,1,2,2},
                       {1,0,2,2},
                       {2,2,2,2},
                       {2,2,2,2}};

// other functions
int not(const int val);
int buf(const int val);