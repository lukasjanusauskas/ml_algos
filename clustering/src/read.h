#ifndef READ_H_
#define READ_H_

#include "rapidcsv.h"
#include<iostream>

struct array_wsize{
    float** arr;
    int nrow;
    int ncol;
};

rapidcsv::Document get_user_dataset();
void print_columns(rapidcsv::Document df);
std::vector<std::string> get_datasets();
void print_datasets();
std::vector<int> get_columns(rapidcsv::Document df);
array_wsize parse_into_array(rapidcsv::Document df, std::vector<int> columns);

#endif