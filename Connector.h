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
        
};

#endif