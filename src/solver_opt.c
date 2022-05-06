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
        double *lineA = A + i * N;
        for (int j = 0; j < N; ++j) {
            register double *lineA_copy = lineA + i;
            register double *colB = B + j * N + i;
            register double sum = 0;

            for (int k = i; k < N; ++k) {
                sum += *lineA_copy * *colB;
                lineA_copy++;
                colB++;
             }
             res[i * N + j] = sum; 
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
        double *lineA = A + i * N;
        for (int j = 0; j < N; ++j) {
            register double *lineA_copy = lineA;
            register double *lineB = B + j * N;
            register double sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += *lineA_copy * *lineB;
                lineB++;
                lineA_copy++;
            }
            res[i * N + j] = sum;
        }
    }
    return res;
}

/* B x Btr */
double *multiply3(int N, double *A, double *B) {

    double *res = (double *) calloc(N * N, sizeof(double));
    if(!res)
        return NULL;

    register double sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += A[k * N + i] * B[k * N + j];
            }
            res[i * N + j] = sum;
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