#include <stdio.h>
#include "j29.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <limits.h>

JK_EXTERN_C_BEGIN

static const char sourcefile[] = "j30.c";

#define jk_out_of_memory_error (~1)
#define jk_error_uninitialized (~2)
#define jk_error_unreachable   (~3)
typedef void (*jk_pfn_vv_t)(void);
#define  jk_pointer_to_function_uninitialized ((jk_pfn_vv_t*)~4)
#define jk_sizet_uninitialized   (~5)
#define jk_pointer_uninitialized ((void*)~6)
#define jk_integer_overflow_error (~7)

long
jk_carry_to_error(
	unsigned carry
	)
{
	return (carry ? jk_integer_overflow_error : 0);
}

#define jk_debug_strings 1

#if jk_debug_strings
#define jk_debug_string(x) x
#else
#define jk_debug_string(x) ""
#endif

#if jk_debug_strings
#define jk_function(x) static const char function[] = x
#else
#define jk_function(x) static const char function[] = ""
#endif

#define jk_assert(x) \
 ((void)((x) || jk_assert_failed(jk_debug_string(#x), sourcefile, __LINE__)))

#if jk_debug_strings
#define jk_make_profile_function_name_string(x) jk_make_seven_bit_constant_string(x)
#else
#define jk_make_profile_function_name_string(x) jk_make_seven_bit_constant_string("")
#endif

#if jk_debug_strings
#define jk_field_name(x) x
#else
#define jk_field_name(x) ""
#endif

#define jk_debug_printf printf
#define jk_printf printf

#define jk_cast(t) (t)

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

long
jk_undone(
    void
    )
#if 0
;
#else
{
    return -1;
}
#endif

void jk_unused(const void * a) { a = &a; }

void jk_unused4(const void * a1, const void * a2, const void * a3, const void * a4)
{
	a1 = &a1; a2 = &a2; a3 = &a3; a4 = &a4;
}

JK_ORCAC_SEGMENT

#if defined(_MSC_VER) /* Visual C++ */

#define jk_format_file_line "%s(%u):"

#else /* MPW */

#define jk_format_file_line "file %s; line %u #"

#endif

struct jk_profile_count_function_calls_map_entry_t
{
    jk_seven_bit_constant_string_t name;
    size_t index;
};

struct jk_profile_count_function_calls_t
{
	size_t first;
	size_t jk_compute_packed_size;
	size_t jk_compute_packed_or_unpacked_size;
	size_t jk_compute_unpacked_size;
	size_t jk_file_close;
	size_t jk_file_open_for_read;
	size_t jk_file_read_ahead;
	size_t jk_file_read_and_unpack;
	size_t jk_file_read_copy;
	size_t jk_file_read_get_buffer;
    size_t jkp_file_read_direct;
    size_t jk_malloc;
    size_t jk_free;
    size_t jk_default_memory_allocator_allocate;
    size_t jk_default_memory_allocator_free;
    size_t jk_reverse_memory_range_exclusive;
    size_t jk_reverse_memory_byte_count;
    size_t jk_reverse_memory_range_inclusive;
    size_t jk_move_memory;
    size_t jk_copy_memory;
    size_t jk_copy_memory_unsigned_char;
    size_t jk_copy_memory_reverse;
    size_t jk_zero_memory;
    size_t jk_unpack;
};

jk_seven_bit_constant_string_t jk_profile_name_functions[sizeof(jk_profile_count_function_calls_t)/sizeof(size_t)] =
{
	jk_make_profile_function_name_string(""),
	jk_make_profile_function_name_string("jk_compute_packed_size"),
	jk_make_profile_function_name_string("jk_compute_packed_or_unpacked_size"),
	jk_make_profile_function_name_string("jk_compute_unpacked_size"),
	jk_make_profile_function_name_string("jk_file_close"),
	jk_make_profile_function_name_string("jk_file_open_for_read"),
	jk_make_profile_function_name_string("jk_file_read_ahead"),
	jk_make_profile_function_name_string("jk_file_read_and_unpack"),
	jk_make_profile_function_name_string("jk_file_read_copy"),
	jk_make_profile_function_name_string("jk_file_read_get_buffer"),
	jk_make_profile_function_name_string("jkp_file_read_direct"),
	jk_make_profile_function_name_string("jk_malloc"),
	jk_make_profile_function_name_string("jk_free"),
	jk_make_profile_function_name_string("jk_default_memory_allocator_allocate"),
	jk_make_profile_function_name_string("jk_default_memory_allocator_free"),
	jk_make_profile_function_name_string("jk_reverse_memory_range_exclusive"),
	jk_make_profile_function_name_string("jk_reverse_memory_byte_count"),
	jk_make_profile_function_name_string("jk_reverse_memory_range_inclusive"),
	jk_make_profile_function_name_string("jk_move_memory"),
	jk_make_profile_function_name_string("jk_copy_memory"),
	jk_make_profile_function_name_string("jk_copy_memory_unsigned_char"),
	jk_make_profile_function_name_string("jk_copy_memory_reverse"),
	jk_make_profile_function_name_string("jk_zero_memory"),
	jk_make_profile_function_name_string("jk_unpack")
};

jk_profile_count_function_calls_t jk_profile_count_function_calls;

/* #define jk_profile_count_function_call(function_name) \
    globals->profile_count_function_calls->function_name += 1
*/
#define jk_profile_count_function_call(function_name) \
    jk_profile_count_function_calls.function_name += 1

void
jk_profile_dump_function_call_counts(
    const jk_globals_t * globals
    )
{
	const size_t * count = &globals->profile_count_function_calls->first;
	const jk_seven_bit_constant_string_t * names = globals->profile_name_functions;
	const size_t n = globals->profile_number_of_functions;
	
    size_t longest_name_length = 0;
    size_t i = 0;
	
    for ( i = 0 ; i != n ; ++i)
    {
        size_t name_length = names[i].length;
        if (name_length > longest_name_length)
        {
            longest_name_length = name_length;
        }
    }

    for ( i = 0 ; i != n ; ++i)
    {
		if (i != 0)
		    jk_printf("%-*s %lu\n", (int)longest_name_length, names[i].chars, count[i]);
    }
}

long
jk_malloc(
	void ** pp,
	size_t n
	)
{
	void * p;

	jk_profile_count_function_call(jk_malloc);
	
	p = malloc(n);
	*pp = p;
	if (p == 0)
	{
		return -__LINE__;
	}
	return 0;
}

void
jk_free(
	void ** pp
	)
{
	void * p = *pp;
	
	jk_profile_count_function_call(jk_free);
	
	*pp = NULL;
	if (p != NULL)
	{
		free(p);
	}
}

long
jk_default_memory_allocator_allocate(
    jk_memory_allocator_t * state,
    size_t number_of_bytes,
    void ** pp
    )
{
	void * p;

	jk_profile_count_function_call(jk_default_memory_allocator_allocate);
	
	jk_unused(state);

    *pp = 0;
    p = malloc(number_of_bytes);
    *pp = p;
    return ((p != NULL) ? 0 : jk_out_of_memory_error);
}

void
jk_default_memory_allocator_free(
    jk_memory_allocator_t * state,
    void ** pp
    )
{
    void * p;

	jk_profile_count_function_call(jk_default_memory_allocator_free);

	jk_unused(&state);
    
    p = *pp;
    *pp = 0;
    free(p);
}

const
jk_memory_allocator_functions_t
jk_default_memory_allocator_functions =
{
    jk_default_memory_allocator_allocate,
    jk_default_memory_allocator_free
};

jk_memory_allocator_t
jk_default_memory_allocator = { &jk_default_memory_allocator_functions };

jk_fields_t jk_fields;

void
jk_init_fields(void)
{
	jk_fields_t fields =
	{
		/* java_classfile */
		{
			{
				jk_field_name("magic"),
				jk_field_offset(jk_types_t, t_void),
				jk_field_size(jk_java_classfile_t, magic),
				jk_field_size(jk_java_packed_classfile1_t, magic),
				jk_field_offset(jk_java_classfile_t, magic),
				jk_field_offset(jk_java_packed_classfile1_t, magic),
			},
			{
				jk_field_name("minor_version"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, minor_version),
				jk_field_size(jk_java_packed_classfile1_t, minor_version),
				jk_field_offset(jk_java_classfile_t, minor_version),
				jk_field_offset(jk_java_packed_classfile1_t, minor_version),
			},
			{
				jk_field_name("major_version"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, major_version),
				jk_field_size(jk_java_packed_classfile1_t, major_version),
				jk_field_offset(jk_java_classfile_t, major_version),
				jk_field_offset(jk_java_packed_classfile1_t, major_version),
			},
			{
				jk_field_name("constant_pool_count"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, constant_pool_count),
				jk_field_size(jk_java_packed_classfile1_t, constant_pool_count),
				jk_field_offset(jk_java_classfile_t, constant_pool_count),
				jk_field_offset(jk_java_packed_classfile1_t, constant_pool_count),
			},
			{
				jk_field_name("constant_pool"),
				jk_field_offset(jk_types_t, t_void),
				0,
				0,
				0,
				0
			},
			{
				jk_field_name("access_flags"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, access_flags),
				jk_field_size(jk_java_packed_classfile2_t, access_flags),
				jk_field_offset(jk_java_classfile_t, access_flags),
				jk_field_offset(jk_java_packed_classfile2_t, access_flags),
			},
			{
				jk_field_name("this_class"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, this_class),
				jk_field_size(jk_java_packed_classfile2_t, this_class),
				jk_field_offset(jk_java_classfile_t, this_class),
				jk_field_offset(jk_java_packed_classfile2_t, this_class),
			},
			{
				jk_field_name("super_class"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, super_class),
				jk_field_size(jk_java_packed_classfile2_t, super_class),
				jk_field_offset(jk_java_classfile_t, super_class),
				jk_field_offset(jk_java_packed_classfile2_t, super_class),
			},
			{
				jk_field_name("interfaces_count"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, interfaces_count),
				jk_field_size(jk_java_packed_classfile2_t, interfaces_count),
				jk_field_offset(jk_java_classfile_t, interfaces_count),
				jk_field_offset(jk_java_packed_classfile2_t, interfaces_count),
			},
			{
				jk_field_name("interfaces"),
				jk_field_offset(jk_types_t, t_void),
				0,
				0,
				0,
				0,
			},
			{
				jk_field_name("fields_count"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, fields_count),
				jk_field_size(jk_java_packed_classfile3_t, fields_count),
				jk_field_offset(jk_java_classfile_t, fields_count),
				0
			},
			{
				jk_field_name("fields"),
				jk_field_offset(jk_types_t, t_void),
				0,
				0,
				0,
				0
			},
			{
				jk_field_name("methods_count"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, methods_count),
				jk_field_size(jk_java_packed_classfile3_t, methods_count),
				jk_field_offset(jk_java_classfile_t, methods_count),
				0
			},
			{
				jk_field_name("methods"),
				jk_field_offset(jk_types_t, t_void),
				0,
				0,
				0,
				0
			},
			{
				jk_field_name("attributes_count"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, attributes_count),
				jk_field_size(jk_java_packed_classfile3_t, attributes_count),
				jk_field_offset(jk_java_classfile_t, attributes_count),
				0
			},
			{
				jk_field_name("attributes"),
				jk_field_offset(jk_types_t, t_void),
				0,
				0,
				0,
				0
			}
		}
	};
	jk_fields = fields;
}

jk_struct_t jk_java_classfile_type_info;
jk_struct_t jk_java_classfile1_type_info;
jk_struct_t jk_java_classfile2_type_info;

void
jk_init_classfile_type_info(void)
{
	jk_struct_t classfile_type_info =
	{
		jk_endian_big,
		jk_field_offset(jk_fields_t, java_classfile.magic),
		jk_field_offset(jk_fields_t, java_classfile.attributes),
	};
	jk_struct_t classfile1_type_info =
	{
		jk_endian_big,
		jk_field_offset(jk_fields_t, java_classfile.magic),
		jk_field_offset(jk_fields_t, java_classfile.constant_pool_count),
	};
	jk_struct_t classfile2_type_info =
	{
		jk_endian_big,
		jk_field_offset(jk_fields_t, java_classfile.access_flags),
		jk_field_offset(jk_fields_t, java_classfile.interfaces_count),
	};

	jk_java_classfile_type_info = classfile_type_info;
	jk_java_classfile1_type_info = classfile1_type_info;
	jk_java_classfile2_type_info = classfile2_type_info;
}

void
jk_reverse_memory_range_exclusive(
    void * void_start,
    void * void_end
    )
{
    unsigned char * start = (unsigned char *)void_start;
    unsigned char * end = (unsigned char *)void_end;

	jk_profile_count_function_call(jk_reverse_memory_range_exclusive);

    while (start < end)
    {
        unsigned char t = *start;
        --end;
        *start = *end;
        *end = t;
        ++start;
    }
}

JK_ORCAC_SEGMENT

void
jk_reverse_memory_byte_count(
    void * p_void,
    size_t count
    )
{
	void * void_end = count + (unsigned char*)p_void;
	
	jk_profile_count_function_call(jk_reverse_memory_byte_count);

    jk_reverse_memory_range_exclusive(p_void, void_end);
}

void
jk_reverse_memory_range_inclusive(
    void * void_start,
    void * void_end
    )
{
	void_end = 1 + (unsigned char*)void_end;
	
	jk_profile_count_function_call(jk_reverse_memory_range_inclusive);

	jk_reverse_memory_range_exclusive(void_start, void_end);
}

void
jk_move_memory(
    void * to,
    const void * from,
    size_t count
    )
{
	jk_profile_count_function_call(jk_move_memory);
	
    memmove(to, from, count);
}

void
jk_copy_memory(
    void * to,
    const void * from,
    size_t count
    )
{
	jk_profile_count_function_call(jk_copy_memory);

    memcpy(to, from, count);
}

void
jk_copy_memory_unsigned_char(
    unsigned char * to,
    const unsigned char * from,
    size_t count
    )
{
	jk_profile_count_function_call(jk_copy_memory_unsigned_char);

    memcpy(to, from, count);
}

void
jk_copy_memory_reverse(
    unsigned char * to,
    const unsigned char * from,
    size_t count
    )
{
	jk_profile_count_function_call(jk_copy_memory_reverse);

    while (count != 0)
    {
    	*to++ = from[--count];
    }
}

void
jk_zero_memory(
    void * p,
    size_t n
    )
{
	jk_profile_count_function_call(jk_zero_memory);

    memset(p, 0, n);
}

long
jk_unpack(
    const jk_globals_t * globals,
    unsigned endian,
    const void * vpacked_buffer,
    void * vunpacked_buffer,
    jk_struct_t * typeinfo
    )
{
    long err = -1;
    const unsigned char * packed_buffer = (const unsigned char *)vpacked_buffer;
    unsigned char * unpacked_buffer = (unsigned char*)vunpacked_buffer;
    union {
    	unsigned long i;
    	unsigned char c[sizeof(unsigned long)];
    } uhost_endian = { 1 };
    unsigned host_endian = uhost_endian.c[0];
    unsigned endian_factor = (host_endian << 1) | endian;
    unsigned sign_byte_index = 0;
    void (*copy)(unsigned char *, const unsigned char *, size_t) = 0;

    const unsigned offset_to_first_field = typeinfo->offset_to_first_field;
    const unsigned offset_to_last_field = typeinfo->offset_to_last_field;
    const unsigned char * const fields_base = (const unsigned char *)globals->fields;
    const unsigned char * const types_base = (const unsigned char *)globals->types;
    unsigned offset = 0;
    jk_field_t field;
    const jk_field_t * field_pointer = 0;
    unsigned char const * packed_field = 0;
    unsigned char * unpacked_field = 0;

	jk_profile_count_function_call(jk_unpack);

    switch (endian_factor)
    {
    	case 0:
    		copy = jk_copy_memory_unsigned_char;
    		sign_byte_index = 1;
    		break;
    	case 1:
    		copy = jk_copy_memory_reverse;
    		sign_byte_index = 0;
    		break;
    	case 2:
    		copy = jk_copy_memory_reverse;
    		sign_byte_index = 1;
    		break;
    	case 3:
    		copy = jk_copy_memory_unsigned_char;
    		sign_byte_index = 0;
    		break;
    }

    for ( offset = offset_to_first_field ; offset <= offset_to_last_field ; offset += sizeof(field) )
    {
    	size_t number_of_bytes_to_copy = 0;
    	size_t number_of_packed_bytes_to_skip = 0;
    	size_t number_of_unpacked_bytes_to_skip = 0;
  
        field_pointer = (const jk_field_t*)(fields_base + offset);
        field.packed_offset = field_pointer->packed_offset;
        field.packed_size = field_pointer->packed_size;
        field.unpacked_offset = field_pointer->unpacked_offset;
        field.unpacked_size = field_pointer->unpacked_size;        
        
    	packed_field = packed_buffer + field.packed_offset;
    	unpacked_field = unpacked_buffer + field.unpacked_offset;

    	if (field.unpacked_size == field.packed_size)
    	{
    		number_of_bytes_to_copy = field.packed_size;
    		number_of_packed_bytes_to_skip = 0;
    		number_of_unpacked_bytes_to_skip = 0;
    	}
    	else if (field.unpacked_size > field.packed_size)
    	{
            const jk_type_t * type_pointer = (const jk_type_t *)(types_base + field_pointer->offset_to_type);
            const unsigned is_signed = type_pointer->is_signed;

    		memset(
    			unpacked_field,
    			(is_signed && (packed_field[sign_byte_index ? (field.packed_size - 1) : 0]) & 0x80) ? -1 : 0,
    			field.unpacked_size
    			);
    		number_of_bytes_to_copy = field.packed_size;
    		number_of_packed_bytes_to_skip = 0;
    		if (host_endian == jk_endian_big)
    			number_of_unpacked_bytes_to_skip = (field.unpacked_size - number_of_bytes_to_copy);
    		else
    			number_of_unpacked_bytes_to_skip = 0;
    	}
    	else /* field.unpacked_size < field.packed_size */
    	{
    		number_of_bytes_to_copy = field.unpacked_size;
    		number_of_unpacked_bytes_to_skip = 0;
    		if (endian == jk_endian_big)
    			number_of_packed_bytes_to_skip = (field.packed_size - number_of_bytes_to_copy);
    		else
    			number_of_packed_bytes_to_skip = 0;
    	}
    	(*copy)(
    		unpacked_field + number_of_unpacked_bytes_to_skip,
    		packed_field + number_of_packed_bytes_to_skip,
    		number_of_bytes_to_copy
    		);
    }
    err = 0;
    return err;
}

long
jk_compute_packed_size(
    const jk_globals_t * globals,
    jk_struct_t * p
    )
{
	jk_profile_count_function_call(jk_compute_packed_size);
	
    return jk_compute_packed_or_unpacked_size(globals, p, 1);
}

JK_ORCAC_SEGMENT

long
jk_compute_unpacked_size(
    const jk_globals_t * globals,
    jk_struct_t * p
    )
{
	jk_profile_count_function_call(jk_compute_unpacked_size);

    return jk_compute_packed_or_unpacked_size(globals, p, 0);
}

long
jk_compute_packed_or_unpacked_size(
    const jk_globals_t * globals,
    jk_struct_t * p,
    unsigned packed_or_unpacked
    )
{
    long err = -1;
	size_t offset_to_first_field;
	size_t offset_to_last_field;
	const unsigned char * fields_base;
	size_t offset;
	size_t maximum = 0;
	size_t i;
	const jk_field_t * field;
	
	jk_profile_count_function_call(jk_compute_packed_or_unpacked_size);

    if ((packed_or_unpacked ? p->packed_size : p->unpacked_size) == 0)
	{
        offset_to_first_field = p->offset_to_first_field;
        offset_to_last_field = p->offset_to_last_field;
        fields_base = (const unsigned char *)globals->fields;
    	for ( offset = offset_to_first_field ; offset <= offset_to_last_field ; offset += sizeof(jk_field_t) )
    	{
    	    field = (const jk_field_t*)(fields_base + offset);
			if (packed_or_unpacked)
			{
    			i = field->packed_size + field->packed_offset;
			}
			else
			{
    			i = field->unpacked_size + field->unpacked_offset;
			}
    		if (i > maximum)
    		{
    			maximum = i;
    		}
    	}
		if (packed_or_unpacked)
		{
			p->packed_size = maximum;
		}
		else
		{
			p->unpacked_size = maximum;
		}
	}
	err = 0;
    return err;
}

unsigned
jk_align_integer(
    unsigned n
    )
{
    unsigned m = (2 * sizeof(void*)) - 1;
    
    return (n + m) & ~m;
}

long
jk_file_open_for_read(
    const jk_globals_t * globals,
    jk_file_t * file,
    const char * file_path
    )
{
    jk_function("jk_file_open_for_read");
    long err = -1;
    const char * openmode = "rb";

	jk_profile_count_function_call(jk_file_open_for_read);
	jk_unused(globals);

    file->stdio_file = fopen(file_path, openmode);	
    if (file->stdio_file == 0) goto exit;
    file->openmode = openmode;
    file->file_path = file_path;
    err = 0;
exit:
	if (err < 0)
		jk_printf("%s exiting with %ld\n", function, err);
    return err;
}

long
jk_file_close(
    const jk_globals_t * globals,
    jk_file_t * file
    )
{
	jk_profile_count_function_call(jk_file_close);
	jk_unused(globals);

    if (file->stdio_file != 0)
    {
    	fclose((FILE*)file->stdio_file);
    	file->stdio_file = 0;
    }
    return 0;
}

long
jkp_file_read_direct(
    const jk_globals_t * globals,
    jk_file_t * file,
    void * buffer,
    size_t bytes_to_read,
    size_t * bytes_read /* optional */
    )
{
    jk_function("jkp_file_read_direct");
	size_t n;
	
	jk_profile_count_function_call(jkp_file_read_direct);
	jk_unused(function);
	jk_unused(globals);

    n = fread(buffer, 1, bytes_to_read, (FILE*)file->stdio_file);
    if (bytes_read != 0)
    {
    	*bytes_read = n;
    }
	#if 0
	jk_printf(jk_format_file_line "%s bytes_to_read /* %u */ /* %u */\n", sourcefile, (unsigned)__LINE__, function, bytes_to_read, (unsigned)n);
	#endif
    return 0;
}

long
jk_file_read_and_unpack(
    const jk_globals_t * globals,
    jk_file_t * file,
    jk_struct_t * spec,
    size_t packed_buffer_size,
    void * unpacked_buffer,
    size_t unpacked_buffer_size
    )
{
	jk_function("jk_file_read_and_unpack");
    long err = -1;
    size_t bytes_read = 0;
    void * packed_buffer = 0;

	jk_profile_count_function_call(jk_file_read_and_unpack);

    err = jk_compute_packed_size(globals, spec);
    if (err < 0) goto exit;
    err = jk_compute_unpacked_size(globals, spec);
    if (err < 0) goto exit;
    if (spec->packed_size > packed_buffer_size)
    	err = -__LINE__;
    else if (spec->unpacked_size > unpacked_buffer_size)
    	err = -__LINE__;
    if (err < 0) goto exit;
    err = jk_file_read_get_buffer(globals, file, &packed_buffer, spec->packed_size, &bytes_read);
    if (err < 0) goto exit;
    if (bytes_read != spec->packed_size)
	{
	#if 0
		jk_printf("bytes_read /* %u */ != spec->packed_size /* %u */\n",
			bytes_read,
			(unsigned)spec->packed_size);
	#endif
    	err = -__LINE__;
	}
    if (err < 0) goto exit;
    err = jk_unpack(globals, spec->endian, packed_buffer, unpacked_buffer, spec);
    if (err < 0) goto exit;	
    
    err= 0;
exit:
	if (err < 0)
		jk_printf(jk_format_file_line "%s exiting with %ld\n", sourcefile, (unsigned)__LINE__, function, err);
    return err;
}

JK_ORCAC_SEGMENT

void jk_limited_truncating_string_copy(char * dest, const char * src, size_t n)
{
    size_t m;
    
    if (n == 0)
        return;
    m = 1 + strlen(src);
    if (src[0] == 1)
    {
        dest[0] = 0;
        return;
    }
    if (m > n)
        m = n;

    memcpy(dest, src, m - 1);
    dest[m - 1] = 0;
}

#if defined(__ORCAC__)
#define JK_INTEGER_DUMP_LENGTH(t) (sizeof(t)*CHAR_BIT*2+7)
#else
#define JK_INTEGER_DUMP_LENGTH(t) (sizeof(t)*CHAR_BIT*2+sizeof(" -0x()"))
#endif

size_t jk_get_dump_length_int(int data)
{
	jk_unused(&data);
    return JK_INTEGER_DUMP_LENGTH(int);
}

size_t jk_get_dump_length_unsigned_int(unsigned int data)
{
	jk_unused(&data);
    return JK_INTEGER_DUMP_LENGTH(unsigned);
}

size_t jk_get_dump_length_long(long data)
{
	jk_unused(&data);
    return JK_INTEGER_DUMP_LENGTH(long);
}

size_t jk_get_dump_length_unsigned_long(unsigned long data)
{
	jk_unused(&data);
    return JK_INTEGER_DUMP_LENGTH(unsigned long);
}

long jk_type_get_dump_length_int(const jk_type_t * t, const void * data, size_t * length)
{
	jk_unused(&t);
	*length = jk_get_dump_length_int(*(const int*)data);
	return 0;
}

long jk_type_get_dump_length_unsigned_int(const jk_type_t * t, const void * data, size_t * length)
{
	jk_unused(&t);
	*length = jk_get_dump_length_unsigned_int(*(const unsigned int*)data);
	return 0;
}

long jk_type_get_dump_length_long(const jk_type_t * t, const void * data, size_t * length)
{
	jk_unused(&t);
	*length = jk_get_dump_length_int(*(const long*)data);
	return 0;
}

long jk_type_get_dump_length_unsigned_long(const jk_type_t * t, const void * data, size_t * length)
{
	jk_unused(&t);
	*length = jk_get_dump_length_unsigned_long(*(const unsigned long*)data);
	return 0;
}

void jk_dump_int(size_t buffer_size, char * buffer, int data)
{
    jk_dump_long(buffer_size, buffer, (long)data);
}

void jk_dump_unsigned_int(size_t buffer_size, char * buffer, unsigned int data)
{
    jk_dump_unsigned_long(buffer_size, buffer, (unsigned long)data);
}

void jk_dump_long(size_t buffer_size, char * buffer, long data)
{
	char big_enough_buffer[JK_INTEGER_DUMP_LENGTH(long)];
			
    if (data >= 16)
        sprintf(big_enough_buffer, "%ld (0x%lx)", data, (unsigned long)data);
    else
        sprintf(big_enough_buffer, "%ld", data);
	
	jk_limited_truncating_string_copy(buffer, big_enough_buffer, buffer_size);
}

void jk_dump_unsigned_long(size_t buffer_size, char * buffer, unsigned long data)
{
	char big_enough_buffer[JK_INTEGER_DUMP_LENGTH(unsigned long)];
	
    if (data >= 16)
        sprintf(big_enough_buffer, "%lu (0x%lx)", data, data);
    else
        sprintf(big_enough_buffer, "%lu", data);

	jk_limited_truncating_string_copy(buffer, big_enough_buffer, buffer_size);
}

long jk_type_dump_int(const jk_type_t * t, size_t buffer_size, char * buffer, const void * data)
{
	jk_unused(&t);
	jk_dump_int(buffer_size, buffer, *(const int *)data);
	return 0;
}

long jk_type_dump_unsigned_int(const jk_type_t * t, size_t buffer_size, char * buffer, const void * data)
{
	jk_unused(&t);
	jk_dump_unsigned_int(buffer_size, buffer, *(const unsigned int *)data);
	return 0;
}

long jk_type_dump_long(const jk_type_t * t, size_t buffer_size, char * buffer, const void * data)
{
	jk_unused(&t);
	jk_dump_long(buffer_size, buffer, *(const long *)data);
	return 0;
}

long jk_type_dump_unsigned_long(const jk_type_t * t, size_t buffer_size, char * buffer, const void * data)
{
	jk_unused(&t);
	jk_dump_unsigned_long(buffer_size, buffer, *(const unsigned long *)data);
	return 0;
}

void jk_type_dump_char(const jk_type_t * t, size_t buffer_size, char * buffer, void * data)
{
	jk_unused4(&t, &buffer_size, &buffer, &data);
}

long
jk_dump_struct(
    const jk_globals_t * globals,
    const char * prefix,
    const void * vbase,
    const jk_struct_t * typeinfo
    )
{
	long err = jk_error_uninitialized;
    const char * base = (const char*)vbase;
    size_t name_length = 0;
    size_t maximum_name_length = 0;
    const jk_field_t * field = 0;
	const jk_type_t * type = 0;
    const size_t offset_to_first_field = typeinfo->offset_to_first_field;
    const size_t offset_to_last_field = typeinfo->offset_to_last_field;
    const unsigned char * const fields_base = (const unsigned char *)globals->fields;
    const unsigned char * const types_base = (const unsigned char *)globals->types;
    unsigned offset = 0;
    jk_type_get_dump_length_t get_dump_length = (jk_type_get_dump_length_t)jk_pointer_to_function_uninitialized;
	jk_type_dump_t dump = (jk_type_dump_t)jk_pointer_to_function_uninitialized;
	char stack_buffer[64];
	jk_buffer_t buffer;
    	
	err = jk_buffer_init(&buffer, sizeof(stack_buffer), &stack_buffer);
	if (err < 0) goto exit;

    for ( offset = offset_to_first_field ; offset <= offset_to_last_field ; offset += sizeof(jk_field_t) )
    {
        field = (const jk_field_t*)(fields_base + offset);
    	name_length = strlen(field->name);
    	if (name_length > maximum_name_length)
    		maximum_name_length = name_length;
    }
    
    for ( offset = offset_to_first_field ; offset <= offset_to_last_field ; offset += sizeof(jk_field_t) )
    {
        field = (const jk_field_t*)(fields_base + offset);
		type = *(const jk_type_t**)(types_base + field->offset_to_type);
	    get_dump_length = type->get_dump_length;
		dump = type->dump;
		if (get_dump_length && dump)
		{
			char * p = (char *)jk_pointer_uninitialized;
        	size_t dump_length = jk_sizet_uninitialized;
			
			err = (*get_dump_length)(type, (base + field->unpacked_offset), &dump_length);
			if (err < 0) goto exit;

			err = jk_buffer_set_size(&buffer, dump_length, (void**)&p);
			if (err < 0) goto exit;
			
			err = (*dump)(type, dump_length, p, (base + field->unpacked_offset));
			if (err < 0) goto exit;

			jk_printf("%s%-*s%s\n", prefix, (int)maximum_name_length, field->name, p);
		}
    }
exit:
	jk_buffer_free(&buffer);
	return err;
}

long
jk_file_read_ahead(
    const jk_globals_t * globals,
    jk_file_t * file,
    size_t n
    )
{
	jk_unused(globals);
	jk_profile_count_function_call(jk_file_read_ahead);

    file->buffer.read_ahead += n;
    return 0;
}

long
jk_file_read_copy(
    const jk_globals_t * globals,
    jk_file_t * file,
    void * buffer,
    size_t bytes_to_read,
    size_t * bytes_read
    )
{
    void * my_buffer = 0;
    long err = 0;

	jk_profile_count_function_call(jk_file_read_copy);

    err = jk_file_read_get_buffer(globals, file, &my_buffer, bytes_to_read, bytes_read);
    if (err < 0)
        goto exit;
    jk_copy_memory(buffer, my_buffer, *bytes_read);
    err = 0;
exit:
    return err;
}

long
jk_file_read_get_buffer(
    const jk_globals_t * globals,
    jk_file_t * file,
    void ** out_buffer,
    size_t bytes_to_read,
    size_t * out_bytes_read /* optional */
    )
{
    jk_function("jk_file_read_get_buffer");
    long err = -1;
	
    char * new_buffer = 0;
    size_t new_buffer_size = 0;
    unsigned keep_all_bytes = 0;
    size_t buffer_size = 0;
    size_t bytes_to_read_plus_read_ahead = 0;
    size_t bytes_read = 0;
    size_t bytes_in_buffer = 0;
    size_t position = 0;
    char * buffer = 0;

	jk_profile_count_function_call(jk_file_read_get_buffer);

	/*
	jk_debug_printf(jk_format_file_line "\n", sourcefile, (unsigned)__LINE__);
	*/
	
    bytes_in_buffer = file->buffer.bytes_in_buffer;
    position = file->buffer.position;
    buffer = file->buffer.buffer;

    /* fast path -- there are enough bytes */
    if (bytes_to_read <= (bytes_in_buffer - position))
    {
		#if 0
		jk_debug_printf(jk_format_file_line "%u %p \n", sourcefile, (unsigned)__LINE__, (unsigned)bytes_to_read, out_bytes_read);
		#endif
        if (out_bytes_read != NULL)
        {
            *out_bytes_read = bytes_to_read;
        }
    	*out_buffer = (buffer + position);
    	file->buffer.position = (position + bytes_to_read);
    	return 0;
    }

	/*
	jk_debug_printf(jk_format_file_line "\n", sourcefile, (unsigned)__LINE__);
	*/

    buffer_size = file->buffer.buffer_size;
    keep_all_bytes = file->buffer.keep_all_bytes;
    
	#if 0
	jk_debug_printf(jk_format_file_line "read_ahead %u\n", sourcefile, (unsigned)__LINE__, (unsigned)file->buffer.read_ahead);
	#endif
    bytes_to_read_plus_read_ahead = bytes_to_read + file->buffer.read_ahead;
    file->buffer.read_ahead = 0;

    new_buffer_size = jk_max(buffer_size, bytes_to_read_plus_read_ahead);
    if (keep_all_bytes)
    {
    	new_buffer_size += buffer_size;
    }

    #if 0
	jk_debug_printf(jk_format_file_line "\n", sourcefile, (unsigned)__LINE__);
	#endif
    if (new_buffer_size > buffer_size)
    {
    	#if 0
		jk_debug_printf(jk_format_file_line "\n", sourcefile, (unsigned)__LINE__);
		#endif
    	new_buffer_size = jk_align_integer(new_buffer_size);
    	err = jk_malloc((void**)&new_buffer, new_buffer_size);
    	if (err < 0)
    		goto exit;
    	if (keep_all_bytes)
		{
    		jk_copy_memory((void*)new_buffer, (void*)buffer, bytes_in_buffer);
		}
    	jk_free((void**)&buffer);
    	file->buffer.buffer = new_buffer;
    	buffer = new_buffer;
    	new_buffer = 0;
    	file->buffer.buffer_size = new_buffer_size;
    	buffer_size = new_buffer_size;
    }
    else if (!keep_all_bytes && (buffer_size - bytes_in_buffer) < bytes_to_read)
    {
    	#if 0
    	jk_debug_printf(jk_format_file_line "\n", sourcefile, (unsigned)__LINE__);
    	#endif
    	jk_move_memory(buffer, (void*)(buffer + position), bytes_in_buffer - position);
    	bytes_in_buffer -= position;
    	file->buffer.position = 0;
    	position = 0;
    }
    err = jkp_file_read_direct(globals, file, buffer + bytes_in_buffer, buffer_size - bytes_in_buffer, &bytes_read);
    if (err < 0)
        goto exit;
    file->buffer.bytes_in_buffer = (bytes_in_buffer + bytes_read);
    if (bytes_read > bytes_to_read)
    {
    	bytes_read = bytes_to_read;
    }
    if (out_bytes_read != NULL)
    {
        *out_bytes_read = bytes_read;
    }
    else if (bytes_read < bytes_to_read)
    {
        err = -__LINE__;
        goto exit;
    }
    *out_buffer = (buffer + position);
    file->buffer.position = (position + bytes_read);
    err = 0;
exit:
    if (new_buffer != NULL)
    {
    	free(new_buffer);
    }
	if (err < 0)
	{
		jk_printf("%s exiting with %ld\n", function, err);
	}
	return err;
}

JK_ORCAC_SEGMENT

unsigned jk_get_big_endian_u2(const unsigned char * a)
{
    return (((unsigned)a[0]) << 8) | a[1];
}

unsigned long jk_get_big_endian_u4(const unsigned char * a)
{
    return (((unsigned long)a[0]) << 24)
    		| (((unsigned long)a[1]) << 16)
    		| (((unsigned)a[2]) << 8)
    		| a[3]
    		;
}

JK_EXTERN_CONST float jk_java_positive_infinity_float = -1;
JK_EXTERN_CONST float jk_java_negative_infinity_float = -2;
JK_EXTERN_CONST double jk_java_positive_infinity_double = -3;
JK_EXTERN_CONST double jk_java_negative_infinity_double = -4;
JK_EXTERN_CONST float jk_java_nan_float = -5;
JK_EXTERN_CONST double jk_java_nan_double = -6;

/*
jk_ulonglong_t
jk_longlong_to_ulonglong(
    jk_longlong_t a
    )
{
    jk_ulonglong_t b;
    b.low = a.low;
    b.high = (unsigned long)a.high;
    return b;
}
*/

jk_ulonglong_t *
jk_longlong_to_ulonglong_pointer(
    jk_longlong_t * a
    )
{
    return (jk_ulonglong_t*)a;
}

#define jk_add_with_carry_in(function_name, type) \
void function_name(type * a, type b, type c, unsigned carry) \
{ \
  *a = (b + c + (type)carry); \
}

#define jk_add_in_place_with_carry_in(function_name, type) \
void function_name(type * a, type b, unsigned carry) \
{ \
  *a += (b + (type)carry); \
}

#define jk_signed_add_with_carry_in(function_name, type) \
	jk_add_with_carry_in(function_name, type)

#define jk_signed_add_in_place_with_carry_in(function_name, type) \
	jk_add_in_place_with_carry_in(function_name, type)

#define jk_signed_add_with_carry_out(function_name, type) \
void function_name(type * a, type b, type c, unsigned * carry) \
{ \
  const type aa = (b + c); \
  const unsigned aasign = (aa < 0); \
  *a = aa; \
  *carry = (aasign != (b < 0)) && (aasign != (c < 0)); \
}

#define jk_signed_add_with_carry_in_and_out(function_name, type) \
void function_name(type * a, type b, type c, unsigned * carry) \
{ \
  const type aa = (b + c + (type)*carry); \
  const unsigned aasign = (aa < 0); \
  *a = aa; \
  *carry = (aasign != (b < 0)) && (aasign != (c < 0)); \
}

#define jk_unsigned_add_with_carry_in(function_name, type) \
	jk_add_with_carry_in(function_name, type)

#define jk_unsigned_add_in_place_with_carry_in(function_name, type) \
	jk_add_in_place_with_carry_in(function_name, type)

#define jk_unsigned_add_with_carry_in_and_out(function_name, type) \
void function_name(type * a, type b, type c, unsigned * carry) \
{ \
  const type aa = (b + c + (type)*carry); \
  *a = aa; \
  *carry = ((aa < b) || (aa < c)); \
}

#define jk_unsigned_add_with_carry_out(function_name, type) \
void function_name(type * a, type b, type c, unsigned * carry) \
{ \
  const type aa = (b + c); \
  *a = aa; \
  *carry = ((aa < b) || (aa < c)); \
}

#define jk_unsigned_add_one_with_carry_out(function_name, type) \
void function_name(type * a, type b, unsigned * carry) \
{ \
  const type aa = (b + 1); \
  *a = aa; \
  *carry = (aa == 0); \
}

#define jk_unsigned_add_one_in_place_with_carry_out(function_name, type) \
void function_name(type * a, unsigned * carry) \
{ \
  const type aa = (*a + 1); \
  *a = aa; \
  *carry = (aa == 0); \
}

jk_signed_add_with_carry_in(						jk_long_add_with_carry_in, long)
jk_signed_add_with_carry_out(						jk_long_add_with_carry_out, long)
jk_signed_add_with_carry_in_and_out(				jk_long_add_with_carry_in_and_out, long)
jk_signed_add_in_place_with_carry_in(				jk_long_add_in_place_with_carry_in, long)
/*jk_signed_add_in_place_with_carry_out(			jk_long_add_in_place_with_carry_out, long)*/
/*jk_signed_add_in_place_with_carry_in_in_and_out(	jk_long_add_in_place_with_carry_in_and_out, long)*/
/*jk_signed_add_one_with_carry_out(					jk_long_add_one_with_carry_out, long)*/

jk_unsigned_add_with_carry_in(						jk_ulong_add_with_carry_in, unsigned long)
jk_unsigned_add_with_carry_out(						jk_ulong_add_with_carry_out, unsigned long)
jk_unsigned_add_with_carry_in_and_out(				jk_ulong_add_with_carry_in_and_out, unsigned long)
jk_unsigned_add_in_place_with_carry_in(				jk_ulong_add_in_place_with_carry_in, unsigned long)
/*jk_unsigned_add_in_place_with_carry_out(			jk_ulong_add_in_place_with_carry_out, unsigned long)*/
/*jk_unsigned_add_in_place_with_carry_in_in_and_out( jk_ulong_add_in_place_with_carry_in_and_out, unsigned long)*/
jk_unsigned_add_one_with_carry_out(					jk_ulong_add_one_with_carry_out, unsigned long)
jk_unsigned_add_one_in_place_with_carry_out(		jk_ulong_add_one_in_place_with_carry_out, unsigned long)

jk_unsigned_add_with_carry_in(						jk_sizet_add_with_carry_in, size_t)
jk_unsigned_add_with_carry_out(						jk_sizet_add_with_carry_out, size_t)
jk_unsigned_add_with_carry_in_and_out(				jk_sizet_add_with_carry_in_and_out, size_t)
jk_unsigned_add_in_place_with_carry_in(				jk_sizet_add_in_place_with_carry_in, size_t)
/*jk_unsigned_add_in_place_with_carry_out(			jk_sizet_add_in_place_with_carry_out, size_t)*/
/*jk_unsigned_add_in_place_with_carry_in_in_and_out( jk_sizet_add_in_place_with_carry_in_and_out, size_t)*/
jk_unsigned_add_one_with_carry_out(					jk_sizet_add_one_with_carry_out, size_t)
jk_unsigned_add_one_in_place_with_carry_out(		jk_sizet_add_one_in_place_with_carry_out, size_t)

void
jk_long_add_in_place_with_carry_out(long * a, long b, unsigned * carry)
{
    jk_long_add_with_carry_out(a, *a, b, carry);
}

void
jk_long_add_in_place_with_carry_in_and_out(long * a, long b, unsigned * carry)
{
    jk_long_add_with_carry_in_and_out(a, *a, b, carry);
}

void
jk_ulong_add_in_place_with_carry_out(unsigned long * a, unsigned long b, unsigned * carry)
{
    jk_ulong_add_with_carry_out(a, *a, b, carry);
}

void
jk_ulong_add_in_place_with_carry_in_and_out(unsigned long * a, unsigned long b, unsigned * carry)
{
    jk_ulong_add_with_carry_in_and_out(a, *a, b, carry);
}

void
jk_sizet_add_in_place_with_carry_out(size_t * a, size_t b, unsigned * carry)
{
    jk_sizet_add_with_carry_out(a, *a, b, carry);
}

void
jk_sizet_add_in_place_with_carry_in_and_out(size_t * a, size_t b, unsigned * carry)
{
    jk_sizet_add_with_carry_in_and_out(a, *a, b, carry);
}

#define jk_multipleprecision_integer_in_use_malloced 0
#define jk_multipleprecision_integer_in_use_built_in 1

struct jk_multiprecisioninteger_t
{
    unsigned long * malloced_value_array;
    unsigned long built_in_value_array[4];
    unsigned precision;
    unsigned malloced_precision;
    unsigned is_precision_fixed : 1;
    unsigned in_use : 1;
    signed   sign : 1; /* -1, +1 */
};

unsigned long *
jk_multipleprecision_integer_get_value_array(
    const jk_multiprecisioninteger_t * m
    )
{
	const unsigned long * p;
	if (m->in_use)
	{
		p = m->built_in_value_array;
	}
	else
	{
		p = m->malloced_value_array;
	}
	return (unsigned long*)p;
}
#define jk_multiprecision_integer_get_value_array jk_multipleprecision_integer_get_value_array

long
jk_multiprecision_integer_ensure_precision(
    jk_multiprecisioninteger_t * m,
    unsigned n
    )
{
    jk_unused(m);
    jk_unused(&n);
    return jk_undone();
}

long
jk_multiprecision_integer_from_ulong_and_sign(
    jk_multiprecisioninteger_t * m,
    unsigned long i,
    int sign
    )
{
    long err = jk_error_uninitialized;
    
    err = jk_multiprecision_integer_ensure_precision(m, 1);
    if (err < 0) return err;
    m->precision = 1;
    m->sign = sign;
    jk_multipleprecision_integer_get_value_array(m)[0] = i;
    return 0;
}

long
jk_multiprecision_integer_from_ulong(
    jk_multiprecisioninteger_t * m,
    unsigned long i
    )
{
    return jk_multiprecision_integer_from_ulong_and_sign(m, i, 1);
}
    
long
jk_multiprecision_integer_from_long(
    jk_multiprecisioninteger_t * m,
    long i
    )
{
    unsigned long u;
    int sign;
   
    if (i >= 0)
    {
        u = (unsigned long)i;
        sign = +1;
    }
    else
    {
        i += 1;               /* -32768 => -32767 */
        i = -i;               /* -32767 => 32767 */
        u = (unsigned long)i; /* 32767 => 32767 */
        u += 1;               /* 32767 => 32768 */
        sign = -1;
    }
    return jk_multiprecision_integer_from_ulong_and_sign(m, u, sign);
}

unsigned
jk_multiprecision_integer_to_boolean(
    const jk_multiprecisioninteger_t * m
    )
{
    const unsigned long * value_array = jk_multiprecision_integer_get_value_array(m);
    unsigned precision = m->precision;        
    for ( ; precision != 0 ; (--precision), ++value_array)
    {
        if (*value_array != 0)
            return 1;
    }
    return 0;
}

long
jk_multiprecision_integer_bitwise_invert(
    jk_multiprecisioninteger_t * m
    )
{
    unsigned long * value_array = jk_multiprecision_integer_get_value_array(m);
    unsigned precision = m->precision;    
    for ( ; precision != 0 ; (--precision), ++value_array)
    {
        *value_array ^= ~0UL;
    }
    return 0;
}

long
jk_multiprecision_integer_bitwise_and(
    jk_multiprecisioninteger_t * m,
    const jk_multiprecisioninteger_t * n
    )
{
    unsigned long * value_array = jk_multiprecision_integer_get_value_array(m);
    const unsigned long * value_array2 = jk_multiprecision_integer_get_value_array(n);
    unsigned precision = m->precision;
    const unsigned precision2 = n->precision;
    unsigned long any_zero = 0;
    unsigned long t;

    if (precision > precision2)
    {
        precision = precision2;
    }
    for ( ; precision != 0 ; (--precision), (++value_array), (++value_array2))
    {
        t = (*value_array & *value_array2);
        *value_array = t;
        if (t == 0)
        {
            any_zero = 1;
        }
    }
    if (any_zero)
    {
        jk_multiprecision_integer_reduce_precision_due_to_leading_zeros(m);
    }
    return 0;
}

long
jk_multiprecision_integer_reduce_precision_due_to_leading_zeros(
    jk_multiprecisioninteger_t * m
    )
{
    unsigned long const * const value_array = jk_multiprecision_integer_get_value_array(m);
    unsigned precision = m->precision;
    
    while (precision != 0 && value_array[precision - 1] == 0)
    {
        --precision;
    }
    m->precision = precision;
    return 0;
}

long
jk_multiprecision_integer_bitwise_or(
    jk_multiprecisioninteger_t * m,
    const jk_multiprecisioninteger_t * m2
    )
{
    unsigned long * value_array = 0;
    const unsigned long * value_array2 = jk_multiprecision_integer_get_value_array(m2);
    const unsigned precision = m->precision;
    unsigned precision2 = m2->precision;
    long err = jk_error_uninitialized;

    if (precision < precision2)
    {
        err = jk_multiprecision_integer_set_precision(m, precision2);
        if (err < 0) return err;
    }
    value_array = jk_multiprecision_integer_get_value_array(m);
    for ( ; precision2 != 0 ; )
    {
        --precision2;
        value_array[precision2] |= value_array2[precision2];
    }
    return 0;
}

unsigned
jk_multiprecision_integer_logical_not(
    const jk_multiprecisioninteger_t * m
    )
{
    return !jk_multiprecision_integer_to_boolean(m);
}

unsigned
jk_multiprecision_integer_logical_and(
    const jk_multiprecisioninteger_t * m,
    const jk_multiprecisioninteger_t * n
    )
{
    return jk_multiprecision_integer_to_boolean(m) && jk_multiprecision_integer_to_boolean(n);
}

unsigned
jk_multiprecision_integer_logical_or(
    const jk_multiprecisioninteger_t * m,
    const jk_multiprecisioninteger_t * n
    )
{
    return jk_multiprecision_integer_to_boolean(m) || jk_multiprecision_integer_to_boolean(n);
}

long
jk_multiprecision_integer_set_precision(
    jk_multiprecisioninteger_t * m,
    unsigned n
    )
{
    unsigned long * p = 0;
    unsigned i = 0;

    if (n == m->precision)
        return 0;

    if (n > jk_number_of(m->built_in_value_array)
        && m->malloced_value_array != NULL
        && n < m->precision
        )
    {
        m->precision = n;
        return 0;
    }
    p = (unsigned long*)malloc(sizeof(unsigned long) * n);
    if (p == NULL)
        return jk_out_of_memory_error;
    for (i = m->precision; i != n ; ++i)
    {
        p[i] = 0;
    }
    free(m->malloced_value_array);
    m->malloced_value_array = p;
    m->precision = n;
    
    return 0;
}

void
jk_longlong_add(jk_longlong_t * a, const jk_longlong_t * b, const jk_longlong_t * c)
{
    unsigned carry;

    jk_ulong_add_with_carry_out(&a->low, b->low, c->low, &carry);
    jk_long_add_with_carry_in(&a->high, b->high, c->high, carry);
}

void
jk_longlong_add_in_place(jk_longlong_t * a, const jk_longlong_t * b)
{
    unsigned carry;

    jk_ulong_add_with_carry_out(&a->low, a->low, b->low, &carry);
    jk_long_add_with_carry_in(&a->high, a->high, b->high, carry);
}

void
jk_ulonglong_add(jk_ulonglong_t * a, const jk_ulonglong_t * b, const jk_ulonglong_t * c)
{
    unsigned carry;

    jk_ulong_add_with_carry_out(&a->low, b->low, c->low, &carry);
    jk_ulong_add_with_carry_in(&a->high, b->high, c->high, carry);
}

void
jk_ulonglong_add_in_place(jk_ulonglong_t * a, const jk_ulonglong_t * b)
{
    unsigned carry;
    
    jk_ulong_add_in_place_with_carry_out(&a->low, b->low, &carry);
    a->high += (b->high + carry);
}

void
jk_ulonglong_add_one_in_place(
    jk_ulonglong_t * a
    )
{
    a->high += ((a->low += 1) == 0);
}

void
jk_longlong_add_one_in_place(
    jk_longlong_t * a
    )
{
    a->high += ((a->low += 1) == 0);
}

void
jk_ulonglong_add_one(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    )
{
    a->high = b->high + ((a->low = b->low + 1) == 0);
}

void
jk_longlong_add_one(
    jk_longlong_t * a,
    const jk_longlong_t * b
    )
{
    a->high = b->high + ((a->low = b->low + 1) == 0);
}

void
jk_add_ulong_to_ulonglong(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * c,
    unsigned long b
    )
{
    unsigned carry;

    jk_ulong_add_with_carry_out(&a->low, b, c->low, &carry);
    a->high += carry;
}

void
jk_add_ulong_to_ulonglong_in_place(
    jk_ulonglong_t * a,
    unsigned long b
    )
{
    unsigned carry;

    jk_ulong_add_in_place_with_carry_out(&a->low, b, &carry);
    a->high += carry;
}

void
jk_longlong_from_long(
    jk_longlong_t * a,
    long b)
{
    a->low = (unsigned long)b;
    a->high = (b < 0) ? -1L : 0L;
}

void
jk_ulonglong_from_long(
    jk_ulonglong_t * a,
    long b
    )
{
    a->low = (unsigned long)b;
    a->high = (unsigned long)((b < 0) ? -1L : 0L);
}

void
jk_longlong_from_ulong(
    jk_longlong_t * a,
    unsigned long b
    )
{
    a->low = b;
    a->high = 0;
}

void
jk_ulonglong_from_ulong(
    jk_ulonglong_t * a,
    unsigned long b
    )
{
    a->low = b;
    a->high = 0;
}

void
jk_ulonglong_bitwise_and(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b,
    const jk_ulonglong_t * c
    )
{
    a->low = (b->low & c->low);
    a->high = (b->high & c->high);
}

void
jk_ulonglong_bitwise_and_with_ulong_in_place(
    jk_ulonglong_t * a,
    unsigned long b
    )
{
    a->low &= b;
    a->high = 0;
}

void
jk_ulonglong_bitwise_or(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b,
    const jk_ulonglong_t * c
    )
{
    a->low = (b->low | c->low);
    a->high = (b->high | c->high);
}

void
jk_ulonglong_bitwise_or_in_place(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    )
{
    a->low |= b->low;
    a->high |= b->high;
}

void
jk_longlong_bitwise_and(
    jk_longlong_t * a,
    const jk_longlong_t * b,
    const jk_longlong_t * c
    )
{
    a->high = (b->high & c->high);
    a->low = (b->low & c->low);
}

void
jk_longlong_bitwise_or(
    jk_longlong_t * a,
    const jk_longlong_t * b,
    const jk_longlong_t * c
    )
{
    a->high = (b->high | c->high);
    a->low = (b->low | c->low);
}

unsigned
jk_ulonglong_to_boolean(
    const jk_ulonglong_t * a
    )
{
    return ((a->high | a->low) != 0);
}

unsigned
jk_longlong_to_boolean(
    const jk_longlong_t * a
    )
{
    return ((a->high | a->low) != 0);
}

unsigned
jk_ulonglong_logical_and(
    const jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    )
{
    return (jk_ulonglong_to_boolean(a) & jk_ulonglong_to_boolean(b));
}

unsigned
jk_ulonglong_logical_or(
    const jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    )
{
    return ((a->low | a->high | b->low | b->high) != 0);
}

unsigned
jk_longlong_logical_and(
    const jk_longlong_t * a,
    const jk_longlong_t * b
    )
{
    return jk_ulonglong_logical_and(jk_cast(const jk_ulonglong_t *)(a), jk_cast(const jk_ulonglong_t *)(b));
}

unsigned
jk_longlong_logical_or(
    const jk_longlong_t * a,
    const jk_longlong_t * b
    )
{
    return jk_ulonglong_logical_or(jk_cast(const jk_ulonglong_t *)(a), jk_cast(const jk_ulonglong_t *)(b));
}

void
jk_ulonglong_bitwise_invert(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    )
{
    a->low = ~b->low;
    a->high = ~b->high;
}

void
jk_longlong_bitwise_invert(
    jk_longlong_t * a,
    const jk_longlong_t * b
    )
{
    a->low = ~b->low;
    a->high = ~b->high;
}

void
jk_ulonglong_bitwise_invert_in_place(jk_ulonglong_t * a)
{
    a->low = ~a->low;
    a->high = ~a->high;
}

void
jk_longlong_bitwise_invert_in_place(jk_longlong_t * a)
{
    a->low = ~a->low;
    a->high = ~a->high;
}

void
jk_ulonglong_bitwise_exclusive_or(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b,
    const jk_ulonglong_t * c
    )
{
    a->low = (b->low ^ c->low);
    a->high = (b->high ^ c->high);
}

void
jk_longlong_bitwise_exclusive_or(
    jk_longlong_t * a,
    const jk_longlong_t * b,
    const jk_longlong_t * c
    )
{
    a->low = (b->low ^ c->low);
    a->high = (b->high ^ c->high);
}

unsigned
jk_ulonglong_logical_not(const jk_ulonglong_t * a)
{
    return !jk_ulonglong_to_boolean(a);
}

unsigned
jk_longlong_logical_not(const jk_longlong_t * a)
{
    return !jk_longlong_to_boolean(a);
}

unsigned long
jk_ulong_extract_left_n_bits_right_aligned(unsigned long a, unsigned n)
{
	const unsigned k = jk_bits_of(unsigned long);
    return (a >> (k - n));
}

unsigned long
jk_ulong_extract_left_n_bits(unsigned long a, unsigned n)
{
    return (a & ((~0UL) << n));
}

unsigned long
jk_ulong_extract_right_n_bits(unsigned long a, unsigned n)
{
    return (a & ~((~0UL) << n));
}

unsigned long
jk_ulong_extract_right_n_bits_left_aligned(unsigned long a, unsigned n)
{
	const unsigned k = jk_bits_of(unsigned long);
    return (a << (k - n));
}

void
jk_ulonglong_left_shift(jk_ulonglong_t * a, const jk_ulonglong_t * b, unsigned shift)
{
	const unsigned k = jk_bits_of(unsigned long);
	const unsigned k2 = (k * 2);
	unsigned long a_low = 0;
	unsigned long a_high = 0;
	const unsigned long b_low = b->low;
    if (shift < k2)
    {
        if (shift >= k)
        {
        	a_high = (b_low << (shift - k));
        }
        else
        {        
        	a_low = (b_low << shift);
            a_high = (b->high << shift) | jk_ulong_extract_left_n_bits_right_aligned(b_low, shift);
        }
    }
    a->low = a_low;
    a->high = a_high;
}

void
jk_ulonglong_left_shift_in_place(
    jk_ulonglong_t * a,
    unsigned shift
    )
{
    jk_ulonglong_left_shift(a, a, shift);
}

void
jk_longlong_left_shift(
    jk_longlong_t * a,
    const jk_longlong_t * b,
    unsigned shift
    )
{
    jk_ulonglong_left_shift(jk_cast(jk_ulonglong_t *)(a), jk_cast(const jk_ulonglong_t *)(b), shift);
}

void
jk_longlong_left_shift_in_place(
    jk_longlong_t * a,
    unsigned shift
    )
{
    jk_ulonglong_left_shift_in_place(jk_cast(jk_ulonglong_t *)(a), shift);
}

void
jk_ulonglong_right_shift(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b,
    unsigned shift
    )
{
    jk_ulonglong_zero_fill_right_shift(a, b, shift);
}

void
jk_ulonglong_right_shift_in_place(
    jk_ulonglong_t * a,
    unsigned shift
    )
{
    jk_ulonglong_right_shift(a, a, shift);
}

long
jk_long_one_fill_right_shift(
    long a,
    unsigned shift
    )
{
	return (a >> shift) | jk_long_with_n_left_bits_set(shift);
}

long
jk_long_zero_fill_right_shift(
    long a,
    unsigned shift
    )
{
	return (long)(((unsigned long)a) >> shift);
}

long
jk_long_sign_fill_right_shift(
    long a,
    unsigned shift
    )
{
	return ((a < 0) ? jk_long_one_fill_right_shift(a, shift)
	                : jk_long_zero_fill_right_shift(a, shift));
}

         long jk_long_with_n_right_bits_clear(unsigned n)  { return (long) ((~0L ) << n); }
         long jk_long_with_n_right_bits_set(unsigned n)    { return (long)~((~0L ) << n); }
         long jk_long_with_n_left_bits_clear(unsigned n)   { return (long) ((~0UL) >> n); }
         long jk_long_with_n_left_bits_set(unsigned n)     { return (long)~((~0UL) >> n); }
unsigned long jk_ulong_with_n_right_bits_clear(unsigned n) { return        ((~0UL) << n); }
unsigned long jk_ulong_with_n_right_bits_set(unsigned n)   { return       ~((~0UL) << n); }
unsigned long jk_ulong_with_n_left_bits_clear(unsigned n)  { return        ((~0UL) >> n); }
unsigned long jk_ulong_with_n_left_bits_set(unsigned n)    { return       ~((~0UL) >> n); }

#define jk_bits_of(x) (sizeof(x)*8)

unsigned long
jk_ulong_rotate_left(
    unsigned long a,
    unsigned b
    )
{
	const unsigned k = jk_bits_of(unsigned long);

	return (a << b) | (a >> (k - b));
}

unsigned long
jk_ulong_rotate_right(
    unsigned long a,
    unsigned b
    )
{
	const unsigned k = jk_bits_of(unsigned long);

	return (a >> b) | (a << (k - b));
}

unsigned long
jk_ulong_one_fill_right_shift(unsigned long a, unsigned shift)
{
	const unsigned k = jk_bits_of(unsigned long);

	return (a >> shift) | ~((~0UL) << (k - shift));
}

unsigned long
jk_ulong_zero_fill_right_shift(unsigned long a, unsigned shift)
{
	return (a >> shift);
}

void
jk_ulonglong_zero_fill_right_shift(jk_ulonglong_t * a, const jk_ulonglong_t * b, unsigned shift)
{
	const unsigned k = jk_bits_of(unsigned long);
	const unsigned k2 = (k * 2);
	unsigned long a_low = 0;
	unsigned long a_high = 0;
	const unsigned long b_high = b->high;
    if (shift < k2)
    {
        if (shift >= k)
        {
            a_low = (b_high >> (shift - k));
        }
        else
        {
            a_high = (b_high >> shift);
            a_low = (b->low >> shift) | jk_ulong_extract_right_n_bits_left_aligned(b_high, shift);
        }
    }
    a->low = a_low;
    a->high = a_high;
}

void
jk_ulonglong_one_fill_right_shift(jk_ulonglong_t * a, const jk_ulonglong_t * b, unsigned shift)
{
	const unsigned k = jk_bits_of(unsigned long);
	const unsigned k2 = (k * 2);
	unsigned long a_low = ~0UL;
	unsigned long a_high = ~0UL;
	const unsigned long b_high = b->high;
    if (shift < k2)
    {
        if (shift >= k)
        {
            a_low = jk_ulong_one_fill_right_shift(b_high, shift - k);
        }
        else
        {
            a_high = (b_high >> shift) | ~(~0UL >> shift);
            a_low =  (b->low >> shift) | (b_high << (k - shift));
        }
    }
    a->low = a_low;
    a->high = a_high;
}

void
jk_longlong_one_fill_right_shift(jk_longlong_t * a, const jk_longlong_t * b, unsigned shift)
{
	jk_ulonglong_one_fill_right_shift(
		jk_cast(jk_ulonglong_t *)(a),
		jk_cast(const jk_ulonglong_t *)(b),
		shift);
}

void
jk_longlong_zero_fill_right_shift(
    jk_longlong_t * a,
    const jk_longlong_t * b,
    unsigned shift
    )
{
	jk_ulonglong_zero_fill_right_shift(
		jk_cast(jk_ulonglong_t *)(a),
		jk_cast(const jk_ulonglong_t *)(b),
		shift);
}

void
jk_longlong_sign_fill_right_shift(
    jk_longlong_t * a,
    const jk_longlong_t * b,
    unsigned shift
    )
{
    (b->high < 0)
        ? jk_longlong_one_fill_right_shift(a, b, shift)
        : jk_longlong_zero_fill_right_shift(a, b, shift);
}

unsigned long jk_ulong_get_right_justified_high_half(unsigned long a)
{
    return (a >> (jk_bits_of(a) / 2));
}

unsigned long jk_ulong_get_low_half(unsigned long a)
{
    return  (a & (~0UL >> (jk_bits_of(a) / 2)));
}

unsigned long jk_ulong_get_left_justified_high_half(unsigned long a)
{
    return  (a & (~0UL << (jk_bits_of(a) / 2)));
}

void
jk_ulong_multiply_to_ulonglong(jk_ulonglong_t * a, unsigned long b, unsigned long c)
{
    const unsigned long bl = jk_ulong_get_low_half(b);
    const unsigned long bh = jk_ulong_get_right_justified_high_half(b);
    const unsigned long cl = jk_ulong_get_low_half(c);
    const unsigned long ch = jk_ulong_get_right_justified_high_half(c);
    jk_ulonglong_t aa[2];
    unsigned carry;

    if ((bh | ch) == 0)
    {
        a->low = bl * cl;
        a->high = 0;
        return;
    }
    aa[0].low = (bl * cl);
    aa[0].high = (bh * ch);
    jk_ulong_add_with_carry_out(&aa[1].low, (bl * ch), (bh * cl), &carry);
    aa[1].high = carry;    
    jk_ulonglong_left_shift_in_place(&aa[1], jk_bits_of(unsigned long)/2);
    jk_ulonglong_add(a, &aa[0], &aa[1]);
}

void
jk_long_split_into_magnitude_and_sign(
    long i,
    unsigned long * magnitude,
    int * sign
    )
{
    int local_sign = 1;
    unsigned long local_magnitude = (unsigned long)i;
    if (i < 0)
    {
        local_magnitude = ((unsigned long)-(i + 1)) + 1;
        local_sign = -1;
    }
    *sign = local_sign;
    *magnitude = local_magnitude;
}

void
jk_ultoa(
    unsigned long u,
    char * a
    )
{
    char * b = a;
    do
    {
        *b++ = (char)((u % 10) + '0');
        u /= 10;
    } while (u != 0);
    *b = 0;
    jk_reverse_memory_range_exclusive(a, b);
}
 
void
jk_utoa(
    unsigned u,
    char * a
    )
{
    char * b = a;
    do
    {
        *b++ = (char)((u % 10) + '0');
        u /= 10;
    } while (u != 0);
    *b = 0;
    jk_reverse_memory_range_exclusive(a, b);
}

void
jk_ltoa(
    long i,
    char * a
    )
{
    unsigned long u;
    if (i < 0)
    {
        *a++ = '-';
        u = ((unsigned long)(-(i + 1))) + 1;
    }
    else
    {
        u = (unsigned long)i;
    }
    jk_ultoa(u, a);    
}

void
jk_itoa(
    int i,
    char * a
    )
{
    unsigned u;
    if (i < 0)
    {
        *a++ = '-';
        u = ((unsigned)(-(i + 1))) + 1;
    }
    else
    {
        u = (unsigned)i;
    }
    jk_utoa(u, a);    
}

void
jk_longlong_split_into_magnitude_and_sign(
	const jk_longlong_t * i,
    jk_ulonglong_t * magnitude,
    int * sign
    )
{
    int local_sign;
    unsigned long local_low = i->low;
    long local_high = i->high;
    if (local_high < 0)
    {
        local_high = -local_high - (local_low != 0);
        local_low = -local_low;
        local_sign = -1;
    }
    else
    {
        local_sign = +1;
    }
    magnitude->low = local_low;
    magnitude->high = (unsigned long)local_high;
    *sign = local_sign;
}

void
jk_ulonglong_negate(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    )
{
    unsigned long b_low = -b->low;
    a->low = b_low;
    a->high = -b->high - (b_low != 0);
}

void
jk_ulonglong_negate_in_place(
    jk_ulonglong_t * a
    )
{
    jk_ulonglong_negate(a, a);
}

void
jk_longlong_negate(
    jk_longlong_t * a,
    const jk_longlong_t * b
    )
{
    unsigned long b_low = -b->low;
    a->low = b_low;
    a->high = -b->high - (b_low != 0);
}

void
jk_longlong_negate_in_place(
    jk_longlong_t * a
    )
{
    jk_longlong_negate(a, a);
}

void
jk_long_multiply_to_longlong(
    jk_longlong_t * a,
    long b,
    long c
    )
{
    jk_ulonglong_t ua;
    unsigned long ub;
    unsigned long uc;
    int signb;
    int signc;
    
    jk_long_split_into_magnitude_and_sign(b, &ub, &signb);
    jk_long_split_into_magnitude_and_sign(c, &uc, &signc);
    jk_ulong_multiply_to_ulonglong(&ua, ub, uc);
    a->low = ua.low;
    a->high = (long)ua.high;
    /* negative times negative => positive
       positive times positive => positive
       negative times positive => negative
    */
    if (signb != signc)
    {
        jk_longlong_negate_in_place(a);
    }
}

void
jk_ulonglong_multiply(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b,
    const jk_ulonglong_t * c
    )
{
    const unsigned long bl = b->low;
    const unsigned long bh = b->high;
    const unsigned long cl = c->low;
    const unsigned long ch = c->high;
    jk_ulonglong_t t;

    jk_ulong_multiply_to_ulonglong(a, bl, cl);
 
    t.low = 0;
    t.high = (bl * ch) + (bh * cl);
    jk_ulonglong_add_in_place(a, &t);    
}

void
jk_longlong_multiply(
    jk_longlong_t * a,
    const jk_longlong_t * b,
    const jk_longlong_t * c
    )
{
    jk_ulonglong_t ua;
    jk_ulonglong_t ub;
    jk_ulonglong_t uc;
    int signb;
    int signc;
    
    jk_longlong_split_into_magnitude_and_sign(b, &ub, &signb);
    jk_longlong_split_into_magnitude_and_sign(c, &uc, &signc);
    jk_ulonglong_multiply(&ua, &ub, &uc);
    a->low = ua.low;
    a->high = (long)ua.high;
    /* negative times negative => positive
       positive times positive => positive
       negative times positive => negative
    */
    if (signb != signc)
    {
        jk_longlong_negate_in_place(a);
    }
}

unsigned
jk_ulonglong_is_greater_or_equal(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j
    )
{
    return (i->high > j->high) || ((i->high == j->high) && (i->low >= j->low));
}

unsigned
jk_ulonglong_is_greater(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j
    )
{
    return (i->high > j->high) || ((i->high == j->high) && (i->low > j->low));
}

unsigned
jk_ulonglong_is_less(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j
    )
{
    return (i->high < j->high) || ((i->high == j->high) && (i->low < j->low));
}

unsigned
jk_ulonglong_is_less_or_equal(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j
    )
{
    return (i->high < j->high) || ((i->high == j->high) && (i->low <= j->low));
}

unsigned
jk_longlong_is_greater_or_equal(
    const jk_longlong_t * i,
    const jk_longlong_t * j
    )
{
    return (i->high > j->high) || ((i->high == j->high) && (i->low >= j->low));
}

unsigned
jk_longlong_is_greater(
    const jk_longlong_t * i,
    const jk_longlong_t * j
    )
{
    return (i->high > j->high) || ((i->high == j->high) && (i->low > j->low));
}

unsigned
jk_longlong_is_less(
    const jk_longlong_t * i,
    const jk_longlong_t * j
    )
{
    return (i->high < j->high) || ((i->high == j->high) && (i->low < j->low));
}

unsigned
jk_longlong_is_less_or_equal(
    const jk_longlong_t * i,
    const jk_longlong_t * j
    )
{
    return (i->high < j->high) || ((i->high == j->high) && (i->low < j->low));
}

unsigned
jk_ulonglong_is_equal(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j
    )
{
    return (i->high == j->high) && (i->low == j->low);
}

unsigned
jk_ulonglong_is_not_equal(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j
    )
{
    return (i->high != j->high) || (i->low != j->low);
}

unsigned
jk_longlong_is_equal(
    const jk_longlong_t * i,
    const jk_longlong_t * j
    )
{
    return (i->high == j->high) && (i->low == j->low);
}

unsigned
jk_longlong_is_not_equal(
    const jk_longlong_t * i,
    const jk_longlong_t * j
    )
{
    return (i->high != j->high) || (i->low != j->low);
}

#define jk_swap_primtive(T,x,y) do { T t = x; x = y; y = t; } while(0)
 
unsigned
jk_ulonglong_is_in_ordered_range_inclusive(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * low,
    const jk_ulonglong_t * high
    )
{

    return jk_ulonglong_is_greater_or_equal(i, low) && jk_ulonglong_is_less_or_equal(i, high);
}

unsigned
jk_longlong_is_in_ordered_range_inclusive(
    const jk_longlong_t * i,
    const jk_longlong_t * low,
    const jk_longlong_t * high
    )
{

    return jk_longlong_is_greater_or_equal(i, low) && jk_longlong_is_less_or_equal(i, high);
}

void
jk_ulonglong_order_range(
    const jk_ulonglong_t ** pplow,
    const jk_ulonglong_t ** pphigh
    )
{
    const jk_ulonglong_t * plow = *pplow;
    const jk_ulonglong_t * phigh = *pphigh;
    if (jk_ulonglong_is_greater(plow, phigh))
    {
        *pplow = phigh;
        *pphigh = plow;
    }
}

void
jk_longlong_order_range(
    const jk_longlong_t ** pplow,
    const jk_longlong_t ** pphigh
    )
{
    const jk_longlong_t * plow = *pplow;
    const jk_longlong_t * phigh = *pphigh;
    if (jk_longlong_is_greater(plow, phigh))
    {
        *pplow = phigh;
        *pphigh = plow;
    }
}

unsigned
jk_ulonglong_is_in_unordered_range_inclusive(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j,
    const jk_ulonglong_t * k
    )
{
    jk_ulonglong_order_range(&j, &k);
    return jk_ulonglong_is_in_ordered_range_inclusive(i, j, k);
}

unsigned
jk_longlong_is_in_unordered_range_inclusive(
    const jk_longlong_t * i,
    const jk_longlong_t * j,
    const jk_longlong_t * k
    )
{
    jk_longlong_order_range(&j, &k);
    return jk_longlong_is_in_ordered_range_inclusive(i, j, k);
}

unsigned
jk_ulonglong_is_in_ordered_range_exclusive(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * low,
    const jk_ulonglong_t * high
    )
{
    return jk_ulonglong_is_greater_or_equal(i, low) && jk_ulonglong_is_less(i, high);
}    

unsigned
jk_longlong_is_in_ordered_range_exclusive(
    const jk_longlong_t * i,
    const jk_longlong_t * low,
    const jk_longlong_t * high
    )
{
    return jk_longlong_is_greater_or_equal(i, low) && jk_longlong_is_less(i, high);
}    

unsigned
jk_ulonglong_is_in_unordered_range_exclusive(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j,
    const jk_ulonglong_t * k
    )
{
    jk_ulonglong_order_range(&j, &k);
    return jk_ulonglong_is_in_ordered_range_exclusive(i, j, k);
}

unsigned
jk_longlong_is_in_unordered_range_exclusive(
    const jk_longlong_t * i,
    const jk_longlong_t * j,
    const jk_longlong_t * k
    )
{
    jk_longlong_order_range(&j, &k);
    return jk_longlong_is_in_ordered_range_exclusive(i, j, k);
}

void
jk_copy_ulonglong_to_longlong(
    jk_longlong_t * to,
    const jk_ulonglong_t * from
    )
{
    to->low = from->low;
    to->high = (long)from->high;
}

void
jk_copy_longlong_to_ulonglong(
    jk_ulonglong_t * to,
    const jk_longlong_t * from
    )
{
    to->low = from->low;
    to->high = (unsigned long)from->high;
}

void
jk_ulonglong_from_high_low_32bit_ulongs(
    jk_ulonglong_t * i,
    unsigned long high,
    unsigned long low
    )
{
   i->high = 0;
   i->low = high;
   jk_ulonglong_left_shift_in_place(i, 32);
   i->low |= low;
}

JK_ORCAC_SEGMENT

double
jk_java_convert_java_double_to_native_double(
    const unsigned char * bytes
    )
{
    jk_function("jk_java_convert_java_double_to_native_double");
    jk_ulonglong_t positive_infinity;
    jk_ulonglong_t negative_infinity;
    jk_ulonglong_t nan[4];
    jk_ulonglong_t ll;
    jk_ulonglong_t ll_sign;
    jk_ulonglong_t ll_exponent;
    jk_ulonglong_t ll_mantissa;
    int sign;
    int exponent;
    double nan_result = 0;
    jk_ulonglong_t bit53;
    jk_ulonglong_t bits52;
    unsigned long mantissa_low32;
    unsigned long mantissa_high20;
    double result;
    
    jk_unused(function); 
    
    jk_java_get_ulong(&ll, bytes);
#if 0
    jk_debug_printf("%s 0x%lx 0x%lx\n", function, ll.high, ll.low);
    jk_debug_printf("%s %f\n", function, *(double*)&ll);
#endif
    jk_ulonglong_from_high_low_32bit_ulongs(&positive_infinity, 0x7ff00000ul, 0);    
    if (jk_ulonglong_is_equal(&ll, &positive_infinity))
    {
        /*jk_debug_printf("%s +inf\n", function);*/
        result = jk_java_positive_infinity_double;
        goto exit;
    }
    jk_ulonglong_from_high_low_32bit_ulongs(&negative_infinity, 0xfff00000ul, 0);    
    if (jk_ulonglong_is_equal(&ll, &negative_infinity))
    {
        /*jk_debug_printf("%s -inf\n", function);*/
        result = jk_java_negative_infinity_double;
        goto exit;
    }    
    jk_ulonglong_from_high_low_32bit_ulongs(&nan[0], 0x7ff00000UL, 1);    
    jk_ulonglong_from_high_low_32bit_ulongs(&nan[1], 0x7fffffffUL, 0xffffffffUL);    
    if (jk_ulonglong_is_in_unordered_range_inclusive(&ll, &nan[0], &nan[1]))
    {
#if 0
        jk_debug_printf("%s nan1 0x%lx 0x%lx\n", function, nan[0].high, nan[0].low);
        jk_debug_printf("%s nan1 0x%lx 0x%lx\n", function, nan[1].high, nan[1].low);
        jk_debug_printf("%s nan1\n", function);
#endif
        result = nan_result;
        goto exit;
    }
    jk_ulonglong_from_high_low_32bit_ulongs(&nan[2], 0xfff00000UL, 1);    
    jk_ulonglong_from_high_low_32bit_ulongs(&nan[3], 0xffffffffUL, 0xffffffffUL);    
    if (jk_ulonglong_is_in_unordered_range_inclusive(&ll, &nan[2], &nan[3]))
    {
        /*jk_debug_printf("%s nan2\n", function);*/
        result = nan_result;
        goto exit;
    }
    jk_ulonglong_right_shift(&ll_sign, &ll, 63);
    jk_ulonglong_right_shift(&ll_exponent, &ll, 52);
    jk_ulonglong_from_high_low_32bit_ulongs(&bits52, 0xfffff, 0xffffffff);
    /*jk_debug_printf("%s bits52=0x%lx 0x%lx\n", function, bits52.high, bits52.low);*/
    jk_ulonglong_bitwise_and(&ll_mantissa, &ll, &bits52);
    exponent = (int)(ll_exponent.low & 0x7ff);
    sign = ((ll_sign.low & 1) ? -1 : +1);
    /*jk_debug_printf("%s exponent 0x%x %+d\n", function, (unsigned)exponent, exponent - 1075);*/
    /*jk_debug_printf("%s sign %+d\n", function, sign);*/
    if (exponent == 0)
    {
        jk_ulonglong_left_shift_in_place(&ll_mantissa, 1);
        /*jk_debug_printf("%s exp=0, mant=0x%lx 0x%lx\n", function, ll_mantissa.high, ll_mantissa.low);*/
    }
    else
    {        
        jk_ulonglong_from_high_low_32bit_ulongs(&bit53, 0x100000, 0x00000000);
        jk_ulonglong_bitwise_or_in_place(&ll_mantissa, &bit53);
        /*jk_debug_printf("%s exp!=0, mant=0x%lx 0x%lx\n", function, ll_mantissa.high, ll_mantissa.low);*/
    }    
    mantissa_low32 = (ll_mantissa.low & 0xffffffff);
    jk_ulonglong_right_shift_in_place(&ll_mantissa, 32);
    mantissa_high20 = ll_mantissa.low;    
   /*jk_debug_printf("%s mantissa_high20 0x%lx\n", function, mantissa_high20);*/
   /*jk_debug_printf("%s mantissa_low32 0x%lx\n", function, mantissa_low32);*/
   result = sign * (ldexp(mantissa_low32, exponent - 1075) + ldexp(mantissa_high20, exponent - 1075 + 32));
exit:
    /*jk_debug_printf("%s %f\n", function, result);*/

    return result;
}

float
jk_java_convert_java_float_to_native_float(
    const unsigned char * bytes
    )
{
    jk_function("jk_java_convert_java_float_to_native_float");
    long sign;
    int exponent;
    long mantissa;
    unsigned long i;
    float f;

    jk_unused(function); 

    i = jk_get_big_endian_u4(bytes);
    
#if 0
    jk_debug_printf("%s 0x%lx\n", function, i);
    jk_debug_printf("%s %f\n", function, *(float*)&i);
#endif
    if (bytes[0] == 0x7f || bytes[0] == 0xff)
    {
        if (i == 0x7f800000ul)
        {
            f = jk_java_positive_infinity_float;
            goto exit;
        }
        else if (i == 0xff800000ul)
        {
            f = jk_java_negative_infinity_float;
            goto exit;
        }
        else if ((i >= 0x7f800001ul && i <= 0x7ffffffful)
                || (i >= 0xff800001ul && i <= 0xfffffffful))
        {
            f = jk_java_nan_float;
            goto exit;
        }
    }
    sign = ((i >> 31) == 0) ? +1 : -1;
    exponent = (int)((i >> 23) & 0xff);
    mantissa = (long)((exponent == 0) ? ((i & 0x7fffff) << 1) : ((i & 0x7fffff) | 0x800000));

    f = (float)(sign * ldexp(mantissa, exponent - 150));
    /*jk_debug_printf("%s %f\n", function, f);*/
exit:
    return f;
}

void
jk_java_free_constant_pool(
    jk_java_constant_pool_t * constant_pool
    )
{
	jk_free((void**)&constant_pool->tags);
	jk_free((void**)&constant_pool->any);
}

typedef struct jk_compactable_heap_entry_t {
/* private */
    size_t offset;
    size_t size;
} jk_compactable_heap_entry_t;

struct jk_compactable_heap_t
{
/* public */
	unsigned char * base;
/* private */
	size_t underlying_bytes_allocated;
	size_t total_bytes_used;
	size_t total_bytes_free;
	jk_compactable_heap_entry_t used_array;
	jk_compactable_heap_entry_t free_array;
	jk_compactable_heap_entry_t large_free_block;
};

void
jk_get_pointer_into_compactable_heap(
    jk_compactable_heap_t * heap,
    size_t offset,
    void ** pointer
    )
{
    *pointer = (heap->base + offset);
}
    
void
jk_compact_compactable_heap(
    jk_compactable_heap_t * heap
    )
{
    jk_compactable_heap_t local = *heap;
    jk_compactable_heap_entry_t * used_entry;
    jk_compactable_heap_entry_t * free_entry;

    if (local.free_array.size == 0)
        return;
    jk_get_pointer_into_compactable_heap(heap, local.free_array.offset, (void**)&free_entry);
    if (local.free_array.size == 1)
    {
        if (free_entry->offset == local.total_bytes_used
            || free_entry->offset == 0)
        {
            return;
        }
    }
    jk_get_pointer_into_compactable_heap(heap, local.used_array.offset, (void**)&used_entry);
    while (used_entry->offset < free_entry->offset)
    {
        used_entry += 1;
    }
}

void
jk_compact_compactable_heap_to_new_minimal_underlying_allocation(
    jk_compactable_heap_t * heap
    )
{
    jk_unused(heap);
}

#if 0

struct jk_movable_heap_t
{
	unsigned char * base;
	size_t used;
	size_t free;
	size_t number_of_allocations;
};

long
jk_init_movable_heap(
	jk_movable_heap_t * heap
	)
{
	heap->base = 0;
	heap->used = 0;
	heap->free = 0;
	heap->number_of_allocations = 0;
	return 0;
}

long
jk_grow_movable_heap(
	jk_movable_heap_t * heap,
	size_t new_size
	)
{
	unsigned char * new_base = 0;
	unsigned char * old_base = 0;
	size_t current_size = 0;
	long err = jk_error_uninitialized;
	
	current_size = heap->used + heap->free;
	if (current_size >= new_size)
		return 0;
	err = jk_malloc((void**)&new_base, new_size);
	if (err < 0) goto exit;
	old_base = heap->base;
	jk_copy_memory(new_base, old_base, heap->used);
	jk_free((void**)&old_base);
	heap->base = new_base;
	heap->free += (current_size - new_size);
	err = 0;
exit:
	return err;
}

long
jk_allocate_from_movable_heap(
	jk_movable_heap_t * heap,
	size_t size,
	unsigned char * p
	)
{
	long err = jk_error_uninitialized;
	jk_movable_heap_t local;
	
	local.used = heap->used;
	local.base = heap->base;
	local.free = heap->free;
	
	if (local.free < size)
	{
		size_t current_heap_size = (local.used + local.free);
		size_t new_heap_size = current_heap_size * 2;
		if (new_heap_size < size)
			new_heap_size = size;
		err = jk_grow_movable_heap(heap, new_heap_size);
		if (err < 0) goto exit;
		local.free = (new_heap_size - local.used);
	}
	heap->free = local.free - size;
	*p = (local.base + local.used);
	heap->used = (local.used + size);
	err = 0;
exit:
	return err;
}
#endif

#if 0
long
jk_free_to_position_independent_heap(
	)
{
	return jk_error_unimplemented;
}

long
jk_free_position_independent_heap(
	)
{
	return jk_error_unimplemented;
}
#endif

JK_ORCAC_SEGMENT

typedef struct jk_hash_table_entry_t {
	struct jk_hash_table_entry_t * next;
	unsigned key_hash;
	unsigned key_size;
	unsigned value_size;
} jk_hash_table_entry_t;

typedef struct jk_hash_table_bucket_t {
	unsigned number_of_entries;
	jk_hash_table_entry_t * entries;
} jk_hash_table_bucket_t;

typedef struct jk_hash_table_t {
	unsigned number_of_buckets;
	unsigned number_of_entries;
	jk_hash_table_bucket_t * buckets;
} jk_hash_table_t;

long
jk_java_read_constant_pool(
    const jk_globals_t * globals,
    jk_java_classfile_t * classfile
    )
{
    jk_function("jk_java_read_constant_pool");
    long err = jk_error_uninitialized;
    unsigned constants_read;
    unsigned constant_pool_count = classfile->constant_pool_count;
    jk_java_constant_pool_t * constant_pool = &classfile->constant_pool;
    jk_file_t * file = &classfile->file;
    unsigned char * buffer;
    unsigned char * tags;
    unsigned char tag;
	jk_java_any_t * any;
	unsigned string_index;
	unsigned class_index;
	unsigned name_and_type_index;
	unsigned name_index;
	unsigned type_index;
	unsigned long unsigned_long;
	unsigned utf8_length_in_bytes;
	char* char_pointer;
	size_t bytes_read;
	float native_float;
	double native_double;

    constant_pool->tags = 0;
    constant_pool->any = 0;

	err = jk_malloc((void**)&tags, constant_pool_count);
	if (err < 0) goto exit;
    constant_pool->tags = tags;

	err = jk_malloc((void**)&any, sizeof(*any) * constant_pool_count);
	if (err < 0) goto exit;
    constant_pool->any = any;
	
    err = jk_file_read_ahead(globals, file, 3 * constant_pool_count);
    if (err < 0) goto exit;

    for ( constants_read = 1 ; constants_read != constant_pool_count ; ++constants_read )
    {
        #if 0
        jk_debug_printf("%s 0x%x 0x%x\n", function, constants_read, constant_pool_count);
        #endif
    	err = jk_file_read_get_buffer(globals, file, (void**)&buffer, 3, NULL);
    	if (err < 0) goto exit;
    	tag = buffer[0];
    	tags[constants_read] = tag;
    	switch (tag)
    	{
    	case jk_java_constant_class_tag:
            class_index = jk_get_big_endian_u2(buffer + 1);
            any[constants_read].unresolved_constant.class_ref.class_index = class_index;
    	    jk_debug_printf("%s jk_java_constant_class tag=0x%x class=0x%x\n", function, tag, class_index);
    		break;
    	case jk_java_constant_name_and_type_tag:
			err = jk_file_read_ahead(globals, file, 2);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(globals, file, (void**)&buffer, 2, NULL);
    		if (err < 0)
    			goto exit;
            name_index = jk_get_big_endian_u2(buffer - 2);
            type_index = jk_get_big_endian_u2(buffer);
            any[constants_read].unresolved_constant.name_and_type.name_index = name_index;
            any[constants_read].unresolved_constant.name_and_type.type_index = type_index;
    	    jk_debug_printf("%s jk_java_constant_name_and_type tag=0x%x name=0x%x type=0x%x\n", function, tag, name_index, type_index);
            break;
    	case jk_java_constant_fieldref_tag:
    	case jk_java_constant_methodref_tag:
    	case jk_java_constant_interfacemethodref_tag:
			err = jk_file_read_ahead(globals, file, 2);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(globals, file, (void**)&buffer, 2, NULL);
    		if (err < 0)
    			goto exit;
            class_index = jk_get_big_endian_u2(buffer - 2);
            name_and_type_index = jk_get_big_endian_u2(buffer);
            any[constants_read].unresolved_constant.member_ref.class_index = class_index;
            any[constants_read].unresolved_constant.member_ref.name_and_type_index = name_and_type_index;
    	    jk_debug_printf("%s jk_java_constant_ref tag=0x%x class=0x%x name_and_type=0x%x\n", function, tag, class_index, name_and_type_index);
            break;
         case jk_java_constant_string_tag:
            string_index = jk_get_big_endian_u2(buffer + 1);
            any[constants_read].unresolved_constant.string_ref.string_index = string_index;
    	    jk_debug_printf("%s jk_java_constant_string tag=%x string=%x\n", function, tag, string_index);
         	break;
         case jk_java_constant_integer_tag:         	
			err = jk_file_read_ahead(globals, file, 2);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(globals, file, (void**)&buffer, 2, NULL);
    		if (err < 0)
    			goto exit;
			unsigned_long = jk_get_big_endian_u4(buffer - 2);
			any[constants_read].UnsignedLong = unsigned_long;
    	    jk_debug_printf("%s jk_java_constant_integer tag=0x%x 0x%lx\n", function, tag, unsigned_long);
    		break;
         case jk_java_constant_float_tag:         	
			err = jk_file_read_ahead(globals, file, 2);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(globals, file, (void**)&buffer, 2, NULL);
    		if (err < 0)
    			goto exit;
			native_float = jk_java_convert_java_float_to_native_float(buffer - 2);
			any[constants_read].native_float = native_float;
    	    jk_debug_printf("%s jk_java_constant_float tag=0x%x %f\n", function, tag, native_float);
    		break;
         case jk_java_constant_double_tag:         	
			err = jk_file_read_ahead(globals, file, 3);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(globals, file, (void**)&buffer, 6, NULL);
    		if (err < 0)
    			goto exit;
			native_double = jk_java_convert_java_double_to_native_double(buffer - 2);
			any[constants_read].native_double = native_double;
			constants_read += 1;
    	    jk_debug_printf("%s jk_java_constant_double 0x%x %f\n", function, tag, native_double);
    		break;
         case jk_java_constant_long_tag:         	
			err = jk_file_read_ahead(globals, file, 3);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(globals, file, (void**)&buffer, 6, NULL);
    		if (err < 0)
    			goto exit;
			jk_java_get_long(&any[constants_read].LongLong, buffer - 2);
			constants_read += 1;
    	    jk_debug_printf("%s jk_java_constant_long 0x%x\n", function, tag);
    		break;
        case jk_java_constant_utf8_tag:
            utf8_length_in_bytes = jk_get_big_endian_u2(buffer + 1);
			err = jk_file_read_ahead(globals, file, utf8_length_in_bytes);
    		if (err < 0)
    			goto exit;
    		err = jk_malloc((void**)&char_pointer, utf8_length_in_bytes + 1);
    		if (err < 0)
    			goto exit;
    		err = jk_file_read_copy(globals, file, char_pointer, utf8_length_in_bytes, &bytes_read);
    		if (err < 0)
    			goto exit;
    		char_pointer[utf8_length_in_bytes] = 0;
            any[constants_read].char_pointer = char_pointer;
    	    jk_debug_printf("%s jk_java_constant_utf8 0x%x 0x%x %s\n", function, tag, utf8_length_in_bytes, char_pointer);
            break;
    	default:
    	    jk_debug_printf("unknown tag %x\n", tag);
    	    break;
    	}
    }
    err = 0;
exit:
	if (err < 0)
	{
		jk_printf("%s exiting with %ld\n", function, err);
		jk_java_free_constant_pool(constant_pool);
	}
    return err;
}

long
jk_init_file_buffer(
    const jk_globals_t * globals,
	jk_file_buffer_t * file_buffer
	)
{
	jk_file_buffer_t * const x = file_buffer;

    jk_unused(globals);
	
	x->buffer = 0;
	x->buffer_size = 0;
	x->bytes_in_buffer = 0;
	x->position = 0;
	x->read_ahead = 0;
	x->keep_all_bytes = 0;
	return 0;
}

long
jk_init_file(
    const jk_globals_t * globals,
	jk_file_t * file
	)
{
	jk_file_t * const x = file;
	
	x->stdio_file = 0;
	x->file_path = 0;
	x->openmode = 0;
	jk_init_file_buffer(globals, &x->buffer);
	return 0;
}

long
jk_java_init_constant_pool(
    const jk_globals_t * globals,
	jk_java_constant_pool_t * constant_pool
	)
{
	jk_java_constant_pool_t * const x = constant_pool;
	
    jk_unused(globals);

	x->tags = 0;
	x->any = 0;
	return 0;
}

long
jk_java_init_classfile(
    const jk_globals_t * globals,
	jk_java_classfile_t * classfile
	)
{
	jk_java_classfile_t * const x = classfile;
	
	jk_zero_memory(classfile, sizeof(*classfile));
	x->magic[0] = 0;
	x->magic[1] = 0;
	x->magic[2] = 0;
	x->magic[3] = 0;
	x->minor_version = 0;	
	x->major_version = 0;
	x->constant_pool_count = 0;
	x->access_flags = 0;
	x->this_class = 0;
	x->super_class = 0;
	x->interfaces_count = 0;
	x->fields_count = 0;
	x->methods_count = 0;
	x->attributes_count = 0;
	jk_init_file(globals, &x->file);
	jk_java_init_constant_pool(globals, &x->constant_pool);
	
	return 0;
}

void
jk_java_get_ulong(
    jk_ulonglong_t * i,
    const unsigned char * p
    )
{
	i->high =  (((unsigned long)p[0]) << 24)
            | (((unsigned long)p[1]) << 16)
            | (((unsigned long)p[2]) << 8)
            | ((unsigned long)p[3])
            ;
    i->low =   (((unsigned long)p[4]) << 24)
            | (((unsigned long)p[5]) << 16)
            | (((unsigned long)p[6]) << 8)
            | ((unsigned long)p[7])
            ;
}

void
jk_java_get_long(
    jk_longlong_t * i,
    const unsigned char * p
    )
{
	jk_java_get_ulong(jk_cast(jk_ulonglong_t*)i, p);
}

long
jk_java_read_classfile(
    const jk_globals_t * globals,
    jk_java_classfile_t ** ppcf,
    const char * filepath
    )
{
	jk_function("jk_java_read_classfile");
    jk_java_classfile_t classfile;
    jk_file_t * file = &classfile.file;
    long err = -1;

	jk_unused(ppcf);
    
	jk_java_init_classfile(globals, &classfile);
	classfile.file.buffer.keep_all_bytes = 1;
	err = jk_file_open_for_read(globals, file, filepath);
    if (err < 0)
        goto exit;

	err = jk_file_read_ahead(globals, file, sizeof(jk_java_packed_classfile3_t));
    if (err < 0)
        goto exit;

    err =
        jk_file_read_and_unpack(
            globals,
            file,
            globals->java_packed_classfile1_type_info,
            sizeof(jk_java_packed_classfile1_t),
            (void*)&classfile,
            sizeof(classfile));
    if (err < 0)
        goto exit;
    
    err = jk_java_read_constant_pool(globals, &classfile);
    if (err < 0)
        goto exit;

    err =
        jk_file_read_and_unpack(
            globals,
            file,
            globals->java_packed_classfile2_type_info,
            sizeof(jk_java_packed_classfile2_t),
            (void*)&classfile,
            sizeof(classfile));
    if (err < 0)
        goto exit;

    jk_dump_struct(globals, jk_debug_string("classfile."), (void*)&classfile, globals->java_packed_classfile_type_info); 

    err = 0;
exit:
	if (err < 0)
		jk_printf("%s existing with %ld\n", function, err);
    return err;
}

long
jk_type_copy_n_copy_memory(const jk_type_t * type, void * to, const void * from, size_t n)
{
    jk_copy_memory(to, (void*)from, n * type->size);
    return 0;
}

long
jk_type_move_n_copy_memory(const jk_type_t * type, void * to, void * from, size_t n)
{
    jk_copy_memory(to, from, n * type->size);
    return 0;
}

long
jk_type_move_n_copy_memory_and_zero_memory(const jk_type_t * type, void * to, void * from, size_t n)
{
    size_t size = type->size;
    jk_copy_memory(to, from, n * size);
    jk_zero_memory(from, n * size);
    return 0;
}

long
jk_type_construct_n_zero_memory(const jk_type_t * type, void * p, size_t n)
{
    jk_zero_memory(p, n * type->size);
    return 0;
}

long
jk_type_construct_n_do_nothing(const jk_type_t * type, void * p, size_t n)
{
    jk_unused(type);
    jk_unused(p);
    jk_unused(&n);
    return 0;
}

long
jk_type_destroy_n_do_nothing(const jk_type_t * type, void * p, size_t n)
{
    jk_unused(type);
    jk_unused(p);
    jk_unused(&n);
    return 0;
}

long
jk_array_init(
    jk_array_t * array,
    const jk_type_t * element_type,
    jk_memory_allocator_t * allocator
    )
{
    array->element_type = element_type;
    array->allocator = allocator;
    array->elements = 0;
    array->size_allocated = 0;
    array->size_requested = 0;
    return 0;
}

long
jk_array_get_base(
    jk_array_t * array,
    void ** base
    )
{
    *base = array->elements;
    return 0;
}

long
jk_array_get_pointer_to_element_at(
    jk_array_t * array,
    size_t n,
    void ** pointer_to_element
    )
{
    *pointer_to_element = ((char*)array->elements) + n * array->element_type->size;
    return 0;
}

long
jk_array_get_size(
    jk_array_t * array,
    size_t * size
    )
{
    *size = array->size_requested;
    return 0;
}
 
long
jk_array_set_size( /* std::vector::resize() */
    jk_array_t * array,
    size_t new_size
    )
{
    size_t current_size;
    size_t diff;
    int i;
    
    current_size = array->size_requested;
    i = jk_integer_compare_tristate(new_size, current_size);
    switch (i)
    {
    case 0:
        return 0;
    case -1:
        diff = current_size - new_size;
        return 0;
    case 1:
        diff = new_size - current_size;
        return 0;
    }
    jk_assert(jk_false);
    return jk_error_unreachable;
}

#define jk_is_char_signed1 (CHAR_MAX == SCHAR_MAX)
#define jk_is_char_signed2 (CHAR_MAX != UCHAR_MAX)
#define jk_is_char_signed3 (CHAR_MIN == SCHAR_MIN)
#define jk_is_char_signed4 (CHAR_MIN != 0)
#define jk_is_char_signed5 (CHAR_MIN < 0)

#if    (jk_is_char_signed1 != jk_is_char_signed2) \
	|| (jk_is_char_signed1 != jk_is_char_signed3) \
	|| (jk_is_char_signed1 != jk_is_char_signed4) \
	|| (jk_is_char_signed1 != jk_is_char_signed5)
#error "is_char_signed?"
#endif
#define jk_is_char_signed jk_is_char_signed1

const jk_type_t jk_type_void = {
    0,
	jk_type_construct_n_do_nothing, jk_type_destroy_n_do_nothing,
	jk_type_copy_n_copy_memory, jk_type_move_n_copy_memory,
	jk_false,
	NULL, NULL
};

const jk_type_t jk_type_char = {
    sizeof(char),
	jk_type_construct_n_do_nothing, jk_type_destroy_n_do_nothing,
	jk_type_copy_n_copy_memory, jk_type_move_n_copy_memory,
	jk_is_char_signed
};

const jk_type_t jk_type_schar = {
    sizeof(signed char),
	jk_type_construct_n_do_nothing, jk_type_destroy_n_do_nothing,
	jk_type_copy_n_copy_memory, jk_type_move_n_copy_memory,
	jk_true
};

const jk_type_t jk_type_uchar = {
    sizeof(unsigned char),
	jk_type_construct_n_do_nothing, jk_type_destroy_n_do_nothing,
	jk_type_copy_n_copy_memory, jk_type_move_n_copy_memory,
	jk_false
};

const jk_type_t jk_type_short = {
    sizeof(short),
	jk_type_construct_n_do_nothing, jk_type_destroy_n_do_nothing,
	jk_type_copy_n_copy_memory, jk_type_move_n_copy_memory,
	jk_true
};

const jk_type_t jk_type_ushort = {
    sizeof(unsigned short),
	jk_type_construct_n_do_nothing, jk_type_destroy_n_do_nothing,
	jk_type_copy_n_copy_memory, jk_type_move_n_copy_memory,
	jk_false
};

const jk_type_t jk_type_int = {
    sizeof(int),
	jk_type_construct_n_do_nothing, jk_type_destroy_n_do_nothing,
	jk_type_copy_n_copy_memory, jk_type_move_n_copy_memory,
	jk_true,
	jk_type_get_dump_length_int, jk_type_dump_int
};

const jk_type_t jk_type_uint = {
    sizeof(unsigned int),
	jk_type_construct_n_do_nothing, jk_type_destroy_n_do_nothing,
	jk_type_copy_n_copy_memory, jk_type_move_n_copy_memory,
	jk_false,
	jk_type_get_dump_length_unsigned_int, jk_type_dump_unsigned_int
};

const jk_type_t jk_type_long = {
    sizeof(long),
	jk_type_construct_n_do_nothing, jk_type_destroy_n_do_nothing,
	jk_type_copy_n_copy_memory, jk_type_move_n_copy_memory,
	jk_true,
	jk_type_get_dump_length_long, jk_type_dump_long
};

const jk_type_t jk_type_ulong = {
    sizeof(unsigned long),
	jk_type_construct_n_do_nothing, jk_type_destroy_n_do_nothing,
	jk_type_copy_n_copy_memory, jk_type_move_n_copy_memory,
	jk_false,
	jk_type_get_dump_length_unsigned_long,
	jk_type_dump_unsigned_long
};

JK_ORCAC_SEGMENT

long
jk_array_get_allocated_size( /* std::vector::capacity() */
    jk_array_t * array,
    size_t * size
    )
 {
    *size = array->size_requested;
    return 0;
}

long
jk_array_ensure_allocated_size( /* std::vector::reserve() */
    jk_array_t * array,
    size_t new_size
    )
{
	long err = jk_error_uninitialized;
    void * new_bytes;
    const jk_memory_allocator_functions_t * memory_allocator_functions;
    jk_memory_allocator_t * memory_allocator;
    
    if (array->size_requested >= new_size)
    {
        return 0;
    }
    memory_allocator = array->allocator;
    memory_allocator_functions = memory_allocator->functions;
    err = memory_allocator_functions->allocate(memory_allocator, new_size, &new_bytes);
	if (err < 0)
		return err;
    return 0;
}
 
long
jk_array_add_last_element(/* std::vector::push_back() */
    jk_array_t * array,
    void * element
    );

long
jk_array_remove_last_element(/* std::vector::pop_back() */
    jk_array_t * array
    );

long
jk_array_get_first_element(/* std::vector::front() */
    jk_array_t * array,
    void **
    );

long
jk_array_get_last_element(/* std::vector::back() */
    jk_array_t * array,
    void ** last_element
    )
{
    jk_unused(array);
    jk_unused(last_element);
    return 0;
}

long
jk_array_set_element_at_index(
    jk_array_t * array,
    size_t n,
    void * element
    )
{
    jk_unused(array);
    jk_unused(&n);
    jk_unused(element);
    return 0;
}

long
jk_array_begin(
    jk_array_t * array,
    jk_array_iterator_t * iterator
    )
{
    iterator->array = array;
    iterator->index = 0;
    return 0;
}

long
jk_array_end(
    jk_array_t * array,
    jk_array_iterator_t * iterator
    )
{
    iterator->array = array;
    iterator->index = array->size_requested;
    return 0;
}

void
jk_assert_iterator_assert_is_valid(
    const jk_array_iterator_t * iterator
    )
{
    jk_assert(iterator != 0);
    jk_assert(iterator->array != 0);
    jk_assert(iterator->index <= iterator->array->size_requested);
}

long
jk_array_iterator_increment(
    jk_array_iterator_t * iterator
    )
{
    jk_assert_iterator_assert_is_valid(iterator);
    jk_assert(iterator->index < iterator->array->size_requested);
    iterator->index += 1;
    jk_assert_iterator_assert_is_valid(iterator);
    return 0;
}

long
jk_array_iterator_decrement(
    jk_array_iterator_t * iterator
    )
{
    jk_assert_iterator_assert_is_valid(iterator);
    jk_assert(iterator->index != 0);
    iterator->index -= 1;
    jk_assert_iterator_assert_is_valid(iterator);
    return 0;
}

long
jk_array_iterator_add_integer(
    jk_array_iterator_t * iterator,
    size_t n
    )
{
    jk_assert_iterator_assert_is_valid(iterator);
    iterator->index += n;
    jk_assert_iterator_assert_is_valid(iterator);
    return 0;
}

long
jk_array_iterator_subtract_integer(
    jk_array_iterator_t * iterator,
    size_t n
    )
{
    jk_assert_iterator_assert_is_valid(iterator);
    iterator->index -= n;
    jk_assert_iterator_assert_is_valid(iterator);
    return 0;
}

long
jk_array_iterator_subtract_iterator(
    jk_array_iterator_t * iterator,
    const jk_array_iterator_t * iterator_to_subtract
    )
{
    jk_assert_iterator_assert_is_valid(iterator);
    jk_assert(iterator->array == iterator_to_subtract->array);
    iterator->index -= iterator_to_subtract->index;
    jk_assert_iterator_assert_is_valid(iterator);
    return 0;
}
    
long
jk_array_iterator_dereference(
    jk_array_iterator_t * iterator,
    void ** element
    )
{
    jk_array_t * array;
    
    jk_assert_iterator_assert_is_valid(iterator);
    array = iterator->array;
    jk_assert(iterator->index < array->size_requested);
    *element = ((char*)array->elements) + (iterator->index * array->element_type->size);
    return 0;
}

long
jk_array_iterator_is_equal(
    const jk_array_iterator_t * iterator1,
    const jk_array_iterator_t * iterator2,
    jk_boolean_t * is_equal
    )
{
    jk_assert_iterator_assert_is_valid(iterator1);
    jk_assert(iterator1->array == iterator2->array);
    *is_equal = ((iterator1->array == iterator2->array && iterator1->index == iterator2->index) ? jk_true : jk_false);
    return 0;
}

const jk_type_t jk_type_struct = { 0 };
const jk_type_t jk_type_void_pointer = { 0 };

const jk_types_t jk_types = {
	&jk_type_void,
	&jk_type_char,
	&jk_type_schar,
	&jk_type_uchar,	
	&jk_type_short,
	&jk_type_ushort,
	&jk_type_int,
	&jk_type_uint,
	&jk_type_long,
	&jk_type_ulong
};

const jk_globals_t jk_globals = {
    &jk_fields,
    &jk_types,
    &jk_profile_count_function_calls,
    &jk_profile_name_functions[0],
    jk_number_of(jk_profile_name_functions),
    &jk_java_classfile_type_info,
    &jk_java_classfile1_type_info,
    &jk_java_classfile2_type_info
};

long
jk_buffer_init(
	jk_buffer_t * buffer,
	size_t preallocated_buffer_size,
	void * preallocated_buffer
	)
{
	buffer->allocator = &jk_default_memory_allocator;
	buffer->bytes = NULL;
	buffer->allocated_size = 0;
	buffer->requested_size = 0;
	buffer->static_buffer = preallocated_buffer;
	buffer->static_size = preallocated_buffer_size;
	return 0;
}
	
void
jk_buffer_free(
	jk_buffer_t * buffer
	)
{
	void * static_buffer;
	void * bytes;
	jk_memory_allocator_t * allocator;
	
	bytes = buffer->bytes;
	static_buffer = buffer->static_buffer;
	
	if (bytes != NULL && bytes != static_buffer)
	{
		allocator = buffer->allocator;
		(*allocator->functions->free)(allocator, &bytes);
	}
	jk_buffer_init(buffer, buffer->static_size, static_buffer);
}

long
jk_buffer_set_size(
	jk_buffer_t * buffer,
	size_t size,
	void ** pointer /* optional */
	)
{
	long err = jk_error_uninitialized;
	size_t allocated_size = jk_sizet_uninitialized;
	size_t static_size = jk_sizet_uninitialized;
	void * bytes = jk_pointer_uninitialized;
    jk_memory_allocator_t * allocator = (jk_memory_allocator_t *)jk_pointer_uninitialized;
    jk_memory_allocator_functions_allocate_t allocate = (jk_memory_allocator_functions_allocate_t)jk_pointer_uninitialized;
	
	allocated_size = buffer->allocated_size;
	if (allocated_size >= size
		|| buffer->requested_size >= size
		)
	{
		bytes = buffer->bytes;
		goto success;
	}
	static_size = buffer->static_size;
	if (static_size >= size)
	{
		bytes = buffer->static_buffer;
		allocated_size = static_size;
		goto success;
	}
	allocated_size *= 2;
	if (allocated_size < size)
	{
		allocated_size = size;
	}
	allocator = buffer->allocator;
	allocate = allocator->functions->allocate;
	err = (*allocate)(allocator, allocated_size, &bytes);
	if (err < 0 && allocated_size > size)
	{
		allocated_size = size;
		err = (*allocate)(allocator, allocated_size, &bytes);
	}
	if (err < 0)
	{
		goto exit;
	}
success:
	buffer->allocated_size = allocated_size;
	buffer->requested_size = size;
	buffer->bytes = bytes;
	if (pointer != NULL)
		*pointer = bytes;
	err = 0;
exit:
	return err;
}

JK_EXTERN_C_END

int main(int argc, char ** argv)
{    
	const jk_globals_t * globals = &jk_globals;

	jk_init_fields();
	jk_init_classfile_type_info();

    if (argc > 1 && argv && argv[1])
    {
    	jk_java_read_classfile(globals, 0, argv[1]);
    	jk_profile_dump_function_call_counts(globals);
}
	return -1;
}
