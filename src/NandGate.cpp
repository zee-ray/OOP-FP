#include "NandGate.h"
void NandGate::evaluate(){
    int andresult = -1;
    andresult = AND[right->get_val()][left->get_val()];
    switch(andresult){
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