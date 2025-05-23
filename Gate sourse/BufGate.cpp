#include "BufGate.h"
int BufGate::evaluate(map<string,Node*> allNode){
    if(left->get_val() == -1)   left->set_val(allNode[left->get_name()]->evaluate(allNode));
    if(left->get_val() == 3)    this->set_val(2);
    else    this->set_val(left->get_val());
    return this->get_val();
}