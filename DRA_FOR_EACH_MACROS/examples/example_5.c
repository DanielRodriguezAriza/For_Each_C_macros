/*
	Using FOR_EACH_GET for almost everything.
	FOR_EACH_GET Expands to a sequence of transforms applied to the elements in the list. Said transforms can append if needed a special character at the end or at the begining of the expansion.
	This means that you can generate lists and even have a similar behavior to FOR_EACH_DO with FOR_EACH_GET
*/

#include <stdio.h>
#include "dra_loops.h"

#define PRINT1(x) printf("this is a thing: %s\n", #x)
#define PRINT2(x) PRINT1(x) ;

int main()
{
	FOR_EACH_DO(PRINT1,1,2,3,4,5,6,7,8,9,10);
	FOR_EACH_GET(PRINT2,1,2,3,4,5,6,7,8,9,10);
	return 0;
}