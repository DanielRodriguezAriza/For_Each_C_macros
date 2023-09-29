# For_Each_C_macros

## Introduction
A simple program to generate headers that contain definitions for macros to get elements from ```__VA_ARGS__```.

## Description
In C, there is no standard way to iterate over the elements of a variadic macro with the preprocessor. This sort of behavior can be achieved by making multiple variadic macros that simulate the different iterations of a loop, allowing you to extract and utilize the individual elements from ```__VA_ARGS__``` at compiletime.

This means that depending on the amount of iterations you want to perform, you will have to define another macro to define another step of the iteration process.

## Usage
The header file "dra_loop_args_generator.h" contains all of the code required for the code generation for the functions FOR_EACH_DO and FOR_EACH_GET

-Compile the source file "dra_loop_args_generator.c":
	Example compilation with GCC: ```gcc dra_loop_args_generator.c -o loops_generator```

-Run the program with the appropriate parameters:
	Program parameters: ```loops_generator <destination filename> <number of desired loops to generate>```
	Example execution: ```./loops_generator dra_loops.h 100```

-Include the generated header file in your program

For further reference about the usage of this code, read the code from the included examples.

## Features
-**Simple program for code generation:** Generate as many loops as you require for your project with the code gen program.
-**FOR_EACH_GET Macro:** Extract the elements from ```__VA_ARGS__```.
-**FOR_EACH_DO Macro:** Run a function or macro for each of the elements in ```__VA_ARGS__```


## Platforms
Tested with:
-**GNU GCC Linux**
-**MinGW GCC Windows**
-**MSVC Windows** (requires enabling C standard compliant preprocessor tokenization in the compiler settings)
