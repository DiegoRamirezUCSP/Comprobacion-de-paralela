package main

import (
	"fmt"
	"math/rand"
	"time"
)

const N = 500

func fila(A, B, C *[N][N]float64) {
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			C[i][j] = A[i][j] + B[i][j]
		}
	}
}

func columna(A, B, C *[N][N]float64) {
	for j := 0; j < N; j++ {
		for i := 0; i < N; i++ {
			C[i][j] = A[i][j] + B[i][j]
		}
	}
}

func main() {
	var A, B, C [N][N]float64
	
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			A[i][j] = float64(rand.Intn(100))
			B[i][j] = float64(rand.Intn(100))
		}
	}
	start := time.Now()
	fila(&A, &B, &C)
	elapsed := time.Since(start)
	fmt.Printf("Tiempo (suma por filas): %f segundos\n\n", elapsed.Seconds())

	start = time.Now()
	columna(&A, &B, &C)
	elapsed = time.Since(start)
	fmt.Printf("Tiempo (suma por columnas): %f segundos\n\n", elapsed.Seconds())
}
