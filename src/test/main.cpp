#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

typedef std::vector<std::string> strings;
// std::vector<std::string> fileToStrArray(std::string filename){

//     std::vector<std::string> lineArr;

//     std::ifstream file(filename); //open the file
//     std::string line = "";
//     if (file.is_open() && file.good()) {
//         std::cout << "File is now open!\nContains:\n";
//         std::string line = "";
//         while (getline(file, line)){
//             lineArr.push_back(line);
//             std::cout << line << std::endl;
//         }
//         return(lineArr);
        
//     } else {
//         std::cout << "Failed to open file..";
//         while (line != "end"){
//             std::cout << "Please Input Command :" << std::endl;
//             std::cin >> line ;
//         }
//     }
//     return;
// }
strings removeComments(strings lineIn){
    strings lineOut;
    std::istringstream out();
    int i = 0;
    int j; 
    while (i < lineIn.size()){
       std::istringstream o(lineIn[i]);
       o = lineIn[i].get(o, lineIn[i].length, ';');
    }
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
    size_t i = 0;
    while (i < lineIn.size()){
        std::cout << lineIn[i] << std::endl;
        i++;
    }
    strings removedComments;

    removedComments = removeComments(lineIn);
    i = 0;
    while (i < removedComments.size()){
        std::cout << removedComments[i] << std::endl;
        i++;
    }
    return 0;
}