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
    tc->create(parser->parse("clear"))->execute();
    while(running){
        
        std::cout<<"$ "; //Display prompt
        std::getline(std::cin, userInput); //Get user input
        if(!(userInput.empty()))
            //Parse user input
            tc->create(parser->parse(userInput))->execute();
            //Create tree from parsed input
            //Execute parsed input
            //Repeat
    }
}

