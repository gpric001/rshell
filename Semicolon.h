#ifndef Semicolon_h
#define Semicolon_h

#include "Connector.h"

using namespace std;

class Semicolon : public Connector
{
    private:
    
    public:
        Semicolon(CommandComponent* left, CommandComponent* right);
        int execute();
            
};

#endif
