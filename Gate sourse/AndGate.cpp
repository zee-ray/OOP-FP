#include "AndGate.h"
int AndGate::evaluate(map<string,Gate*> allGate){
    if(left->get_val() == -1){
        left->set_val( allGate[left->get_name()]->evaluate(allGate) );
    }
    if(right->get_val() == -1){
        right->set_val( allGate[right->get_name()]->evaluate(allGate) );
    }
    return AND[right->get_val()][left->get_val()];
}