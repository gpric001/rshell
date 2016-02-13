#ifndef RSHELL_H
#define RSHELL_H

#include <iostream>
#include <string>
#include "Parser.h"
#include "TreeCreator.h"
 
class Rshell {
    public:
        Rshell();
        void setParser(Parser *p);
        void setTreeCreator(TreeCreator *tc);
        void run();
    private:
        Parser *parser;
        TreeCreator *tc;
}; 
#endif

