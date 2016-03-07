#ifndef _INVALID_INPUT_EXCEPTION_H
#define _INVALID_INPUT_EXCEPTION_H
#include <exception>
#include <string>
#include <iostream>

class InvalidInputException: public std::exception{
     const std::string what(std::string) const throw();
};
#endif
