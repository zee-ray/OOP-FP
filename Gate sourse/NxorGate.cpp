#include "NxorGate.h"
int NxorGate::evaluate(map<string,Gate*> allGate){
    int xorresult = -1;
    if(left->get_val() == -1){
        left->set_val( allGate[left->get_name()]->evaluate(allGate) );
    }
    if(right->get_val() == -1){
        right->set_val( allGate[right->get_name()]->evaluate(allGate) );
    }
    xorresult = XOR[right->get_val()][left->get_val()];
    switch(xorresult){
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
        case 3:
            return 2;
    }
}