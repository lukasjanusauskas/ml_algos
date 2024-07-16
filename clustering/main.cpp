#include <iostream>
#include "read.h"
#include "matplotlib.h"

int main(){
    rapidcsv::Document df = get_user_dataset();

    std::cout << "Available columns:" << "\n";
    for (std::string column: df.GetColumnNames())
        std::cout << column << " ";

    // std::vector<int> train_columns = get_columns(df);

    return 0;
}