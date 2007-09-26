#include <stdio.h>#include <stdlib.h>#include <errno.h>#include <string.h>typedef unsigned char byte_t;const char * argv0 = "binarycompare";char * jk_strdup(const char * s){	char * t = 0;	size_t len = 0;		len = 1 + strlen(s);	t = (char*)malloc(len);	if (t != 0)	{		memcpy(t, s, len);	}	return t;}#define jk_abs(x) (((x) >= 0) ? (x) : (x))typedef struct jk_directory_entry_t {	char			name[260];	unsigned		name_length;/*	unsigned long	size;	bool_t 			is_directory;*/} jk_directory_entry_t;typedef struct jk_open_directory_t {	const char * name;#if defined(JK_MACINTOSH)#elif defined(JK_WINDOWS)	HANDLE jkwin_findhandle;#elif defined(JK_UNIX)	DIR * jkunix_dir;#endif	jk_directory_entry_t directory_entry;} jk_open_directory_t;typedef struct jk_open_file_or_directory_t  {	const char *  		  	name;	const char *			openmode;	unsigned long 		  	size;	FILE *                	file;	jk_open_directory_t * 	directory;} jk_open_file_and_get_information_t;long jk_errno(){	return -jk_abs(errno);}#if defined(JK_WINDOWS)void jkwin_closehandle(HANDLE * h){	HANDLE g;		g = *h;	*h = 0;		if (g != 0 && g != INVALID_HANDLE_VALUE)		CloseHandle(g);}long jkwin_lastwinerror(){	long i;		i = GetLastError();	if (i == 0)		i = ERROR_INTERNAL_ERROR;	return -jk_abs(i);}#endiflong jk_open_directory(jk_open_directory_t ** dir, const char * name){	long result = -1;	size_t namelen = 0;#if defined(JK_WINDOWS)	char * jkwin_name_slash_star = 0;	WIN32_FIND_DATA jkwin_find_data;#elif defined(JK_MACINTOSH)#elif defined(JK_UNIX)#endif	jk_open_directory_t local_dir = { name };	jk_open_directory_t  * local_dirp = 0;	*dir = 0;	local_dirp = (jk_open_directory_t*)malloc(sizeof(*localdirp));	memset(local_dirp, 0, sizeof(*local_dirp));	namelen = strlen(local_dir.name);#if defined(JK_WINDOWS)	win_name_slash_star = (char*)malloc(len + 3);	memcpy(win_name_slash_star, local_dir.name, len + 1);	jk_ensure_trailing_char_from_set(win_name_slash_star, "\\/");	strcat(win_name_slash_star, "*");	local_dir.jkwin_findhandle = FindFirstFileA(win_name_slash_star, &jkwin_find_data);	if (local_dir.jkwin_findhandle == INVALID_HANDLE_VALUE)	{		result = jkwin_lastwinerror();		goto Exit:	}#endifExit:	free(jkwin_name_slash_star);	if (result >= 0)	{		*dir = local_dir;	}	else	{#if defined(JK_WINDOWS)		jkwin_closehandle(&local_dir.jkwin_findhandle);#endif	}	return result;}long jk_open_file_or_directory(	jk_open_file_or_directory_t * file	){	int fseek_error = 0;	long ftell_result = 0;	open_file_and_get_information_t local_file = { file->name, file->openmode };		*file = local_file;	local_file.stdio_file = fopen(local_file.name, local_file.openmode);	if (local_file.stdio_file != 0)	{		fseek_error = fseek(local_file.stdio_file, 0, SEEK_END);		if (fseek_error != 0)		{			ftell_result = ftell(local_file.stdio_file);			if (ftell_result != -1)			{				local_file.file_size = (unsigned long)ftell_result;			}			fseek_error = fseek(local_file.stdio_file, 0, SEEK_SET);			if (fseek_error != 0)			{				fclose(local_file.stdio_file);				return jk_errno();			}		}	}	else	{		/* try opening it as a directory */	}	*file = local_file;	return 0;}int main(int argc, char ** argv){	FILE * f1 = 0;	FILE * f2 = 0;	const size_t buffersize = 65536;	byte_t * buffer1 = 0;	byte_t * buffer2 = 0;	size_t bytesread1 = 0;	size_t bytesread2 = 0;	size_t offset = 0;	size_t i = 0;	int err = 0;		if (argc != 3)	{		goto Exit;	}	f1 = fopen(argv[1], "rb");	if (f1 == 0)	{		printf("%s: error opening %s: %s\n", argv0, argv[1], strerror(err = errno));		goto Exit;	}	f2 = fopen(argv[2], "rb");	if (f2 == 0)	{		printf("%s: error opening %s: %s\n", argv0, argv[2], strerror(err = errno));		goto Exit;	}		buffer1 = (byte_t*)malloc(buffersize);	buffer2 = (byte_t*)malloc(buffersize);		if (buffer1 == 0 || buffer2 == 0)	{		printf("%s: out of memory\n", argv0);		goto Exit;	}	while (1)	{		bytesread1 = fread(buffer1, 1, buffersize, f1);		bytesread2 = fread(buffer2, 1, buffersize, f2);		if (bytesread1 != bytesread2)		{			printf("%s: bytesread1:%lu, bytesread2: %lu, files %s %s differ\n",				argv0,				(unsigned long)bytesread1,				(unsigned long)bytesread2,				argv[1],				argv[2]);			break;		}		if (memcmp(buffer1, buffer2, bytesread1) != 0)		{			for ( i = 0 ; i != bytesread1 ; ++i)			{				if (buffer1[i] != buffer2[i])				{					break;				}			}			printf("%s: files %s and %s differ at offset %lu\n",				argv0,				argv[1],				argv[2],				(unsigned long)(i + offset)				);			break;		}		if (bytesread1 != buffersize)		{			printf("%s: files %s and %s are the same\n", argv0, argv[1], argv[2]);			break;		}		offset += bytesread1;	}Exit:	if (f1) fclose(f1);	if (f2) fclose(f2);	if (buffer1) free(buffer1);	if (buffer2) free(buffer2);	return 0;}