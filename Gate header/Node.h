#ifndef NODE_H 
#define NODE_H
#include <string>
#include <vector>
#include <map>
using namespace std;
class Node
{
protected:
    int val; // for cache
    string name;
    string type;
    Node *left, *right;
public:
    Node():val(-1), name("no_name"), type(""), left(nullptr), right(nullptr){}
    Node(string theName):val(-1),name(theName),type(""),left(nullptr),right(nullptr){}
    Node(string theName, int theValue):val(theValue),name(theName),type(""),left(nullptr),right(nullptr){}
    Node(string theName, string theType, Node* left, Node* right):val(-1),name(theName),type(theType),left(left),right(right){}
    virtual ~Node(){/* do nothing */}
    void set_val(int theValue){val = theValue;}
    int get_val()const{return val;}
    void set_name(string theName){name = theName;}
    string get_name()const{return name;}
    void set_type(string theType){type = theType;}
    string get_type()const{return type;}
    void set_left(Node* leftnode){left = leftnode;}
    Node* get_left()const{return left;}
    void set_right(Node* rightnode){right = rightnode;}
    Node* get_right()const{return right;}
    virtual int evaluate(map<string,Node*> allNode);
};

/* Truth Table */
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
#endif