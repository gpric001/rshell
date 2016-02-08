#ifndef BinCmd_H
#define BinCmd_H

#include <vector>
#include <string>
using namespace std;

#include "CommandComponent.h"

class BinCmd : public CommandComponent
{
    public:
        
    private:
        void set(string c, vector<string> a);
        int execute();
};

#endif