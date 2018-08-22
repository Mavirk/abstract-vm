#include "avm.hpp"

AVM::AVM(std::string filename){
    std::ifstream f(filename);
    _end = false;
    std::string line;
    std::vector<std::string> raw;

    if(filename.empty() || !f.good()){
        std::cout << "Input Error : Invalid File ... Starting Manual Input Mode" << std::endl;
        while (line != ";;"){
            std::getline(std::cin, line);
            line += '\n';
            if (line != ";;")
                raw.push_back(line);
            else
                raw.push_back("exit\n");
        }
    }else if (f.is_open()){
        while (getline(f, line)){
            line += '\n';
            raw.push_back(line);    
        }
    }else
        throw InputError("Unforseen error");

    Lexer   lexer(raw);
    lexer.run();
    _lexemes = lexer.getLexemes();
    
    _fptr["push"] = &AVM::push;
    _fptr["pop"] = &AVM::pop;
    _fptr["dump"] = &AVM::dump;
    _fptr["assert"] = &AVM::ass;
    _fptr["add"] = &AVM::add;
    _fptr["sub"] = &AVM::sub;
    _fptr["mul"] = &AVM::mul;
    _fptr["div"] = &AVM::div;
    _fptr["mod"] = &AVM::mod;
    _fptr["print"] = &AVM::print;
    _fptr["exit"] = &AVM::exit;
}

AVM::~AVM(){}

AVM::AVM(const AVM& obj){
    *this = obj;
}

AVM &
AVM::operator=(const AVM & vm){
    if (this != &vm) {
        _end = vm._end;
        _buf = vm._buf;
        _stack = vm._stack;
        _fptr = vm._fptr;
    }
    return *this;
}

void
AVM::run(){
    bool error = false;
    for(size_t x = 0; x < _lexemes.size(); x++){
        if (_lexemes[x].type == -1){
            error = true;
            std::cout << "ERROR : on line " << _lexemes[x].l << " " << _lexemes[x].value << std::endl;
        }
    }
    for(size_t i = 0; i < _lexemes.size(); i++){
        if (!error){    
            if (_lexemes[i].value == "push" || _lexemes[i].value == "assert"){
                if (i + 1 < _lexemes.size()){
                    (this->*_fptr[_lexemes[i].value])(_lexemes[i + 1].value);
                    i++;
                }else{
                    throw NoExit("no exit was found");
                }
            }else{
                (this->*_fptr[_lexemes[i].value])("");
            }
        }
    }
    if (error){
        throw InputError("Error(s) found");
    }
    if (_end)
        return;
    throw NoExit("NO exit was found");
}
void
AVM::push(std::string const &str){
    std::cout << "PUSH : ";
    _stack.emplace(Parser::operand(str));
    std::cout << _stack.top()->toString() << std::endl;
}
void
AVM::pop(std::string const &str UNUSED){
    std::cout << "POP : ";
    std::cout << _stack.top()->toString() << std::endl;
    if (_stack.empty())
        throw StackError("Pop on empty");
    _stack.pop();
}
void
AVM::dump(std::string const &str UNUSED){
    std::cout << "DUMP : " << std::endl;
    std::cout << "======" << std::endl;
    std::stack<IOperand const *> s = _stack;
    while (!s.empty()){
        switch(s.top()->getType()){
            case 0 : std::cout << "Int8 ";
                    break;
            case 1 : std::cout << "Int16 ";
                    break;
            case 2 : std::cout << "Int32 ";
                    break;
            case 3 : std::cout << "Float ";
                    break;
            case 4 : std::cout << "Double ";
                    break;
        } 
        std::cout << s.top()->toString() << std::endl;
        s.pop();
    }
    std::cout << "======" << std::endl;
}
void
AVM::ass(std::string const &str){
    std::cout << "ASSERT : ";
    IOperand const		*cmp = Parser::operand(str);
    std::cout << _stack.top()->toString() << std::endl;
    if (_stack.top()->getType() != cmp->getType()
        || _stack.top()->toString() != cmp->toString()){
            throw AssertFalse(str + "cannot be asserted to top of stack");
        }
}
void
AVM::add(std::string const &str UNUSED){
    std::cout << "ADD : ";
    IOperand const   *a, *b;
    if (_stack.size() < 2)
        throw StackLessThan2("");
    a = _stack.top();
    std::cout << _stack.top()->toString();
    _stack.pop();
    b = _stack.top();
    std::cout << " + " << _stack.top()->toString();
    _stack.pop();
    _stack.emplace(*a + *b);
    std::cout << " = " << _stack.top()->toString() << std::endl;
    // std::cout << _stack.top()->toString() << std::endl;
}
void
AVM::sub(std::string const &str UNUSED){
    std::cout << "SUB : ";
    IOperand const   *a, *b;
    if (_stack.size() < 2)
        throw StackLessThan2("");
    a = _stack.top();
    std::cout << a->toString();
    _stack.pop();
    b = _stack.top();
    std::cout << " - " << b->toString();
    _stack.pop();
    _stack.emplace(*b - *a);
    std::cout << " = " << _stack.top()->toString() << std::endl;
}
void
AVM::mul(std::string const &str UNUSED){
    std::cout << "MUL : ";
    IOperand const   *a, *b;
    if (_stack.size() < 2)
        throw StackLessThan2("");
    a = _stack.top();
    std::cout << _stack.top()->toString();
    _stack.pop();
    b = _stack.top();
    std::cout << " * " << _stack.top()->toString();
    _stack.pop();
    _stack.emplace(*a * *b);
    std::cout << " = " << _stack.top()->toString() << std::endl;

}
void
AVM::div(std::string const &str UNUSED){
    std::cout << "DIV : ";
    IOperand const   *a, *b;
    if (_stack.size() < 2)
        throw StackLessThan2("");
    a = _stack.top();
    std::cout << _stack.top()->toString();
    _stack.pop();
    b = _stack.top();
    std::cout << " / " << _stack.top()->toString();
    _stack.pop();
    if (b->toString() == "0"){
        std::cout << "\n";
        throw MathError("Div by zero");
    }    
    _stack.emplace(*b / *a);
    std::cout << " = " << _stack.top()->toString() << std::endl;

}

void
AVM::mod(std::string const &str UNUSED){
    std::cout << "MOD : ";
    IOperand const   *a, *b;
    if (_stack.size() < 2)
        throw StackLessThan2("");
    a = _stack.top();
    std::cout << _stack.top()->toString();
    _stack.pop();
    b = _stack.top();
    std::cout << " % " << _stack.top()->toString();
    _stack.pop();
    if (b->toString() == "0"){
        std::cout << "\n";
        throw MathError("Mod by zero");
    }
    _stack.emplace(*b % *a);
    std::cout << " = " << _stack.top()->toString() << std::endl;
}
void
AVM::print(std::string const &str UNUSED){
    std::cout << "PRINT : ";
    if (_stack.top()->getType() != Int8){
        throw LogicalError("Cant print non-int8 value");
    }
    std::cout << _stack.top()->toString() << std::endl; 
}
void
AVM::exit(std::string const &str UNUSED){
    std::cout << "EXIT : " << std::endl;
    _end = true;
}