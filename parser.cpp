#include "parser.hpp"

Parser::Parser(){}

Parser::~Parser(){}

Parser::Parser(const Parser &obj){
    *this = obj;
    return;
}

Parser&
Parser::operator=(Parser const &rhs){
    if (this != &rhs){
        return *this;
    }
    return *this;
}

IOperand const *
Parser::createOperand(eOperandType type, std::string const & value ) const{

    IOperand    *(*fptr[])(std::string const & value) = {&createInt8,
                                                        &createInt16,
                                                        &createInt32, 
                                                        &createFloat, 
                                                        &createDouble};
    return fptr[type](value);
}

IOperand*   Parser::createInt8(const std::string& value){
    IOperand*           ret;
    std::stringstream   ss;
    long double         val;

    ss.str(value);
    ss >> val;
    if (val < std::numeric_limits<signed char>::min() || val > std::numeric_limits<signed char>::max())
        std::cout << "Erro of type : Overflow or Underflow for value " << value  << "doesnt fit into an int8";
    ret = new Operand<char>(Int8, value);
    return ret;
}