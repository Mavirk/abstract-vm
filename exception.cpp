#include "Exceptions.hpp"

Exception::Exception(std::string const& msg): std::exception{
    _msg = msg;
    _type = "";
}
Exception::~Exception() throw() {}

const char *Exception::what() throw() {
    return (_type + _msg).data();
}

LexParseError::LexParseError(std::string const& msg) :Exception(msg) {
    _type = "Lex/Parse Error : ";
}
UnknownInstruction::UnknownInstruction(std::string const& msg) :Exception(msg) {
    _type = "Lex/Parse Error : ";
}
Overflow::Overflow(std::string const& msg) :Exception(msg) {
    _type = "Lex/Parse Error : ";
}
Underflow::Underflow(std::string const& msg) :Exception(msg) {
    _type = "Underflow Error : ";
}
PopOnEmpty::PopOnEmpty(std::string const& msg) :Exception(msg) {
    _type = "Pop on Empty Stack Error : ";
}
DivByZero::DivByZero(std::string const& msg) :Exception(msg) {
    _type = "Divide by Zero Error : ";
}
NoExit::NoExit(std::string const& msg) :Exception(msg) {
    _type = "Exit Error : ";
}
AssertFalse::AssertFalse(std::string const& msg) :Exception(msg) {
    _type = "Assert Error";
}
StackLessThan2::StackLessThan2(std::string const& msg) :Exception(msg) {
    _type = "Stack Error ; ";
}