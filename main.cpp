#include <../omp.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

int main()
{
    system("cls");
    //define variables
    int i = 0,n,input_pi;
    double sum = 0.0;
    printf("Input threads\n");
    scanf("%d", &n);
    std::vector<double> array(n);
    printf("Input size for pi:\n");
    scanf("%d", &input_pi);

    //set the number of active threads
    omp_set_num_threads(n);
    printf("Starting calculate pi in the array on threads\n");
#pragma omp parallel shared(array, sum, input_pi)
    {
        int tid = omp_get_thread_num();
        int num = omp_get_max_threads();
        int chunks = input_pi/num;
        int j = 0;
        printf("current thread id: %d\n", tid);
        printf("chunk: %d\n", chunks);
        //parallel computing using chunk of size e.g. 100-200/200-300
#pragma omp for private(j) reduction (+: sum)
        for(j = tid*chunks; j < (tid+1)*chunks; j++)
        {
            sum += pow(-1,j)/(2.0 * j + 1);
        }
    }
    sum = 4*sum;
    printf("Pi estimation: %f\n", sum);
    return 0;
}
