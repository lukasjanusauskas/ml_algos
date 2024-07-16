#include<iostream>
#include <string.h>
#include <vector>
#include "rapidcsv.h"

rapidcsv::Document get_user_dataset();
void print_columns(rapidcsv::Document df);
std::vector<std::string> get_datasets();
void print_datasets();
std::vector<int> get_columns(rapidcsv::Document df);

void print_datasets(){
    std::cout << "Possible datasets:\n";
    int code = system("ls data");

    if(code != 0) exit(EXIT_FAILURE);
}

std::vector<std::string> get_datasets(){
    int code = system("ls data >> tmp.txt");

    if(code != 0) exit(EXIT_FAILURE);

    std::ifstream fr("tmp.txt");
    std::vector<std::string> files; 

    for(std::string s; std::getline(fr, s);)
        files.push_back(s);

    fr.close(); system("rm tmp.txt");

    return files;
}

rapidcsv::Document get_user_dataset(){
    print_datasets();
    std::vector<std::string> files = get_datasets();

    int index = __INT16_MAX__;
    while(index >= files.size()){
        std::cout << "Choose, which will be used for the decision tree" << std::endl;
        std::cin >> index;
    }

    std::string path = std::string("data/") + files.at(index);

    return rapidcsv::Document(path);
}