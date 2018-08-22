#ifndef AVM_HPP
#define AVM_HPP
#include "parser.hpp"
#include "lexer.hpp"
#include "exception.hpp"
#include "operand.hpp"
#include <iostream>
#include <stack>
#include <map>

#ifndef UNUSED
#define UNUSED __attribute__((unused))
#endif

class AVM {
    public:
        AVM(std::string filename = NULL);
        ~AVM();
        AVM(const AVM& obj);
        AVM	    &operator=(const AVM & vm);
       
        void    run();
        void	push(std::string const &str);
        void	pop(std::string const &str);
        void	dump(std::string const &str);
        void	ass(std::string const &str);
        void	add(std::string const &str);
        void	sub(std::string const &str);
        void	mul(std::string const &str);
        void	div(std::string const &str);
        void	mod(std::string const &str);
        void	print(std::string const &str);
        void	exit(std::string const &str);
        std::vector<Lexeme>                                         _lexemes;
        bool								                        _end;
        std::string							                        _buf;
        std::stack<IOperand const *>						        _stack;
        std::map<std::string, void (AVM::*)(std::string const &)>	_fptr;
};
#endif

