#include "InvalidInputException.h"

const char* InvalidInputException::what() const throw(){
    const char* errmsg = "Error, invalid input";
    return errmsg;
}
