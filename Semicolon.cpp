#include "Semicolon.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

Semicolon::Semicolon(CommandComponent* left, CommandComponent* right)
:Connector(left, right) {};

int Semicolon::execute()
{
	childL->execute();
	childR->execute();
	return 1;
};

