#ifndef KMEANS_H_
#define KMEANS_H_
class KMeans{
public:
    int k;
    float** values;

    float sq_distance(float* set1, float* set2);
    float** sq_distance(float** points, int length, int height);
    float variance(float** points, int* labels);
    int* generate_indices();
    int* label_points(float** points, int* k_indices);
    float** return_values(float** points, int* k_indices);
    KMeans(int k);
    float** fit(float** points, int n = -1);
};
#endif