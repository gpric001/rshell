#include "Or.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int Or::execute()
{
    return ( childL->execute() || childR->execute() );
};