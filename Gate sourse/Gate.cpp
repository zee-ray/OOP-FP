#include "Gate.h"
Gate::Gate(){
    val = -1;
    type = "no type";
    name = "no name";
    left = nullptr;
    right = nullptr;
}
Gate::Gate(string theName, string theType, Node* LN, Node* RN){
    val = -1;
    type = theType;
    name = theName;
    left = LN;
    right = RN;
}
/*
Gate::Gate(const Gate& to_copy){
    val = to_copy.val;
    type = to_copy.type;
    name = to_copy.name;
    left = to_copy.left;
    right = to_copy.right;
}
*/
int Gate::evaluate(map<string,Gate*> allGate){
    int result = -1;
}