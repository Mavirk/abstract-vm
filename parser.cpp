#include "parser.hpp"
#include "operand.hpp"

IOperand const *
Parser::createOperand(eOperandType type, std::string const & value ){

    IOperand    *(*fptr[])(std::string const & value) = {&createInt8//,
                                                        // &createInt16,
                                                        // &createInt32, 
                                                        // &createFloat, 
                                                        // &createDouble
                                                        };
    return fptr[type](value);
}

IOperand const*
Parser::operand(std::string const &str){
    std::map<std::string, eOperandType>     ops;
    
    // std::cout << "str :";
    // std::cout << str << std::endl;
    ops["int8"] = Int8;
    ops["int16"] = Int16;
    ops["int32"] = Int32;
    ops["float"] = Float;
    ops["double"] = Double;
    std::string	type, value;
    type = str.substr(0, str.find("("));
    value = str.substr(str.find("(") + 1, str.find(")") - str.find("(") - 1);
    // std::cout << type <<std::endl;
    if (ops.find(type) == ops.end())
        throw LexParseError("Unknown type : " + type);
    return Parser::createOperand(ops[type], value);

}
// void
// Parser::checkPushAssert(std::vector<Lexeme> lexemes){

//     ops["int8"] = Int8;
//     ops["int16"] = Int16;
//     ops["int32"] = Int32;
//     ops["float"] = Float;
//     ops["double"] = Double;

//     std::string sub;
//     for (size_t i = 0; i < lexemes.size(); i++){
//         if (lexemes[i].value == "push" || "assert"){
//             if ((i + 1) < lexemes.size()){
//                 sub = lexemes[i + 1].value;
//                 sub = sub.substr(0, sub.find("("));
//                 if (ops.find(sub) == ops.end())
//                     throw LexParseError("Push/Assert with No type or Unkwon type : " + lexemes[i].value + sub);
//             }else{
//                 throw NoExit("Push/Assert is last instruction");
//             }
//         }
//     }
// }

IOperand*
Parser::createInt8(const std::string& value){
    IOperand*           ret;
    std::stringstream   ss;
    long double         val;

    ss.str(value);
    ss >> val;
    if (val < std::numeric_limits<signed char>::min() || val > std::numeric_limits<signed char>::max())
        std::cout << "Erro of type : Overflow or Underflow for value " << value  << "doesnt fit into an int8";
    ret = new Operand<char>(Int8, value);
    return ret;
}

IOperand*
Parser::createInt16(const std::string& value){
    IOperand*           ret;
    std::stringstream   ss;
    long double         val;

    ss.str(value);
    ss >> val;
    if (val < std::numeric_limits<short>::min() || val > std::numeric_limits<short>::max())
        std::cout << "Erro of type : Overflow or Underflow for value " << value  << "doesnt fit into an int16";
    ret = new Operand<short>(Int16, value);
    return ret;
}

IOperand*
Parser::createInt32(const std::string& value){
    IOperand*           ret;
    std::stringstream   ss;
    long double         val;

    ss.str(value);
    ss >> val;
    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        std::cout << "Erro of type : Overflow or Underflow for value " << value  << "doesnt fit into an int32";
    ret = new Operand<int>(Int32, value);
    return ret;
}

IOperand*
Parser::createFloat(const std::string& value){
    IOperand*           ret;
    std::stringstream   ss;
    long double         val;

    ss.str(value);
    ss >> val;
    if (val < std::numeric_limits<float>::min() || val > std::numeric_limits<float>::max())
        std::cout << "Erro of type : Overflow or Underflow for value " << value  << "doesnt fit into an float";
    ret = new Operand<float>(Float, value);
    return ret;
}

IOperand*
Parser::createDouble(const std::string& value){
    IOperand*           ret;
    std::stringstream   ss;
    long double         val;

    ss.str(value);
    ss >> val;
    if (val < std::numeric_limits<double>::min() || val > std::numeric_limits<double>::max())
        std::cout << "Erro of type : Overflow or Underflow for value " << value  << "doesnt fit into an double";
    ret = new Operand<double>(Double, value);
    return ret;
}