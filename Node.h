#include <string>
#include <vector>
using namespace std;
class Node
{
private:
    int val;
    string name;
    // bool with_gate;
public:
    Node();
    Node(string theName);
    Node(string theName, int theValue);
    void set_val(int theValue);
    int get_val();
    void set_name(string theName);
    string get_name();
    // void set_with_gate();
    // bool get_with_gate();
};