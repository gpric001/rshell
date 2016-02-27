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

#include "TreeCreator.h"

TreeCreator::TreeCreator() {}

CommandComponent* TreeCreator::create(const tokens& input){
    return build(0, input);
}

CommandComponent* TreeCreator::build(int start, const tokens& input){
    //Searches for a ; connector, i found then it builds the left subtree
    //And recursively trys to build the right subtree up to the next ; connector
    for(unsigned int i = start; i < input.size(); i++){
        if(input[i][0] == ";"){
            CommandComponent* left = buildSub(start, i, input);
            CommandComponent* right = build(i+1, input);
            return buildConnector(";", left, right);
        }
    }
    //If no ; connector is found then builds the entire tree as a subtree
    return buildSub(start, input.size(), input);
}

CommandComponent* TreeCreator::buildSub(int start, int end, const tokens& input){
    //If we're at the last grouping, build it as a command
    if((end - start - 1) == 0)
        return buildCmd(input[start]);
    //Otherwise recursively build the connector and commands
    std::string connectorToken = input[start+1][0];
        CommandComponent* left = buildCmd(input[start]);
        CommandComponent* right = buildSub(start+2, end, input);
        return buildConnector(connectorToken, left, right);
}

CommandComponent* TreeCreator::buildConnector(const std::string& token, 
                                CommandComponent* left, 
                                CommandComponent* right){
    CommandComponent* connector;
    if(token == ";")
        connector = new Semicolon(left, right);

    else if(token == "||")
        connector = new Or(left, right);

    else if (token == "&&")
        connector = new And(left, right);

    return connector;
}

CommandComponent* TreeCreator::buildCmd(const std::vector<std::string>& cmd){
    std::string cmdName = cmd[0];
    CommandComponent* command;
    if(cmdName == "echo")
        command = new Echo(cmdName, cmd);
    else if(cmdName == "cd")
        command = new Cd(cmdName, cmd);
    else if(cmdName == "exit")
        command = new Exit(cmdName, cmd);
    else
        command = new BinCmd(cmdName, cmd);
    return command;
}

