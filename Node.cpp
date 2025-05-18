#include"Node.h"
Node::Node():val(-1), name("no name"){}
Node::Node(string theName):val(-1), name(theName){}
Node::Node(string theName, int theValue):val(theValue), name(theName){}
void Node::set_val(int theValue){val = theValue;}
int Node::get_val(){return val;}
void Node::set_name(string theName){name = theName;}
string Node::get_name(){return name;}