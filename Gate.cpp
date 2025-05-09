#include "Gate.h"
int not(const int val);
int buf(const int val);
Gate::Gate():name(""),type(""),input1(NULL),input2(NULL){}
int Gate::gate_val(){
    int result = -1; // for debug
    if(type == "and"){
        result = and(*this);
    }else if(type == "or"){
        result = or(*this);
    }else if(type == "nand"){
        result = not(and(*this));
    }else if(type == "nor"){
        result = not(or(*this));
    }else if(type == "xor"){
        result = xor(*this);
    }else if(type == "xnor"){
        result = not(xor(*this));
    }else if(type == "not"){
        result = not(this->input1->value);
    }else if(type == "buf"){
        result = buf(this->input1->value);
    }
    return result;
}

int and(const Gate& gate){
    return AND[gate.input1->value][gate.input2->value];
}
int or(const Gate& gate){
    return OR[gate.input1->value][gate.input2->value];
}
int xor(const Gate& gate){
    return XOR[gate.input1->value][gate.input2->value];
}
int not(const Gate& gate){
    return not(gate.input1->value);
}
int not(const int val){
    switch (val)
    {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
    case 3:
        return 2;
    }
}
int buf(const Gate& gate){
    return (buf(gate.input1->value));
}
int buf(const int val){
    return (val==3)? 2:val;
}