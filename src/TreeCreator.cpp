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
#include "InvalidInputException.h"
#include <iostream>

TreeCreator::TreeCreator() {}

CommandComponent* TreeCreator::create(const std::vector<tokens>& input){
    if(!balancedParens(input))
        throw InvalidInputException();
    return build(0, input.size(), this->reverse(input));
}

CommandComponent* TreeCreator::build(unsigned int start, unsigned int end,
                                     const std::vector<tokens>& input){
    //Searches for a ; connector, if found then it builds the left subtree
    //And recursively trys to build the right subtree up to the next ; connector
    for(unsigned int i = start; i < end; i++){
        if(input[i][0] == ";"){
            CommandComponent* left = buildSub(start, i, input);
            CommandComponent* right = build(i+1, end, input);
            return buildConnector(";", right, left);
        }
    }
    //If no ; connector is found then builds the entire tree as a subtree
    return buildSub(start, end, input);
}

CommandComponent* TreeCreator::buildSub(unsigned int start, unsigned int end,
                                        const std::vector<tokens>& input){

    if(input[start][0] == "("){
        int parenCtnr = 1;
        unsigned int parenEnd = 0;
        for(unsigned int i = start + 1; i < end; i++){
            if(input[i][0] == "(") parenCtnr++;
            else if(input[i][0] == ")") parenCtnr--;
            if(parenCtnr == 0){
                parenEnd = i;
                break;
            }
        }
        return build(start + 1, parenEnd, input);
    }
    else{ 
        //If we're at the last grouping, build it as a command
        if((end - start - 1) == 0){
            return buildCmd(input[start]);
        }
        //Otherwise recursively build the connector and commands
        std::string connectorToken = input[start+1][0];
        CommandComponent* left = buildCmd(input[start]);
        //std::cout<<"3: "<<input[start+2][0]<<std::endl;
        CommandComponent* right = buildSub(start+2, end, input);
        return buildConnector(connectorToken, right, left);
    }
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

CommandComponent* TreeCreator::buildCmd(const tokens& cmd){
    std::string cmdName = cmd[0];
    CommandComponent* command;
    if(cmdName == "echo")
        command = new Echo(cmdName, cmd);
    else if(cmdName == "cd")
        command = new Cd(cmdName, cmd);
    else if(cmdName == "exit")
        command = new Exit(cmdName, cmd);
    else if(cmdName == "test")
        command = new Test(cmdName, cmd);
    else
        command = new BinCmd(cmdName, cmd);
    std::cout<<"Build complete"<<std::endl;
    return command;
}

std::vector<tokens> TreeCreator::reverse(const std::vector<tokens>& input){
    std::vector<tokens> result;
    tokens tmp;
    for(int i = (input.size() - 1); i >= 0; i--){
        if(input[i][0] == "(")
            tmp.push_back(")");
        else if(input[i][0] == ")")
            tmp.push_back("(");
        else
            tmp = input[i];
        result.push_back(tmp);
        tmp.clear();
    }
    return result;
}

bool TreeCreator::balancedParens(const std::vector<tokens>& input){
    int balanceCntr = 0;
    for(unsigned int i = 0; i < input.size(); i++){
        if(balanceCntr < 0)
            return false;
        if(input[i][0] == "(")
            balanceCntr++;
        else if(input[i][0] == ")")
            balanceCntr--;
    }
    return (balanceCntr == 0);
}
