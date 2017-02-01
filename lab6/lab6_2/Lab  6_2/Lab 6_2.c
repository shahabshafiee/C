#include<stdlib.h>
#include<stdio.h>

//------------------- prototypes -----------------------------
double * allocate_mem_on_heap_for_vector_1D(int N);
void free_mem_on_heap_for_vector_1D(double *);
void free_mem_on_heap_for_matrix_2D(double **, int N);
void copy_vector_1D_from_stack_to_heap(
	double p2vector_1D_on_stack[],
	double p2vector_1D_on_heap[],
	int N);
//void copy_vector_1D_from_heap_to_stack(
	//double vector_1D_on_heap[],
	//double vector_1D_on_stack[],
	//int N);
double * vector_1D_add(double *p2A, double *p2B, int N);
double dot_product(double *p2A, double *p2B, int N);
double ** column_vector_1D_times_row_vector_1D(double *p2A, double *p2B, int N);
void print_vector_1D(double *p2_vec, int N);
void print_matrix_2D(double **p2p2_matrix, int N);
//------------------------------------------------------------
//------------------- main program, variables ---------------------
int main(){
	double A_on_stack[] = {1, 2, 3, 4};
	double B_on_stack[] = {11, 22, 33, 44};
	double *p2A_on_heap = NULL;
	double *p2B_on_heap = NULL;
	double *p2C_on_heap = NULL;
	double *p2D_on_heap = NULL;
	double dot_prod_val;
	int elements;
	double **p2_matrix2D_on_heap = NULL;
	//--------------------------------------------------------------
	// code starts:
	// calculate the number of elements
	elements = sizeof(A_on_stack)/sizeof(double);
	printf("number of elements in vectors : %d\n\n", elements);
	// allocate space for vectors A and B on heap
	p2A_on_heap = allocate_mem_on_heap_for_vector_1D(elements);
	p2B_on_heap = allocate_mem_on_heap_for_vector_1D(elements);
	// copy vectors A and B from stack to heap
	copy_vector_1D_from_stack_to_heap(A_on_stack, p2A_on_heap, elements);
	copy_vector_1D_from_stack_to_heap(B_on_stack, p2B_on_heap, elements);
	// computes C = A + B. Note : A, B and C are on heap
	p2C_on_heap = vector_1D_add(p2A_on_heap, p2B_on_heap, elements);
	printf("vector addition:\n");
	print_vector_1D(p2C_on_heap, elements);
	printf("\n");
	// computes dot_prod(A, B), A and B on heap, result is a SCALAR value on stack
	dot_prod_val= dot_product(p2A_on_heap, p2B_on_heap, elements);
	printf("dot_prod_val = %lf\n\n", dot_prod_val);
	// calculate 1D column vector times 1D row vector --> matrix
	p2_matrix2D_on_heap = column_vector_1D_times_row_vector_1D(p2A_on_heap, p2B_on_heap,
		elements);
	printf("1D column vector times 1D row vector :\n");
	print_matrix_2D(p2_matrix2D_on_heap, elements);
	// free memory
	free_mem_on_heap_for_vector_1D(p2A_on_heap);
	free_mem_on_heap_for_vector_1D(p2B_on_heap);
	free_mem_on_heap_for_matrix_2D(p2_matrix2D_on_heap, elements);
	system("pause");
	return 0;
} // end of main

double * allocate_mem_on_heap_for_vector_1D(int N)
{
	double *p=(double *)malloc(N*sizeof(double));
	return p;
}

void copy_vector_1D_from_stack_to_heap(
	double p2vector_1D_on_stack[],
	double p2vector_1D_on_heap[],
	int N)
{
	int i;
	for (i=0;i<N;i++)
		p2vector_1D_on_heap[i]=p2vector_1D_on_stack[i];
}

double * vector_1D_add(double *p2A, double *p2B, int N)
{
	int i;
 double *vector_1D_add=(double *)malloc(N*sizeof(double));
 for (i=0;i<N;i++)
 *(vector_1D_add+i)=*(p2A+i)+*(p2B+i);
 return vector_1D_add;
}

void print_vector_1D(double *p2_vec, int N)
{
	int i;
	for (i=0;i<N;i++)
		printf("%lf ",*(p2_vec+i));
}

double dot_product(double *p2A, double *p2B, int N)
{
	double dot_product=0;
	int i;
	for (i=0;i<N;i++)
		dot_product=dot_product+((*(p2A+i))*(*(p2B+i)));
	return dot_product;
}

double ** column_vector_1D_times_row_vector_1D(double *p2A, double *p2B, int N)
{
	int i,j;
	double **matrix_2D= NULL; 
	matrix_2D= (double**) malloc( sizeof( double* ) *N); 
	for (i=0; i<N; i++)
		matrix_2D[i] =(double *)malloc( sizeof(double)*N);
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
			matrix_2D[i][j]=p2A[i]*p2B[j];
	}
		return matrix_2D; 
}

void print_matrix_2D(double **p2p2_matrix, int N)
{
	int i,j;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
			printf("%lf ",p2p2_matrix[i][j]);
		printf("\n");
	}
}

void free_mem_on_heap_for_vector_1D(double *p)
{
	free(p);
}

void free_mem_on_heap_for_matrix_2D(double **p2_matrix2D, int N)
{
	int i;
	for (i=0;i<N;i++)
		free(*(p2_matrix2D+i)); 
	free(p2_matrix2D);
}




















	



































	

























		









