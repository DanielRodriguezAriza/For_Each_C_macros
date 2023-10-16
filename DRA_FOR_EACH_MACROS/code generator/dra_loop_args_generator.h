#ifndef DRA_LOOP_ARGS_GENERATOR_H
#define DRA_LOOP_ARGS_GENERATOR_H

#include <stdio.h>
#include <stdint.h>

static char const DRA_LARGS_HEADER_START[] = "#ifndef DRA_LOOPS_ARGS_H\n#define DRA_LOOPS_ARGS_H\n";
static char const DRA_LARGS_HEADER_END[] = "#endif\n";

static char const DRA_LARGS_FOR_EACH_DO_FIRST_LOOP[] = "#define FOR_EACH_DO_1(fn,x) fn(x)\n";
static char const DRA_LARGS_FOR_EACH_DO_NTH_LOOP[] = "#define FOR_EACH_DO_%d(fn,x,...) fn(x); FOR_EACH_DO_%d(fn,__VA_ARGS__)\n";

static char const DRA_LARGS_FOR_EACH_GET_FIRST_LOOP[] = "#define FOR_EACH_GET_1(fn,x) fn(x)\n";
static char const DRA_LARGS_FOR_EACH_GET_NTH_LOOP[] = "#define FOR_EACH_GET_%d(fn,x,...) fn(x) FOR_EACH_GET_%d(fn,__VA_ARGS__)\n";

static char const DRA_LARGS_FOR_EACH_ENUMERATE_FIRST_LOOP[] = "#define FOR_EACH_ENUMERATE_1(fn,x) fn(x)\n";
static char const DRA_LARGS_FOR_EACH_ENUMERATE_NTH_LOOP[] = "#define FOR_EACH_ENUMERATE_%d(fn,x,...) fn(x) , FOR_EACH_ENUMERATE_%d(fn,__VA_ARGS__)\n";

static char const DRA_LARGS_FOR_EACH_DO_DEF[] = "#define FOR_EACH_DO(fn,...) COUNT_NUM_ARGS_FN_CALL(FOR_EACH_DO,__VA_ARGS__) (fn,__VA_ARGS__)\n";
static char const DRA_LARGS_FOR_EACH_GET_DEF[] = "#define FOR_EACH_GET(fn,...) COUNT_NUM_ARGS_FN_CALL(FOR_EACH_GET,__VA_ARGS__) (fn,__VA_ARGS__)\n";
static char const DRA_LARGS_FOR_EACH_ENUMERATE_DEF[] = "#define FOR_EACH_ENUMERATE(fn,...) COUNT_NUM_ARGS_FN_CALL(FOR_EACH_ENUMERATE,__VA_ARGS__) (fn,__VA_ARGS__)\n";

static char const DRA_LARGS_COUNT_NARGS_IMPL_START[] = "#define COUNT_NUM_ARGS_IMPL(";
static char const DRA_LARGS_COUNT_NARGS_IMPL_END[] = "N,...) N\n";

static char const DRA_LARGS_COUNT_NARGS_START[] = "#define COUNT_NUM_ARGS(...) COUNT_NUM_ARGS_IMPL(__VA_ARGS__";
static char const DRA_LARGS_COUNT_NARGS_END[] = ")\n";

static char const DRA_LARGS_COUNT_NARGS_CALL_START[] = "#define COUNT_NUM_ARGS_FN_CALL(func_name,...) COUNT_NUM_ARGS_IMPL(__VA_ARGS__";
static char const DRA_LARGS_COUNT_NARGS_CALL_END[] = ")\n";

int dra_generate_loop_args(char const *filename, size_t count)
{
	FILE *file;
	file = fopen(filename,"wb");
	
	if(file == NULL)
	{
		return -1;
	}
	
	fprintf(file,"%s",DRA_LARGS_HEADER_START);
	
	fprintf(file,"%s",DRA_LARGS_FOR_EACH_DO_FIRST_LOOP);
	for(size_t i = 2; i <= count; ++i)
	{
		fprintf(file,DRA_LARGS_FOR_EACH_DO_NTH_LOOP,i,i-1);
	}
	fprintf(file,"%s",DRA_LARGS_FOR_EACH_DO_DEF);
	
	fprintf(file,"%s",DRA_LARGS_FOR_EACH_GET_FIRST_LOOP);
	for(size_t i = 2; i <= count; ++i)
	{
		fprintf(file,DRA_LARGS_FOR_EACH_GET_NTH_LOOP,i,i-1);
	}
	fprintf(file,"%s",DRA_LARGS_FOR_EACH_GET_DEF);
	
	fprintf(file, "%s", DRA_LARGS_FOR_EACH_ENUMERATE_FIRST_LOOP);
	for(size_t i = 2; i <= count; ++i)
	{
		fprintf(file,DRA_LARGS_FOR_EACH_ENUMERATE_NTH_LOOP,i,i-1);
	}
	fprintf(file,"%s", DRA_LARGS_FOR_EACH_ENUMERATE_DEF);
	
	fprintf(file,"%s",DRA_LARGS_COUNT_NARGS_IMPL_START);
	for(size_t i = 1; i<= count; ++i)
	{
		fprintf(file,"_%d,",i);
	}
	fprintf(file,"%s",DRA_LARGS_COUNT_NARGS_IMPL_END);
	
	fprintf(file,"%s",DRA_LARGS_COUNT_NARGS_START);
	for(size_t i = 0; i <= count; ++i)
	{
		fprintf(file,",%d",count-i);
	}
	fprintf(file,"%s",DRA_LARGS_COUNT_NARGS_END);
	
	fprintf(file,"%s",DRA_LARGS_COUNT_NARGS_CALL_START);
	for(size_t i = 0; i <= count; ++i)
	{
		fprintf(file,",func_name##_%d",count-i);
	}
	fprintf(file,"%s",DRA_LARGS_COUNT_NARGS_CALL_END);
	
	fprintf(file,"%s",DRA_LARGS_HEADER_END);
	
	fclose(file);
	
	return 0;
}

#endif
