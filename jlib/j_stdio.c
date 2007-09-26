#define _CRT_SECURE_NO_DEPRECATE
#include "j.h"
#include <stdio.h>
#include <stdarg.h>

unsigned
jk_assert_failed(
    const char * x,
    const char * file,
    long line
    )
{
    fprintf(stderr, "%s(%ld): assertion failed: %s\n", file, line, x);
    return 0;
}

void jk_sprintf(char* buffer, const char* format, ...)
{
	va_list args;
	
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
}

void jk_printf(const char* format, ...)
{
	va_list args;
	
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

void jk_debug_printf(const char* format, ...)
{
	va_list args;
	
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

long
jk_stdio_fopen(
	const char * filepath,
	const char * access,
	void **      file
	)
{
	*file = 0;
	if ((*file = fopen(filepath, access)) != NULL)
		return 0;
	return jk_errno();
}

long
jk_stdio_close(
	void ** file
	)
{
	void * local_file = *file;
	if (local_file != 0)
	{
		*file = 0;
		fclose((FILE*)local_file);
	}
	return 0;
}

long
jk_get_stdio_filesize(
	void * file,
	jk_longlong_t * out_filesize
	)
{
	long filesize;

	jk_longlong_assign_zero(out_filesize);
	filesize = fseek((FILE*)file, 0, SEEK_CUR);
	if (filesize == -1)
	{
		return jk_errno();
	}
	jk_longlong_from_long(out_filesize, filesize);
	return 0;
}

long
jk_file_close(
    jk_file_t * file
    )
{
	jk_function(jk_file_close);
	jk_profile_count_function_call();

    if (file->stdio_file != 0)
    {
    	fclose((FILE*)file->stdio_file);
    	file->stdio_file = 0;
    }
    return 0;
}

long
jkp_file_read_direct(
    jk_file_t * file,
    void * buffer,
    size_t bytes_to_read,
    size_t * bytes_read /* optional */
    )
{
    jk_function(jkp_file_read_direct);
	size_t n;
	
	jk_profile_count_function_call();

    n = fread(buffer, 1, bytes_to_read, (FILE*)file->stdio_file);
    if (bytes_read != 0)
    {
    	*bytes_read = n;
    }
#if 0
	jk_printf(jk_format_file_line "%s bytes_to_read /* %u */ /* %u */\n", sourcefile, (unsigned)__LINE__, function.chars, (unsigned)bytes_to_read, (unsigned)n);
#endif
    return 0;
}
