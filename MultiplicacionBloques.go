package main

import (
	"fmt"
	"time"
)

func multiplicarMatricesBloques(A, B, C [][]int, n, bloque int) {
	for bi := 0; bi < n; bi += bloque {
		for bj := 0; bj < n; bj += bloque {
			for bk := 0; bk < n; bk += bloque {
				// Multiplicación de submatrices
				for i := bi; i < min(bi+bloque, n); i++ {
					for j := bj; j < min(bj+bloque, n); j++ {
						for k := bk; k < min(bk+bloque, n); k++ {
							C[i][j] += A[i][k] * B[k][j]
						}
					}
				}
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

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	tamanos := []int{128, 256, 512, 1024}
	bloque := 32 // Tamaño del bloque

	for _, n := range tamanos {
		A := generarMatriz(n)
		B := generarMatriz(n)
		C := generarMatriz(n)

		inicio := time.Now()
		multiplicarMatricesBloques(A, B, C, n, bloque)
		duracion := time.Since(inicio)

		fmt.Printf("Tiempo para n = %d con bloque %d: %v segundos\n", n, bloque, duracion.Seconds())
	}
}
