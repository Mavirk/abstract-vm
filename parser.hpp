#ifndef PARSER_HPP
#define PARSER_HPP
#include "lexer.hpp"
#include "exception.hpp"
#include "Ioperand.hpp"
#include <string>
#include <limits>
#include <sstream>
#include <iostream>
#include <map>

class Parser{
    public:
        static IOperand const      *createOperand( eOperandType type, std::string const & value );
        static IOperand const      *operand(std::string const &str);
        static IOperand const      *createOperand(eOperandType type, long double value);
        // void                checkPushAssert(std::vector<Lexeme> lexemes);

    private:
        static IOperand*	createInt8(const std::string& value);
        static IOperand*	createInt16(const std::string& value);
        static IOperand*	createInt32(const std::string& value);
        static IOperand*	createFloat(const std::string& value);
        static IOperand*	createDouble(const std::string& value);


};
#endif