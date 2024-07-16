#ifndef READ_H_
#define READ_H_

#include "rapidcsv.h"
#include<iostream>

rapidcsv::Document get_user_dataset();
void print_columns(rapidcsv::Document df);
std::vector<std::string> get_datasets();
void print_datasets();
std::vector<int> get_columns(rapidcsv::Document df);
float** parse_into_array(rapidcsv::Document df, int* columns);

#endif