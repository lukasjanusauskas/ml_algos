#include<iostream>
#include <string.h>
#include <vector>
#include <set>
#include "rapidcsv.h"

struct array_wsize{
    float** arr;
    int nrow;
    int ncol;
};

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

std::vector<int> get_columns(rapidcsv::Document df){
    std::set<int> cols; 

    std::vector<std::string> all_cols = df.GetColumnNames();

    int index = -1;
    while(index != 0){
        std::cout << "Choose a column(input a number) or input 0 to " << std::endl;

        for(int i = 0; i < all_cols.size(); i++)
            std::cout << i+1 << "\t" << all_cols.at(i) << " ";
        std::cout << std::endl;

        std::cin >> index;
        cols.insert(index);
    }

    std::vector<int> indices;
    for(int col_index: cols){
        if(col_index == 0) continue;
        indices.push_back(col_index - 1);
    }

    return indices;
}

array_wsize parse_into_array(rapidcsv::Document df, std::vector<int> columns){
    int arr_size = columns.size();
    std::vector<float>* tmp_vector = new std::vector<float>[arr_size];

    // TODO: add type checking
    for(int i = 0; i < arr_size; i++){
        const std::size_t index = columns.at(i);

        tmp_vector[i] = df.GetColumn<float>(index);
    }

    int row_size = tmp_vector[0].size();

    float** final_array = (float**)malloc(sizeof(float*) * row_size);
    for(int i = 0; i < row_size; i++)
        final_array[i] = (float*)malloc(sizeof(float) * arr_size);


    for(int i = 0; i < row_size; i++)
        for(int j = 0; j < arr_size; j++)
            final_array[i][j] = tmp_vector[j].at(i);

    array_wsize res = {final_array, row_size, arr_size};

    return res;
}