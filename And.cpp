#include "And.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int And::execute()
{
    return ( childL->execute() && childR->execute() );
};