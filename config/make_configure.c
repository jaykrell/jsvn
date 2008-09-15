
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef unsigned char boolean;
#define TRUE 1
#define FALSE 0

char* types[] = { "short", "int", "float", "double" };

char* defines[] =
{
	"__APPLE_CC__",
    "__APPLE_CPP__",
    "applec",
	"__useAppleExts__",

    "_BOOL",
	"CALL_NOT_IN_CARBON",
    "__CFM68K__", /* Macintosh Code Fragment Manager for 68K -- CFM is a more "normal" runtime architecture than previously. */
    "__cplusplus",
	"_DLL",     /* Microsoft targeting C runtime in a .dll */
	"_MT",      /* Microsoft targeting multithreaded C runtime (thread safe) */
    "__GNUC__",
    "i386",
    "__i386__",
    "__386__",
    "__86__",
	"intel",
    "__linux__",
    "m68k",
    "_MSC_VER", /* Microsoft C, various versions, including 16 bit, 32 bit, 64 bit */
    "_M_ALPHA", /* Microsoft C, 32 bit int, 32 bit long, 32 bit size_t, NT, Alpha */
	"_M_IX86",  /* Microsoft C, 32 bit int, 32 bit long, 32 bit size_t, NT/Win9x, x86, Win3.1?, (386 or newer)? */
    "_M_M68K",  /* Microsoft C, 32 bit int, 32 bit long, 32 bit size_t, Macintosh, 68k */
    "_M_MPPC",  /* Microsoft C, 32 bit int, 32 bit long, 32 bit size_t, Macintosh, PowerPC, NT Xbox? */
	"_M_PPC",   /* Microsoft C, 32 bit int, 32 bit long, 32 bit size_t, NT, PowerPC, NT Xbox? */
    "_M_MRX000",  /* Microsoft C, 32 bit int, 32 bit long, 32 bit size_t, NT, Mips */
	"__MACH__",
    "macos",
    "_MAC",
    "macintosh",
    "_MIPS_ISA",
    "__MOTO__",
	"MPW_C",
    "MPW_CPLUS",
    "__MRC__",
    "__MWERKS__",
    "__NEXT_CPP__",
    "powerc",
	"__powerc",
    "ppc",
    "__ppc__",
    "__PPCC__",
    "__sparc",
    "__spillargs",
    "__STDC__",
	"SYMANTEC_C",
    "THINK_C",
    "__VEC__",
    "_WIN32",
	"_WIN64",
    "_WINDOWS",
    "__xlC",
    "__xlc",
    "__XLC121__",
    "__ORCAC__", /* ORCA/C ANSI C for Apple IIGS 65816 16 bit int, 32 bit size_t?, optional 32 bit int */
    "__SC__", /* Symantec C -- always for 68k Macintosh? */
    "__DOS__",

    /* Watcom defines */

};

char* envvar_names[] = {
"PATH", /* Unix, Windows, Macosx (not MPW) */
"COMMANDS", "MPW", "SYSTEMFOLDER", /* MPW */
"MACHTYPE", "OSTYPE", /* Macosx */
"WINDIR", /* Windows (3x, 9x, NT) */
"OS", "SYSTEMDRIVE", "SYSTEMROOT", "PROCESSOR_ARCHITECTURE", /* Windows NT/2000/XP/2003 */
"PROCESSOR_ARCHITEW6432", /* 32bit on 64bit Windows */

/* environment variables that affect Watcom */
"LIBOS2",  /* not recommended */
"LIB",     /* not recommended */
"LIBWIN",  /* not recommended */
"LIBDOS",  /* not recommended */
"LIBPHAR", /* not recommended */
"INCLUDE",
"FORCE",
"NO87",
"TMP",
"WATCOM",  /* e.g. c:\watcom */
"WCC",
"WCC386",
"WCL",
"WCL386",
"WCGMEMORY",
"WD",     /* debugger options */
"WDW",    /* Windows debugger options */
"WLANG",  /* what language to issue warnings/errors in -- English, Japaense, 0 (English), or 1 (Japanese) */
"WPP",    /* options for 16 bit C++ compiler */
"WPP386", /* options for 32 bit C++ compiler */
};

const char* strings[] = {
"#include <stdarg.h>\n"
"#include <stdio.h>\n"
"#include <stdlib.h>\n",
"#include <string.h>\n",
"void print_string(char* s) { printf(\"%s\", s); }\n"
"void print_format(char* s, ... ) { va_list args; va_start(args, s); vprintf(s, args); va_end(args); }\n"
"void* alloc(size_t n) { void* p = malloc(n); if (p == NULL) { printf(\"out of memory\n\"); abort(); } return p; }\n"
"char* string_duplicate(const char* s)"
"{"
"	size_t n = strlen(s);"
"	char* t = (char*) alloc(n + 1);"
"	memcpy(t, s, n);"
"	t[n] = 0;"
"	return t;"
"}\n"
"#if defined(applec) && !defined(__SC__) && !defined(__cplusplus)\n",
"#define JK_CC \"c\"\n",
"#endif\n"
"#if defined(applec) && !defined(__SC__) && defined(__cplusplus)\n",
"#define JK_CC \"cplus\"\n",
"#endif\n",
"#if defined(applec) && defined(__SC__) && !defined(__cplusplus)\n",
"#define JK_CC \"sc\"\n"
"#endif\n"
"#if defined(applec) && defined(__SC__) && defined(__cplusplus)\n",
"#define JK_CC \"scpp\"\n",
"#endif\n",
"#if defined(__PPCC__) && !defined(__cplusplus)\n",
"#define JK_CC \"ppcc\"\n",
"#endif\n"
"#if defined(__PPCC__) && defined(__cplusplus)\n",
"#define JK_CC \"\\\"ppcc -dialect -cplus\\\"\"\n",
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
	0,
"\n",
"int main(int argc, char** argv)\n"
"{\n"
"char* s = 0;\n"
"char* t = 0;\n",
"size_t i = 0;\n"
"size_t j = 0;\n"
"\n"
"if (argc < 0)\n"
"  return -1;\n",
"\n"
"print_format(\"argv[0]=%s \", argv[0]);\n",
"\n"
"#if defined(JK_CC)\n",
"print_format(\"JK_CC=%s \", JK_CC);\n",
"#endif\n",
"\n"
"for (i = 0 ; ((s = defines[i]) != 0) ; ++i)\n"
"    print_string(s);\n"
"\n"
"j = sizeof(envvar_names)/sizeof(envvar_names[0]);\n"
"for (i = 0 ; i != j ; ++i)\n"
"{\n"
"  if ((s = getenv(t = envvar_names[i])) != 0)\n"
"{\n"
"    envvar_values.array[i] = s = string_duplicate(t);\n"
"    print_format(\"$%s=%s \", t, s);\n"
"}\n"
"}\n",
"print_string(\"\\n\");\n"
"return 0;\n}\n",
0
};

char* compiler;

char* search_mpw_path(char* a, char* b)
{
	return 0;
}

void is_executable()
{
}

typedef struct file_in_memory_t
{
	void (*cleanup)(struct file_in_memory_t*);
	void * base;
	unsigned long size;
	unsigned is_mz : 1;
	unsigned is_pe : 1;
	unsigned is_pef : 1;
} file_in_memory_t;


char * get_temp_file_path(void)
{

}

boolean is_microsoft_compiler()
{
}

boolean is_microsoft_linker()
{
}

void determine_compiler()
{
/*
examples include:
 /usr/bin/cc
 /usr/bin/gcc
 c:\program files\devstudio\vc\bin\cl.exe
 {MPW}Commands:CPlus
 {MPW}Commands:mrc
 {MPW}Commands:sc
 {MPW}Commands:mrcpp
 {MPW}Commands:scpp
 \msdev\10\bin\cl.exe
 \msdev\15\bin\cl.exe
 \msdev\20\bin\cl.exe
 \msdev\40\bin\cl.exe
 \msdev\40\mac\m68k\bin\cl.exe
 \msdev\40\mac\mppc\bin\cl.exe
 \msdev\41\bin\cl.exe
 \msdev\41\mac\m68k\bin\cl.exe
 \msdev\41\mac\mppc\bin\cl.exe
 \msdev\42\bin\cl.exe
 \msdev\42\mac\m68k\bin\cl.exe
 \msdev\42\mac\mppc\bin\cl.exe
 \msdev\50\vc\bin\cl.exe
 \msdev\60\vc98\bin\cl.exe
 \msdev\70\vc7\bin\cl.exe
 \msdev\71\bin\cl.exe
 \msdev\80\vc\bin\cl.exe
*/
 char* mpw_compilers = "C\0CPlus\0mrc\0sc\0mrcpp\0scpp\0mwc68k\0mwcppc\0cciigs\0";
 char* commands = getenv("commands");
 char* path = getenv("path");
 char* lib = getenv("lib");
 char* includes = getenv("includes");
 char* jk_cc = getenv("jk_cc");
 FILE* f;
 if (jk_cc)
 {
   printf("environment override used: jk_cc=%s\n", jk_cc);
   f = fopen(jk_cc, "rb");
   if (f) fclose(f);
   if (!f)
   {
      if (!strchr(jk_cc, '\\') && !strchr(jk_cc, '//') && !strchr(jk_cc, ':'))
	  {
        printf("jk_cc not found, will search path\n");
	  }
	  else
	  {
        printf("jk_cc not found\n");
	  }
   }
 if (commands && !path)
 {
   char* found = 0;
   char * a;
   printf("this appears to be MPW; MPW can have many compilers and there's no way to know which you want..\n");
   for (a = mpw_compilers ; *a ; a += strlen(a) + 1)
   {
   	char* found2 = search_mpw_path(commands, a);
	if (found2)
	{
	    printf("found: %s\n", found2);
		if (!found)
			found = found2;
		else
			free(found2);
   }   
 }
 if (cc = getenv("CC"))
 {
   FILE* f = fopen(cc, "rb");
   if (f) fclose(f);
   if (f)
   {
     compiler = 
}

void determine_linker()
{
/*
 /usr/bin/ld
 {MPW}Commands:link
 {MPW}Commands:ppclink
 \msdev\10\bin\link.exe
 \msdev\15\bin\link.exe
 \msdev\20\bin\link.exe
 \msdev\40\bin\link.exe
 \msdev\41\bin\link.exe
 \msdev\42\bin\link.exe
 \msdev\50\vb\link.exe
 \msdev\50\vc\bin\link.exe
 \msdev\60\vb98\link.exe
 \msdev\60\vc98\bin\link.exe
 \msdev\70\vc7\bin\link.exe
 \msdev\71\bin\link.exe
 \msdev\80\vc\bin\link.exe
*/
}

typedef struct c_compiler_options_t {
    boolean align_power;
	boolean allign_mac68k;
	boolean align_byte;
	boolean align_packed;
	boolean ansi_off;
	boolean ansi_on;
	boolean ansi_relaxed;
	boolean ansi_strict;
	boolean auto_import;
	int     auto_import_size;
	boolean pc_relative_strings_and_functions; /* -b */
	boolean pc_relative_strings_and_functions_overlay_equal_strings; /* -b2 */
	boolean pc_relative_strings; /* -b3 */	
	boolean single_large_segment; /* -bigseg */
	boolean char_signed;
	boolean char_unsigned;
	boolean char_unsigned_sign_extended;
	boolean mc68020; /* -mc68020 */
	boolean mc68040;
	boolean mc68881; /* -mc68881 */
	boolean model_far; /* -model far */
	boolean model_farCode; /* -model farCode */
	boolean model_farData; /* -model farData */
	boolean model_near; /* -model near */
	boolean model_nearCode; /* -model nearCode */
	boolean model_nearData; /* -model nearData */
	boolean cfmseg;
	boolean cfmflat;
	boolean nomapcr;
	boolean nomfmem;
	boolean opt_all;
	boolean opt_full;
	boolean opt_all;
	boolean opt_none;
	boolean opt_space;
	boolean opt_time;
	boolean opt_speed;
	boolean one_frag;
	boolean print_progress; /* -p */
	boolean paslinkage;
	boolean proto_strict;
	boolean proto_auto;

    char** includes;
	size_t number_of_includes;
	char** defines;
	size_t number_of_defines;
	boolean symbols;
	boolean profile;
	char*   processor; /* x86, ia64, amd64, 68000, 68020, powerpc, ia32, mips, alpha, etc. */
	unsigned warning_level; /* 1, 2, 3, 4 */
	boolean warnings_are_errors;
	char*   default_calling_convention; /* pascal, __cdecl, __fastcall, __stdcall */
	char*   model; /* far, near, huge, etc. */
} c_compiler_options_t;

void compile_c(c_compiler_options_t* options)
{
/*
gcc: cc -c -o foo.obj foo.c 
MPW C: 
*/
}

void preprocess()
{
}

void compiler_string_to_object_file()
{
}

void determine_target()
{
}

void print_string(const char *s) { printf("%s", s); }
void print_format(const char *s, ... ) { va_list args; va_start(args, s); vprintf(s, args); va_end(args);}
void string_format(char *buffer, size_t n, const char* format, ... )
{
	va_list args;
	va_start(args, format);
	buffer[n - 1] = 0;
	vsprintf(buffer, format, args);
	if (buffer[n - 1] != 0)
	{
		abort();
	}
	va_end(args);
}

int
caseinsensitive_strcmp(const char *s, const char *t)
{
	if (strcmp(s, t) == 0)
		return 0;
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
	const void* v1,
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
	size_t col = 0;
	char *argv1 = 0;
	int option = 0;
	int length = 0;
	int longest = 0;
	int line_length = 0;
	char s[100];
	const char *t = 0;
	
	print_format(
"/*\n"
"This file was machine generated by make_configure version " __DATE__ " " __TIME__ "\n"
"\n"
"argc=%d, argv[0]=%s, argv[1]=%s\n"
"*/\n"
, argc, argv[0] ? argv[0] : "", (argv1 = (argv[1] ? argv[1] : "")));
	
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

		print_string("char* types[] = {");
		for (i = 0 ; i != j ; ++i)
			print_format("%s\"%s\"", (i != 0 ? "," : ""), types[i]);
		print_string("};\n");

		print_string("unsigned long type_sizes[] = {");
		for (i = 0 ; i != j ; ++i)
			print_format("%ssizeof(%s)", (i != 0 ? "," : ""), types[i]);
		print_string("};\n");

		j = sizeof(defines)/sizeof(defines[0]);
		print_string("char* defines[] = {\n");
		for (i = 0 ; i != j ; ++i)
		{
			print_format("#if defined(%s)\n", defines[i]);
			print_format("\"%s \",\n", defines[i]);
			print_string("#endif\n");
		}
		print_string("0};\n");
		
		j = sizeof(envvar_names)/sizeof(envvar_names[0]);

		print_string("char* envvar_names[] = {");
		col = 20;
		for (i = 0 ; i != j ; ++i)
		{
			char s[3] = ",";
			if (i == (j - 1))
			{
			  s[0] = 0;
			}
			else if (col > 60)
			{
			  s[1] = '\n';
			  s[2] = 0;
			  col = 0;
			}
			print_format("\"%s\"%s", envvar_names[i], s);
			col += strlen(envvar_names[i]);
		}
		print_string("};\nunion { struct { char* ");
		col = 20;
		for (i = 0 ; i != j ; ++i)
		{
			char s[4] = ",";
			if (i == (j - 1))
			{
			  s[0] = 0;
			}
			else if (col > 60)
			{
			  s[1] = '\n';
			  s[2] = 0;
			  col = 0;
			}
			print_format("%s%s", envvar_names[i], s);
			col += strlen(envvar_names[i]);
		}
		print_format(";} named;\nPCSTR array[%lu];\n} envvar_values;\n", (unsigned long)j);

		while ((t = strings[k++]) != 0)
			print_string(t);
		
		break;
	}
	return 0;
}
