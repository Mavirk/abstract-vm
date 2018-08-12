#ifndef AVM_HPP
#define AVM_HPP
#include "parser.hpp"
#include "lexer.hpp"
#include <iostream>

class AVM :{
    AVM(std::string const filename);
    ~AVM();
    AVM(const AVM& obj);
};
#endif

