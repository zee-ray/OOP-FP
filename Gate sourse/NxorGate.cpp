#include "NxorGate.h"
int NxorGate::evaluate(map<string,Node*> allNode){
    int xorresult = -1;
    if(left->get_val() == -1){
        left->set_val( allNode[left->get_name()]->evaluate(allNode) );
    }
    if(right->get_val() == -1){
        right->set_val( allNode[right->get_name()]->evaluate(allNode) );
    }
    xorresult = XOR[right->get_val()][left->get_val()];
    switch(xorresult){
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