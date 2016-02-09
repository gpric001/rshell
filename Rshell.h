#ifndef R_SHELL.h
#define R_SHELL.h

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
        CommandComponant *cc;
}
#endif
