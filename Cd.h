#ifndef Cd_H
#define Cd_H

#include "CommandComponent.h"

class Cd : public CommandComponent
{
    private:
    
    public:
        void set(string c, vector<string> a);
        int execute();
};

#endif
