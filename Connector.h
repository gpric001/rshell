#ifndef Connector_H
#define Connector_H

using namespace std;

#include "CommandComponent.h"

class Connector : public CommandComponent
{
    private:
        CommandComponent* childL;
        CommandComponent* childR;
        
    public:
        virtual int execute() = 0;
        
        Connector(CommandComponent* c1, CommandComponent* c2)
        {
            childL = c1;
            childR = c2;
        }
};

#endif
