#pragma once

#include <iostream>
#include <vector>
#include <string>

// https://stackoverflow.com/a/17440673
class Timing
{
private:
    std::vector<double> wt_timestamp_log;
    std::vector<double> cpu_timestamp_log;

public:
    Timing();
    ~Timing();

    static void print_impl_info()
    {
        #ifdef _WIN32
            std::cout << "Timing::init::WIN" << std::endl;
        #else
            std::cout << "Timing::init::UNX" << std::endl;
        #endif
    }

    double get_wt_timestamp();
    double get_cpu_timestamp();

    uint get_log_count();
    double get_wt_timedelta(uint idx_start, uint idx_end);
    double get_cpu_timedelta(uint idx_start, uint idx_end);
    std::string get_summary_timedelta(uint idx_start, uint idx_end);

    uint log_timestamp();
};
