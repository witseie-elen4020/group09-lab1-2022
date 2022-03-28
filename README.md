# ELEN4020-group09-lab1-2022

### This a 2D and 3D matrix multiplication programs using parallel programming

The programs perform a parallel execution of matrix multiplication in 2D and 3D
Each file in the **src** implements one of the following functions:

-rank2TensorMultPThread(): 2D PThreads
-rank3TensorMultPthread(): 3D PThreads
-rank2TensorMultOpenMP(): 2D OpenMP
-rank2TensorMultOpenMP(): 3D OpenMP 
-rank2TensorMultSerial(): 2D Serial
-rank2TensorMultSerial(): 3D Serial 

Only the multiplication part of the code in all source files is timed and displayed
onto the terminal

## Compile Instructions
the source code is compiled in either one of the followays two ways, and the following
should be considered when tying to run and compile programms:

-C++ has been used in developing the code
-Ubuntu linux version is 18.04 LTS (WSL in Windows 10)
-The compiler is g++ version 7.4.0
-The GNU make version is 4.1
-The VIM - Vi 8.0

### Method 1
*1* Clone the repository into local directory.
*2* Access/open the <scripts> folder found within the local-directroy\Ugroup09-lab1-2022\scripts in  ubuntu terminal
*3* Run the <executeCode.sh> file by typing the following command in ubuntu terminal: <./executeCode.sh> , hit enter{not*, to exclude the '<' & '>' in all commands}
    - If the terminal does not allow permission to run the <executeCode.sh> file then type: <chmod +x executeCode.sh> hit enter
      then </execute.sh> 	
*3* This should automatically run the Makefile located in the <executables> folder.
*4* The Makefile will compiles all source code located in the <src> folder and produce the respective object files into the <executables> folder
*5* After all compilation by the Makefile, the <executeCode.sh> file will then run the object files and print the execution times on the ubuntu terminal

### Method2
*1* Clone the repository into local directory.
*2* Access/open the <scripts> folder found within the local-directroy\Ugroup09-lab1-2022\scripts in  git bash terminal
*3* Run the <executeCode.sh> file by typing the following command in git bash terminal: <./executeCode.sh> , hit enter{not*, to exclude the '<' & '>' in all commands}
    - If the terminal does not allow permission to run the <executeCode.sh> file then type: <chmod +x executeCode.sh> hit enter
      then </execute.sh>
    - Make sure your git bash has the command <make> installed and working or else you will an error using this method
*3* This should automatically run the Makefile located in the <executables> folder.
*4* The Makefile will compiles all source code located in the <src> folder and produce the respective object files into the <executables> folder
*5* After all compilation by the Makefile, the <executeCode.sh> file will then run the object files and print the execution times on the ubuntu terminal


####please be patient, it could take up to 3minutes for code to compile and run object files to print execution times of various matrix sizes.
