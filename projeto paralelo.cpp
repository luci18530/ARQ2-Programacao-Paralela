#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <chrono>
#include <iostream>

// GRUPO : LUCIANO PEREIRA, GIOVANNA ALBURQUERQUE, RYAN MATHEUS

static long NUM = 10000;
double step;

using namespace std;

int main()
{
    double a[NUM], b[NUM], c[NUM], d[NUM];
    int i, j;
    auto start = std::chrono::high_resolution_clock::now();

#pragma omp parallel default(none) shared(NUM, a, b, c, d) private(i, j)
    {
#pragma omp for nowait
        for (i = 0; i < NUM; i++)
        {
            a[i] = i * 1.0;
            b[i] = i * 2.0;
            c[i] = i * 3.0;
            d[i] = i * 4.0;
        }

#pragma omp for nowait

        for (i = 0; i < NUM - 2; i++)
        {
            for (j = 0; j < NUM - 2; j++)
            {
                a[i] = b[i] + c[i] * d[i];
            }
        }

#pragma omp for nowait

        for (i = 0; i < NUM; i++)
        {
            d[i] = a[i] * a[i];
        }
    }

    auto finish = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count();

    float time = duration / 1000000.0;
    // print time
    cout << "Time: " << time << " seconds" << endl;
}