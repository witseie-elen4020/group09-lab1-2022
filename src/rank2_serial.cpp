#include <bits/stdc++.h>

using namespace std;

int** A;
int** B;
int** C;

//default input  inialized if no input from terminal 
auto matrix_dim = 10;

//Initialise all Matrices
void init_2D_matrices(int** matrixA,int** matrixB,int** matrixC);
//Perform Matrix Multiplication 
void rank2TensorMultSerial();

int main(int argc, char*argv[]){
	
	if(argc == 2){
		matrix_dim = atoi(argv[1]);
	}
	else{
	 	cout << "Too many or few arguments. Input 3 arguments. Default values will be used" << endl;
		matrix_dim = 10;
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
	rank2TensorMultSerial();
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

void rank2TensorMultSerial(){
	auto N = matrix_dim;
	clock_t start, end;
	int i,j,k = 0;
	start = clock();
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
    	end = clock();
    	cout << "Time taken: " << fixed << (double(end - start) / double(CLOCKS_PER_SEC)) << setprecision(10)<< "s"<<endl;  
}







