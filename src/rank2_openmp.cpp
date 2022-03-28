#include <iostream>
#include <cstdlib>
#include <omp.h>

using namespace std;

int** A;
int** B;
int** C;

//default if no input from terminal 
auto matrix_dim = 10;
auto num_of_threads = omp_get_max_threads();

//Initialise all Matrices
void init_2D_matrices(int** matrixA,int** matrixB,int** matrixC);
//Perform Matrix Multiplication 
void rank2TensorMultOpenMP();

int main(int argc, char*argv[]){
	
	if(argc == 3){
		matrix_dim = atoi(argv[1]);
		num_of_threads = atoi(argv[2]);
	}
	else{
	 	cout << "Too many or few arguments. Input needs 3 arguments. Default values will be used" << endl;
		matrix_dim = 10;
		num_of_threads = omp_get_max_threads();
	}
	
	auto N = matrix_dim;
	
	A = new int* [N];
	B = new int* [N];
	C = new int* [N];
	
	for(int i = 0;i < N;i++){
     		A[i] = new int[N];
     		B[i] = new int[N];
     		C[i] = new int[N];
	}
	
	init_2D_matrices(A,B,C);
	rank2TensorMultOpenMP();
}

void init_2D_matrices(int** matrixA,int** matrixB,int** matrixC){
        auto N = matrix_dim;
	for(auto i = 0; i < N; i++){
		for(auto j = 0; j < N; j++){
			matrixA[i][j] = rand()%21;
			matrixB[i][j] = rand()%21;
			matrixC[i][j] = 0;
		}
	}
}

void rank2TensorMultOpenMP(){
	auto N = matrix_dim;
	double start = 0;
	double end = 0;
	int i,j,k = 0;
	
	omp_set_num_threads(num_of_threads);
	start = omp_get_wtime();
	{
		#pragma omp parallel for private(i,j,k) shared(A,B,C) 
    		for (i = 0; i < N;i++) {
        		for (j = 0; j < N;j++) {
            			for (k = 0; k < N;k++) {
                		C[i][j] += A[i][k] * B[k][j];
        	      		}
        		}
    		}
    	}
    	end = omp_get_wtime();
    	cout << "Time taken: " << (end-start) << "s"<<endl;  
}













