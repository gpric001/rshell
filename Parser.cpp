#include "Parser.h"

Parser::Parser() {};

std::vector<std::vector<std::string> > Parser::parse(std::string &s){
    std::vector<std::vector<std::string> > result;
    std::vector<std::string> tempParse;
    char * cstr = new char [s.size()+1];
    std::strcpy(cstr, s.c_str());
    char * p = std::strtok(cstr, " ");
    bool continueConnect;
    while(p != NULL){
        continueConnect = false; //Flag for ';' connector
        std::string tmp(p);

        if(tmp[tmp.size()-1] == ';'){
            tmp = tmp.substr(0, tmp.size()-1);
            continueConnect = true;
        }

        if(tmp[0] == '-'){
            //If the string is a list of flags then split them
            for(int i = 1; i < tmp.size(); i++)
                tempParse.push_back(std::string(1, tmp[i]));
                }
        else
            tempParse.push_back(tmp);

        if(continueConnect)
            tempParse.push_back(";");

        p = std::strtok(NULL, " ");
    }
    
    std::vector<std::string> cmdToken;
    for(int i = 0; i < tempParse.size(); i++){
        if(tempParse[i] != "||" && tempParse[i] != ";" && tempParse[i] != "&&")
            cmdToken.push_back(tempParse[i]);
        else{
            result.push_back(cmdToken);
            cmdToken.clear();
            cmdToken.push_back(tempParse[i]);
            result.push_back(cmdToken);
            cmdToken.clear();
        }
    }
    result.push_back(cmdToken);
    delete[] cstr;
    return result;
}

//void Parser::setShell(Rshell* shell){
//    this.shell = shell;
//

