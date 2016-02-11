#include "Semicolon.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

Semicolon::Semicolon(CommandComponent* left, CommandComponent* right)
:Connector(left, right) {};

int Semicolon::execute()
{
    return 1;
};

void set(const string& c, const vector<string>& a)
{

};
