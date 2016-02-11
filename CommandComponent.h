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
        void set(const string& c, const vector<string>& a);
        virtual int execute() = 0;
  
};

#endif
