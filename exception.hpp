#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <string>
#include <exception>

class Exception : public std::exception{
    public:
        std::string _msg;
        std::string _type;
        Exception(std::string const& msg);
        ~Exception() throw();

        char* what() throw();
};

class LexError : public Exception{
    public:
        LexError(std::string const &msg);
}

#endif