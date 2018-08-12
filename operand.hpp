#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "Ioperand.hpp"
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
            eOperandType        precise;
            long double         rhsvalue;

            ss << rhs.toString();
            ss >> rhsvalue;
            precise = _type >= rhs.getType() ? _type : rhs.getType;
            return Parser::createOperand(precise, _value + rhsvalue)
        }

        IOperand const * operator-( IOperand const & rhs ) const{
            std::stringstream   ss;
            eOperandType        precise;
            long double         rhsvalue;

            ss << rhs.toString();
            ss >> rhsvalue;
            precise = _type >= rhs.getType() ? _type : rhs.getType;
            return Parser::createOperand(precise, _value - rhsvalue)
        }

        IOperand const * operator*( IOperand const & rhs ) const{
            std::stringstream   ss;
            eOperandType        precise;
            long double         rhsvalue;

            ss << rhs.toString();
            ss >> rhsvalue;
            precise = _type >= rhs.getType() ? _type : rhs.getType;
            return Parser::createOperand(precise, _value * rhsvalue);
        }

        IOperand const * operator/( IOperand const & rhs ) const{
            std::stringstream   ss;
            eOperandType        precise;
            long double         rhsvalue;

            ss << rhs.toString();
            ss >> rhsvalue;
            precise = _type >= rhs.getType() ? _type : rhs.getType;
            return Parser::createOperand(precise, _value / rhsvalue)
        }

        IOperand const * operator%( IOperand const & rhs ) const{
            std::stringstream   ss;
            eOperandType        precise;
            long double         rhsvalue;

            ss << rhs.toString();
            ss >> rhsvalue;
            precise = _type >= rhs.getType() ? _type : rhs.getType;
            return Parser::createOperand(precise, _value % rhsvalue)
        }
};
#endif