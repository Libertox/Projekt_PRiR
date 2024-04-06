#include "util.hpp"
#include <random>

Random::Random()
{
    this->dfe = std::default_random_engine(time(NULL));
}

Random::Random(uint seed)
{
    this->dfe = std::default_random_engine(seed);
}

Random::~Random() {}

int Random::get_random(int low_bound, int top_bound)
{
    std::uniform_int_distribution<> distrib(low_bound, top_bound);
    return distrib(this->dfe);
}

double Random::get_random(double low_bound, double top_bound)
{
    std::uniform_real_distribution<double> distrib(low_bound, top_bound);
    return distrib(this->dfe);
}

void Random::fill_tab_with_randoms(int tab[], uint size, int low_bound, int top_bound)
{
    for (int i = 0; i < size; ++i)
        tab[i] = this->get_random(low_bound, top_bound);
}

void Random::fill_tab_with_randoms(double tab[], uint size, double low_bound, double top_bound)
{
    for (int i = 0; i < size; ++i)
        tab[i] = this->get_random(low_bound, top_bound);
}
