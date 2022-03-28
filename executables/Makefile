# -*- MakeFile -*-

all: openmp_rank2 openmp_rank3 pthreads_rank2 pthreads_rank3 serial_rank2 serial_rank3

openmp_rank2: ../src/rank2_openmp.cpp
	g++ ../src/rank2_openmp.cpp -fopenmp -o openmp_rank2
	
openmp_rank3: ../src/rank3_openmp.cpp
	g++ ../src/rank3_openmp.cpp -fopenmp -o openmp_rank3
	
pthreads_rank2: ../src/rank2_pthreads.cpp
	g++ ../src/rank2_pthreads.cpp -lpthread -o pthreads_rank2
	
pthreads_rank3: ../src/rank3_pthreads.cpp
	g++ ../src/rank3_pthreads.cpp -lpthread -o pthreads_rank3
	
serial_rank2: ../src/rank2_serial.cpp
	g++ ../src/rank2_serial.cpp -o serial_rank2
	
serial_rank3: ../src/rank3_serial.cpp
	g++ ../src/rank3_serial.cpp -o serial_rank3
	
clean:
	rm openmp_rank2 openmp_rank3 pthreads_rank2 pthreads_rank3 serial_rank2 serial_rank3
