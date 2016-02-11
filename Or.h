#ifndef Or_H
#define Or_H

#include "Connector.h"

using namespace std;

class Or : public Connector
{
    private:
    
    public:
        Or(CommandComponent* left, CommandComponent* right);
        int execute();
    
};

#endif
