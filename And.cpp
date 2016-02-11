#include "And.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

And::And(CommandComponent* left, CommandComponent* right)
:Connector(left, right) {};

int And::execute()
{
    return ( childL->execute() && childR->execute() );
};

void set(const string& c, const vector<string>& a)
{

};


