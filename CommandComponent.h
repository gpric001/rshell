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
        void set(string c, vector<string> a);
        virtual int execute() = 0;
  
};

#endif
