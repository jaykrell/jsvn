
# -I /System/Library/Frameworks/ApplicationServices.framework/Headers  \
# -I /System/Library/Frameworks/ApplicationServices.framework/Frameworks/QD.framework/Headers \
# -I /System/Library/Frameworks/ApplicationServices.framework/Frameworks/CoreGraphics.framework/Headers \

!ifdef WINDIR

all: \
 j.lib \

clean:
 -del *.pdb *.obj *.exe *.manifest *.res *.idb *.ilk *.temp *.lib *.pch

j.lib: \
 j_win.obj \
 j.obj \
 j_errno.obj \
 j_malloc.obj \
 j_stdio.obj \

 link /lib $** /out:$@

!if defined(_NMAKE_VER) && "$(_NMAKE_VER)" != "162"
.c.obj::
!else
.c.obj:
!endif
 cl /nologo /c /MD /W4 /WX $<

!else

cc=cc
nul=/dev/null

.c.o:
	$(cc) -g -c -I /Developer/Headers/FlatCarbon $<

.c.S:
	$(cc) -S -c -I /Developer/Headers/FlatCarbon $<
 
j: \
 j_errno.o \
 j_macos.o \
 j_macosx.o \
 j_malloc.o  \
 j_stdio.o \
 j.o
	$(cc) \
		j_errno.o \
		j_macos.o \
		j_macosx.o \
		j_malloc.o \
		j_stdio.o \
		j.o \
		/System/Library/Frameworks/ApplicationServices.framework/ApplicationServices \
	-o j

clean: clean1

clean1:
	-rm 2>$(nul) \
		j_errno.o \
		j_macos.o \
		j_macosx.o \
		j_malloc.o \
		j_stdio.o \
		j.o \
		j

clean2: clean1
	-rm 2>$(nul) \
		j.tar \
		j.tar.gz \

j.tar:
	tar cf j.tar \
		Makefile \
		j_errno.c \
		j_macos.c \
		j_macosx.c \
		j_malloc.c \
		j_stdio.c \
		j.c \
		j.h \

j.tar.gz: j.tar
	gzip j.tar

!endif
