#ifndef TREECREATOR_H
#define TREECREATOR_H

#include "Or.h"
#include "And.h"
#include "Semicolon.h"
#include "Exit.h"
#include "Echo.h"
#include "Cd.h"
#include "BinCmds.h"

#typedef std::vector<std::vector<std::string > > tokens; 
class TreeCreator{
    public:
        TreeCreator();
        CommandComponent* create();
    private:
        CommandComponent* build(int start, tokens& input);
        CommandComponent* buildSub(int start, int end, tokens& input);
        CommandComponent* buildConnector(std::string token,
                                         CommandComponent* left,
                                         CommandComponent* right);
        CommandComponent* buildCmd(tokens input);
}
#endif
