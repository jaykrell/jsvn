/*
Written Jay Krell
*/
#if defined(__cplusplus) && (defined(__SC__) || defined(__MRC__))
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

#include <stddef.h>

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
#else
#define JK_ORCAC_SEGMENT /* nothing */
#endif

JK_EXTERN_C_BEGIN

extern const long jk_out_of_memory_error;

typedef unsigned char jk_boolean_t;
typedef jk_boolean_t jk_bool_t;
typedef jk_boolean_t bool_t;
#define jk_false ((jk_boolean_t)0)
#define jk_true  ((jk_boolean_t)1)

typedef unsigned char  uchar_t;
typedef unsigned int   uint_t;
typedef unsigned short ushort_t;
typedef unsigned long  ulong_t;
typedef unsigned short jchar_t;

typedef  char  char_t;
typedef short short_t;
typedef   int   int_t;
typedef  long  long_t;
/* These conflict with C99 math.h or somesuch (CodeWarrior 6).
typedef float float_t;
typedef double double_t;
*/

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
    ulong_t low;
} jk_longlong_t;

typedef struct jk_ulonglong_t {
    ulong_t high;
    ulong_t low;
} jk_ulonglong_t;

/*
typedef struct jk_packed_longlong_t {
    uchar_t bytes[8];
} jk_packed_longlong_t;

typedef struct jk_packed_ulonglong_t {
    uchar_t bytes[8];
} jk_packed_ulonglong_t;
*/

typedef struct jk_memory_allocator_functions_t jk_memory_allocator_functions_t;
typedef struct jk_memory_allocator_t jk_memory_allocator_t;
typedef struct jk_type_t jk_type_t;
typedef struct jk_globals_t jk_globals_t;

void
jk_reverse_memory_byte_count(
    void * void_p,
    size_t count
    );

void
jk_reverse_memory_range_inclusive(
    void * void_start,
    void * void_end
    );

void
jk_reverse_memory_range_exclusive(
    void * void_start,
    void * void_end
    );

void
jk_move_memory(
    void * to,
    const void * from,
    size_t count
    );

void
jk_copy_memory(
    void * to,
    const void * from,
    size_t count
    );

void
jk_copy_memory_unsigned_char(
    unsigned char * to,
    const uchar_t * from,
    size_t count
    );

void
jk_copy_memory_reverse(
    uchar_t * to,
    const uchar_t * from,
    size_t count
    );

void
jk_zero_memory(
    void * p,
    size_t n
    );

/* strongly typed, narrow, specific interface */
size_t jk_get_dump_length_int(int data);
size_t jk_get_dump_length_unsigned_int(uint_t data);
size_t jk_get_dump_length_long(long data);
size_t jk_get_dump_length_unsigned_long(ulong_t data);

/* strongly typed, narrow, specific interface */
void jk_dump_int(size_t buffer_size, char * buffer, int data);
void jk_dump_unsigned_int(size_t buffer_size, char * buffer, uint_t data);
void jk_dump_long(size_t buffer_size, char * buffer, long data);
void jk_dump_unsigned_long(size_t buffer_size, char * buffer, ulong_t data);

/* jk_type_t conformant wrappers */
long jk_type_get_dump_length_int(const jk_type_t *, const void * data, size_t * length);
long jk_type_get_dump_length_unsigned_int(const jk_type_t *, const void * data, size_t * length);
long jk_type_get_dump_length_long(const jk_type_t *, const void * data, size_t * length);
long jk_type_get_dump_length_unsigned_long(const jk_type_t *, const void * data, size_t * length);

/* jk_type_t conformant wrappers */
long jk_type_dump_int(const jk_type_t *, size_t buffer_size, char * buffer, const void * data);
long jk_type_dump_unsigned_int(const jk_type_t *, size_t buffer_size, char * buffer, const void * data);
long jk_type_dump_long(const jk_type_t *, size_t buffer_size, char * buffer, const void * data);
long jk_type_dump_unsigned_long(const jk_type_t *, size_t buffer_size, char * buffer, const void * data);

typedef long (*jk_type_get_dump_length_t)(const jk_type_t *, const void * data, size_t * length);
typedef long (*jk_type_dump_t)(const jk_type_t *, size_t buffer_size, char * buffer, const void * data);

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
    const char * name;
    size_t       value; /* TBD use ulonglong_t for cross types not representable in host size_t */
} jk_enumeration_member_t;

typedef struct jk_structure_member_t {
    const char * name;
    size_t       offset;
    size_t       aligned_size;
    struct jk_type_t * type;
} jk_structure_member_t;

/* not type descriptor */
typedef struct jk_array_t {
    const struct jk_type_t * element_type;
    struct jk_memory_allocator_t * allocator;
    void * elements;
    size_t size_allocated;
    size_t size_requested;
} jk_array_t;

typedef struct jk_string_constant_t {
    const char * chars; /* TBD host vs. target character sets */
    size_t length;
} jk_string_constant_t, jk_constant_string_t;

typedef struct jk_wide_string_constant_t {
    const wchar_t * chars; /* TBD host vs. target character sets and wide char representation */
    size_t length;
} jk_wide_string_constant_t;

#define jk_constant_string(s) (s), sizeof(s) - sizeof((s)[0])

struct jk_type_t {
    size_t size; /* TBD ulonglong_t for cross types? */
    long (*construct_n)(const jk_type_t *, void * , size_t n);
    long (*destroy_n)(const jk_type_t *, void *, size_t n);
    long (*copy_n)(const jk_type_t *, void * , const void *, size_t n);
    long (*move_n)(const jk_type_t *, void * , void*, size_t n);
    uint_t is_signed;
    jk_type_get_dump_length_t get_dump_length;
	jk_type_dump_t dump;
	jk_constant_string_t name;
    size_t aligned_size; /* TBD ulonglong_t for cross types? */
	enum et_t et;
	unsigned cv_const : 1;
	unsigned cv_volatile : 1;
	union {
	    struct {
	        struct jk_type_t * integer_rep;
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
	        struct jk_type_t * integer_rep;
	    } floatingpoint;
	    struct {
	        jk_array_t members;
	        struct jk_type_t * integer_rep; /* usually NULL but may be non NULL for small structs */
	    } structure;
	    struct {
	        enum etlang_t etlang;
	        enum etlink_t etlink;
	        const char * name;
	        jk_array_t parameters;
	        struct {
	            uchar_t * object; /* processor? */
	            char * source;
	        } code;
	    } function;
	} u;
};

#define jk_type_get_size_macro(t,s) (((*s) = (t)->size), 0)
long
jk_type_get_size_function(
    jk_type_t * type,
    size_t * size
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
jk_type_copy_n_copy_memory(const jk_type_t * type, void * to, const void * from, size_t n);

long
    jk_type_move_n_copy_memory(const jk_type_t * type, void * to, void * from, size_t n);

long
jk_type_move_n_copy_memory_and_zero_memory(const jk_type_t * type, void * to, void * from, size_t n);

long
jk_type_construct_n_zero_memory(const jk_type_t * type, void * p, size_t n);

long
jk_type_construct_n_do_nothing(const jk_type_t * type, void * p, size_t n);

long
jk_type_destroy_n_do_nothing(const jk_type_t * type, void * p, size_t n);

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

typedef struct jk_field_t {
    const char * name;
    size_t offset_to_type; /* offset within jk_types_t (FUTURE: types defined at runtime) */
    size_t unpacked_size;
    size_t packed_size;
    size_t unpacked_offset;
    size_t packed_offset;
	size_t unpacker_offset; /* offset within jk_field_unpackers_t */
} jk_field_t;

typedef
long
(*jk_field_unpacker_t)(
	const jk_field_t * field,
	const void * from,
	void * to
	);

long
jk_unpack_field_packed_little_endian_uint64_to_jk_ulonglong(
	const jk_field_t * field,
	const void * from,
	void /*jk_ulonglont_t*/ * to
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

typedef struct jk_struct_t {
    uchar_t endian;
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
    const jk_type_t * t_void;
    const jk_type_t * t_char;
    const jk_type_t * t_schar;
    const jk_type_t * t_uchar;
    const jk_type_t * t_short;
    const jk_type_t * t_ushort;
    const jk_type_t * t_int;
    const jk_type_t * t_uint;
    const jk_type_t * t_long;
    const jk_type_t * t_ulong;
    struct jk_hashtable_t * hashtable;
} jk_types_t;

/* strawman abstraction for fetching dynamically defined types */
jk_type_t *
jk_get_type_by_name(
    const char * s
    );
    
long
jk_array_init(
    jk_array_t * array,
    const jk_type_t * element_type,
    jk_memory_allocator_t * allocator
    );

long
jk_array_get_element_type(
    jk_array_t * array,
    const jk_type_t ** element_type
    );

long
jk_array_free(
    jk_array_t * array
    );

long
jk_array_get_base(
    jk_array_t * array,
    void **
    );

long
jk_array_get_pointer_to_element_at(
    jk_array_t * array,
    size_t n,
    void**
    );

long
jk_array_get_size( /* std::vector::size() */
    jk_array_t * array,
    size_t*
    );

long
jk_array_set_size( /* std::vector::resize() */
    jk_array_t * array,
    size_t new_size
    );

long
jk_array_get_allocated_size( /* std::vector::capacity() */
    jk_array_t * array,
    size_t*
    );

long
jk_array_ensure_allocated_size( /* std::vector::reserve() */
    jk_array_t * array,
    size_t new_size
    );
 
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
    void **
    );

long
jk_array_set_element_at_index(
    jk_array_t * array,
    size_t n,
    void * element
    );
    
typedef struct jk_array_iterator_t {
    jk_array_t * array;
    size_t index;
} jk_array_iterator_t;

void
jk_assert_iterator_assert_is_valid(
    const jk_array_iterator_t * iterator
    );

long
jk_array_begin(
    jk_array_t * array,
    jk_array_iterator_t * iterator
    );

long
jk_array_end(
    jk_array_t * array,
    jk_array_iterator_t * iterator
    );

long
jk_array_iterator_increment(
    jk_array_iterator_t * iterator
    );

long
jk_array_iterator_decrement(
    jk_array_iterator_t * iterator
    );

long
jk_array_iterator_add_integer(
    jk_array_iterator_t * iterator,
    size_t n
    );

long
jk_array_iterator_subtract_integer(
    jk_array_iterator_t * iterator,
    size_t n
    );

long
jk_array_iterator_subtract_iterator(
    jk_array_iterator_t * iterator,
    const jk_array_iterator_t * iterator_to_subtract
    );
    
long
jk_array_iterator_dereference(
    jk_array_iterator_t * iterator,
    void **
    );

long
jk_array_iterator_is_equal(
    const jk_array_iterator_t * iterator1,
    const jk_array_iterator_t * iterator2,
    jk_boolean_t *
    );

typedef struct jk_hashtable_element_t {
    size_t hash;
    const void * key;
    void * value;
} jk_hashtable_element_t;

typedef struct jk_hashtable_bucket_t {
    jk_array_t elements;
} jk_hashtable_bucket_t;

typedef struct jk_hashtable_static_context_t {
    jk_memory_allocator_t * memory_allocator;
    size_t (*key_hash_function)(const void *);
    bool_t (*key_equal_function)(const void *, const void *);
    const jk_type_t * key_type;
    const jk_type_t * value_type;
} jk_hashtable_static_context_t;

typedef struct jk_hashtable_search_result_t {
    const void * key;
    void * value;
    bool_t found;
    size_t opaque[2];
} jk_hashtable_search_result_t;

typedef struct jk_hashtable_iterator_t {
    struct jk_hashtable_t * hashtable;
    const void * key;
    void * value;
    bool_t done;
    size_t opaque[2];
} jk_hashtable_iterator_t;

typedef struct jk_hashtable_t {
    jk_hashtable_static_context_t * context;
    jk_array_t buckets;
    size_t number_of_elements;
    size_t number_of_outstanding_iterators;
} jk_hashtable_t;
    
long
jk_hashtable_init(
    jk_hashtable_t * hashtable,
    jk_hashtable_static_context_t * context
    );

long
jk_hashtable_free(
    jk_hashtable_t * hashtable
    );
    
long
jk_hashtable_get_memory_allocator(
    jk_hashtable_t * hashtable,
    jk_memory_allocator_t ** memory_allocator
    );

long
jk_hashtable_get_size(
    jk_hashtable_t * hashtable,
    size_t * size
    );
    
long
jk_hashtable_add_element(
    jk_hashtable_t * hashtable,
    const void * key,
    void * value
    );
    
long
jk_hashtable_remove_key(
    jk_hashtable_t * hashtable,
    const void * key
    );

long
jk_hashtable_remove_all(
    jk_hashtable_t * hashtable
    );

long
jk_hashtable_search(
    jk_hashtable_t * hashtable,
    const void * key,
    jk_hashtable_search_result_t * search_result
    );

long
jk_hashtable_remove_search_result(
    jk_hashtable_t * hashtable,
    jk_hashtable_search_result_t * search_result
    );
    
long
jk_hashtable_iterator_init(
    jk_hashtable_t * hashtable,
    jk_hashtable_iterator_t * iterator,
    bool_t * done
    );

long
jk_hashtable_iterator_remove_and_next(
    jk_hashtable_iterator_t * iterator,
    bool_t * done
    );
    
long
jk_hashtable_iterator_next(
    jk_hashtable_iterator_t * iterator,
    bool_t * done
    );

long
jk_hashtable_iterator_free(
    jk_hashtable_iterator_t * iterator
    );
    
typedef struct jk_java_unresolved_constant_interface_member_ref_no_tag_t {
	uint_t class_index;
	uint_t name_and_type_index;
} jk_java_unresolved_constant_member_ref_no_tag_t;

typedef struct jk_java_unresolved_constant_string_ref_no_tag_t {
	uint_t string_index;
} jk_java_unresolved_constant_string_ref_no_tag_t;

typedef struct jk_java_unresolved_constant_class_ref_no_tag_t {
	uint_t class_index;
} jk_java_unresolved_constant_class_ref_no_tag_t;

typedef struct jk_java_unresolved_constant_name_and_type_no_tag_t {
	uint_t name_index;
	uint_t type_index;
} jk_java_unresolved_constant_name_and_type_no_tag_t;

/*
typedef struct jk_java_packed_unresolved_constant_interface_member_ref_no_tag_t {
	uchar_t class_index[2];
	uchar_t name_and_type_index[2];
} jk_java_packed_unresolved_constant_member_ref_no_tag_t;

typedef struct jk_java_packed_unresolved_constant_string_ref_no_tag_t {
	uchar_t string_index[2];
} jk_java_packed_unresolved_constant_string_ref_no_tag_t;

typedef struct jk_java_packed_unresolved_constant_class_ref_no_tag_t {
	uchar_t class_index[2];
} jk_java_packed_unresolved_constant_class_ref_no_tag_t;
*/

typedef union jk_java_half_word_t {
    ushort_t  us;
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
    void *    VoidPointer;
    char *    CharPointer;
    jchar_t * JcharPointer;
    ulong_t   UnsignedLong;
    ushort_t  UnsignedShorts[2];
	jk_java_half_word_t HalfWords[2];
    float     Float;
	uchar_t   Bytes[4];
	jk_java_unresolved_constant_no_tag_t unresolved_constant;
} jk_java_word_t;

typedef jk_longlong_t jk_java_long_t;

typedef union jk_java_any_t {
    void *          void_pointer;
    void *          voidpointer;
    void *    		VoidPointer;
    char *          char_pointer;
    char *          charpointer;
    char *    		CharPointer;
    jchar_t *       jchar_pointer;
    jchar_t *       jcharpointer;
    jchar_t * 		JcharPointer;
    ulong_t         unsigned_long;
    ulong_t         unsignedlong;
    ulong_t   		UnsignedLong;
    ushort_t        unsigned_shorts[2];
    ushort_t        unsignedshorts[2];
    ushort_t	  	UnsignedShorts[2];
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
    ulong_t   		UnsignedLongs[2];
     long_t   		Longs[2];
	uchar_t      	Bytes[8];
} jk_java_double_word_t;
*/

typedef struct jk_java_constant_memberref_t {
    uint_t class_index;
    uint_t name_and_type_index;
} jk_java_constant_memberref_t;

typedef jk_java_constant_memberref_t jk_java_constant_fieldref_t;
typedef jk_java_constant_memberref_t jk_java_constant_methodref_t;
typedef jk_java_constant_memberref_t jk_java_constant_interfacemethodref_t;

typedef struct jk_java_constant_string_t {
    uint_t string_index;
} jk_java_constant_string_t;

typedef struct jk_java_constant_integer_t {
    ulong_t number;
} jk_java_constant_integer_t;

typedef struct jk_java_constant_float_t {
    float number;
} jk_java_constant_float_t;

typedef union jk_java_constant_untagged_union_t {
    jk_java_constant_memberref_t memberref;
} jk_java_constant_untagged_union_t;

#define jk_java_magic "\xca\xfe\xba\xbe"

typedef struct jk_file_buffer_t {
    uchar_t * buffer;
    size_t buffer_size;
    size_t bytes_in_buffer;
    size_t position;
    size_t read_ahead;
    unsigned keep_all_bytes : 1;
} jk_file_buffer_t;

long
jk_init_file_buffer(
	jk_file_buffer_t * file_buffer
	);

long
jk_free_file_buffer(
	jk_file_buffer_t * file_buffer
	);

typedef struct jk_file_t {
    void * stdio_file;
    const char * file_path;
    const char * openmode;
    jk_file_buffer_t buffer;
} jk_file_t;

long
jk_init_file(
	jk_file_t * file
	);

long
jk_free_file(
	jk_file_t * file
	);

long
jk_file_open_for_read(
    const jk_globals_t * globals,
    jk_file_t * file,
    const char * file_path
    );
    
long
jk_file_read_copy(
    jk_file_t * file,
    void * buffer,
    size_t bytes_to_read,
    size_t * bytes_read /* optional */
    );

long
jk_file_read_get_buffer(
    jk_file_t * file,
    void ** buffer,
    size_t bytes_to_read,
    size_t * bytes_read /* optional */
    );

long
jk_file_read_ahead(
    jk_file_t * b,
    size_t bytes_to_read
    );
    
long
jk_file_close(
    jk_file_t * f
    );

typedef struct jk_java_constant_pool_t {
    uint_t      count;
    uchar_t *   tags;
    jk_java_any_t * any;
} jk_java_constant_pool_t;

typedef struct jk_java_classfile_t {
    jk_file_t   file;
    uchar_t     magic[4];
    uint_t      minor_version;
    uint_t      major_version;
    jk_java_constant_pool_t constant_pool;
    uint_t      access_flags;
    uint_t      this_class;
    uint_t      super_class;
    uint_t      interfaces_count;
    jk_array_t  interfaces;
    uint_t      fields_count;
    uint_t      methods_count;
    uint_t      attributes_count;
} jk_java_classfile_t;

typedef struct jk_java_packed_classfile1_t {
    uchar_t    magic[4];
    uchar_t    minor_version[2];
    uchar_t    major_version[2];
	struct {
	    uchar_t    count[2];
	} constant_pool;
    /* constant_pool */
} jk_java_packed_classfile1_t;

typedef struct jk_java_packed_classfile2_t {
    uchar_t    access_flags[2];
    uchar_t    this_class[2];
    uchar_t    super_class[2];
    uchar_t    interfaces_count[2];
    /* uchar_t interfaces[interfaces_count][[2] */
} jk_java_packed_classfile2_t;

typedef struct jk_java_packed_classfile3_t {
    uchar_t    magic[4];
    uchar_t    minor_version[2];
    uchar_t    major_version[2];
	struct {
	    uchar_t    count[2];
	} constant_pool;
    /* constant_pool */
    uchar_t    access_flags[2];
    uchar_t    this_class[2];
    uchar_t    super_class[2];
    uchar_t    interfaces_count[2];
    /* uchar_t interfaces[interfaces_count][[2]; */
    uchar_t fields_count[2];
    /* jk_java_packed_field_info_t fields[fields_count]; */
    uchar_t methods_count[2];
    /* jk_java_packed_method_info_t methods[method_count]; */
    uchar_t attributes_count[2];
    /* jk_java_packed_attribute_info_t attributes[attribute_count]; */
} jk_java_packed_classfile3_t;

#define jk_java_constant_class_tag          7
#define jk_java_constant_fieldref_tag       9
#define jk_java_constant_methodref_tag      10
#define jk_java_constant_interfacemethodref_tag 11
#define jk_java_constant_string_tag         8
#define jk_java_constant_integer_tag        3
#define jk_java_constant_float_tag          4
#define jk_java_constant_long_tag           5
#define jk_java_constant_double_tag         6
#define jk_java_constant_name_and_type_tag  12
#define jk_java_constant_utf8_tag           1

typedef struct jk_java_constant_class_t {
    uint_t tag;
    uint_t name_index;
} jk_java_constant_class_t;

long
jk_file_read_and_unpack(
    const jk_globals_t * globals,
    jk_file_t * f,
    jk_struct_t * spec,
    size_t packed_buffer_size,
    void * unpacked_buffer,
    size_t unpacked_buffer_size
    );

long
jk_file_read_and_unpack_array(
    const jk_globals_t * globals,
    jk_file_t * file,
    jk_array_t * array,
    size_t offset,
    size_t size
    );

long
jk_unpack(
    const jk_globals_t * globals,
    uint_t endian,
    const void * vpacked_buffer,
    void * vunpacked_buffer,
    jk_struct_t * specs
    );

#define jk_min(x,y) (((x) < (y)) ? (x) : (y))
#define jk_max(x,y) (((x) < (y)) ? (y) : (x))

long
jk_compute_packed_or_unpacked_size(
    const jk_globals_t * globals,
    jk_struct_t * p,
    uint_t packed_or_unpacked
    );

long
jk_compute_packed_size(
    const jk_globals_t * globals,
    jk_struct_t * p
    );

long
jk_compute_unpacked_size(
    const jk_globals_t * globals,
    jk_struct_t * p
    );

unsigned jk_align_integer(unsigned n);

long
jk_file_open_for_read(
    const jk_globals_t * globals,
    jk_file_t * file,
    const char * file_path
    );

long
jk_file_close(
    jk_file_t * file
    );

long
jkp_file_read_direct(
    jk_file_t * file,
    void * buffer,
    size_t bytes_to_read,
    size_t * bytes_read
    );

long
jk_dump_struct(
    const jk_globals_t * globals,
    const char * prefix,
    const void * vbase,
    const jk_struct_t * desc
    );

long
jk_file_read_ahead(
    jk_file_t * file,
    size_t n
    );

long
jk_file_read_copy(
    jk_file_t * file,
    void * buffer,
    size_t bytes_to_read,
    size_t * bytes_read
    );
    
long
jk_file_read_get_buffer(
    jk_file_t * file,
    void ** out_buffer,
    size_t bytes_to_read,
    size_t * out_bytes_read
    );

uint_t
jk_get_big_endian_u2(
    const uchar_t * a
    );

ulong_t
jk_get_big_endian_u4(
    const uchar_t * a
    );

uint_t
jk_get_little_endian_u2(
    const uchar_t * a
    );
    
ulong_t
jk_get_little_endian_u4(
    const uchar_t * a
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
    jk_longlong_t * a
    );

void
jk_longlong_from_long(
    jk_longlong_t * a,
    long b
    );

void
jk_longlong_from_ulong(
    jk_longlong_t * a,
    ulong_t b
    );

void
jk_ulonglong_from_ulong(
    jk_ulonglong_t * a,
    ulong_t b
    );

long
jk_carry_to_error(
	uint_t carry
	);

typedef uint_t jk_carry_t;

/* long */

void jk_long_add_with_carry_in(long * a, long b, long c, jk_carry_t carry);
void jk_long_add_with_carry_out(long * a, long b, long c, jk_carry_t * carry);
void jk_long_add_with_carry_in_and_out(long * a, long b, long c, jk_carry_t * carry);

void jk_long_add_in_place_with_carry_in(long * a, long b, jk_carry_t carry);
void jk_long_add_in_place_with_carry_out(long * a, long b, jk_carry_t * carry);
void jk_long_add_in_place_with_carry_in_and_out(long * a, long b, jk_carry_t * carry);

/* unsigned long */

void jk_ulong_add_with_carry_in(ulong_t * a, ulong_t b, ulong_t c, jk_carry_t carry);
void jk_ulong_add_with_carry_out(ulong_t * a, ulong_t b, ulong_t c, jk_carry_t * carry);
void jk_ulong_add_with_carry_in_and_out(ulong_t * a, ulong_t b, ulong_t c, jk_carry_t * carry);

void jk_ulong_add_in_place_with_carry_in(ulong_t * a, ulong_t b, jk_carry_t carry);
void jk_ulong_add_in_place_with_carry_out(ulong_t * a, ulong_t b, jk_carry_t * carry);
void jk_ulong_add_in_place_with_carry_in_and_out(ulong_t * a, ulong_t b, jk_carry_t * carry);

void jk_ulong_add_one_with_carry_out(ulong_t * a, ulong_t b, jk_carry_t * carry);
void jk_ulong_add_one_in_place_with_carry_out(ulong_t * a, jk_carry_t * carry);

/* size_t */

void jk_sizet_add_with_carry_in(size_t * a, size_t b, size_t c, jk_carry_t carry);
void jk_sizet_add_with_carry_out(size_t * a, size_t b, size_t c, jk_carry_t * carry);
void jk_sizet_add_with_carry_in_and_out(size_t * a, size_t b, size_t c, jk_carry_t * carry);

void jk_sizet_add_in_place_with_carry_in(size_t * a, size_t b, jk_carry_t carry);
void jk_sizet_add_in_place_with_carry_out(size_t * a, size_t b, jk_carry_t * carry);
void jk_sizet_add_in_place_with_carry_in_and_out(size_t * a, size_t b, jk_carry_t * carry);

void jk_sizet_add_one_with_carry_out(size_t * a, size_t b, jk_carry_t * carry);
void jk_sizet_add_one_in_place_with_carry_out(size_t * a, jk_carry_t * carry);
void jk_sizet_add_one_in_place_with_carry_out(size_t * a, jk_carry_t * carry);

/* jk_longlong_t
   jk_ulonglong_t
*/

void
jk_longlong_add(
    jk_longlong_t * a,
    const jk_longlong_t * b,
    const jk_longlong_t * c
    );

void
jk_ulonglong_add(jk_ulonglong_t * a, const jk_ulonglong_t * b, const jk_ulonglong_t * c);

void
jk_ulonglong_bitwise_and(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b,
    const jk_ulonglong_t * c
    );

void
jk_ulonglong_bitwise_or(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b,
    const jk_ulonglong_t * c
    );

void
jk_longlong_bitwise_and(
    jk_longlong_t * a,
    const jk_longlong_t * b,
    const jk_longlong_t * c
    );

void
jk_longlong_bitwise_or(
    jk_longlong_t * a,
    const jk_longlong_t * b,
    const jk_longlong_t * c
    );

unsigned
jk_ulonglong_to_boolean(
    const jk_ulonglong_t * a
    );

unsigned
jk_longlong_to_boolean(
    const jk_longlong_t * a
    );

unsigned
jk_ulonglong_logical_and(
    const jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    );

unsigned
jk_ulonglong_logical_or(
    const jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    );

unsigned
jk_longlong_logical_and(
    const jk_longlong_t * a,
    const jk_longlong_t * b
    );

unsigned
jk_longlong_logical_or(
    const jk_longlong_t * a,
    const jk_longlong_t * b
    );

void
jk_ulonglong_bitwise_invert(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    );

void
jk_longlong_bitwise_invert(
    jk_longlong_t * a,
    const jk_longlong_t * b
    );

unsigned
jk_ulonglong_logical_not(
    const jk_ulonglong_t * a
    );

unsigned
jk_longlong_logical_not(
    const jk_longlong_t * a
    );

void
jk_ulonglong_left_shift(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b,
    unsigned shift
    );

void
jk_longlong_left_shift(
    jk_longlong_t * a,
    const jk_longlong_t * b,
    unsigned shift
    );

void
jk_ulonglong_right_shift(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b,
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

ulong_t
jk_ulong_one_fill_right_shift(
    ulong_t a,
    unsigned shift
    );

ulong_t
jk_ulong_zero_fill_right_shift(
    ulong_t a,
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
jk_ulonglong_one_fill_right_shift(jk_ulonglong_t * a, const jk_ulonglong_t * b, unsigned shift);

void
jk_ulonglong_zero_fill_right_shift(jk_ulonglong_t * a, const jk_ulonglong_t * b, unsigned shift);

void
jk_longlong_one_fill_right_shift(jk_longlong_t * a, const jk_longlong_t * b, unsigned shift);

void
jk_longlong_zero_fill_right_shift(jk_longlong_t * a, const jk_longlong_t * b, unsigned shift);

void
jk_longlong_sign_fill_right_shift(jk_longlong_t * a, const jk_longlong_t * b, unsigned shift);

void
jk_ulong_multiply_to_ulonglong(jk_ulonglong_t * a, ulong_t b, ulong_t c);

void
jk_long_multiply_to_longlong(jk_longlong_t * a, long b, long c);

void
jk_ulonglong_multiply(
	jk_ulonglong_t * a,
	const jk_ulonglong_t * b,
	const jk_ulonglong_t * c
	);

void
jk_longlong_multiply(
	jk_longlong_t * a,
	const jk_longlong_t * b,
	const jk_longlong_t * c
	);

float
jk_java_convert_java_float_to_native_float(
    const unsigned char * bytes
    );

double
jk_java_convert_java_double_to_native_double(
    const unsigned char * bytes
    );

void
jk_java_get_long(
    jk_longlong_t * i,
    const unsigned char * p
    );

void
jk_java_get_ulong(
    jk_ulonglong_t * i,
    const unsigned char * p
    );

long
jk_java_read_constant_pool(
    jk_file_t * file,
    jk_java_constant_pool_t * constant_pool
    );

long
jk_java_read_classfile(
    const jk_globals_t * globals,
    jk_java_classfile_t ** ppcf,
	const char * filepath
	);

ulong_t
jk_ulong_rotate_left(
	ulong_t a,
	unsigned b
	);

ulong_t
jk_ulong_rotate_right(
	ulong_t a,
	unsigned b
	);
    
void
jk_add_ulong_to_ulonglong_in_place(
    jk_ulonglong_t * a,
    ulong_t b
    );

/*
this inteface supports usual pointer-ful heaps and position independent, compactable heaps

the out pointer from allocate may just be an opaque cookie
that you may have to pass to convert_cookie_to_pointer to use
the result of convert_cookie_to_pointer may be invalidated
by calls to allocate and free, but the opaque cookie never is
*/
typedef long (*jk_memory_allocator_functions_allocate_t)(jk_memory_allocator_t *, size_t number_of_bytes, void ** p);
typedef long (*jk_memory_allocator_functions_convert_cookie_to_pointer_t)(jk_memory_allocator_t *, void * cookie, void ** p);
 
struct jk_memory_allocator_functions_t {
    jk_memory_allocator_functions_allocate_t allocate;
    void (*free)(jk_memory_allocator_t *, void ** p);
    jk_memory_allocator_functions_convert_cookie_to_pointer_t convert_cookie_to_pointer;
};

struct jk_memory_allocator_t {
    /*const*/ jk_memory_allocator_functions_t * functions;
};

long
jk_default_memory_allocator_allocate(
    jk_memory_allocator_t * state,
    size_t number_of_bytes,
    void ** pp
    );

void
jk_default_memory_allocator_free(
    jk_memory_allocator_t * state,
    void ** pp
    );

long
jk_default_memory_allocator_convert_cookie_to_pointer(
    jk_memory_allocator_t * state,
    void * cookie,
    void ** pointer
    );

typedef struct jk_multiprecisioninteger_t jk_multiprecisioninteger_t;

ulong_t *
jk_multipleprecision_integer_get_value_array(
    const jk_multiprecisioninteger_t * m
    );
    
long
jk_multiprecision_integer_from_long(
    jk_multiprecisioninteger_t * m,
    long i
    );

long
jk_multiprecision_integer_from_ulong(
    jk_multiprecisioninteger_t * m,
    ulong_t i
    );

long
jk_multiprecision_integer_from_ulong_and_sign(
    jk_multiprecisioninteger_t * m,
    ulong_t i,
    int sign
    );

long
jk_multiprecision_integer_ensure_precision(
    jk_multiprecisioninteger_t * m,
    unsigned n
    );

long
jk_multiprecision_integer_set_precision(
    jk_multiprecisioninteger_t * m,
    unsigned n
    );
    
void
jk_ulonglong_add_in_place(
	jk_ulonglong_t * a,
	const jk_ulonglong_t * b
	);

void
jk_add_ulong_to_ulonglong(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * c,
    ulong_t b
    );

void
jk_ulonglong_bitwise_exclusive_or(
	jk_ulonglong_t * a,
	const jk_ulonglong_t * b,
	const jk_ulonglong_t * c
	);

void
jk_longlong_bitwise_exclusive_or(
	jk_longlong_t * a,
	const jk_longlong_t * b,
	const jk_longlong_t * c
	);

void
jk_ulonglong_bitwise_invert_in_place(
	jk_ulonglong_t * a
	);

void
jk_longlong_bitwise_invert_in_place(
	jk_longlong_t * a
	);

ulong_t
jk_ulong_extract_left_n_bits_right_aligned(
	ulong_t a,
	unsigned n
	);

ulong_t
jk_ulong_extract_left_n_bits(
	ulong_t a,
	unsigned n
	);

ulong_t
jk_ulong_extract_right_n_bits(
	ulong_t a,
	unsigned n
	);

ulong_t
jk_ulong_extract_right_n_bits_left_aligned(
	ulong_t a,
	unsigned n
	);

void
jk_ulonglong_left_shift_in_place(
	jk_ulonglong_t * a,
	unsigned shift
	);

ulong_t
jk_ulong_with_n_right_bits_clear(
	unsigned n
	);

ulong_t
jk_ulong_with_n_right_bits_set(
	unsigned n
	);

ulong_t
jk_ulong_with_n_left_bits_clear(
	unsigned n
	);

ulong_t
jk_ulong_with_n_left_bits_set(
	unsigned n
	);

ulong_t
jk_ulong_get_right_justified_high_half(
	ulong_t a
	);

ulong_t
jk_ulong_get_low_half(
	ulong_t a
	);

ulong_t
jk_ulong_get_left_justified_high_half(
	ulong_t a
	);

void
jk_long_split_into_magnitude_and_sign(
    long i,
    ulong_t * magnitude,
    int * sign
    );

void
jk_longlong_split_into_magnitude_and_sign(
	const jk_longlong_t * i,
    jk_ulonglong_t * magnitude,
    int * sign
    );

void
jk_longlong_negate(
    jk_longlong_t * a,
    const jk_longlong_t * b
    );
    
void
jk_longlong_negate_in_place(
    jk_longlong_t * a
    );

void
jk_longlong_add_in_place(
    jk_longlong_t * a,
    const jk_longlong_t * b
    );

long
jk_java_init_constant_pool(
	jk_java_constant_pool_t * constant_pool
	);

long
jk_java_init_classfile(
	jk_java_classfile_t * classfile
	);
	
void
jk_java_free_constant_pool(
    jk_java_constant_pool_t * constant_pool
    );
	
long
jk_java_free_classfile(
    jk_java_classfile_t * classfile
    );

void
jk_profile_dump_function_call_counts(
    void
    );

typedef size_t jk_spin_lock_t;
typedef size_t jk_irql_t;

void jk_initialize_spin_lock(jk_spin_lock_t * lock);
void jk_acquire_spin_lock(jk_spin_lock_t * lock, jk_irql_t * previous_irql);
void jk_release_spin_lock(jk_spin_lock_t * lock, jk_irql_t previous_irql);

void jk_spin(int i);

void jk_sleep(int i);

typedef struct jk_profile_record_t {
	unsigned long call_count;
	struct jk_profile_record_t * next;
	jk_constant_string_t function_name;
} jk_profile_record_t;

extern jk_spin_lock_t        jk_profile_record_list_lock;
extern jk_profile_record_t * jk_profile_record_list;

void
jkp_initialize_profile_record(
	jk_profile_record_t * profile_record
	);

void jk_interlocked_compare_exchange_pointer();
void jk_interlocked_exchange_pointer();
long jk_interlocked_increment_long(long *);
long jk_interlocked_decrement_long(long *);

typedef struct jk_critical_section_t { int i; } jk_critical_section_t;
void jk_enter_critical_section(jk_critical_section_t * cs);
void jk_leave_critical_section(jk_critical_section_t * cs);

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
    jk_range_table_t * range_table
    );
    
long
jk_range_table_add_value(
    jk_range_table_t * range_table,
    size_t value
    );

long
jk_range_table_remove_value(
    jk_range_table_t * range_table,
    size_t value
    );
    
long
jk_range_table_add_range(
    jk_range_table_t * range_table,
    const jk_range_t * range
    );

long
jk_range_table_remove_range(
    jk_range_table_t * range_table,
    const jk_range_t * range
    );
    
long
jk_range_table_contains_value(
    jk_range_table_t * range_table,
    size_t value,
    jk_bool_t * contains_value
    );

long
jk_range_table_find_range_with_value(
    jk_range_table_t * range_table,
    size_t value,
    jk_range_t * range
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
    ulong_t sequence_number;
} jk_special_heap_block_t;

typedef struct jk_special_heap_t {
    jk_memory_allocator_t * memory_allocator;
    uchar_t *   store;
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
    jk_special_heap_t * heap,
    jk_memory_allocator_t * allocator
    );

long
jk_special_heap_destroy(
    jk_special_heap_t * heap
    );

long
jk_special_heap_alloc(
    jk_special_heap_t * heap,
    size_t number_of_bytes_to_allocate,
    ulong_t * sequence_number,
    void ** optional_out_unstable_pointer
    );

long
jk_special_heap_get_pointer(
    jk_special_heap_t * heap,
    ulong_t sequence_number,
    void ** pointer
    );

long
jk_special_heap_free(
    jk_special_heap_t * heap,
    ulong_t sequence_number
    );

long
jk_undone(
    void
    );

void jk_unused4(const void * a1, const void * a2, const void * a3, const void * a4);
void jk_unused(const void *);
void jk_init_fields(void);
void jk_init_classfile_type_info(void);
void jk_limited_truncating_string_copy(char * dest, const char * src, size_t n);
void jk_type_dump_char(const jk_type_t * t, size_t buffer_size, char * buffer, void * data);

long
jk_malloc(
	void ** pp,
	size_t n
	);

void
jk_free(
	void ** pp
	);

void
jk_longlong_left_shift_in_place(
    jk_longlong_t * a,
    unsigned shift
    );
    
long
jk_long_safe_negate(
    long i
    );

void
jk_longlong_left_shift_in_place(
    jk_longlong_t * a,
    unsigned shift
    );

unsigned
jk_ulonglong_is_greater_or_equal(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j
    );

unsigned
jk_ulonglong_is_greater(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j
    );

unsigned
jk_ulonglong_is_less(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j
    );

unsigned
jk_ulonglong_is_less_or_equal(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j
    );

unsigned
jk_ulonglong_is_equal(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j
    );

unsigned
jk_ulonglong_is_not_equal(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j
    );


unsigned
jk_longlong_is_greater_or_equal(
    const jk_longlong_t * i,
    const jk_longlong_t * j
    );

unsigned
jk_longlong_is_greater(
    const jk_longlong_t * i,
    const jk_longlong_t * j
    );

unsigned
jk_longlong_is_less(
    const jk_longlong_t * i,
    const jk_longlong_t * j
    );

unsigned
jk_longlong_is_less_or_equal(
    const jk_longlong_t * i,
    const jk_longlong_t * j
    );

unsigned
jk_longlong_is_equal(
    const jk_longlong_t * i,
    const jk_longlong_t * j
    );

unsigned
jk_longlong_is_not_equal(
    const jk_longlong_t * i,
    const jk_longlong_t * j
    );

#define jk_swap_primtive(T,x,y) do { T t = x; x = y; y = t; } while(0)
#define jk_integer_compare_tristate(x,y) ((x == y) ? 0 : (x < y) ? -1 : +1)

unsigned
jk_ulonglong_is_in_ordered_range_inclusive(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * low,
    const jk_ulonglong_t * high
    );

unsigned
jk_longlong_is_in_ordered_range_inclusive(
    const jk_longlong_t * i,
    const jk_longlong_t * low,
    const jk_longlong_t * high
    );

void
jk_ulonglong_order_range(
    const jk_ulonglong_t ** low,
    const jk_ulonglong_t ** high
    );

void
jk_longlong_order_range(
    const jk_longlong_t ** low,
    const jk_longlong_t ** high
    );

unsigned
jk_ulonglong_is_in_unordered_range_inclusive(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j,
    const jk_ulonglong_t * k
    );

unsigned
jk_longlong_is_in_unordered_range_inclusive(
    const jk_longlong_t * i,
    const jk_longlong_t * j,
    const jk_longlong_t * k
    );

unsigned
jk_ulonglong_is_in_ordered_range_exclusive(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * low,
    const jk_ulonglong_t * high
    );

unsigned
jk_longlong_is_in_ordered_range_exclusive(
    const jk_longlong_t * i,
    const jk_longlong_t * low,
    const jk_longlong_t * high
    );

unsigned
jk_ulonglong_is_in_unordered_range_exclusive(
    const jk_ulonglong_t * i,
    const jk_ulonglong_t * j,
    const jk_ulonglong_t * k
    );

unsigned
jk_longlong_is_in_unordered_range_exclusive(
    const jk_longlong_t * i,
    const jk_longlong_t * j,
    const jk_longlong_t * k
    );
 
void
jk_copy_ulonglong_to_longlong(
    jk_longlong_t * to,
    const jk_ulonglong_t * from
    );

void
jk_copy_longlong_to_ulonglong(
    jk_ulonglong_t * to,
    const jk_longlong_t * from
    );
    
void
jk_ulonglong_from_long(
    jk_ulonglong_t * a,
    long b
    );

unsigned
jk_multiprecision_integer_to_boolean(
    const jk_multiprecisioninteger_t * m
    );

unsigned
jk_multiprecision_integer_logical_not(
    const jk_multiprecisioninteger_t * m
    );

unsigned
jk_multiprecision_integer_logical_and(
    const jk_multiprecisioninteger_t * m,
    const jk_multiprecisioninteger_t * n
    );

unsigned
jk_multiprecision_integer_logical_or(
    const jk_multiprecisioninteger_t * m,
    const jk_multiprecisioninteger_t * n
    );

long
jk_multiprecision_integer_bitwise_invert(
    jk_multiprecisioninteger_t * m
    );

long
jk_multiprecision_integer_bitwise_and(
    jk_multiprecisioninteger_t * m,
    const jk_multiprecisioninteger_t * n
    );
 
long
jk_multiprecision_integer_reduce_precision_due_to_leading_zeros(
    jk_multiprecisioninteger_t * m
    );

long
jk_multiprecision_integer_bitwise_or(
    jk_multiprecisioninteger_t * m,
    const jk_multiprecisioninteger_t * n
    );
    
void
jk_ulonglong_add_one_in_place(
    jk_ulonglong_t * a
    );

void
jk_longlong_add_one_in_place(
    jk_longlong_t * a
    );

void
jk_ulonglong_add_one(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    );

void
jk_longlong_add_one(
    jk_longlong_t * a,
    const jk_longlong_t * b
    );
    
void
jk_ulonglong_negate(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    );

void
jk_ulonglong_negate_in_place(
    jk_ulonglong_t * a
    );

void
jk_ulonglong_bitwise_and_with_ulong_in_place(
    jk_ulonglong_t * a,
    ulong_t b
    );

unsigned
jk_assert_failed(
    const char * x,
    const char * file,
    long line
    );

void
jk_ulonglong_from_high_low_32bit_ulongs(
    jk_ulonglong_t * i,
    ulong_t high,
    ulong_t low
    );

void
jk_ulonglong_bitwise_or_in_place(
    jk_ulonglong_t * a,
    const jk_ulonglong_t * b
    );
    
void
jk_ulonglong_right_shift_in_place(
    jk_ulonglong_t * a,
    unsigned shift
    );

void
jk_utoa(
    unsigned u,
    char * a
    );
    
void
jk_itoa(
    int i,
    char * a
    );

void
jk_ultoa(
    ulong_t u,
    char * a
    );
    
void
jk_ltoa(
    long i,
    char * a
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
	void * bytes;
	void * static_buffer;
	size_t static_size;
	size_t allocated_size;
	size_t requested_size;
    jk_memory_allocator_t * allocator;
} jk_buffer_t;

long
jk_buffer_init(
	jk_buffer_t * buffer,
	size_t preallocated_buffer_size,
	void * preallocated_buffer
	);
	
void
jk_buffer_free(
	jk_buffer_t * buffer
	);
	
long
jk_buffer_set_size(
	jk_buffer_t * buffer,
	size_t size,
	void ** pointer /* optional */
	);

long
jk_buffer_get_size(
	jk_buffer_t * buffer,
	size_t * size
	);

long
jk_buffer_get_pointer(
	jk_buffer_t * buffer,
	void ** pointer
	);

#define jk_mspecoff_directory_entry_com_descriptor 14

typedef struct jk_mspecoff_packed_data_directory_t {
	uchar_t virtual_address[4];
	uchar_t size[4];
} jk_mspecoff_packed_data_directory_t;

typedef struct jk_mspecoff_data_directory_t {
	ulong_t virtual_address;
	ulong_t size;
} jk_mspecoff_data_directory_t;

typedef struct jk_mspecoff_packed_file_header_packed_t {
	uchar_t machine[2];
	uchar_t number_of_sections[2];
	uchar_t time_date_stamp[4];
	uchar_t pointer_to_symbol_table[4];
	uchar_t number_of_symbols[4];
	uchar_t size_of_optional_header[2];
	uchar_t characteristics[2]; /* aka flags */
} jk_mspecoff_packed_file_header_packed_t;

typedef struct jk_mspecoff_file_header_t {
	unsigned machine;
	unsigned number_of_sections;
	ulong_t time_date_stamp;
	ulong_t pointer_to_symbol_table;
	ulong_t number_of_symbols;
	unsigned size_of_optional_header;
	unsigned characteristics; /* aka flags */
} jk_mspecoff_file_header_t;

typedef struct jk_mspecoff_packed_optional_header32_t {
	/* standard fields */
	uchar_t magic[2];
	uchar_t major_linker_version;
	uchar_t minor_link_version;
	uchar_t size_of_code[4];
	uchar_t size_of_initialized_data[4];
	uchar_t size_of_uninitialized_data[4];
	uchar_t adddress_of_entry_point[4];
	uchar_t base_of_code[4];
	uchar_t base_of_data[4];
	/* nt fields */
	uchar_t image_base[4];
	uchar_t section_alignment[4]; /* aka in_memory_section_alignment */
	uchar_t file_alignment[4]; /* aka on_disk_section_alignment */
	uchar_t major_operating_system_version[2];
	uchar_t minor_operating_system_version[2];
	uchar_t major_image_version[2];
	uchar_t minor_image_version[2];
	uchar_t major_subsystem_version[2];
	uchar_t minor_subsystem_version[2];
	uchar_t win32_version[4];
	uchar_t size_of_image[4];
	uchar_t size_of_headers[4];
	uchar_t checksum[4];
	uchar_t subsystem[2];
	uchar_t dll_characteristics[2]; /* aka flags */
	uchar_t size_of_stack_reserve[4];
	uchar_t size_of_stack_commit[4];
	uchar_t size_of_heap_reserve[4];
	uchar_t size_of_heap_commit[4];
	uchar_t loader_flags[4];
	uchar_t number_of_rva_and_sizes[4]; /* aka number_of_data_directories */
} jk_mspecoff_packed_optional_header32_t;

typedef struct jk_mspecoff_packed_optional_header64_t {
	/* standard fields */
	uchar_t magic[2];
	uchar_t major_linker_version;
	uchar_t minor_link_version;
	uchar_t size_of_code[4];
	uchar_t size_of_initialized_data[4];
	uchar_t size_of_uninitialized_data[4];
	uchar_t adddress_of_entry_point[4];
	uchar_t base_of_code[4];
	/* nt fields */
	uchar_t image_base[8];
	uchar_t section_alignment[4]; /* aka in_memory_section_alignment */
	uchar_t file_alignment[4]; /* aka on_disk_section_alignment */
	uchar_t major_operating_system_version[2];
	uchar_t minor_operating_system_version[2];
	uchar_t major_image_version[2];
	uchar_t minor_image_version[2];
	uchar_t major_subsystem_version[2];
	uchar_t minor_subsystem_version[2];
	uchar_t win32_version[4];
	uchar_t size_of_image[4];
	uchar_t size_of_headers[4];
	uchar_t checksum[4];
	uchar_t subsystem[2];
	uchar_t dll_characteristics[2]; /* aka flags */
	uchar_t size_of_stack_reserve[8];
	uchar_t size_of_stack_commit[8];
	uchar_t size_of_heap_reserve[8];
	uchar_t size_of_heap_commit[8];
	uchar_t loader_flags[4];
	uchar_t number_of_rva_and_sizes[4]; /* aka number_of_data_directories */
} jk_mspecoff_packed_optional_header64_t;

struct jk_mspecoff_optional_header {
	/* standard fields */
	uint_t   magic;
	uint_t   major_linker_version;
	uint_t   minor_link_version;
	ulong_t size_of_code;
	ulong_t size_of_initialized_data;
	ulong_t size_of_uninitialized_data;
	ulong_t adddress_of_entry_point;
	jk_ulonglong_t  base_of_code;
	ulong_t base_of_data;
	/* nt fields */
	ulong_t image_base;
	ulong_t section_alignment; /* aka in_memory_section_alignment */
	ulong_t file_alignment; /* aka on_disk_section_alignment */
	uint_t  major_operating_system_version;
	uint_t  minor_operating_system_version;
	uint_t  major_image_version;
	uint_t  minor_image_version;
	uint_t  major_subsystem_version;
	uint_t  minor_subsystem_version;
	ulong_t win32_version;
	ulong_t size_of_image;
	ulong_t size_of_headers;
	ulong_t checksum;
	uint_t  subsystem;
	uint_t  dll_characteristics;        /* aka flags */
	jk_ulonglong_t size_of_stack_reserve;
	jk_ulonglong_t size_of_stack_commit;
	jk_ulonglong_t size_of_heap_reserve;
	jk_ulonglong_t size_of_heap_commit;
	ulong_t loader_flags;
	ulong_t number_of_rva_and_sizes;    /* aka number_of_data_directories */
	jk_array_t data_directory;          /* array of jk_mspecoff_data_directory_t */
} jk_mspecoff_optional_header;
	
/*
#    IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
#} IMAGE_OPTIONAL_HEADER, *PIMAGE_OPTIONAL_HEADER;
*/

void
jk_dump_environment_variablese(
    const jk_globals_t * globals
    );

struct jk_globals_t {
    const jk_fields_t * fields;
    const jk_types_t * types;
    jk_struct_t * java_packed_classfile_type_info;
    jk_struct_t * java_packed_classfile1_type_info;
    jk_struct_t * java_packed_classfile2_type_info;
    char ** environment_variables;
    jk_memory_allocator_t * default_memory_allocator;
};

extern jk_fields_t jk_fields;
extern jk_struct_t jk_java_classfile_type_info;
extern jk_struct_t jk_java_classfile1_type_info;
extern jk_struct_t jk_java_classfile2_type_info;
extern jk_memory_allocator_t jk_default_memory_allocator;

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
    jk_constant_string_t * s,
    const char * t,
    size_t length
    );

JK_EXTERN_C_END
