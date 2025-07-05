#include <iostream>
#include <fstream>
#include "ops128.h"
#include <time.h>

int v, n;

struct dato {
    bool sim;
    int var;
};

int asignacion[100];
bool asignado[100];
dato funcion[100][3];
__int128_t cont = 0;

int parcial_valida() {
    for (int i = 0; i < n; ++i) {
        bool todos_asignados = true;
        bool cumple = false;
        for (int j = 0; j < 3; ++j) {
            int var = funcion[i][j].var;
            bool signo = funcion[i][j].sim;
            if (!asignado[var]) {
                todos_asignados = false;
                continue;
            }
            bool valor = asignacion[var];
            if (!signo) {
                valor = !valor;
            }

            if (valor) {
                cumple = true;
                break;
            }
        }
        if (todos_asignados && !cumple) {
            return false;
        }
    }
    return true;
}

void f(int i) {
    if(i == v) {
        cont += 1;
    } else {
        asignacion[i] = true;
        asignado[i] = true;
        if(parcial_valida()) {
            f(i + 1);
        }
        asignacion[i] = false;
        if(parcial_valida()) {
            f(i + 1);
        }
        asignacion[i] = false;
        asignado[i] = false;
    }
}

int main() {
    for(int u = 0; u < 25; ++u) {
        std::ofstream media("media.txt", std::ios::app), tiempo("tiempo.txt", std::ios::app);
        cont = 0;
        for(int i = 0; i < 100; ++i) {
            asignacion[i] = 0;
            asignado[i] = 0;
        }
        n = u + 1; v;
        std::cin >> v;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 3; ++j) {
                char sim; int var;
                std::cin >> sim >> var;
                funcion[i][j] = dato{sim == '+', var};
            }
        }
        clock_t t0 = clock();
        f(0);
        clock_t t1 = clock();
        media << i128to_string(cont) << "\n";
        tiempo << double(t1 - t0) / CLOCKS_PER_SEC << "\n";
        std::cout << u << " :)\n";
    }
}