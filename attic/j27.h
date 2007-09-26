#include <stdio.h>

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
    uchar_t bytes[8];
} jk_packed_longlong_t;

typedef struct jk_packed_ulonglong_t {
    uchar_t bytes[8];
} jk_packed_ulonglong_t;
*/

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
    const unsigned char * from,
    size_t count
    );

void
jk_copy_memory_reverse(
    unsigned char * to,
    const unsigned char * from,
    size_t count
    );

void
jk_zero_memory(
    void * p,
    size_t n
    );

typedef struct jk_memory_allocator_functions_t jk_memory_allocator_functions_t;
typedef struct jk_memory_allocator_t jk_memory_allocator_t;
typedef struct jk_type_t jk_type_t;
typedef struct jk_globals_t jk_globals_t;

long jk_get_dump_length_int(size_t buffer_size, char * buffer, int data);
long jk_get_dump_length_unsigned_int(size_t buffer_size, char * buffer, unsigned int data);
long jk_get_dump_length_long(size_t buffer_size, char * buffer, long data);
long jk_get_dump_length_unsigned_long(size_t buffer_size, char * buffer, unsigned long data);

void jk_dump_int(size_t buffer_size, char * buffer, int data);
void jk_dump_unsigned_int(size_t buffer_size, char * buffer, unsigned int data);
void jk_dump_long(size_t buffer_size, char * buffer, long data);
void jk_dump_unsigned_long(size_t buffer_size, char * buffer, unsigned long data);

typedef long (*jk_type_get_dump_length_t)(const jk_type_t *, const void * data, size_t * length);
typedef long (*jk_type_dump_t)(const jk_type_t *, size_t buffer_size, char * buffer, const void * data);

struct jk_type_t
{	
    size_t size;
    long (*construct_n)(const jk_type_t *, void * , size_t n);
    long (*destroy_n)(const jk_type_t *, void *, size_t n);
    long (*copy_n)(const jk_type_t *, void * , const void *, size_t n);
    long (*move_n)(const jk_type_t *, void * , void*, size_t n);
    unsigned is_signed;
    jk_type_get_dump_length_t get_dump_length;
	jk_type_dump_t dump;
};

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

extern jk_type_t jk_type_uchar;
extern jk_type_t jk_type_char;
extern jk_type_t jk_type_short;
extern jk_type_t jk_type_ushort;
extern jk_type_t jk_type_int;
extern jk_type_t jk_type_uint;
extern jk_type_t jk_type_long;
extern jk_type_t jk_type_ulong;
extern jk_type_t jk_type_struct;
extern jk_type_t jk_type_void_pointer;

typedef struct jk_array_t {
    const jk_type_t * element_type;
    jk_memory_allocator_t * allocator;
    void * elements;
    size_t size_allocated;
    size_t size_requested;
} jk_array_t;

long
jk_array_init(
    jk_array_t * array,
    const jk_type_t * element_type,
    jk_memory_allocator_t * allocator
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

#define jk_endian_big    0
#define jk_endian_little 1

typedef struct jk_field_t {
    const char * name;
    size_t offset_to_type;
    size_t unpacked_size;
    size_t packed_size;
    size_t unpacked_offset;
    size_t packed_offset;
} jk_field_t;

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
} jk_fields_t;

typedef struct jk_struct_t {
    unsigned char endian;
    size_t offset_to_first_field;
    size_t offset_to_last_field;
    size_t packed_size;
    size_t unpacked_size;
} jk_struct_t;

#if defined(_WIN64)
typedef unsigned __int64 jk_ulong_ptr_t;
typedef          __int64 jk_long_ptr_t;
#else
typedef unsigned long jk_ulong_ptr_t;
typedef          long  jk_long_ptr_t;
#endif

typedef jk_ulong_ptr_t jk_size_t;
typedef  jk_long_ptr_t jk_ptrdiff_t;

#define jk_number_of(a)        ((size_t)(sizeof(a)/sizeof((a)[0])))
#define jkp_field(t,f)         (((t*)0)->f)
/*#define jk_field_size(t,f)     ((size_t)sizeof(jkp_field(t,f)))*/
#define jk_field_size(t,f)     sizeof(jkp_field(t,f))
#define jk_field_offset(a,b)   ((size_t)(jk_ulong_ptr_t)&jkp_field(a,b))
/*#define jk_field_offset(a,b)   ((size_t)(jk_ulong_ptr_t)8)*/
/*#define jk_field_index(t,f)    (jk_offsetof_field(t,f)/jk_sizeof_field(t,f))*/
#define jk_field_index(t,f)    jk_offsetof_field(t,f)
#define jk_offsetof(t,f)       jk_field_offset(t,f)
#define jk_offsetof_field(t,f) jk_field_offset(t,f)
#define jk_indexof_field(t,f)  jk_field_index(t,f)
#define jk_sizeof_field(t,f)   jk_field_size(t,f)
#define jk_sizeof_struct_through_and_including_field(t,f) (jk_offsetof_field(t,f) + jk_sizeof_field(t,f))
#define jk_sizeof_struct_through_but_excluding_field(t,f) jk_offsetof_field(t,f)
#define jk_does_struct_size_contain_field(s,size,f) ((size) <= jk_sizeof_struct_through_and_including_field(s,f))

typedef struct jk_types_t {
    jk_type_t * t_void;
    jk_type_t * t_char;
    jk_type_t * t_uchar;
    jk_type_t * t_short;
    jk_type_t * t_ushort;
    jk_type_t * t_int;
    jk_type_t * t_uint;
    jk_type_t * t_long;
    jk_type_t * t_ulong;
} jk_types_t;

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
	unsigned char Bytes[4];
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
    unsigned long   unsigned_long;
    unsigned long   unsignedlong;
    ulong_t   		UnsignedLong;
    unsigned short  unsigned_shorts[2];
    unsigned short  unsignedshorts[2];
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
	unsigned char 	Bytes[8];
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
    char * buffer;
    size_t buffer_size;
    size_t bytes_in_buffer;
    size_t position;
    size_t read_ahead;
    unsigned keep_all_bytes : 1;
} jk_file_buffer_t;

typedef struct jk_file_t {
    void * stdio_file;
    const char * file_path;
    const char * openmode;
    jk_file_buffer_t buffer;
} jk_file_t;

long
jk_file_open_for_read(
    const jk_globals_t * globals,
    jk_file_t * file,
    const char * file_path
    );
    
long
jk_file_read_copy(
    const jk_globals_t * globals,
    jk_file_t * f,
    void * buffer,
    size_t bytes_to_read,
    size_t * bytes_read /* optional */
    );

long
jk_file_read_get_buffer(
    const jk_globals_t * globals,
    jk_file_t * f,
    void ** buffer,
    size_t bytes_to_read,
    size_t * bytes_read /* optional */
    );

long
jk_file_read_ahead(
    const jk_globals_t * globals,
    jk_file_t * b,
    size_t bytes_to_read
    );
    
long
jk_file_close(
    const jk_globals_t * globals,
    jk_file_t * f
    );

typedef struct jk_java_constant_pool_t {
    uchar_t *   tags;
    jk_java_any_t * any;
} jk_java_constant_pool_t;

typedef struct jk_java_classfile_t {
    jk_file_t   file;
    char        magic[4];
    uint_t      minor_version;
    uint_t      major_version;
    uint_t      constant_pool_count;
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
    uchar_t    constant_pool_count[2];
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
    uchar_t    constant_pool_count[2];
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
    unsigned tag;
    unsigned name_index;
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
jk_unpack(
    const jk_globals_t * globals,
    unsigned endian,
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
    unsigned packed_or_unpacked
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
    const jk_globals_t * globals,
    jk_file_t * file
    );

long
jkp_file_read_direct(
    const jk_globals_t * globals,
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
    const jk_globals_t * globals,
    jk_file_t * file,
    size_t n
    );

long
jk_file_read_copy(
    const jk_globals_t * globals,
    jk_file_t * file,
    void * buffer,
    size_t bytes_to_read,
    size_t * bytes_read
    );
    
long
jk_file_read_get_buffer(
    const jk_globals_t * globals,
    jk_file_t * file,
    void ** out_buffer,
    size_t bytes_to_read,
    size_t * out_bytes_read
    );

unsigned
jk_get_big_endian_u2(const unsigned char * a);

unsigned long
jk_get_big_endian_u4(const unsigned char * a);

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
    unsigned long b
    );

void
jk_ulonglong_from_ulong(
    jk_ulonglong_t * a,
    unsigned long b
    );

void
jk_long_add_with_carry_in(long * a, long b, long c, unsigned carry);

void
jk_long_add_with_carry_out(long * a, long b, long c, unsigned * carry);

void
jk_long_add_with_carry_in_and_out(long * a, long b, long c, unsigned * carry);

void
jk_ulong_add_with_carry_in(unsigned long * a, unsigned long b, unsigned long c, unsigned carry);

void
jk_ulong_add_with_carry_out(unsigned long * a, unsigned long b, unsigned long c, unsigned * carry);

void
jk_ulong_add_with_carry_in_and_out(unsigned long * a, unsigned long b, unsigned long c, unsigned * carry);

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
jk_ulong_multiply_to_ulonglong(jk_ulonglong_t * a, unsigned long b, unsigned long c);

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
    const jk_globals_t * globals,
    jk_java_classfile_t * classfile
    );

long
jk_java_read_classfile(
    const jk_globals_t * globals,
    jk_java_classfile_t ** ppcf,
	const char * filepath
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
    jk_ulonglong_t * a,
    unsigned long b
    );

struct jk_memory_allocator_functions_t
{
    long (*allocate)(jk_memory_allocator_t *, size_t number_of_bytes, void ** p);
    void (*free)(jk_memory_allocator_t *, void ** p);
};

struct jk_memory_allocator_t
{
    const jk_memory_allocator_functions_t * functions;
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

void
jk_long_add_in_place_with_carry_in(
	long * a,
	long b,
	unsigned carry
	);

void
jk_long_add_in_place_with_carry_out(
	long * a,
	long b,
	unsigned * carry
	);

void
jk_long_add_in_place_with_carry_in_and_out(
	long * a,
	long b,
	unsigned * carry
	);

void
jk_ulong_add_in_place_with_carry_in(
	unsigned long * a,
	unsigned long b,
	unsigned carry
	);

void
jk_ulong_add_in_place_with_carry_in_and_out(
	unsigned long * a,
	unsigned long b,
	unsigned * carry
	);

typedef struct jk_multiprecisioninteger_t jk_multiprecisioninteger_t;

unsigned long *
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
    unsigned long i
    );

long
jk_multiprecision_integer_from_ulong_and_sign(
    jk_multiprecisioninteger_t * m,
    unsigned long i,
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
    unsigned long b
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
	jk_ulonglong_t * a,
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
jk_long_split_into_magnitude_and_sign(
    long i,
    unsigned long * magnitude,
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
jk_init_file_buffer(
    const jk_globals_t * globals,
	jk_file_buffer_t * file_buffer
	);
	
long
jk_init_file(
    const jk_globals_t * globals,
	jk_file_t * file
	);
	
long
jk_java_init_constant_pool(
    const jk_globals_t * globals,
	jk_java_constant_pool_t * constant_pool
	);

long
jk_java_init_classfile(
    const jk_globals_t * globals,
	jk_java_classfile_t * classfile
	);
	
void
jk_java_free_constant_pool(
    jk_java_constant_pool_t * constant_pool
    );

void
jk_profile_dump_function_call_counts(
    const jk_globals_t * globals
    );

typedef struct jk_compactable_heap_t jk_compactable_heap_t;

void
jk_get_pointer_into_compactable_heap(
    jk_compactable_heap_t * heap,
    size_t offset,
    void ** pointer
    );

void
jk_compact_compactable_heap(
    jk_compactable_heap_t * heap
    );
 
void
jk_compact_compactable_heap_to_new_minimal_underlying_allocation(
    jk_compactable_heap_t * heap
    );
    
#if 0

typedef struct jk_movable_heap_t jk_movable_heap_t;

long
jk_init_movable_heap(
	jk_movable_heap_t * heap
	);
	
long
jk_grow_movable_heap(
	jk_movable_heap_t * heap,
	size_t new_size
	);

long
jk_allocate_from_movable_heap(
	jk_movable_heap_t * heap,
	size_t size,
	size_t * pbase
	);

#endif

long
jk_undone(
    void
    );

void
jk_unused(
    const void *
    );

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
jk_ulong_add_one_with_carry_out(
    unsigned long * a,
    unsigned long b,
    unsigned * carry
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
jk_ulong_add_in_place_with_carry_out(
    unsigned long * a,
    unsigned long b,
    unsigned * carry
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
    unsigned long b
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
    unsigned long high,
    unsigned long low
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
    unsigned long u,
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

typedef struct jk_profile_count_function_calls_t jk_profile_count_function_calls_t;
typedef struct jk_profile_count_function_calls_map_entry_t jk_profile_count_function_calls_map_entry_t;

#define jkp_preprocessor_paste(x,y) x##y
#define jk_preprocessor_paste(x,y)  jkp_preprocessor_paste(x,y)
#define jk_compile_time_assert(x) typedef unsigned char jk_preprocessor_paste(jkp_compile_time_assert_private,__LINE__)[(x) ? 1 : 0]

typedef struct jk_seven_bit_constant_string_t {
    const char * chars; /* not necessarily nul terminated */
    size_t length;    /* in chars, not counting optional terminal nul */
} jk_seven_bit_constant_string_t;

#define jk_make_seven_bit_constant_string(s) { s, sizeof(s) - sizeof((s)[0]) }

typedef struct jk_buffer_t {
	void * bytes;
	void * static_buffer;
	size_t static_size;
	size_t allocated_size;
	size_t requested_size;
    jk_memory_allocator_t * allocator;
} jk_buffer_t;

long
jk_buffer_set_size(
	jk_buffer_t * buffer,
	size_t size
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

struct jk_globals_t
{
    const jk_fields_t * fields;
    const jk_types_t * types;
    jk_profile_count_function_calls_t * profile_count_function_calls;
	jk_seven_bit_constant_string_t * profile_name_functions;
    size_t profile_number_of_functions;
    jk_struct_t * java_packed_classfile_type_info;
    jk_struct_t * java_packed_classfile1_type_info;
    jk_struct_t * java_packed_classfile2_type_info;
};

JK_EXTERN_C_END
