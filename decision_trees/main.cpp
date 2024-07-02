#include <iostream>
#include <string.h>
#include <vector>
#include "rapidcsv.h"

rapidcsv::Document get_user_dataset();
void print_columns(rapidcsv::Document df);

int main(){
    rapidcsv::Document df = get_user_dataset();

    return 0;
}

rapidcsv::Document get_user_dataset(){
    // Print possible datasets
    std::cout << "Possible datasets:";
    system("ls data");

    return rapidcsv::Document();
}