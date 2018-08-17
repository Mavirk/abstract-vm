#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "parser.hpp"

#include "Ioperand.hpp"
#include "avm.hpp"
template<typename T>
class Operand : public IOperand {
    private:
        eOperandType    _type;
        T               _val;
        std::string     _str;

    public:
        Operand(eOperandType type, std::string const &str) {
            std::stringstream ss;
            ss.str(str);
            _type = type;
            ss >> _val;
            _str = str;
        }

        Operand(Operand const& o){
            _type = o._type;
            _str = o._str;
            _val = o._type;
        }

        ~Operand(){}

        Operand &operator=(Operand const& o){
            if (this != &o){
                _type = o._type;
                _str = o._str;
                _val = o._val;
            }
            return *this;
        }

        std::string const & toString() const {
            return _str;
        }

        int getPrecision() const{
            return static_cast<int>(_type);
        }

        eOperandType    getType() const{
            return _type;
        }

        IOperand const * operator+( IOperand const & rhs ) const{
            std::stringstream   ss;
            char                v = _val;
            eOperandType        precise;
            char         value;
            // long double         lhsvalue;
            // lhsvalue = _val;
            std::cout << "+ operator v " << v << std::endl;
            ss << rhs.toString();
            ss >> value;
            precise = _type >= rhs.getType() ? _type : rhs.getType();
            // std::cout << "+ operator lhs value" << lhsvalue << std::endl;
            std::cout << "+ operator rhs value " << value << std::endl;
            std::cout << "sum" << v + value << std::endl;
            return Parser::createOperand(precise, std::to_string(_val + value));
        }

        IOperand const * operator-( IOperand const & rhs ) const{
            std::stringstream   ss;
            eOperandType        precise;
            long double         rhsvalue;
            long double         lhsvalue;
            lhsvalue = _val;


            ss << rhs.toString();
            ss >> rhsvalue;

            precise = _type >= rhs.getType() ? _type : rhs.getType();
            return Parser::createOperand(precise, std::to_string(lhsvalue + rhsvalue));
        }

        IOperand const * operator*( IOperand const & rhs ) const{
            std::stringstream   ss;
            eOperandType        precise;
            long double         rhsvalue;
            long double         lhsvalue;
            lhsvalue = _val;

            ss << rhs.toString();
            ss >> rhsvalue;
            precise = _type >= rhs.getType() ? _type : rhs.getType();
            return Parser::createOperand(precise, std::to_string(lhsvalue + rhsvalue));
        }

        IOperand const * operator/( IOperand const & rhs ) const{
            std::stringstream   ss;
            eOperandType        precise;
            long double         rhsvalue;
            long double         lhsvalue;
            lhsvalue = _val;

            ss << rhs.toString();
            ss >> rhsvalue;
            precise = _type >= rhs.getType() ? _type : rhs.getType();
            return Parser::createOperand(precise, std::to_string(lhsvalue + rhsvalue));
        }

        // IOperand const * operator%( IOperand const & rhs ) const{
        //     std::stringstream   ss;
        //     eOperandType        precise;
        //     long double         rhsvalue;
        //     long double         lhsvalue;
        //     lhsvalue = _val;

        //     ss << rhs.toString();
        //     ss >> rhsvalue;
        //     precise = _type >= rhs.getType() ? _type : rhs.getType();
        //     return Parser::createOperand(precise, _val % rhsvalue);
        // }
};
#endif