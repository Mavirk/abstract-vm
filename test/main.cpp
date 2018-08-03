#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


typedef int32_t i32;
typedef std::vector<std::string> strings;
typedef std::vector<i32> stack;



int lex(std::string in){
    // stack st;
    // size_t f;
    // size_t i = 0;
    // std::string curr;
    if (0 == in.find("push")){
        std::cout << "push command" << std::endl;
    }else if(0 == in.find("pop")){
        std::cout << "pop command" << std::endl;
    }else if(0 == in.find("dump")){
        std::cout << "dump command" << std::endl;
    }else if (0 == in.find("assert")){
        std::cout << "assert command" << std::endl;
    }else if (0 == in.find("add")){
        std::cout << "add command" << std::endl;
    }else if (0 == in.find("sub")){
        std::cout << "sub command" << std::endl;
    }else if (0 == in.find("mul")){
        std::cout << "mul command" << std::endl;
    }else if (0 == in.find("div")){
        std::cout << "div command" << std::endl;
    }else if (0 == in.find("mod")){
        std::cout << "mod command" << std::endl;
    }else if (0 == in.find("print")){
        std::cout << "print command" << std::endl;
    }else if (0 == in.find("exit")){
        std::cout << "exit command" << std::endl;
    }else {
        return -1;
    }

    return 0;
}

std::string removeComment(std::string s){
    std::string str;
    size_t i = 0;

    while (i < s.length()){
        if (s[i] == ';' ){
            while (s[i] != '\n'){
                i++;
            }
        }else{
            str += s[i];
        }
        i++;
    }
    return (str);
}

int main(int argc, char* argv[]) 
{
    strings lineIn;
    if (argc > 1) {
        std::cout << "Running File : " << argv[1] << std::endl;
        
        std::ifstream infile(argv[1]); //open the file

        if (infile.is_open() && infile.good()) {
            std::cout << "File is now open!\nContains:\n";
            std::string line = "";
            while (getline(infile, line)){
                lineIn.push_back(line);
            }
       } else{
           std::cout << "ERROR: file " << argv[1] << " does not exist"  << std::endl;
           return 0;
       }
    } else {
        std::cout << "No file name entered......";
        std::cout << "Please enter the program line my line" << std::endl << "use the ';;' command on it own to end input mode" << std::endl;
        std::string line = "";
        while(line != ";;"){
            std::cin >> line;
            lineIn.push_back(line);
        }
    }
    // std::cout << "this is  a test" std::endl;
    // remove comments from all lines
    //
    // std::cout << "input looks like::" << std::endl;
    size_t i = 0;
    while (i < lineIn.size()){
        // std::cout << lineIn[i] << "" << std::endl;
        i++;
    }
    std::string instr;
    // std::cout << "removing comments" << std::endl;
    i = 0;
    std::string s;
    while (i < lineIn.size()){
        s = removeComment(lineIn[i]);
        if (!s.empty()){
            instr = s;
            if (lex(s) == -1){
                std::cout << "ERROR" << std::endl;
            }
        }
        i++;
    }
    i = 0;
    while (i < instr.size()){
        std::cout << instr[i] << std::endl; 
        i++;
    }
    // i = 0;
    // while (i < rmCom.size()){
    //     std::cout << rmCom[i] << std::endl;
    //     i++;
    // }
    // return 0;
}