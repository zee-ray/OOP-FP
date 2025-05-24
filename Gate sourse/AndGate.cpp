#include "AndGate.h"
void AndGate::evaluate(){
    this->set_val(AND[right->get_val()][left->get_val()]);
}