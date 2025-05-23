#ifndef PARSER_H
#define PARSER_H
#include "allGate.h"
#include <fstream>
#include <iostream>
class Parser{
public:
    void ParseNetlist(ifstream& netlist_fin, map<string,Node*>& InputNode, map<string,Node*>& OutputNode, map<string,Node*>& allNode);
    // bool ParsePattern(ifstream& pat_fin, vector<Node*>& InputNode);
};
#endif