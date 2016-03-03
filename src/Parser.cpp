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

#include "Parser.h"

class InvalidInput;

Parser::Parser() {}
 
std::vector<tokens> Parser::parse(const std::string &s){
    std::vector<tokens> tkns; //The complete tokenized string
    tokens tempParse; //One command or connector
    char * cstr = new char [s.size()+1]; //The string as a char array
    std::strcpy(cstr, s.c_str()); 
    char * p = std::strtok(cstr, " "); //The first token
    std::string delims = "()[];#";
    while(p != NULL){
        this->split(p, delims, tempParse);
        //Go to next token
        p = std::strtok(NULL, " ");
    }
    
    tokens cmdToken;

    tokens::iterator tknsItr = tempParse.begin(), testItr;
    while(tknsItr != tempParse.end()){
        if(*tknsItr == "["){
            *tknsItr = "test";
            tknsItr++;
            testItr = tknsItr;
            while(testItr != tempParse.end()){
                if(testItr == tempParse.end())
                    throw InvalidInput();
                if(*testItr == "]"){
                    tknsItr = tempParse.erase(testItr);
                    break;
                }
                testItr++; tknsItr++;
            }
            if(tknsItr != tempParse.end())
                tknsItr++;
        }
    }
    
    for(unsigned int i = 0; i < tempParse.size(); i++){
        if(tempParse[i] != "||" && tempParse[i] != ";" && tempParse[i] != "&&")
            cmdToken.push_back(tempParse[i]);
        else{
            tkns.push_back(cmdToken);
            cmdToken.clear();
            cmdToken.push_back(tempParse[i]);
            tkns.push_back(cmdToken);
            cmdToken.clear();
        }
    }
    //Push the command/connector group to the result
    tkns.push_back(cmdToken);
    delete[] cstr;
    return tkns;
}

void Parser::split(char* pTkn, std::string delims, tokens& tkns){
    std::string::iterator delimItr;
    std::string buf;

    for(unsigned int i = 0; pTkn[i] != '\0'; i++){
        delimItr = std::find(delims.begin(), delims.end(), pTkn[i]);
        if(delimItr == delims.end()){
            buf.push_back(pTkn[i]);
        }
        else{
            if(!buf.empty()){
                tkns.push_back(buf);
                buf.clear();
            }
            if(pTkn[i] == '#')
                break;
            std::string delim(1, pTkn[i]);
            tkns.push_back(delim);
        }
    }
    if(!buf.empty())
        tkns.push_back(buf);
}

const std::string InvalidInput::what(std::string& s) const throw(){
    return "Invalid input error on: " + s;
}
