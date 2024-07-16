#include <iostream>
#include "read.h"
#include "kmeans.h"
#include "matplotlib.h"

int main(){
    rapidcsv::Document df = get_user_dataset();

    std::cout << "Available columns:" << "\n";

    KMeans kmn = KMeans(3);

    float arr[2][3] = {
        {1, 2, 3},
        {3, 2, 1}
    };

    float** dist = kmn.sq_distance(arr, 2, 3);
    for (int i = 0; i < 2; i ++)
        for(int j = 0; j < 3; j++)
            std::cout << arr[i][j] << "\n";

    // std::vector<int> train_columns = get_columns(df);

    return 0;
}