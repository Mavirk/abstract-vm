#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "parser.hpp"
#include <typeinfo>
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
            if (type == Int8)
                _val = static_cast<int8_t>(stoi(str));
            else
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
            long double         value;
            
            ss << rhs.toString();
            ss >> value;
            precise = _type >= rhs.getType() ? _type : rhs.getType();
            value = value + _val;
            return Parser::createOperand(precise, value);
        }

        IOperand const * operator-( IOperand const & rhs ) const{
            std::stringstream   ss;
            eOperandType        precise;
            long double         value;
            
            ss << rhs.toString();
            ss >> value;
            precise = _type >= rhs.getType() ? _type : rhs.getType();
            value = value - _val;
            return Parser::createOperand(precise, value);
        }

        IOperand const * operator*( IOperand const & rhs ) const{
            std::stringstream   ss;
            eOperandType        precise;
            long double         value;
            
            ss << rhs.toString();
            ss >> value;
            precise = _type >= rhs.getType() ? _type : rhs.getType();
            value = value * _val;
            // std::cout <<"mul val "<< value << std::endl;
            return Parser::createOperand(precise, value);
        }

        IOperand const * operator/( IOperand const & rhs ) const{
            std::stringstream   ss;
            eOperandType        precise;
            long double         value;
            
            ss << rhs.toString();
            ss >> value;
            precise = _type >= rhs.getType() ? _type : rhs.getType();
            value = value / _val;
            return Parser::createOperand(precise, value);
        }

        IOperand const * operator%( IOperand const & rhs ) const{
            std::stringstream   ss;
            eOperandType        precise;
            int                 value;

            if (rhs.getType() >= Float || _type >= Float)
                throw MathError("Can't process modulo on decimal types");
            ss << rhs.toString();
            ss >> value;
            precise = _type >= rhs.getType() ? _type : rhs.getType();
            value = static_cast<int>(value) % static_cast<int>(_val);
            return Parser::createOperand(precise, value);
        }
};
#endif