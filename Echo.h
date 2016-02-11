#ifndef Echo_H
#define Echo_H

#include <vector>
#include <string>
using namespace std;

#include "CommandComponent.h"

class Echo : public CommandComponent
{
    private:
        
    public:
    	Echo(const string& c, const vector<string>& a);  
        int execute();
};

#endif
