#include "j44.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <limits.h>
#include <errno.h>

#if defined(_MSC_VER)
#pragma warning(disable:4127) /* conditional expression is constant */
#endif

JK_EXTERN_C_BEGIN

static const char sourcefile[] = "j40.c";

#define jk_out_of_memory_error (~1)
#define jk_error_uninitialized (~2)
#define jk_error_unreachable   (~3)
typedef void (*jk_pfn_vv_t)(void);
#define jk_pointer_to_function_uninitialized ((jk_pfn_vv_t*)~4)
#define jk_sizet_uninitialized   (~(size_t)5)
#define jk_pointer_uninitialized ((void*)~6)
#define jk_function_pointer_uninitialized ((void(*)())~7)
#define jk_integer_overflow_error (~8)
#define jk_bad_parameter (~9)

#if defined(_MSC_VER) /* Visual C++ */

#define jk_format_file_line "%s(%u):"

#else /* MPW */

#define jk_format_file_line "file %s; line %u #"

#endif

#define jk_tristate_compare_integer(x,y) \
 (((x) < (y)) ? -1 : ((x) > (y)) ? 1 : 0)

#define jkp_get_null_terminated_string_length_generic(Name, T) \
size_t Name(const T * s); size_t Name(const T * s) { const T * t = s; for ( ; *s != 0 ; ++s) ; return (size_t)(s - t); }

jkp_get_null_terminated_string_length_generic(
	jk_get_null_terminated_string_length_a,
	char
	)

typedef unsigned short jk_wchar_t;

jkp_get_null_terminated_string_length_generic(
	jk_get_null_terminated_string_length_w,
	jk_wchar_t
	)

char
jk_lowercase_ascii_char(
	char ch
	)
{
	return (ch | ((ch >= 0x41 && ch <= 0x5A) ? 0x20 : 0));
}

char
jk_uppercase_ascii_char(
	char ch
	)
{
	return (ch ^ ((ch >= 0x61 && ch <= 0x7A) ? 0x20 : 0));
}

void
jk_uppercase_string_in_place_a(
	jk_string_t *s
	)
{
	char *buffer = s->chars;
	char *buffer_end = (buffer + s->length);
	for ( ; buffer != buffer_end ; ++buffer)
		*buffer = jk_uppercase_ascii_char(*buffer);		
}

void
jk_lowercase_string_in_place_a(
	jk_string_t *s
	)
{
	char *buffer = s->chars;
	char *buffer_end = (buffer + s->length);
	for ( ; buffer != buffer_end ; ++buffer)
		*buffer = jk_lowercase_ascii_char(*buffer);		
}

void
jk_uppercase_null_terminated_string_in_place_a(
	char *s
	)
{
	jk_string_t t;
	t.chars = s;
	t.length = jk_get_null_terminated_string_length_a(s);
	jk_uppercase_string_in_place_a(&t);
}

void
jk_lowercase_null_terminated_string_in_place_a(
	char *s
	)
{
	jk_string_t t;
	t.chars = s;
	t.length = jk_get_null_terminated_string_length_a(s);
	jk_lowercase_string_in_place_a(&t);
}

int
jk_compare_strings_case_sensitive(
	jk_string_t *a,
	jk_string_t *b
	)
{
	const unsigned char *a_buffer = (const unsigned char *)a->chars;
	const unsigned char *a_buffer_end = (const unsigned char *)(a_buffer + a->length);

	const unsigned char *b_buffer = (const unsigned char *)b->chars;
	const unsigned char *b_buffer_end = (const unsigned char *)(b_buffer + b->length);

	for ( ; a_buffer != a_buffer_end && b_buffer != b_buffer_end ; (++a_buffer), (b_buffer))
	{
		unsigned char a_char = *a_buffer;
		unsigned char b_char = *b_buffer;
		if (a_char != b_char)
			return (a_char < b_char) ? -1 : 1;
	}
	if (b_buffer != b_buffer_end)
		return -1;
	else if (a_buffer != a_buffer_end)
		return 1;
	else
		return 0;
}

int
jk_compare_strings_case_insensitive(
	jk_string_t *a,
	jk_string_t *b
	)
{
	const unsigned char *a_buffer = (const unsigned char *)a->chars;
	const unsigned char *a_buffer_end = (const unsigned char *)(a_buffer + a->length);

	const unsigned char *b_buffer = (const unsigned char *)b->chars;
	const unsigned char *b_buffer_end = (const unsigned char *)(b_buffer + b->length);

	for ( ; a_buffer != a_buffer_end && b_buffer != b_buffer_end ; (++a_buffer), (b_buffer))
	{
		unsigned char a_char = *a_buffer;
		unsigned char b_char = *b_buffer;
		if (a_char != b_char)
		{
			a_char = jk_lowercase_ascii_char(a_char);
			b_char = jk_lowercase_ascii_char(b_char);
			if (a_char != b_char)
				return (a_char < b_char) ? -1 : +1;
		}
	}
	if (b_buffer != b_buffer_end)
		return -1;
	else if (a_buffer != a_buffer_end)
		return 1;
	else
		return 0;
}

int
jk_strcmp(
	const char *a,
	const char *b
	)
{
	jk_string_t c;
	jk_string_t d;

	c.chars = (char *)a;
	c.length = jk_get_null_terminated_string_length_a(a);

	d.chars = (char *)b;
	d.length = jk_get_null_terminated_string_length_a(b);
	
	return jk_compare_strings_case_sensitive(&c, &d);
}

int
jk_stricmp(
	const char *a,
	const char *b
	)
{	
	jk_string_t c;
	jk_string_t d;

	c.chars = (char *)a;
	c.length = jk_get_null_terminated_string_length_a(a);

	d.chars = (char *)b;
	d.length = jk_get_null_terminated_string_length_a(b);
	
	return jk_compare_strings_case_insensitive(&c, &d);
}

void jk_unused(const void * a) { a = &a; }

void jk_unused4(const void * a1, const void * a2, const void * a3, const void * a4)
{
	a1 = &a1; a2 = &a2; a3 = &a3; a4 = &a4;
}

long
jk_carry_to_error(
	jk_carry_t carry
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
#define jk_function(x) static JK_CONST jk_constant_string_t function = jk_constant_string(#x)
#else
#define jk_function(x) static JK_CONST jk_constant_string_t function = jk_constant_string("")
#endif

#define jk_assert(x) \
 ((void)((x) || jk_assert_failed(jk_debug_string(#x), sourcefile, __LINE__)))

#if jk_debug_strings
#define jk_field_name(x) x
#else
#define jk_field_name(x) ""
#endif

#define jk_debug_printf printf
#define jk_printf printf

#define jk_cast(t) (t)

long
jk_report_bad_parameter(
    const jk_constant_string_t * function,
    const char * expression
    )
{
    jk_printf("bad parameter in function %s: %s\n", function->chars, expression);
    return jk_bad_parameter;
}
    
#define JK_CHECK_PARAMETER(expr) \
    do { if (!(expr)) \
            return jk_report_bad_parameter(&function, #expr); \
       } while(0)

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

JK_ORCAC_SEGMENT

jk_spin_lock_t        jk_profile_record_list_lock;
jk_profile_record_t * jk_profile_record_list = (jk_profile_record_t *)&jk_profile_record_list;

#define jk_profile_count_function_call() \
	do { \
		static jk_profile_record_t profile_record = { 0, 0, &function }; \
		profile_record.call_count += 1; \
		if (!profile_record.next) { \
			jkp_initialize_profile_record(&profile_record); \
		} \
	} while(0)

void
jkp_initialize_profile_record(
	jk_profile_record_t * profile_record
	)
{
	jk_irql_t previous_irql;
	jk_profile_record_t * head;

	jk_acquire_spin_lock(&jk_profile_record_list_lock, &previous_irql);

	head = jk_profile_record_list;
	jk_profile_record_list = profile_record;
	profile_record->next = head;

	jk_release_spin_lock(&jk_profile_record_list_lock, previous_irql);
}

void
jk_profile_dump_function_call_counts(
	void
    )
{
    jk_function(jk_profile_dump_function_call_counts);
	jk_profile_record_t * p;
	size_t longest_name_length = 0;

	jk_profile_count_function_call();

    for ( p = jk_profile_record_list ; p != (void*)&jk_profile_record_list ; p = p->next )
    {
        size_t name_length = p->function_name->length;
        if (name_length > longest_name_length)
        {
            longest_name_length = name_length;
        }
    }

    for ( p = jk_profile_record_list ; p != (void*)&jk_profile_record_list ; p = p->next )
    {
		jk_printf("%-*s %lu\n", (int)longest_name_length, p->function_name->chars, p->call_count);
    }
}

long
jk_malloc(
	void ** pp,
	size_t n
	)
{
	void * p;

	jk_function(jk_malloc);
	jk_profile_count_function_call();
	
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
	
	jk_function(jk_free);
	jk_profile_count_function_call();
	
	*pp = NULL;
	if (p != NULL)
	{
    	jk_function(jk_free_non_null);
		jk_profile_count_function_call();
		free(p);
	}
}

/*
to be done -- reverse the relationship between
jk_heap_* and jk_malloc/jk_free

That is -- implement our own heap.

err -- but isn't jk_memory_allocator_t the preexisting interface?
*/
jk_heap_t * jk_get_default_heap()
{
	return 0;
}

long
jk_heap_allocate_memory(
	jk_heap_t * heap,
	void ** pp,
	size_t n
	)
{
	jk_unused(heap);
	return jk_malloc(pp, n);
}

void
jk_heap_free_memory(
	jk_heap_t * heap,
	void ** pp
	)
{
	jk_unused(heap);
	jk_free(pp);
}

long
jk_default_memory_allocator_allocate(
    jk_memory_allocator_t * state,
    size_t number_of_bytes,
    jk_opaque_cookie_t * cookie
    )
{
	void * p;
    void ** pp = &cookie->u.p;

    jk_function(jk_default_memory_allocator_allocate);
	jk_profile_count_function_call();
	
	jk_unused(state);

    *pp = 0;
    p = malloc(number_of_bytes);
    *pp = p;
    return ((p != NULL) ? 0 : jk_out_of_memory_error);
}

void
jk_default_memory_allocator_free(
    jk_memory_allocator_t * state,
    jk_opaque_cookie_t * cookie
    )
{
    void * p;
    void ** pp = &cookie->u.p;

    jk_function(jk_default_memory_allocator_free);
	jk_profile_count_function_call();

	jk_unused(&state);
    
    p = *pp;
    *pp = 0;
    free(p);
}

long
jk_default_memory_allocator_convert_cookie_to_pointer(
    jk_memory_allocator_t * state,
    jk_opaque_cookie_t cookie,
    void ** pointer
    )
{
    jk_function(jk_default_memory_allocator_convert_cookie_to_pointer);
	jk_profile_count_function_call();

	jk_unused(&state);

    *pointer = cookie.u.p;
    
    return 0;
}

#if 1
#define jk_copy_struct(to, from) \
 do { \
    jk_compile_time_assert(sizeof(to) == sizeof(from)); \
    if (0) { (to) = (from); } \
    jk_copy_memory(&(to), &(from), sizeof(from)); \
 } while (0)
#else
#define jk_copy_struct(to, from) ((to) = (from))
#endif

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
				0
			},
			{
				jk_field_name("minor_version"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, minor_version),
				jk_field_size(jk_java_packed_classfile1_t, minor_version),
				jk_field_offset(jk_java_classfile_t, minor_version),
				jk_field_offset(jk_java_packed_classfile1_t, minor_version),
				0
			},
			{
				jk_field_name("major_version"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, major_version),
				jk_field_size(jk_java_packed_classfile1_t, major_version),
				jk_field_offset(jk_java_classfile_t, major_version),
				jk_field_offset(jk_java_packed_classfile1_t, major_version),
				0
			},
			{
				jk_field_name("constant_pool_count"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, constant_pool.count),
				jk_field_size(jk_java_packed_classfile1_t, constant_pool.count),
				jk_field_offset(jk_java_classfile_t, constant_pool.count),
				jk_field_offset(jk_java_packed_classfile1_t, constant_pool.count),
				0
			},
			{
				jk_field_name("constant_pool"),
				jk_field_offset(jk_types_t, t_void),
				0,
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
				0
			},
			{
				jk_field_name("this_class"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, this_class),
				jk_field_size(jk_java_packed_classfile2_t, this_class),
				jk_field_offset(jk_java_classfile_t, this_class),
				jk_field_offset(jk_java_packed_classfile2_t, this_class),
				0
			},
			{
				jk_field_name("super_class"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, super_class),
				jk_field_size(jk_java_packed_classfile2_t, super_class),
				jk_field_offset(jk_java_classfile_t, super_class),
				jk_field_offset(jk_java_packed_classfile2_t, super_class),
				0
			},
			{
				jk_field_name("interfaces_count"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, interfaces_count),
				jk_field_size(jk_java_packed_classfile2_t, interfaces_count),
				jk_field_offset(jk_java_classfile_t, interfaces_count),
				jk_field_offset(jk_java_packed_classfile2_t, interfaces_count),
				0
			},
			{
				jk_field_name("interfaces"),
				jk_field_offset(jk_types_t, t_void),
				0,
				0,
				0,
				0,
				0
			},
			{
				jk_field_name("fields_count"),
				jk_field_offset(jk_types_t, t_uint),
				jk_field_size(jk_java_classfile_t, fields_count),
				jk_field_size(jk_java_packed_classfile3_t, fields_count),
				jk_field_offset(jk_java_classfile_t, fields_count),
				0,
				0
			},
			{
				jk_field_name("fields"),
				jk_field_offset(jk_types_t, t_void),
				0,
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
				0,
				0
			},
			{
				jk_field_name("methods"),
				jk_field_offset(jk_types_t, t_void),
				0,
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
				0,
				0
			},
			{
				jk_field_name("attributes"),
				jk_field_offset(jk_types_t, t_void),
				0,
				0,
				0,
				0,
				0
			}
		}
	};
	jk_copy_struct(jk_fields, fields);
}

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

	jk_copy_struct(jk_java_classfile_type_info, classfile_type_info);
	jk_copy_struct(jk_java_classfile1_type_info, classfile1_type_info);
	jk_copy_struct(jk_java_classfile2_type_info, classfile2_type_info);
}

void
jk_reverse_memory_range_exclusive(
    void * void_start,
    void * void_end
    )
{
    unsigned char * start = (unsigned char *)void_start;
    unsigned char * end = (unsigned char *)void_end;

    jk_function(jk_reverse_memory_range_exclusive);
	jk_profile_count_function_call();

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
	
	jk_function(jk_reverse_memory_byte_count);
	jk_profile_count_function_call();

    jk_reverse_memory_range_exclusive(p_void, void_end);
}

void
jk_reverse_memory_range_inclusive(
    void * void_start,
    void * void_end
    )
{
	jk_function(jk_reverse_memory_range_inclusive);

	void_end = 1 + (unsigned char*)void_end;
	
	jk_profile_count_function_call();

	jk_reverse_memory_range_exclusive(void_start, void_end);
}

void
jk_move_memory(
    void * to,
    const void * from,
    size_t count
    )
{
    jk_function(jk_move_memory);
	jk_profile_count_function_call();
	
    memmove(to, from, count);
}

void
jk_copy_memory(
    void * to,
    const void * from,
    size_t count
    )
{
    jk_function(jk_copy_memory);
	jk_profile_count_function_call();

    memcpy(to, from, count);
}

void
jk_copy_memory_unsigned_char(
    unsigned char * to,
    const unsigned char * from,
    size_t count
    )
{
	jk_function(jk_copy_memory_unsigned_char);
	jk_profile_count_function_call();

    memcpy(to, from, count);
}

void
jk_copy_memory_reverse(
    unsigned char * to,
    const unsigned char * from,
    size_t count
    )
{
	jk_function(jk_copy_memory_reverse);
	jk_profile_count_function_call();

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
	jk_function(jk_zero_memory);
	jk_profile_count_function_call();

    memset(p, 0, n);
}

long
jk_unpack(
    const jk_globals_t * globals,
    uint_t endian,
    const void * vpacked_buffer,
    void * vunpacked_buffer,
    jk_struct_t * typeinfo
    )
{
    long err = -1;
    const unsigned char * packed_buffer = (const unsigned char *)vpacked_buffer;
    unsigned char * unpacked_buffer = (unsigned char*)vunpacked_buffer;
    union {
    	ulong_t i;
    	unsigned char c[sizeof(ulong_t)];
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

	jk_function(jk_unpack);
	jk_profile_count_function_call();

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
       	size_t number_of_bytes_to_copy = jk_sizet_uninitialized;
    	size_t number_of_packed_bytes_to_skip = jk_sizet_uninitialized;
    	size_t number_of_unpacked_bytes_to_skip = jk_sizet_uninitialized;

        field_pointer = (const jk_field_t*)(fields_base + offset);
        field = *field_pointer;
    	packed_field = packed_buffer + field.packed_offset;
    	unpacked_field = unpacked_buffer + field.unpacked_offset;
		
		if (field.unpacker_offset != 0)
		{
    		jk_field_unpacker_t * field_unpacker = *(jk_field_unpacker_t **)(((uchar_t *)&jk_field_unpackers) + field.unpacker_offset);
    		(*field_unpacker)(field_pointer, packed_field, unpacked_field);
    		continue;
    	}	
		switch (jk_tristate_compare_integer(field.unpacked_size, field.packed_size))
	    {
            const jk_type_t * type_pointer;
            unsigned is_signed;
            
	        case 0:
	            /*
	            just copy, possibly in reverse
	            */
        		number_of_bytes_to_copy = field.packed_size;
        		number_of_packed_bytes_to_skip = 0;
        		number_of_unpacked_bytes_to_skip = 0;
        		break;
        	
        	case 1:
        	    /*
        	    sign extend or zero extend
        	    */
                type_pointer = (const jk_type_t *)(types_base + field.offset_to_type);
                is_signed = type_pointer->is_signed;

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
            	break;
 
            case -1:
                /*
                WARNING -- truncation happening
                */
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
	jk_function(jk_compute_packed_size);
	jk_profile_count_function_call();
	
    return jk_compute_packed_or_unpacked_size(globals, p, 1);
}

JK_ORCAC_SEGMENT

long
jk_compute_unpacked_size(
    const jk_globals_t * globals,
    jk_struct_t * p
    )
{
	jk_function(jk_compute_unpacked_size);
	jk_profile_count_function_call();

    return jk_compute_packed_or_unpacked_size(globals, p, 0);
}

long
jk_compute_packed_or_unpacked_size(
    const jk_globals_t * globals,
    jk_struct_t * p,
    uint_t packed_or_unpacked
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
	
	jk_function(jk_compute_packed_or_unpacked_size);
	jk_profile_count_function_call();

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
jk_errno()
{
	long err = errno;
	if (err == 0)
		return -1;
	if (err < 0)
		return err;
	return -err;
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
jk_file_open_for_read(
    const jk_globals_t * globals,
    jk_file_t * file,
    const char * file_path
    )
{
    jk_function(jk_file_open_for_read);
    long err = -1;
    const char * openmode = "rb";

	jk_profile_count_function_call();
	jk_unused(globals);

	if ((err = jk_stdio_fopen(file_path, openmode, &file->stdio_file)) < 0)
		goto exit;
    file->openmode = openmode;
    file->file_path = file_path;
    err = 0;
exit:
	if (err < 0)
		jk_printf("%s exiting with %ld\n", function.chars, err);
    return err;
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
	jk_function(jk_file_read_and_unpack);
    long err = -1;
    size_t bytes_read = 0;
    void * packed_buffer = 0;

	jk_profile_count_function_call();

    err = jk_compute_packed_size(globals, spec);
    if (err < 0) goto exit;
    err = jk_compute_unpacked_size(globals, spec);
    if (err < 0) goto exit;
    if (spec->packed_size > packed_buffer_size)
    	err = -__LINE__;
    else if (spec->unpacked_size > unpacked_buffer_size)
    	err = -__LINE__;
    if (err < 0)
        goto exit;
    err = jk_file_read_get_buffer(file, &packed_buffer, spec->packed_size, &bytes_read);
    if (err < 0)
        goto exit;
    if (bytes_read != spec->packed_size)
	{
#if 0
		jk_printf("bytes_read /* %u */ != spec->packed_size /* %u */\n",
			(unsigned)bytes_read,
			(unsigned)spec->packed_size);
#endif
    	err = -__LINE__;
	}
    if (err < 0)
        goto exit;
    err = jk_unpack(globals, spec->endian, packed_buffer, unpacked_buffer, spec);
    if (err < 0)
        goto exit;
    
    err = 0;
exit:
	if (err < 0)
		jk_printf(jk_format_file_line "%s exiting with %ld\n", sourcefile, (unsigned)__LINE__, function.chars, err);
    return err;
}

JK_ORCAC_SEGMENT

long
jk_file_read_and_unpack_array(
    const jk_globals_t * globals,
    jk_file_t * file,
    jk_array_t * array,
    size_t offset,
    size_t size
    )
{
	jk_function(jk_file_read_and_unpack_array);
    long err = -1;
    size_t required_array_size;
    size_t array_size;
    uchar_t * array_base;
    const jk_type_t * array_element_type;
    size_t array_element_type_size;
    size_t bytes_read;
    void * packed_buffer;
    size_t bytes_to_read;
    
    jk_unused(globals);
    
    err = jk_array_get_size(array, &array_size);
    if (err < 0)
        goto exit;

    err = jk_array_get_element_type(array, &array_element_type);
    if (err < 0)
        goto exit;
        
    err = jk_type_get_size(array_element_type, &array_element_type_size);
    if (err < 0)
        goto exit;

    required_array_size = offset + size;
    if (required_array_size > array_size)
    {
        err = jk_array_set_size(array, required_array_size);
        if (err < 0)
            goto exit;
    }
    err = jk_array_get_base(array, (void**)&array_base);
    if (err < 0)
        goto exit;
      
    bytes_to_read = array_element_type_size * size;
    err = jk_file_read_get_buffer(file, &packed_buffer, bytes_to_read, &bytes_read);
    if (err < 0)
        goto exit;
    if (bytes_read != bytes_to_read)
	{
#if 0
		jk_printf("bytes_read /* %u */ != spec->packed_size /* %u */\n",
			(unsigned)bytes_read,
			(unsigned)bytes_to_read);
#endif
    	err = -__LINE__;
	}
    if (err < 0)
        goto exit;
    err = 0;
exit:
	if (err < 0)
		jk_printf(jk_format_file_line "%s exiting with %ld\n", sourcefile, (unsigned)__LINE__, function.chars, err);
    return err;
}

JK_ORCAC_SEGMENT

size_t
jk_find_index_of_character_in_counted_string_a(
	const char * s,
	size_t length,
	char ch
	)
{
	size_t i = 0;
	for ( ; i != length && s[i] == ch ; ++i)
		;
	return i;
}

size_t
jk_find_index_of_character_in_null_terminated_string_a(
	const char * s,
	char ch
	)
{
	return jk_find_index_of_character_in_counted_string_a(s, jk_get_null_terminated_string_length_a(s), ch);
}

unsigned
jk_ulong_log_base_2_rounded_up(
	unsigned long a
	)
{
	unsigned b = 0;
	while (a != 0)
	{
		b += 1;
		a >>= 1;
	}
	return b;
}

void
jk_set_bit_in_uchar_array(
	unsigned char bits[],
	unsigned long bit
	)
{
	const unsigned k = CHAR_BIT;
	bits[bit / k] |= (1U << (bit % k));
}

void
jk_set_bit_in_ulong(
	unsigned long *bits,
	unsigned long bit
	)
{
	*bits |= (1UL << bit);
}

unsigned long
jk_get_bit_in_ulong_not_right_justified(
	unsigned long bits,
	unsigned long bit
	)
{
	return (bits & (1UL << bit));
}

unsigned
jk_get_bit_in_ulong_right_justified(
	unsigned long bits,
	unsigned long bit
	)
{
	return ((bits >> bit) & 1);
}

void
jk_set_bit_in_ulong_array(
	unsigned long bits[],
	unsigned long bit
	)
{
	const unsigned k = (CHAR_BIT * sizeof(unsigned long));
	
	jk_set_bit_in_ulong(&bits[bit / k], bit % k);
}

unsigned long
jk_get_bit_in_ulong_array_not_right_justified(
	unsigned long bits[],
	unsigned long bit
	)
{
	const unsigned k = (CHAR_BIT * sizeof(unsigned long));
	
	return jk_get_bit_in_ulong_not_right_justified(bits[bit / k], bit % k);
}

unsigned
jk_get_bit_in_ulong_array_right_justified(
	unsigned long *bits,
	unsigned long bit
	)
{
	const unsigned k = (CHAR_BIT * sizeof(unsigned long));

	return jk_get_bit_in_ulong_right_justified(bits[bit / k], bit % k);
}

long
jk_new_fixed_size_bit_set(
	jk_fixed_size_bit_set_t ** bit_set,
	unsigned long size_in_bits
	)
{
	const unsigned k = (CHAR_BIT * sizeof(unsigned long));

	long result = -1;
	jk_fixed_size_bit_set_t * temp = 0;
	unsigned long size_in_ulongs = 0;

	size_in_ulongs = (size_in_bits / k) + !!(size_in_bits % k);
	
	*bit_set = 0;
	
	result = jk_malloc((void**)&temp, sizeof(*temp) + (size_in_ulongs * sizeof(unsigned long)));
	if (result < 0)
		goto Exit;
	
	temp->bits = &(temp + 1)->size_in_bits;

	*bit_set = temp;
	temp = 0;
	result = 0;
Exit:
	jk_delete_fixed_size_bit_set(&temp);
	return result;
}

void
jk_delete_fixed_size_bit_set(
	jk_fixed_size_bit_set_t ** bit_set
	)
{
	(*bit_set)->bits = 0;
	free((*bit_set));
	*bit_set = 0;
}

void
jk_set_bit_in_fixed_size_bit_set(
	jk_fixed_size_bit_set_t * set,
	unsigned long bit
	)
{
	if (bit < set->size_in_bits)
		jk_set_bit_in_ulong_array(set->bits, bit);
}

unsigned
jk_is_bit_in_fixed_size_bit_set(
	jk_fixed_size_bit_set_t * bit_set,
	unsigned long bit
	)
{
	if (bit >= bit_set->size_in_bits)
		return 0;
	return jk_get_bit_in_ulong_array_not_right_justified(bit_set->bits, bit) ? 1 : 0;
}

void
jk_add_to_zeroed_character_set_from_counted_string_a(
	jk_character_set_a_t * set,
	const char * s,
	size_t length
	)
{
	size_t i = 0;

	for ( ; i != length ; ++i)
	{
		unsigned u = (unsigned char)s[i];
		set->bits[u >> 5] |= (1UL << (u & 31));
	}
}

void
jk_make_character_set_from_counted_string_a(
	jk_character_set_a_t * set,
	const char * s,
	size_t length
	)
{
	memset(set, 0, sizeof(*set));
	jk_add_to_zeroed_character_set_from_counted_string_a(set, s, length);
}

jk_bool_t
jk_is_character_in_character_set_a(
	jk_character_set_a_t * set,
	char ch
	)
{
	unsigned u = (unsigned)ch;
	if (set->bits[u >> 5] & (1UL << (u & 31)))
		return jk_true;
	else
		return jk_false;
}

size_t
jk_find_index_of_character_set_in_counted_string_a(
	const char * s,
	size_t length,
	jk_character_set_a_t * set
	)
{
	size_t i = 0;

	for ( ; i != length ; ++i)
	{
		if (jk_is_character_in_character_set_a(set, s[i]))
			break;
	}
	return i;
}

size_t
jk_get_number_of_chars_from_set_at_start_of_string(
	jk_string_t * s,
	jk_character_set_a_t * set
	)
{
	size_t i = 0;
	char * s_chars = s->chars;
	size_t s_length = s->length;

	for ( ; i != s_length && jk_is_character_in_character_set_a(set, s_chars[i]) ; ++i)
		;

	return i;
}

size_t
jk_get_number_of_chars_from_set_at_end_of_string(
	jk_string_t * s,
	jk_character_set_a_t * set
	)
{
	size_t i = 0;
	char * s_chars = s->chars;
	size_t s_length = s->length;

	for ( ; i != s_length && jk_is_character_in_character_set_a(set, s_chars[s_length - i - 1]) ; ++i)
		;

	return i;
}

size_t
jk_strspn(
	const char * s,
	const char * t
	)
{
	jk_string_t s2 = { 0 };
	jk_character_set_a_t set = { { 0 } };
	
	s2.chars = (char*)s;
	s2.length = jk_get_null_terminated_string_length_a(s);
	
	jk_add_to_zeroed_character_set_from_counted_string_a(
		&set,
		t,
		jk_get_null_terminated_string_length_a(t)
		);
	
	return jk_get_number_of_chars_from_set_at_start_of_string(&s2, &set);
}

JK_ORCAC_SEGMENT

void
jk_limited_truncating_string_copy(
    char * dest,
    const char * src,
    size_t n
    )
{
    size_t m;
    
	jk_function(jk_limited_truncating_string_copy);
	jk_profile_count_function_call();

    if (n == 0)
        return;
    m = 1 + strlen(src);
    if (m != 1)
    {
	    if (m > n)
	        m = n;

	    memcpy(dest, src, m - 1);
	}
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

size_t jk_get_dump_length_unsigned_int(uint_t data)
{
	jk_unused(&data);
    return JK_INTEGER_DUMP_LENGTH(unsigned);
}

size_t jk_get_dump_length_long(long data)
{
	jk_unused(&data);
    return JK_INTEGER_DUMP_LENGTH(long);
}

size_t jk_get_dump_length_unsigned_long(ulong_t data)
{
	jk_unused(&data);
    return JK_INTEGER_DUMP_LENGTH(ulong_t);
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
	*length = jk_get_dump_length_unsigned_int(*(const uint_t*)data);
	return 0;
}

long jk_type_get_dump_length_long(const jk_type_t * t, const void * data, size_t * length)
{
	jk_unused(&t);
	*length = jk_get_dump_length_long(*(const long*)data);
	return 0;
}

long jk_type_get_dump_length_unsigned_long(const jk_type_t * t, const void * data, size_t * length)
{
	jk_unused(&t);
	*length = jk_get_dump_length_unsigned_long(*(const ulong_t*)data);
	return 0;
}

void jk_dump_int(size_t buffer_size, char * buffer, int data)
{
    jk_dump_long(buffer_size, buffer, (long)data);
}

void jk_dump_unsigned_int(size_t buffer_size, char * buffer, uint_t data)
{
    jk_dump_unsigned_long(buffer_size, buffer, (ulong_t)data);
}

void jk_dump_long(size_t buffer_size, char * buffer, long data)
{
	char big_enough_buffer[JK_INTEGER_DUMP_LENGTH(long)];
			
    if (data >= 16)
        sprintf(big_enough_buffer, "%ld (0x%lx)", data, (ulong_t)data);
    else
        sprintf(big_enough_buffer, "%ld", data);
	
	jk_limited_truncating_string_copy(buffer, big_enough_buffer, buffer_size);
}

void jk_dump_unsigned_long(size_t buffer_size, char * buffer, ulong_t data)
{
	char big_enough_buffer[JK_INTEGER_DUMP_LENGTH(ulong_t)];
	
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
	jk_dump_unsigned_int(buffer_size, buffer, *(const uint_t *)data);
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
	jk_dump_unsigned_long(buffer_size, buffer, *(const ulong_t *)data);
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
    size_t maximum_name_length = 0;
    const jk_field_t * field = (jk_field_t *)jk_pointer_to_function_uninitialized;
    const size_t offset_to_first_field = typeinfo->offset_to_first_field;
    const size_t offset_to_last_field = typeinfo->offset_to_last_field;
    const unsigned char * const fields_base = (const unsigned char *)globals->fields;
    const unsigned char * const types_base = (const unsigned char *)globals->types;
    unsigned offset = 0;
	char stack_buffer[64];
	jk_buffer_t buffer = { {{{ 0 }}}, 0, 0, 0, 0, 0, 0 };

	jk_function(jk_dump_struct);
	jk_profile_count_function_call();

	err = jk_buffer_init(&buffer, sizeof(stack_buffer), &stack_buffer);
	if (err < 0)
	    goto exit;

    for ( offset = offset_to_first_field ; offset <= offset_to_last_field ; offset += sizeof(jk_field_t) )
    {
    	size_t name_length;
	
        field = (const jk_field_t*)(fields_base + offset);
    	name_length = strlen(field->name);
    	if (name_length > maximum_name_length)
    		maximum_name_length = name_length;
    }
    
    for ( offset = offset_to_first_field ; offset <= offset_to_last_field ; offset += sizeof(jk_field_t) )
    {
		jk_type_get_dump_length_t get_dump_length;
		jk_type_dump_t dump;
		const jk_type_t * type;
	
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

			jk_printf("%s%-*s %s\n", prefix, (int)maximum_name_length, field->name, p);
		}
    }
exit:
	jk_buffer_free(&buffer);
	return err;
}

long
jk_file_read_ahead(
    jk_file_t * file,
    size_t n
    )
{
	jk_function(jk_file_read_ahead);
	jk_profile_count_function_call();

    file->buffer.read_ahead += n;
    return 0;
}

long
jk_file_read_copy(
    jk_file_t * file,
    void * buffer,
    size_t bytes_to_read,
    size_t * bytes_read
    )
{
    void * my_buffer = 0;
    long err = 0;

	jk_function(jk_file_read_copy);
	jk_profile_count_function_call();

    err = jk_file_read_get_buffer(file, &my_buffer, bytes_to_read, bytes_read);
    if (err < 0)
        goto exit;
    jk_copy_memory(buffer, my_buffer, *bytes_read);
    err = 0;
exit:
    return err;
}

long
jk_file_read_get_buffer(
    jk_file_t * file,
    void ** out_buffer,
    size_t bytes_to_read,
    size_t * out_bytes_read /* optional */
    )
{
    jk_function(jk_file_read_get_buffer);
    long err = -1;
    uchar_t * new_buffer = 0;
    size_t new_buffer_size = 0;
    unsigned keep_all_bytes = 0;
    size_t buffer_size = 0;
    size_t bytes_to_read_plus_read_ahead = 0;
    size_t bytes_read = 0;
    size_t bytes_in_buffer = 0;
    size_t position = 0;
    uchar_t * buffer = 0;

	jk_profile_count_function_call();

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
		else
		{
			jk_move_memory(new_buffer, (void*)(buffer + position), bytes_in_buffer - position);
			bytes_in_buffer -= position;
			file->buffer.position = 0;
			position = 0;
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
    err = jkp_file_read_direct(file, buffer + bytes_in_buffer, buffer_size - bytes_in_buffer, &bytes_read);
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
	jk_free((void**)&new_buffer);
	if (err < 0)
	{
		jk_printf("%s exiting with %ld\n", function.chars, err);
	}
	return err;
}

JK_ORCAC_SEGMENT

uint_t jk_get_big_endian_u2(const uchar_t * a)
{
    return (((uint_t)a[0]) << 8) | (uint_t)a[1];
}

ulong_t jk_get_big_endian_u4(const uchar_t * a)
{
    return (((ulong_t)a[0]) << 24)
    		| (((ulong_t)a[1]) << 16)
    		| (((ulong_t)a[2]) << 8)
    		| (ulong_t)a[3]
    		;
}

uint_t jk_get_little_endian_u2(const uchar_t * a)
{
    return (((unsigned)a[1]) << 8) | a[0];
}

ulong_t jk_get_little_endian_u4(const uchar_t * a)
{
    return (((ulong_t)a[3]) << 24)
    		| (((ulong_t)a[2]) << 16)
    		| (((ulong_t)a[1]) << 8)
    		| (ulong_t)a[0]
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
    b.high = (ulong_t)a.high;
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
void function_name(type * a, type b, type c, jk_carry_t carry) \
{ \
  *a = (b + c + (type)carry); \
}

#define jk_add_in_place_with_carry_in(function_name, type) \
void function_name(type * a, type b, jk_carry_t carry) \
{ \
  *a += (b + (type)carry); \
}

#define jk_signed_add_with_carry_in(function_name, type) \
	jk_add_with_carry_in(function_name, type)

#define jk_signed_add_in_place_with_carry_in(function_name, type) \
	jk_add_in_place_with_carry_in(function_name, type)

#define jk_signed_add_with_carry_out(function_name, type) \
void function_name(type * a, type b, type c, jk_carry_t * carry) \
{ \
  const type aa = (b + c); \
  const int aasign = (aa < 0); \
  *a = aa; \
  *carry = (aasign != (b < 0)) && (aasign != (c < 0)); \
}

#define jk_signed_add_with_carry_in_and_out(function_name, type) \
void function_name(type * a, type b, type c, jk_carry_t * carry) \
{ \
  const type aa = (b + c + (type)*carry); \
  const int aasign = (aa < 0); \
  *a = aa; \
  *carry = (aasign != (b < 0)) && (aasign != (c < 0)); \
}

#define jk_unsigned_add_with_carry_in(function_name, type) \
	jk_add_with_carry_in(function_name, type)

#define jk_unsigned_add_in_place_with_carry_in(function_name, type) \
	jk_add_in_place_with_carry_in(function_name, type)

#define jk_unsigned_add_with_carry_in_and_out(function_name, type) \
void function_name(type * a, type b, type c, jk_carry_t * carry) \
{ \
  const type aa = (b + c + (type)*carry); \
  *a = aa; \
  *carry = ((aa < b) || (aa < c)); \
}

#define jk_unsigned_add_with_carry_out(function_name, type) \
void function_name(type * a, type b, type c, jk_carry_t * carry) \
{ \
  const type aa = (b + c); \
  *a = aa; \
  *carry = ((aa < b) || (aa < c)); \
}

#define jk_unsigned_add_one_with_carry_out(function_name, type) \
void function_name(type * a, type b, jk_carry_t * carry) \
{ \
  const type aa = (b + 1); \
  *a = aa; \
  *carry = (aa == 0); \
}

#define jk_unsigned_add_one_in_place_with_carry_out(function_name, type) \
void function_name(type * a, jk_carry_t * carry) \
{ \
  const type aa = (*a + 1); \
  *a = aa; \
  *carry = (aa == 0); \
}

jk_signed_add_with_carry_in(						jk_long_add_with_carry_in, long)
jk_signed_add_with_carry_out(						jk_long_add_with_carry_out, long)
jk_signed_add_with_carry_in_and_out(				jk_long_add_with_carry_in_and_out, long)
jk_signed_add_in_place_with_carry_in(				jk_long_add_in_place_with_carry_in, long)

jk_unsigned_add_with_carry_in(						jk_ulong_add_with_carry_in, ulong_t)
jk_unsigned_add_with_carry_out(						jk_ulong_add_with_carry_out, ulong_t)
jk_unsigned_add_with_carry_in_and_out(				jk_ulong_add_with_carry_in_and_out, ulong_t)
jk_unsigned_add_in_place_with_carry_in(				jk_ulong_add_in_place_with_carry_in, ulong_t)
jk_unsigned_add_one_with_carry_out(					jk_ulong_add_one_with_carry_out, ulong_t)
jk_unsigned_add_one_in_place_with_carry_out(		jk_ulong_add_one_in_place_with_carry_out, ulong_t)

jk_unsigned_add_with_carry_in(						jk_sizet_add_with_carry_in, size_t)
jk_unsigned_add_with_carry_out(						jk_sizet_add_with_carry_out, size_t)
jk_unsigned_add_with_carry_in_and_out(				jk_sizet_add_with_carry_in_and_out, size_t)
jk_unsigned_add_in_place_with_carry_in(				jk_sizet_add_in_place_with_carry_in, size_t)
jk_unsigned_add_one_with_carry_out(					jk_sizet_add_one_with_carry_out, size_t)
jk_unsigned_add_one_in_place_with_carry_out(		jk_sizet_add_one_in_place_with_carry_out, size_t)

void
jk_long_add_in_place_with_carry_out(long * a, long b, jk_carry_t * carry)
{
    jk_long_add_with_carry_out(a, *a, b, carry);
}

void
jk_long_add_in_place_with_carry_in_and_out(long * a, long b, jk_carry_t * carry)
{
    jk_long_add_with_carry_in_and_out(a, *a, b, carry);
}

void
jk_ulong_add_in_place_with_carry_out(ulong_t * a, ulong_t b, jk_carry_t * carry)
{
    jk_ulong_add_with_carry_out(a, *a, b, carry);
}

void
jk_ulong_add_in_place_with_carry_in_and_out(ulong_t * a, ulong_t b, jk_carry_t * carry)
{
    jk_ulong_add_with_carry_in_and_out(a, *a, b, carry);
}

void
jk_sizet_add_in_place_with_carry_out(size_t * a, size_t b, jk_carry_t * carry)
{
    jk_sizet_add_with_carry_out(a, *a, b, carry);
}

void
jk_sizet_add_in_place_with_carry_in_and_out(size_t * a, size_t b, jk_carry_t * carry)
{
    jk_sizet_add_with_carry_in_and_out(a, *a, b, carry);
}

#define jk_multipleprecision_integer_in_use_malloced 0
#define jk_multipleprecision_integer_in_use_built_in 1

struct jk_multiprecisioninteger_t
{
    ulong_t * malloced_value_array;
    ulong_t built_in_value_array[4];
    unsigned precision;
    unsigned is_precision_fixed : 1;
    unsigned in_use : 1;
    signed   sign : 2; /* -1, +1 */
};

ulong_t *
jk_multipleprecision_integer_get_value_array(
    const jk_multiprecisioninteger_t * m
    )
{
	const ulong_t * p;
	if (m->in_use)
		p = m->built_in_value_array;
	else
		p = m->malloced_value_array;
	return (ulong_t*)p;
}
#define jk_multiprecision_integer_get_value_array jk_multipleprecision_integer_get_value_array

void
jk_multiprecision_integer_trim_heap(
    jk_multiprecisioninteger_t * m
    )
{
	if (m->in_use == jk_multipleprecision_integer_in_use_malloced && m->precision <= jk_number_of(m->built_in_value_array))
	{
		memcpy(m->built_in_value_array, m->malloced_value_array, (m->precision * sizeof(ulong_t)));
		free(m->malloced_value_array);
		m->malloced_value_array = NULL;
		m->in_use = jk_multipleprecision_integer_in_use_built_in;
	}
}

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
    ulong_t i,
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
    ulong_t i
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
    ulong_t u;
    int sign;
   
    if (i >= 0)
    {
        u = (ulong_t)i;
        sign = +1;
    }
    else
    {
        i += 1;         /* -32768 => -32767 */
        i = -i;         /* -32767 => 32767 */
        u = (ulong_t)i; /*  32767 => 32767 */
        u += 1;         /*  32767 => 32768 */
        sign = -1;
    }
    return jk_multiprecision_integer_from_ulong_and_sign(m, u, sign);
}

unsigned
jk_multiprecision_integer_to_boolean(
    const jk_multiprecisioninteger_t * m
    )
{
    const ulong_t * value_array = jk_multiprecision_integer_get_value_array(m);
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
    ulong_t * value_array = jk_multiprecision_integer_get_value_array(m);
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
    ulong_t * value_array = jk_multiprecision_integer_get_value_array(m);
    const ulong_t * value_array2 = jk_multiprecision_integer_get_value_array(n);
    unsigned precision = m->precision;
    const unsigned precision2 = n->precision;
    ulong_t any_zero = 0;
    ulong_t t;
    unsigned p;

    if (precision > precision2)
    {
        precision = precision2;
    }
    for (p = 0 ; p != precision ; ++p)
    {
        t = (value_array[p] & value_array2[p]);
        value_array[p] = t;
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
    ulong_t * value_array = jk_multiprecision_integer_get_value_array(m);
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
    ulong_t * value_array = 0;
    const ulong_t * value_array2 = jk_multiprecision_integer_get_value_array(m2);
    const unsigned precision = m->precision;
    unsigned precision2 = m2->precision;
    long err = jk_error_uninitialized;
    unsigned p;

    if (precision < precision2)
    {
        err = jk_multiprecision_integer_set_precision(m, precision2);
        if (err < 0) return err;
    }
    value_array = jk_multiprecision_integer_get_value_array(m);
    for (p = 0 ; p != precision2 ; ++p)
    {
        value_array[p] |= value_array2[p];
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
    unsigned new_precision
    )
{
    ulong_t * oldp = 0;
    ulong_t * newp = 0;
    size_t old_precision = m->precision;

    if (new_precision == old_precision)
        return 0;
    if (new_precision < old_precision)
    {
        m->precision = new_precision;
        return 0;
    }

    newp = (ulong_t*)malloc(sizeof(ulong_t) * new_precision);
    if (newp == NULL)
        return jk_out_of_memory_error;

    oldp = jk_multiprecision_integer_get_value_array(m);
    memcpy(newp, oldp, old_precision * sizeof(ulong_t));
    memset(newp + old_precision, 0, (new_precision - old_precision) * sizeof(ulong_t));
    free(m->malloced_value_array);
    m->malloced_value_array = newp;
    m->precision = new_precision;
	m->in_use = jk_multipleprecision_integer_in_use_malloced;
    
    return 0;
}

void
jk_longlong_add(jk_longlong_t * a, const jk_longlong_t * b, const jk_longlong_t * c)
{
    jk_carry_t carry;

    jk_ulong_add_with_carry_out(&a->low, b->low, c->low, &carry);
    jk_long_add_with_carry_in(&a->high, b->high, c->high, carry);
}

void
jk_longlong_add_in_place(jk_longlong_t * a, const jk_longlong_t * b)
{
    jk_carry_t carry;

    jk_ulong_add_with_carry_out(&a->low, a->low, b->low, &carry);
    jk_long_add_with_carry_in(&a->high, a->high, b->high, carry);
}

void
jk_ulonglong_add(jk_ulonglong_t * a, const jk_ulonglong_t * b, const jk_ulonglong_t * c)
{
    jk_carry_t carry;

    jk_ulong_add_with_carry_out(&a->low, b->low, c->low, &carry);
    jk_ulong_add_with_carry_in(&a->high, b->high, c->high, carry);
}

void
jk_ulonglong_add_in_place(jk_ulonglong_t * a, const jk_ulonglong_t * b)
{
    jk_carry_t carry;
    
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
    ulong_t b
    )
{
    jk_carry_t carry;

    jk_ulong_add_with_carry_out(&a->low, b, c->low, &carry);
    a->high += carry;
}

void
jk_add_ulong_to_ulonglong_in_place(
    jk_ulonglong_t * a,
    ulong_t b
    )
{
    jk_carry_t carry;

    jk_ulong_add_in_place_with_carry_out(&a->low, b, &carry);
    a->high += carry;
}

void
jk_longlong_from_long(
    jk_longlong_t * a,
    long b)
{
    a->low = (ulong_t)b;
    a->high = (b < 0) ? -1L : 0L;
}

void
jk_longlong_assign_zero(
    jk_longlong_t * a
    )
{
    a->low = 0;
    a->high = 0;
}

void
jk_ulonglong_assign_zero(
    jk_ulonglong_t * a
    )
{
    a->low = 0;
    a->high = 0;
}

void
jk_ulonglong_from_long(
    jk_ulonglong_t * a,
    long b
    )
{
    a->low = (ulong_t)b;
    a->high = (ulong_t)((b < 0) ? -1L : 0L);
}

void
jk_longlong_from_ulong(
    jk_longlong_t * a,
    ulong_t b
    )
{
    a->low = b;
    a->high = 0;
}

void
jk_ulonglong_from_ulong(
    jk_ulonglong_t * a,
    ulong_t b
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
    ulong_t b
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
    return (((a->low | a->high) != 0) && ((b->low | b->high) != 0));
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
    return (((a->low | a->high) != 0) && ((b->low | b->high) != 0));
}

unsigned
jk_longlong_logical_or(
    const jk_longlong_t * a,
    const jk_longlong_t * b
    )
{
    return ((a->low | a->high | b->low | b->high) != 0);
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

ulong_t
jk_ulong_extract_left_n_bits_right_aligned(ulong_t a, unsigned n)
{
	const unsigned k = jk_bits_of(ulong_t);
    return (a >> (k - n));
}

ulong_t
jk_ulong_extract_left_n_bits(ulong_t a, unsigned n)
{
    return (a & ((~0UL) << n));
}

ulong_t
jk_ulong_extract_right_n_bits(ulong_t a, unsigned n)
{
    return (a & ~((~0UL) << n));
}

ulong_t
jk_ulong_extract_right_n_bits_left_aligned(ulong_t a, unsigned n)
{
	const unsigned k = jk_bits_of(ulong_t);
    return (a << (k - n));
}

void
jk_ulonglong_left_shift(jk_ulonglong_t * a, const jk_ulonglong_t * b, unsigned shift)
{
	const unsigned k = jk_bits_of(ulong_t);
	const unsigned k2 = (k * 2);
	ulong_t a_low = 0;
	ulong_t a_high = 0;
	const ulong_t b_low = b->low;
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
	return (long)(((ulong_t)a) >> shift);
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
ulong_t jk_ulong_with_n_right_bits_clear(unsigned n) { return        ((~0UL) << n); }
ulong_t jk_ulong_with_n_right_bits_set(unsigned n)   { return       ~((~0UL) << n); }
ulong_t jk_ulong_with_n_left_bits_clear(unsigned n)  { return        ((~0UL) >> n); }
ulong_t jk_ulong_with_n_left_bits_set(unsigned n)    { return       ~((~0UL) >> n); }

#define jk_bits_of(x) (sizeof(x)*8)

ulong_t
jk_ulong_rotate_left(
    ulong_t a,
    unsigned b
    )
{
	const unsigned k = jk_bits_of(ulong_t);

	return (a << b) | (a >> (k - b));
}

ulong_t
jk_ulong_rotate_right(
    ulong_t a,
    unsigned b
    )
{
	const unsigned k = jk_bits_of(ulong_t);

	return (a >> b) | (a << (k - b));
}

ulong_t
jk_ulong_one_fill_right_shift(ulong_t a, unsigned shift)
{
	const unsigned k = jk_bits_of(ulong_t);

	return (a >> shift) | ~((~0UL) << (k - shift));
}

ulong_t
jk_ulong_zero_fill_right_shift(ulong_t a, unsigned shift)
{
	return (a >> shift);
}

void
jk_ulonglong_zero_fill_right_shift(jk_ulonglong_t * a, const jk_ulonglong_t * b, unsigned shift)
{
	const unsigned k = jk_bits_of(ulong_t);
	const unsigned k2 = (k * 2);
	ulong_t a_low = 0;
	ulong_t a_high = 0;
	const ulong_t b_high = b->high;
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
	const unsigned k = jk_bits_of(ulong_t);
	const unsigned k2 = (k * 2);
	ulong_t a_low = ~0UL;
	ulong_t a_high = ~0UL;
	const ulong_t b_high = b->high;
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

ulong_t jk_ulong_get_right_justified_high_half(ulong_t a)
{
    return (a >> (jk_bits_of(a) / 2));
}

ulong_t jk_ulong_get_low_half(ulong_t a)
{
    return  (a & (~0UL >> (jk_bits_of(a) / 2)));
}

ulong_t jk_ulong_get_left_justified_high_half(ulong_t a)
{
    return  (a & (~0UL << (jk_bits_of(a) / 2)));
}

void
jk_ulong_multiply_to_ulonglong(jk_ulonglong_t * a, ulong_t b, ulong_t c)
{
    const ulong_t bl = jk_ulong_get_low_half(b);
    const ulong_t bh = jk_ulong_get_right_justified_high_half(b);
    const ulong_t cl = jk_ulong_get_low_half(c);
    const ulong_t ch = jk_ulong_get_right_justified_high_half(c);
    jk_ulonglong_t aa[2];
    jk_carry_t carry;

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
    jk_ulonglong_left_shift_in_place(&aa[1], jk_bits_of(ulong_t)/2);
    jk_ulonglong_add(a, &aa[0], &aa[1]);
}

unsigned long
jkp_common_split_into_magnitude_and_sign(
    long i,
    int * sign
    )
{
    int local_sign;
    unsigned long local_magnitude;
    if (i < 0)
    {
        local_magnitude = ((unsigned long)-(i + 1)) + 1;
        local_sign = -1;
    }
    else
    {
	    local_magnitude = (unsigned long)i;
	    local_sign = 1;
    }
    *sign = local_sign;
    return local_magnitude;
}

void
jk_long_split_into_magnitude_and_sign(
    long i,
    ulong_t * magnitude,
    int * sign
    )
{
	*magnitude = jkp_common_split_into_magnitude_and_sign(i, sign);
}

void
jk_int_split_into_magnitude_and_sign(
    int i,
    unsigned * magnitude,
    int * sign
    )
{
	*magnitude = (unsigned)jkp_common_split_into_magnitude_and_sign((long)i, sign);
}

void
jk_short_split_into_magnitude_and_sign(
    short i,
    unsigned short * magnitude,
    int * sign
    )
{
	*magnitude = (unsigned short)jkp_common_split_into_magnitude_and_sign((long)i, sign);
}

void
jk_signed_char_split_into_magnitude_and_sign(
    signed char i,
    unsigned char * magnitude,
    int * sign
    )
{
	*magnitude = (unsigned char)jkp_common_split_into_magnitude_and_sign((long)i, sign);
}
void
jk_ultoa(
    ulong_t u,
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
    ulong_t magnitude;
    int sign;
	
	jk_function(jk_ltoa);
	jk_profile_count_function_call();

	jk_long_split_into_magnitude_and_sign(i, &magnitude, &sign);
	
    if (sign < 0)
        *a++ = '-';
    jk_ultoa(magnitude, a);
}

void
jk_itoa(
    int i,
    char * a
    )
{
    unsigned magnitude;
    int sign;
	
	jk_function(jk_itoa);
	jk_profile_count_function_call();

	jk_int_split_into_magnitude_and_sign(i, &magnitude, &sign);
	
    if (sign < 0)
        *a++ = '-';
    jk_utoa(magnitude, a);
}

void
jk_longlong_split_into_magnitude_and_sign(
	const jk_longlong_t * i,
    jk_ulonglong_t * magnitude,
    int * sign
    )
{
    int local_sign;
    ulong_t local_low = i->low;
    long local_high = i->high;
    if (local_high < 0)
    {
        local_high = -local_high - (local_low != 0);
        local_low = 0 - local_low;
        local_sign = -1;
    }
    else
    {
        local_sign = +1;
    }
    magnitude->low = local_low;
    magnitude->high = (ulong_t)local_high;
    *sign = local_sign;
}

void
jk_ulonglong_negate(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    )
{
    ulong_t b_low = 0 - b->low;
    a->low = b_low;
    a->high = 0 - b->high - (b_low != 0);
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
    ulong_t b_low = 0 - b->low;
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
    ulong_t ub;
    ulong_t uc;
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
    const ulong_t bl = b->low;
    const ulong_t bh = b->high;
    const ulong_t cl = c->low;
    const ulong_t ch = c->high;
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
    to->high = (ulong_t)from->high;
}

void
jk_ulonglong_from_high_low_32bit_ulongs(
    jk_ulonglong_t * i,
    ulong_t high,
    ulong_t low
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
    jk_function(jk_java_convert_java_double_to_native_double);
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
    ulong_t mantissa_low32;
    ulong_t mantissa_high20;
    double result;
    
	jk_profile_count_function_call();
    
    jk_java_get_ulong(&ll, bytes);
#if 0
    jk_debug_printf("%s 0x%lx 0x%lx\n", function.chars, ll.high, ll.low);
    jk_debug_printf("%s %f\n", function.chars, *(double*)&ll);
#endif
    jk_ulonglong_from_high_low_32bit_ulongs(&positive_infinity, 0x7ff00000ul, 0);    
    if (jk_ulonglong_is_equal(&ll, &positive_infinity))
    {
        /*jk_debug_printf("%s +inf\n", function.chars);*/
        result = jk_java_positive_infinity_double;
        goto exit;
    }
    jk_ulonglong_from_high_low_32bit_ulongs(&negative_infinity, 0xfff00000ul, 0);    
    if (jk_ulonglong_is_equal(&ll, &negative_infinity))
    {
        /*jk_debug_printf("%s -inf\n", function.chars);*/
        result = jk_java_negative_infinity_double;
        goto exit;
    }    
    jk_ulonglong_from_high_low_32bit_ulongs(&nan[0], 0x7ff00000UL, 1);    
    jk_ulonglong_from_high_low_32bit_ulongs(&nan[1], 0x7fffffffUL, 0xffffffffUL);    
    if (jk_ulonglong_is_in_unordered_range_inclusive(&ll, &nan[0], &nan[1]))
    {
#if 0
        jk_debug_printf("%s nan1 0x%lx 0x%lx\n", function.chars, nan[0].high, nan[0].low);
        jk_debug_printf("%s nan1 0x%lx 0x%lx\n", function.chars, nan[1].high, nan[1].low);
        jk_debug_printf("%s nan1\n", function.chars);
#endif
        result = nan_result;
        goto exit;
    }
    jk_ulonglong_from_high_low_32bit_ulongs(&nan[2], 0xfff00000UL, 1);    
    jk_ulonglong_from_high_low_32bit_ulongs(&nan[3], 0xffffffffUL, 0xffffffffUL);    
    if (jk_ulonglong_is_in_unordered_range_inclusive(&ll, &nan[2], &nan[3]))
    {
        /*jk_debug_printf("%s nan2\n", function.chars);*/
        result = nan_result;
        goto exit;
    }
    jk_ulonglong_right_shift(&ll_sign, &ll, 63);
    jk_ulonglong_right_shift(&ll_exponent, &ll, 52);
    jk_ulonglong_from_high_low_32bit_ulongs(&bits52, 0xfffff, 0xffffffff);
    /*jk_debug_printf("%s bits52=0x%lx 0x%lx\n", function.chars, bits52.high, bits52.low);*/
    jk_ulonglong_bitwise_and(&ll_mantissa, &ll, &bits52);
    exponent = (int)(ll_exponent.low & 0x7ff);
    sign = ((ll_sign.low & 1) ? -1 : +1);
    /*jk_debug_printf("%s exponent 0x%x %+d\n", function.chars, (unsigned)exponent, exponent - 1075);*/
    /*jk_debug_printf("%s sign %+d\n", function.chars, sign);*/
    if (exponent == 0)
    {
        jk_ulonglong_left_shift_in_place(&ll_mantissa, 1);
        /*jk_debug_printf("%s exp=0, mant=0x%lx 0x%lx\n", function.chars, ll_mantissa.high, ll_mantissa.low);*/
    }
    else
    {        
        jk_ulonglong_from_high_low_32bit_ulongs(&bit53, 0x100000, 0x00000000);
        jk_ulonglong_bitwise_or_in_place(&ll_mantissa, &bit53);
        /*jk_debug_printf("%s exp!=0, mant=0x%lx 0x%lx\n", function.chars, ll_mantissa.high, ll_mantissa.low);*/
    }    
    mantissa_low32 = (ll_mantissa.low & 0xffffffff);
    jk_ulonglong_right_shift_in_place(&ll_mantissa, 32);
    mantissa_high20 = ll_mantissa.low;    
   /*jk_debug_printf("%s mantissa_high20 0x%lx\n", function.chars, mantissa_high20);*/
   /*jk_debug_printf("%s mantissa_low32 0x%lx\n", function.chars, mantissa_low32);*/
   result = sign * (ldexp(mantissa_low32, exponent - 1075) + ldexp(mantissa_high20, exponent - 1075 + 32));
exit:
    /*jk_debug_printf("%s %f\n", function.chars, result);*/

    return result;
}

float
jk_java_convert_java_float_to_native_float(
    const unsigned char * bytes
    )
{
    jk_function(jk_java_convert_java_float_to_native_float);
    long sign;
    int exponent;
    long mantissa;
    ulong_t i;
    float f;

	jk_profile_count_function_call();

    i = jk_get_big_endian_u4(bytes);
    
#if 0
    jk_debug_printf("%s 0x%lx\n", function.chars, i);
    jk_debug_printf("%s %f\n", function.chars, *(float*)&i);
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
    /*jk_debug_printf("%s %f\n", function.chars, f);*/
exit:
    return f;
}

void
jk_java_free_constant_pool(
    jk_java_constant_pool_t * constant_pool
    )
{
    jk_java_constant_pool_t * x = constant_pool;
	jk_java_any_t * any = x->any;
    unsigned char * tags = x->tags;
	unsigned count = x->count;
	unsigned tag;
	unsigned i;
	
	if (tags != NULL && any != NULL && count != 0)
	{		
		for (i = 1 ; i != count ; ++i)
		{
			switch (tag = tags[i])
			{
	        case jk_java_constant_utf8_tag:
	            jk_free((void**)&any[i].char_pointer);
				break;
			case jk_java_constant_class_tag:
			case jk_java_constant_name_and_type_tag:
			case jk_java_constant_fieldref_tag:
			case jk_java_constant_methodref_tag:
			case jk_java_constant_interfacemethodref_tag:
			case jk_java_constant_string_tag:
			case jk_java_constant_integer_tag:         	
			case jk_java_constant_float_tag:         	
				break;
			 case jk_java_constant_double_tag:         	
			 case jk_java_constant_long_tag:         	
				i += 1;
				break;
			default:
				jk_debug_printf("unknown tag %x\n", tag);
				break;
			}
		}
	}
	jk_free((void**)&x->tags);
	jk_free((void**)&x->any);
}

JK_ORCAC_SEGMENT

long
jk_hashtable_init(
    jk_hashtable_t * hashtable,
    jk_hashtable_static_context_t * context
    )
{
    jk_function(jk_hashtable_init);
	
    JK_CHECK_PARAMETER(hashtable != NULL);
    
    hashtable->context = context;
    hashtable->number_of_elements = 0;
    hashtable->number_of_outstanding_iterators = 0;
    jk_array_init(&hashtable->buckets, 0, 0); /* undone */
    return 0;
}

long
jk_hashtable_get_size(
    jk_hashtable_t * hashtable,
    size_t * size
    )
{
    jk_function(jk_hashtable_get_size);

    JK_CHECK_PARAMETER(hashtable != NULL);
    JK_CHECK_PARAMETER(size != NULL);

    *size = hashtable->number_of_elements;
    
    return 0;
}    

JK_ORCAC_SEGMENT

void
jk_java_get_ulong(
    jk_ulonglong_t * i,
    const unsigned char * p
    )
{
	i->high =  (((ulong_t)p[0]) << 24)
            | (((ulong_t)p[1]) << 16)
            | (((ulong_t)p[2]) << 8)
            | ((ulong_t)p[3])
            ;
    i->low =   (((ulong_t)p[4]) << 24)
            | (((ulong_t)p[5]) << 16)
            | (((ulong_t)p[6]) << 8)
            | ((ulong_t)p[7])
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
jk_java_read_constant_pool(
    jk_file_t * file,
    jk_java_constant_pool_t * constant_pool
    )
{
    jk_function(jk_java_read_constant_pool);
    long err = jk_error_uninitialized;
    unsigned constants_read;
    unsigned count = constant_pool->count;
    unsigned char * buffer;
    unsigned char * tags;
    unsigned char tag;
	jk_java_any_t * any;
	unsigned string_index;
	unsigned class_index;
	unsigned name_and_type_index;
	unsigned name_index;
	unsigned type_index;
	ulong_t unsigned_long;
	unsigned utf8_length_in_bytes;
	char* char_pointer;
	size_t bytes_read;
	float native_float;
	double native_double;

	jk_profile_count_function_call();

    constant_pool->tags = 0;
    constant_pool->any = 0;

	err = jk_malloc((void**)&tags, count);
	if (err < 0) goto exit;
    constant_pool->tags = tags;

	err = jk_malloc((void**)&any, sizeof(*any) * count);
	if (err < 0) goto exit;
    constant_pool->any = any;

	/* all constants are at least 3 bytes, so read that much now
	   as we read the tags and we discover the full sizes, we read ahead
	   a little extra (read ahead just bumps up the number of bytes
	   to be read the next time we hit the end of our buffer)
	*/
    err = jk_file_read_ahead(file, 3 * count);
    if (err < 0) goto exit;

    for ( constants_read = 1 ; constants_read != count ; ++constants_read )
    {
        #if 0
        jk_debug_printf("%s 0x%x 0x%x\n", function.chars, constants_read, count);
        #endif
    	err = jk_file_read_get_buffer(file, (void**)&buffer, 3, NULL);
    	if (err < 0) goto exit;
    	tag = buffer[0];
    	tags[constants_read] = tag;
    	switch (tag)
    	{
    	case jk_java_constant_class_tag:
            class_index = jk_get_big_endian_u2(buffer + 1);
            any[constants_read].unresolved_constant.class_ref.class_index = class_index;
    	    jk_debug_printf("%s jk_java_constant_class tag=0x%x class=0x%x\n", function.chars, tag, class_index);
    		break;
    	case jk_java_constant_name_and_type_tag:
			err = jk_file_read_ahead(file, 2);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(file, (void**)&buffer, 2, NULL);
    		if (err < 0)
    			goto exit;
            name_index = jk_get_big_endian_u2(buffer - 2);
            type_index = jk_get_big_endian_u2(buffer);
            any[constants_read].unresolved_constant.name_and_type.name_index = name_index;
            any[constants_read].unresolved_constant.name_and_type.type_index = type_index;
    	    jk_debug_printf("%s jk_java_constant_name_and_type tag=0x%x name=0x%x type=0x%x\n", function.chars, tag, name_index, type_index);
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
            class_index = jk_get_big_endian_u2(buffer - 2);
            name_and_type_index = jk_get_big_endian_u2(buffer);
            any[constants_read].unresolved_constant.member_ref.class_index = class_index;
            any[constants_read].unresolved_constant.member_ref.name_and_type_index = name_and_type_index;
    	    jk_debug_printf("%s jk_java_constant_ref tag=0x%x class=0x%x name_and_type=0x%x\n", function.chars, tag, class_index, name_and_type_index);
            break;
         case jk_java_constant_string_tag:
            string_index = jk_get_big_endian_u2(buffer + 1);
            any[constants_read].unresolved_constant.string_ref.string_index = string_index;
    	    jk_debug_printf("%s jk_java_constant_string tag=0x%x string=%x\n", function.chars, tag, string_index);
         	break;
         case jk_java_constant_integer_tag:         	
			err = jk_file_read_ahead(file, 2);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(file, (void**)&buffer, 2, NULL);
    		if (err < 0)
    			goto exit;
			unsigned_long = jk_get_big_endian_u4(buffer - 2);
			any[constants_read].UnsignedLong = unsigned_long;
    	    jk_debug_printf("%s jk_java_constant_integer tag=0x%x 0x%lx\n", function.chars, tag, unsigned_long);
    		break;
         case jk_java_constant_float_tag:         	
			err = jk_file_read_ahead(file, 2);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(file, (void**)&buffer, 2, NULL);
    		if (err < 0)
    			goto exit;
			native_float = jk_java_convert_java_float_to_native_float(buffer - 2);
			any[constants_read].native_float = native_float;
    	    jk_debug_printf("%s jk_java_constant_float tag=0x%x %f\n", function.chars, tag, native_float);
    		break;
         case jk_java_constant_double_tag:         	
			err = jk_file_read_ahead(file, 3);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(file, (void**)&buffer, 6, NULL);
    		if (err < 0)
    			goto exit;
			native_double = jk_java_convert_java_double_to_native_double(buffer - 2);
			any[constants_read].native_double = native_double;
			constants_read += 1;
    	    jk_debug_printf("%s jk_java_constant_double 0x%x %f\n", function.chars, tag, native_double);
    		break;
         case jk_java_constant_long_tag:         	
			err = jk_file_read_ahead(file, 3);
    		if (err < 0)
    			goto exit;
            err = jk_file_read_get_buffer(file, (void**)&buffer, 6, NULL);
    		if (err < 0)
    			goto exit;
			jk_java_get_long(&any[constants_read].LongLong, buffer - 2);
			constants_read += 1;
    	    jk_debug_printf("%s jk_java_constant_long 0x%x\n", function.chars, tag);
    		break;
        case jk_java_constant_utf8_tag:
            utf8_length_in_bytes = jk_get_big_endian_u2(buffer + 1);
			err = jk_file_read_ahead(file, utf8_length_in_bytes);
    		if (err < 0)
    			goto exit;
    		err = jk_malloc((void**)&char_pointer, utf8_length_in_bytes + 1);
    		if (err < 0)
    			goto exit;
    		err = jk_file_read_copy(file, char_pointer, utf8_length_in_bytes, &bytes_read);
    		if (err < 0)
    			goto exit;
    		char_pointer[utf8_length_in_bytes] = 0;
            any[constants_read].char_pointer = char_pointer;
    	    jk_debug_printf("%s jk_java_constant_utf8 tag=0x%x length=0x%x %s\n", function.chars, tag, utf8_length_in_bytes, char_pointer);
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
		jk_printf("%s exiting with %ld\n", function.chars, err);
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

	jk_function(jk_init_file_buffer);
	jk_profile_count_function_call();
	
	x->buffer = 0;
	x->buffer_size = 0;
	x->bytes_in_buffer = 0;
	x->position = 0;
	x->read_ahead = 0;
	x->keep_all_bytes = 0;
	return 0;
}

long
jk_free_file_buffer(
	jk_file_buffer_t * file_buffer
	)
{
	jk_function(jk_free_file_buffer);
	jk_profile_count_function_call();
	jk_free((void**)&file_buffer->buffer);
	return 0;
}

long
jk_init_file(
	jk_file_t * file
	)
{
	jk_file_t * const x = file;

	jk_function(jk_init_file);
	jk_profile_count_function_call();

	x->stdio_file = 0;
	x->file_path = 0;
	x->openmode = 0;
	jk_init_file_buffer(&x->buffer);
	return 0;
}

long
jk_free_file(
	jk_file_t * file
	)
{
	jk_function(jk_free_file);
	jk_profile_count_function_call();
	jk_file_close(file);
	jk_free_file_buffer(&file->buffer);
	return 0;
}

long
jk_java_init_constant_pool(
	jk_java_constant_pool_t * constant_pool
	)
{
	jk_java_constant_pool_t * const x = constant_pool;
	jk_function(jk_java_init_constant_pool);
	jk_profile_count_function_call();
	x->count = 0;
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
	
	jk_function(jk_java_init_classfile);
	jk_profile_count_function_call();

	jk_zero_memory(classfile, sizeof(*classfile));

	x->magic[0] = 0;
	x->magic[1] = 0;
	x->magic[2] = 0;
	x->magic[3] = 0;
	x->minor_version = 0;	
	x->major_version = 0;
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

long
jk_java_free_classfile(
    jk_java_classfile_t * classfile
    )
{
	jk_java_classfile_t * const x = classfile;
	jk_function(jk_java_free_classfile);
	jk_profile_count_function_call();
	jk_java_free_constant_pool(&x->constant_pool);
	jk_free_file(&x->file);
	return 0;
}

long
jk_java_read_classfile(
    const jk_globals_t * globals,
    jk_java_classfile_t ** ppcf,
    const char * filepath
    )
{
	jk_function(jk_java_read_classfile);
    jk_java_classfile_t classfile;
    jk_file_t * file = &classfile.file;
    jk_array_t array_uint = { 0 };
    uint_t array_uint_base;
    long err = -1;

	jk_profile_count_function_call();

	jk_unused(ppcf);
    jk_array_init(&array_uint, &jk_type_uint, globals->default_memory_allocator);
	jk_java_init_classfile(&classfile);
	classfile.file.buffer.keep_all_bytes = 1;

	err = jk_file_open_for_read(globals, file, filepath);
    if (err < 0)
        goto exit;

	err = jk_file_read_ahead(file, sizeof(jk_java_packed_classfile3_t));
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
    
    err = jk_java_read_constant_pool(&classfile.file, &classfile.constant_pool);
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

    err = jk_array_set_size(&array_uint, classfile.interfaces_count);
    if (err < 0)
        goto exit;
        
    err = jk_array_get_base(&array_uint, (void**)&array_uint_base);
    if (err < 0)
        goto exit;
        
    err =
        jk_file_read_and_unpack_array(
            globals,
            file,
            &array_uint,
            0,
            classfile.interfaces_count);
    if (err < 0)
        goto exit;
    
    jk_dump_struct(globals, jk_debug_string("classfile."), (void*)&classfile, globals->java_packed_classfile_type_info); 

    err = 0;
exit:
	if (err < 0) {
		jk_printf("%s existing with %ld\n", function.chars, err);
	}
	jk_java_free_classfile(&classfile);
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
jk_array_get_element_type(
    jk_array_t * array,
    const jk_type_t ** element_type
    )
{
    *element_type = array->element_type;
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
    jk_opaque_cookie_t new_bytes = {{{ 0 }}};
    /*const*/ jk_memory_allocator_functions_t * memory_allocator_functions;
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
    if (iterator1->array == iterator2->array && iterator1->index == iterator2->index)
    {
        *is_equal = jk_true;
    }
    else
    {
        *is_equal = jk_false;
    }
    return 0;
}

void
jk_opaque_cookie_init(
	jk_opaque_cookie_t * cookie
	)
{
	jk_opaque_cookie_t z = {{{ 0 }}};
	*cookie	= z;
}

long
jk_buffer_init(
	jk_buffer_t * buffer,
	size_t preallocated_buffer_size,
	void * preallocated_buffer
	)
{
	buffer->allocator = &jk_default_memory_allocator;
	jk_opaque_cookie_init(&buffer->cookie);
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
		(*allocator->functions->free)(allocator, &buffer->cookie);
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
	jk_opaque_cookie_t cookie = {{{ 0 }}};
    jk_memory_allocator_t * allocator = (jk_memory_allocator_t *)jk_pointer_uninitialized;
    jk_memory_allocator_functions_t * functions = (jk_memory_allocator_functions_t *)jk_pointer_uninitialized;
    jk_memory_allocator_functions_allocate_t allocate = (jk_memory_allocator_functions_allocate_t)jk_function_pointer_uninitialized;
    jk_memory_allocator_functions_convert_cookie_to_pointer_t convert_cookie_to_pointer = (jk_memory_allocator_functions_convert_cookie_to_pointer_t)jk_function_pointer_uninitialized;
	
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
	functions = allocator->functions;
	allocate = functions->allocate;
	err = (*allocate)(allocator, allocated_size, &cookie);
	if (err < 0 && allocated_size > size)
	{
		allocated_size = size;
		err = (*allocate)(allocator, allocated_size, &cookie);
		if (err < 0)
			goto exit;
	}
	convert_cookie_to_pointer = functions->convert_cookie_to_pointer;
	err = (*convert_cookie_to_pointer)(allocator, cookie, &bytes);
	if (err < 0)
		goto exit;
success:
	buffer->allocated_size = allocated_size;
	buffer->requested_size = size;
	buffer->bytes = bytes;
	buffer->cookie = cookie;
	if (pointer != NULL)
		*pointer = bytes;
	err = 0;
exit:
	return err;
}

long jk_interlocked_increment_long(long * i)
{
	return ++*i;
}

long jk_interlocked_decrement_long(long * i)
{
	return --*i;
}

void jk_memory_barrier(void)
{
	static long i;
	
	jk_interlocked_increment_long(&i);
}

void jk_spin(int i)
{
	while (i--)
	{
	}
}

void jk_sleep(int i)
{
	jk_spin(i * 2 + 1);
}

void jk_initialize_spin_lock(jk_spin_lock_t * lock)
{
	*lock = 0;
}

void jk_acquire_spin_lock(jk_spin_lock_t * lock, jk_irql_t * previous_irql)
{
	while (*lock)
	{
		jk_sleep(1);
	}
	*lock = 1;
	*previous_irql = 0;
}

void jk_release_spin_lock(jk_spin_lock_t * lock, jk_irql_t previous_irql)
{
	*lock = previous_irql;
}

/*const*/
jk_memory_allocator_functions_t
jk_default_memory_allocator_functions = {
    jk_default_memory_allocator_allocate,
    jk_default_memory_allocator_free,
    jk_default_memory_allocator_convert_cookie_to_pointer
};

jk_memory_allocator_t
jk_default_memory_allocator = {
    &jk_default_memory_allocator_functions
};

jk_fields_t jk_fields;

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
    sizeof(uint_t),
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
    sizeof(ulong_t),
	jk_type_construct_n_do_nothing, jk_type_destroy_n_do_nothing,
	jk_type_copy_n_copy_memory, jk_type_move_n_copy_memory,
	jk_false,
	jk_type_get_dump_length_unsigned_long,
	jk_type_dump_unsigned_long
};

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

long
jk_unpack_field_packed_little_endian_uint64_to_jk_ulonglong(
	const jk_field_t * field,
	const void * vfrom,
	void /*jk_ulonglont_t*/ * vto
	)
{
	const jk_byte_t * from = (const jk_byte_t*)vfrom;
	
	jk_unused(&field);

    jk_ulonglong_from_high_low_32bit_ulongs(
        (jk_ulonglong_t *)vto,
        jk_get_little_endian_u4(from),
        jk_get_little_endian_u4(from + 4));
        
    return 0;
}

const jk_field_unpackers_t jk_field_unpackers = {
    0,
    &jk_unpack_field_packed_little_endian_uint64_to_jk_ulonglong
};

jk_struct_t jk_java_classfile_type_info;
jk_struct_t jk_java_classfile1_type_info;
jk_struct_t jk_java_classfile2_type_info;

jk_globals_t jk_globals = {
    &jk_fields,
    &jk_types,
    &jk_java_classfile_type_info,
    &jk_java_classfile1_type_info,
    &jk_java_classfile2_type_info,
    &jk_default_memory_allocator,
    0,
    0,
    0
};

void
jk_dump_environment_variablese(
    const jk_globals_t * globals
    )
{
    char ** env = globals->environment_variables;
    
    if (env && *env)
    {
        while (*env)
        {
            printf("%s\n", *env++);
        }
    }
}

#if 1

#define jk_offset_to_pointer(t,p,o) ((t*)(((size_t)(p)) + (o)))

typedef struct jk_processor_t {
	jk_constant_string_t name;
} jk_processor_t;

jk_processor_t processor_8086;
jk_processor_t processor_80286;
jk_processor_t processor_80386;
jk_processor_t processor_80486;
jk_processor_t processor_pentium;
jk_processor_t processor_pentiumpro;
jk_processor_t processor_pentiumii;
jk_processor_t processor_pentiumiii;
jk_processor_t processor_pentiumiv;
jk_processor_t processor_athlon;
jk_processor_t processor_x86;
jk_processor_t processor_alpha;
jk_processor_t processor_vax;
jk_processor_t processor_power;
jk_processor_t processor_power2;
jk_processor_t processor_rs6000;
jk_processor_t processor_powerpc_601;
jk_processor_t processor_powerpc_603;
jk_processor_t processor_powerpc;
jk_processor_t processor_68000;
jk_processor_t processor_68020;
jk_processor_t processor_68040;
jk_processor_t processor_68k;
jk_processor_t processor_mips32le;
jk_processor_t processor_mips32be;
jk_processor_t processor_mips64le;
jk_processor_t processor_mips64be;
jk_processor_t processor_ia64;
jk_processor_t processor_amd64;
jk_processor_t processor_6502;
jk_processor_t processor_65c02;
jk_processor_t processor_65816;
jk_processor_t processor_sparc32;
jk_processor_t processor_sparc64;
jk_processor_t processor_hppa;
jk_processor_t processor_sh3;
jk_processor_t processor_sh4;
jk_processor_t processor_sh5;

typedef struct jk_executable_file_format_t {
	jk_constant_string_t name;
} jk_executable_file_format_t;

typedef struct jk_executable_file_t {
	jk_executable_file_format_t * format;
} jk_executable_file_t;

jk_executable_file_format_t exe_elf32le;
jk_executable_file_format_t exe_elf32be;
jk_executable_file_format_t exe_elf64le;
jk_executable_file_format_t exe_elf64be;
jk_executable_file_format_t exe_mspecoff32;
jk_executable_file_format_t exe_mspecoff64;
jk_executable_file_format_t exe_macho;
jk_executable_file_format_t exe_pef;
jk_executable_file_format_t exe_appleiigs_omf;
jk_executable_file_format_t exe_xcoff;
jk_executable_file_format_t exe_aout;
jk_executable_file_format_t exe_bout;

typedef struct jk_object_file_format_t {
	jk_constant_string_t name;
	long (*read_file)(struct jk_object_file_format_t* format, const char* file, struct jk_object_file_t** out_objfile);
	long (*write_file)(struct jk_object_file_format_t* format, struct jk_object_file_t* objfile, const char* filepath);
} jk_object_file_format_t;

typedef struct jk_object_file_t {
	struct jk_object_file_format_t * format;
} jk_object_file_t;

jk_object_file_format_t obj_elf32le;
jk_object_file_format_t obj_elf32be;
jk_object_file_format_t obj_elf64le;
jk_object_file_format_t obj_elf64be;
jk_object_file_format_t obj_mspecoff32;
jk_object_file_format_t obj_mspecoff64;
jk_object_file_format_t obj_macho;
jk_object_file_format_t obj_appleiigs_omf;
jk_object_file_format_t obj_xcoff;

void
jk_init_position_independent_one_shot_heap(
	jk_position_independent_one_shot_heap_t * heap
	)
{
	heap->bytes = 0;
	heap->size = 0;
	heap->allocated_size = 0;
}

void
jk_destroy_position_independent_one_shot_heap(
	jk_position_independent_one_shot_heap_t * heap
	)
{
	jk_free((void**)&heap->bytes);
	heap->size = 0;
	heap->allocated_size = 0;
}

void
jk_allocate_from_position_independent_one_shot_heap(
	jk_position_independent_one_shot_heap_t * heap,
	unsigned long * offset,
	/* optional */void ** pointer
	);

void
jk_get_pointer_in_position_independent_one_shot_heap(
	jk_position_independent_one_shot_heap_t * heap,
	unsigned long offset,
	void ** pointer
	);
	
/*
a static library is primarily an indexed collection of object files
*/

typedef struct jk_static_library_file_format_t {
	jk_constant_string_t name;
	long (*read_file)(struct jk_static_library_file_format_t* format, const char*, struct jk_static_library_file_t** out_libfile);
	long (*write_file)(struct jk_static_library_file_format_t* format, struct jk_static_library_file_t* libfile, const char* filepath);
} jk_static_library_file_format_t;

typedef struct jk_static_library_file_symbol_t {
	unsigned long name_offset;
	unsigned long object_index;
} jk_static_library_file_symbol_t;

typedef struct jk_static_library_file_t {
	struct jk_static_library_file_format_t * format;
	unsigned long number_of_objects;
	unsigned long number_of_symbols;
	jk_static_library_file_symbol_t * symbols;
	jk_object_file_t ** objects;
} jk_static_library_file_t;

jk_static_library_file_format_t lib_elf32le = { jk_constant_string("lib_elf32le") };
jk_static_library_file_format_t lib_elf32be = { jk_constant_string("lib_elf32be") };
jk_static_library_file_format_t lib_elf64le = { jk_constant_string("lib_elf64le") };
jk_static_library_file_format_t lib_elf64be = { jk_constant_string("lib_elf64be") };
jk_static_library_file_format_t lib_mspecoff32 = { jk_constant_string("lib_mspecoff64") };
jk_static_library_file_format_t lib_mspecoff64 = { jk_constant_string("lib_mspecoff64") };
jk_static_library_file_format_t lib_macho = { jk_constant_string("lib_macho") };
jk_static_library_file_format_t lib_appleiigs_omf = { jk_constant_string("lib_appleiigs_omf") };
jk_static_library_file_format_t lib_xcoff = { jk_constant_string("lib_xcoff") };

typedef struct jk_platform_t {
	jk_constant_string_t                name;
	jk_processor_t *                    processor;
	jk_object_file_format_t *           obj_file_format;
	jk_static_library_file_format_t *   lib_file_format;
	jk_executable_file_format_t *       exe_file_format;

    unsigned                            bits_in_integer : 8;
    unsigned                            bits_in_pointer : 8;
    unsigned                            has_int64 : 1;
    unsigned                            has_longlong : 1;
	unsigned                            endian : 1;
	jk_type_t *                         types;
} jk_platform_t;

jk_platform_t platform_msdos_small = { jk_constant_string("platform_msdos_small"), 0, 0, 0, 0, 16, 16, 0, 0, 0, 0 };
jk_platform_t platform_msdos_large = { jk_constant_string("platform_msdos_large"), 0, 0, 0, 0, 16, 32, 0, 0, 0, 0 };
jk_platform_t platform_msdos_32bit = { jk_constant_string("platform_msdos_32bit"), 0, 0, 0, 0, 32, 32, 0, 0, 0, 0 };
jk_platform_t platform_iigs  = { jk_constant_string("platform_iigs"), &processor_65816, &obj_appleiigs_omf, &lib_appleiigs_omf, &exe_appleiigs_omf, 16, 32, 0, 0, 0 };
jk_platform_t platform_win32_x86_microsoft = { jk_constant_string("platform_win32_x86"), &processor_x86,  &obj_mspecoff32, &lib_mspecoff32, &exe_mspecoff32, 32, 32, 0, 0, 0 };
jk_platform_t platform_win32_powerpc_microsoft = { jk_constant_string("platform_win32_powerpc"), &processor_powerpc,  &obj_mspecoff32, &lib_mspecoff32, &exe_mspecoff32, 32, 32, 0, 0, 0, 0 };
jk_platform_t platform_win32_alpha_microsoft = { jk_constant_string("platform_win32_alpha"), &processor_alpha,  &obj_mspecoff32, &lib_mspecoff32, &exe_mspecoff32, 32, 32, 0, 0, 0, 0 };
jk_platform_t platform_win32_mips_microsoft = { jk_constant_string("platform_win32_mips"), &processor_mips32le,  &obj_mspecoff32, &lib_mspecoff32, &exe_mspecoff32, 32, 32, 0, 0, 0, 0 };
jk_platform_t platform_win64_ia64_microsoft = { jk_constant_string("platform_win64_ia64"), &processor_ia64,  &obj_mspecoff64, &lib_mspecoff64, &exe_mspecoff64, 32, 64, 0, 0, 0, 0 };
jk_platform_t platform_win64_amd64_microsoft = { jk_constant_string("platform_win64_amd64"), &processor_amd64,  &obj_mspecoff64, &lib_mspecoff64, &exe_mspecoff64, 32, 64, 0, 0, 0, 0 };
jk_platform_t platform_mac_68k_2i         = { jk_constant_string("platform_mac_68k_2i"), &processor_68k, 0, 0, 0, 16, 32, 0, 0, 0, 0 };
jk_platform_t platform_mac_68k_4i         = { jk_constant_string("platform_mac_68k_4i"), &processor_68k, 0, 0, 0, 32, 32, 0, 0, 0, 0 };
jk_platform_t platform_mac_68k_cfm        = { jk_constant_string("platform_mac_68k_cfm"), &processor_68k, 0, 0, 0, 32, 32, 0, 0, 0, 0 };
jk_platform_t platform_mac_powerpc_cfm    = { jk_constant_string("platform_mac_powerpc_cfm"), &processor_powerpc, 0, 0, 0, 32, 32, 0, 0, 0, 0 };
jk_platform_t platform_mac_powerpc_carbon_cfm = { jk_constant_string("platform_mac_powerpc_carbon_cfm"), &processor_powerpc, 0, 0, 0, 32, 32, 0, 0, 0, 0 };
jk_platform_t platform_mac_powerpc_carbon_macho = { jk_constant_string("platform_mac_powerpc_carbon_macho"), &processor_powerpc, 0, 0, 0, 32, 32, 0, 0, 0, 0 };
jk_platform_t platform_mac_powerpc_macho  = { jk_constant_string("platform_mac_powerpc_macho"), &processor_powerpc, 0, 0, 0, 32, 32, 0, 0, 0, 0 };

void
jk_init_platforms(
    void
    )
/*
iigs int2, long4, ptr4, little endian, no longlong, no int64
Microsoft win16?
Microsoft win32 (x86, mips, powerpc, alpha) int4, long4, litte endian, no longlong, int64
Microsoft win64 (alpha64, ia64, amd64) int4, long4,  litte endian, no longlong, int64
gcc win32, int4, long4, little endian, longlong, no int64
gcc win64, int4, long4, little endian, longlong, no int64
gcc x86, int4, long4, little endian, longlong, no int64
gcc alpha, int4, long8?, little endian?, longlong, no int64
Macintosh 2i 68k
Macintosh 4i 68k
Macintosh 4i 68k cfm
Macintosh PowerPC cfm
Macintosh PowerPC macho
MS-DOS?
calling conventions
exception handling
*/
{
    typedef struct local_t {
        jk_constant_string_t name_char;
        jk_constant_string_t name_uchar;
        jk_constant_string_t name_schar;
        jk_constant_string_t name_short;
        jk_constant_string_t name_ushort;
        jk_constant_string_t name_int;
        jk_constant_string_t name_uint;
        jk_constant_string_t name_long;
        jk_constant_string_t name_ulong;
        jk_type_t t_plain_uchar;
        jk_type_t t_plain_schar;
        jk_type_t t_schar;
        jk_type_t t_uchar;
        jk_type_t t_short;
        jk_type_t t_ushort;
        jk_type_t t_int2;
        jk_type_t t_uint2;
        jk_type_t t_int4;
        jk_type_t t_uint4;
        jk_type_t t_long4;
        jk_type_t t_ulong4;
        jk_type_t t_long8;
        jk_type_t t_ulong8;
        jk_type_t t_int64;
        jk_type_t t_uint64;
        jk_type_t t_longlong;
        jk_type_t t_ulonglong;
    } local_t;
    local_t t;
#define JKX(x) offsetof(local_t, x)
    JK_STATIC_CONST struct {
        unsigned short t_offset;
        unsigned short size;
    } sizes[] = {
        { JKX(t_plain_uchar), 1 }, { JKX(t_plain_schar), 1 }, { JKX(t_schar), 1 }, { JKX(t_uchar), 1 },
        { JKX(t_short), 2 }, { JKX(t_ushort), 2 }, { JKX(t_int2), 2 }, { JKX(t_uint2), 2 },
        { JKX(t_int4), 4 }, { JKX(t_uint4), 4 }, { JKX(t_long4), 4 }, { JKX(t_ulong4), 4 },
        { JKX(t_long8), 8 },  { JKX(t_ulong8), 8 }, { JKX(t_int64), 8 }, { JKX(t_uint64), 8 },
        { JKX(t_longlong), 8 }, { JKX(t_ulonglong), 8 }
    };
    JK_STATIC_CONST struct {
        unsigned short t_offset;
        unsigned is_signed : 1;
    } signedness[] = {
        { JKX(t_plain_uchar), 0 }, { JKX(t_plain_schar), 1 }, { JKX(t_schar), 1 }, { JKX(t_uchar), 0 },
        { JKX(t_short), 1 }, { JKX(t_ushort), 0 }, { JKX(t_int2), 1 }, { JKX(t_uint2), 0 },
        { JKX(t_int4), 1 }, { JKX(t_uint4), 0 }, { JKX(t_long4), 1 }, { JKX(t_ulong4), 0 },
        { JKX(t_long8), 1 },  { JKX(t_ulong8), 0 }, { JKX(t_int64), 1 }, { JKX(t_uint64), 0 },
        { JKX(t_longlong), 1 }, { JKX(t_ulonglong), 0 }
    };
    JK_STATIC_CONST struct {
        unsigned short t_offset;
        jk_constant_string_t name;
    } strings[] = {
        { JKX(name_char), jk_constant_string("char") },
        { JKX(name_uchar), jk_constant_string("unsigned char") },
        { JKX(name_schar), jk_constant_string("signed char") },
        { JKX(name_short), jk_constant_string("short") },
        { JKX(name_ushort), jk_constant_string("unsigned short") },
        { JKX(name_int), jk_constant_string("int") },
        { JKX(name_uint), jk_constant_string("unsigned int") },
        { JKX(name_long), jk_constant_string("long") },
        { JKX(name_ulong), jk_constant_string("unsigned long") }
    };
#undef JKX
    size_t i;
    jk_zero_memory(&t, sizeof(t));
    for (i = 0 ; i != jk_number_of(strings) ; ++i) {
        jk_constant_string_t * p = jk_offset_to_pointer(jk_constant_string_t, &t, strings[i].t_offset);
        *p = strings[i].name;
    }   
    for (i = 0 ; i != jk_number_of(sizes) ; ++i) {
        jk_type_t * p = jk_offset_to_pointer(jk_type_t, &t, sizes[i].t_offset);
        p->size = sizes[i].size;
        p->aligned_size = sizes[i].size;
    }
    for (i = 0 ; i != jk_number_of(signedness) ; ++i) {
        jk_type_t * p = jk_offset_to_pointer(jk_type_t, &t, signedness[i].t_offset);
        p->u.integer.ets = signedness[i].is_signed ? ets_signed : ets_unsigned;
    }
    t.t_plain_schar.name = t.name_char;
    t.t_plain_uchar.name = t.name_char;
    t.t_schar.name = t.name_schar;
    t.t_uchar.name = t.name_uchar;
    t.t_short.name = t.name_short;
    t.t_ushort.name = t.name_ushort;
    t.t_int2.name = t.name_int;
    t.t_int4.name = t.name_int;
    t.t_uint2.name = t.name_uint;
    t.t_uint4.name = t.name_uint;
    t.t_long4.name = t.name_long;
    t.t_long8.name = t.name_long;
    t.t_ulong4.name = t.name_ulong;
    t.t_ulong8.name = t.name_ulong;
}

#endif

JK_EXTERN_C_END

#if 1

struct jk_character_bitmap_8_t {
	unsigned x00:1,x01:1,x02:1,x03:1,x04:1,x05:1,x06:1,x07:1;
};

struct jk_character_bitmap_11_t {
	unsigned x00:1,x01:1,x02:1,x03:1,x04:1,x05:1,x06:1,x07:1;
	unsigned x08:1,x09:1,x0a:1;
};

struct jk_character_bitmap_16_t {
	unsigned x00:1,x01:1,x02:1,x03:1,x04:1,x05:1,x06:1,x07:1,x08:1,x09:1,x0a:1,x0b:1,x0c:1,x0d:1,x0e:1,x0f:1;
};

struct jk_character_bitmap_21_t {
	unsigned x00:1,x01:1,x02:1,x03:1,x04:1,x05:1,x06:1,x07:1,x08:1,x09:1,x0a:1,x0b:1,x0c:1,x0d:1,x0e:1,x0f:1;
	unsigned x10:1,x11:1,x12:1,x13:1,x14:1;
};

struct jk_character_bitmap_24_t {
	unsigned x00:1,x01:1,x02:1,x03:1,x04:1,x05:1,x06:1,x07:1,x08:1,x09:1,x0a:1,x0b:1,x0c:1,x0d:1,x0e:1,x0f:1;
	unsigned x10:1,x11:1,x12:1,x13:1,x14:1,x15:1,x16:1,x17:1;
};

struct jk_character_bitmap_32_t {
	unsigned x00:1,x01:1,x02:1,x03:1,x04:1,x05:1,x06:1,x07:1,x08:1,x09:1,x0a:1,x0b:1,x0c:1,x0d:1,x0e:1,x0f:1;
	unsigned x10:1,x11:1,x12:1,x13:1,x14:1,x15:1,x16:1,x17:1,x18:1,x19:1,x1a:1,x1b:1,x1c:1,x1d:1,x1e:1,x1f:1;
};

struct jk_character_bitmap_40_t {
	unsigned x00:1,x01:1,x02:1,x03:1,x04:1,x05:1,x06:1,x07:1,x08:1,x09:1,x0a:1,x0b:1,x0c:1,x0d:1,x0e:1,x0f:1;
	unsigned x10:1,x11:1,x12:1,x13:1,x14:1,x15:1,x16:1,x17:1,x18:1,x19:1,x1a:1,x1b:1,x1c:1,x1d:1,x1e:1,x1f:1;
	unsigned x20:1,x21:1,x22:1,x23:1,x24:1,x25:1,x26:1,x27:1;
};

struct jk_character_bitmap_48_t {
	unsigned x00:1,x01:1,x02:1,x03:1,x04:1,x05:1,x06:1,x07:1,x08:1,x09:1,x0a:1,x0b:1,x0c:1,x0d:1,x0e:1,x0f:1;
	unsigned x10:1,x11:1,x12:1,x13:1,x14:1,x15:1,x16:1,x17:1,x18:1,x19:1,x1a:1,x1b:1,x1c:1,x1d:1,x1e:1,x1f:1;
	unsigned x20:1,x21:1,x22:1,x23:1,x24:1,x25:1,x26:1,x27:1,x28:1,x29:1,x2a:1,x2b:1,x2c:1,x2d:1,x2e:1,x2f:1;
};

struct jk_character_bitmap_64_t {
	unsigned x00:1,x01:1,x02:1,x03:1,x04:1,x05:1,x06:1,x07:1,x08:1,x09:1,x0a:1,x0b:1,x0c:1,x0d:1,x0e:1,x0f:1;
	unsigned x10:1,x11:1,x12:1,x13:1,x14:1,x15:1,x16:1,x17:1,x18:1,x19:1,x1a:1,x1b:1,x1c:1,x1d:1,x1e:1,x1f:1;
	unsigned x20:1,x21:1,x22:1,x23:1,x24:1,x25:1,x26:1,x27:1,x28:1,x29:1,x2a:1,x2b:1,x2c:1,x2d:1,x2e:1,x2f:1;
	unsigned x30:1,x31:1,x32:1,x33:1,x34:1,x35:1,x36:1,x37:1,x38:1,x39:1,x3a:1,x3b:1,x3c:1,x3d:1,x3e:1,x3f:1;
};

struct jk_character_bitmap_128_t {
	unsigned x00:1,x01:1,x02:1,x03:1,x04:1,x05:1,x06:1,x07:1,x08:1,x09:1,x0a:1,x0b:1,x0c:1,x0d:1,x0e:1,x0f:1;
	unsigned x10:1,x11:1,x12:1,x13:1,x14:1,x15:1,x16:1,x17:1,x18:1,x19:1,x1a:1,x1b:1,x1c:1,x1d:1,x1e:1,x1f:1;
	unsigned x20:1,x21:1,x22:1,x23:1,x24:1,x25:1,x26:1,x27:1,x28:1,x29:1,x2a:1,x2b:1,x2c:1,x2d:1,x2e:1,x2f:1;
	unsigned x30:1,x31:1,x32:1,x33:1,x34:1,x35:1,x36:1,x37:1,x38:1,x39:1,x3a:1,x3b:1,x3c:1,x3d:1,x3e:1,x3f:1;
	unsigned x40:1,x41:1,x42:1,x43:1,x44:1,x45:1,x46:1,x47:1,x48:1,x49:1,x4a:1,x4b:1,x4c:1,x4d:1,x4e:1,x4f:1;
	unsigned x50:1,x51:1,x52:1,x53:1,x54:1,x55:1,x56:1,x57:1,x58:1,x59:1,x5a:1,x5b:1,x5c:1,x5d:1,x5e:1,x5f:1;
	unsigned x60:1,x61:1,x62:1,x63:1,x64:1,x65:1,x66:1,x67:1,x68:1,x69:1,x6a:1,x6b:1,x6c:1,x6d:1,x6e:1,x6f:1;
	unsigned x70:1,x71:1,x72:1,x73:1,x74:1,x75:1,x76:1,x77:1,x78:1,x79:1,x7a:1,x7b:1,x7c:1,x7d:1,x7e:1,x7f:1;
};

struct jk_character_bitmap_256_t {
	unsigned x00:1,x01:1,x02:1,x03:1,x04:1,x05:1,x06:1,x07:1,x08:1,x09:1,x0a:1,x0b:1,x0c:1,x0d:1,x0e:1,x0f:1;
	unsigned x10:1,x11:1,x12:1,x13:1,x14:1,x15:1,x16:1,x17:1,x18:1,x19:1,x1a:1,x1b:1,x1c:1,x1d:1,x1e:1,x1f:1;
	unsigned x20:1,x21:1,x22:1,x23:1,x24:1,x25:1,x26:1,x27:1,x28:1,x29:1,x2a:1,x2b:1,x2c:1,x2d:1,x2e:1,x2f:1;
	unsigned x30:1,x31:1,x32:1,x33:1,x34:1,x35:1,x36:1,x37:1,x38:1,x39:1,x3a:1,x3b:1,x3c:1,x3d:1,x3e:1,x3f:1;
	unsigned x40:1,x41:1,x42:1,x43:1,x44:1,x45:1,x46:1,x47:1,x48:1,x49:1,x4a:1,x4b:1,x4c:1,x4d:1,x4e:1,x4f:1;
	unsigned x50:1,x51:1,x52:1,x53:1,x54:1,x55:1,x56:1,x57:1,x58:1,x59:1,x5a:1,x5b:1,x5c:1,x5d:1,x5e:1,x5f:1;
	unsigned x60:1,x61:1,x62:1,x63:1,x64:1,x65:1,x66:1,x67:1,x68:1,x69:1,x6a:1,x6b:1,x6c:1,x6d:1,x6e:1,x6f:1;
	unsigned x70:1,x71:1,x72:1,x73:1,x74:1,x75:1,x76:1,x77:1,x78:1,x79:1,x7a:1,x7b:1,x7c:1,x7d:1,x7e:1,x7f:1;
	unsigned x80:1,x81:1,x82:1,x83:1,x84:1,x85:1,x86:1,x87:1,x88:1,x89:1,x8a:1,x8b:1,x8c:1,x8d:1,x8e:1,x8f:1;
	unsigned x90:1,x91:1,x92:1,x93:1,x94:1,x95:1,x96:1,x97:1,x98:1,x99:1,x9a:1,x9b:1,x9c:1,x9d:1,x9e:1,x9f:1;
	unsigned xa0:1,xa1:1,xa2:1,xa3:1,xa4:1,xa5:1,xa6:1,xa7:1,xa8:1,xa9:1,xaa:1,xab:1,xac:1,xad:1,xae:1,xaf:1;
	unsigned xb0:1,xb1:1,xb2:1,xb3:1,xb4:1,xb5:1,xb6:1,xb7:1,xb8:1,xb9:1,xba:1,xbb:1,xbc:1,xbd:1,xbe:1,xbf:1;
	unsigned xc0:1,xc1:1,xc2:1,xc3:1,xc4:1,xc5:1,xc6:1,xc7:1,xc8:1,xc9:1,xca:1,xcb:1,xcc:1,xcd:1,xce:1,xcf:1;
	unsigned xd0:1,xd1:1,xd2:1,xd3:1,xd4:1,xd5:1,xd6:1,xd7:1,xd8:1,xd9:1,xda:1,xdb:1,xdc:1,xdd:1,xde:1,xdf:1;
	unsigned xe0:1,xe1:1,xe2:1,xe3:1,xe4:1,xe5:1,xe6:1,xe7:1,xe8:1,xe9:1,xea:1,xeb:1,xec:1,xed:1,xee:1,xef:1;
	unsigned xf0:1,xf1:1,xf2:1,xf3:1,xf4:1,xf5:1,xf6:1,xf7:1,xf8:1,xf9:1,xfa:1,xfb:1,xfc:1,xfd:1,xfe:1,xff:1;
};

struct jk_character_bitmap_5x7_t {
/* 5x7 == 35 == 32 + 3 */
	unsigned x00:1,x01:1,x02:1,x03:1,x04:1,x05:1,x06:1,x07:1,x08:1,x09:1,x0a:1,x0b:1,x0c:1,x0d:1,x0e:1,x0f:1;
	unsigned x10:1,x11:1,x12:1,x13:1,x14:1,x15:1,x16:1,x17:1,x18:1,x19:1,x1a:1,x1b:1,x1c:1,x1d:1,x1e:1,x1f:1;
	unsigned x20:1,x21:1,x22:1;
};

struct jk_character_bitmap_5x9_t {
/* 5x9 == 45 == 48 - 3 */
	jk_character_bitmap_48_t x48;
};

struct jk_character_bitmap_5x9x8_t {
/* 5x8x9 == 360 == 320 + 40 == 64 * 5 + 32 + 8 */
	jk_character_bitmap_64_t x64x5[5];
	jk_character_bitmap_40_t x40;
};

struct jk_character_bitmap_5x9x9_t {
/* 5x9x9 == 405 == 64 * 6 + 21 */
	jk_character_bitmap_64_t x64x6[6];
	jk_character_bitmap_21_t x21;
};

struct jk_character_bitmap_5x8x9_t {
/* 5x8x9 == 360 == 320 + 40 == 64 * 5 + 32 + 8 */
	jk_character_bitmap_64_t x64x5[5];
	jk_character_bitmap_40_t x40;
};

struct jk_character_bitmap_5x8x8_t {
/* 5x8x8 == 320 == 64 * 5 */
	jk_character_bitmap_64_t x64x5[5];
};

struct jk_character_bitmap_5x7x9_t {
/* 5x7x9 == 315 == 64 * 5 - 5 */
	jk_character_bitmap_64_t x64x5[5];
};

struct jk_character_bitmap_5x7x8_t {
/* 5x7x8 == 280 == 64 * 4 + 24 */
	jk_character_bitmap_64_t x64x4[4];
	jk_character_bitmap_24_t x24;
};

struct jk_character_bitmap_5x7x24_t {
/* 5 * 7 * 24 == 840 == 64 * 13 + 8 */
	jk_character_bitmap_64_t x64x13[13];
	jk_character_bitmap_8_t  x8;
};

struct jk_character_bitmap_5x8x24_t {
/* 5 * 8 * 24 == 960 == 64 * 15 */
	jk_character_bitmap_64_t x64x15[15];
};

jk_character_bitmap_5x9_t jk_character_bitmaps[256];

#define JK_GET_BITMAP_BIT_CASE(y) case 0x##y : return bitmap->x##y;
#define JK_SET_BITMAP_BIT_CASE(y) case 0x##y : bitmap->x##y = bit_value; break;

#undef X
#undef Y
#define X(y) JK_GET_BITMAP_BIT_CASE(y)
#define Y(y) JK_SET_BITMAP_BIT_CASE(y)

unsigned
jk_character_bitmap_8_get_bit(
	const jk_character_bitmap_8_t* bitmap,
	unsigned bit_index
	)
{
	switch (bit_index)
	{
		X(00) X(01) X(02) X(03) X(04) X(05) X(06) X(07)
	}
	return 0;
}

void
jk_character_bitmap_8_set_bit(
	jk_character_bitmap_8_t* bitmap,
	unsigned bit_index,
	unsigned bit_value
	)
{
	switch (bit_index)
	{
		Y(00) Y(01) Y(02) Y(03) Y(04) Y(05) Y(06) Y(07)
	}
}

unsigned
jk_character_bitmap_8_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	)
{
	return jk_character_bitmap_8_get_bit((const jk_character_bitmap_8_t*)vbitmap, bit_index);
}

unsigned
jk_character_bitmap_24_get_bit(
	const jk_character_bitmap_24_t* bitmap,
	unsigned bit_index
	)
{
	switch (bit_index)
	{
		X(00)X(01)X(02)X(03)X(04)X(05)X(06)X(07)X(08)X(09)X(0a)X(0b)X(0c)X(0d)X(0e)X(0f)
		X(10)X(11)X(12)X(13)X(14)X(15)X(16)X(17)
	}
	return 0;
}

unsigned
jk_character_bitmap_48_get_bit(
	const jk_character_bitmap_48_t* bitmap,
	unsigned bit_index
	)
{
	switch (bit_index)
	{
		X(00)X(01)X(02)X(03)X(04)X(05)X(06)X(07)X(08)X(09)X(0a)X(0b)X(0c)X(0d)X(0e)X(0f)
		X(10)X(11)X(12)X(13)X(14)X(15)X(16)X(17)X(18)X(19)X(1a)X(1b)X(1c)X(1d)X(1e)X(1f)
		X(20)X(21)X(22)X(23)X(24)X(25)X(26)X(27)X(28)X(29)X(2a)X(2b)X(2c)X(2d)X(2e)X(2f)
	}
	return 0;
}

void
jk_character_bitmap_48_set_bit(
	jk_character_bitmap_48_t* bitmap,
	unsigned bit_index,
	unsigned bit_value
	)
{
	switch (bit_index)
	{
		Y(00)Y(01)Y(02)Y(03)Y(04)Y(05)Y(06)Y(07)Y(08)Y(09)Y(0a)Y(0b)Y(0c)Y(0d)Y(0e)Y(0f)
		Y(10)Y(11)Y(12)Y(13)Y(14)Y(15)Y(16)Y(17)Y(18)Y(19)Y(1a)Y(1b)Y(1c)Y(1d)Y(1e)Y(1f)
		Y(20)Y(21)Y(22)Y(23)Y(24)Y(25)Y(26)Y(27)Y(28)Y(29)Y(2a)Y(2b)Y(2c)Y(2d)Y(2e)Y(2f)
	}
}

unsigned
jk_character_bitmap_48_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	)
{
	return jk_character_bitmap_48_get_bit((const jk_character_bitmap_48_t*)vbitmap, bit_index);
}

unsigned
jk_character_bitmap_5x9_get_bit(
	const jk_character_bitmap_5x9_t* bitmap,
	unsigned bit_index
	)
{
	if (bit_index >= 5 * 9)
		return 0;
	return jk_character_bitmap_48_get_bit(&bitmap->x48, bit_index);
}

void
jk_character_bitmap_5x9_set_bit(
	jk_character_bitmap_5x9_t* bitmap,
	unsigned bit_index,
	unsigned bit_value
	)
{
	if (bit_index >= 5 * 9)
		return;
	jk_character_bitmap_48_set_bit(&bitmap->x48, bit_index, bit_value);
}

unsigned
jk_character_bitmap_5x9_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	)
{
	return jk_character_bitmap_5x9_get_bit((const jk_character_bitmap_5x9_t*)vbitmap, bit_index);
}

void
jk_character_bitmap_5x9_set_bit_v(
	void* vbitmap,
	unsigned bit_index,
	unsigned bit_value
	)
{
	if (bit_index >= 5 * 9)
		return;
	jk_character_bitmap_5x9_set_bit((jk_character_bitmap_5x9_t*)vbitmap, bit_index, bit_value);
}

unsigned
jk_character_bitmap_64_get_bit(
	const jk_character_bitmap_64_t* bitmap,
	unsigned bit_index
	)
{
	switch (bit_index)
	{
		X(00)X(01)X(02)X(03)X(04)X(05)X(06)X(07)X(08)X(09)X(0a)X(0b)X(0c)X(0d)X(0e)X(0f)
		X(10)X(11)X(12)X(13)X(14)X(15)X(16)X(17)X(18)X(19)X(1a)X(1b)X(1c)X(1d)X(1e)X(1f)
		X(20)X(21)X(22)X(23)X(24)X(25)X(26)X(27)X(28)X(29)X(2a)X(2b)X(2c)X(2d)X(2e)X(2f)
		X(30)X(31)X(32)X(33)X(34)X(35)X(36)X(37)X(38)X(39)X(3a)X(3b)X(3c)X(3d)X(3e)X(3f)
	}
	return 0;
}

void
jk_character_bitmap_64_set_bit(
	jk_character_bitmap_64_t* bitmap,
	unsigned bit_index,
	unsigned bit_value
	)
{
	switch (bit_index)
	{
		Y(00)Y(01)Y(02)Y(03)Y(04)Y(05)Y(06)Y(07)Y(08)Y(09)Y(0a)Y(0b)Y(0c)Y(0d)Y(0e)Y(0f)
		Y(10)Y(11)Y(12)Y(13)Y(14)Y(15)Y(16)Y(17)Y(18)Y(19)Y(1a)Y(1b)Y(1c)Y(1d)Y(1e)Y(1f)
		Y(20)Y(21)Y(22)Y(23)Y(24)Y(25)Y(26)Y(27)Y(28)Y(29)Y(2a)Y(2b)Y(2c)Y(2d)Y(2e)Y(2f)
		Y(30)Y(31)Y(32)Y(33)Y(34)Y(35)Y(36)Y(37)Y(38)Y(39)Y(3a)Y(3b)Y(3c)Y(3d)Y(3e)Y(3f)
	}
}

unsigned
jk_character_bitmap_64_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	)
{
	return jk_character_bitmap_64_get_bit((const jk_character_bitmap_64_t*)vbitmap, bit_index);
}

unsigned
jk_character_bitmap_128_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	)
{
	const jk_character_bitmap_128_t* bitmap = (const jk_character_bitmap_128_t*)vbitmap;
	switch (bit_index)
	{
		X(00)X(01)X(02)X(03)X(04)X(05)X(06)X(07)X(08)X(09)X(0a)X(0b)X(0c)X(0d)X(0e)X(0f)
		X(10)X(11)X(12)X(13)X(14)X(15)X(16)X(17)X(18)X(19)X(1a)X(1b)X(1c)X(1d)X(1e)X(1f)
		X(20)X(21)X(22)X(23)X(24)X(25)X(26)X(27)X(28)X(29)X(2a)X(2b)X(2c)X(2d)X(2e)X(2f)
		X(30)X(31)X(32)X(33)X(34)X(35)X(36)X(37)X(38)X(39)X(3a)X(3b)X(3c)X(3d)X(3e)X(3f)
		X(40)X(41)X(42)X(43)X(44)X(45)X(46)X(47)X(48)X(49)X(4a)X(4b)X(4c)X(4d)X(4e)X(4f)
		X(50)X(51)X(52)X(53)X(54)X(55)X(56)X(57)X(58)X(59)X(5a)X(5b)X(5c)X(5d)X(5e)X(5f)
		X(60)X(61)X(62)X(63)X(64)X(65)X(66)X(67)X(68)X(69)X(6a)X(6b)X(6c)X(6d)X(6e)X(6f)
		X(70)X(71)X(72)X(73)X(74)X(75)X(76)X(77)X(78)X(79)X(7a)X(7b)X(7c)X(7d)X(7e)X(7f)
	}
	return 0;
}

unsigned
jk_character_bitmap_256_get_bit(
	const jk_character_bitmap_256_t* bitmap,
	unsigned bit_index
	)
{
	switch (bit_index)
	{
		X(00)X(01)X(02)X(03)X(04)X(05)X(06)X(07)X(08)X(09)X(0a)X(0b)X(0c)X(0d)X(0e)X(0f)
		X(10)X(11)X(12)X(13)X(14)X(15)X(16)X(17)X(18)X(19)X(1a)X(1b)X(1c)X(1d)X(1e)X(1f)
		X(20)X(21)X(22)X(23)X(24)X(25)X(26)X(27)X(28)X(29)X(2a)X(2b)X(2c)X(2d)X(2e)X(2f)
		X(30)X(31)X(32)X(33)X(34)X(35)X(36)X(37)X(38)X(39)X(3a)X(3b)X(3c)X(3d)X(3e)X(3f)
		X(40)X(41)X(42)X(43)X(44)X(45)X(46)X(47)X(48)X(49)X(4a)X(4b)X(4c)X(4d)X(4e)X(4f)
		X(50)X(51)X(52)X(53)X(54)X(55)X(56)X(57)X(58)X(59)X(5a)X(5b)X(5c)X(5d)X(5e)X(5f)
		X(60)X(61)X(62)X(63)X(64)X(65)X(66)X(67)X(68)X(69)X(6a)X(6b)X(6c)X(6d)X(6e)X(6f)
		X(70)X(71)X(72)X(73)X(74)X(75)X(76)X(77)X(78)X(79)X(7a)X(7b)X(7c)X(7d)X(7e)X(7f)
		X(80)X(81)X(82)X(83)X(84)X(85)X(86)X(87)X(88)X(89)X(8a)X(8b)X(8c)X(8d)X(8e)X(8f)
		X(90)X(91)X(92)X(93)X(94)X(95)X(96)X(97)X(98)X(99)X(9a)X(9b)X(9c)X(9d)X(9e)X(9f)
		X(a0)X(a1)X(a2)X(a3)X(a4)X(a5)X(a6)X(a7)X(a8)X(a9)X(aa)X(ab)X(ac)X(ad)X(ae)X(af)
		X(b0)X(b1)X(b2)X(b3)X(b4)X(b5)X(b6)X(b7)X(b8)X(b9)X(ba)X(bb)X(bc)X(bd)X(be)X(bf)
		X(c0)X(c1)X(c2)X(c3)X(c4)X(c5)X(c6)X(c7)X(c8)X(c9)X(ca)X(cb)X(cc)X(cd)X(ce)X(cf)
		X(d0)X(d1)X(d2)X(d3)X(d4)X(d5)X(d6)X(d7)X(d8)X(d9)X(da)X(db)X(dc)X(dd)X(de)X(df)
		X(e0)X(e1)X(e2)X(e3)X(e4)X(e5)X(e6)X(e7)X(e8)X(e9)X(ea)X(eb)X(ec)X(ed)X(ee)X(ef)
		X(f0)X(f1)X(f2)X(f3)X(f4)X(f5)X(f6)X(f7)X(f8)X(f9)X(fa)X(fb)X(fc)X(fd)X(fe)X(ff)
	}
	return 0;
}

#undef X

unsigned
jk_character_bitmap_256_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	)
{
	return jk_character_bitmap_256_get_bit((const jk_character_bitmap_256_t*)vbitmap, bit_index);
}

unsigned
jk_character_bitmap_5x7x24_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	)
{
	const jk_character_bitmap_5x7x24_t* bitmap = (const jk_character_bitmap_5x7x24_t*)vbitmap;
	if (bit_index >= 5 * 7 * 24)
		return 0;
	else if (bit_index < 64 * 13)
		return jk_character_bitmap_64_get_bit(&bitmap->x64x13[bit_index / 64], bit_index % 64);
	else
		return jk_character_bitmap_8_get_bit(&bitmap->x8, bit_index - 64 * 13);
}

unsigned
jk_character_bitmap_5x7x8_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	)
{
	const jk_character_bitmap_5x7x8_t* bitmap = (const jk_character_bitmap_5x7x8_t*)vbitmap;
	if (bit_index >= 5 * 7 * 8)
		return 0;
	else if (bit_index < 64 * 4)
		return jk_character_bitmap_64_get_bit(&bitmap->x64x4[bit_index / 64], bit_index % 64);
	else
		return jk_character_bitmap_24_get_bit(&bitmap->x24, bit_index - 64 * 4);
}

unsigned
jk_character_bitmap_5x7x9_get_bit(
	const jk_character_bitmap_5x7x9_t *bitmap,
	unsigned bit_index
	)
{
	return jk_character_bitmap_64_get_bit(&bitmap->x64x5[bit_index / 64], bit_index % 64);
}

unsigned
jk_character_bitmap_5x7x9_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	)
{
	const jk_character_bitmap_5x7x9_t* bitmap = (const jk_character_bitmap_5x7x9_t*)vbitmap;
	if (bit_index >= 5 * 7 * 9)
		return 0;
	if (bit_index >= 64 * 5)
		return 0;
	return jk_character_bitmap_5x7x9_get_bit(bitmap, bit_index);
}

void
jk_convert_character_bitmap_generic(
	const void* from_data,
	unsigned from_width,
	unsigned from_height,
	unsigned from_base,
	unsigned from_stride,
	unsigned (*from_get_bit)(const void* vbitmap, unsigned bit_index),
	void* to_data,
	unsigned to_width,
	unsigned to_height,
	unsigned to_base,
	unsigned to_stride,
	void (*to_set_bit)(void* vbitmap, unsigned bit_index, unsigned bit_value)
	)
{
	unsigned x = 0;
	unsigned y = 0;
	unsigned to_index = to_base;
	unsigned from_index = from_base;
	unsigned height = jk_min(to_height, from_height);
	unsigned width = jk_min(to_width, from_width);

	to_stride -= to_width;
	from_stride -= from_width;
#if 0
	if (to_height != from_height || to_width != from_width)
	{
		for (y = 0 ; y != to_height ; ++y)
		{
			for (x = 0 ; x != to_width ; ++x)
			{		
				to_set_bit(to, to_base + to_index++, 0);
			}
			to_index += to_stride;
		}
	}
	to_index = to_base;
	from_index = from_base;
#endif
	for (y = 0 ; y != height ; ++y)
	{
		for (x = 0 ; x != width ; ++x)
		{
			to_set_bit(to_data, to_index++, from_get_bit(from_data, from_index++));
		}
		to_index += to_stride;
		from_index += from_stride;
	}
}

void
jk_convert_character_bitmap_579_to_59array(
	const jk_character_bitmap_5x7x9_t *x579,
	jk_character_bitmap_5x9_t *x59array
	)
{
	unsigned i = 0;

	memset(x59array, 0, sizeof(*x59array) * 9);
	
	for (i = 0; i != 9 ; ++i)
	{
		jk_convert_character_bitmap_generic(
			x579,
			5,
			7,
			i * 5,
			5 * 9,
			&jk_character_bitmap_5x7x9_get_bit_v,
			&x59array[i],
			5,
			9,
			0,
			5,
			&jk_character_bitmap_5x9_set_bit_v
			);
	}
}

#undef X
#undef _

#define X 1,
#define _ 0,

const jk_character_bitmap_5x7x9_t jk_character_bitmap_ABCDEFGHI = {{
_ X X X _   X X X X _   _ X X X _   X X X X _   X X X X X   X X X X X   _ X X X _    X _ _ _ X   _ _ X _ _
X _ _ _ X   X _ _ _ X   X _ _ _ X   X _ _ _ X   X _ _ _ _   X _ _ _ _   X _ _ _ X    X _ _ _ X   _ _ X _ _
X _ _ _ X   X _ _ _ X   X _ _ _ _   X _ _ _ X   X _ _ _ _   X _ _ _ _   X _ _ _ _    X _ _ _ X   _ _ X _ _
X X X X X   X X X X _   X _ _ _ _   X _ _ _ X   X X X X _   X X X X _   X _ _ X X    X X X X X   _ _ X _ _
X _ _ _ X   X _ _ _ X   X _ _ _ _   X _ _ _ X   X _ _ _ _   X _ _ _ _   X _ _ _ X    X _ _ _ X   _ _ X _ _
X _ _ _ X   X _ _ _ X   X _ _ _ X   X _ _ _ X   X _ _ _ _   X _ _ _ _   X _ _ _ X    X _ _ _ X   _ _ X _ _
X _ _ _ X   X X X X _   _ X X X _   X X X X _   X X X X X   X _ _ _ _   _ X X X _    X _ _ _ X   _ _ X _ _
}};
const jk_character_bitmap_5x8x9_t jk_character_bitmap_JKLMNOPQR = {
_ _ _ _ X   X _ _ _ X   X _ _ _ _   X _ _ _ X   X _ _ _ X   _ X X X _   X X X X _    _ X X X _   X X X X _
_ _ _ _ X   X _ _ X _   X _ _ _ _   X X _ X X   X X _ _ X   X _ _ _ X   X _ _ _ X    X _ _ _ X   X _ _ _ X
_ _ _ _ X   X _ X _ _   X _ _ _ _   X _ X _ X   X _ X _ X   X _ _ _ X   X _ _ _ X    X _ _ _ X   X _ _ _ X
_ _ _ _ X   X X _ _ _   X _ _ _ _   X _ _ _ X   X _ _ X X   X _ _ _ X   X X X X _    X _ _ _ X   X X X X _
X _ _ _ X   X _ X _ _   X _ _ _ _   X _ _ _ X   X _ _ _ X   X _ _ _ X   X _ _ _ _    X _ _ _ X   X _ _ _ X
X _ _ _ X   X _ _ X _   X _ _ _ _   X _ _ _ X   X _ _ _ X   X _ _ _ X   X _ _ _ _    X _ _ _ X   X _ _ _ X
_ X X X _   X _ _ _ X   X X X X X   X _ _ _ X   X _ _ _ X   _ X X X _   X _ _ _ _    _ X X X _   X _ _ _ X
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _    _ _ _ _ X   _ _ _ _ _
};
const jk_character_bitmap_5x7x8_t jk_character_bitmap_STUVWXYZ = {
_ X X X _   X X X X X   X _ _ _ X   X _ _ _ X   X _ _ _ X   X _ _ _ X   X _ _ _ X    X X X X X
X _ _ _ X   _ _ X _ _   X _ _ _ X   X _ _ _ X   X _ _ _ X   _ X _ X _   X _ _ _ X    _ _ _ _ X
X _ _ _ _   _ _ X _ _   X _ _ _ X   X _ _ _ X   X _ _ _ X   _ _ X _ _   X _ _ _ X    _ _ _ X _
_ X X X _   _ _ X _ _   X _ _ _ X   _ X _ X _   X _ _ _ X   _ _ X _ _   _ X _ X _    _ _ X _ _
_ _ _ _ X   _ _ X _ _   X _ _ _ X   _ X _ X _   X _ X _ X   _ _ X _ _   _ _ X _ _    _ X _ _ _
X _ _ _ X   _ _ X _ _   X _ _ _ X   _ _ X _ _   X X _ X X   _ X _ X _   _ _ X _ _    X _ _ _ _
_ X X X _   _ _ X _ _   _ X X X _   _ _ X _ _   X _ _ _ X   X _ _ _ X   _ _ X _ _    X X X X X
};

const jk_character_bitmap_5x9x9_t jk_character_bitmap_abcdefghi = {
_ _ _ _ _   X _ _ _ _   _ _ _ _ _   _ _ _ _ X   _ _ _ _ _   _ _ _ X X   _ _ _ _ _    X _ _ _ _   _ _ X _ _
_ _ _ _ _   X _ _ _ _   _ _ _ _ _   _ _ _ _ X   _ _ _ _ _   _ _ X _ _   _ _ _ _ _    X _ _ _ _   _ _ _ _ _
_ X X X X   X X X X _   _ X X X _   _ X X X X   _ X X X _   _ X X X _   _ X X X X    X X X X _   _ _ X _ _
X _ _ _ X   X _ _ _ X   X _ _ _ X   X _ _ _ X   X _ _ _ X   _ _ X _ _   X _ _ _ X    X _ _ _ X   _ _ X _ _
X _ _ _ X   X _ _ _ X   X _ _ _ _   X _ _ _ X   X X X X X   _ _ X _ _   X _ _ _ X    X _ _ _ X   _ _ X _ _
X _ _ X X   X _ _ _ X   X _ _ _ _   X _ _ _ X   X _ _ _ _   _ _ X _ _   X _ _ _ X    X _ _ _ X   _ _ X _ _
_ X X _ X   X X X X _   _ X X X X   _ X X X X   _ X X X X   _ _ X _ _   _ X X X X    X _ _ _ X   _ _ X _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ X    _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ X X X _    _ _ _ _ _   _ _ _ _ _
};
const jk_character_bitmap_5x9x9_t jk_character_bitmap_jklmnopqr = {
_ _ X _ _   X _ _ _ _   _ _ X _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _    _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   X _ _ _ _   _ _ X _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _    _ _ _ _ _   _ _ _ _ _
_ _ X _ _   X _ _ X _   _ _ X _ _   X X X X _   X _ X X _   _ X X X _   X X X X _    _ X X X X   X _ X X _
_ _ X _ _   X _ X _ _   _ _ X _ _   X _ X _ X   X X _ _ X   X _ _ _ X   X _ _ _ X    X _ _ _ X   X X _ _ X
_ _ X _ _   X X X _ _   _ _ X _ _   X _ X _ X   X _ _ _ X   X _ _ _ X   X _ _ _ X    X _ _ _ X   X _ _ _ _
_ _ X _ _   X _ _ X _   _ _ X _ _   X _ X _ X   X _ _ _ X   X _ _ _ X   X _ _ _ X    X _ _ _ X   X _ _ _ _
_ _ X _ _   X _ _ _ X   _ _ X X _   X _ X _ X   X _ _ _ X   _ X X X _   X X X X _    _ X X X X   X _ _ _ _
_ _ X _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   X _ _ _ _    _ _ _ _ X   _ _ _ _ _
X X _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   X _ _ _ _    _ _ _ _ X   _ _ _ _ _
};
const jk_character_bitmap_5x9x8_t jk_character_bitmap_stuvwxyz = {
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
};

/*
const jk_character_bitmap_5x7x9_t = {
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
};
const jk_character_bitmap_5x9x9_t = {
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
_ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _
};
*/

#undef X
#undef _

int main(int argc, char ** argv, char **env)
{
	char a[sizeof(unsigned long) * CHAR_BIT + 3];
	jk_globals_t * globals = &jk_globals;
    unsigned u;
    unsigned long v;
    void * p = 0;

    u = (unsigned)p;
    v = (unsigned long)p;

    globals->argc = argc;
    globals->argv = argv;
    globals->environment_variables = env;

#if 0
	jk_init_fields();
	jk_init_classfile_type_info();
    
    if (argc > 1 && argv && argv[1])
    {
    	jk_java_read_classfile(globals, 0, argv[1]);
    	jk_profile_dump_function_call_counts();
	}
#endif

#undef X
#undef Y

#define X(x) printf("%s %lx\n", #x, (unsigned long)x)
#define Y(x) X(x(0)); X(x(1)); X(x(2)); X(x(30)); X(x(31)); X(x(32))

Y(jk_long_with_n_right_bits_clear);
Y(jk_long_with_n_right_bits_set);
Y(jk_long_with_n_left_bits_clear);
Y(jk_long_with_n_left_bits_set);
Y(jk_ulong_with_n_right_bits_clear);
Y(jk_ulong_with_n_right_bits_set);
Y(jk_ulong_with_n_left_bits_clear);
Y(jk_ulong_with_n_left_bits_set);

X(sizeof(jk_character_bitmap_5x7_t));
X(sizeof(jk_character_bitmap_5x9_t));
X(sizeof(jk_character_bitmap_5x9x9_t));

#undef Y
#undef X

#define X(x) x; printf("%s %s\n", #x, a)
X(jk_ultoa(0, a));
X(jk_ultoa(1, a));
X(jk_ultoa(~0UL, a));
X(jk_ultoa(~0UL >> 1, a));
X(jk_ultoa(~0UL << 1, a));

X(jk_ltoa(0, a));
X(jk_ltoa(1, a));
X(jk_ltoa(~0UL, a));
X(jk_ltoa(~0UL >> 1, a));
X(jk_ltoa(~0UL << 1, a));

	return -1;
}

#else

int main()
{
	return -1;
}

#endif
