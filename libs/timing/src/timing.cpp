#include "timing.hpp"
#include <sstream>
#include <iomanip>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <time.h>
    #include <sys/time.h>
#endif

Timing::Timing()
{
    this->wt_timestamp_log.push_back(this->get_wt_timestamp());
    this->cpu_timestamp_log.push_back(this->get_cpu_timestamp());
}

Timing::~Timing() {}

double Timing::get_wt_timestamp()
{
    #ifdef _WIN32
        LARGE_INTEGER time, freq;
        if (!QueryPerformanceFrequency(&freq))
        {
            //  Handle error
            return 0;
        }
        if (!QueryPerformanceCounter(&time))
        {
            //  Handle error
            return 0;
        }
        return (double)time.QuadPart / freq.QuadPart;
    #else
        struct timeval time;
        if (gettimeofday(&time, NULL))
        {
            //  Handle error
            return 0;
        }
        return (double)time.tv_sec + (double)time.tv_usec * .000001;
    #endif
}

double Timing::get_cpu_timestamp()
{
    #ifdef _WIN32
        FILETIME a, b, c, d;
        if (GetProcessTimes(GetCurrentProcess(), &a, &b, &c, &d) != 0)
        {
            //  Returns total user time.
            //  Can be tweaked to include kernel times as well.
            return (double)(d.dwLowDateTime |
                            ((unsigned long long)d.dwHighDateTime << 32)) *
                0.0000001;
        }
        else
        {
            //  Handle error
            return 0;
        }
    #else
        return (double)clock() / CLOCKS_PER_SEC;
    #endif
}

uint Timing::get_log_count()
{
    return this->wt_timestamp_log.size();
}

uint Timing::log_timestamp()
{
    this->wt_timestamp_log.push_back(this->get_wt_timestamp());
    this->cpu_timestamp_log.push_back(this->get_cpu_timestamp());

    return this->get_log_count() - 1;
}

double Timing::get_wt_timedelta(uint idx_start, uint idx_end)
{
    if (this->get_log_count() <= idx_start || idx_end < idx_start)
        throw std::range_error("Invalid index values");
    return this->wt_timestamp_log[idx_end] - this->wt_timestamp_log[idx_start];
}

double Timing::get_cpu_timedelta(uint idx_start, uint idx_end)
{
    if (this->get_log_count() <= idx_start || idx_end < idx_start)
        throw std::range_error("Invalid index values");
    return this->cpu_timestamp_log[idx_end] - this->cpu_timestamp_log[idx_start];
}

std::string Timing::get_summary_timedelta(uint idx_start, uint idx_end)
{
    std::ostringstream summary;
    summary << std::setprecision(15);
    summary << "WT: " << this->get_wt_timedelta(idx_start, idx_end);
    summary << "   CPU: " << this->get_cpu_timedelta(idx_start, idx_end);
    return summary.str();
}
