#ifndef RSHELL_H
#define RSHELL_H

#include <iostream>
#include <string>

class Rshell {
    public:
        Rshell();
        void setParser(Parser *p);
        void seTreeCreator(TreeCreator *tc);
        void run();
    private:
        Parser *parser;
        TreeCreator *tc;
};
#endif

