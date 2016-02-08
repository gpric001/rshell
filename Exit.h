#ifndef Exit_H
#define Exit_H

#include <vector>
#include <string>
using namespace std;

#include "CommandComponent.h"

class Exit : public CommandComponent
{
    private:

    public:
        void set(string c, vector<string> a);
        int execute();
};

#endif