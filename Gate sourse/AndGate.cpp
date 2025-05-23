#include "AndGate.h"
int AndGate::evaluate(map<string,Node*> allNode){
    if(left->get_val() == -1){
        left->set_val( allNode[left->get_name()]->evaluate(allNode) );
    }
    if(right->get_val() == -1){
        right->set_val( allNode[right->get_name()]->evaluate(allNode) );
    }
    this->set_val(AND[right->get_val()][left->get_val()]);
    return this->get_val();
}


#include "NotGate.h"
#include <iostream>
void clean(map<string,Node*> allNode){
    for(auto n : allNode){
        n.second->set_val(-1);
    }
    cout<<"all nodes have been set to -1"<<endl;
}
int main(){
    Node a("A"),b("B");
    Node* n1 = new AndGate("node1" , &a, &b);
    Node* n2 = new NotGate("node2",n1);
    map<string,Node*> allNode;
    allNode[a.get_name()] = &a;
    allNode[b.get_name()] = &b;
    allNode[n1->get_name()] = n1;
    allNode[n2->get_name()] = n2;
    while(1){
        int val;
        cin>>val;
        if(val == -1)   break;
        a.set_val(val);
        cin>>val;
        b.set_val(val);
        cout<<"val for andgate:"<<n1->evaluate(allNode)<<endl;
        cout<<"val for notgate:"<<n2->evaluate(allNode)<<endl;
        clean(allNode);
    }
    delete n1;
    delete n2;
}