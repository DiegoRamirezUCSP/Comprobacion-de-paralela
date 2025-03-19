#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void multiplicar_matrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

vector<vector<int>> generar_matriz(int n) {
    vector<vector<int>> M(n, vector<int>(n, 1)); 
    return M;
}

int main() {
    vector<int> tamanos = {128, 256, 512, 1024};
    cout << "tiempo segundos" << endl;
    for (int n : tamanos) {
        vector<vector<int>> A = generar_matriz(n);
        vector<vector<int>> B = generar_matriz(n);
        vector<vector<int>> C(n, vector<int>(n, 0));

        auto inicio = high_resolution_clock::now();
        multiplicar_matrices(A, B, C, n);
        auto fin = high_resolution_clock::now();

        duration<double> tiempo = fin - inicio;
        
        cout << n << " " << tiempo.count() << endl;
    }

    return 0;
}
