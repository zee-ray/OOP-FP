#include "BufGate.h"
int BufGate::evaluate(map<string,Gate*> allGate){
    if(left->get_val() == -1)   left->set_val(allGate[left->get_name()]->evaluate(allGate));
    if(left->get_val() == 3)    return 2;
    else return left->get_val();
}