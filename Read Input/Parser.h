#ifndef PARSER_H
#define PARSER_H
#include "allGate.h"
#include <fstream>
#include <iostream>
class Parser{
public:
    void ParseNetlist(ifstream& netlist_fin, vector<Node*>& allNode, vector<Node*>& OutputNode, map<string,Gate*>& allGate);
    bool ParsePattern(ifstream& pat_fin, vector<Node*>& allNode);
};
#endif