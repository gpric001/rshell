/*  Copyright (C) 2016  Authors: Guthrie Price, Mathew Schaffrath

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program under the filename LICENSE.
    If not, see <http://www.gnu.org/licenses/>.

    This program comes with ABSOLUTELY NO WARRANTY.     */

#ifndef TREECREATOR_H
#define TREECREATOR_H

#include "CommandComponent.h"
#include "Or.h"
#include "And.h"
#include "Semicolon.h"
#include "Exit.h"
#include "Echo.h"
#include "Cd.h"
#include "Test.h"
#include "BinCmd.h"
 
typedef std::vector<std::string> tokens; 
class TreeCreator{
    public:
        TreeCreator();
        CommandComponent* create(const std::vector<tokens>&); //Entry to create a tree of commands/connectors
    private:
        CommandComponent* build(int, const std::vector<tokens>& input); //Builds the top level of the tree giving priority to the ; connector
        CommandComponent* buildSub(int, int, const std::vector<tokens>& input); //Buils a subtree on the left and right of a ; connector
        CommandComponent* buildConnector(const std::string& token,
                                         CommandComponent* left,
                                         CommandComponent* right); //Builds a connector
        CommandComponent* buildCmd(const tokens& input); //Builds a command
}; 
#endif
