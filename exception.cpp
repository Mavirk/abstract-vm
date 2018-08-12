#include "Exceptions.hpp"

Exception::Exception(std::string const& msg): std::exception{
    _msg = msg;
    _type = "";
}