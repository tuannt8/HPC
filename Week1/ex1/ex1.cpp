#include <stdio.h>
#include <stdlib.h>
#include <time.h>
extern "C" {
#include <cblas.h>
}

void mat_add(int m, int n, double *A, double *B, double *C)
{
	int idx, i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			idx = i*n + j;
			C[idx] = A[idx] + B[idx];
		}
	}
}

void print_mat(double *A, int m, int n)
{
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%f ", A[i*n + j]);
		}
		printf("\n");
	}
}

void init_mat(double *A, int m, int n, int s)
{
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			A[i*n+j] = s;
		}
	}
}

inline int index(int i, int j, int m, int n)
{
	return i*n + j;
}

int main(int argc, char* argv[])
{
	
	int m = 5;
	int n = 2;
	int k = 20;
	
	if(argc >= 2)
	{
		m = atoi(argv[1]);
		n = atoi(argv[2]);
	}	
	
	double *A = (double*)malloc(m*k*sizeof(double));
	double *B = (double*)malloc(k*n*sizeof(double));
	double *C = (double*)malloc(m*n*sizeof(double));
	
	init_mat(A,m,k,1);
	init_mat(B,k,n,2);
	
  double alpha = 1.0;
  double beta  = 0.0;
  int LDA = k; // Width of A aka A.cols()
  int LDB = n; // Width of B aka B.cols()
  int LDC = n; // Width of C aka C.cols()
  /* Interface for Cblas dgemm */
  /* void cblas_dgemm(const enum CBLAS_ORDER Order, */
  /* 		   const enum CBLAS_TRANSPOSE TA, */
  /* 		   const enum CBLAS_TRANSPOSE TB, */
  /* 		   const int M, */
  /* 		   const int N, */
  /* 		   const int K, */
  /* 		   const double alpha, */
  /* 		   const double * A, */
  /* 		   const int lda, */
  /* 		   const double * B, */
  /* 		   const int ldb, */
  /* 		   const double beta, */
  /* 		   double * C, */
  /* 		   const int ldc  */
  /* 		   ) */
  /* http://fossies.org/dox/atlas3.10.2/cblas__dgemm_8c.html */

  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
  				m, n, k, alpha, A, LDA, B, LDB, beta, C, LDC);

print_mat(C, m, n);
	free(A);
	free(B);
	free(C);
	
	return 0;
}
