#include <stdio.h>
#include "dra_loops.h"

/*
	FOR_EACH_ENUMERATE Example.
*/

#define DO_STR_LIST(type,name,printstr) "\t" #type " " #name " = " #printstr ";\n"
#define GROUPED_DO_STR_LIST(x) DO_STR_LIST x

#define GET_STRUCT_DATA(type,name,printstr) type name
#define GROUPED_GET_STRUCT_DATA(x) GET_STRUCT_DATA x

#define GET_VALUE(type,name,printstr) s->name
#define GROUPED_GET_VALUE(x) GET_VALUE x 


#define SERIALIZE_STRUCT(name, ...) struct name {\
	FOR_EACH_DO(GROUPED_GET_STRUCT_DATA,__VA_ARGS__);\
};\
\
void print_##name(struct name *s)\
{\
	printf("%s = {\n" FOR_EACH_GET(GROUPED_DO_STR_LIST,__VA_ARGS__) "}\n", #name, FOR_EACH_ENUMERATE(GROUPED_GET_VALUE,__VA_ARGS__) );\
}


#define print_int "%d"
#define print_float "%f"
#define print_char "%c"
#define print_double "%lf"


SERIALIZE_STRUCT(test_struct, (int, var_i, "%d"), (float, var_f, "%f"), (char, var_c, "%c"), (double, var_d, "%lf"), (char const *, var_string, "%s"));


int main()
{
	struct test_struct t = {69,420.34,'F',6969.3434,"Hello, cruel world!"};
	print_test_struct(&t);
	return 0;
}