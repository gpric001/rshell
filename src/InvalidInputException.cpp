#include "InvalidInputException.h"

const std::string InvalidInputException::what(std::string s) const throw(){
    std::cout<<"\nError, invalid input on: " + s<<std::endl;
}
