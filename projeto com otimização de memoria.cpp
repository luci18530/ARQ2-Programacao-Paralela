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

int main () {
    double a[NUM], b[NUM], c[NUM], d[NUM];
    int i,j;
    auto start = std::chrono::high_resolution_clock::now();

    for (i=0; i < NUM; i++) {
    auto values = std::make_tuple(i * 1.0, i * 2.0, i * 3.0, i * 4.0);
    a[i] = std::get<0>(values);
    b[i] = std::get<1>(values);
    c[i] = std::get<2>(values);
    d[i] = std::get<3>(values);
    }

    for (i=0; i < NUM-2; i++) {
        for (j=0; j < NUM-2; j++) {
            a[i] = b[i] + c[i] * d[i];
        }
    }

    for (i=0; i < NUM; i++) {
        d[i] = a[i] * a[i];
    }

    auto finish = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count();

    float time = duration / 1000000.0;
    // print time 
    cout << "Time: " << time << " seconds" << endl;
}