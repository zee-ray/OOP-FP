#include "XorGate.h"
int XorGate::evaluate(map<string,Node*> allNode){
    if(left->get_val() == -1){
        left->set_val( allNode[left->get_name()]->evaluate(allNode) );
    }
    if(right->get_val() == -1){
        right->set_val( allNode[right->get_name()]->evaluate(allNode) );
    }
    this->set_val(XOR[right->get_val()][left->get_val()]);
    return this->get_val();
}