#include "Echo.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

void Echo::set(string c, vector<string> a)
{
    cmd = c;
    args = a;
};

int Echo::execute()
{
    cout << args[0] << endl;
    
    return 1;
};