#include "Parser.h"

Parser::Parser() {}
 
std::vector<std::vector<std::string> > Parser::parse(const std::string &s){
    std::vector<std::vector<std::string> > result; //The complete parsed string
    std::vector<std::string> tempParse; //One command or connected parsed
    char * cstr = new char [s.size()+1]; //The string as a char array
    std::strcpy(cstr, s.c_str()); 
    char * p = std::strtok(cstr, " "); //The first token
    bool continueConnect; //Flag for determining if we get a ;
    while(p != NULL){
        continueConnect = false; //Assume the token isn't a ; first
        std::string tmp(p);

        //Check to see if the current token is a ;
        if(tmp[tmp.size()-1] == ';'){
            tmp = tmp.substr(0, tmp.size()-1);
            continueConnect = true;
        }

        //Check to see if the current token is a flag
        if(tmp[0] == '-'){
            //If the string is a list of flags then split them
            if(tmp.size() >= 2 && tmp[1] == '-') //Check for -- flag
                tempParse.push_back(tmp);
            for(unsigned int i = 1; i < tmp.size(); i++){
                std::string tmpS(1, tmp[i]);
                tmpS.insert(0, "-");
                tempParse.push_back(tmpS);
            }
         }
        //Check if the current token is a comment
        else if(tmp[0] == '#')
            break;
        //Push the current token
        else
            tempParse.push_back(tmp);

        if(continueConnect)
            tempParse.push_back(";");

        //Go to next token
        p = std::strtok(NULL, " ");
    }
    
    std::vector<std::string> cmdToken;
    //Create the name of the command or connector for each grouped command
    for(unsigned int i = 0; i < tempParse.size(); i++){
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
    //Push the command/connector group to the result
    result.push_back(cmdToken);
    delete[] cstr;
    return result;
}
