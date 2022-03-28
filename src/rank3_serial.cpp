#include <bits/stdc++.h>

using namespace std;

int*** A;
int*** B;
int*** C;

//default if no input from terminal 
auto matrix_dim = 10;

//Initialise all Matrices
void init_3D_matrices(int*** matrixA,int*** matrixB,int*** matrixC);
//Perform Matrix Multiplication
void rank2TensorMultSerial(int** A, int** B,int** C);
void rank3TensorMultSerial();

int main(int argc, char*argv[]){
	
	if(argc == 2){
		matrix_dim = atoi(argv[1]);
	}
	else{
	 	cout << "Too many or few arguments. Input needs 2 arguments. Default values will be used" << endl;
		matrix_dim = 10;
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
	rank3TensorMultSerial();
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

void rank2TensorMultSerial(int** matrixA, int** matrixB,int** matrixC){
	auto N = matrix_dim;
	int i,j,k = 0;
	{
    		for (i = 0; i < N;i++) {
        		for (j = 0; j < N;j++) {
            			for (k = 0; k < N;k++) {
                		matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
        	      		}
        		}
    		}
    	}

}
void rank3TensorMultSerial(){
	auto N = matrix_dim;
	clock_t start, end;
	
	start =  clock();
	for(auto i = 0; i < N;i++){
		rank2TensorMultSerial(A[i],B[i],C[i]);
	}
	end =  clock();
	
	cout << "Time taken: " << fixed << (double(end - start) / double(CLOCKS_PER_SEC)) << setprecision(10)<< "s"<<endl;
    
}

