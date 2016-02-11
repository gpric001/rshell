#ifndef And_H
#define And_H

#include "Connector.h"

using namespace std;

class And : public Connector
{
    private:
    
    public:
        And(CommandComponent* left, CommandComponent* right);
        int execute();
    
};

#endif
