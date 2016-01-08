#include <stdio.h>
#include <omp.h>
	

int main()
{
	int loop = 10000;
	
	double p = 0;
	
#pragma omp parallel for default(none) shared(loop) reduction(+: p)	
	for(int i = 0; i < loop; i++)
		for (int j = 0; j < loop; j++)
	{
		p += 10;
	}
	
	printf("Hello OpenMP");
	
	return 0;
}