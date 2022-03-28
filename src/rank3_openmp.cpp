#include <iostream>
#include <omp.h>

using namespace std;

int*** A;
int*** B;
int*** C;

//default if no input from terminal 
auto matrix_dim = 10;
auto num_of_threads = omp_get_max_threads();

//Initialise all Matrices
void init_3D_matrices(int*** matrixA,int*** matrixB,int*** matrixC);
//Perform Matrix Multiplication
void rank2TensorMultOpenMP(int** A, int** B,int** C);
void rank3TensorMultOpenMP();

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
	A = new int** [N];
	B = new int** [N];
	C = new int** [N];
	
	for(int i = 0;i < N;i++){
     		A[i] = new int* [N];
		B[i] = new int* [N];
		C[i] = new int* [N];
	}
	
	for(int i = 0;i < N;i++){
		for(int j = 0; j < N; j++){
	     		A[i][j] = new int [N];
	     		B[i][j] = new int [N];
	     		C[i][j] = new int [N];
	     		}
	} 
	
	init_3D_matrices(A,B,C);
	rank3TensorMultOpenMP();
}

void init_3D_matrices(int*** matrixA,int*** matrixB,int*** matrixC){
        auto N = matrix_dim;
	for(auto i = 0; i < N; i++){
		for(auto j = 0; j < N; j++){
			for(auto k = 0;k < N;k++){
				matrixA[i][j][k] = rand()%21;
				matrixB[i][j][k] = rand()%21;
				matrixC[i][j][k] = 0;
			}
		}
	}	
}

void rank2TensorMultOpenMP(int** matrixA, int** matrixB,int** matrixC){
	auto N = matrix_dim;
	int i,j,k = 0;
	{
		#pragma omp parallel for private(i,j,k) shared(A,B,C) schedule(dynamic,5)
    		for (i = 0; i < N;i++) {
        		for (j = 0; j < N;j++) {
            			for (k = 0; k < N;k++) {
                		matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
        	      		}
        		}
    		}
    	}

}
void rank3TensorMultOpenMP(){
	auto N = matrix_dim;
	double start = 0.f;
	double end = 0.f;
	
	omp_set_num_threads(num_of_threads);
	start = omp_get_wtime();
	for(auto i = 0; i < N;i++){
		rank2TensorMultOpenMP(A[i],B[i],C[i]);
	}
	end = omp_get_wtime();
	
	cout << "Time Taken: " << (end-start) << "s"<< endl;
    
}
