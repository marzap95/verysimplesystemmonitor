#include <iostream>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "cpu.cpp"
#include "ram.cpp"

/*
CPU 0 [####################                    ] 50%
40 points of precision
*/
#define BAR_PRECISION 40

void draw_cpus(vector<Cpu*> cpu_arr, int n_cpus) {
    for (int i=0; i<n_cpus; i++) {
        int percent = cpu_arr[i]->get_used();
        int outta_limit = int((percent * BAR_PRECISION)/100);
        cout << "CPU " << i << " [";
        for (int j=0; j<outta_limit; j++) {
            cout << "#";
        }
        for (int j=0; j<BAR_PRECISION-outta_limit; j++) {
            cout << " ";
        }
        cout << "] " << percent << "%" << endl;
    }
}

void draw_ram(Ram ram) {
    int percent = ram.get_used_percent();
    int outta_limit = int((percent * BAR_PRECISION)/100);
    cout << "RAM   [";
    for (int j=0; j<outta_limit; j++) {
        cout << "#";
    }
    for (int j=0; j<BAR_PRECISION-outta_limit; j++) {
        cout << " ";
    }
    cout << "] " << percent << "%" << endl;
    cout << ram.get_used() << "/" << ram.get_total() << " kB" << endl;
}

#define N_CPUS 8
int main() {
    vector<Cpu*> cpus;
    for (int i=0; i<N_CPUS; i++) {
        cpus.push_back(new Cpu(i));
    }
    Ram ram;

    for (;;) {
        draw_cpus(cpus, N_CPUS);
        cout << endl;
        draw_ram(ram);
        cout << "\033[2J\033[1;1H"; // clears the console
        usleep(2000000);
    }

    return 0;
}
