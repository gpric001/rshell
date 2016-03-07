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

class InvalidInputException;

Parser::Parser() {}
 
std::vector<tokens> Parser::parse(const std::string &s){
    std::vector<tokens> tkns; //The complete tokenized string
    tokens tempParse;
    char * cstr = new char [s.size()+1]; //The string as a char array
    std::strcpy(cstr, s.c_str()); 
    char * p = std::strtok(cstr, " "); //The first token
    std::string delims = "()[];#";
    while(p != NULL){
        if(p[0] == '#')
            break;
        this->split(p, delims, tempParse);
        //Go to next token
        p = std::strtok(NULL, " ");
    }
   
    tempParse = this->sqrBrktHandler(tempParse);

    tokens cmdToken;
    
    for(unsigned int i = 0; i < tempParse.size(); i++){
        if(tempParse[i] != "||" && tempParse[i] != ";" && tempParse[i] != "&&"
           && tempParse[i] != "(" && tempParse[i] != ")")
            cmdToken.push_back(tempParse[i]);
        else{
            if(!cmdToken.empty()){
                tkns.push_back(cmdToken);
                cmdToken.clear();
            }
            cmdToken.push_back(tempParse[i]);
            tkns.push_back(cmdToken);
            cmdToken.clear();
        }
    }
    //Push the command/connector group to the result
    if(!cmdToken.empty())
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
        else if((pTkn[i] == '[' || pTkn[i] == ']') && (i != 0 || pTkn[i+1] != '\0'))
            throw InvalidInputException();
        else{
            if(!buf.empty()){
                tkns.push_back(buf);
                buf.clear();
            }
            buf.push_back(*delimItr);
            tkns.push_back(buf);
            buf.clear();
        }
    }
    if(!buf.empty())
        tkns.push_back(buf);
}

tokens Parser::sqrBrktHandler(tokens& splitInput){
    tokens::iterator tknsItr = splitInput.begin();
    tokens result;
    bool findClosed = false;
    while(tknsItr != splitInput.end()){
        if(*tknsItr == "["){
            result.push_back("test");
            findClosed = true;
        }
        else if(*tknsItr == "]"){
            if(!findClosed)
                throw InvalidInputException();
            else
                findClosed = false;
        }
        else
            result.push_back(*tknsItr);
        tknsItr++;
    }
    return result;
}
