#if defined(__ORCAC__)
#define JK_CC_CCIIGS 1
#endif
#if defined(applec) && !defined(__SC___) && !defined(__cplusplus)
#define JK_CC_MPW_C 1
#endif
#if defined(applec) && !defined(__SC___) && defined(__cplusplus)
#define JK_CC_MPW_CPLUS 1
#endif
#if defined(applec) && defined(__SC___) && !defined(__cplusplus)
#define JK_CC_SC 1
#endif
#if defined(applec) && defined(__SC___) && defined(__cplusplus)
#define JK_CC_SCPP
#endif
#if defined(__PPCC__) && !defined(__cplusplus)
#define JK_CC_PPCC 1
#endif
#if defined(__PPCC__) && defined(__cplusplus)
#define JK_CC_PPCCPP 1
#endif
#if defined(__MRC__) && !defined(__cplusplus)
#define JK_CC_MRC 1
#endif
#if defined(__MRC__) && defined(__cplusplus)
#define JK_CC_MRCPP 1
#endif
#if defined(__MWERKS__) && !defined(__powerc)
#define JK_CC_MWC68K 1
#endif
#if defined(__MWERKS__) && defined(__powerc)
#define JK_CC_MWCPPC  1
#endif

#if defined(JK_CC_CIIIGS)
#define const /* nothing */
#endif
#if defined(JK_CC_MPW_CPLUS)
#define const /* nothing */
#define volatile /* nothing */
#endif
#if defined(JK_CC_MPW_CPLUS)
#define JK_CFRONT 1
#endif

#if defined(JK_CC_SCPP) || defined(JK_CC_MRCPP)
/*
scpp j19.c SCpp C++ Compiler 8.9.0d3e1
		typedef short wchar_t;
File "z:Development:MPW::Interfaces&Libraries:Interfaces:CIncludes:WCharTDef.h"; line 16 #Error: illegal combination of types

mrcpp j19.c MrCpp C++ Compiler 5.0.0d3c1
		typedef short wchar_t;
File "z:Development:MPW::Interfaces&Libraries:Interfaces:CIncludes:WCharTDef.h"; line 16 #Error: illegal combination of types
*/
#define __WCHARTDEF__
#endif

#include <limits.h>
#include <stddef.h>
#if defined(__cplusplus)
#include <vector>
#endif
#include <string.h>
#include <memory.h>

#define JK_NOTHING /* nothing */

#if defined(__cplusplus)
#define JK_IF_CPLUSPLUS_ELSE(x,y) x
#else
#define JK_IF_CPLUSPLUS_ELSE(x,y) y
#endif
#define JK_IF_CPLUSPLUS(x)	JK_IF_CPLUSPLUS_ELSE(x, JK_NOTHING)
#define JK_EXTERN_C       	JK_IF_CPLUSPLUS(extern "C"))
#define JK_EXTERN_C_BEGIN 	JK_IF_CPLUSPLUS(extern "C" {)
#define JK_EXTERN_C_END   	JK_IF_CPLUSPLUS(} /* extern "C" */)

/* In C, const means extern const.
   In C++, const means static const.
   gcc 2.95.2 doesn't like "extern const" in C code.
*/
#define JK_EXTERN_CONST JK_IF_CPLUSPLUS(extern) const

#define JK_STRINGIZE2(x) #x
#define JK_STRINGIZE(x) JK_STRINGIZE2(x)
#define JK_LINE_STRING JK_STRINGIZE(__LINE__)

#if defined(__ORCAC__)
/* ORCA/C for the Apple IIGS can only have 64k of code per "segment".
   Sprinkle JK_ORCAC_SEGMENT around to break up the code into multiple segments.
  
   ORCA/C also has lots of bugs to do with const, so we disable it entirely.
   You often cannot initialize const structs.
   Code with const that does compile without a .sym file present fails to
      compile with .sym file present.
*/
#define JK_ORCAC_SEGMENT segment JK_LINE_STRING;
#define const /* nothing */
#define JK_STATIC_CONST /* nothing */
#define JK_CONST /* nothing */
#else
#define JK_ORCAC_SEGMENT /* nothing */
#define JK_STATIC_CONST static const
#define JK_CONST const
#endif

/* "const static" and "static const" are usually interchangable, but not with all compilers (MPW C). */
#define JK_CONST_STATIC JK_STATIC_CONST

JK_EXTERN_C_BEGIN

/* all caps style */
typedef unsigned char UCHAR; /* remove this */
typedef short SHORT; /* remove this */
typedef unsigned short USHORT; /* remove this */
typedef int INT; /* remove this */
typedef unsigned UINT; /* remove this */
typedef long LONG; /* remove this */
typedef unsigned long ULONG; /* remove this */

/* somewhat portable 64bit integer */
#if defined(_MSC_VER)
typedef __int64 LONGLONG;
typedef unsigned __int64 ULONGLONG;
#else
typedef long long LONGLONG;
typedef unsigned long long ULONGLONG;
#endif

/* explicit sizes */
typedef unsigned char UINT8; /* remove this */
typedef signed char INT8; /* remove this */
typedef short INT16; /* remove this */
//typedef unsigned short INT16;
typedef int INT32; /* remove this */
typedef unsigned UINT32; /* remove this */
typedef long LONG32; /* remove this */
typedef unsigned long ULONG32; /* remove this */
#if defined(_MSC_VER)
typedef __int64 LONG64; /* remove this */
typedef unsigned __int64 ULONG64; /* remove this */
#else
typedef long long LONG64; /* remove this */
typedef unsigned long long ULONG64; /* remove this */
#endif

/* byte */
typedef UCHAR BYTE; /* remove this */
typedef BYTE *PBYTE; /* remove this */

/* strings */
typedef wchar_t WCHAR; /* remove this */
typedef char* PSTR; /* remove this */
typedef wchar_t* PWSTR; /* remove this */
typedef const wchar_t* PCWSTR;
typedef const char* PCSTR; /* remove this */

typedef void* PVOID;
typedef const void* PCVOID;

/* opaque handle */
typedef PVOID HANDLE;

extern const long jk_out_of_memory_error;

typedef unsigned char jk_boolean_t;
typedef jk_boolean_t jk_bool_t;
typedef jk_boolean_t bool_t;
#define jk_false ((jk_boolean_t)0)
#define jk_true  ((jk_boolean_t)1)

typedef unsigned char  jk_uchar_t; /* remove this */
typedef unsigned short jk_ushort_t; /* remove this */
typedef unsigned int   jk_uint_t; /* remove this */
typedef unsigned long  jk_ulong_t; /* remove this */
typedef          char  jk_char_t; /* remove this */
typedef   signed char  jk_schar_t; /* remove this */
typedef          int   jk_int_t; /* remove this */
typedef          short jk_short_t; /* remove this */
typedef          long  jk_long_t; /* remove this */
typedef unsigned char  jk_byte_t; /* remove this */

typedef unsigned short jchar_t; /* remove this */
typedef unsigned short jchar; /* remove this */

#if (UCHAR_MAX == 255)
typedef unsigned char jk_uint8_t;
#endif
#if (UCHAR_MAX == 65535)
typedef unsigned char jk_uint16_t;
#elif (USHRT_MAX == 65535)
typedef unsigned short jk_uint16_t;
#endif
#if (UCHAR_MAX == 4294967295)
typedef unsigned char  jk_uint32_t;
#elif (USHRT_MAX == 4294967295)
typedef unsigned short jk_uint32_t;
#elif (UINT_MAX == 4294967295)
typedef unsigned int   jk_uint32_t;
#elif (ULONG_MAX == 4294967295)
typedef unsigned long  jk_uint32_t;
#endif

/*typedef unsigned u;*/
typedef size_t jk_size_t;
typedef size_t jk_ulong_ptr_t;
typedef size_t ulong_ptr_t;
typedef ptrdiff_t jk_ptrdiff_t;
typedef ptrdiff_t jk_long_ptr_t;
typedef ptrdiff_t long_ptr_t;

/*
Note this is two longs.
They are assumed to be at least 32bits but not necessarily exactly 32bits.
A longlong therefore is at least 64bits, but may be larger.
I do not have a compiler with 64bit longs to exercise this though.
(I do have 16bit ints.)
*/
typedef struct jk_longlong_t {
    signed long high;
    unsigned long low;
} jk_longlong_t;

typedef struct jk_ulonglong_t {
    unsigned long high;
    unsigned long low;
} jk_ulonglong_t;

/*
typedef struct jk_packed_longlong_t {
    unsigned char bytes[8];
} jk_packed_longlong_t;

typedef struct jk_packed_ulonglong_t {
    unsigned char bytes[8];
} jk_packed_ulonglong_t;
*/

typedef struct jk_memory_allocator_functions_t jk_memory_allocator_functions_t;
typedef struct jk_memory_allocator_t jk_memory_allocator_t;
typedef struct jk_type_t jk_type_t;
typedef struct jk_globals_t jk_globals_t;

void
jk_reverse_memory_byte_count(
    void* void_p,
    size_t count
    );

void
jk_reverse_memory_range_inclusive(
    void* void_start,
    void* void_end
    );

void
jk_reverse_memory_range_exclusive(
    void* void_start,
    void* void_end
    );

void
jk_move_memory(
    void* to,
    const void* from,
    size_t count
    );

void
jk_copy_memory(
    void* to,
    const void* from,
    size_t count
    );

void
jk_copy_memory_unsigned_char(
    unsigned char* to,
    const unsigned char* from,
    size_t count
    );

void
jk_copy_memory_reverse(
    unsigned char* to,
    const unsigned char* from,
    size_t count
    );

void
jk_zero_memory(
    void* p,
    size_t n
    );

/* strongly typed, narrow, specific interface */
size_t jk_get_dump_length_int(int data);
size_t jk_get_dump_length_unsigned_int(unsigned data);
size_t jk_get_dump_length_long(long data);
size_t jk_get_dump_length_unsigned_long(unsigned long data);

/* strongly typed, narrow, specific interface */
void jk_dump_int(size_t buffer_size, char* buffer, int data);
void jk_dump_unsigned_int(size_t buffer_size, char* buffer, unsigned data);
void jk_dump_long(size_t buffer_size, char* buffer, long data);
void jk_dump_unsigned_long(size_t buffer_size, char* buffer, unsigned long data);

/* jk_type_t conformant wrappers */
long jk_type_get_dump_length_int(const jk_type_t *, const void* data, size_t* length);
long jk_type_get_dump_length_unsigned_int(const jk_type_t *, const void* data, size_t* length);
long jk_type_get_dump_length_long(const jk_type_t *, const void* data, size_t* length);
long jk_type_get_dump_length_unsigned_long(const jk_type_t *, const void* data, size_t* length);

/* jk_type_t conformant wrappers */
long jk_type_dump_int(const jk_type_t *, size_t buffer_size, char* buffer, const void* data);
long jk_type_dump_unsigned_int(const jk_type_t *, size_t buffer_size, char* buffer, const void* data);
long jk_type_dump_long(const jk_type_t *, size_t buffer_size, char* buffer, const void* data);
long jk_type_dump_unsigned_long(const jk_type_t *, size_t buffer_size, char* buffer, const void* data);

typedef long (*jk_type_get_dump_length_t)(const jk_type_t *, const void* data, size_t* length);
typedef long (*jk_type_dump_t)(const jk_type_t *, size_t buffer_size, char* buffer, const void* data);

enum et_t { /* enum type */
    et_enumeration = 1,
    et_integer = 2,
    et_floatingpoint   = 3,
    et_structure  = 4,
    et_pointer = 5,
    et_array   = 6,
    et_function = 7,
    et_union  = 8,
    et_class  = 9,
    et_memberfunction = 10,
    et_typedef = 11,
    et_stringconstant = 12,
    et_Lstringconstant = 14,
    et_void = 15,
    et_reference = 16
};
enum eti_t { /* enum type integer */
    eti_char =  1,
    eti_schar =  2,
    eti_uchar =  3,
    eti_wchar = 4,
    eti_short = 5,
    eti_int   = 6,
    eti_long  = 7,
    eti_longlong = 8,
    eti_int64 = 9
};
enum ets_t { /* enum type signed */
    ets_signed  = 1,
    ets_unsigned = 2
};
enum etfp_t { /* enum type floating point */
    etfp_float  = 1,
    etfp_double = 2,
    etfp_longdouble = 3,
    etfp_extended80 = 4, /* Macintosh, Motorola 68k */
    etfp_extended96 = 5 /* Macintosh, Motorola 68k floating point unit, padded for alignment */
};
enum etlink_t { /* enum type linkage */
    etl_static = 1,
    etl_inline = 2,
    etl_extern = 3
};
enum etlang_t { /* enum type language linkage */
    etl_c = 1,          
    etl_cpp = 2,
    etl_fortran = 3
};
enum etnc_t { /* enum type native cross */
    etnc_native,
    etnc_cross
};
enum ete_t { /* enum type endian */
    ete_littleendian = 1,
    ete_bigendian = 2
};

typedef struct jk_enumeration_member_t {
    const char* name;
    size_t       value; /* TBD use ulonglong_t for cross types not representable in host size_t */
} jk_enumeration_member_t;

typedef struct jk_structure_member_t {
    const char* name;
    size_t       offset;
    size_t       aligned_size;
    struct jk_type_t* type;
} jk_structure_member_t;

/* not type descriptor */
typedef struct jk_array_t {
    const struct jk_type_t* element_type;
    struct jk_memory_allocator_t* allocator;
    void* elements;
    size_t size_allocated;
    size_t size_requested;
} jk_array_t;

typedef struct jk_string_constant_t {
    const char* chars; /* TBD host vs. target character sets */
    size_t length;
} jk_string_constant_t, jk_constant_string_t;

typedef struct jk_wide_string_constant_t {
    const wchar_t* chars; /* TBD host vs. target character sets and wide char representation */
    size_t length;
} jk_wide_string_constant_t;

#define jk_constant_string(s) { (s), (jk_number_of(s) - 1) }

typedef struct jk_string_t {
	char* chars;
	size_t length;
	jk_memory_allocator_t* memory_allocator;
} jk_string_t;

struct jk_type_t {
    size_t size; /* TBD ulonglong_t for cross types? */
    long (*construct_n)(const jk_type_t *, void* , size_t n);
    long (*destroy_n)(const jk_type_t *, void *, size_t n);
    long (*copy_n)(const jk_type_t *, void* , const void *, size_t n);
    long (*move_n)(const jk_type_t *, void* , void*, size_t n);
    unsigned is_signed;
    jk_type_get_dump_length_t get_dump_length;
	jk_type_dump_t dump;
	jk_constant_string_t name;
    size_t aligned_size; /* TBD ulonglong_t for cross types? */
	enum et_t et;
	unsigned cv_const : 1;
	unsigned cv_volatile : 1;
	union {
	    struct {
	        struct jk_type_t* integer_rep;
	        jk_array_t members;
	    } enumeration;
	    struct {
	        enum eti_t eti;
	        enum ets_t ets;
	    } integer;
	    struct {
	        enum etfp_t etfp;
	        size_t bits_in_mantissa; /* TBD ulonglong_t for cross types? */
	        size_t bits_in_exponent; /* TBD ulonglong_t for cross types? */
	        struct jk_type_t* integer_rep;
	    } floatingpoint;
	    struct {
	        jk_array_t members;
	        struct jk_type_t* integer_rep; /* usually NULL but may be non NULL for small structs */
	    } structure;
	    struct {
	        enum etlang_t etlang;
	        enum etlink_t etlink;
	        const char* name;
	        jk_array_t parameters;
	        struct {
	            unsigned char* object; /* processor? */
	            char* source;
	        } code;
	    } function;
	} u;
};

#define jk_type_get_size_macro(t,s) (((*s) = (t)->size), 0)
long
jk_type_get_size_function(
    jk_type_t* type,
    size_t* size
    );
#define jk_type_get_size(t,s) jk_type_get_size_macro(t,s)

size_t jk_type_char_get_size(const jk_type_t *);
size_t jk_type_uchar_get_size(const jk_type_t *);
size_t jk_type_short_get_size(const jk_type_t *);
size_t jk_type_ushort_get_size(const jk_type_t *);
size_t jk_type_int_get_size(const jk_type_t *);
size_t jk_type_uint_get_size(const jk_type_t *);
size_t jk_type_long_get_size(const jk_type_t *);
size_t jk_type_ulong_get_size(const jk_type_t *);
size_t jk_type_void_pointer_get_size(const jk_type_t *);

long
jk_type_copy_n_copy_memory(const jk_type_t* type, void* to, const void* from, size_t n);

long
jk_type_move_n_copy_memory(const jk_type_t* type, void* to, void* from, size_t n);

long
jk_type_move_n_copy_memory_and_zero_memory(const jk_type_t* type, void* to, void* from, size_t n);

long
jk_type_construct_n_zero_memory(const jk_type_t* type, void* p, size_t n);

long
jk_type_construct_n_do_nothing(const jk_type_t* type, void* p, size_t n);

long
jk_type_destroy_n_do_nothing(const jk_type_t* type, void* p, size_t n);

extern const jk_type_t jk_type_void;
extern const jk_type_t jk_type_uchar;
extern const jk_type_t jk_type_char;
extern const jk_type_t jk_type_short;
extern const jk_type_t jk_type_ushort;
extern const jk_type_t jk_type_int;
extern const jk_type_t jk_type_uint;
extern const jk_type_t jk_type_long;
extern const jk_type_t jk_type_ulong;
extern const jk_type_t jk_type_struct;
extern const jk_type_t jk_type_void_pointer;

#define jk_endian_big    0
#define jk_endian_little 1

struct jk_field_t;
typedef struct jk_field_t jk_field_t;

typedef
long
(*jk_field_unpacker_t)(
	const jk_field_t* field,
	const void* from,
	void* to
	);

typedef struct jk_pointer_or_offset_t {
	void* pointer;
	size_t offset;
} jk_pointer_or_offset_t;

// j47.h

void*
jk_get_pointer_or_offset(
	const jk_pointer_or_offset_t* pointer_or_offset,
	void* base
	);

struct jk_field_t {
    const char* name;
    size_t offset_to_type; /* offset from jk_types (need not be in jk_types) */
    size_t unpacked_size;
    size_t packed_size;
    size_t unpacked_offset;
    size_t packed_offset;
	size_t unpacker_offset; /* offset from jk_field_unpackers (need not be in it) */
};

jk_type_t*
jk_field_get_type(
	jk_field_t*
	);

jk_field_unpacker_t
jk_field_get_unpacker(
	jk_field_t*
	);

long
jk_unpack_field_packed_little_endian_uint64_to_jk_ulonglong(
	const jk_field_t* field,
	const void* from,
	void /*jk_ulonglont_t*/* to
	);

typedef struct jk_field_unpackers_t {
	jk_field_unpacker_t zero;
	jk_field_unpacker_t unpack_field_packed_little_endian_uint64_to_jk_ulonglong;
} jk_field_unpackers_t;

extern const jk_field_unpackers_t jk_field_unpackers;

typedef struct jk_fields_t {
   struct {
       jk_field_t magic;
       jk_field_t minor_version;
       jk_field_t major_version;
       jk_field_t constant_pool_count;
       jk_field_t constant_pool; /* variably sized */
       jk_field_t access_flags;
       jk_field_t this_class;
       jk_field_t super_class;
       jk_field_t interfaces_count;
       jk_field_t interfaces; /* variably sized */
       jk_field_t fields_count;
       jk_field_t fields; /* variably sized */
       jk_field_t methods_count;
       jk_field_t methods; /* variably sized */
       jk_field_t attributes_count;
       jk_field_t attributes; /* variably sized */
    } java_classfile;
    struct {
        jk_field_t endian;
        jk_field_t offset_to_first_field;
        jk_field_t offset_to_last_field;
        jk_field_t packed_size;
        jk_field_t unpacked_size;
    } structure;
} jk_fields_t;

extern jk_fields_t jk_fields;

typedef struct jk_struct_t {
    unsigned char endian;
    size_t offset_to_first_field;
    size_t offset_to_last_field;
    size_t packed_size;
    size_t unpacked_size;
} jk_struct_t;

#define jk_number_of(a)        (sizeof(a)/sizeof((a)[0]))
#define jkp_field(t,f)         (((t*)0)->f)
#define jk_field_size(t,f)     (sizeof(jkp_field(t,f)))
#define jk_field_offset(a,b)   ((size_t)&jkp_field(a,b))
#define jk_offsetof(t,f)       jk_field_offset(t,f)
#define jk_offsetof_field(t,f) jk_field_offset(t,f)
#define jk_sizeof_field(t,f)   jk_field_size(t,f)
#define jk_sizeof_struct_through_and_including_field(t,f) (jk_offsetof_field(t,f) + jk_sizeof_field(t,f))
#define jk_sizeof_struct_through_but_excluding_field(t,f) jk_offsetof_field(t,f)
#define jk_does_struct_size_contain_field(s,size,f) ((size) <= jk_sizeof_struct_through_and_including_field(s,f))

/* FUTURE this should be more dynamic */
typedef struct jk_types_t {
    const jk_type_t* t_void;
    const jk_type_t* t_char;
    const jk_type_t* t_schar;
    const jk_type_t* t_uchar;
    const jk_type_t* t_short;
    const jk_type_t* t_ushort;
    const jk_type_t* t_int;
    const jk_type_t* t_uint;
    const jk_type_t* t_long;
    const jk_type_t* t_ulong;
    struct jk_hashtable_t* hashtable;
} jk_types_t;

/* strawman abstraction for fetching dynamically defined types */
jk_type_t *
jk_get_type_by_name(
    const char* s
    );

extern const jk_types_t jk_types;
    
long
jk_array_init(
    jk_array_t* array,
    const jk_type_t* element_type,
    jk_memory_allocator_t* allocator
    );

long
jk_array_get_element_type(
    jk_array_t* array,
    const jk_type_t** element_type
    );

long
jk_array_free(
    jk_array_t* array
    );

long
jk_array_get_base(
    jk_array_t* array,
    void **
    );

long
jk_array_get_pointer_to_element_at(
    jk_array_t* array,
    size_t n,
    void**
    );

long
jk_array_get_size( /* std::vector::size() */
    jk_array_t* array,
    size_t*
    );

long
jk_array_set_size( /* std::vector::resize() */
    jk_array_t* array,
    size_t new_size
    );

long
jk_array_get_allocated_size( /* std::vector::capacity() */
    jk_array_t* array,
    size_t*
    );

long
jk_array_ensure_allocated_size( /* std::vector::reserve() */
    jk_array_t* array,
    size_t new_size
    );
 
long
jk_array_add_last_element(/* std::vector::push_back() */
    jk_array_t* array,
    void* element
    );

long
jk_array_remove_last_element(/* std::vector::pop_back() */
    jk_array_t* array
    );

long
jk_array_get_first_element(/* std::vector::front() */
    jk_array_t* array,
    void **
    );

long
jk_array_get_last_element(/* std::vector::back() */
    jk_array_t* array,
    void **
    );

long
jk_array_set_element_at_index(
    jk_array_t* array,
    size_t n,
    void* element
    );
    
typedef struct jk_array_iterator_t {
    jk_array_t* array;
    size_t index;
} jk_array_iterator_t;

void
jk_assert_iterator_assert_is_valid(
    const jk_array_iterator_t* iterator
    );

long
jk_array_begin(
    jk_array_t* array,
    jk_array_iterator_t* iterator
    );

long
jk_array_end(
    jk_array_t* array,
    jk_array_iterator_t* iterator
    );

long
jk_array_iterator_increment(
    jk_array_iterator_t* iterator
    );

long
jk_array_iterator_decrement(
    jk_array_iterator_t* iterator
    );

long
jk_array_iterator_add_integer(
    jk_array_iterator_t* iterator,
    size_t n
    );

long
jk_array_iterator_subtract_integer(
    jk_array_iterator_t* iterator,
    size_t n
    );

long
jk_array_iterator_subtract_iterator(
    jk_array_iterator_t* iterator,
    const jk_array_iterator_t* iterator_to_subtract
    );
    
long
jk_array_iterator_dereference(
    jk_array_iterator_t* iterator,
    void **
    );

long
jk_array_iterator_is_equal(
    const jk_array_iterator_t* iterator1,
    const jk_array_iterator_t* iterator2,
    jk_boolean_t *
    );

typedef struct jk_hashtable_element_t {
    size_t hash;
    const void* key;
    void* value;
} jk_hashtable_element_t;

typedef struct jk_hashtable_bucket_t {
    jk_array_t elements;
} jk_hashtable_bucket_t;

typedef struct jk_hashtable_static_context_t {
    jk_memory_allocator_t* memory_allocator;
    size_t (*key_hash_function)(const void *);
    bool_t (*key_equal_function)(const void *, const void *);
    const jk_type_t* key_type;
    const jk_type_t* value_type;
} jk_hashtable_static_context_t;

typedef struct jk_hashtable_search_result_t {
    const void* key;
    void* value;
    bool_t found;
    size_t opaque[2];
} jk_hashtable_search_result_t;

typedef struct jk_hashtable_iterator_t {
    struct jk_hashtable_t* hashtable;
    const void* key;
    void* value;
    bool_t done;
    size_t opaque[2];
} jk_hashtable_iterator_t;

typedef struct jk_hashtable_t {
    jk_hashtable_static_context_t* context;
    jk_array_t buckets;
    size_t number_of_elements; /* jk_hashtable_get_size */
    size_t number_of_outstanding_iterators;
} jk_hashtable_t;
    
long
jk_hashtable_init(
    jk_hashtable_t* hashtable,
    jk_hashtable_static_context_t* context
    );

long
jk_hashtable_free(
    jk_hashtable_t* hashtable
    );
    
long
jk_hashtable_get_memory_allocator(
    jk_hashtable_t* hashtable,
    jk_memory_allocator_t** memory_allocator
    );

long
jk_hashtable_get_size(
    jk_hashtable_t* hashtable,
    size_t* size
    );
    
long
jk_hashtable_add_element(
    jk_hashtable_t* hashtable,
    const void* key,
    void* value
    );
    
long
jk_hashtable_remove_key(
    jk_hashtable_t* hashtable,
    const void* key
    );

long
jk_hashtable_remove_all(
    jk_hashtable_t* hashtable
    );

long
jk_hashtable_search(
    jk_hashtable_t* hashtable,
    const void* key,
    jk_hashtable_search_result_t* search_result
    );

long
jk_hashtable_remove_search_result(
    jk_hashtable_t* hashtable,
    jk_hashtable_search_result_t* search_result
    );
    
long
jk_hashtable_iterator_init(
    jk_hashtable_t* hashtable,
    jk_hashtable_iterator_t* iterator,
    bool_t* done
    );

long
jk_hashtable_iterator_remove_and_next(
    jk_hashtable_iterator_t* iterator,
    bool_t* done
    );
    
long
jk_hashtable_iterator_next(
    jk_hashtable_iterator_t* iterator,
    bool_t* done
    );

long
jk_hashtable_iterator_free(
    jk_hashtable_iterator_t* iterator
    );
    
typedef struct jk_java_unresolved_constant_interface_member_ref_no_tag_t {
	unsigned class_index;
	unsigned name_and_type_index;
} jk_java_unresolved_constant_member_ref_no_tag_t;

typedef struct jk_java_unresolved_constant_string_ref_no_tag_t {
	unsigned string_index;
} jk_java_unresolved_constant_string_ref_no_tag_t;

typedef struct jk_java_unresolved_constant_class_ref_no_tag_t {
	unsigned class_index;
} jk_java_unresolved_constant_class_ref_no_tag_t;

typedef struct jk_java_unresolved_constant_name_and_type_no_tag_t {
	unsigned name_index;
	unsigned type_index;
} jk_java_unresolved_constant_name_and_type_no_tag_t;

/*
typedef struct jk_java_packed_unresolved_constant_interface_member_ref_no_tag_t {
	unsigned char class_index[2];
	unsigned char name_and_type_index[2];
} jk_java_packed_unresolved_constant_member_ref_no_tag_t;

typedef struct jk_java_packed_unresolved_constant_string_ref_no_tag_t {
	unsigned char string_index[2];
} jk_java_packed_unresolved_constant_string_ref_no_tag_t;

typedef struct jk_java_packed_unresolved_constant_class_ref_no_tag_t {
	unsigned char class_index[2];
} jk_java_packed_unresolved_constant_class_ref_no_tag_t;
*/

typedef union jk_java_half_word_t {
    unsigned short  us;
} jk_java_half_word_t;

typedef union jk_java_unresolved_constant_no_tag_t {
	jk_java_unresolved_constant_member_ref_no_tag_t field_ref;
	jk_java_unresolved_constant_member_ref_no_tag_t method_ref;
	jk_java_unresolved_constant_member_ref_no_tag_t interface_method_ref;
	jk_java_unresolved_constant_member_ref_no_tag_t member_ref;
	jk_java_unresolved_constant_string_ref_no_tag_t string_ref;
	jk_java_unresolved_constant_class_ref_no_tag_t  class_ref;
	jk_java_unresolved_constant_name_and_type_no_tag_t name_and_type;
} jk_java_unresolved_constant_no_tag_t;

typedef union jk_java_word_t {
    void*    VoidPointer;
    char*    CharPointer;
    jchar_t* JcharPointer;
    unsigned long   UnsignedLong;
    unsigned short  UnsignedShorts[2];
	jk_java_half_word_t HalfWords[2];
    float     Float;
	unsigned char   Bytes[4];
	jk_java_unresolved_constant_no_tag_t unresolved_constant;
} jk_java_word_t;

typedef jk_longlong_t jk_java_long_t;

typedef union jk_java_any_t {
    void*          void_pointer;
    void*          voidpointer;
    void*    		VoidPointer;
    char*          char_pointer;
    char*          charpointer;
    char*    		CharPointer;
    jchar_t*       jchar_pointer;
    jchar_t*       jcharpointer;
    jchar_t* 		JcharPointer;
    unsigned long         unsigned_long;
    unsigned long         unsignedlong;
    unsigned long   		UnsignedLong;
    unsigned short        unsigned_shorts[2];
    unsigned short        unsignedshorts[2];
    unsigned short	  	UnsignedShorts[2];
	jk_java_half_word_t half_word[2];
	jk_java_half_word_t halfwords[2];
	jk_java_half_word_t HalfWords[2];
	float           native_float;
    float        	Float;
    double          native_double;
	double         	Double;
	jk_longlong_t   long_long;
	jk_longlong_t   longlong;
	jk_longlong_t  	LongLong;
	jk_ulonglong_t  ulong_long;
	jk_ulonglong_t  ulonglong;
	jk_ulonglong_t 	UlongLong;
	jk_java_unresolved_constant_no_tag_t unresolved_constant;
} jk_java_any_t;

/* double_word is not portable enough; we need to store doubles "unbroken"
this will lead us to use a stack of jk_java_any_t instead of jk_java_word_t
if we certain we had ieee float and/or ieee double and/or a 32bit machine,
we could optimize; Java clearly has in mind such a machine; we should be
portable to 16 and 32bit machines, and non ieee floating if accuracy
and precision of floating operations can be altered
typedef union jk_java_double_word_t {
    unsigned long  	UnsignedLongs[2];
     long 		Longs[2];
	unsigned char      Bytes[8];
} jk_java_double_word_t;
*/

typedef struct jk_java_constant_memberref_t {
    unsigned class_index;
    unsigned name_and_type_index;
} jk_java_constant_memberref_t;

typedef jk_java_constant_memberref_t jk_java_constant_fieldref_t;
typedef jk_java_constant_memberref_t jk_java_constant_methodref_t;
typedef jk_java_constant_memberref_t jk_java_constant_interfacemethodref_t;

typedef struct jk_java_constant_string_t {
    unsigned string_index;
} jk_java_constant_string_t;

typedef struct jk_java_constant_integer_t {
    unsigned long number;
} jk_java_constant_integer_t;

typedef struct jk_java_constant_float_t {
    float number;
} jk_java_constant_float_t;

typedef union jk_java_constant_untagged_union_t {
    jk_java_constant_memberref_t memberref;
} jk_java_constant_untagged_union_t;

#define jk_java_magic "\xca\xfe\xba\xbe"

typedef struct jk_file_buffer_t {
    unsigned char* buffer;
    size_t buffer_size;
    size_t bytes_in_buffer;
    size_t position;
    size_t read_ahead;
    unsigned keep_all_bytes : 1;
} jk_file_buffer_t;

long
jk_init_file_buffer(
	jk_file_buffer_t* file_buffer
	);

long
jk_free_file_buffer(
	jk_file_buffer_t* file_buffer
	);

typedef struct jk_file_t {
    void* stdio_file;
    const char* file_path;
    const char* openmode;
    jk_file_buffer_t buffer;
} jk_file_t;

long
jk_init_file(
	jk_file_t* file
	);

long
jk_free_file(
	jk_file_t* file
	);

long
jk_file_open_for_read(
    const jk_globals_t* globals,
    jk_file_t* file,
    const char* file_path
    );
    
long
jk_file_read_copy(
    jk_file_t* file,
    void* buffer,
    size_t bytes_to_read,
    size_t* bytes_read /* optional */
    );

long
jk_file_read_get_buffer(
    jk_file_t* file,
    void** buffer,
    size_t bytes_to_read,
    size_t* bytes_read /* optional */
    );

long
jk_file_read_ahead(
    jk_file_t* b,
    size_t bytes_to_read
    );
    
long
jk_file_close(
    jk_file_t* f
    );

typedef struct jk_java_constant_pool_t {
    unsigned      count;
    unsigned char*   tags;
    jk_java_any_t* any;
} jk_java_constant_pool_t;

typedef struct jk_java_classfile_t {
    jk_file_t   file;
    unsigned char     magic[4];
    unsigned      minor_version;
    unsigned      major_version;
    jk_java_constant_pool_t constant_pool;
    unsigned      access_flags;
    unsigned      this_class;
    unsigned      super_class;
    unsigned      interfaces_count;
    jk_array_t  interfaces;
    unsigned      fields_count;
    unsigned      methods_count;
    unsigned      attributes_count;
} jk_java_classfile_t;

typedef struct jk_java_packed_classfile1_t {
    unsigned char    magic[4];
    unsigned char    minor_version[2];
    unsigned char    major_version[2];
	struct {
	    unsigned char    count[2];
	} constant_pool;
    /* constant_pool */
} jk_java_packed_classfile1_t;

typedef struct jk_java_packed_classfile2_t {
    unsigned char    access_flags[2];
    unsigned char    this_class[2];
    unsigned char    super_class[2];
    unsigned char    interfaces_count[2];
    /* unsigned char interfaces[interfaces_count][[2] */
} jk_java_packed_classfile2_t;

typedef struct jk_java_packed_classfile3_t {
    unsigned char    magic[4];
    unsigned char    minor_version[2];
    unsigned char    major_version[2];
	struct {
	    unsigned char    count[2];
	} constant_pool;
    /* constant_pool */
    unsigned char    access_flags[2];
    unsigned char    this_class[2];
    unsigned char    super_class[2];
    unsigned char    interfaces_count[2];
    /* unsigned char interfaces[interfaces_count][[2]; */
    unsigned char fields_count[2];
    /* jk_java_packed_field_info_t fields[fields_count]; */
    unsigned char methods_count[2];
    /* jk_java_packed_method_info_t methods[method_count]; */
    unsigned char attributes_count[2];
    /* jk_java_packed_attribute_info_t attributes[attribute_count]; */
} jk_java_packed_classfile3_t;

#define jk_java_constant_class_tag          (7)
#define jk_java_constant_fieldref_tag       (9)
#define jk_java_constant_methodref_tag      (10)
#define jk_java_constant_interfacemethodref_tag (11)
#define jk_java_constant_string_tag         (8)
#define jk_java_constant_integer_tag        (3)
#define jk_java_constant_float_tag          (4)
#define jk_java_constant_long_tag           (5)
#define jk_java_constant_double_tag         (6)
#define jk_java_constant_name_and_type_tag  (12)
#define jk_java_constant_utf8_tag           (1)

typedef struct jk_java_constant_class_t {
    unsigned tag;
    unsigned name_index;
} jk_java_constant_class_t;

long
jk_file_read_and_unpack(
    const jk_globals_t* globals,
    jk_file_t* f,
    jk_struct_t* spec,
    size_t packed_buffer_size,
    void* unpacked_buffer,
    size_t unpacked_buffer_size
    );

long
jk_file_read_and_unpack_array(
    const jk_globals_t* globals,
    jk_file_t* file,
    jk_array_t* array,
    size_t offset,
    size_t size
    );

long
jk_unpack(
    const jk_globals_t* globals,
    unsigned endian,
    const void* vpacked_buffer,
    void* vunpacked_buffer,
    jk_struct_t* specs
    );

#define jk_min(x,y) (((x) < (y)) ? (x) : (y))
#define jk_max(x,y) (((x) < (y)) ? (y) : (x))

long
jk_compute_packed_or_unpacked_size(
    const jk_globals_t* globals,
    jk_struct_t* p,
    unsigned packed_or_unpacked
    );

long
jk_compute_packed_size(
    const jk_globals_t* globals,
    jk_struct_t* p
    );

long
jk_compute_unpacked_size(
    const jk_globals_t* globals,
    jk_struct_t* p
    );

unsigned jk_align_integer(unsigned n);

long
jk_file_open_for_read(
    const jk_globals_t* globals,
    jk_file_t* file,
    const char* file_path
    );

long
jk_file_close(
    jk_file_t* file
    );

long
jkp_file_read_direct(
    jk_file_t* file,
    void* buffer,
    size_t bytes_to_read,
    size_t* bytes_read
    );

long
jk_dump_struct(
    const jk_globals_t* globals,
    const char* prefix,
    const void* vbase,
    const jk_struct_t* desc
    );

long
jk_file_read_ahead(
    jk_file_t* file,
    size_t n
    );

long
jk_file_read_copy(
    jk_file_t* file,
    void* buffer,
    size_t bytes_to_read,
    size_t* bytes_read
    );
    
long
jk_file_read_get_buffer(
    jk_file_t* file,
    void** out_buffer,
    size_t bytes_to_read,
    size_t* out_bytes_read
    );

unsigned
jk_get_big_endian_u2(
    const unsigned char* a
    );

unsigned long
jk_get_big_endian_u4(
    const unsigned char* a
    );

unsigned
jk_get_little_endian_u2(
    const unsigned char* a
    );
    
unsigned long
jk_get_little_endian_u4(
    const unsigned char* a
    );

extern const float jk_java_positive_infinity_float;
extern const float jk_java_negative_infinity_float;
extern const double jk_java_positive_infinity_double;
extern const double jk_java_negative_infinity_double;
extern const float jk_java_nan_float;
extern const double jk_java_nan_double;

/*
jk_ulonglong_t
jk_longlong_to_ulonglong(
    jk_longlong_t a
    );
*/

jk_ulonglong_t*
jk_longlong_to_ulonglong_pointer(
    jk_longlong_t* a
    );

void
jk_longlong_assign_zero(
    jk_longlong_t* a
    );

void
jk_longlong_from_long(
    jk_longlong_t* a,
    long b
    );

void
jk_longlong_from_ulong(
    jk_longlong_t* a,
    unsigned long b
    );

void
jk_ulonglong_assign_zero(
    jk_ulonglong_t* a
    );

void
jk_ulonglong_from_ulong(
    jk_ulonglong_t* a,
    unsigned long b
    );

long
jk_carry_to_error(
	unsigned carry
	);

typedef unsigned jk_carry_t;

/* long */

void jk_long_add_with_carry_in(long* a, long b, long c, jk_carry_t carry);
void jk_long_add_with_carry_out(long* a, long b, long c, jk_carry_t* carry);
void jk_long_add_with_carry_in_and_out(long* a, long b, long c, jk_carry_t* carry);

void jk_long_add_in_place_with_carry_in(long* a, long b, jk_carry_t carry);
void jk_long_add_in_place_with_carry_out(long* a, long b, jk_carry_t* carry);
void jk_long_add_in_place_with_carry_in_and_out(long* a, long b, jk_carry_t* carry);

/* unsigned long */

void jk_ulong_add_with_carry_in(unsigned long* a, unsigned long b, unsigned long c, jk_carry_t carry);
void jk_ulong_add_with_carry_out(unsigned long* a, unsigned long b, unsigned long c, jk_carry_t* carry);
void jk_ulong_add_with_carry_in_and_out(unsigned long* a, unsigned long b, unsigned long c, jk_carry_t* carry);

void jk_ulong_add_in_place_with_carry_in(unsigned long* a, unsigned long b, jk_carry_t carry);
void jk_ulong_add_in_place_with_carry_out(unsigned long* a, unsigned long b, jk_carry_t* carry);
void jk_ulong_add_in_place_with_carry_in_and_out(unsigned long* a, unsigned long b, jk_carry_t* carry);

void jk_ulong_add_one_with_carry_out(unsigned long* a, unsigned long b, jk_carry_t* carry);
void jk_ulong_add_one_in_place_with_carry_out(unsigned long* a, jk_carry_t* carry);

/* size_t */

void jk_sizet_add_with_carry_in(size_t* a, size_t b, size_t c, jk_carry_t carry);
void jk_sizet_add_with_carry_out(size_t* a, size_t b, size_t c, jk_carry_t* carry);
void jk_sizet_add_with_carry_in_and_out(size_t* a, size_t b, size_t c, jk_carry_t* carry);

void jk_sizet_add_in_place_with_carry_in(size_t* a, size_t b, jk_carry_t carry);
void jk_sizet_add_in_place_with_carry_out(size_t* a, size_t b, jk_carry_t* carry);
void jk_sizet_add_in_place_with_carry_in_and_out(size_t* a, size_t b, jk_carry_t* carry);

void jk_sizet_add_one_with_carry_out(size_t* a, size_t b, jk_carry_t* carry);
void jk_sizet_add_one_in_place_with_carry_out(size_t* a, jk_carry_t* carry);
void jk_sizet_add_one_in_place_with_carry_out(size_t* a, jk_carry_t* carry);

/* jk_longlong_t
   jk_ulonglong_t
*/

void
jk_longlong_add(
    jk_longlong_t* a,
    const jk_longlong_t* b,
    const jk_longlong_t* c
    );

void
jk_ulonglong_add(jk_ulonglong_t* a, const jk_ulonglong_t* b, const jk_ulonglong_t* c);

void
jk_ulonglong_bitwise_and(
    jk_ulonglong_t* a,
    const jk_ulonglong_t* b,
    const jk_ulonglong_t* c
    );

void
jk_ulonglong_bitwise_or(
    jk_ulonglong_t* a,
    const jk_ulonglong_t* b,
    const jk_ulonglong_t* c
    );

void
jk_longlong_bitwise_and(
    jk_longlong_t* a,
    const jk_longlong_t* b,
    const jk_longlong_t* c
    );

void
jk_longlong_bitwise_or(
    jk_longlong_t* a,
    const jk_longlong_t* b,
    const jk_longlong_t* c
    );

unsigned
jk_ulonglong_to_boolean(
    const jk_ulonglong_t* a
    );

unsigned
jk_longlong_to_boolean(
    const jk_longlong_t* a
    );

unsigned
jk_ulonglong_logical_and(
    const jk_ulonglong_t* a,
    const jk_ulonglong_t* b
    );

unsigned
jk_ulonglong_logical_or(
    const jk_ulonglong_t* a,
    const jk_ulonglong_t* b
    );

unsigned
jk_longlong_logical_and(
    const jk_longlong_t* a,
    const jk_longlong_t* b
    );

unsigned
jk_longlong_logical_or(
    const jk_longlong_t* a,
    const jk_longlong_t* b
    );

void
jk_ulonglong_bitwise_invert(
    jk_ulonglong_t* a,
    const jk_ulonglong_t* b
    );

void
jk_longlong_bitwise_invert(
    jk_longlong_t* a,
    const jk_longlong_t* b
    );

unsigned
jk_ulonglong_logical_not(
    const jk_ulonglong_t* a
    );

unsigned
jk_longlong_logical_not(
    const jk_longlong_t* a
    );

void
jk_ulonglong_left_shift(
    jk_ulonglong_t* a,
    const jk_ulonglong_t* b,
    unsigned shift
    );

void
jk_longlong_left_shift(
    jk_longlong_t* a,
    const jk_longlong_t* b,
    unsigned shift
    );

void
jk_ulonglong_right_shift(
    jk_ulonglong_t* a,
    const jk_ulonglong_t* b,
    unsigned shift
    );

long
jk_long_with_n_right_bits_clear(
    unsigned n
    );

long
jk_long_with_n_right_bits_set(
    unsigned n
    );

long
jk_long_with_n_left_bits_clear(
    unsigned n
    );

long
jk_long_with_n_left_bits_set(
    unsigned n
    );

#define jk_bits_of(x) (sizeof(x)*8)

unsigned long
jk_ulong_one_fill_right_shift(
    unsigned long a,
    unsigned shift
    );

unsigned long
jk_ulong_zero_fill_right_shift(
    unsigned long a,
    unsigned shift
    );

long
jk_long_one_fill_right_shift(
    long a,
    unsigned shift
    );

long
jk_long_zero_fill_right_shift(
    long a,
    unsigned shift
    );

long
jk_long_sign_fill_right_shift(
    long a,
    unsigned shift
    );

void
jk_ulonglong_one_fill_right_shift(jk_ulonglong_t* a, const jk_ulonglong_t* b, unsigned shift);

void
jk_ulonglong_zero_fill_right_shift(jk_ulonglong_t* a, const jk_ulonglong_t* b, unsigned shift);

void
jk_longlong_one_fill_right_shift(jk_longlong_t* a, const jk_longlong_t* b, unsigned shift);

void
jk_longlong_zero_fill_right_shift(jk_longlong_t* a, const jk_longlong_t* b, unsigned shift);

void
jk_longlong_sign_fill_right_shift(jk_longlong_t* a, const jk_longlong_t* b, unsigned shift);

void
jk_ulong_multiply_to_ulonglong(
	jk_ulonglong_t* a,
	unsigned long b,
	unsigned long c
	);

void
jk_long_multiply_to_longlong(
	jk_longlong_t* a,
	long b,
	long c
	);

void
jk_ulonglong_multiply(
	jk_ulonglong_t* a,
	const jk_ulonglong_t* b,
	const jk_ulonglong_t* c
	);

void
jk_longlong_multiply(
	jk_longlong_t* a,
	const jk_longlong_t* b,
	const jk_longlong_t* c
	);

float
jk_java_convert_java_float_to_native_float(
    const unsigned char* bytes
    );

double
jk_java_convert_java_double_to_native_double(
    const unsigned char* bytes
    );

void
jk_java_get_long(
    jk_longlong_t* i,
    const unsigned char* p
    );

void
jk_java_get_ulong(
    jk_ulonglong_t* i,
    const unsigned char* p
    );

long
jk_java_read_constant_pool(
    jk_file_t* file,
    jk_java_constant_pool_t* constant_pool
    );

long
jk_java_read_classfile(
    const jk_globals_t* globals,
    jk_java_classfile_t** ppcf,
	const char* filepath
	);

unsigned long
jk_ulong_rotate_left(
	unsigned long a,
	unsigned b
	);

unsigned long
jk_ulong_rotate_right(
	unsigned long a,
	unsigned b
	);
    
void
jk_add_ulong_to_ulonglong_in_place(
    jk_ulonglong_t* a,
    unsigned long b
    );

typedef union jkp_opaque_cookie_union_t {
	unsigned i;
	void* p;
} jkp_opaque_cookie_union_t;

typedef struct jk_opaque_cookie_t {
	union {
		char b[sizeof(jkp_opaque_cookie_union_t)];
		unsigned i;
		void* p;
	} u;
} jk_opaque_cookie_t;

void
jk_opaque_cookie_init(
	jk_opaque_cookie_t* cookie
	);

/*
this interface supports usual pointer-ful heaps and position independent, compactable heaps

the out pointer from allocate may just be an opaque cookie
that you may have to pass to convert_cookie_to_pointer to use
the result of convert_cookie_to_pointer may be invalidated
by calls to allocate and free, but the opaque cookie never is
*/
typedef long (*jk_memory_allocator_functions_allocate_t)(jk_memory_allocator_t *, size_t number_of_bytes, jk_opaque_cookie_t* cookie);
typedef long (*jk_memory_allocator_functions_free_t)(jk_memory_allocator_t *, jk_opaque_cookie_t* cookie);
typedef long (*jk_memory_allocator_functions_convert_cookie_to_pointer_t)(jk_memory_allocator_t *, jk_opaque_cookie_t cookie, void** p);
 
struct jk_memory_allocator_functions_t {
    jk_memory_allocator_functions_allocate_t allocate;
    jk_memory_allocator_functions_free_t free;
    jk_memory_allocator_functions_convert_cookie_to_pointer_t convert_cookie_to_pointer;
};

struct jk_memory_allocator_t {
    const jk_memory_allocator_functions_t* functions;
};

long
jk_default_memory_allocator_allocate(
    jk_memory_allocator_t* state,
    size_t number_of_bytes,
    jk_opaque_cookie_t* cookie
    );

long
jk_default_memory_allocator_free(
    jk_memory_allocator_t* state,
    jk_opaque_cookie_t* cookie
    );

long
jk_default_memory_allocator_convert_cookie_to_pointer(
    jk_memory_allocator_t* state,
    jk_opaque_cookie_t cookie,
    void** pointer
    );

typedef struct jk_multiprecisioninteger_t jk_multiprecisioninteger_t;

void
jk_multiprecision_integer_trim_heap(
    jk_multiprecisioninteger_t* m
    );

unsigned long *
jk_multipleprecision_integer_get_value_array(
    const jk_multiprecisioninteger_t* m
    );
    
long
jk_multiprecision_integer_from_long(
    jk_multiprecisioninteger_t* m,
    long i
    );

long
jk_multiprecision_integer_from_ulong(
    jk_multiprecisioninteger_t* m,
    unsigned long i
    );

long
jk_multiprecision_integer_from_ulong_and_sign(
    jk_multiprecisioninteger_t* m,
    unsigned long i,
    int sign
    );

long
jk_multiprecision_integer_ensure_precision(
    jk_multiprecisioninteger_t* m,
    unsigned n
    );

long
jk_multiprecision_integer_set_precision(
    jk_multiprecisioninteger_t* m,
    unsigned n
    );
    
void
jk_ulonglong_add_in_place(
	jk_ulonglong_t* a,
	const jk_ulonglong_t* b
	);

void
jk_add_ulong_to_ulonglong(
    jk_ulonglong_t* a,
    const jk_ulonglong_t* c,
    unsigned long b
    );

void
jk_ulonglong_bitwise_exclusive_or(
	jk_ulonglong_t* a,
	const jk_ulonglong_t* b,
	const jk_ulonglong_t* c
	);

void
jk_longlong_bitwise_exclusive_or(
	jk_longlong_t* a,
	const jk_longlong_t* b,
	const jk_longlong_t* c
	);

void
jk_ulonglong_bitwise_invert_in_place(
	jk_ulonglong_t* a
	);

void
jk_longlong_bitwise_invert_in_place(
	jk_longlong_t* a
	);

unsigned long
jk_ulong_extract_left_n_bits_right_aligned(
	unsigned long a,
	unsigned n
	);

unsigned long
jk_ulong_extract_left_n_bits(
	unsigned long a,
	unsigned n
	);

unsigned long
jk_ulong_extract_right_n_bits(
	unsigned long a,
	unsigned n
	);

unsigned long
jk_ulong_extract_right_n_bits_left_aligned(
	unsigned long a,
	unsigned n
	);

void
jk_ulonglong_left_shift_in_place(
	jk_ulonglong_t* a,
	unsigned shift
	);

unsigned long
jk_ulong_with_n_right_bits_clear(
	unsigned n
	);

unsigned long
jk_ulong_with_n_right_bits_set(
	unsigned n
	);

unsigned long
jk_ulong_with_n_left_bits_clear(
	unsigned n
	);

unsigned long
jk_ulong_with_n_left_bits_set(
	unsigned n
	);

unsigned long
jk_ulong_get_right_justified_high_half(
	unsigned long a
	);

unsigned long
jk_ulong_get_low_half(
	unsigned long a
	);

unsigned long
jk_ulong_get_left_justified_high_half(
	unsigned long a
	);

void
jk_signed_char_split_into_magnitude_and_sign(
    signed char i,
    unsigned char* magnitude,
    int* sign
    );

void
jk_short_split_into_magnitude_and_sign(
    short i,
    unsigned short* magnitude,
    int* sign
    );

void
jk_int_split_into_magnitude_and_sign(
    int i,
    unsigned* magnitude,
    int* sign
    );

void
jk_long_split_into_magnitude_and_sign(
    long i,
    unsigned long* magnitude,
    int* sign
    );

unsigned long
jkp_common_split_into_magnitude_and_sign(
    long i,
    int* sign
    );

void
jk_longlong_split_into_magnitude_and_sign(
	const jk_longlong_t* i,
    jk_ulonglong_t* magnitude,
    int* sign
    );

void
jk_longlong_negate(
    jk_longlong_t* a,
    const jk_longlong_t* b
    );
    
void
jk_longlong_negate_in_place(
    jk_longlong_t* a
    );

void
jk_longlong_add_in_place(
    jk_longlong_t* a,
    const jk_longlong_t* b
    );

long
jk_java_init_constant_pool(
	jk_java_constant_pool_t* constant_pool
	);

long
jk_java_init_classfile(
	jk_java_classfile_t* classfile
	);
	
void
jk_java_free_constant_pool(
    jk_java_constant_pool_t* constant_pool
    );
	
long
jk_java_free_classfile(
    jk_java_classfile_t* classfile
    );

void
jk_profile_dump_function_call_counts(
    void
    );

typedef struct {
	size_t value;
} jk_spin_lock_t;

typedef struct {
	size_t value;
} jk_spin_lock_holder_t;

void jk_initialize_spin_lock(jk_spin_lock_t* lock);
void jk_acquire_spin_lock(jk_spin_lock_t* lock, jk_spin_lock_holder_t* holder);
void jk_release_spin_lock(jk_spin_lock_t* lock, jk_spin_lock_holder_t* holder);

void jk_spin(int i);

void jk_sleep(int i);

typedef struct jk_profile_record_t {
	unsigned long call_count;
	struct jk_profile_record_t* next;
	const jk_constant_string_t* function_name;
} jk_profile_record_t;

extern jk_spin_lock_t        jk_profile_record_list_lock;
extern jk_profile_record_t* jk_profile_record_list;

void
jkp_initialize_profile_record(
	jk_profile_record_t* profile_record
	);

#define jk_profile_count_function_call() \
do { static jk_profile_record_t profile_record = { 0, 0, &function }; \
		profile_record.call_count += 1; \
		if (!profile_record.next) { \
			jkp_initialize_profile_record(&profile_record); \
		} \
	} while(0)

void jk_interlocked_compare_exchange_pointer();
void jk_interlocked_exchange_pointer();
long jk_interlocked_increment_long(long *);
long jk_interlocked_decrement_long(long *);

typedef struct jk_critical_section_t { int i; size_t x[6]; } jk_critical_section_t;
void jk_enter_critical_section(jk_critical_section_t* cs);
void jk_leave_critical_section(jk_critical_section_t* cs);

void jk_memory_barrier(void);

typedef struct jk_range_t {
    size_t start;
    size_t count;
} jk_range_t;

typedef struct jk_range_table_t {
    jk_array_t array_of_ranges;
} jk_range_table_t;

long
jk_range_table_init(
    jk_range_table_t* range_table
    );
    
long
jk_range_table_add_value(
    jk_range_table_t* range_table,
    size_t value
    );

long
jk_range_table_remove_value(
    jk_range_table_t* range_table,
    size_t value
    );
    
long
jk_range_table_add_range(
    jk_range_table_t* range_table,
    const jk_range_t* range
    );

long
jk_range_table_remove_range(
    jk_range_table_t* range_table,
    const jk_range_t* range
    );
    
long
jk_range_table_contains_value(
    jk_range_table_t* range_table,
    size_t value,
    jk_bool_t* contains_value
    );

long
jk_range_table_find_range_with_value(
    jk_range_table_t* range_table,
    size_t value,
    jk_range_t* range
    );

/*
a special heap is
  compactable
  position independent
  contiguous
  it'd be nice of the contiguity could be optional so that address space fragmentation
     doesn't limit our ability to allocate so much
*/

typedef struct jk_special_heap_block_t {
    size_t  size;
    size_t  offset;
    unsigned long sequence_number;
} jk_special_heap_block_t;

typedef struct jk_special_heap_t {
    jk_memory_allocator_t* memory_allocator;
    unsigned char*   store;
    size_t      size;
    size_t      sequence_number;
    size_t      number_of_free_blocks;
    size_t      number_of_used_blocks;
    size_t      offset_to_used_blocks_sorted_by_sequence_number;
    size_t      offset_to_free_blocks_sorted_by_size;
    size_t      offset_to_free_blocks_sorted_by_offset;
} jk_special_heap_t;

long
jk_special_heap_init(
    jk_special_heap_t* heap,
    jk_memory_allocator_t* allocator
    );

long
jk_special_heap_destroy(
    jk_special_heap_t* heap
    );

long
jk_special_heap_alloc(
    jk_special_heap_t* heap,
    size_t number_of_bytes_to_allocate,
    unsigned long* sequence_number,
    void** optional_out_unstable_pointer
    );

long
jk_special_heap_get_pointer(
    jk_special_heap_t* heap,
    unsigned long sequence_number,
    void** pointer
    );

long
jk_special_heap_free(
    jk_special_heap_t* heap,
    unsigned long sequence_number
    );

long
jk_undone(
    void
    );

void jk_unused(const void *);
void jk_unused2(const void* a1, const void* a2);
void jk_unused3(const void* a1, const void* a2, const void* a3);
void jk_unused4(const void* a1, const void* a2, const void* a3, const void* a4);
void jk_init_fields(void);
void jk_init_classfile_type_info(void);
void jk_limited_truncating_string_copy(char* dest, const char* src, size_t n);
void jk_type_dump_char(const jk_type_t* t, size_t buffer_size, char* buffer, void* data);

long
jk_malloc(
	void** pp,
	size_t n
	);

void
jk_free(
	void** pp
	);

typedef struct jk_heap_t {
	int pad;
} jk_heap_t;

jk_heap_t* jk_get_default_heap();

long
jk_heap_allocate_memory(
	jk_heap_t* heap,
	void** pp,
	size_t n
	);

void
jk_heap_free_memory(
	jk_heap_t* heap,
	void** pp
	);

void
jk_longlong_left_shift_in_place(
    jk_longlong_t* a,
    unsigned shift
    );
    
long
jk_long_safe_negate(
    long i
    );

void
jk_longlong_left_shift_in_place(
    jk_longlong_t* a,
    unsigned shift
    );

unsigned
jk_ulonglong_is_greater_or_equal(
    const jk_ulonglong_t* i,
    const jk_ulonglong_t* j
    );

unsigned
jk_ulonglong_is_greater(
    const jk_ulonglong_t* i,
    const jk_ulonglong_t* j
    );

unsigned
jk_ulonglong_is_less(
    const jk_ulonglong_t* i,
    const jk_ulonglong_t* j
    );

unsigned
jk_ulonglong_is_less_or_equal(
    const jk_ulonglong_t* i,
    const jk_ulonglong_t* j
    );

unsigned
jk_ulonglong_is_equal(
    const jk_ulonglong_t* i,
    const jk_ulonglong_t* j
    );

unsigned
jk_ulonglong_is_not_equal(
    const jk_ulonglong_t* i,
    const jk_ulonglong_t* j
    );


unsigned
jk_longlong_is_greater_or_equal(
    const jk_longlong_t* i,
    const jk_longlong_t* j
    );

unsigned
jk_longlong_is_greater(
    const jk_longlong_t* i,
    const jk_longlong_t* j
    );

unsigned
jk_longlong_is_less(
    const jk_longlong_t* i,
    const jk_longlong_t* j
    );

unsigned
jk_longlong_is_less_or_equal(
    const jk_longlong_t* i,
    const jk_longlong_t* j
    );

unsigned
jk_longlong_is_equal(
    const jk_longlong_t* i,
    const jk_longlong_t* j
    );

unsigned
jk_longlong_is_not_equal(
    const jk_longlong_t* i,
    const jk_longlong_t* j
    );

#define jk_swap_primtive(T,x,y) do { T t = x; x = y; y = t; } while(0)
#define jk_integer_compare_tristate(x,y) ((x == y) ? 0 : (x < y) ? -1 : +1)

unsigned
jk_ulonglong_is_in_ordered_range_inclusive(
    const jk_ulonglong_t* i,
    const jk_ulonglong_t* low,
    const jk_ulonglong_t* high
    );

unsigned
jk_longlong_is_in_ordered_range_inclusive(
    const jk_longlong_t* i,
    const jk_longlong_t* low,
    const jk_longlong_t* high
    );

void
jk_ulonglong_order_range(
    const jk_ulonglong_t** low,
    const jk_ulonglong_t** high
    );

void
jk_longlong_order_range(
    const jk_longlong_t** low,
    const jk_longlong_t** high
    );

unsigned
jk_ulonglong_is_in_unordered_range_inclusive(
    const jk_ulonglong_t* i,
    const jk_ulonglong_t* j,
    const jk_ulonglong_t* k
    );

unsigned
jk_longlong_is_in_unordered_range_inclusive(
    const jk_longlong_t* i,
    const jk_longlong_t* j,
    const jk_longlong_t* k
    );

unsigned
jk_ulonglong_is_in_ordered_range_exclusive(
    const jk_ulonglong_t* i,
    const jk_ulonglong_t* low,
    const jk_ulonglong_t* high
    );

unsigned
jk_longlong_is_in_ordered_range_exclusive(
    const jk_longlong_t* i,
    const jk_longlong_t* low,
    const jk_longlong_t* high
    );

unsigned
jk_ulonglong_is_in_unordered_range_exclusive(
    const jk_ulonglong_t* i,
    const jk_ulonglong_t* j,
    const jk_ulonglong_t* k
    );

unsigned
jk_longlong_is_in_unordered_range_exclusive(
    const jk_longlong_t* i,
    const jk_longlong_t* j,
    const jk_longlong_t* k
    );
 
void
jk_copy_ulonglong_to_longlong(
    jk_longlong_t* to,
    const jk_ulonglong_t* from
    );

void
jk_copy_longlong_to_ulonglong(
    jk_ulonglong_t* to,
    const jk_longlong_t* from
    );
    
void
jk_ulonglong_from_long(
    jk_ulonglong_t* a,
    long b
    );

unsigned
jk_multiprecision_integer_to_boolean(
    const jk_multiprecisioninteger_t* m
    );

unsigned
jk_multiprecision_integer_logical_not(
    const jk_multiprecisioninteger_t* m
    );

unsigned
jk_multiprecision_integer_logical_and(
    const jk_multiprecisioninteger_t* m,
    const jk_multiprecisioninteger_t* n
    );

unsigned
jk_multiprecision_integer_logical_or(
    const jk_multiprecisioninteger_t* m,
    const jk_multiprecisioninteger_t* n
    );

long
jk_multiprecision_integer_bitwise_invert(
    jk_multiprecisioninteger_t* m
    );

long
jk_multiprecision_integer_bitwise_and(
    jk_multiprecisioninteger_t* m,
    const jk_multiprecisioninteger_t* n
    );
 
long
jk_multiprecision_integer_reduce_precision_due_to_leading_zeros(
    jk_multiprecisioninteger_t* m
    );

long
jk_multiprecision_integer_bitwise_or(
    jk_multiprecisioninteger_t* m,
    const jk_multiprecisioninteger_t* n
    );
    
void
jk_ulonglong_add_one_in_place(
    jk_ulonglong_t* a
    );

void
jk_longlong_add_one_in_place(
    jk_longlong_t* a
    );

void
jk_ulonglong_add_one(
    jk_ulonglong_t* a,
    const jk_ulonglong_t* b
    );

void
jk_longlong_add_one(
    jk_longlong_t* a,
    const jk_longlong_t* b
    );
    
void
jk_ulonglong_negate(
    jk_ulonglong_t* a,
    const jk_ulonglong_t* b
    );

void
jk_ulonglong_negate_in_place(
    jk_ulonglong_t* a
    );

void
jk_ulonglong_bitwise_and_with_ulong_in_place(
    jk_ulonglong_t* a,
    unsigned long b
    );

unsigned
jk_assert_failed(
    const char* x,
    const char* file,
    long line
    );

void
jk_ulonglong_from_high_low_32bit_ulongs(
    jk_ulonglong_t* i,
    unsigned long high,
    unsigned long low
    );

void
jk_ulonglong_bitwise_or_in_place(
    jk_ulonglong_t* a,
    const jk_ulonglong_t* b
    );
    
void
jk_ulonglong_right_shift_in_place(
    jk_ulonglong_t* a,
    unsigned shift
    );

void
jk_utoa(
    unsigned u,
    char* a
    );
    
void
jk_itoa(
    int i,
    char* a
    );

void
jk_ultoa(
    unsigned long u,
    char* a
    );
    
void
jk_ltoa(
    long i,
    char* a
    );

unsigned
jk_unsigned_times_10(
    unsigned u
    );

#define jkp_preprocessor_paste(x,y) x##y
#define jk_preprocessor_paste(x,y)  jkp_preprocessor_paste(x,y)

/*define jk_compile_time_assert(x) typedef unsigned char jk_preprocessor_paste(jkp_compile_time_assert_private,__LINE__)[(x) ? 1 : 0]*/
#define jk_compile_time_assert(x) typedef unsigned char jkp_compile_time_assert_private[(x) ? 1 : 0]

typedef struct jk_buffer_t {
	jk_opaque_cookie_t cookie;
	void* bytes;
	void* static_buffer;
	size_t static_size;
	size_t allocated_size;
	size_t requested_size;
    jk_memory_allocator_t* allocator;
} jk_buffer_t;

long
jk_buffer_init(
	jk_buffer_t* buffer,
	size_t preallocated_buffer_size,
	void* preallocated_buffer
	);
	
void
jk_buffer_free(
	jk_buffer_t* buffer
	);
	
long
jk_buffer_set_size(
	jk_buffer_t* buffer,
	size_t size,
	void** pointer /* optional */
	);

long
jk_buffer_get_size(
	jk_buffer_t* buffer,
	size_t* size
	);

long
jk_buffer_get_pointer(
	jk_buffer_t* buffer,
	void** pointer
	);

#define jk_mspecoff_directory_entry_com_descriptor 14

typedef struct jk_mspecoff_packed_data_directory_t {
	unsigned char virtual_address[4];
	unsigned char size[4];
} jk_mspecoff_packed_data_directory_t;

typedef struct jk_mspecoff_data_directory_t {
	unsigned long virtual_address;
	unsigned long size;
} jk_mspecoff_data_directory_t;

typedef struct jk_mspecoff_packed_file_header_packed_t {
	unsigned char machine[2];
	unsigned char number_of_sections[2];
	unsigned char time_date_stamp[4];
	unsigned char pointer_to_symbol_table[4];
	unsigned char number_of_symbols[4];
	unsigned char size_of_optional_header[2];
	unsigned char characteristics[2]; /* aka flags */
} jk_mspecoff_packed_file_header_packed_t;

typedef struct jk_mspecoff_file_header_t {
	unsigned machine;
	unsigned number_of_sections;
	unsigned long time_date_stamp;
	unsigned long pointer_to_symbol_table;
	unsigned long number_of_symbols;
	unsigned size_of_optional_header;
	unsigned characteristics; /* aka flags */
} jk_mspecoff_file_header_t;

typedef struct jk_mspecoff_packed_optional_header32_t {
	/* standard fields */
	unsigned char magic[2];
	unsigned char major_linker_version;
	unsigned char minor_link_version;
	unsigned char size_of_code[4];
	unsigned char size_of_initialized_data[4];
	unsigned char size_of_uninitialized_data[4];
	unsigned char adddress_of_entry_point[4];
	unsigned char base_of_code[4];
	unsigned char base_of_data[4];
	/* nt fields */
	unsigned char image_base[4];
	unsigned char section_alignment[4]; /* aka in_memory_section_alignment */
	unsigned char file_alignment[4]; /* aka on_disk_section_alignment */
	unsigned char major_operating_system_version[2];
	unsigned char minor_operating_system_version[2];
	unsigned char major_image_version[2];
	unsigned char minor_image_version[2];
	unsigned char major_subsystem_version[2];
	unsigned char minor_subsystem_version[2];
	unsigned char win32_version[4];
	unsigned char size_of_image[4];
	unsigned char size_of_headers[4];
	unsigned char checksum[4];
	unsigned char subsystem[2];
	unsigned char dll_characteristics[2]; /* aka flags */
	unsigned char size_of_stack_reserve[4];
	unsigned char size_of_stack_commit[4];
	unsigned char size_of_heap_reserve[4];
	unsigned char size_of_heap_commit[4];
	unsigned char loader_flags[4];
	unsigned char number_of_rva_and_sizes[4]; /* aka number_of_data_directories */
} jk_mspecoff_packed_optional_header32_t;

typedef struct jk_mspecoff_packed_optional_header64_t {
	/* standard fields */
	unsigned char magic[2];
	unsigned char major_linker_version;
	unsigned char minor_link_version;
	unsigned char size_of_code[4];
	unsigned char size_of_initialized_data[4];
	unsigned char size_of_uninitialized_data[4];
	unsigned char adddress_of_entry_point[4];
	unsigned char base_of_code[4];
	/* nt fields */
	unsigned char image_base[8];
	unsigned char section_alignment[4]; /* aka in_memory_section_alignment */
	unsigned char file_alignment[4]; /* aka on_disk_section_alignment */
	unsigned char major_operating_system_version[2];
	unsigned char minor_operating_system_version[2];
	unsigned char major_image_version[2];
	unsigned char minor_image_version[2];
	unsigned char major_subsystem_version[2];
	unsigned char minor_subsystem_version[2];
	unsigned char win32_version[4];
	unsigned char size_of_image[4];
	unsigned char size_of_headers[4];
	unsigned char checksum[4];
	unsigned char subsystem[2];
	unsigned char dll_characteristics[2]; /* aka flags */
	unsigned char size_of_stack_reserve[8];
	unsigned char size_of_stack_commit[8];
	unsigned char size_of_heap_reserve[8];
	unsigned char size_of_heap_commit[8];
	unsigned char loader_flags[4];
	unsigned char number_of_rva_and_sizes[4]; /* aka number_of_data_directories */
} jk_mspecoff_packed_optional_header64_t;

typedef struct jk_mspecoff_optional_header_t {
	/* standard fields */
	unsigned   magic;
	unsigned   major_linker_version;
	unsigned   minor_link_version;
	unsigned long size_of_code;
	unsigned long size_of_initialized_data;
	unsigned long size_of_uninitialized_data;
	unsigned long adddress_of_entry_point;
	jk_ulonglong_t  base_of_code;
	unsigned long base_of_data;
	/* nt fields */
	unsigned long image_base;
	unsigned long section_alignment; /* aka in_memory_section_alignment */
	unsigned long file_alignment; /* aka on_disk_section_alignment */
	unsigned  major_operating_system_version;
	unsigned  minor_operating_system_version;
	unsigned  major_image_version;
	unsigned  minor_image_version;
	unsigned  major_subsystem_version;
	unsigned  minor_subsystem_version;
	unsigned long win32_version;
	unsigned long size_of_image;
	unsigned long size_of_headers;
	unsigned long checksum;
	unsigned  subsystem;
	unsigned  dll_characteristics;        /* aka flags */
	jk_ulonglong_t size_of_stack_reserve;
	jk_ulonglong_t size_of_stack_commit;
	jk_ulonglong_t size_of_heap_reserve;
	jk_ulonglong_t size_of_heap_commit;
	unsigned long loader_flags;
	unsigned long number_of_rva_and_sizes;    /* aka number_of_data_directories */
	jk_array_t data_directory;          /* array of jk_mspecoff_data_directory_t */
} jk_mspecoff_optional_header_t;
	
/*
#    IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
#} IMAGE_OPTIONAL_HEADER, *PIMAGE_OPTIONAL_HEADER;
*/

void
jk_dump_environment_variablese(
    const jk_globals_t* globals
    );

struct jk_globals_t {
    const jk_fields_t* fields;
    const jk_types_t* types;
    jk_struct_t* java_packed_classfile_type_info;
    jk_struct_t* java_packed_classfile1_type_info;
    jk_struct_t* java_packed_classfile2_type_info;
    jk_memory_allocator_t* default_memory_allocator;
    char** environment_variables;
	int argc;
	char** argv;
	const jk_field_unpackers_t* field_unpackers;	
};

extern jk_struct_t jk_java_classfile_type_info;
extern jk_struct_t jk_java_classfile1_type_info;
extern jk_struct_t jk_java_classfile2_type_info;
extern const jk_memory_allocator_t jk_default_memory_allocator;

jk_memory_allocator_t *
jk_get_default_memory_allocator(
    void
    );

void
jk_init_platforms(
    void
    );

void
jk_init_constant_string(
    jk_constant_string_t* s,
    const char* t,
    size_t length
    );

long
jk_report_bad_parameter(
    const jk_constant_string_t* function,
    const char* expression
    );

typedef struct jk_unpacked_msdos_exe_header_t {
	unsigned char signature[2];
	unsigned long offset_to_pe;	
} jk_unpacked_msdos_exe_header_t;

typedef struct jk_packed_msdos_exe_header_t {
	unsigned char signature[2];
	unsigned char pad[58];
	unsigned char offset_to_pe[4];	
} jk_packed_msdos_exe_header_t;

void
jk_unpack_msdos_exe_header(
	/* out */ jk_unpacked_msdos_exe_header_t* unpacked,
	/* in */  const jk_packed_msdos_exe_header_t* packed
	);

typedef struct jk_packed_mspecoff_file_header_t {
	unsigned char machine[2];
	unsigned char number_of_sections[2];
	unsigned char time_date_stamp[4];
	unsigned char pointer_to_symbol_table[4];
	unsigned char number_of_symbols[4];
	unsigned char size_of_optional_header[2];
	unsigned char characteristics[2];
} jk_packed_mspecoff_file_header_t;

typedef struct jk_unpacked_mspecoff_file_header_t {
	unsigned      machine;
	unsigned      number_of_sections;
	unsigned long time_date_stamp;
	unsigned long pointer_to_symbol_table;
	unsigned long number_of_symbols;
	unsigned      size_of_optional_header;
	unsigned      characteristics;
} jk_unpacked_mspecoff_file_header_t;

struct jk_executable_file_format_t;
struct jk_executable_file_t;
struct jk_static_library_file_format_t;
struct jk_static_library_file_t;
struct jk_object_file_format_t;
struct jk_object_file_t;

void
jk_unpack_mspecoff_file_header(
	/* out */ jk_unpacked_mspecoff_file_header_t* unpacked,
	/* in */  const jk_packed_mspecoff_file_header_t* packed
	);

long
jk_errno(
	void
	);
	
long
jk_stdio_fopen(
	const char* filepath,
	const char* access,
	void**      file
	);

long
jk_stdio_close(
	void** file
	);


long
jk_get_stdio_filesize(
	void* file,
	jk_longlong_t* filesize
	);

	
typedef struct jk_position_independent_one_shot_heap_t {
	char* bytes;
	unsigned long size;
	unsigned long allocated_size;
} jk_position_independent_one_shot_heap_t;

void
jk_init_position_independent_one_shot_heap(
	jk_position_independent_one_shot_heap_t*
	);

void
jk_destroy_position_independent_one_shot_heap(
	jk_position_independent_one_shot_heap_t*
	);

void
jk_allocate_from_position_independent_one_shot_heap(
	jk_position_independent_one_shot_heap_t*,
	unsigned long* offset,
	/* optional */void** pointer
	);

void
jk_get_pointer_in_position_independent_one_shot_heap(
	jk_position_independent_one_shot_heap_t*,
	unsigned long offset,
	void** pointer
	);

char
jk_lowercase_ascii_char(
	char ch
	);

char
jk_uppercase_ascii_char(
	char ch
	);

void
jk_uppercase_string_in_place_a(
	jk_string_t* s
	);

void
jk_uppercase_null_terminated_string_in_place_a(
	char* s
	);

void
jk_lowercase_string_in_place_a(
	jk_string_t* s
	);

void
jk_lowercase_null_terminated_string_in_place_a(
	char* s
	);

int
jk_compare_strings_case_sensitive(
	const jk_string_t* a,
	const jk_string_t* b
	);

int
jk_compare_strings_case_insensitive(
	const jk_string_t* a,
	const jk_string_t* b
	);

int
jk_append_null_terminated_string_to_string(
	jk_string_t* a,
	const char* b
	);

int
jk_append_counted_string_to_string(
	jk_string_t* a,
	const char* b,
	size_t blength
	);

int
jk_append_string_to_string(
	jk_string_t* a,
	const jk_string_t* b
	);

int
jk_append_constant_string_to_string(
	jk_string_t* a,
	const jk_string_constant_t* b
	);

int
jk_strcmp(
	const char* a,
	const char* b
	);

int
jk_stricmp(
	const char* a,
	const char* b
	);

size_t
jk_find_index_of_character_in_counted_string_a(
	const char* s,
	size_t length,
	char ch
	);

size_t
jk_find_index_of_character_in_null_terminated_string_a(
	const char* s,
	char ch
	);

typedef struct jk_fixed_size_bit_set_t {
	size_t size_in_bits;
	size_t first_bit_set;
	size_t first_bit_clear;
	size_t last_bit_set;
	size_t last_bit_clear;
	size_t* bits;
} jk_fixed_size_bit_set_t;

long
jk_new_fixed_size_bit_set(
	jk_fixed_size_bit_set_t** bit_set,
	size_t size_in_bits
	);
	
void
jk_delete_fixed_size_bit_set(
	jk_fixed_size_bit_set_t** bit_set
	);

void
jk_set_bit_in_fixed_size_bit_set(
	jk_fixed_size_bit_set_t* bit_set,
	size_t bit
	);

void
jk_clear_bit_in_fixed_size_bit_set(
	jk_fixed_size_bit_set_t* bit_set,
	size_t bit
	);

long
jk_find_clear_bits_in_fixed_size_bit_set(
	jk_fixed_size_bit_set_t* bit_set,
	size_t number_of_bits,
	size_t* bit
	);

long
jk_find_set_bits_in_fixed_size_bit_set(
	jk_fixed_size_bit_set_t* bit_set,
	size_t number_of_bits,
	size_t* bit
	);


typedef struct jk_bits_in_byte_info_t {
	unsigned leftset : 4;
	unsigned leftclear : 4;
	unsigned rightset : 4;
	unsigned rightclear : 4;
	unsigned maxsetsize : 4;
	unsigned maxsetpos : 3;
	unsigned maxclearsize : 4;
	unsigned maxclearpos : 3;
} jk_bits_in_byte_info_t;

void
jk_compute_bits_in_byte_info_one_byte(
	unsigned b,
	jk_bits_in_byte_info_t* i
	);

void
jk_compute_bits_in_byte_info(
	jk_bits_in_byte_info_t* i
	);

void
jk_print_bits_in_byte_info(
	jk_bits_in_byte_info_t* i,
	void (*printf_callback)(void* context, const char* format, ...)
	);

typedef struct jk_character_set_a_t {
	unsigned long bits[8];
} jk_character_set_a_t;

void
jk_add_to_zeroed_character_set_from_counted_string_a(
	jk_character_set_a_t* set,
	const char* s,
	size_t length
	);

void
jk_make_character_set_from_counted_string_a(
	jk_character_set_a_t* set,
	const char* s,
	size_t length
	);

jk_bool_t
jk_is_character_in_character_set_a(
	jk_character_set_a_t* set,
	char ch
	);

size_t
jk_find_index_of_character_set_in_counted_string_a(
	const char* s,
	size_t length,
	jk_character_set_a_t* set
	);

size_t
jk_get_number_of_chars_from_set_at_start_of_string(
	jk_string_t* s,
	jk_character_set_a_t* set
	);

size_t
jk_get_number_of_chars_from_set_at_end_of_string(
	jk_string_t* s,
	jk_character_set_a_t* set
	);

size_t
jk_strspn(
	const char* s,
	const char* t
	);

size_t
jk_strrspn(
	const char* s,
	const char* t
	);

size_t
jk_strcspn(
	const char* s,
	const char* t
	);

size_t
jk_strrcspn(
	const char* s,
	const char* t
	);

unsigned
jk_ulong_log_base_2_rounded_up(
	unsigned long a
	);

void
jk_set_bit_in_uchar_array(
	unsigned char bits[],
	size_t bit
	);

void
jk_set_bit_in_ulong_array(
	unsigned long bits[],
	size_t bit
	);

void
jk_set_bit_in_sizet_array(
	size_t bits[],
	size_t bit
	);

void
jk_set_bit_in_uchar(
	unsigned char *bits,
	size_t bit
	);

void
jk_set_bit_in_ulong(
	unsigned long *bits,
	size_t bit
	);

void
jk_set_bit_in_sizet(
	size_t *bits,
	size_t bit
	);

unsigned long
jk_get_bit_in_ulong_not_right_justified(
	unsigned long bits,
	size_t bit
	);

unsigned
jk_get_bit_in_ulong_right_justified(
	unsigned long bits,
	size_t bit
	);

unsigned long
jk_get_bit_in_ulong_array_not_right_justified(
	unsigned long bits[],
	size_t bit
	);

unsigned
jk_get_bit_in_ulong_array_right_justified(
	unsigned long* bits,
	size_t bit
	);

size_t
jk_get_bit_in_sizet_not_right_justified(
	size_t bits,
	size_t bit
	);

size_t
jk_get_bit_in_sizet_right_justified(
	size_t bits,
	size_t bit
	);

size_t
jk_get_bit_in_sizet_array_not_right_justified(
	size_t bits[],
	size_t bit
	);

size_t
jk_get_bit_in_sizet_array_right_justified(
	size_t* bits,
	size_t bit
	);

typedef struct jk_character_bitmap_8_t jk_character_bitmap_8_t;
typedef struct jk_character_bitmap_11_t jk_character_bitmap_11_t;
typedef struct jk_character_bitmap_16_t jk_character_bitmap_16_t;
typedef struct jk_character_bitmap_21_t jk_character_bitmap_21_t;
typedef struct jk_character_bitmap_24_t jk_character_bitmap_24_t;
typedef struct jk_character_bitmap_32_t jk_character_bitmap_32_t;
typedef struct jk_character_bitmap_40_t jk_character_bitmap_40_t;
typedef struct jk_character_bitmap_48_t jk_character_bitmap_48_t;
typedef struct jk_character_bitmap_64_t jk_character_bitmap_64_t;
typedef struct jk_character_bitmap_128_t jk_character_bitmap_128_t;
typedef struct jk_character_bitmap_256_t jk_character_bitmap_256_t;
typedef struct jk_character_bitmap_5x7_t jk_character_bitmap_5x7_t;
typedef struct jk_character_bitmap_5x9_t jk_character_bitmap_5x9_t;
typedef struct jk_character_bitmap_5x9x8_t jk_character_bitmap_5x9x8_t;
typedef struct jk_character_bitmap_5x9x9_t jk_character_bitmap_5x9x9_t;
typedef struct jk_character_bitmap_5x8x9_t jk_character_bitmap_5x8x9_t;
typedef struct jk_character_bitmap_5x8x8_t jk_character_bitmap_5x8x8_t;
typedef struct jk_character_bitmap_5x7x9_t jk_character_bitmap_5x7x9_t;
typedef struct jk_character_bitmap_5x7x8_t jk_character_bitmap_5x7x8_t;
typedef struct jk_character_bitmap_5x7x24_t jk_character_bitmap_5x7x24_t;
typedef struct jk_character_bitmap_5x8x24_t jk_character_bitmap_5x8x24_t;

unsigned
jk_character_bitmap_8_get_bit(
	const jk_character_bitmap_8_t* bitmap,
	unsigned bit_index
	);

void
jk_character_bitmap_8_set_bit(
	jk_character_bitmap_8_t* bitmap,
	unsigned bit_index,
	unsigned bit_value
	);

unsigned
jk_character_bitmap_8_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_24_get_bit(
	const jk_character_bitmap_24_t* bitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_48_get_bit(
	const jk_character_bitmap_48_t* bitmap,
	unsigned bit_index
	);

void
jk_character_bitmap_48_set_bit(
	jk_character_bitmap_48_t* bitmap,
	unsigned bit_index,
	unsigned bit_value
	);

unsigned
jk_character_bitmap_48_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_5x9_get_bit(
	const jk_character_bitmap_5x9_t* bitmap,
	unsigned bit_index
	);

void
jk_character_bitmap_5x9_set_bit(
	jk_character_bitmap_5x9_t* bitmap,
	unsigned bit_index,
	unsigned bit_value
	);

unsigned
jk_character_bitmap_5x9_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	);

void
jk_character_bitmap_5x9_set_bit_v(
	void* vbitmap,
	unsigned bit_index,
	unsigned bit_value
	);

unsigned
jk_character_bitmap_64_get_bit(
	const jk_character_bitmap_64_t* bitmap,
	unsigned bit_index
	);

void
jk_character_bitmap_64_set_bit(
	jk_character_bitmap_64_t* bitmap,
	unsigned bit_index,
	unsigned bit_value
	);

unsigned
jk_character_bitmap_64_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_128_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_256_get_bit(
	const jk_character_bitmap_256_t* bitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_256_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_5x7x24_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_5x7x8_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_5x7x9_get_bit(
	const jk_character_bitmap_5x7x9_t *bitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_5x7x9_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	);

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
	);

void
jk_convert_character_bitmap_579_to_59array(
	const jk_character_bitmap_5x7x9_t* x,
	jk_character_bitmap_5x9_t* x59array
	);

void
jk_convert_character_bitmap_589_to_59array(
	const jk_character_bitmap_5x8x9_t* x,
	jk_character_bitmap_5x9_t* x59array
	);

void
jk_convert_character_bitmap_578_to_59array(
	const jk_character_bitmap_5x7x8_t* x,
	jk_character_bitmap_5x9_t* x59array
	);

void
jk_convert_character_bitmap_599_to_59array(
	const jk_character_bitmap_5x9x9_t* x,
	jk_character_bitmap_5x9_t* x59array
	);

void
jk_convert_character_bitmap_598_to_59array(
	const jk_character_bitmap_5x9x8_t* x,
	jk_character_bitmap_5x9_t* x59array
	);

unsigned
jk_character_bitmap_5x8x9_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	);
	
unsigned
jk_character_bitmap_5x9x9_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_5x9x8_get_bit_v(
	const void* vbitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_5x8x9_get_bit(
	const jk_character_bitmap_5x8x9_t* bitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_5x9x9_get_bit(
	const jk_character_bitmap_5x9x9_t* bitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_40_get_bit(
	const jk_character_bitmap_40_t* bitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_21_get_bit(
	const jk_character_bitmap_21_t* bitmap,
	unsigned bit_index
	);

unsigned
jk_character_bitmap_5x9x8_get_bit(
	const jk_character_bitmap_5x8x9_t* bitmap,
	unsigned bit_index
	);

struct jk_display_t;
typedef struct jk_display_t jk_display_t;

struct jk_font_t;
typedef struct jk_font_t jk_font_t;

struct jk_font_t {
	unsigned is_fixed_width : 1;
	unsigned is_fixed_height : 1;
	unsigned is_display : 1;
	unsigned is_print : 1;
	unsigned is_bitmap : 1;
	unsigned is_floating_point_curves : 1; /* postscript */
	unsigned is_fixed_point_curves : 1; /* truetype */
	unsigned is_postscript : 1;
	unsigned is_truetype : 1;
	unsigned is_seven_bit : 1;
	unsigned is_eight_bit : 1;
	unsigned is_sixteen_bit : 1;
	unsigned is_twenty_bit : 1;
	unsigned fixed_width;
	unsigned fixed_height;
	unsigned number_of_characters;
};

typedef struct jk_display_plot_bit_t {
	unsigned char mask;
	unsigned char set;
} jk_display_plot_bit_t;

struct jk_display_t {
	void* opaque_handle;
	unsigned char* base_address;	
	unsigned height;
	unsigned width;
	unsigned bytes_per_row;
	unsigned bits_per_pixel;
	unsigned bits_per_pixel_even_rounded_up;
	unsigned bits_per_pixel_even_rounded_down;
	unsigned bits_per_pixel_even_rounded_up_div_8;
	unsigned bits_per_pixel_even_rounded_down_div_8;
	jk_display_plot_bit_t plot_bit[8];
	unsigned bits_per_pixel_even_rounded_up_mod_8 : 3;
	unsigned bits_per_pixel_even_rounded_down_mod_8 : 3;
	unsigned is_macos : 1;
	unsigned is_macosx : 1;
	unsigned is_win32 : 1;
	unsigned is_network : 1;
	unsigned is_local : 1;
	unsigned is_windowed : 1;
	unsigned is_rectangular : 1;
	unsigned is_full_screen : 1;
	unsigned is_buffer_available : 1;
	struct {
		unsigned pixmap_version;
		unsigned packing_format;
		unsigned packing_size;
		unsigned pixel_type;		
		unsigned components_per_pixel;
		unsigned bits_per_component;
		unsigned long pixel_format;
	} macos;
	struct {
		unsigned samples_per_pixel;
		unsigned bits_per_sample;
		unsigned can_set_palette;
		void* palette;
	} macosx;
	void* cache;
	long (*release)(jk_display_t* display);
	long (*begin_access)(jk_display_t* display);
	long (*end_access)(jk_display_t* display);
};

typedef struct jk_deferred_display_t {
	unsigned height;
	unsigned width;
	unsigned invalid_rect[4];
	unsigned number_of_invalid_lines;
	unsigned char* invalid_lines;
	unsigned char* bits;
	jk_display_t* underlying_display;
} jk_deferred_display_t;

typedef struct jk_display_resolution {
	jk_display_t* display;
	void* cookie;
	unsigned height;
	unsigned width;
	unsigned bits_per_pixel;
} jk_display_resolution;

typedef struct jk_display_buffer {
	jk_display_t* display;
	void* cookie;
	unsigned char* base_address;	
	unsigned bytes_per_row;
} jk_display_buffer;

long jk_get_main_display(jk_display_t*);
long jk_release_display(jk_display_t*);

long jk_macosx_get_main_display(jk_display_t* d);
long jk_macos_get_main_display(jk_display_t* d);

#define jk_debug_strings 1

#if jk_debug_strings
#define jk_debug_string(x) x
#else
#define jk_debug_string(x) ""
#endif

#if jk_debug_strings
#define jk_function(x) static JK_CONST jk_constant_string_t function = jk_constant_string(JK_STRINGIZE(x))
#else
#define jk_function(x) static JK_CONST jk_constant_string_t function = jk_constant_string("")
#endif

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

void jk_sprintf(char*, const char*, ...);
void jk_printf(const char*, ...);
void jk_debug_printf(const char*, ...);

void
jk_printf_display(
	unsigned flags,
	const char* prefix,
	const jk_display_t* d
	);

long
jk_add_unsigned_char(
	unsigned char i,
	unsigned char j,
	unsigned char* k
	);

long
jk_add_unsigned_short(
	unsigned short i,
	unsigned short j,
	unsigned short* k
	);

long
jk_add_unsigned_int(
	unsigned i,
	unsigned j,
	unsigned* k
	);

long
jk_add_unsigned_long(
	unsigned long i,
	unsigned long j,
	unsigned long* k
	);

long
jk_add_signed_char(
	signed char i,
	signed char j,
	signed char* k
	);

long
jk_add_short(
	short i,
	short j,
	short* k
	);

long
jk_add_int(
	int i,
	int j,
	int* k
	);

long
jk_add_long(
	long i,
	long j,
	long* k
	);

long
jk_multiply_unsigned_char(
	unsigned char i,
	unsigned char j,
	unsigned char* k
	);

long
jk_multiply_unsigned_short(
	unsigned short i,
	unsigned short j,
	unsigned short* k
	);

long
jk_multiply_unsigned_int(
	unsigned i,
	unsigned j,
	unsigned* k
	);

long
jk_multiply_unsigned_long(
	unsigned long i,
	unsigned long j,
	unsigned long* k
	);

long
jk_add_sizet(
	size_t a,
	size_t b,
	size_t* c
	);

long
jk_multiply_sizet(
	size_t a,
	size_t b,
	size_t* c
	);

long
jk_multiply_signed_char(
	signed char i,
	signed char j,
	signed char* k
	);

long
jk_multiply_short(
	short i,
	short j,
	short* k
	);

long
jk_multiply_int(
	int i,
	int j,
	int* k
	);

long
jk_multiply_long(
	long i,
	long j,
	long* k
	);

/* all the convert functions should take pointers for their inputs
too in order to disallow silent conversion of the input */

long
jk_convert_unsigned_char_to_short(
	unsigned char from,
	short* to
	);

long
jk_convert_unsigned_short_to_short(
	unsigned short from,
	short* to
	);

long
jk_convert_unsigned_int_to_short(
	unsigned from,
	short* to
	);

long
jk_convert_unsigned_long_to_short(
	unsigned long from,
	short* to
	);

long
jk_convert_int_to_short(
	int from,
	short* to
	);

long
jk_convert_long_to_short(
	long from,
	short* to
	);

long
jk_convert_signed_char_to_unsigned_short(
	signed char from,
	unsigned short* to
	);

long
jk_convert_short_to_unsigned_short(
	short from,
	unsigned short* to
	);

long
jk_convert_int_to_unsigned_short(
	int from,
	unsigned short* to
	);

long
jk_convert_long_to_unsigned_short(
	long from,
	unsigned short* to
	);

long
jk_convert_unsigned_int_to_unsigned_short(
	unsigned from,
	unsigned short* to
	);

long
jk_convert_unsigned_long_to_unsigned_short(
	unsigned long from,
	unsigned short* to
	);

long
jk_convert_unsigned_int_to_int(
	unsigned from,
	int* to
	);

long
jk_convert_unsigned_long_to_int(
	unsigned long from,
	int* to
	);

long
jk_convert_long_to_int(
	long from,
	int* to
	);

long
jk_convert_signed_char_to_unsigned_int(
	signed char from,
	unsigned* to
	);

long
jk_convert_short_to_unsigned_int(
	short from,
	unsigned* to
	);

long
jk_convert_int_to_unsigned_int(
	int from,
	unsigned* to
	);

long
jk_convert_long_to_unsigned_int(
	long from,
	unsigned* to
	);

long
jk_convert_unsigned_long_to_unsigned_int(
	unsigned long from,
	unsigned* to
	);

long
jk_convert_unsigned_int_to_long(
	unsigned from,
	long* to
	);

long
jk_convert_unsigned_long_to_long(
	unsigned long from,
	long* to
	);

long
jk_convert_signed_char_to_unsigned_long(
	signed char from,
	unsigned long* to
	);

long
jk_convert_short_to_unsigned_long(
	short from,
	unsigned long* to
	);

long
jk_convert_int_to_unsigned_long(
	int from,
	unsigned long* to
	);

long
jk_convert_long_to_unsigned_long(
	long from,
	unsigned long* to
	);

void
jk_set_bit_in_char(
	unsigned char* bits,
	size_t bit
	);

void
jk_ulonglong_right_rotate(jk_ulonglong_t* a, const jk_ulonglong_t* b, unsigned shift);

void
jk_ulonglong_left_rotate(jk_ulonglong_t* a, const jk_ulonglong_t* b, unsigned shift);

long
jkp_common_multiply_unsigned(
	unsigned long i,
	unsigned long j,
	jk_ulonglong_t* x,
	unsigned long max
	);

long
jkp_common_multiply_signed(
	long i,
	long j,
	jk_longlong_t* x,
	long min,
	long max
	);

void
jk_printf_macos_display(
	unsigned flags,
	const char* prefix,
	const jk_display_t* d
	);

void
jk_printf_macosx_display(
	unsigned flags,
	const char* prefix,
	const jk_display_t* d
	);

size_t
jk_interlocked_compare_exchange_sizet(
	size_t* dest,
	size_t exch,
	size_t comp
	);

unsigned
jk_is_bit_in_fixed_size_bit_set(
	jk_fixed_size_bit_set_t* bit_set,
	size_t bit
	);

/*
review
  15 probably needs information as to what to do with the extra bit
  24 probably needs to be widened to be like 32 and also
    extra information as to what to do with the extra bits
*/
typedef struct jk_character_pixmap_5x9x1bpp_t  jk_character_pixmap_5x9x1bpp_t;
typedef struct jk_character_pixmap_5x9x2bpp_t  jk_character_pixmap_5x9x2bpp_t;
typedef struct jk_character_pixmap_5x9x4bpp_t  jk_character_pixmap_5x9x4bpp_t;
typedef struct jk_character_pixmap_5x9x8bpp_t  jk_character_pixmap_5x9x8bpp_t;
typedef struct jk_character_pixmap_5x9x15bpp_t jk_character_pixmap_5x9x15bpp_t;
typedef struct jk_character_pixmap_5x9x16bpp_t jk_character_pixmap_5x9x16bpp_t;
typedef struct jk_character_pixmap_5x9x24bpp_t jk_character_pixmap_5x9x24bpp_t;
typedef struct jk_character_pixmap_5x9x32bpp_t jk_character_pixmap_5x9x32bpp_t;

void
jk_convert_character_bitmap_5x9_to_character_pixmap_5x9x8bpp(
	const jk_character_bitmap_5x9_t* bits,
	jk_character_pixmap_5x9x8bpp_t* pix
	);

void
jk_convert_character_bitmap_5x9_to_character_pixmap_5x9x15bpp(
	const jk_character_bitmap_5x9_t* bits,
	jk_character_pixmap_5x9x15bpp_t* pix
	);

void
jk_convert_character_bitmap_5x9_to_character_pixmap_5x9x16bpp(
	const jk_character_bitmap_5x9_t* bits,
	jk_character_pixmap_5x9x16bpp_t* pix
	);

void
jk_convert_character_bitmap_5x9_to_character_pixmap_5x9x24bpp(
	const jk_character_bitmap_5x9_t* bits,
	jk_character_pixmap_5x9x24bpp_t* pix
	);

void
jk_convert_character_bitmap_5x9_to_character_pixmap_5x9x32bpp(
	const jk_character_bitmap_5x9_t* bits,
	jk_character_pixmap_5x9x32bpp_t* pix
	);

long
jk_display_plot_character(
	jk_display_t* display,
	jk_font_t* font,
	unsigned ch,
	unsigned x,
	unsigned y
	);

long
jk_display_get_size_in_characters(
	jk_display_t* display,
	jk_font_t* font,
	unsigned* number_of_characters_across,
	unsigned* number_of_characters_up_and_down
	);

long
jk_display_begin_access(
	jk_display_t* display
	);

long
jk_display_end_access(
	jk_display_t* display
	);

extern jk_font_t jk_placeholder_font;

void
jkp_display_plot_bit(
	jk_display_t* display,
	unsigned x,
	unsigned y,
	unsigned bit
	);

typedef struct jk_keyboard_state_t {
	unsigned shift : 1;
	unsigned option : 1;
	unsigned caps_lock : 1;
	unsigned number_lock : 1;
	unsigned scroll_lock : 1;
	unsigned control : 1;
	unsigned left_control : 1;
	unsigned right_control : 1;
	unsigned alt : 1;
	unsigned left_shift : 1;
	unsigned right_shift : 1;
	unsigned char numeric[256 / 8];
	unsigned char chars[256 / 8];
} jk_keyboard_state_t;

typedef struct jk_mouse_state_t {
	struct {
		unsigned primary : 1;
		unsigned secondary : 1;
		unsigned left : 1;
		unsigned middle : 1;
		unsigned right : 1;
		unsigned all;
	} buttons;
	struct {
		long x;
		long y;
		long z;
	} position;
} jk_mouse_state_t;

typedef struct jk_keyboard_features_t {
	unsigned number_of_keys;
	unsigned number_of_keyboards;
	unsigned has_function_keys : 1;
	unsigned has_numeric_keypad : 1;
	unsigned has_seperate_numeric_keypad : 1;
	unsigned has_volume_up : 1;
	unsigned has_volume_down : 1;
	unsigned has_volume_mute : 1;
	unsigned has_brightness_up : 1;
	unsigned has_brightness_down : 1;
	unsigned has_eject : 1;
	unsigned has_apple : 1;
	unsigned has_apple_clover_leaf : 1;
	unsigned has_return : 1;
	unsigned has_enter : 1;
	unsigned has_alt : 1;
	unsigned has_left_and_right_alt : 1;
	unsigned has_left_and_right_shift : 1;
	unsigned has_left_and_right_control : 1;
	unsigned is_qwerty : 1;
	unsigned is_dvorak : 1;
	unsigned has_dvorak : 1;
	unsigned is_usb : 1;
	unsigned is_ps2 : 1;
	unsigned is_serial : 1;
	unsigned is_adb : 1;
} jk_keyboard_features_t;

typedef struct jk_mouse_features_t {
	unsigned has_scroll_wheel : 1;
	unsigned number_of_buttons;
} jk_mouse_features_t;

typedef struct jk_keyboard_state_change_t {
	unsigned char key;
	unsigned valid : 1;
	unsigned down : 1;
	unsigned shift : 1;
	unsigned option : 1;
	unsigned caps_lock : 1;
	unsigned number_lock : 1;
	unsigned scroll_lock : 1;
	unsigned control : 1;
	unsigned alt : 1;
} jk_keyboard_state_change_t;

typedef struct jk_mouse_state_change_t {
	struct {
		unsigned valid : 1;
		unsigned primary : 1;
		unsigned secondary : 1;
		unsigned left : 1;
		unsigned middle : 1;
		unsigned right : 1;
		unsigned all;
	} buttons;
	struct {
		unsigned valid : 1;
		long x;
		long y;
		long z;
	} position;
	struct {
		unsigned valid : 1;
		long x;
		long y;
		long z;
	} delta;
} jk_mouse_state_change_t;

typedef struct jk_keyboard_or_mouse_state_change_t {
	jk_mouse_state_change_t mouse;
	jk_keyboard_state_change_t keyboard;
} jk_keyboard_or_mouse_state_change_t;

unsigned
jk_system_has_keyboard(
	);

unsigned
jk_system_has_local_keyboard(
	);

unsigned
jk_system_has_remote_keyboard(
	);

unsigned
jk_system_has_mouse(
	);

unsigned
jk_system_has_joystick(
	);

unsigned
jk_system_has_trackball(
	);

unsigned
jk_system_has_paddle(
	);

void
jk_wait_for_keyboard_state_change(
	);

void
jk_wait_for_mouse_state_change(
	);

void
jk_wait_for_keyboard_or_mouse_state_change(
	);

void
jk_get_mouse_state(
	jk_mouse_state_t*
	);

void
jk_get_keyboard_state(
	jk_keyboard_state_t*
	);

void
jk_dump_environment_variables(
    const jk_globals_t * globals
    );

unsigned
jk_appleiigs_init_memory_bank(
	unsigned i
	);

struct jk_stream_buffer_t;
typedef struct jk_stream_buffer_t jk_stream_buffer_t;

struct jk_stream_buffer_t {
	long
	(*flush_or_fill)(
		void* context,
		jk_byte_t* memory,
		size_t number_of_bytes,
		size_t* out_number_of_bytes
		);
	void* context;
	size_t position;
	size_t size_valid;
	size_t size_allocated;
	jk_byte_t* buffer;
};

long
jk_stream_buffer_read(
	jk_stream_buffer_t* buffer,
	unsigned char* bytes,
	size_t number_of_bytes,
	size_t* out_number_of_bytes
	);

long
jk_stream_buffer_write(
	jk_stream_buffer_t* buffer,
	const jk_byte_t* bytes,
	size_t number_of_bytes,
	size_t* out_number_of_bytes
	);

void
jk_trace(
	const char* s
	);

typedef struct jk_appleiigs_t jk_appleiigs_t, jk_iigs_t;
typedef struct jk_iigs_memory_details_t jk_iigs_memory_details_t;

typedef unsigned (*jk_iigs_read_memory_function_t)(jk_iigs_memory_details_t*);
typedef void (*jk_iigs_write_memory_function_t)(jk_iigs_memory_details_t*, unsigned char value);

struct jk_iigs_memory_details_t
{
	unsigned char* native;
	unsigned char* native_write;
	jk_iigs_read_memory_function_t read_function;
	jk_iigs_write_memory_function_t write_function;
	jk_iigs_t* iigs;
	unsigned long address;
};

void
jk_iigs_io_language_card_read_ram(
	jk_iigs_t* iigs
	);

unsigned
jk_iigs_direct_memory_read_function(
	jk_iigs_memory_details_t* d
	);

void
jk_iigs_direct_memory_write_function(
	jk_iigs_memory_details_t* d,
	unsigned char value
	);

unsigned
jk_iigs_special_memory_read(
	jk_iigs_memory_details_t* d
	);

void
jk_iigs_special_memory_write(
	jk_iigs_memory_details_t* d,
	unsigned char value
	);

unsigned
jk_iigs_invalid_memory_read(
	jk_iigs_memory_details_t* d
	);

void
jk_iigs_invalid_memory_write(
	jk_iigs_memory_details_t* d,
	unsigned char value
	);

void
jk_iigs_readonly_memory_write_function(
	jk_iigs_memory_details_t* d,
	unsigned char value
	);

void
jk_iigs_analyze_address(
	jk_iigs_t* iigs,
	unsigned long address,
	jk_iigs_memory_details_t* details
	);

void
jk_iigs_io_language_card_invalid_write(
	jk_iigs_t* iigs,
	unsigned long address
	);

typedef enum {
	jk_iigs_io_is_read,
	jk_iigs_io_is_write
} jk_iigs_io_is_read_or_write;

unsigned
jk_appleiigs_memory(
	jk_iigs_t* iigs,
	jk_iigs_io_is_read_or_write read_or_write,
	unsigned bank,
	unsigned address,
	unsigned value
	);

void
jk_iigs_memory_128k_use_main_01(
	jk_iigs_t* iigs
	);

void
jk_iigs_memory_128k_use_aux_01(
	jk_iigs_t* iigs
	);

void
jk_appleiigs_init_memory(
	jk_appleiigs_t* iigs
	);

void
jk_iigs_io_language_card_unknown_bit(
	jk_appleiigs_t* iigs,
	unsigned long address
	);

void
jk_appleiigs_io_write(
	unsigned adddress,
	unsigned value
	);

typedef struct jk_appleiigs_memory_handler_t {
	unsigned (*read)(unsigned bank_page, unsigned offset);
	void (*write)(unsigned bank_page, unsigned offset, unsigned value);
	unsigned char* (*get_pointer_to_start_of_page)(unsigned bank_page);
} jk_appleiigs_memory_handler_t;
	
jk_appleiigs_memory_handler_t*
jk_appleiigs_memory_handler_from_bank(
	jk_iigs_t* iigs,
	unsigned bank
	);

jk_appleiigs_memory_handler_t*
jk_appleiigs_memory_handler_from_address(
	jk_iigs_t* iigs,
	unsigned long address
	);

struct jk_appleiigs_t
{
	unsigned char code;
	unsigned pc_page;
	unsigned a;
	unsigned x;
	unsigned y;
	unsigned p;
	unsigned d;
	unsigned s;
	unsigned k;
	unsigned b;
	unsigned pc;
	unsigned long kpc;
	unsigned char* kpc_pointer;
	unsigned char* b_cache;
	unsigned io_previous;
	
	unsigned char*** memory_ppp;
	
	unsigned long ghost;
	unsigned char* rom;
	unsigned char* memory;
	unsigned linearize_superhires : 1;	
	unsigned languagecard_read_ram : 1;
	unsigned languagecard_read_rom : 1;
	unsigned languagecard_write_ram : 1;
	unsigned languagecard_ram_bank : 1;
	unsigned io_language_card_bank : 1;
	unsigned io_language_card_read_ram : 1;
	unsigned memory_128k_aux_01 : 1;
};

typedef struct MacResourceForkHeader
{
#if defined(__cplusplus)
	MacResourceForkHeader() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned long OffsetToResorceData;
	unsigned long OffsetToResourceMap;
	unsigned long LengthOfResourceData;
	unsigned long LengthOfRresourceMap;
} MacResourceForkHeader;

typedef struct MacResourceForkHeader_Packed
{
#if defined(__cplusplus)
	MacResourceForkHeader_Packed() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned char OffsetToResorceData[4];
	unsigned char OffsetToResourceMap[4];
	unsigned char LengthOfResourceData[4];
	unsigned char LengthOfRresourceMap[4];
} MacResourceForkHeader_Packed;

void
UnpackMacResourceForkHeader(
	const MacResourceForkHeader_Packed*,
	MacResourceForkHeader*
	);

typedef struct MacPEFContainerHeader
{
#if defined(__cplusplus)
	MacPEFContainerHeader() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned char Tag1[4];
	unsigned char Tag2[4];
	unsigned char Architecture[4];
	unsigned long FormatVersion;
	unsigned long DateTimeStamp;
	unsigned long OldDefVersion;
	unsigned long OldImpVersion;
	unsigned long CurrentVersion;
	unsigned short SectionCount;
	unsigned short InstSectionCount;
	unsigned long ReservedA;
} MacPEFContainerHeader;

/* 40 bytes */
typedef struct MacPEFContainerHeader_Packed
{
#if defined(__cplusplus)
	MacPEFContainerHeader_Packed() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned char Tag1[4];
	unsigned char Tag2[4];
	unsigned char Architecture[4];
	unsigned char FormatVersion[4];
	unsigned char DateTimeStamp[4];
	unsigned char OldDefVersion[4];
	unsigned char OldImpVersion[4];
	unsigned char CurrentVersion[4];
	unsigned char SectionCount[2];
	unsigned char InstSectionCount[2];
	unsigned char ReservedA[4];
} MacPEFContainerHeader_Packed;

void
UnpackMacPEFContainerHeader(
	const MacPEFContainerHeader_Packed*,
	MacPEFContainerHeader*
	);
	
typedef struct MacPEFSectionHeader
{
#if defined(__cplusplus)
	MacPEFSectionHeader() { memset(this, 0, sizeof(*this)); }
#endif
	long NameOffset;
	unsigned long DefaultAddress;
	unsigned long TotalSize;
	unsigned long UnpackedSize;
	unsigned long PackedSize;
	unsigned long ContainerOffset;
	unsigned char SectionKind;
	unsigned char ShareKind;
	unsigned char Alignment;
	unsigned char ReservedA;
} MacPEFSectionHeader;

/* 28 bytes */
typedef struct MacPEFSectionHeader_Packed
{
#if defined(__cplusplus)
	MacPEFSectionHeader_Packed() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned char NameOffset[4];
	unsigned char DefaultAddress[4];
	unsigned char TotalSize[4];
	unsigned char UnpackedSize[4];
	unsigned char PackedSize[4];
	unsigned char ContainerOffset[4];
	unsigned char SectionKind;
	unsigned char ShareKind;
	unsigned char Alignment;
	unsigned char ReservedA;
} MacPEFSectionHeader_Packed;

void
UnpackMacPEFSectionHeader(
	const MacPEFSectionHeader_Packed*,
	MacPEFSectionHeader*
	);

typedef struct MacPEFLoaderInfoHeader
{
#if defined(__cplusplus)
	MacPEFLoaderInfoHeader() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned long MainSection;
	unsigned long MainOffset;
	unsigned long InitSection;
	unsigned long InitOffset;
	unsigned long TermSection;
	unsigned long TermOffset;
	unsigned long ImportedLibraryCount;
	unsigned long TotalmportedSymbolCount;
	unsigned long RelocSectionCount;
	unsigned long RelocInstrSectionCount;
	unsigned long LoaderStringOffset;
	unsigned long ExportHashOffset;
	unsigned long ExportHashTablePower;
	unsigned long ExportedSymbolCount;
} MacPEFLoaderInfoHeader;

/* 56 bytes */
typedef struct MacPEFLoaderInfoHeader_Packed
{
#if defined(__cplusplus)
	MacPEFLoaderInfoHeader_Packed() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned char MainSection[4];
	unsigned char MainOffset[4];
	unsigned char InitSection[4];
	unsigned char InitOffset[4];
	unsigned char TermSection[4];
	unsigned char TermOffset[4];
	unsigned char ImportedLibraryCount[4];
	unsigned char TotalmportedSymbolCount[4];
	unsigned char RelocSectionCount[4];
	unsigned char RelocInstrSectionCount[4];
	unsigned char LoaderStringOffset[4];
	unsigned char ExportHashOffset[4];
	unsigned char ExportHashTablePower[4];
	unsigned char ExportedSymbolCount[4];
} MacPEFLoaderInfoHeader_Packed;

typedef struct MacPEFImportedLibrary
{
#if defined(__cplusplus)
	MacPEFImportedLibrary() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned long NameOffset;
	unsigned long OldImpVersion;
	unsigned long CurrentVersion;
	unsigned long ImportedSymbolCount;
	unsigned long FirstImportedSymbol;
	unsigned char Options;
	unsigned char ReservedA;
	unsigned short ReservedB;
} MacPEFImportedLibrary;

/* 24 bytes */
typedef struct MacPEFImportedLibrary_Packed
{
#if defined(__cplusplus)
	MacPEFImportedLibrary_Packed() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned char NameOffset[4];
	unsigned char OldImpVersion[4];
	unsigned char CurrentVersion[4];
	unsigned char ImportedSymbolCount[4];
	unsigned char FirstImportedSymbol[4];
	unsigned char Options;
	unsigned char ReservedA;
	unsigned char ReservedB[2];
} MacPEFImportedLibrary_Packed;

/* This is an in-memory only data structure. */
struct MacPEFRelocationState
{
#if defined(__cplusplus)
	MacPEFRelocationState() { memset(this, 0, sizeof(*this)); }
#endif
	void* RelocAddress;
	size_t ImportIndex;
	void* SectionC;
	void* SectionD;
};

struct MacPEFRelocationHeader
{
#if defined(__cplusplus)
	MacPEFRelocationHeader() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned short SectionIndex;
	unsigned short ReservedA;
	unsigned long RelocCount;
	unsigned long FirstRelocOffset;
};

/* 12 bytes */
struct MacPEFRelocationHeader_Packed
{
#if defined(__cplusplus)
	MacPEFRelocationHeader_Packed() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned char SectionIndex[2];
	unsigned char ReservedA[2];
	unsigned char RelocCount[4];
	unsigned char FirstRelocOffset[4];
};

struct MacPEFExportedSymbol
{
#if defined(__cplusplus)
	MacPEFExportedSymbol() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned long ClassAndName;
	unsigned long SymbolValue;
	unsigned short SectionIndex;
};

typedef struct MacPEFExportedSymbol_Packed
{
#if defined(__cplusplus)
	MacPEFExportedSymbol_Packed() { memset(this, 0, sizeof(*this)); }
#endif
	unsigned char ClassAndName[4];
	unsigned char SymbolValue[4];
	unsigned char SectionIndex[2];
} MacPEFExportedSymbol_Packed;

typedef struct MacPEFSection
{
	 MacPEFSectionHeader Header;
	 /* ... */
} MacPEFSection;

#if defined(__cplusplus)
typedef struct MacPEFContainer
{
	MacPEFContainer()
	{
		SectionNameTableOffset = 0;
		SectionNameTablePointer = 0;
		NumberOfLoaderSections = 0;
	}

	std::vector<unsigned char> FileContents;
	MacPEFContainerHeader Header;
	std::vector<MacPEFSection> Sections;
	size_t SectionNameTableOffset;
	char* SectionNameTablePointer;
	size_t NumberOfLoaderSections;
	std::vector<size_t> LoaderSections;
	std::vector<MacPEFLoaderInfoHeader> LoaderHeaders;
} MacPEFContainer;
#endif

#define MAC_PEF_SECTION_KIND_CODE (0)
#define MAC_PEF_SECTION_KIND_UNPACKED_DATA (1)
#define MAC_PEF_SECTION_KIND_PATTERN_INITIALIZED_DATA (2)
#define MAC_PEF_SECTION_KIND_CONSTANT (3)
#define MAC_PEF_SECTION_KIND_LOADER (4)
#define MAC_PEF_SECTION_KIND_DEBUG (5)
#define MAC_PEF_SECTION_KIND_EXECUTABLE_DATA (6)
#define MAC_PEF_SECTION_KIND_EXECEPTION_DATA (7)
#define MAC_PEF_SECTION_KIND_TRACEBACK (8)

const wchar_t*
MacPEFSectionKindString(
	unsigned long x
	);

ULONG64
GetFileSize(
	HANDLE FileHandle
	);

void
ReadFileAtOffset(
	HANDLE FileHandle,
	size_t offset,
	size_t count,
	PVOID buffer
	);

unsigned long
Unpack(
	const unsigned char* Bytes,
	unsigned Size,
	unsigned BigEndian,
	unsigned Signed
	);

unsigned short
UnpackUBE2( /* unsigned big endian 2 bytes */
	const unsigned char* Bytes
	);

unsigned long
UnpackUBE4( /* unsigned big endian 4 bytes */
	const unsigned char* Bytes
	);

unsigned long
GetUBE4( /* unsigned big endian 4 bytes */
	unsigned char const** ppBytes
	);

unsigned long
GetUBE2( /* unsigned big endian 4 bytes */
	unsigned char const** ppBytes
	);

void
PrintError(
	const wchar_t* Format,
	...
	);

JK_EXTERN_C_END
