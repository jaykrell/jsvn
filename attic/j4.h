#define JK_NOTHING /* nothing */#if defined(__cplusplus)#define JK_IF_CPLUSPLUS_ELSE(x,y) x#else#define JK_IF_CPLUSPLUS_ELSE(x,y) y#endif#define JK_IF_CPLUSPLUS(x)	JK_IF_CPLUSPLUS_ELSE(x, JK_NOTHING)#define JK_EXTERN_C       	JK_IF_CPLUSPLUS(extern "C"))#define JK_EXTERN_C_BEGIN 	JK_IF_CPLUSPLUS(extern "C" {)#define JK_EXTERN_C_END   	JK_IF_CPLUSPLUS(} /* extern "C" */)/* In C, const means extern const.   In C++, const means static const.   gcc 2.95.2 doesn't like "extern const" in C code.*/#define JK_EXTERN_CONST JK_IF_CPLUSPLUS(extern) constJK_EXTERN_C_BEGINextern const long jk_out_of_memory_error;typedef unsigned char  uchar_t;typedef unsigned int   uint_t;typedef unsigned short ushort_t;typedef unsigned long  ulong_t;typedef unsigned short jchar_t;typedef  char  char_t;typedef short short_t;typedef   int   int_t;typedef  long  long_t;/* These conflict with C99 math.h or somesuch (CodeWarrior 6).typedef float float_t;typedef double double_t;*/typedef struct jk_longlong_t {    signed long high;    unsigned long low;} jk_longlong_t;typedef struct jk_ulonglong_t {    unsigned long high;    unsigned long low;} jk_ulonglong_t;/*typedef struct jk_packed_longlong_t {    uchar_t bytes[8];} jk_packed_longlong_t;typedef struct jk_packed_ulonglong_t {    uchar_t bytes[8];} jk_packed_ulonglong_t;*/typedef struct jk_java_unresolved_constant_interface_member_ref_no_tag_t {	uint_t class_index;	uint_t name_and_type_index;} jk_java_unresolved_constant_member_ref_no_tag_t;typedef struct jk_java_unresolved_constant_string_ref_no_tag_t {	uint_t string_index;} jk_java_unresolved_constant_string_ref_no_tag_t;typedef struct jk_java_unresolved_constant_class_ref_no_tag_t {	uint_t class_index;} jk_java_unresolved_constant_class_ref_no_tag_t;/*typedef struct jk_java_packed_unresolved_constant_interface_member_ref_no_tag_t {	uchar_t class_index[2];	uchar_t name_and_type_index[2];} jk_java_packed_unresolved_constant_member_ref_no_tag_t;typedef struct jk_java_packed_unresolved_constant_string_ref_no_tag_t {	uchar_t string_index[2];} jk_java_packed_unresolved_constant_string_ref_no_tag_t;typedef struct jk_java_packed_unresolved_constant_class_ref_no_tag_t {	uchar_t class_index[2];} jk_java_packed_unresolved_constant_class_ref_no_tag_t;*/typedef union jk_java_half_word_t {    ushort_t  us;} jk_java_half_word_t;typedef union jk_java_unresolved_constant_no_tag_t {	jk_java_unresolved_constant_member_ref_no_tag_t field_ref;	jk_java_unresolved_constant_member_ref_no_tag_t method_ref;	jk_java_unresolved_constant_member_ref_no_tag_t interface_method_ref;	jk_java_unresolved_constant_member_ref_no_tag_t member_ref;	jk_java_unresolved_constant_string_ref_no_tag_t string_ref;	jk_java_unresolved_constant_class_ref_no_tag_t  class_ref;} jk_java_unresolved_constant_no_tag_t;typedef union jk_java_word_t {    void *    VoidPointer;    char *    CharPointer;    jchar_t * JcharPointer;    ulong_t   UnsignedLong;    ushort_t  UnsignedShorts[2];	jk_java_half_word_t HalfWords[2];    float     Float;	unsigned char Bytes[4];	jk_java_unresolved_constant_no_tag_t unresolved_constant;} jk_java_word_t;typedef jk_longlong_t jk_java_long_t;typedef union jk_java_any_t {    void *    		VoidPointer;    char *    		CharPointer;    jchar_t * 		JcharPointer;    ulong_t   		UnsignedLong;    ushort_t	  	UnsignedShorts[2];	jk_java_half_word_t HalfWords[2];    float        	Float;	double         	Double;	jk_longlong_t  	LongLong;	jk_ulonglong_t 	UlongLong;	jk_java_unresolved_constant_no_tag_t unresolved_constant;} jk_java_any_t;/* double_word is not portable enough; we need to store doubles "unbroken"this will lead us to use a stack of jk_java_any_t instead of jk_java_word_tif we certain we had ieee float and/or ieee double and/or a 32bit machine,we could optimize; Java clearly has in mind such a machine; we should beportable to 16 and 32bit machines, and non ieee floating if accuracyand precision of floating operations can be alteredtypedef union jk_java_double_word_t {    ulong_t   		UnsignedLongs[2];     long_t   		Longs[2];	unsigned char 	Bytes[8];} jk_java_double_word_t;*/typedef struct jk_java_constant_memberref_t {    unsigned class_index;    unsigned name_and_type_index;} jk_java_constant_memberref_t;typedef jk_java_constant_memberref_t jk_java_constant_fieldref_t;typedef jk_java_constant_memberref_t jk_java_constant_methodref_t;typedef jk_java_constant_memberref_t jk_java_constant_interfacemethodref_t;typedef struct jk_java_constant_string_t {    unsigned string_index;} jk_java_constant_string_t;typedef struct jk_java_constant_integer_t {    unsigned long number;} jk_java_constant_integer_t;typedef struct jk_java_constant_float_t {    float number;} jk_java_constant_float_t;typedef union jk_java_constant_untagged_union_t {    jk_java_constant_memberref_t memberref;} jk_java_constant_untagged_union_t;#define jk_java_magic "\xca\xfe\xba\xbe"typedef struct jk_file_buffer_t {    char * buffer;    unsigned buffer_size;    unsigned bytes_in_buffer;    unsigned position;    unsigned read_ahead;    unsigned keep_all_bytes : 1;} jk_file_buffer_t;typedef struct jk_file_t {    void * stdio_file;    const char * file_path;    const char * openmode;    jk_file_buffer_t buffer;} jk_file_t;longjk_file_open_for_read(    jk_file_t * file,    const char * file_path    );    longjk_file_read_copy(    jk_file_t * f,    void * buffer,    unsigned bytes_to_read,    unsigned * bytes_read /* optional */    );longjk_file_read_get_buffer(    jk_file_t * f,    void ** buffer,    unsigned bytes_to_read,    unsigned * bytes_read /* optional */    );longjk_file_read_ahead(    jk_file_t * b,    unsigned bytes_to_read    );    longjk_file_close(    jk_file_t * f    );typedef struct jk_java_constant_pool_t {    uchar_t *   tags;    jk_java_any_t * any;} jk_java_constant_pool_t;typedef struct jk_java_classfile_t {    jk_file_t   file;    char        magic[4];    uint_t      minor_version;    uint_t      major_version;    uint_t      constant_pool_count;    uint_t      access_flags;    uint_t      this_class;    uint_t      super_class;    uint_t      interfaces_count;    uint_t      fields_count;    uint_t      methods_count;    uint_t      attributes_count;    jk_java_constant_pool_t constant_pool;} jk_java_classfile_t;typedef struct jk_java_packed_classfile1_t {    uchar_t    magic[4];    uchar_t    minor_version[2];    uchar_t    major_version[2];    uchar_t    constant_pool_count[2];    /* constant_pool */} jk_java_packed_classfile1_t;typedef struct jk_java_packed_classfile2_t {    uchar_t    access_flags[2];    uchar_t    this_class[2];    uchar_t    super_class[2];    uchar_t    interfaces_count[2];    /* uchar_t interfaces[interfaces_count][[2] */} jk_java_packed_classfile2_t;typedef struct jk_java_packed_classfile3_t {    uchar_t    magic[4];    uchar_t    minor_version[2];    uchar_t    major_version[2];    uchar_t    constant_pool_count[2];    /* constant_pool */    uchar_t    access_flags[2];    uchar_t    this_class[2];    uchar_t    super_class[2];    uchar_t    interfaces_count[2];    /* uchar_t interfaces[interfaces_count][[2]; */    uchar_t fields_count[2];    /* jk_java_packed_field_info_t fields[fields_count]; */    uchar_t methods_count[2];    /* jk_java_packed_method_info_t methods[method_count]; */    uchar_t attributes_count[2];    /* jk_java_packed_attribute_info_t attributes[attribute_count]; */} jk_java_packed_classfile3_t;#define jk_java_constant_class_tag          7#define jk_java_constant_fieldref_tag       9#define jk_java_constant_methodref_tag      10#define jk_java_constant_interfacemethodref_tag 11#define jk_java_constant_string_tag         8#define jk_java_constant_integer_tag        3#define jk_java_constant_float_tag          4#define jk_java_constant_long_tag           5#define jk_java_constant_double_tag         6#define jk_java_constant_nameandtype_tag    12#define jk_java_constant_utf8_tag           1typedef struct jk_java_constant_class_t {    unsigned tag;    unsigned name_index;} jk_java_constant_class_t;#define jk_endian_big    0#define jk_endian_little 1typedef struct jk_pack_spec1_t {    unsigned packed_size     : 4;    unsigned unpacked_size   : 4;    unsigned packed_offset   : 7;    unsigned unpacked_offset : 7;    signed   is_signed       : 1;} jk_pack_spec1_t;typedef struct jk_pack_specn_t {    unsigned endian             : 2;    unsigned number_of_elements : 5;    const jk_pack_spec1_t * elements;    unsigned packed_size        : 6;    unsigned unpacked_size      : 6;} jk_pack_specn_t;#define jk_field_size(a,b)   ((unsigned)sizeof(((a*)0)->b))#define jk_field_offset(a,b) ((unsigned)&((a*)0)->b)#define jk_number_of(a)      ((unsigned)(sizeof(a)/sizeof((a)[0])))#define jk_make_pack_spec(packed, unpacked, field, endian) \    {     jk_field_size(packed, field), \        jk_field_size(unpacked, field), \        jk_field_offset(packed, field), \        jk_field_offset(unpacked, field) \    }    #define jk_offsetof(t,f) ((unsigned)(&((t*)0)->f))longjk_file_read_and_unpack(    jk_file_t * f,    jk_pack_specn_t * spec,    unsigned packed_buffer_size,    void * unpacked_buffer,    unsigned unpacked_buffer_size    );longjk_unpack(    unsigned endian,    const void * vpacked_buffer,    void * vunpacked_buffer,    const jk_pack_spec1_t * specs,    unsigned n    );#define jk_min(x,y) (((x) < (y)) ? (x) : (y))#define jk_max(x,y) (((x) < (y)) ? (y) : (x))extern const jk_pack_spec1_t jk_java_classfile_pack_specs1[];extern const jk_pack_spec1_t jk_java_classfile_pack_specs2[];extern jk_pack_specn_t jk_java_classfile_pack_spec1;voidjk_reverse_memory(    unsigned char * p,    unsigned count    );voidjk_move_memory(    void * to,    const void * from,    unsigned count    );voidjk_copy_memory(    void * to,    const void * from,    unsigned count    );voidjk_copy_memory_unsigned_char(    unsigned char * to,    const unsigned char * from,    unsigned count    );voidjk_copy_memory_reverse(    unsigned char * to,    const unsigned char * from,    unsigned count    );voidjk_zero_memory(    void * p,    unsigned n    );longjk_unpack(    unsigned endian,    const void * vpacked_buffer,    void * vunpacked_buffer,    const jk_pack_spec1_t * specs,    unsigned n    );longjk_compute_packed_or_unpacked_size(    jk_pack_specn_t * p,    unsigned packed_or_unpacked    );longjk_compute_packed_size(jk_pack_specn_t * p);longjk_compute_unpacked_size(jk_pack_specn_t * p);unsigned jk_align_integer(unsigned n);longjk_file_open_for_read(    jk_file_t * file,    const char * file_path    );longjk_file_close(    jk_file_t * file    );longjkp_file_read_direct(    jk_file_t * file,    void * buffer,    unsigned bytes_to_read,    unsigned * bytes_read    );longjk_file_read_and_unpack(    jk_file_t * file,    jk_pack_specn_t * spec,    unsigned packed_buffer_size,    void * unpacked_buffer,    unsigned unpacked_buffer_size    );typedef struct jk_dump_struct_t {    unsigned     number_of_fields;    const struct jk_dump_field_t * fields;} jk_dump_struct_t;typedef struct jk_dump_field_t {    unsigned offset;    const char * name;    const char * format;} jk_dump_field_t;longjk_dump_struct(    const char * prefix,    const void * vbase,    const jk_dump_struct_t * desc    );extern const jk_dump_field_t jk_dump_java_classfile_fields[];extern const jk_dump_struct_t jk_dump_java_classfile_struct;longjk_file_read_ahead(    jk_file_t * file,    unsigned n    );longjk_file_read_copy(    jk_file_t * file,    void * buffer,    unsigned bytes_to_read,    unsigned * bytes_read    );    longjk_file_read_get_buffer(    jk_file_t * file,    void ** out_buffer,    unsigned bytes_to_read,    unsigned * out_bytes_read    );unsignedjk_get_big_endian_u2(const unsigned char * a);unsigned longjk_get_big_endian_u4(const unsigned char * a);extern const float jk_java_positive_infinity_float;extern const float jk_java_negative_infinity_float;extern const double jk_java_positive_infinity_double;extern const double jk_java_negative_infinity_double;extern const float jk_java_nan_float;extern const double jk_java_nan_double;jk_ulonglong_tjk_longlong_to_ulonglong(jk_longlong_t a);jk_ulonglong_t*jk_longlong_to_ulonglong_pointer(jk_longlong_t * a);voidjk_longlong_from_long(jk_longlong_t * a, long b);voidjk_longlong_from_ulong(jk_longlong_t * a, unsigned long b);voidjk_ulonglong_from_ulong(jk_ulonglong_t * a, unsigned long b);voidjk_long_add_with_carry_in(long * a, long b, long c, unsigned carry);voidjk_long_add_with_carry_out(long * a, long b, long c, unsigned * carry);voidjk_long_add_with_carry_in_and_out(long * a, long b, long c, unsigned * carry);voidjk_ulong_add_with_carry_in(unsigned long * a, unsigned long b, unsigned long c, unsigned carry);voidjk_ulong_add_with_carry_out(unsigned long * a, unsigned long b, unsigned long c, unsigned * carry);voidjk_ulong_add_with_carry_in_and_out(unsigned long * a, unsigned long b, unsigned long c, unsigned * carry);voidjk_longlong_add(jk_longlong_t * a, jk_longlong_t b, jk_longlong_t c);voidjk_ulonglong_add(jk_ulonglong_t * a, jk_ulonglong_t b, jk_ulonglong_t c);voidjk_ulonglong_bitwise_and(jk_ulonglong_t * a, jk_ulonglong_t b, jk_ulonglong_t c);voidjk_ulonglong_bitwise_or(jk_ulonglong_t * a, jk_ulonglong_t b, jk_ulonglong_t c);voidjk_longlong_bitwise_and(jk_longlong_t * a, jk_longlong_t b, jk_longlong_t c);voidjk_longlong_bitwise_or(jk_longlong_t * a, jk_longlong_t b, jk_longlong_t c);unsignedjk_ulonglong_to_boolean(jk_ulonglong_t a);unsignedjk_longlong_to_boolean(jk_longlong_t a);unsignedjk_ulonglong_logical_and(jk_ulonglong_t a, jk_ulonglong_t b);unsignedjk_ulonglong_logical_or(jk_ulonglong_t a, jk_ulonglong_t b);unsignedjk_longlong_logical_and(jk_longlong_t a, jk_longlong_t b);unsignedjk_longlong_logical_or(jk_longlong_t a, jk_longlong_t b);voidjk_ulonglong_bitwise_not(jk_ulonglong_t * a, jk_ulonglong_t b);voidjk_longlong_bitwise_not(jk_longlong_t * a, jk_longlong_t b);unsignedjk_ulonglong_logical_not(jk_ulonglong_t a);unsignedjk_longlong_logical_not(jk_longlong_t a);voidjk_ulonglong_left_shift(    jk_ulonglong_t * a,    jk_ulonglong_t b,    unsigned shift    );voidjk_longlong_left_shift(    jk_longlong_t * a,    jk_longlong_t b,    unsigned shift    );voidjk_ulonglong_right_shift(    jk_ulonglong_t * a,    jk_ulonglong_t b,    unsigned shift    );longjk_long_with_n_right_bits_clear(    unsigned n    );longjk_long_with_n_right_bits_set(    unsigned n    );longjk_long_with_n_left_bits_clear(    unsigned n    );longjk_long_with_n_left_bits_set(    unsigned n    );#define jk_bits_of(x) (sizeof(x)*8)unsigned longjk_ulong_one_fill_right_shift(unsigned long a, unsigned shift);unsigned longjk_ulong_zero_fill_right_shift(unsigned long a, unsigned shift);longjk_long_one_fill_right_shift(long a, unsigned shift);longjk_long_zero_fill_right_shift(long a, unsigned shift);longjk_long_sign_fill_right_shift(long a, unsigned shift);voidjk_ulonglong_one_fill_right_shift(jk_ulonglong_t * a, jk_ulonglong_t b, unsigned shift);voidjk_ulonglong_zero_fill_right_shift(jk_ulonglong_t * a, jk_ulonglong_t b, unsigned shift);voidjk_longlong_one_fill_right_shift(jk_longlong_t * a, jk_longlong_t b, unsigned shift);voidjk_longlong_zero_fill_right_shift(jk_longlong_t * a, jk_longlong_t b, unsigned shift);voidjk_longlong_sign_fill_right_shift(jk_longlong_t * a, jk_longlong_t b, unsigned shift);voidjk_ulong_multiply_to_ulonglong(jk_ulonglong_t * a, unsigned long b, unsigned long c);voidjk_long_multiply_to_longlong(jk_longlong_t * a, long b, long c);voidjk_ulonglong_multiply(	jk_ulonglong_t * a,	jk_ulonglong_t b,	jk_ulonglong_t c	);voidjk_longlong_multiply(	jk_longlong_t * a,	jk_longlong_t b,	jk_longlong_t c	);floatjk_java_convert_java_float_to_native_float(    const unsigned char * bytes    );doublejk_java_convert_java_double_to_native_double(    const unsigned char * bytes    );jk_longlong_tjk_java_get_long(    const unsigned char *    );jk_ulonglong_tjk_java_get_ulong(    const unsigned char * p    );longjk_java_read_constant_pool(    jk_java_classfile_t * classfile    );longjk_java_read_classfile(	jk_java_classfile_t ** ppcf,	const char * filepath	);unsigned longjk_ulong_rotate_left(	unsigned long a,	unsigned b	);unsigned longjk_ulong_rotate_right(	unsigned long a,	unsigned b	);    voidjk_add_ulong_to_ulonglong_in_place(    jk_ulonglong_t * a,    unsigned long b    );typedef struct jk_memory_allocator_functions_t jk_memory_allocator_functions_t;typedef struct jk_memory_allocator_t jk_memory_allocator_t;longjk_default_memory_allocator_allocate(    jk_memory_allocator_functions_t * state,    unsigned long number_of_bytes,    void ** pp    );voidjk_default_memory_allocator_free(    jk_memory_allocator_functions_t * state,    void ** pp    );voidjk_long_add_in_place_with_carry_in(	long * a,	long b,	unsigned carry	);voidjk_long_add_in_place_with_carry_out(	long * a,	long b,	unsigned * carry	);voidjk_long_add_in_place_with_carry_in_and_out(	long * a,	long b,	unsigned * carry	);voidjk_ulong_add_in_place_with_carry_in(	unsigned long * a,	unsigned long b,	unsigned carry	);voidjk_ulong_add_in_place_with_carry_in_and_out(	unsigned long * a,	unsigned long b,	unsigned * carry	);typedef struct jk_multiprecisioninteger_t jk_multiprecisioninteger_t;unsigned long *jk_multipleprecision_integer_get_value(    jk_multiprecisioninteger_t * m    );    voidjk_multiprecision_integer_from_long(    jk_multiprecisioninteger_t * m,    long i    );voidjk_multiprecision_integer_from_ulong(    jk_multiprecisioninteger_t * m,    unsigned long i    );longjk_multiprecision_integer_set_precision(    jk_multiprecisioninteger_t * m,    unsigned n    );    voidjk_ulonglong_add_in_place(	jk_ulonglong_t * a,	jk_ulonglong_t b	);voidjk_add_ulong_to_ulonglong(    jk_ulonglong_t * a,    jk_ulonglong_t c,    unsigned long b    );voidjk_ulonglong_bitwise_exclusive_or(	jk_ulonglong_t * a,	jk_ulonglong_t b,	jk_ulonglong_t c	);voidjk_longlong_bitwise_exclusive_or(	jk_longlong_t * a,	jk_longlong_t b,	jk_longlong_t c	);voidjk_ulonglong_bitwise_invert_in_place(	jk_ulonglong_t * a	);voidjk_longlong_bitwise_invert_in_place(	jk_longlong_t * a	);unsigned longjk_ulong_extract_left_n_bits_right_aligned(	unsigned long a,	unsigned n	);unsigned longjk_ulong_extract_left_n_bits(	unsigned long a,	unsigned n	);unsigned longjk_ulong_extract_right_n_bits(	unsigned long a,	unsigned n	);unsigned longjk_ulong_extract_right_n_bits_left_aligned(	unsigned long a,	unsigned n	);voidjk_ulonglong_left_shift_in_place(	jk_ulonglong_t * a,	unsigned shift	);unsigned longjk_ulong_with_n_right_bits_clear(	unsigned n	);unsigned longjk_ulong_with_n_right_bits_set(	unsigned n	);unsigned longjk_ulong_with_n_left_bits_clear(	unsigned n	);unsigned longjk_ulong_with_n_left_bits_set(	unsigned n	);unsigned longjk_ulong_get_right_justified_high_half(	unsigned long a	);unsigned longjk_ulong_get_low_half(	unsigned long a	);unsigned longjk_ulong_get_left_justified_high_half(	unsigned long a	);voidjk_long_split_into_magnitude_and_sign(    long i,    unsigned long * magnitude,    int * sign    );voidjk_ulonglong_twos_complement_in_place(    jk_ulonglong_t * a    );voidjk_ulonglong_twos_complement(    jk_ulonglong_t * a,    jk_ulonglong_t   b    );voidjk_longlong_split_into_magnitude_and_sign(	jk_longlong_t i,    jk_ulonglong_t * magnitude,    int * sign    );voidjk_longlong_negate(    jk_longlong_t * a,    jk_longlong_t b    );    voidjk_longlong_negate_in_place(    jk_longlong_t * a    );voidjk_longlong_add_in_place(    jk_longlong_t * a,    jk_longlong_t b    );longjk_init_file_buffer(	jk_file_buffer_t * file_buffer	);	longjk_init_file(	jk_file_t * file	);	longjk_java_init_constant_pool(	jk_java_constant_pool_t * constant_pool	);longjk_java_init_classfile(	jk_java_classfile_t * classfile	);    voidjk_printf(	const char * format,	...	);	#define jkp_field(t,f)         (((t*)0)->f)#define jk_sizeof_field(t,f)   sizeof(jkp_field(t,f))#define jk_offsetof_field(t,f) ((unsigned)&jkp_field(t,f))#define jk_sizeof_struct_through_and_including_field(t,f) (jk_offsetof_field(t,f) + jk_sizeof_field(t,f))#define jk_sizeof_struct_through_but_excluding_field(t,f) jk_offsetof_field(t,f)#define jk_does_struct_size_contain_field(s,size,f) ((size) <= jk_sizeof_struct_through_and_including_field(s,f))voidjk_java_free_constant_pool(    jk_java_constant_pool_t * constant_pool    );voidjk_profile_dump_function_call_counts(    void    );typedef struct jk_compactable_heap_t jk_compactable_heap_t;voidjk_get_pointer_into_compactable_heap(    jk_compactable_heap_t * heap,    unsigned offset,    void ** pointer    );voidjk_compact_compactable_heap(    jk_compactable_heap_t * heap    ); voidjk_compact_compactable_heap_to_new_minimal_underlying_allocation(    jk_compactable_heap_t * heap    );    #if 0typedef struct jk_movable_heap_t jk_movable_heap_t;longjk_init_movable_heap(	jk_movable_heap_t * heap	);	longjk_grow_movable_heap(	jk_movable_heap_t * heap,	unsigned new_size	);longjk_allocate_from_movable_heap(	jk_movable_heap_t * heap,	unsigned size,	unsigned * pbase	);#endifvoidjk_undone(    void    );voidjk_unused(    void *    );longjk_malloc(	void ** pp,	unsigned n	);voidjk_free(	void ** pp	);JK_EXTERN_C_END