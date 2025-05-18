#include "NotGate.h"
int NotGate::evaluate(map<string,Gate*> allGate){
    if(left->get_val() == -1)   allGate[left->get_name()]->evaluate(allGate);
    switch(left->get_val()){
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
        case 3:
            return 2;
    }
}