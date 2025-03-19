#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void multiplicar_matrices_bloques(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n, int bloque) {
    for (int bi = 0; bi < n; bi += bloque) {
        for (int bj = 0; bj < n; bj += bloque) {
            for (int bk = 0; bk < n; bk += bloque) {
                // Multiplicación de submatrices
                for (int i = bi; i < min(bi + bloque, n); ++i) {
                    for (int j = bj; j < min(bj + bloque, n); ++j) {
                        for (int k = bk; k < min(bk + bloque, n); ++k) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

vector<vector<int>> generar_matriz(int n) {
    vector<vector<int>> M(n, vector<int>(n, 1)); // Matriz llena de 1s
    return M;
}

int main() {
    vector<int> tamanos = {128, 256, 512, 1024}; // Tamaños de prueba
    int bloque = 32; // Tamaño del bloque (ajustable según arquitectura)
    cout << "matriz segundos" << endl;
    for (int n : tamanos) {
        vector<vector<int>> A = generar_matriz(n);
        vector<vector<int>> B = generar_matriz(n);
        vector<vector<int>> C(n, vector<int>(n, 0));

        auto inicio = high_resolution_clock::now();
        multiplicar_matrices_bloques(A, B, C, n, bloque);
        auto fin = high_resolution_clock::now();

        duration<double> tiempo = fin - inicio;
        cout <<  n << " " << tiempo.count() << endl;
    }

    return 0;
}
