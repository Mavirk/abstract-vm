#ifndef PARSER_HPP
#define PARSER_HPP
#include "Ioperand.hpp"
class Parser{
    public:
        Parser();
        ~Parser();
        Parser(const Parser &obj);
        Parser              &operator=(Parser const &rhs);
        IOperand const      *createOperand( eOperandType type, std::string const & value ) const;
    private:
        static IOperand*	createInt8(const std::string& value);
        static IOperand*	createInt16(const std::string& value);
        static IOperand*	createInt32(const std::string& value);
        static IOperand*	createFloat(const std::string& value);
        static IOperand*	createDouble(const std::string& value);
};
#endif