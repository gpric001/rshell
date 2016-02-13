#ifndef TREECREATOR_H
#define TREECREATOR_H

#include "CommandComponent.h"
#include "Or.h"
#include "And.h"
#include "Semicolon.h"
#include "Exit.h"
#include "Echo.h"
#include "Cd.h"
#include "BinCmd.h"

typedef std::vector<std::vector<std::string > > tokens; 
class TreeCreator{
    public:
        TreeCreator();
        CommandComponent* create(const tokens&); //Entry to create a tree of commands/connectors
    private:
        CommandComponent* build(int start, const tokens& input); //Builds the top level of the tree giving priority to the ; connector
        CommandComponent* buildSub(int start, int end, const tokens& input); //Buils a subtree on the left and right of a ; connector
        CommandComponent* buildConnector(const std::string& token,
                                         CommandComponent* left,
                                         CommandComponent* right); //Builds a connector
        CommandComponent* buildCmd(const std::vector<std::string>& input); //Builds a command
}; 
#endif
