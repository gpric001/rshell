#ifndef BinCmd_H
#define BinCmd_H

#include <vector>
#include <string>
using namespace std;

#include "CommandComponent.h"

class BinCmd : public CommandComponent
{
    private:
        
    public:
	BinCmd(const string& c, const vector<string>& a);
        int execute();
};

#endif
