#include "read.h"
#include "kmeans.h"

#include<time.h>
#include <algorithm>
#include<random>
#include<set>

KMeans::KMeans(int k){
    this->k = k;     
}

float KMeans::sq_distance(float* set1, float* set2, int length){
    // Calculate the square distance between them
    float res = 0;
    for (int i = 0; i < length; i++)
        res += (set1[i] - set2[i]) * (set1[i] - set2[i]);

    return res;
}

int* KMeans::generate_indices(int max){
    srand(time(NULL));
    std::set<int> indices;

    for(int i = 0; i < this->k; i++)
        indices.insert(rand() % max);

    int* index_array = new int[this->k];

    int i = 0;
    for(int index: indices)
        index_array[i++] = index;

    return index_array;
}

int arr_argmin(float* arr, int arr_size){
    return std::min_element(arr, arr+arr_size) - arr;
}

std::vector<int> KMeans::label_points(array_wsize points, int* k_indices){
    std::vector<int> labels;
    float* k_candidates = new float[this->k];
    float** data = points.arr;

    for(int arr_ind = 0; arr_ind < points.nrow; arr_ind++){
        // Calculates distances between cluster point and the arr_ind'th point
        for(int i = 0; i < this->k; i++)
            k_candidates[i] = sq_distance(data[arr_ind], data[k_indices[i]], points.ncol);

        int argmin = arr_argmin(k_candidates, this->k);
        labels.push_back(argmin);
    }

    return labels;
}

// void label_counts(int size, std::vector<int> labels, int* output_array){
//     for(int i = 0; i < size; i++){
//         int label = labels.at(i);
//         output_array[label]++;
//     }
// }

// void calculate_first_moments(int size, std::vector<int> labels, int* counts, int* output_array){
//     for(int i = 0; i < size; i++){

//     }
// }

// float KMeans::variance(array_wsize points, std::vector<int> labels){
//     int* counts = new int[this->k];
//     float* first_moments = new float[this->k];
//     float* second_moments = new float[this->k];


//     return 0;
// }

// TODO: Finish the final function and fix the fit function
// float** KMeans::set_values(array_wsize points, int* k_indices);

// float** KMeans::fit(arr_wsize points, int n){
//     if(n == -1)
//         n = sizeof(points) / sizeof(points[0]);

//     float* variances = (float*)malloc(n * sizeof(float));
//     int** all_indices = (int**)malloc(this->k * sizeof(int));

//     for (int i = 0; i < n; i++){
//         int* indices = generate_indices();
//         all_indices[i] = indices;

//         int* labels = label_points(points, indices);

//         variances[i] = variance(points, indices);
//     }

//     return KMeans::return_values(points, all_indices[0]);
// }