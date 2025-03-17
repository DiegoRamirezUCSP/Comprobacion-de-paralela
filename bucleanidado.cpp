#include <iostream>
#include <ctime>

using namespace std;

#define N 500

void fila(double A[N][N], double B[N][N], double C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void columna(double A[N][N], double B[N][N], double C[N][N]) {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    double A[N][N], B[N][N], C[N][N];
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }

    clock_t inicio, fin;
    double tiempo;

    // Medición del tiempo para orden fila-mayor (row-major)
    inicio = clock();
    fila(A, B, C);
    fin = clock();
    tiempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    cout << "Tiempo (suma por filas): " << tiempo << " segundos\n" << endl;

    clock_t inicio2, fin2;
    double tiempo2;

    // Medición del tiempo para orden columna-mayor (column-major)
    inicio2 = clock();
    columna(A, B, C);
    fin2 = clock();
    tiempo2 = ((double)(fin2 - inicio2)) / CLOCKS_PER_SEC;
    cout << "Tiempo (suma por columnas): " << tiempo2 << " segundos\n" << endl; // CORREGIDO

    return 0;
}
