#include "BufGate.h"
void BufGate::evaluate(){
    if(left->get_val() == 3)    this->set_val(2);
    else    this->set_val(left->get_val());
}