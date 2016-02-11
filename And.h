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
	void set(const string& c, const vector<string>& a );
};

#endif
