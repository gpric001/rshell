#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <cstring>

class Parser{
    public:
        Parser();
        std::vector<std::vector<std::string> > parse(const std::string &s);
//        void setShell (Rshell* shell);
//    private:
//        Rshell* shell;
};
#endif
