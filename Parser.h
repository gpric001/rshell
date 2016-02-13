#ifndef PARSER_H
#define PARSER_H
 
#include <string>
#include <vector>
#include <cstring>

class Parser{
    public:
        Parser();
        std::vector<std::vector<std::string> > parse(const std::string &s); //Parses user input into groups on commands/connectors
}; 
#endif
