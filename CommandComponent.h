#ifndef CommandComponent_H
#define CommandComponent_H

#include <string>
#include <vector>
using namespace std;

class CommandComponent
{
    protected:
        string cmd;
        vector<string> args;
    
    public:
        virtual void set(string c, vector<string> a) = 0;
        virtual int execute() = 0;
  
};

#endif