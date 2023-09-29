#include <stdio.h>
#include <stdlib.h> 
#include "include/loop_args_generator.h"

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		fprintf(stderr,"Usage: %s <dest filename> <num loops>\n", argv[0]);
		exit(-1);
	}
	
	dra_generate_loop_args(argv[1],atoi(argv[2]));
	
	return 0;
}