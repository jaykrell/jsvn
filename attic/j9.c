#include "j3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

JK_EXTERN_C_BEGIN

const static char sourcefile[] = "j9.c";

const long jk_out_of_memory_error = -__LINE__;

void
jk_profile_dump_function_call_counts(
    void
    );

void jk_unused(
    void *
    );

long
jk_malloc(
	void ** pp,
	unsigned n
	);

void
jk_free(
	void ** pp
	);

void
jk_unused(
    void * x
    )
{
    x = x;
}

long
jk_malloc(
	void ** pp,
	unsigned n
	)
{
	void * p;
	
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
	*pp = 0;
	free(p);
}

#if defined(_MSC_VER) /* Visual C++ */

#define jk_format_file_line "%s(%u):"

#else /* MPW */

#define jk_format_file_line "file %s; line %u #"

#endif

typedef struct jk_seven_bit_constant_string_t {
    const char * chars;   /* not necessarily nul terminated */
    unsigned length; /* in chars, not counting optional terminal nul */
} jk_seven_bit_constant_string_t;

#define jk_make_seven_bit_constant_string(s) { s, sizeof(s) - sizeof((s)[0]) }

typedef struct jk_profile_count_function_calls_map_entry_t {
    jk_seven_bit_constant_string_t name;
    unsigned offset;
} jk_profile_count_function_calls_map_entry_t;

typedef struct jk_profile_count_function_calls_t
{
    unsigned jkp_file_read_direct;
	unsigned jk_compute_packed_size;
	unsigned jk_compute_unpacked_size;
	unsigned jk_compute_packed_or_unpacked_size;
	unsigned jk_file_read_and_unpack;
} jk_profile_count_function_calls_t;

const jk_profile_count_function_calls_map_entry_t jk_profile_count_function_calls_map[] =
{
    { jk_make_seven_bit_constant_string("jkp_file_read_direct"), jk_offsetof_field(jk_profile_count_function_calls_t, jkp_file_read_direct) },
    { jk_make_seven_bit_constant_string("jk_compute_packed_size"), jk_offsetof_field(jk_profile_count_function_calls_t, jk_compute_packed_size) },
    { jk_make_seven_bit_constant_string("jk_compute_unpacked_size"), jk_offsetof_field(jk_profile_count_function_calls_t, jk_compute_unpacked_size) },
    { jk_make_seven_bit_constant_string("jk_compute_packed_or_unpacked_size"), jk_offsetof_field(jk_profile_count_function_calls_t, jk_compute_packed_or_unpacked_size) },
    { jk_make_seven_bit_constant_string("jk_file_read_and_unpack"), jk_offsetof_field(jk_profile_count_function_calls_t, jk_file_read_and_unpack) },
};

jk_profile_count_function_calls_t jk_profile_count_function_calls;

#define jk_profile_count_function_call(function_name) \
    jk_profile_count_function_calls.function_name += 1

void
jk_profile_dump_function_call_counts(
    void
    )
{
    size_t i = 0;
    size_t longest_name_length = 0;
    jk_profile_count_function_calls_map_entry_t const * const map = &jk_profile_count_function_calls_map[0];
    jk_profile_count_function_calls_t const * count = &jk_profile_count_function_calls;
    const size_t n = jk_number_of(jk_profile_count_function_calls_map);

    for ( i = 0 ; i != n ; ++i)
    {
        size_t name_length = map[i].name.length;
        if (name_length > longest_name_length)
        {
            longest_name_length = name_length;
        }
    }

    for ( i = 0 ; i != n ; ++i)
    {
	    jk_printf("%-*s %u\n", longest_name_length, map[i].name.chars, *(unsigned*)(((const char*)count) + map[i].offset));
    }
}

struct jk_memory_allocator_functions_t
{
    long (*allocate)(struct jk_memory_allocator_functions_t *, unsigned long number_of_bytes, void ** p);
    void (*free)(struct jk_memory_allocator_functions_t *, void ** p);
};

struct jk_memory_allocator_t
{
    jk_memory_allocator_functions_t const * functions;
};

long
jk_default_memory_allocator_allocate(
    jk_memory_allocator_functions_t * state,
    unsigned long number_of_bytes,
    void ** pp
    )
{
	void * p;
	
	jk_unused(state);
    
    *pp = 0;
    p = malloc(number_of_bytes);
    *pp = p;
    return ((p != NULL) ? 0 : jk_out_of_memory_error);
}

void
jk_default_memory_allocator_free(
    jk_memory_allocator_functions_t * state,
    void ** pp
    )
{
    void * p;

	jk_unused(state);
    
    p = *pp;
    *pp = 0;
    free(p);
}

const jk_memory_allocator_functions_t
jk_default_memory_allocator_functions =
{
    jk_default_memory_allocator_allocate,
    jk_default_memory_allocator_free
};

const jk_memory_allocator_t
jk_default_memory_allocator = { &jk_default_memory_allocator_functions };

JK_EXTERN_CONST jk_pack_spec1_t jk_java_classfile_pack_specs1[] =
{
    jk_make_pack_spec(jk_java_packed_classfile1_t, jk_java_classfile_t, magic, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile1_t, jk_java_classfile_t, minor_version, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile1_t, jk_java_classfile_t, major_version, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile1_t, jk_java_classfile_t, constant_pool_count, jk_endian_big),
};

jk_pack_specn_t jk_java_classfile_pack_spec1 =
{
    jk_endian_big,
    jk_number_of(jk_java_classfile_pack_specs1),
    jk_java_classfile_pack_specs1
};

JK_EXTERN_CONST jk_pack_spec1_t jk_java_classfile_pack_specs2[] =
{
    jk_make_pack_spec(jk_java_packed_classfile2_t, jk_java_classfile_t, access_flags, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile2_t, jk_java_classfile_t, this_class, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile2_t, jk_java_classfile_t, super_class, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile2_t, jk_java_classfile_t, interfaces_count, jk_endian_big),
};

jk_pack_specn_t jk_java_classfile_pack_spec2 =
{
    jk_endian_big,
    jk_number_of(jk_java_classfile_pack_specs2),
    jk_java_classfile_pack_specs2
};

JK_EXTERN_CONST jk_pack_spec1_t jk_java_classfile_pack_specs3[] =
{
    jk_make_pack_spec(jk_java_packed_classfile3_t, jk_java_classfile_t, magic, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile3_t, jk_java_classfile_t, minor_version, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile3_t, jk_java_classfile_t, major_version, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile3_t, jk_java_classfile_t, constant_pool_count, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile3_t, jk_java_classfile_t, access_flags, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile3_t, jk_java_classfile_t, this_class, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile3_t, jk_java_classfile_t, super_class, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile3_t, jk_java_classfile_t, interfaces_count, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile3_t, jk_java_classfile_t, fields_count, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile3_t, jk_java_classfile_t, methods_count, jk_endian_big),
    jk_make_pack_spec(jk_java_packed_classfile3_t, jk_java_classfile_t, attributes_count, jk_endian_big),
};

jk_pack_specn_t jk_java_classfile_pack_spec3 =
{
    jk_endian_big,
    jk_number_of(jk_java_classfile_pack_specs3),
    jk_java_classfile_pack_specs3
};

void
jk_reverse_memory(
    unsigned char * p,
    unsigned count
    )
{
    unsigned char * q = (p + count);
    while (p < q)
    {
    	*p++ = *--q;
    }
}

void
jk_move_memory(
    void * to,
    const void * from,
    unsigned count
    )
{
    memmove(to, from, count);
}

void
jk_copy_memory(
    void * to,
    const void * from,
    unsigned count
    )
{
    memcpy(to, from, count);
}

void
jk_copy_memory_unsigned_char(
    unsigned char * to,
    const unsigned char * from,
    unsigned count
    )
{
    memcpy(to, from, count);
}


void
jk_copy_memory_reverse(
    unsigned char * to,
    const unsigned char * from,
    unsigned count
    )
{
    while (count != 0)
    {
    	*to++ = from[--count];
    }
}

void
jk_zero_memory(
    void * p,
    unsigned n
    )
{
    memset(p, 0, n);
}

void
jk_printf(
	const char * format,
	...
	)
{
	va_list args;
	
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

long
jk_unpack(
    unsigned endian,
    const void * vpacked_buffer,
    void * vunpacked_buffer,
    const jk_pack_spec1_t * specs,
    unsigned n
    )
{
    long err = -1;
    unsigned i = 0;
    const unsigned char * packed_buffer = (const unsigned char *)vpacked_buffer;
    unsigned char * unpacked_buffer = (unsigned char*)vunpacked_buffer;
    union {
    	unsigned long i;
    	unsigned char c[sizeof(unsigned long)];
    } uhost_endian = { 1 };
    unsigned host_endian = uhost_endian.c[0];
    unsigned endian_factor = (host_endian << 1) | endian;
    unsigned sign_byte_index = 0;
    void (*copy)(unsigned char *, const unsigned char *, unsigned) = 0;

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

    for (i = 0 ; i != n ; ++i)
    {
    	const jk_pack_spec1_t spec = specs[i];
    	unsigned char const * const packed_field = packed_buffer + spec.packed_offset;
    	unsigned char * const unpacked_field = unpacked_buffer + spec.unpacked_offset;
    	unsigned number_of_bytes_to_copy = 0;
    	unsigned number_of_packed_bytes_to_skip = 0;
    	unsigned number_of_unpacked_bytes_to_skip = 0;

    	if (spec.unpacked_size == spec.packed_size)
    	{
    		number_of_bytes_to_copy = spec.packed_size;
    		number_of_packed_bytes_to_skip = 0;
    		number_of_unpacked_bytes_to_skip = 0;
    	}
    	else if (spec.unpacked_size > spec.packed_size)
    	{
    		memset(
    			unpacked_field,
    			(spec.is_signed && (packed_field[sign_byte_index ? (spec.packed_size - 1) : 0]) & 0x80) ? spec.is_signed : 0,
    			spec.unpacked_size
    			);
    		number_of_bytes_to_copy = spec.packed_size;
    		number_of_packed_bytes_to_skip = 0;
    		if (host_endian == jk_endian_big)
    			number_of_unpacked_bytes_to_skip = (spec.unpacked_size - number_of_bytes_to_copy);
    		else
    			number_of_unpacked_bytes_to_skip = 0;
    	}
    	else /* spec.unpacked_size < spec.packed_size */
    	{
    		number_of_bytes_to_copy = spec.unpacked_size;
    		number_of_unpacked_bytes_to_skip = 0;
    		if (endian == jk_endian_big)
    			number_of_packed_bytes_to_skip = (spec.packed_size - number_of_bytes_to_copy);
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
jk_compute_packed_or_unpacked_size(
    jk_pack_specn_t * p,
    unsigned packed_or_unpacked
    )
{
    long err = -1;
	
	jk_profile_count_function_call(jk_compute_packed_or_unpacked_size);
	
    if ((packed_or_unpacked ? p->packed_size : p->unpacked_size) == 0)
    {
    	unsigned max = 0;
    	unsigned n = p->number_of_elements;
    	const jk_pack_spec1_t * specs = p->elements;
    	for ( ; n != 0 ; ++specs , --n )
    	{
    		unsigned i = 
    			(packed_or_unpacked ? (specs->packed_size + specs->packed_offset)
    							    : (specs->unpacked_size + specs->unpacked_offset));
    		if (i > max)
    		{
    			max = i;
    		}
    	}
    	packed_or_unpacked ? (p->packed_size = max) : (p->unpacked_size = max);
    }
    err = 0;
    return err;
}

long
jk_compute_packed_size(jk_pack_specn_t * p)
{
	jk_profile_count_function_call(jk_compute_packed_size);
	
    return jk_compute_packed_or_unpacked_size(p, 1);
}

long
jk_compute_unpacked_size(
    jk_pack_specn_t * p
    )
{
	jk_profile_count_function_call(jk_compute_unpacked_size);

    return jk_compute_packed_or_unpacked_size(p, 0);
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
    jk_file_t * file,
    const char * file_path
    )
{
	const static char function[] = "jk_file_open_for_read";
    long err = -1;
    const char * openmode = "rb";

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
    jk_file_t * file
    )
{
    
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
    unsigned bytes_to_read,
    unsigned * bytes_read /* optional */
    )
{
	const static char function[] = "jkp_file_read_direct";
	size_t n;
	
	jk_profile_count_function_call(jkp_file_read_direct);
	
    n = fread(buffer, 1, bytes_to_read, (FILE*)file->stdio_file);
    if (bytes_read != 0)
    {
    	*bytes_read = (unsigned)n;
    }
	#if 1
	jk_printf(jk_format_file_line "%s bytes_to_read /* %u */ /* %u */\n", sourcefile, (unsigned)__LINE__, function, bytes_to_read, (unsigned)n);
	#endif
    return 0;
}

long
jk_file_read_and_unpack(
    jk_file_t * file,
    jk_pack_specn_t * spec,
    unsigned packed_buffer_size,
    void * unpacked_buffer,
    unsigned unpacked_buffer_size
    )
{
	const static char function[] = "jk_file_read_and_unpack";
    long err = -1;
    unsigned bytes_read = 0;
    void * packed_buffer = 0;

	jk_profile_count_function_call(jk_file_read_and_unpack);

    err = jk_compute_packed_size(spec);
    if (err < 0) goto exit;
    err = jk_compute_unpacked_size(spec);
    if (err < 0) goto exit;
    if (spec->packed_size > packed_buffer_size)
    	err = -__LINE__;
    else if (spec->unpacked_size > unpacked_buffer_size)
    	err = -__LINE__;
    if (err < 0) goto exit;
    err = jk_file_read_get_buffer(file, &packed_buffer, spec->packed_size, &bytes_read);
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
    err = jk_unpack(spec->endian, packed_buffer, unpacked_buffer, spec->elements, spec->number_of_elements);
    if (err < 0) goto exit;	
    
    err= 0;
exit:
	if (err < 0)
		jk_printf(jk_format_file_line "%s exiting with %ld\n", sourcefile, -err, function, err);
    return err;
}

long
jk_dump_struct(
    const char * prefix,
    const void * vbase,
    const jk_dump_struct_t * desc
    )
{
    const char * base = (const char*)vbase;
    int name_length = 0;
    int maximum_name_length = 0;
    unsigned i = 0;
    const jk_dump_field_t * field = 0;
    unsigned u = 0;

    for ( i = 0 ; i != desc->number_of_fields ; ++i )
    {
    	field = &desc->fields[i];
    	name_length = (int)strlen(field->name);
    	if (name_length > maximum_name_length)
    		maximum_name_length = name_length;
    }
    for ( i = 0 ; i != desc->number_of_fields ; ++i )
    {
    	field = &desc->fields[i];
    	u = *(unsigned*)(base + field->offset);
    	if (u >= 16)
    		jk_printf("%s%-*s %u (0x%x)\n", prefix, maximum_name_length, field->name, u, u);
    	else
    		jk_printf("%s%-*s %u\n", prefix, maximum_name_length, field->name, u);
    }
    return 0;
}

const jk_dump_field_t jk_dump_java_classfile_fields[] =
{
#define X(x) { jk_offsetof(jk_java_classfile_t, x), #x },
    X(minor_version)
    X(major_version)
    X(constant_pool_count)
#undef X
};

const jk_dump_struct_t jk_dump_java_classfile_struct =
{
    jk_number_of(jk_dump_java_classfile_fields),
    jk_dump_java_classfile_fields
};

long
jk_file_read_ahead(
    jk_file_t * file,
    unsigned n
    )
{
    file->buffer.read_ahead += n;
    return 0;
}

long
jk_file_read_copy(
    jk_file_t * file,
    void * buffer,
    unsigned bytes_to_read,
    unsigned * bytes_read
    )
{
    void * my_buffer = 0;
    long err = 0;

    err = jk_file_read_get_buffer(file, &my_buffer, bytes_to_read, bytes_read);
    if (err < 0) goto exit;
    jk_copy_memory(buffer, my_buffer, *bytes_read);
    err = 0;
exit:
    return err;
}

long
jk_file_read_get_buffer(
    jk_file_t * file,
    void ** out_buffer,
    unsigned bytes_to_read,
    unsigned * out_bytes_read /* optional */
    )
{
	const static char function[] = "jk_file_read_get_buffer";
    long err = -1;
    char * new_buffer = 0;
    unsigned new_buffer_size = 0;
    unsigned keep_all_bytes = 0;
    unsigned buffer_size = 0;
    unsigned bytes_to_read_plus_read_ahead = 0;
    unsigned bytes_read = 0;
    unsigned bytes_in_buffer = 0;
    unsigned position = 0;
    char * buffer = 0;

	/*
	printf(jk_format_file_line "\n", sourcefile, (unsigned)__LINE__);
	*/
	
    bytes_in_buffer = file->buffer.bytes_in_buffer;
    position = file->buffer.position;
    buffer = file->buffer.buffer;

    /* fast path -- there are enough bytes */
    if (bytes_to_read <= (bytes_in_buffer - position))
    {
		#if 0
		printf(jk_format_file_line "%u %p \n", sourcefile, (unsigned)__LINE__, (unsigned)bytes_to_read, out_bytes_read);
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
	printf(jk_format_file_line "\n", sourcefile, (unsigned)__LINE__);
	*/

    buffer_size = file->buffer.buffer_size;
    keep_all_bytes = file->buffer.keep_all_bytes;
    
	#if 1
	printf(jk_format_file_line "read_ahead %u\n", sourcefile, (unsigned)__LINE__, (unsigned)file->buffer.read_ahead);
	#endif
    bytes_to_read_plus_read_ahead = bytes_to_read + file->buffer.read_ahead;
    file->buffer.read_ahead = 0;

    /* slow path -- there are not enough bytes */
    new_buffer_size = jk_max(buffer_size, bytes_to_read_plus_read_ahead);
    if (keep_all_bytes)
    {
    	new_buffer_size += buffer_size;
    }

	/*
	printf(jk_format_file_line "\n", sourcefile, (unsigned)__LINE__);
	*/
    if (new_buffer_size > buffer_size)
    {
		/*
		printf(jk_format_file_line "\n", sourcefile, (unsigned)__LINE__);
		*/
    	new_buffer_size = jk_align_integer(new_buffer_size);
    	new_buffer  = (char*)malloc(new_buffer_size);
    	if (new_buffer == 0)
    	{
    		err = -__LINE__;
    		goto exit;
    	}
    	if (keep_all_bytes)
    	{
    		jk_copy_memory(new_buffer, buffer, bytes_in_buffer);
    	}
    	free(buffer);
    	file->buffer.buffer = new_buffer;
    	buffer = new_buffer;
    	new_buffer = 0;
    	file->buffer.buffer_size = new_buffer_size;
    	buffer_size = new_buffer_size;
    }
	/*
	printf(jk_format_file_line "\n", sourcefile, (unsigned)__LINE__);
	*/
    if (!keep_all_bytes && (buffer_size - bytes_in_buffer) < bytes_to_read)
    {
    	jk_move_memory(buffer, buffer + position, bytes_in_buffer - position);
    	file->buffer.position = 0;
    	position = 0;
    }
    err = jkp_file_read_direct(file, buffer + position, buffer_size - bytes_in_buffer, &bytes_read);
    if (err < 0) goto exit;
    file->buffer.bytes_in_buffer += bytes_read;
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
    if (new_buffer)
    {
    	free(new_buffer);
    }
	if (err < 0)
	{
		jk_printf("%s exiting with %ld\n", function, err);
	}
    return err;
}

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

JK_EXTERN_CONST float jk_java_positive_infinity_float = (1.0f / 0.0f);
JK_EXTERN_CONST float jk_java_negative_infinity_float = -(1.0f / 0.0f);
JK_EXTERN_CONST double jk_java_positive_infinity_double = (1.0 / 0.0);
JK_EXTERN_CONST double jk_java_negative_infinity_double = -(1.0 / 0.0);
JK_EXTERN_CONST float jk_java_nan_float = (0.0f / 0.0f);
JK_EXTERN_CONST double jk_java_nan_double = (0.0 / 0.0);

jk_ulonglong_t
jk_longlong_to_ulonglong(jk_longlong_t a)
{
    jk_ulonglong_t b;
    b.low = a.low;
    b.high = (unsigned long)a.high;
    return b;
}

jk_ulonglong_t*
jk_longlong_to_ulonglong_pointer(jk_longlong_t * a)
{
    return (jk_ulonglong_t*)a;
}

void
jk_long_add_with_carry_in(long * a, long b, long c, unsigned carry)
{
    *a = b + c + (carry ? 1 : 0);
}

void
jk_long_add_in_place_with_carry_in(long * a, long b, unsigned carry)
{
    *a += b + (carry ? 1 : 0);
}

void
jk_long_add_with_carry_out(long * a, long b, long c, unsigned * carry)
{
    long aa = b + c;
    *a = aa;
    *carry = ((aa < 0) != (b < 0)) && ((aa < 0) != (c < 0));
}

void
jk_long_add_in_place_with_carry_out(long * a, long b, unsigned * carry)
{
    jk_long_add_with_carry_out(a, *a, b, carry);
}

void
jk_long_add_with_carry_in_and_out(long * a, long b, long c, unsigned * carry)
{
    long aa;
    unsigned asign;
    
    aa = b + c + (*carry ? 1 : 0);
    asign = (aa < 0);
    *a = aa;
    
    *carry = (asign != (b < 0)) && (asign != (c < 0));
}

void
jk_long_add_in_place_with_carry_in_and_out(long * a, long b, unsigned * carry)
{
    jk_long_add_with_carry_in_and_out(a, *a, b, carry);
}

void
jk_ulong_add_with_carry_in(unsigned long * a, unsigned long b, unsigned long c, unsigned carry)
{
    *a = (b + c + carry);
}

void
jk_ulong_add_in_place_with_carry_in(unsigned long * a, unsigned long b, unsigned carry)
{
    *a += (b + carry);
}

void
jk_ulong_add_with_carry_out(unsigned long * a, unsigned long b, unsigned long c, unsigned * carry)
{
    unsigned long aa = b + c;
    *a = aa;
    *carry = ((aa < b) || (aa < c));
}

void
jk_ulong_add_with_carry_in_and_out(unsigned long * a, unsigned long b, unsigned long c, unsigned * carry)
{
    unsigned long aa = b + c + *carry;
    *a = aa;
    *carry = ((aa < b) || (aa < c));
}

void
jk_ulong_add_in_place_with_carry_in_and_out(unsigned long * a, unsigned long b, unsigned * carry)
{
    jk_ulong_add_with_carry_in_and_out(a, *a, b, carry);
}

struct jk_multiprecisioninteger_t
{
    unsigned long * malloced_value_array;
    unsigned long built_in_value_array[4];
    signed int sign : 1; /* -1, +1 */
    unsigned is_precision_fixed  : 1;
    unsigned precision : 13; /* number of unsigned longs */
};

unsigned long *
jk_multipleprecision_integer_get_value(
    jk_multiprecisioninteger_t * m
    )
{
    return ((m->malloced_value_array != NULL) ? m->malloced_value_array : m->built_in_value_array);
}
    
void
jk_multiprecision_integer_from_long(
    jk_multiprecisioninteger_t * m,
    long i
    )
{    
    free(m->malloced_value_array);
    m->malloced_value_array = NULL;

    m->precision = 1;
    if (i >= 0)
    {
        m->sign = +1;
        m->built_in_value_array[0] = (unsigned long)i;
    }
    else
    {
        m->sign = -1;
        m->built_in_value_array[0] = ((unsigned long)-(i + 1)) - 1;
    }
}

void
jk_multiprecision_integer_from_ulong(
    jk_multiprecisioninteger_t * m,
    unsigned long i
    )
{
    free(m->malloced_value_array);
    m->malloced_value_array = NULL;
    
    m->sign = +1;
    m->precision = 1;
    m->built_in_value_array[0] = i;
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
jk_longlong_add(jk_longlong_t * a, jk_longlong_t b, jk_longlong_t c)
{
    unsigned carry = 0;

    jk_ulong_add_with_carry_out(&a->low, b.low, c.low, &carry);
    jk_long_add_with_carry_in(&a->high, b.high, c.high, carry);
}

void
jk_longlong_add_in_place(jk_longlong_t * a, jk_longlong_t b)
{
    jk_longlong_add(a, *a, b);
}

void
jk_ulonglong_add(jk_ulonglong_t * a, jk_ulonglong_t b, jk_ulonglong_t c)
{
    unsigned carry = 0;

    jk_ulong_add_with_carry_out(&a->low, b.low, c.low, &carry);
    jk_ulong_add_with_carry_in(&a->high, b.high, c.high, carry);
}

void
jk_ulonglong_add_in_place(jk_ulonglong_t * a, jk_ulonglong_t b)
{
    jk_ulonglong_t c;
    
    c = *a;
    jk_ulonglong_add(a, b, c);
}

void
jk_add_ulong_to_ulonglong(
    jk_ulonglong_t * a,
    jk_ulonglong_t c,
    unsigned long b
    )
{
    unsigned carry;

    jk_ulong_add_with_carry_out(&a->low, b, c.low, &carry);
    a->high += carry;
}

void
jk_add_ulong_to_ulonglong_in_place(
    jk_ulonglong_t * a,
    unsigned long b
    )
{
    unsigned carry;

    jk_ulong_add_with_carry_out(&a->low, a->low, b, &carry);
    a->high += carry;
}

void
jk_longlong_from_long(jk_longlong_t * a, long b)
{
    a->low = (unsigned long)b;
    a->high = (b < 0) ? -1 : +1;
}

void
jk_longlong_from_ulong(jk_longlong_t * a, unsigned long b)
{
    a->low = b;
    a->high = 0;
}

void
jk_ulonglong_from_ulong(jk_ulonglong_t * a, unsigned long b)
{
    a->low = b;
    a->high = 0;
}

void
jk_ulonglong_bitwise_and(jk_ulonglong_t * a, jk_ulonglong_t b, jk_ulonglong_t c)
{
    a->low = (b.low & c.low);
    a->high = (b.high & c.high);
}

void
jk_ulonglong_bitwise_or(jk_ulonglong_t * a, jk_ulonglong_t b, jk_ulonglong_t c)
{
    a->low = (b.low | c.low);
    a->high = (b.high | c.high);
}

void
jk_longlong_bitwise_and(jk_longlong_t * a, jk_longlong_t b, jk_longlong_t c)
{
    a->high = (b.high & c.high);
    a->low = (b.low & b.low);
}

void
jk_longlong_bitwise_or(jk_longlong_t * a, jk_longlong_t b, jk_longlong_t c)
{
    a->high = (b.high | c.high);
    a->low = (b.low | b.low);
}

unsigned
jk_ulonglong_to_boolean(jk_ulonglong_t a)
{
     return (a.high != 0 || a.low != 0);
}

unsigned
jk_longlong_to_boolean(jk_longlong_t a)
{
    return (a.high != 0 || a.low != 0);
}

unsigned
jk_ulonglong_logical_and(jk_ulonglong_t a, jk_ulonglong_t b)
{
    return jk_ulonglong_to_boolean(a) && jk_ulonglong_to_boolean(b);
}

unsigned
jk_ulonglong_logical_or(jk_ulonglong_t a, jk_ulonglong_t b)
{
    return jk_ulonglong_to_boolean(a) || jk_ulonglong_to_boolean(b);
}

unsigned
jk_longlong_logical_and(jk_longlong_t a, jk_longlong_t b)
{
    return jk_ulonglong_logical_and(jk_longlong_to_ulonglong(a), jk_longlong_to_ulonglong(b));
}

unsigned
jk_longlong_logical_or(jk_longlong_t a, jk_longlong_t b)
{
    return jk_ulonglong_logical_or(jk_longlong_to_ulonglong(a), jk_longlong_to_ulonglong(b));
}

void
jk_ulonglong_bitwise_not(jk_ulonglong_t * a, jk_ulonglong_t b)
{
    a->low = ~b.low;
    a->high = ~b.high;
}

void
jk_ulonglong_bitwise_exclusive_or(jk_ulonglong_t * a, jk_ulonglong_t b, jk_ulonglong_t c)
{
    a->low = (b.low ^ c.low);
    a->high = (b.high ^ c.high);
}

void
jk_longlong_bitwise_exclusive_or(jk_longlong_t * a, jk_longlong_t b, jk_longlong_t c)
{
    a->low = (b.low ^ c.low);
    a->high = (b.high ^ c.high);
}

void
jk_ulonglong_bitwise_invert_in_place(jk_ulonglong_t * a)
{
    a->low ^= ~0UL;
    a->high ^=  ~0UL;
}

void
jk_longlong_bitwise_invert_in_place(jk_longlong_t * a)
{
    a->low ^= ~0L;
    a->high ^= ~0UL;
}

unsigned
jk_ulonglong_logical_not(jk_ulonglong_t a)
{
    return (a.high == 0 && a.low == 0);
}

unsigned
jk_longlong_logical_not(jk_longlong_t a)
{
    return (a.high == 0 && a.low == 0);
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
jk_ulonglong_left_shift(jk_ulonglong_t * a, jk_ulonglong_t b, unsigned shift)
{
	const unsigned k = jk_bits_of(unsigned long);
	const unsigned k2 = (k * 2);
    if (shift >= k2)
    {
    	a->low = 0;
    	a->high = 0;
    }
    else if (shift >= k)
    {
    	a->low = 0;
    	a->high = (b.low << (shift - k));
    }
    else
    {        
        unsigned long aa = b.low;
    	a->low = (aa << shift);
        a->high = (b.high << shift) | jk_ulong_extract_left_n_bits_right_aligned(aa, shift);
    }
}

void
jk_ulonglong_left_shift_in_place(jk_ulonglong_t * a, unsigned shift)
{
    jk_ulonglong_t b = *a;
    jk_ulonglong_left_shift(a, b, shift);
}

void
jk_longlong_left_shift(jk_longlong_t * a, jk_longlong_t b, unsigned shift)
{
    jk_ulonglong_left_shift(jk_longlong_to_ulonglong_pointer(a), jk_longlong_to_ulonglong(b), shift);
}

void
jk_ulonglong_right_shift(jk_ulonglong_t * a, jk_ulonglong_t b, unsigned shift)
{
	const unsigned k = jk_bits_of(unsigned long);
	const unsigned k2 = (k * 2);
    if (shift >= k2)
    {
        a->low = 0;
        a->high = 0;
    }
    else if (shift >= k)
    {
        a->high = 0;
        a->low = (b.high >> (shift - k));
    }
    else
    {
        unsigned long aa = b.high;
        a->high = (aa >> shift);
        a->low = (b.low >> shift) | jk_ulong_extract_right_n_bits_left_aligned(aa, shift);
    }
}

long
jk_long_one_fill_right_shift(long a, unsigned shift)
{
	return (a >> shift) | jk_long_with_n_left_bits_set(shift);
}

long
jk_long_zero_fill_right_shift(long a, unsigned shift)
{
	return (long)(((unsigned long)a) >> shift);
}

long
jk_long_sign_fill_right_shift(long a, unsigned shift)
{
	return ((a < 0) ? jk_long_one_fill_right_shift : jk_long_zero_fill_right_shift)(a, shift);
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
jk_ulong_rotate_left(unsigned long a, unsigned b)
{
	const unsigned k = jk_bits_of(unsigned long);

	return (a << b) | (a >> (k - b));
}

unsigned long
jk_ulong_rotate_right(unsigned long a, unsigned b)
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
jk_ulonglong_zero_fill_right_shift(jk_ulonglong_t * a, jk_ulonglong_t b, unsigned shift)
{
	const unsigned k = jk_bits_of(unsigned long);
	const unsigned k2 = (k * 2);
    if (shift >= k2)
    {
        a->low = 0UL;
        a->high = 0UL;
    }
    else if (shift >= k)
    {
        a->high = 0UL;
        a->low = jk_ulong_zero_fill_right_shift(b.high, shift - k);
    }
    else
    {
        unsigned long aa = b.high;
        a->high = (aa >> shift);
        a->low =  (b.low >> shift);
    }
}

void
jk_ulonglong_one_fill_right_shift(jk_ulonglong_t * a, jk_ulonglong_t b, unsigned shift)
{
	const unsigned k = jk_bits_of(unsigned long);
	const unsigned k2 = (k * 2);
    if (shift >= k2)
    {
        a->low = ~0UL;
        a->high = ~0UL;
    }
    else if (shift >= k)
    {
        a->high = ~0UL;
        a->low = jk_ulong_one_fill_right_shift(b.high, shift - k);
    }
    else
    {
        unsigned long aa = b.high;
        a->high = (aa >> shift) | ~(~0UL >> shift);
        a->low =  (b.low >> shift) | (aa << (k - shift));
    }
}

void
jk_longlong_one_fill_right_shift(jk_longlong_t * a, jk_longlong_t b, unsigned shift)
{
	jk_ulonglong_one_fill_right_shift(
		jk_longlong_to_ulonglong_pointer(a),
		jk_longlong_to_ulonglong(b),
		shift);
}

void
jk_longlong_zero_fill_right_shift(jk_longlong_t * a, jk_longlong_t b, unsigned shift)
{
	jk_ulonglong_zero_fill_right_shift(
		jk_longlong_to_ulonglong_pointer(a),
		jk_longlong_to_ulonglong(b),
		shift);
}

void
jk_longlong_sign_fill_right_shift(jk_longlong_t * a, jk_longlong_t b, unsigned shift)
{
	((b.high < 0) ? jk_longlong_one_fill_right_shift : jk_longlong_zero_fill_right_shift)(a, b, shift);
}

unsigned long jk_ulong_get_right_justified_high_half(unsigned long a) { return (a >> (jk_bits_of(a) / 2)); }
unsigned long jk_ulong_get_low_half(unsigned long a) { return  (a & (~0UL >> (jk_bits_of(a) / 2))); }
unsigned long jk_ulong_get_left_justified_high_half(unsigned long a) { return  (a & (~0UL << (jk_bits_of(a) / 2))); }

void
jk_ulong_multiply_to_ulonglong(jk_ulonglong_t * a, unsigned long b, unsigned long c)
{
    unsigned long bl = jk_ulong_get_low_half(b);
    unsigned long bh = jk_ulong_get_right_justified_high_half(b);
    unsigned long cl = jk_ulong_get_low_half(c);
    unsigned long ch = jk_ulong_get_right_justified_high_half(c);
    jk_ulonglong_t aa[6];

    if (bh == 0 && ch == 0)
    {
        a->low = bl * cl;
        a->high = 0;
        return;
    }
    aa[0].high = 0;
    aa[1].high = 0;
    aa[2].high = 0;
    aa[3].low = 0;
    
    aa[0].low = (bl * cl);
    aa[1].low = (bh * cl);
    aa[2].low = (bl * ch);
    aa[3].high = (bh * ch);
    
    jk_ulonglong_left_shift_in_place(&aa[1], jk_bits_of(unsigned long)/2);
    jk_ulonglong_left_shift_in_place(&aa[2], jk_bits_of(unsigned long)/2);
    
    jk_ulonglong_add(&aa[4], aa[0], aa[1]);
    jk_ulonglong_add(&aa[5], aa[2], aa[3]);
    jk_ulonglong_add(a, aa[4], aa[5]);
}

void
jk_long_split_into_magnitude_and_sign(
    long i,
    unsigned long * magnitude,
    int * sign
    )
{
    int local_sign;
    unsigned long local_magnitude;
    
    if (i >= 0)
    {
        local_magnitude = (unsigned long)i;
        local_sign = +1;
    }
    else
    {
        /* +1 and -1 to avoid negating the most negative long */
        local_magnitude = ((unsigned long)-(i + 1)) - 1;
        local_sign = -1;
    }
    *sign = local_sign;
    *magnitude = local_magnitude;
}
    
void
jk_ulonglong_twos_complement_in_place(
    jk_ulonglong_t * a
    )
{
    a->high ^= ~0UL;
    a->low ^= ~0UL;
    jk_add_ulong_to_ulonglong_in_place(a, 1);
}

void
jk_ulonglong_twos_complement(
    jk_ulonglong_t * a,
    jk_ulonglong_t   b
    )
{
    *a = b;
    jk_ulonglong_twos_complement_in_place(a);
}

void
jk_longlong_split_into_magnitude_and_sign(
	jk_longlong_t i,
    jk_ulonglong_t * magnitude,
    int * sign
    )
{    
    if (i.high >= 0)
    {
        magnitude->high = (unsigned long)i.high;
        magnitude->low =  i.low;
        *sign = +1;
    }
    else
    {
        jk_ulonglong_t uone;
        jk_longlong_t one;
        
        *sign = -1;
        uone.low = 1;
        uone.high = 0;
        one.low = 1;
        one.high = 0;

        /* I don't know what to do here other than assume two's complement.
        I suspect there is a real problem here that native signed arithmetic
        should be avoided in any multiple precision arithmetic code.
        */
        /* +1 and -1 to avoid negating the most negative long */
        /* * magnitude = ((unsigned long)-(i + 1)) - 1; */
        jk_longlong_add_in_place(&i, one);
        jk_ulonglong_bitwise_invert_in_place(magnitude);
        jk_ulonglong_add_in_place(magnitude, uone);
        *sign = -1;
    }
}
    
void
jk_longlong_negate(
    jk_longlong_t * a,
    jk_longlong_t b
    )
{
    /* I don't know what to do here other than assume two's complement.
    I suspect there is a real problem here that native signed arithmetic
    should be avoided in any multiple precision arithmetic code.
    */
    jk_ulonglong_t ua;
    jk_ulonglong_t one;

    one.low = 1;
    one.high = 0;

    ua.high = (unsigned long)b.high;
    ua.low = b.low;

    jk_ulonglong_bitwise_invert_in_place(&ua);
    jk_ulonglong_add_in_place(&ua, one);
    
    a->high = (long)ua.high;
    a->low = ua.low;
}

void
jk_longlong_negate_in_place(
    jk_longlong_t * a
    )
{
    jk_longlong_t b;

    b = *a;
    jk_longlong_negate(a, b);
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
    jk_ulonglong_t b,
    jk_ulonglong_t c
    )
{
	/* undone but quash warning */
	a->low = b.low * c.low;
}

void
jk_longlong_multiply(
    jk_longlong_t * a,
    jk_longlong_t b,
    jk_longlong_t c
    )
{
	/* undone but quash warning */
	a->low = b.low * c.low;
}

float
jk_java_convert_java_float_to_native_float(
    unsigned char * bytes
    )
{
    long sign;
    long exponent;
    long mantissa;
    unsigned long i;
    float f;

    i = jk_get_big_endian_u4(bytes);
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
    exponent = (long)((i >> 23) & 0xff);
    mantissa = (long)((exponent == 0) ? ((i & 0x7fffff) << 1) : ((i & 0x7fffff) | 0x800000));

    f = (float)(sign * mantissa * pow(2, exponent - 150));
exit:
    return f;
}

void
jk_java_free_constantpool(
    jk_java_constant_pool_t * constant_pool
    )
{
	jk_free((void**)&constant_pool->tags);
	jk_free((void**)&constant_pool->any);
}

typedef struct jk_compactable_heap_entry_t {
/* private */
    unsigned offset;
    unsigned size;
} jk_compactable_heap_entry_t;

struct jk_compactable_heap_t
{
/* public */
	unsigned char * base;
/* private */
	unsigned underlying_bytes_allocated;
	unsigned total_bytes_used;
	unsigned total_bytes_free;
	jk_compactable_heap_entry_t used_array;
	jk_compactable_heap_entry_t free_array;
	jk_compactable_heap_entry_t large_free_block;
};

void
jk_get_pointer_into_compactable_heap(
    jk_compactable_heap_t * heap,
    unsigned offset,
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
}

#if 0

struct jk_movable_heap_t
{
	unsigned char * base;
	unsigned used;
	unsigned free;
	unsigned number_of_allocations;
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
	unsigned new_size
	)
{
	unsigned char * new_base = 0;
	unsigned char * old_base = 0;
	unsigned current_size = 0;
	long err = -__LINE__;
	
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
	unsigned size,
	unsigned char * p
	)
{
	long err = -__LINE__;
	jk_movable_heap_t local;
	
	local.used = heap->used;
	local.base = heap->base;
	local.free = heap->free;
	
	if (local.free < size)
	{
		unsigned current_heap_size = (local.used + local.free);
		unsigned new_heap_size = current_heap_size * 2;
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
	return -__LINE__;
}

long
jk_free_position_independent_heap(
	)
{
	return -__LINE__;
}
#endif

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
jk_java_read_constantpool(
    jk_java_classfile_t * classfile
    )
{
	const static char function[] = "jk_java_read_constantpool";
    long err = -__LINE__;
    unsigned constants_read = 0;
    unsigned constant_pool_count = classfile->constant_pool_count;
    jk_java_constant_pool_t * constant_pool = &classfile->constant_pool;
    jk_file_t * file = &classfile->file;
    unsigned char * buffer = 0;
    unsigned char * tags = 0;
    unsigned char tag = 0;
	jk_java_any_t * any = 0;

    constant_pool->tags = 0;
    constant_pool->any = 0;

	err = jk_malloc(constant_pool_count, (void**)&tags);
	if (err < 0) goto exit;
    constant_pool->tags = tags;
	
	err = jk_malloc(sizeof(*any) * constant_pool_count, (void**)&any);
	if (err < 0) goto exit;
    constant_pool->any = any;
	
    err = jk_file_read_ahead(file, 3 * constant_pool_count);
    if (err < 0) goto exit;

    for ( constants_read = 0 ; constants_read != constant_pool_count ; ++constants_read )
    {
    	err = jk_file_read_get_buffer(file, (void**)&buffer, 3, NULL);
    	if (err < 0) goto exit;
    	tag = buffer[0];
    	tags[constants_read] = tag;
    	switch (tag)
    	{
    	case jk_java_constant_class_tag:
            any[constants_read].unresolved_constant.class_ref.class_index = jk_get_big_endian_u2(buffer + 1);
    		break;
    	case jk_java_constant_fieldref_tag:
    	case jk_java_constant_methodref_tag:
    	case jk_java_constant_interfacemethodref_tag:
			err = jk_file_read_ahead(file, 2);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(file, (void**)&buffer, 2, NULL);
    		if (err < 0)
    			goto exit;
            any[constants_read].unresolved_constant.member_ref.class_index = jk_get_big_endian_u2(buffer - 4);
            any[constants_read].unresolved_constant.member_ref.name_and_type_index = jk_get_big_endian_u2(buffer - 2);
            break;
         case jk_java_constant_string_tag:
            any[constants_read].unresolved_constant.string_ref.string_index = jk_get_big_endian_u2(buffer + 1);
         	break;
         case jk_java_constant_integer_tag:         	
			err = jk_file_read_ahead(file, 2);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(file, (void**)&buffer, 2, NULL);
    		if (err < 0)
    			goto exit;
			any[constants_read].UnsignedLong = jk_get_big_endian_u4(buffer - 4);
    		break;
         case jk_java_constant_float_tag:         	
			err = jk_file_read_ahead(file, 2);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(file, (void**)&buffer, 2, NULL);
    		if (err < 0)
    			goto exit;
			any[constants_read].Float = jk_java_convert_java_float_to_native_float(buffer - 4);
    		break;
         case jk_java_constant_double_tag:         	
			err = jk_file_read_ahead(file, 6);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(file, (void**)&buffer, 6, NULL);
    		if (err < 0)
    			goto exit;
			any[constants_read].Double = jk_java_convert_java_float_to_native_double(buffer - 8);
    		break;
         case jk_java_constant_long_tag:         	
			err = jk_file_read_ahead(file, 6);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(file, (void**)&buffer, 6, NULL);
    		if (err < 0)
    			goto exit;
			any[constants_read].LongLong = jk_java_get_long(buffer - 8);
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
	jk_file_buffer_t * file_buffer
	)
{
	jk_file_buffer_t * const x = file_buffer;
	
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
	jk_file_t * file
	)
{
	jk_file_t * const x = file;
	
	x->stdio_file = 0;
	x->file_path = 0;
	x->openmode = 0;
	jk_init_file_buffer(&x->buffer);
	return 0;
}

long
jk_java_init_constant_pool(
	jk_java_constant_pool_t * constant_pool
	)
{
	jk_java_constant_pool_t * const x = constant_pool;
	
	x->tags = 0;
	x->any = 0;
	return 0;
}

long
jk_java_init_classfile(
	jk_java_classfile_t * classfile
	)
{
	jk_java_classfile_t * const x = classfile;
	
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
	jk_init_file(&x->file);
	jk_java_init_constant_pool(&x->constant_pool);
	
	return 0;
}

long jk_java_read_classfile(jk_java_classfile_t ** ppcf, const char * filepath)
{
#pragma unused(ppcf)
	const static char function[]  = "jk_java_read_classfile";
    jk_java_classfile_t classfile;
    jk_file_t * file = &classfile.file;
    long err = -1;
    unsigned n = 0;
    
	jk_java_init_classfile(&classfile);
	classfile.file.buffer.keep_all_bytes = 1;
    err = jk_file_open_for_read(file, filepath);
    if (err < 0) goto exit;

	err = jk_file_read_ahead(file, sizeof(jk_java_packed_classfile3_t);
    if (err < 0) goto exit;

    err =
        jk_file_read_and_unpack(
            file,
            &jk_java_classfile_pack_spec1,
            sizeof(jk_java_packed_classfile1_t),
            &classfile,
            sizeof(classfile));
    if (err < 0) goto exit;
    
    err = jk_java_read_constantpool(&classfile);
    n = jk_align_integer(sizeof(classfile));

    err =
        jk_file_read_and_unpack(
            file,
            &jk_java_classfile_pack_spec2,
            sizeof(jk_java_packed_classfile2_t),
            &classfile,
            sizeof(classfile));
    if (err < 0) goto exit;

    jk_dump_struct("classfile.", &classfile, &jk_dump_java_classfile_struct); 

    err = 0;
exit:
	if (err < 0)
		jk_printf("%s existing with %ld\n", function, err);
    return err;
}

JK_EXTERN_C_END

int main(int argc, char ** argv)
{
    if (argc > 1 && argv && argv[1])
    {
    	jk_java_read_classfile(0, argv[1]);
    	
    	jk_profile_dump_function_call_counts();
    }
    return -1;
}
