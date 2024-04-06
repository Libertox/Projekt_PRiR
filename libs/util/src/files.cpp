#include "util.hpp"


size_t get_next_data_chunk_size(size_t glob_idx, size_t fsize, Random rdm)
{
    size_t val = (size_t)rdm.get_random(90000, 100000);
    if (glob_idx + val > fsize)
        return fsize - glob_idx;
    else
        return val;
}
