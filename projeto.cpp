#include <chrono>
#include <iostream>

// GRUPO : LUCIANO PEREIRA, GIOVANNA ALBURQUERQUE, RYAN MATHEUS

static long NUM = 10000;
double step;

using namespace std;

int main () {
    double a[NUM], b[NUM], c[NUM], d[NUM]; // arrays
    int i,j; // loop counters
    auto start = std::chrono::high_resolution_clock::now();

    
    for (i=0; i < NUM; i++) {
        a[i] = i * 1.0;
        b[i] = i * 2.0;
        c[i] = i * 3.0;
        d[i] = i * 4.0;
    }

    for (i=0; i < NUM-2; i++) {
        for (j=0; j < NUM-2; j++) {
            a[i] = b[i] + c[i] * d[j];
        }
    }

    for (i=0; i < NUM; i++) {
        d[i] = a[i] * a[i];
    }

    auto finish = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count();

    float time = duration / 1000000.0;
    // print time 
    cout << "Time: " << time << " segundos" << endl;
}