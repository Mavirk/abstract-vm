#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <string>
#include <exception>

class Exception : public std::exception{
    protected:
        std::string _msg;
        std::string _type;
    
    public:
        Exception(std::string const& msg);
        ~Exception() throw();

        const char* what() const throw();
};

class LexParseError : public Exception{
    public:
        LexParseError(std::string const &msg);
};

class UnknownInstruction : public Exception{
    public:
        UnknownInstruction(std::string const &msg);
};

class Overflow : public Exception{
    public:
        Overflow(std::string const &msg);
};

class Underflow : public Exception{
    public:
        Underflow(std::string const &msg);
};

class PopOnEmpty : public Exception{
    public:
        PopOnEmpty(std::string const &msg);
};

class DivByZero : public Exception{
    public:
        DivByZero(std::string const &msg);
};

class NoExit : public Exception{
    public:
        NoExit(std::string const &msg);
};

class AssertFalse : public Exception{
    public:
        AssertFalse(std::string const &msg);
};

class StackLessThan2 : public Exception{
    public:
        StackLessThan2(std::string const &msg);
};
#endif