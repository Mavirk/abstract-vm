#include "exception.hpp"

Exception::Exception(std::string const& msg): std::exception(){
    _msg = msg;
    _type = "";
}

Exception::~Exception() throw() {}

const char *Exception::what() const throw() {
    return (_type + _msg).data();
}

LexParseError::LexParseError(std::string const& msg) :Exception(msg) {
    _type = "Lex/Parse Error : ";
}
UnknownInstruction::UnknownInstruction(std::string const& msg) :Exception(msg) {
    _type = "Unknown Instruction Error : ";
}
Overflow::Overflow(std::string const& msg) :Exception(msg) {
    _type = "Overflow Error : ";
}
Underflow::Underflow(std::string const& msg) :Exception(msg) {
    _type = "Underflow Error : ";
}
StackError::StackError(std::string const& msg) :Exception(msg) {
    _type = "Stack Error : ";
}
LogicalError::LogicalError(std::string const& msg) :Exception(msg) {
    _type = "Logical Error : ";
}
InputError::InputError(std::string const& msg) :Exception(msg) {
    _type = "Input Error : ";
}
NoExit::NoExit(std::string const& msg) :Exception(msg) {
    _type = "Exit Error : ";
}
AssertFalse::AssertFalse(std::string const& msg) :Exception(msg) {
    _type = "Assert Error : ";
}
StackLessThan2::StackLessThan2(std::string const& msg) :Exception(msg) {
    _type = "Stack Error ; ";
}