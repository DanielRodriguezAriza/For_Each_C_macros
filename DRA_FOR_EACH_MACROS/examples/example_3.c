/*
	FOR_EACH_DO and FOR_EACH_GET Example
*/
#include <stdio.h>
#include "dra_loops_30.h"

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

/*
	Useful for debugging.
	Equivalent hand-written implementation in C would be error prone and harder to maintain:
	
	typedef enum TokenList
	{
		TOKEN0 = 0,
		TOKEN1,
		TOKEN2,
		TOKEN3,
		TOKEN4,
		NUM_TOKENS
	} TokenList;
	
	static char const *TokenNameList[] = {
		"TOKEN0",
		"TOKEN1",
		"TOKEN2",
		"TOKEN3",
		"TOKEN4",
		"NUM_TOKENS"
	};
	
	This can quickly get out of hand when defining large enums for things like a Tokenizer or a Parser, where the ability of a token to be printable is desirable for debugging and error reporting.
	
*/

int main()
{
	/*Printing the name of all the Tokens from the TokenList enum*/
	for(size_t i = 0; i < NUM_TOKENS; ++i)
	{
		printf("Token with ID %d has string %s\n",i,TokenNameList[i]);
	}
	
	return 0;
}