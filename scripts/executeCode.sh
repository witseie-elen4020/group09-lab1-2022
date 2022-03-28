cd ..
cd executables 
make
echo " "
echo "2D-Matrix Multiplication using OpenMP"
echo " "
echo "10x10 matrices using 100 threads"
./openmp_rank2 10 100
echo "20x20 matrices using 100 threads"
./openmp_rank2 20 100
echo "30x30 matrices using 100 threads"
./openmp_rank2 30 100
echo "100x100 matrices using 100 threads"
./openmp_rank2 100 100
echo "150x150 matrices using 100 threads"
./openmp_rank2 150 100
echo "200x200 matrices using 100 threads"
./openmp_rank2 200 100
echo " "
echo "3D-Matrix Multiplication using OpenMP"
echo " "
echo "10x10 matrices using 100 threads"
./openmp_rank3 10 100
echo "20x20 matrices using 100 threads"
./openmp_rank3 20 100
echo "30x30 matrices using 100 threads"
./openmp_rank3 30 100
echo "100x100 matrices using 100 threads"
./openmp_rank3 100 100
echo "150x150 matrices using 100 threads"
./openmp_rank3 150 100
echo "200x200 matrices using 100 threads"
./openmp_rank3 200 100
echo " "
echo "2D-Matrix Multiplication using PThreads"
echo " "
echo "10x10 matrices using 100 threads"
./pthreads_rank2 10 100
echo "20x20 matrices using 100 threads"
./pthreads_rank2 20 100
echo "30x30 matrices using 100 threads"
./pthreads_rank2 30 100
echo "100x100 matrices using 100 threads"
./pthreads_rank2 100 100
echo "150x150 matrices using 100 threads"
./pthreads_rank2 150 100
echo "200x200 matrices using 100 threads"
./pthreads_rank2 200 100
echo " "
echo "3D-Matrix Multiplication using PThreads"
echo " "
echo "10x10 matrices using 100 threads"
./pthreads_rank3 10 100
echo "20x20 matrices using 100 threads"
./pthreads_rank3 20 100
echo "30x30 matrices using 100 threads"
./pthreads_rank3 30 100
echo "100x100 matrices using 100 threads"
./pthreads_rank3 100 100
echo "150x150 matrices using 100 threads"
./pthreads_rank3 150 100
echo "200x200 matrices using 100 threads"
./pthreads_rank3 200 100
echo " "
echo "2D-Matrix Multiplication Serial"
echo " "
echo "10x10 matrices"
./serial_rank2 10
echo "20x20 matrices"
./serial_rank2 20
echo "30x30 matrices"
./serial_rank2 30
echo "100x100 matrices"
./serial_rank2 100
echo "150x150 matrices"
./serial_rank2 150
echo "200x200 matrices"
./serial_rank2 200
echo " "
echo "3D-Matrix Multiplication serial"
echo " "
echo "10x10 matrices"
./serial_rank3 10
echo "20x20 matrices"
./serial_rank3 20
echo "30x30 matrices"
./serial_rank3 30
echo "100x100 matrices"
./serial_rank3 100
echo "150x150 matrices"
./serial_rank3 150
echo "200x200 matrices"
./pthreads_rank3 200
echo " "
