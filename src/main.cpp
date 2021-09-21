#include <omp.h>
#include <iostream>
  
int main(int argc, char* argv[])
{
    int nthreads, tid;
    #pragma omp parallel private(nthreads, tid)
    {
        // Getting thread number
        tid = omp_get_thread_num();
        #pragma omp critical
        {
            std::cout << "OpenMP boilerplate code from thread = " << tid << std::endl;
        }        
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            std::cout << "Total number of threads = " << nthreads << std::endl;
        }
    }
}