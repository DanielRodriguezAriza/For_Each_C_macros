/*
	FOR_EACH_DO Example
	
	In this example file, the FOR_EACH_DO macro is used to execute a piece of code (function or macro) that takes as input parameter one of the elements from the variadic elements list from the macro.
	This means that each iteration runs the specified function as a transformation on the elements in __VA_ARGS__.
	
*/
#include <stdio.h>
#include "dra_loops_30.h"

#define say(x) printf("the type %s has a size of %zu bytes\n",#x,sizeof(x));

void print(char const *str)
{
	printf("PRINT: %s\n",str);
}

int main()
{
	FOR_EACH_DO(say,char,int,float,double,int*,char const *); /*Running a macro on every single element from the variadic list*/
	FOR_EACH_DO(print,"hi","bye","thing"); /*Running a function on every single element from the variadic list*/
	
	return 0;
}