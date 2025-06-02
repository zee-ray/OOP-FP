#include "OrGate.h"
void OrGate::evaluate(){
    this->set_val(OR[right->get_val()][left->get_val()]);
}