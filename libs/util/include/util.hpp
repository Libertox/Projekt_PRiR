#pragma once
#include <random>

#define EPSILON 0.000000001

void print_table(double tab[], int size);

bool compare_tables(int t1[], int t2[], int size);

bool eq_double(double a, double b);

class Random
{
private:
    std::default_random_engine dfe;

public:
    Random();
    Random(uint seed);
    ~Random();

    int get_random(int low_bound, int top_bound);
    double get_random(double low_bound, double top_bound);

    void fill_tab_with_randoms(int tab[], uint size, int low_bound, int top_bound);
    void fill_tab_with_randoms(double tab[], uint size, double low_bound, double top_bound);
};

size_t get_next_data_chunk_size(size_t glob_idx, size_t fsize, Random rdm);
