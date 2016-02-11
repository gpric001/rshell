#include "Echo.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

Echo::Echo(const string& c, const vector<string>& a)
{
    cmd = c;
    args = a;
};

int Echo::execute()
{
    cout << args[0] << endl;
    
    return 1;
};
