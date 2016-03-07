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

#include "Rshell.h"

class InvalidInputException;

Rshell::Rshell() {}

void Rshell::setParser(Parser* p){
    parser = p;
}

void Rshell::setTreeCreator(TreeCreator* tc){
    this->tc = tc;
}

void Rshell::run(){
    bool running = true;
    std::string userInput;
    while(running){
        
        std::cout<<"$ "; //Display prompt
        std::getline(std::cin, userInput); //Get user input
        //If the user input isn't empty, then parse user input,
        //build the tree, and execute the top node of the tree.
        try{
            if(!(userInput.empty() || userInput[0] == '#'))
                tc->create(parser->parse(userInput))->execute();
        }
        catch(InvalidInputException& e){
            std::cout<<e.what()<<std::endl;
        }
    }
}

