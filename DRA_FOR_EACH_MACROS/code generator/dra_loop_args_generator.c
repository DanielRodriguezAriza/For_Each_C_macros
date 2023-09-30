#include <stdio.h>
#include <stdlib.h> 
#include "dra_loop_args_generator.h"

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		fprintf(stderr,"Usage: %s <dest filename> <num loops>\n", argv[0]);
		exit(-1);
	}
	
	printf("DRA code generation: Generating file \"%s\"...\n",argv[1]);
	
	int status = dra_generate_loop_args(argv[1],atoi(argv[2]));
	
	if(status != 0)
	{
		fprintf(stderr,"DRA code generation: ERROR: Could not generate file!\n");
	}
	else
	{
		printf("DRA code generation: Successfully finished generating file!\n");
	}
	
	return 0;
}
