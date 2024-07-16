#include "read.h"
#include "kmeans.h"

KMeans::KMeans(int k){
    k = k;     
}

float KMeans::sq_distance(float* set1, float* set2){
    // Calculate teh lengths of the arrays
    int len1 = sizeof(set1) / sizeof(set1[0]);
    int len2 = sizeof(set1) / sizeof(set2[0]);

    // Check, if they are the same size
    if (len1 != len2)
        exit(EXIT_FAILURE);

    // Calculate the square distance between them
    float res = 0;
    for (int i = 0; i < len1; i++)
        res += (set1[i] - set2[i]) * (set1[i] - set2[i]);

    return res;
}

float** KMeans::sq_distance(float** points, int length, int height){
    // Allocate two dimensional array for dist
    float** dist = (float**)malloc(length * sizeof(float*));
    for(int i = 0; i < length; i++) 
        dist[i] = (float*)malloc(length * sizeof(float));

    // Calculate distances
    for (int i = 0; i < length; i++){
        for (int j = i; j < length; j++){
            dist[i][j] = sq_distance(points[i], points[j]);
            dist[j][i] = dist[i][j];
        }
    }

    return dist;
}

// TODO: wriet implementations of these functions

// float KMeans::variance(float** points, int* labels);
// int* KMeans::generate_indices();
// int* KMeans::label_points(float** points, int* k_indices);
// float** KMeans::return_values(float** points, int* k_indices);
    
// TODO: after writing the implementations, finidh and test this function

// float** KMeans::fit(float** points, int n){
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