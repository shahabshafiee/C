//lab6_1 allocating memory on the heap for a three-dimensional array
//6_1.c
//shahab shafieihajiabady , bahram samavatian


#include <stdio.h>
#include <stdlib.h>

void main()
{
	int planes=4 , rows=2 , columns=3,i,j,k;
	double ***matr=NULL;


	matr = (double***) malloc( sizeof( double* ) * planes );//for array of pointers
	for (i=0; i<planes; i++)
	{
		matr[i] = (double**) malloc( sizeof( double* ) *rows);
		for (j=0;j<rows;j++)
			matr[i][j]= (double*)malloc( sizeof(double)*columns );
	}


	for (k=0 ;k<planes;k++)
	{
		for (i=0;i<rows;i++)
		{
			for(j=0;j<columns;j++)
				matr[k][i][j]=k*1000+i*10+j*100;
		}
	}
	for (k=0 ;k<planes;k++)
	{
		for (i=0;i<rows;i++)
		{
			for(j=0;j<columns;j++)
				printf("%f ",matr[k][i][j]);
			printf("\n");
		}
		printf("\n");
	}



	for (i=0; i<planes;i++)
	{
		for (j=0;j<rows;j++)
			free(matr[i][j]);
	}
	for(i=0;i<planes;i++)
		free(matr[i]);
	free (matr);

	system("pause");
}
