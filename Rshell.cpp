#include "Rshell.h"

Rshell::Rshell() {};

void Rshell::setParser(Parser* p){
    parser = p;
}

void Rshell::setTreeCreator(TreeCreator* tc){
    this.tc = tc;
}

void Rshell::run(){
    return;
}

