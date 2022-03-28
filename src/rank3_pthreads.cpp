#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <ctime>

using namespace std;

int*** A;
int*** B;
int*** C;

//default if no input from terminal 
auto matrix_dim = 10;
auto num_of_threads = 4;

//Initialise all Matrices
void init_3D_matrices(int*** matrixA,int*** matrixB,int*** matrixC);
//Perform Matrix Multiplication
void rank2TensorMultPThread(int** A, int** B,int** C);
void rank3TensorMultPThread();
void* matrix_multiplication(void* arg);

int main(int argc, char*argv[]){
	
	if(argc == 3){
		matrix_dim = atoi(argv[1]);
		num_of_threads = atoi(argv[2]);
	}
	else{
	 cout << "Too many or few arguments. Input needs 3 arguments. Default values will be used" << endl;
		matrix_dim = 10;
		num_of_threads = 4;
	}
	
	auto N = matrix_dim;
	A = new int** [N];
	B = new int** [N];
	C = new int** [N];
	
	for(auto i = 0;i < N;i++){
     		A[i] = new int* [N];
		B[i] = new int* [N];
		C[i] = new int* [N];
	}
	
	for(auto i = 0;i < N;i++){
		for(auto j = 0; j < N; j++){
	     		A[i][j] = new int [N];
	     		B[i][j] = new int [N];
	     		C[i][j] = new int [N];
	     		}
	} 
	
	init_3D_matrices(A,B,C);
	rank3TensorMultPThread();
}

void rank3TensorMultPThread(){
	
	pthread_t myThreads[num_of_threads];
	int thread_numbers[num_of_threads];
	clock_t start_t, end_t; 
	double total = 0;
	
	start_t = clock(); 
	for(auto i = 0;i < num_of_threads;i++){
		thread_numbers[i] = i;
		pthread_create(&myThreads[i],NULL,matrix_multiplication,&thread_numbers[i]);
	}		
	
	for(auto i = 0; i < num_of_threads;i++){
		pthread_join(myThreads[i],NULL);
	}    
	end_t = clock();
	total = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	cout << "Time taken: " << total << "s"<< endl;
}

void* matrix_multiplication(void* arg){
	auto N = matrix_dim;
	auto thread = *((int*)arg);
	auto begin = (thread*matrix_dim)/num_of_threads;
	auto finish = ((thread+1)*matrix_dim)/num_of_threads;

    	for (auto i = begin; i < finish;i++){
		rank2TensorMultPThread(A[i],B[i],C[i]);
	}
 
    	return 0;
}

void rank2TensorMultPThread(int** matrixA, int** matrixB,int** matrixC){

	auto N = matrix_dim;
	{
    		for (auto i = 0; i < N;i++) {
        		for (auto j = 0; j < N;j++) {
            			for (auto k = 0; k < N;k++) {
                		     matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
        	      		}
        		}
    		}
    	}

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



