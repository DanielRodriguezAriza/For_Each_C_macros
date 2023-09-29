#ifndef DRA_LOOP_ARGS_GENERATOR_H
#define DRA_LOOP_ARGS_GENERATOR_H

#include <stdio.h>
#include <stdint.h>

char start_header_info[] = "#ifndef DRA_LOOPS_ARGS_H\n#define DRA_LOOPS_ARGS_H\n";
char end_header_info[] = "#endif\n";
char first_loop[] = "#define FOR_EACH_DO_1(fn,x) fn(x)\n";
char nth_loop[] = "#define FOR_EACH_DO_%d(fn,x,...) fn(x); FOR_EACH_DO_%d(fn,__VA_ARGS__)\n";


char first_get_loop[] = "#define FOR_EACH_GET_1(fn,x) fn(x)\n";
char nth_get_loop[] = "#define FOR_EACH_GET_%d(fn,x,...) fn(x) FOR_EACH_GET_%d(fn,__VA_ARGS__)\n";

char loop_fn[] = "#define FOR_EACH_DO(fn,...) COUNT_NUM_ARGS_FN_CALL(FOR_EACH_DO,__VA_ARGS__) (fn,__VA_ARGS__)\n";
char loop_get_fn[] = "#define FOR_EACH_GET(fn,...) COUNT_NUM_ARGS_FN_CALL(FOR_EACH_GET,__VA_ARGS__) (fn,__VA_ARGS__)\n";

char count_num_args_impl_start[] = "#define COUNT_NUM_ARGS_IMPL(";
char count_num_args_impl_end[] = "N,...) N\n";

char count_num_args_fn_start[] = "#define COUNT_NUM_ARGS(...) COUNT_NUM_ARGS_IMPL(__VA_ARGS__";
char count_num_args_fn_end[] = ")\n";

char count_num_args_fn_call_start[] = "#define COUNT_NUM_ARGS_FN_CALL(func_name,...) COUNT_NUM_ARGS_IMPL(__VA_ARGS__";
char count_num_args_fn_call_end[] = ")\n";

/* example usage: */ /* dra_generate_loop_args("./dra_loop_args.h",100); */ /* generates a file called "dra_loop_args.h" that contains definitions for up to 100 loops.*/
void dra_generate_loop_args(char const *filename, size_t count)
{
	printf("Generating file...\n");
	
	FILE *file;
	file = fopen(filename,"wb");
	
	fwrite(start_header_info,sizeof(char),sizeof(start_header_info) - 1,file);
	
	fwrite(first_loop,sizeof(char),sizeof(first_loop) - 1,file);
	for(size_t i = 2; i <= count; ++i)
	{
		fprintf(file,nth_loop,i,i-1);
	}
	fwrite(loop_fn,sizeof(char),sizeof(loop_fn) - 1,file);
	
	fwrite(first_get_loop,sizeof(char),sizeof(first_get_loop) - 1,file);
	for(size_t i = 2; i <= count; ++i)
	{
		fprintf(file,nth_get_loop,i,i-1);
	}
	fwrite(loop_get_fn,sizeof(char),sizeof(loop_get_fn) - 1,file);
	
	
	fwrite(count_num_args_impl_start,sizeof(char),sizeof(count_num_args_impl_start) - 1,file);
	for(size_t i = 1; i<= count; ++i)
	{
		fprintf(file,"_%d,",i);
	}
	fwrite(count_num_args_impl_end,sizeof(char),sizeof(count_num_args_impl_end) - 1,file);
	
	fwrite(count_num_args_fn_start,sizeof(char),sizeof(count_num_args_fn_start) - 1,file);
	for(size_t i = 0; i <= count; ++i)
	{
		fprintf(file,",%d",count-i);
	}
	fwrite(count_num_args_fn_end,sizeof(char),sizeof(count_num_args_fn_end) - 1,file);
	
	fwrite(count_num_args_fn_call_start,sizeof(char),sizeof(count_num_args_fn_call_start) - 1,file);
	for(size_t i = 0; i <= count; ++i)
	{
		fprintf(file,",func_name##_%d",count-i);
	}
	fwrite(count_num_args_fn_call_end,sizeof(char),sizeof(count_num_args_fn_call_end) - 1,file);
	
	fwrite(end_header_info,sizeof(char),sizeof(end_header_info) - 1,file);
	fclose(file);
	
	printf("Finished.\n");
}

#endif