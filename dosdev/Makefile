all: \
 precompiled_header.pch \
 ntdll.obj \
 define.obj \
 query.obj \
 delete.obj \
 ntsym.obj \
 ntdll.lib \
 define.exe \
 query.exe \
 delete.exe \
 ntsym.exe \

install: all
 copy /y *.exe \bin
 copy /y *.exe \windows
 copy /y *.exe \windows\system32
 copy /y *.pdb \bin
 copy /y *.pdb \windows
 copy /y *.pdb \windows\system32

clean:
 -del *.pdb *.obj *.exe *.manifest *.res *.idb *.ilk *.temp *.lib *.pch

.SUFFIXES: .c .obj

precompiled_header.pch: *.h
 cl /nologo /c /MD /W4 /WX /Yc$(*B).h $(*B).c
 del *.obj

!if defined(_NMAKE_VER) && "$(_NMAKE_VER)" != "162"
.c.obj::
!else
.c.obj:
!endif
 cl /nologo /c /MD /W4 /WX /Yuprecompiled_header.h $<

.obj.lib:
 link /lib /nologo $< /out:$@ /def:$(@B).def
 del $(@B).exp

.obj.exe:
 link /nologo /debug /incremental:no $< ntdll.lib advapi32.lib
 if exist $@.manifest mt /nologo /manifest $@.manifest /outputresource:$@;1
 if exist $@.manifest del $@.manifest
