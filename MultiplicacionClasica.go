package main

import (
	"fmt"
	"time"
)

func multiplicarMatrices(A, B, C [][]int, n int) {
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			C[i][j] = 0
			for k := 0; k < n; k++ {
				C[i][j] += A[i][k] * B[k][j]
			}
		}
	}
}

func generarMatriz(n int) [][]int {
	M := make([][]int, n)
	for i := range M {
		M[i] = make([]int, n)
		for j := range M[i] {
			M[i][j] = 1
		}
	}
	return M
}

func main() {
	tamanos := []int{128, 256, 512, 1024}

	for _, n := range tamanos {
		A := generarMatriz(n)
		B := generarMatriz(n)
		C := generarMatriz(n)

		inicio := time.Now()
		multiplicarMatrices(A, B, C, n)
		duracion := time.Since(inicio)

		fmt.Printf("Tiempo para n = %d: %v segundos\n", n, duracion.Seconds())
	}
}
