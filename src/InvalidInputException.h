#ifndef _INVALID_INPUT_EXCEPTION_H
#define _INVALID_INPUT_EXCEPTION_H
#include <exception>

class InvalidInputException: public std::exception{
     public:
        const char* what() const throw();
};
#endif
