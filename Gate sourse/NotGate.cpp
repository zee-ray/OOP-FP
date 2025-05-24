#include "NotGate.h"
void NotGate::evaluate(){
    switch(left->get_val()){
        case 0:
            this->set_val(1);
            return;
        case 1:
            this->set_val(0);
            return;
        case 2:
        case 3:
            this->set_val(2);
            return;
    }
}