/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"

/* A x Atr */
double *multiply1(int N, double *A, double *B) {
    double *res = (double *) calloc(N * N, sizeof(double));
    if(!res)
        return NULL;
    for (int i = 0; i < N; ++i) {
         for (int j = 0; j < N; ++j) {
             for (int k = i; k < N; ++k) {
                 res[i * N + j] += A[i * N + k] * B[j * N + k];
             }
         }
     }
     return res;
}

/* B x A x Atr */
double *multiply2(int N, double *A, double *B) {

    double *res = (double *) calloc(N * N, sizeof(double));
    if(!res)
        return NULL;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                res[i * N + j] += A[i * N + k] * B[k * N + j];
            }
        }
    }
    return res;
}

/* B x Btr */
double *multiply3(int N, double *A, double *B) {

    double *res = (double *) calloc(N * N, sizeof(double));
    if(!res)
        return NULL;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                res[i * N + j] += A[k * N + i] * B[k * N + j];
            }
        }
    }
    return res;
}

/* sum of two matrix */
double *sum(int N, double *A, double *B) {
    double *res = (double *) calloc(N * N, sizeof(double));
    if(!res)
        return NULL;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            res[i * N + j] += A[i * N + j] + B[i * N + j];
        }
    }
    
    return res;
}

double* my_solver(int N, double *A, double* B) {

    double *AAtr = multiply1(N, A, A);
    double *BAAtr = multiply2(N, B, AAtr);
    double *BBtr = multiply3(N, B, B);
    double *res = sum(N, BAAtr, BBtr);

    free(AAtr);
    free(BAAtr);
    free(BBtr);
    return res;
}