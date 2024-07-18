#include <iostream>
#include <algorithm>

#include "read.h"
#include "kmeans.h"
// #include "matplotlib.h"

int main(){
    rapidcsv::Document df = get_user_dataset();

    std::vector<int> indices = get_columns(df);

    array_wsize points = parse_into_array(df, indices);
    
    KMeans kmn = KMeans(3);
    int* k_ind = kmn.generate_indices(points.nrow);
    std::vector<int> labels = kmn.label_points(points, k_ind);

    for(int i: labels)
        std::cout << i << " ";

    std::cout << std::endl;
    return 0;
}