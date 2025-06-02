#include "NxorGate.h"
void NxorGate::evaluate(){
    int xorresult = -1;
    xorresult = XOR[right->get_val()][left->get_val()];
    switch(xorresult){
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