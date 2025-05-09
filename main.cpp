#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include"Gate.h"
using namespace std;
void ReadNetlist(char* fin_name, set<string>& allNodeName, map<string,Node>& allNode, map<string,Gate>& allGate, set<string>& allGateName);
void OutputPattern(char* fout_name, set<string>& allNodeName, map<string,Node>& allNode, map<string,Gate>& allGate, set<string>& allGateName);
int main(int argc, char** argv){
    ReadNetlist();
    OutputPattern();
}