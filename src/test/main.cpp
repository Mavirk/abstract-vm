#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

enum week { sunday, monday, tuesday, wednesday, thursday, friday, saturday };
std::vector<std::string> fileToStrArray(std::string filename){

    std::vector<std::string> lineArr;

    std::ifstream file(filename); //open the file
    std::string line = "";
    if (file.is_open() && file.good()) {
        std::cout << "File is now open!\nContains:\n";
        std::string line = "";
        while (getline(file, line)){
            lineArr.push_back(line);
            std::cout << line << std::endl;
        }
        return(lineArr);
        
    } else {
        std::cout << "Failed to open file..";
        while (line != "end"){
            std::cout << "Please Input Command :" << std::endl;
            std::cin >> line ;
        }
    }
    return;
}

int main(int argc, char* argv[])
{ 
    if (argc > 1) {
        std::cout << "Running File : " << argv[1] << std::endl;
    } else {
        std::cout << "No file name entered. Exiting...";
    }
    ifstream infile(argv[1]); //open the file
    
    if (infile.is_open() && infile.good()) {
        cout << "File is now open!\nContains:\n";
        string line = "";
        while (getline(infile, line)){
            cout << line << '\n';
        }
        
    } else {
        cout << "Failed to open file..";
    }
    return 0;
}
    enum week today;
    today = wednesday;
    printf("Day %d",today+1);
    return 0;
}