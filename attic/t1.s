.data
.cstring
	.align 2
LC0:
	.ascii "%d\12\0"
.text
	.align 2
	.globl _main
_main:
LFB1:
	mflr r0
	stmw r28,-16(r1)
LCFI0:
	stw r0,8(r1)
LCFI1:
	stwu r1,-96(r1)
LCFI2:
	mr r30,r1
LCFI3:
	bcl 20,31,L1$pb
L1$pb:
	mflr r31
	li r3,4
	bl L___cxa_allocate_exception$stub
	mr r9,r3
	li r0,1
	stw r0,0(r9)
	mr r3,r9
	addis r9,r31,ha16(L__ZTIi$non_lazy_ptr-L1$pb)
	lwz r4,lo16(L__ZTIi$non_lazy_ptr-L1$pb)(r9)
	li r5,0
LEHB0:
	bl L___cxa_throw$stub
LEHE0:
L29:
	stw r3,68(r30)
	lwz r3,68(r30)
	bl L___cxa_begin_catch$stub
	li r3,4
	bl L___cxa_allocate_exception$stub
	mr r9,r3
	li r0,2
	stw r0,0(r9)
	mr r3,r9
	addis r9,r31,ha16(L__ZTIi$non_lazy_ptr-L1$pb)
	lwz r4,lo16(L__ZTIi$non_lazy_ptr-L1$pb)(r9)
	li r5,0
LEHB1:
	bl L___cxa_throw$stub
LEHE1:
L27:
	stw r3,68(r30)
	lwz r3,68(r30)
	bl L___cxa_begin_catch$stub
LEHB2:
	bl L___cxa_end_catch$stub
	bl L___cxa_rethrow$stub
LEHE2:
L28:
	stw r3,68(r30)
	stw r4,72(r30)
	lwz r29,68(r30)
	lwz r28,72(r30)
	bl L___cxa_end_catch$stub
	stw r29,68(r30)
	stw r28,72(r30)
L30:
	lwz r0,72(r30)
	cmpwi cr0,r0,1
	beq cr0,L19
	lwz r3,68(r30)
LEHB3:
	bl L__Unwind_Resume$stub
LEHE3:
L19:
	lwz r3,68(r30)
	bl L___cxa_begin_catch$stub
	mr r9,r3
	lwz r0,0(r9)
	stw r0,64(r30)
	addis r3,r31,ha16(LC0-L1$pb)
	la r3,lo16(LC0-L1$pb)(r3)
	lwz r4,64(r30)
	bl L_printf$stub
	bl L___cxa_end_catch$stub
	li r0,0
	mr r3,r0
	lwz r1,0(r1)
	lwz r0,8(r1)
	mtlr r0
	lmw r28,-16(r1)
	blr
LFE1:
.data
.section __DATA,__gcc_except_tab
	.align 2
LLSDA1:
	.byte	0xff
	.byte	0x0
	.byte	0x45
	.byte	0x3
	.byte	0x34
	.set L$set$0,LEHB0-LFB1
	.long L$set$0
	.set L$set$1,LEHE0-LEHB0
	.long L$set$1
	.set L$set$2,L29-LFB1
	.long L$set$2
	.byte	0x1
	.set L$set$3,LEHB1-LFB1
	.long L$set$3
	.set L$set$4,LEHE1-LEHB1
	.long L$set$4
	.set L$set$5,L27-LFB1
	.long L$set$5
	.byte	0x1
	.set L$set$6,LEHB2-LFB1
	.long L$set$6
	.set L$set$7,LEHE2-LEHB2
	.long L$set$7
	.set L$set$8,L28-LFB1
	.long L$set$8
	.byte	0x5
	.set L$set$9,LEHB3-LFB1
	.long L$set$9
	.set L$set$10,LEHE3-LEHB3
	.long L$set$10
	.long	0x0
	.byte	0x0
	.byte	0x2
	.byte	0x0
	.byte	0x1
	.byte	0x0
	.byte	0x0
	.byte	0x7d
	.align 2
	.long	0
	.long	__ZTIi
.text
.data
.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms
_EH_unwind_info:
Lframe1:
	.set L$set$11,LECIE1-LSCIE1
	.long L$set$11
LSCIE1:
	.long	0x0
	.byte	0x1
	.ascii "zPLR\0"
	.byte	0x1
	.byte	0x7c
	.byte	0x41
	.byte	0x7
	.byte	0x90
	.long	L___gxx_personality_v0$non_lazy_ptr-.
	.byte	0x10
	.byte	0x10
	.byte	0xc
	.byte	0x1
	.byte	0x0
	.align 2
LECIE1:
.globl main.eh
main.eh:
LSFDE1:
	.set L$set$12,LEFDE1-LASFDE1
	.long L$set$12
LASFDE1:
	.long	LASFDE1-Lframe1
	.long	LFB1-.
	.set L$set$13,LFE1-LFB1
	.long L$set$13
	.byte	0x4
	.long	LLSDA1-.
	.byte	0x4
	.set L$set$14,LCFI2-LFB1
	.long L$set$14
	.byte	0xe
	.byte	0x60
	.byte	0x11
	.byte	0x41
	.byte	0x7e
	.byte	0x9f
	.byte	0x1
	.byte	0x9e
	.byte	0x2
	.byte	0x9d
	.byte	0x3
	.byte	0x9c
	.byte	0x4
	.byte	0x4
	.set L$set$15,LCFI3-LCFI2
	.long L$set$15
	.byte	0xd
	.byte	0x1e
	.align 2
LEFDE1:
.data
.picsymbol_stub
L__Unwind_Resume$stub:
	.indirect_symbol __Unwind_Resume
	mflr r0
	bcl 20,31,L0$__Unwind_Resume
L0$__Unwind_Resume:
	mflr r11
	addis r11,r11,ha16(L__Unwind_Resume$lazy_ptr-L0$__Unwind_Resume)
	mtlr r0
	lwz r12,lo16(L__Unwind_Resume$lazy_ptr-L0$__Unwind_Resume)(r11)
	mtctr r12
	addi r11,r11,lo16(L__Unwind_Resume$lazy_ptr-L0$__Unwind_Resume)
	bctr
.data
.lazy_symbol_pointer
L__Unwind_Resume$lazy_ptr:
	.indirect_symbol __Unwind_Resume
	.long dyld_stub_binding_helper
.data
.picsymbol_stub
L_printf$stub:
	.indirect_symbol _printf
	mflr r0
	bcl 20,31,L0$_printf
L0$_printf:
	mflr r11
	addis r11,r11,ha16(L_printf$lazy_ptr-L0$_printf)
	mtlr r0
	lwz r12,lo16(L_printf$lazy_ptr-L0$_printf)(r11)
	mtctr r12
	addi r11,r11,lo16(L_printf$lazy_ptr-L0$_printf)
	bctr
.data
.lazy_symbol_pointer
L_printf$lazy_ptr:
	.indirect_symbol _printf
	.long dyld_stub_binding_helper
.data
.picsymbol_stub
L___cxa_rethrow$stub:
	.indirect_symbol ___cxa_rethrow
	mflr r0
	bcl 20,31,L0$___cxa_rethrow
L0$___cxa_rethrow:
	mflr r11
	addis r11,r11,ha16(L___cxa_rethrow$lazy_ptr-L0$___cxa_rethrow)
	mtlr r0
	lwz r12,lo16(L___cxa_rethrow$lazy_ptr-L0$___cxa_rethrow)(r11)
	mtctr r12
	addi r11,r11,lo16(L___cxa_rethrow$lazy_ptr-L0$___cxa_rethrow)
	bctr
.data
.lazy_symbol_pointer
L___cxa_rethrow$lazy_ptr:
	.indirect_symbol ___cxa_rethrow
	.long dyld_stub_binding_helper
.data
.picsymbol_stub
L___cxa_end_catch$stub:
	.indirect_symbol ___cxa_end_catch
	mflr r0
	bcl 20,31,L0$___cxa_end_catch
L0$___cxa_end_catch:
	mflr r11
	addis r11,r11,ha16(L___cxa_end_catch$lazy_ptr-L0$___cxa_end_catch)
	mtlr r0
	lwz r12,lo16(L___cxa_end_catch$lazy_ptr-L0$___cxa_end_catch)(r11)
	mtctr r12
	addi r11,r11,lo16(L___cxa_end_catch$lazy_ptr-L0$___cxa_end_catch)
	bctr
.data
.lazy_symbol_pointer
L___cxa_end_catch$lazy_ptr:
	.indirect_symbol ___cxa_end_catch
	.long dyld_stub_binding_helper
.data
.picsymbol_stub
L___cxa_begin_catch$stub:
	.indirect_symbol ___cxa_begin_catch
	mflr r0
	bcl 20,31,L0$___cxa_begin_catch
L0$___cxa_begin_catch:
	mflr r11
	addis r11,r11,ha16(L___cxa_begin_catch$lazy_ptr-L0$___cxa_begin_catch)
	mtlr r0
	lwz r12,lo16(L___cxa_begin_catch$lazy_ptr-L0$___cxa_begin_catch)(r11)
	mtctr r12
	addi r11,r11,lo16(L___cxa_begin_catch$lazy_ptr-L0$___cxa_begin_catch)
	bctr
.data
.lazy_symbol_pointer
L___cxa_begin_catch$lazy_ptr:
	.indirect_symbol ___cxa_begin_catch
	.long dyld_stub_binding_helper
.data
.picsymbol_stub
L___cxa_throw$stub:
	.indirect_symbol ___cxa_throw
	mflr r0
	bcl 20,31,L0$___cxa_throw
L0$___cxa_throw:
	mflr r11
	addis r11,r11,ha16(L___cxa_throw$lazy_ptr-L0$___cxa_throw)
	mtlr r0
	lwz r12,lo16(L___cxa_throw$lazy_ptr-L0$___cxa_throw)(r11)
	mtctr r12
	addi r11,r11,lo16(L___cxa_throw$lazy_ptr-L0$___cxa_throw)
	bctr
.data
.lazy_symbol_pointer
L___cxa_throw$lazy_ptr:
	.indirect_symbol ___cxa_throw
	.long dyld_stub_binding_helper
.data
.picsymbol_stub
L___cxa_allocate_exception$stub:
	.indirect_symbol ___cxa_allocate_exception
	mflr r0
	bcl 20,31,L0$___cxa_allocate_exception
L0$___cxa_allocate_exception:
	mflr r11
	addis r11,r11,ha16(L___cxa_allocate_exception$lazy_ptr-L0$___cxa_allocate_exception)
	mtlr r0
	lwz r12,lo16(L___cxa_allocate_exception$lazy_ptr-L0$___cxa_allocate_exception)(r11)
	mtctr r12
	addi r11,r11,lo16(L___cxa_allocate_exception$lazy_ptr-L0$___cxa_allocate_exception)
	bctr
.data
.lazy_symbol_pointer
L___cxa_allocate_exception$lazy_ptr:
	.indirect_symbol ___cxa_allocate_exception
	.long dyld_stub_binding_helper
.data
.non_lazy_symbol_pointer
L___gxx_personality_v0$non_lazy_ptr:
	.indirect_symbol ___gxx_personality_v0
	.long	0
L__ZTIi$non_lazy_ptr:
	.indirect_symbol __ZTIi
	.long	0
.data
.constructor
.data
.destructor
	.align 1
