
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>

int printf(const char *, ...);
int vprintf(const char*, va_list);

void print_string(const char* s) { printf("%s", s)); }
void print_with_format(const char* s, ... ) { va_list args; va_start(args, s); vprintf(s, args); va_end(args); }

int
compare1(
	const void *v1,
	const void* v2
	)
{
	const char* s1 = *(const char**)v1;
	const char* s2 = *(const char**)v2;
	int i = 0;
	
	s1 += strspn(s1, "_");
	s2 += strspn(s2, "_");
	i = strcmp(s1, s2);
	
	if (i < 0)
		return -1;
	if (i > 0)
		return +1;
	return 0;	
}

int main(int argc, char** argv)
{
	const char* a[] =
	{
	"__SC__",               "MPW_C",             "MPW_CPLUS",                 "__cplusplus",         "__cpluscplus",
	"_MSC_VER",             "__MWERKS__",        "__MRC__",                   "SYMANTEC_C",          "__useAppleExts__",
	"applec",               "__STDC__",          "__PPCC__",                   "__STDC__",           "CALL_NOT_IN_CARBON", 
	"__powerc",             "powerc",            "__CFM68K__",                 "MAC_CONV_IS_A_PLIST",
	"MAC_CTOR_OPTS",        "MAC_DEBUG_MISC",    "MAC_FIX_ATT2_0_BUG",
	"MAC_FIX_ATT2_1_0_BUG", "MAC_LOAD_DUMP",     "MAC_MARK_OPTION",            "MAC_MISC",
	"MAC_PASCAL",           "MAC_PASCAL_OBJECT", "MAC_SADE_SUPPORT",           "MAC_SANE",
	"MAC_SCANNER",          "MAC_TOKEN_STREAM",	 "MAC_USUALLY_OMIT_THE_SUFFIX",
	"__spillargs",          "__VEC__",			  "__ppc__",					"ppc",
	"__GNUC__",				"__APPLE_CPP__",	  "__APPLE_CC__",				"__NEXT_CPP__",
	"__xlC",				"THINK_C",
	"__MACH__",				"m68k", "sparc",
	"__i386__",             "i386", "intel", "__linux__", "macos",
	"__xlc", "__xlC", "__xlC__", "__XLC121__",
	"_M_MPPC", "_M_IX86", "_M_PPC", "_M_ALPHA", "__MOTO__", "_MIPS_ISA", "_BOOL", "__sparc", "_M_M68K", "_M_MRX000", 
		
	}
	;
	const char *b[] = { "short", "int", "float", "double" };
	
	const char *c = 0;
	size_t j = 0;
	size_t i = 0;
	char *argv1 = 0;
	int option = 0;
	int length = 0;
	int longest = 0;
	int line_length = 0;
	char s[100];
	
	print_with_format("/* argc=%d, argv[0]=%s, argv[1]=%s */\n", argc, argv[0] ? argv[0] : "", (argv1 = (argv[1] ? argv[1] : "")));
	
	if (argv1)
	{
		option = atoi(argv1);
	}
	switch (option)
	{
	case 1:
		qsort(a, sizeof(a), sizeof(a[0]), compare1);
		j = sizeof(a)/sizeof(a[0]);
		for (i = 0 ; i != j ; ++i)
		{
			length = (int)strlen(a[i]);
			longest += 3;
			if (length > longest)
			{
				longest = length;
			}
		}
		assert(longest < sizeof(s));				
		line_length += longest;
		for (i = 0 ; i != j ; ++i)
		{
			sprintf(s, "\"%*s\", ", a[i]);
			printf("%.*s, ", longest, s);
			line_length += longest;
			if (line_length > 70)
			{
				print_string("\n");
				line_length += 1;
			}
		}
		break;
	case 0:
		printf("\
int printf(const char *, ...);\n\
int main(int argc, char** argv)\n\
{\n\
if (argc < 0) return -1;\n\
printf(\"argv[0]=%%-22s \", argv[0]);\n\
\n\
");
		j = sizeof(a)/sizeof(a[0]);
		for (i = 0 ; i != j ; ++i)
		{
			print_with_format("#if defined(%s)\n", a[i]);
			print_with_format("printf(\"%s=%%lu \", (unsigned long)%s);\n", a[i], a[i]);
			print_with_format("printf(\"%s=0x%%-8lx \", (unsigned long)%s);\n", a[i], a[i]);
			print_string("#else\n");
			print_with_format("printf(\"%s=0 \");\n", a[i]);
			print_string("#endif\n");
		}
		j = sizeof(b)/sizeof(b[0]);
		for (i = 0 ; i != j ; ++i)
		{
			print_with_format("printf(\"sizeof(%s) == %%lu \", (unsigned long)sizeof(%s));\n", b[i], b[i]);
		}
		print_string("printf(\"\\n\");\n");
		print_string("return 0;\n}\n");
		break;
	}
	return 0;
}
