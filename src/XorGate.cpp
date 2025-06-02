#include "XorGate.h"
void XorGate::evaluate(){
    this->set_val(XOR[right->get_val()][left->get_val()]);
}