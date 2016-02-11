#include "Exit.h"

#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

Exit::Exit(const string& c, const vector<string>& a)
{
    cmd = c;
    args = a;
};

int Exit::execute()
{
    exit(0);
    
};
