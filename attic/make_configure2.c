
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* types[] = { "short", "int", "float", "double" };

const char* defines[] =
{
	"__APPLE_CC__",               "__APPLE_CPP__",              "applec",                     "_BOOL",                      
	"CALL_NOT_IN_CARBON",         "__CFM68K__",                 "__cplusplus",                
	"_DLL",                       "__GNUC__",                   "i386",                       "__i386__",                   
	"intel",                      "__linux__",                  "m68k",                       "_M_ALPHA",                   
	"_M_IX86",                    "_M_M68K",                    "_M_MPPC",                    "_M_MRX000",                  
	"_M_PPC",
	"__MACH__",                   "macos",                      "_MIPS_ISA",                  "__MOTO__",                   
	"MPW_C",                      "MPW_CPLUS",                  "__MRC__",                    "_MSC_VER",                   
	"_MT",                        "__MWERKS__",                 "__NEXT_CPP__",               "powerc",                     
	"__powerc",                   "ppc",                        "__ppc__",                    "__PPCC__",                   
	"__SC__",                     "__sparc",                    "__spillargs",                "__STDC__",                   
	"SYMANTEC_C",                 "THINK_C",                    "__VEC__",                    "_WIN32",                     
	"_WIN64",                     "__xlC",                      "__xlc",                      "__XLC121__",
	"__useAppleExts__", "_MAC", "macintosh"
};

const char* strings[] = {
"#include <stdarg.h>\n"
"#include <stdio.h>\n\n"
"#include <stdlib.h>\n",
"void print_string(const char* s) { printf(\"%s\", s); }\n"
"void print_format(const char* s, ... ) { va_list args; va_start(args, s); vprintf(s, args); va_end(args); }\n"
"#if defined(applec) && !defined(__SC___) && !defined(__cplusplus)\n",
"#define JK_CC \"c\"\n",
"#endif\n"
"#if defined(applec) && !defined(__SC___) && defined(__cplusplus)\n",
"#define JK_CC \"cplus\"\n",
"#endif\n",
"#if defined(applec) && defined(__SC___) && !defined(__cplusplus)\n",
"#define JK_CC \"sc\"\n"
"#endif\n"
"#if defined(applec) && defined(__SC___) && defined(__cplusplus)\n",
"#define JK_CC \"scpp\"\n",
"#endif\n",
"#if defined(__PPCC__) && !defined(__cplusplus)\n",
"#define JK_CC \"ppcc\"\n",
"#endif\n"
"#if defined(__PPCC__) && defined(__cplusplus)\n",
"#define JK_CC \"ppcc -dialect -cplus\"\n",
"#endif\n",
"#if defined(__MRC__) && !defined(__cplusplus)\n",
"#define JK_CC \"mrc\"\n",
"#endif\n"
"#if defined(__MRC__) && defined(__cplusplus)\n",
"#define JK_CC \"mrcpp\"\n",
"#endif\n",
"#if defined(__MWERKS__) && !defined(__powerc)\n",
"#define JK_CC \"mw68k\"\n",
"#endif\n",
"#if defined(__MWERKS__) && defined(__powerc)\n",
"#define JK_CC \"mwcppc\"\n",
"#endif\n",
"const char *envvars[] = { \"COMMANDS\", \"MPW\", \"MACHTYPE\", \"OSTYPE\", \"PATH\", \"OS\", \"SYSTEMDRIVE\", \"SYSTEMROOT\", \"WINDIR\", \"PROCESSOR_ARCHITECTURE\" };\n",
"\n",
"int main(int argc, char** argv)\n"
"{\nconst char *s = 0;\n",
"const char *t = 0;\n",
"size_t i = 0;\n"
"size_t j = 0;\n"
"size_t k = 0;\n",
0,
"if (argc < 0)\n"
"  return -1;\n",
"\n"
"print_format(\"argv[0]=%s \", argv[0]);\n",
"\n"
"j = sizeof(envvars)/sizeof(envvars[0]);\n"
"for (i = 0 ; i != j ; ++i)\n"
"{\n"
"  if ((s = getenv(t = envvars[i])) != 0)\n"
"    print_format(\"$%s=%s \", t, s);\n"
"}\n",
0,
"print_string(\"\\n\");\n"
"return 0;\n}\n",
0
};

void print_string(const char* s) { printf("%s", s); }
void print_format(const char* s, ... ) { va_list args; va_start(args, s); vprintf(s, args); va_end(args); }
void string_format(char* buffer, size_t n, const char* format, ... )
{
	va_list args;
	va_start(args, format);
	buffer[n - 1] = 0;
	vsprintf(buffer, format, args);
	if (buffer[n - 1] != 0)
		abort();
	va_end(args);
}

int
caseinsensitive_strcmp(const char *s, const char *t)
{
	while (1)
	{
		unsigned char c1 = *(unsigned char*)s;
		unsigned char c2 = *(unsigned char*)t;
		if (c1 != c2)
		{
			c1 = tolower(c1);
			c2 = tolower(c2);
		}
		if (c1 == 0 && c2 == 0)
		{
			return 0;
		}
		else if (c1 == c2)
		{
			s += 1;
			t += 1;
			continue;
		}
		if (c1 < c2)
			return -1;
		else if (c1 > c2)
			return 1;
		else if (c1 == 0)
		{
			if (c2 == 0)
				return 0;
			return 1;
		}
		else if (c2 == 0)
		{
			return -1;
		}
	}
}

#if defined(__cplusplus)
extern "C"
#endif
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
	i = caseinsensitive_strcmp(s1, s2);
	
	if (i < 0)
		return -1;
	if (i > 0)
		return 1;
	return 0;	
}

#if defined(__cplusplus)
extern "C"
#endif
int
compare2(
	const void *v1,
	const void* v2
	)
{
	const char* s1 = *(const char**)v1;
	const char* s2 = *(const char**)v2;
	int i = 0;
	
	i = caseinsensitive_strcmp(s1, s2);
	
	if (i < 0)
		return -1;
	if (i > 0)
		return 1;
	return 0;	
}

int main(int argc, char** argv)
{
	const char *c = 0;
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;
	char *argv1 = 0;
	int option = 0;
	int length = 0;
	int longest = 0;
	int line_length = 0;
	char s[100];
	const char *t = 0;
	
	print_format("/* argc=%d, argv[0]=%s, argv[1]=%s */\n", argc, argv[0] ? argv[0] : "", (argv1 = (argv[1] ? argv[1] : "")));
	
	if (argv1)
	{
		option = atoi(argv1);
	}
	switch (option)
	{
	case 1:
		j = sizeof(defines)/sizeof(defines[0]);
		qsort(defines, j, sizeof(defines[0]), compare2);
		qsort(defines, j, sizeof(defines[0]), compare1);
		for (i = 0 ; i != j ; ++i)
		{
			length = (int)strlen(defines[i]);
			length += 3;
			if (length > longest)
			{
				longest = length;
			}
		}
		for (i = 1 ; i != j ; ++i)
		{
			if (strcmp(defines[i], defines[i - 1]))
			{
				k += 1;
			}
			defines[k] = defines[i];
		}
		print_format("longest %d\n", longest);
		assert(longest < sizeof(s));				
		line_length += longest;
		for (i = 0 ; i != k ; ++i)
		{
			if (i != 0 && (i % 4) == 0)
			{
				print_string("\n");
			}
			string_format(s, sizeof(s), "\"%s\", ", defines[i]);
			if (((i + 1) % 4) == 0)
			{
				print_format("%s", s);
			}
			else
			{
				print_format("%-*s", longest, s);
			}
		}
		break;
	case 0:
	
		k = 0;
		while ((t = strings[k++]) != 0)
			print_string(t);

		j = sizeof(types)/sizeof(types[0]);

		print_string("const char *types[] = {");
		for (i = 0 ; i != j ; ++i)
			print_format("%s\"%s\"", (i != 0 ? "," : ""), types[i]);
		print_string("};\n");

		print_string("unsigned long type_sizes[] = {");
		for (i = 0 ; i != j ; ++i)
			print_format("%ssizeof(%s)", (i != 0 ? "," : ""), types[i]);
		print_string("};\n");

		while ((t = strings[k++]) != 0)
			print_string(t);

		print_string("#if defined(JK_CC)\n");
		print_format("print_format(\"%s=%%s \", %s);\n", "JK_CC", "JK_CC");
		print_string("#endif\n");
		j = sizeof(defines)/sizeof(defines[0]);
		for (i = 0 ; i != j ; ++i)
		{
			print_format("#if defined(%s)\n", defines[i]);
			print_format("print_string(\"%s \");\n", defines[i]);
			print_string("#endif\n");
		}

		while ((t = strings[k++]) != 0)
			print_string(t);
		
		break;
	}
	return 0;
}
