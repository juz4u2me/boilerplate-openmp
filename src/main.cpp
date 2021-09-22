#include <omp.h>
#include <iostream>
#include <vector>
#include "mc4d.h"
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/median.hpp>
#include <boost/accumulators/statistics/variance.hpp>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
using namespace boost::accumulators;
  
int main(int argc, char* argv[])
{
    std::srand(time(NULL));
    int numIter = 1000000;
    accumulator_set<int, stats<tag::variance, tag::mean, tag::median> > outcomes;
    int nthreads, tid;
    const double t0 = omp_get_wtime();    
    #pragma omp parallel private(nthreads, tid) 
    {
        tid = omp_get_thread_num();
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            std::cout << "Total number of threads = " << nthreads << std::endl;
        }
        #pragma omp for
            for(int i=0; i<numIter; ++i) {
                MC4D d;
                // d.display();
                int prize = d.run(2886, 1);
                #pragma omp critical
                {
                    outcomes(prize);
                }
            }
    }
    const double t1 = omp_get_wtime();
    const double ts   = t1-t0; // time in seconds
    const double tms  = ts*1.0e3; // time in milliseconds

    std::cout << "Mean: " << mean(outcomes) << std::endl;
    std::cout << "Median: " << median(outcomes) << std::endl;
    std::cout << "Std Dev: " << sqrt(variance(outcomes)) << std::endl;
    std::cout << "Time taken: " << tms << std::endl;

    // int nthreads, tid;
    // #pragma omp parallel private(nthreads, tid)
    // {
    //     // Getting thread number
    //     tid = omp_get_thread_num();
    //     #pragma omp critical
    //     {
    //         std::cout << "OpenMP boilerplate code from thread = " << tid << std::endl;
    //     }        
    //     if (tid == 0) {
    //         nthreads = omp_get_num_threads();
    //         std::cout << "Total number of threads = " << nthreads << std::endl;
    //     }
    // }
}