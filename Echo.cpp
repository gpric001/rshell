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
	for(unsigned int i = 1; i < args.size(); i++)
	{
		cout << args[i] << endl;
    	}

    return 1;
};
