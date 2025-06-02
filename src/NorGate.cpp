#include "NorGate.h"
void NorGate::evaluate(){
    int orresult = -1;
    orresult = OR[right->get_val()][left->get_val()];
    switch(orresult){
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