#include "Rshell.h"

Rshell::Rshell() {};

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
        if(!(userInput.empty()))
            tc->create(parser->parse(userInput))->execute();
    }
}

