#ifndef KMEANS_H_
#define KMEANS_H_
class KMeans{
private:
    float** values;
    float sq_distance(float* set1, float* set2, int length);
    int arr_argmin(float* arr, int arr_size);
    void label_counts(int size, std::vector<int> labels, int* output_array);
    void calculate_first_moments(int size, std::vector<int> labels, int* counts, int* output_array);
    void calculate_second_moments(int size, std::vector<int> labels, int* counts, float* means, int* output_array);

public:
    int k;

    int* generate_indices(int max);
    std::vector<int> label_points(array_wsize points, int* k_indices);
    float variance(array_wsize points, std::vector<int> labels);
    void set_values(float** points, int* k_indices);

    KMeans(int k);
    float** fit(float** points, int n = -1);
};
#endif