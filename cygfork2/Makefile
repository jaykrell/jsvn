
all: cygwin1.dll cygwin3.dll 2.exe fork.obj

.c.obj:
    cl -c -MD -Z7 -Zl -GS- $<

2.exe: cygwin1.lib 2.c
    -del cygwin1.ilk cygwin1.dll.1
    move cygwin1.dll cygwin1.dll.1
    gcc 2.c -o $@
    move cygwin1.dll.1 cygwin1.dll

cygwin1.c cygwin1.def cygwin2.def cygwin2.c cygwin3.def: functions.txt make.py
    python make.py

clean:
    -del \
        a.exe \
        cygwin1.c \
        cygwin2.c \
        cygwin3.c \
        fork.exe \
        forkmain.exe \
        *.def \
        *.dll \
        *.exp \
        *.ilk \
        *.manifest \
        *.map \
        *.lib \
        *.obj \
        *.pdb \
        *.stackdump \
        2.o \
        2.exe \
        3.exe \
        tls.exe \
        cygwin1.c \
        cygwin2.c \
        cygwin3.c \
        cygwin1.def \
        cygwin2.def \
        cygwin3.def \


cygwin2.lib: cygwin2.def cygwin2.obj
    link -lib @<<
-def:$**
-out:$@
<<

cygwin1.exp cygwin1.lib: cygwin1.def cygwin1.obj fork.obj cygwin3.lib
    link -lib @<<
-def:$**
-out:cygwin1.lib
<<

cygwin3.exp cygwin3.lib: cygwin3.def cygwin2.lib
    link -lib @<<
-def:$**
-out:cygwin3.lib
<<

cygwin3.dll: cygwin2.lib cygwin3.lib cygwin3.exp
    link @<<
-debug
$**
-nod
-out:$@
-noentry
-dll
kernel32.lib
<<

cygwin1.dll: cygwin1.obj fork.obj cygwin3.lib cygwin1.lib cygwin1.exp
    link @<<
-debug
$**
-nod
-out:$@
-noentry
-dll
kernel32.lib
ntdll.lib
<<
