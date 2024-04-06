#include "util.hpp"
#include <iostream>


void print_table(double tab[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

bool compare_tables(int t1[], int t2[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (t1[i] != t2[i])
        {
            return false;
        }
    }
    return true;
}

bool eq_double(double a, double b)
{
    return fabs(a - b) < EPSILON;
}
