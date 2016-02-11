#ifndef Cd_H
#define Cd_H

#include "CommandComponent.h"

class Cd : public CommandComponent
{
    private:
    
    public:
        void set(const string& c, const vector<string>& a);
        int execute();
};

#endif
