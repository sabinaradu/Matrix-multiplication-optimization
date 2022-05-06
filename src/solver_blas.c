/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <cblas.h>

double *copy(int N, double *A) {

    double *B = malloc(N * N * sizeof(double));
    if(!B) 
        return NULL;
    
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            B[i * N + j] = A[i * N + j];
        }
    }
    return B;
}

double* my_solver(int N, double *A, double *B) {
    /* alocare memorie pentru matrici */
    double *C = copy(N, B);

    cblas_dtrmm(
            CblasRowMajor,
            CblasRight,
            CblasUpper,
            CblasNoTrans,
            CblasNonUnit,
            N,
            N,
            1.0,
            A,
            N,
            C,
            N
    );

    cblas_dtrmm(
            CblasRowMajor,
            CblasRight,
            CblasUpper,
            CblasTrans,
            CblasNonUnit,
            N,
            N,
            1.0,
            A,
            N,
            C,
            N
    );

    cblas_dgemm(
            CblasRowMajor,
            CblasTrans,
            CblasNoTrans,
            N,
            N,
            N,
            1.0,
            B,
            N,
            B,
            N,
            1.0,
            C,
            N
    );

    
    return C;
}
