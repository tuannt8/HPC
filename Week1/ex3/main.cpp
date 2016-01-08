#include <stdio.h>
#include <time.h>
#include <string.h>


int main(int argc, char* argv[])
{
	int row = 1;
	if(argc>1)
	{
		if(strcmp(argv[1], "row") == 0)
			row = 1;
		else if (strcmp(argv[1], "col")==0)
			row = 0;
		else
		{
			printf("Invalid arg\n");
			return 1;
		}
	}

	int m = 1000, n = 1000, k = 100;
	double A[m][k];
	double B[k][n];
	double C[m][n];
	
	int i,j,o;
	
	double t = clock();
	
	if(row == 1)
	{
	for (i=0; i<m; i++)
	for (j=0; j<n; j++)
			for(o=0; o<k; o++)
			{
				C[i][j] += A[i][o]*B[o][j];
			}
	}
	else
	{
		for (j=0; j<n; j++)
		for (i=0; i<m; i++)
			for(o=0; o<k; o++)
			{
				C[i][j] += A[i][o]*B[o][j];
			}
	}
	
	t = (clock() - t)/(double)CLOCKS_PER_SEC;
	printf("%f\n", t);
	return 0;
}
