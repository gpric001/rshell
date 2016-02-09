#include "TreeCreator.h"

TreeCreator::TreeCreator() {};

CommandComponent* TreeCreator::create(tokens& input){
    build(0, input);
}

CommandComponent* TreeCreator::build(int start, tokens& input){
    for(int i = start; i < input.size(); i++){
        if(input[i][0] == ";"){
            CommandComponent* left = buildSub(start, i, input);
            CommandComponent* right = build(i+1, input);
            return buildConnector(";", left, right);
        }
    }
    return buildSub(start, input.size(), input);
}

CommandComponent* TreeCreator::buildSub(int start, int end, tokens& input){
    if((end - start - 1) == 0)
        return buildCmd(input[start]);
    std::string connectorToken = tokens[start+1][0];
    if(connectorToken == "||" || connectorToken == "&&"){
        CommandComponent* left = buildCmd(tokens[start]);
        CommandComponent* right = buildSub(start+2, end, tokens);
        return buildConnector(connectorToken, left, right);
    }
    else{
        //return an error
    }
}

CommandComponent* TreeCreator::buildConnector(std::string& token, 
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

CommandComponent* TreeCreator::buildCmd(tokens& input){
    std::string cmdName = input[0];
    CommandComponent* command;
    if(cmdName == "echo")
        command = new Echo();
    else if(cmdName == "cd")
        command = new Cd();
    else if(cmdName == "exit")
        command = new Exit();
    else
        command = new BinCmd();
    command->set(cmdName, input);
    return command;
}

