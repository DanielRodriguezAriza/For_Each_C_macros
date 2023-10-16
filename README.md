# For Each C macros

## Introduction
A simple header that offers the ability to get elements from ```__VA_ARGS__``` and apply a transform macro to all of them.
Comes with a simple code generator program to generate the headers that contain the definitions for the for each macros, with as many iterations as the user desires.

## Description
In C, there is no standard way to iterate over the elements of a variadic macro with the preprocessor. This sort of behavior can be achieved by making multiple variadic macros that simulate the different iterations of a loop, allowing you to extract and utilize the individual elements from ```__VA_ARGS__``` at compiletime.

This means that depending on the amount of iterations you want to perform, you will have to define another macro to define another step of the iteration process.

This project takes care of that, by offering headers with macro definitions that allow you to loop for multiple elements. The default header offered in the include folder offers up to 30 iterations, but if more are required, you can compile and run the code generator to create files with hundreds or thousands of iterations (as many as you require).

## Usage
If you simply want to make use of the FOR_EACH_ macros, you can open the include folder and include the header inside in your project. That header offers 30 iterations for all the FOR_EACH_ macros.

If you require more than 30 iterations, you can build the code generator and create a header with as many iterations as required by your project.
The header file "dra_loop_args_generator.h" contains all of the code required for the code generation for the FOR_EACH_ macros.

- **Compile the source file "dra_loop_args_generator.c":**
	- **Example compilation with GCC:** ```gcc dra_loop_args_generator.c -o loops_generator```

- **Run the program with the appropriate parameters:**
	- **Program parameters:** ```loops_generator <destination filename> <number of desired loops to generate>```
 	- **Example execution to generate 100 loop macros:** ```./loops_generator dra_loops.h 100```

- **Include the generated header file in your program.**

For further reference about the usage of this code, read the code from the included examples.

## Features
- **Simple program for code generation:** Generate as many loops as you require for your project with the code gen program.
- **FOR_EACH_ macros:** Extract the elements from ```__VA_ARGS__``` and apply a transform to them (a function or another macro). Each macro offers a different additional behavior which allows you to select the right macro for the right situation.
- **FOR_EACH_GET Macro:** Used when you require the output of the FOR_EACH_ macro to return the raw transform of the macro or function over all the elements. ```FOR_EACH_GET(TRANSFORM,elem1,elem2,elem3)``` would lead to the macro expansion ```TRANSFORM(elem1) TRANSFORM(elem2) TRANSFORM(elem3)```.
- **FOR_EACH_DO Macro:** Used when you require the output of the FOR_EACH_ macro to return a series of semicolon delimited transform executions over all the elements. ```FOR_EACH_DO(TRANSFORM,elem1,elem2,elem3)``` would lead to the macro expansion ```TRANSFORM(elem1); TRANSFORM(elem2); TRANSFORM(elem3)```. Note that the last element does not get a semicolon appended, meaing that the FOR_EACH_DO macro is used in a similar way to any other C function, requiring the user to write a semicolon after using the macro.
- **FOR_EACH_ENUMERATE Macro:** Used when you require the output of the FOR_EACH_ macro to return an enumerated list of the transformed elements. ```FOR_EACH_ENUMERATE(TRANSFORM,elem1,elem2,elem3)``` would lead to the macro expansion ```TRANSFORM(elem1), TRANSFORM(elem2), TRANSFORM(elem3)```. Note that the last element does not get a comma appended, meaning that the FOR_EACH_ENUMERATE macro can be used in variading functions or any other situation where a comma delimited list is required. A similar behavior can be obtained with the FOR_EACH_GET macro by using a transform that appends commas at the end of each element, but that will only work with enums and array initializer lists in C.


## Platforms
Tested with:
- **GNU GCC Linux**
- **MinGW GCC Windows**
- **MSVC Windows** (requires enabling C standard compliant preprocessor tokenization in the compiler settings)
