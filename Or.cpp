#include "Or.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

Or::Or(CommandComponent* left, CommandComponent* right)
:Connector(left, right) {};

int Or::execute()
{
    return ( childL->execute() || childR->execute() );
};
