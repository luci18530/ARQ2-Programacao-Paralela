#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <chrono>
#include <iostream>

// GRUPO : LUCIANO PEREIRA, GIOVANNA ALBURQUERQUE, RYAN MATHEUS

// set 5 threads for openmp

// HOW TO COMPILE: g++ -fopenmp projeto-paralelo.cpp -o projeto-paralelo


static long NUM = 10000;
double step;

using namespace std;

int main()
{
    int effarray[NUM][4];
    int i, j, temp;
    auto start = std::chrono::high_resolution_clock::now();

//omp_set_dynamic(0);   // Explicitly disable dynamic teams
omp_set_num_threads(1); 
#pragma omp parallel default(none) shared(NUM, effarray, temp) private(i, j) 
    {
#pragma omp for nowait

        for (i=0; i < NUM; i++) {
        temp = i * 1;
        effarray[i][0] = temp;
        effarray[i][1] = temp * 2;
        effarray[i][2] = temp * 3;
        effarray[i][3] = temp * 4;
    }

#pragma omp for nowait

        for (i=0; i < NUM; i++) {
        for (j=0; j < NUM; j++) {
            effarray[i][0] = effarray[i][1] + effarray[j][2];
        }
    }

#pragma omp for nowait

        for (i=0; i < NUM; i++) {
        effarray[i][3] = effarray[i][0] * effarray[i][0];
    }
    }

    auto finish = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count();

    float time = duration / 1000000.0;
    // print time
    cout << "Time: " << time << " seconds" << endl;
}