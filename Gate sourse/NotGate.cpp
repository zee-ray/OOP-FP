#include "NotGate.h"
int NotGate::evaluate(map<string,Node*> allGate){
    if(left->get_val() == -1)   left->set_val(allGate[left->get_name()]->evaluate(allGate));
    switch(left->get_val()){
        case 0:
            this->set_val(1);
            return 1;
        case 1:
            this->set_val(0);
            return 0;
        case 2:
        case 3:
            this->set_val(2);
            return 2;
    }
}