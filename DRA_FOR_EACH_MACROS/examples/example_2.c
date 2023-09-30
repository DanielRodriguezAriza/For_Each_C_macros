/*
	FOR_EACH_GET Example
*/
#include <stdio.h>
#include "dra_loops_30.h"

#define STRINGIFY_AND_ADD_TO_LIST(x) #x ,

int main()
{
	/*Creating a list of strings from a set of identifiers*/
	char const *arr[] = {
		FOR_EACH_GET(STRINGIFY_AND_ADD_TO_LIST,
			identifier1,
			identifier2,
			identifier3,
			identifier4
		)
	};
	
	/*Printing all the elements in the array*/
	for(size_t i = 0; i < 4; ++i)
	{
		printf("arr[%d] = %s\n",i,arr[i]);
	}
	
	return 0;
}