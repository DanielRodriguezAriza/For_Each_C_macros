#include <stdio.h>
#include "dra_loops.h"

#define say(x) printf("the type %s has a size of %zu bytes\n",#x,sizeof(x));

#define GET_ENUM_ELEM_NAME(x) x ,
#define GET_ENUM_ELEM_STRING(x) #x ,

#define MAKE_ENUM_AND_STR(enum_name, str_name, ...)\
typedef enum enum_name\
{\
	FOR_EACH_GET(GET_ENUM_ELEM_NAME,__VA_ARGS__)\
} enum_name;\
\
static char const *str_name[] = {\
	FOR_EACH_GET(GET_ENUM_ELEM_STRING,__VA_ARGS__)\
};

/*Creating an enum with the elements named TOKEN0,TOKEN1,...,NUM_TOKENS and an array of strings where the token names are stored as well.*/
MAKE_ENUM_AND_STR(TokenList,TokenNameList,TOKEN0,TOKEN1,TOKEN2,TOKEN3,TOKEN4,NUM_TOKENS);

void print(char const *str)
{
	printf("PRINT: %s\n",str);
}

int main()
{
	FOR_EACH_DO(say,char,int,float,double,int*,char const *); /*Running a macro on every single element from the variadic list*/
	FOR_EACH_DO(print,"hi","bye","thing"); /*Running a function on every single element from the variadic list*/
	
	char const *arr[] = {FOR_EACH_GET(GET_ENUM_ELEM_STRING,A,B,C,D)}; /*Creating a list of strings (this example exists only for the purpose of making the code in MAKE_ENUM_AND_STR clearer)*/
	
	/*Printing all the elements in the array "arr"*/
	for(size_t i = 0; i < 4; ++i)
	{
		printf("arr[%d] = %s\n",i,arr[i]);
	}
	
	/*Printing the name of all the Tokens from the TokenList enum*/
	for(size_t i = 0; i < NUM_TOKENS; ++i)
	{
		printf("Token with ID %d has string %s\n",i,TokenNameList[i]);
	}
	
	return 0;
}