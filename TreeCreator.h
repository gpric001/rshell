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
        CommandComponent* create(const tokens&);
    private:
        CommandComponent* build(int start, const tokens& input);
        CommandComponent* buildSub(int start, int end, const tokens& input);
        CommandComponent* buildConnector(const std::string& token,
                                         CommandComponent* left,
                                         CommandComponent* right);
        CommandComponent* buildCmd(const std::vector<std::string>& input);
}; 
#endif
