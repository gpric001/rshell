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

Parser::Parser() {};

std::vector<std::vector<std::string> > Parser::parse(const std::string &s){
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

