
# Breach Protocol Solver

BreachProtocolSolver is a program designed to solve problems inspired by the breach protocol mini-game mechanics in Cyberpunk 2077. This program is written in C++ language, adhering to the minimum requirement of CMake version 3.10.




## Requirement

- Minimum required version of CMake: 3.10
- C++ Standard: 11




## How to compile

This program is already compiled in MacOS arm-64 environment. If you are using the same environment, you can skip this step. If you are using another environmen, run the following command

```bash
  cd bin

  rm CMakeCache.txt

  cmake ../src
  
  make
```


## How to run

After compiling the program, follow these steps to run it:

```bash
cd bin

./BreachProtocolSolver
```
The program will prompt the user for input by displaying the following options:

- Select 1 to take input from a file.
- Select 2 to use random input from the Command Line Interface (CLI).
- Select 0 to exit the program.

After running the program with the appropriate input, the execution result will be saved in the `/test/output` folder



## Directory Structure
-  `/src`: Main directory of the program.
    - `/IO`: Contains files related to input-output.
    - `/Data-Structure`: Contains definitions of data structures used.
    - `/Solver`: Contains files related to problem-solving.
    - `/Utils`: Contains various utility functions.

- `/doc`: Contains documentation files.
- `/bin`: Contains binary/executable files.
- `/test`: Contain test case files.
    - `/output`: Contains output of the program.
## Contact
This program is made by Maulvi (13522122). For inquiries or feedback, please kindly contact me at [Linked.in](https://www.linkedin.com/in/maulvi-ziadinda-maulana-02b1a5225/). Be sure to look at my [Portofolio](maulvi-zm.github.io).

Thank you for using BreachProtocolSolver! 🎮

