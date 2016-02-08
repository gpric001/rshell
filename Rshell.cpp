#include "Rshell.h"

Rshell::Rshell() {};

void Rshell::setParser(Parser* p){
    parser = p;
}

void Rshell::setTreeCreator(TreeCreator* tc){
    this.tc = tc;
}

void Rshell::run(){
    bool running = true;
    while(running){
        //TODO: Display prompt
        //TOOD: Get user input
        std::string test = "e || d; f || g; h && s || z || m";
        //Parse user input
        cc->execute(tc->create(p->parse()));
        //Create tree from parsed input
        //Execute parsed input
        //Repeat
        running = false;
    }
}

