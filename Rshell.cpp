#include "Rshell.h"

Rshell::Rshell() {};

void Rshell::setParser(Parser* p){
    parser = p;
}

void Rshell::setTreeCreator(TreeCreator* tc){
<<<<<<< HEAD
    this->tc = tc;
}

void Rshell::run(){
    bool running = true;
    std::string userInput;
    while(running){
        
        std::cout<<"$ "; //Display prompt
        std::getline(std::cin, userInput); //Get user input
        //Parse user input
        tc->create(parser->parse(userInput));
        //Create tree from parsed input
        //Execute parsed input
        //Repeat
        running = false;
    }
}

