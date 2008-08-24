.c.obj::
    cl -c -O1 -MD -Zi $<

all: cygwin1.dll fork.exe

fork.exe: cygwin1.lib fork.c
 cl -MD -Zi -DMAIN fork.c cygwin1.lib kernel32.lib

cygwin1.def cygwin2.def cygwin2.c: functions.txt make.py
    python make.py

clean:
    del *.obj *.lib *.def cygwin2.c *.pdb *.manifest *.exp *.dll *.stackdump

cygwin2.lib: cygwin2.def cygwin2.obj
    link -lib @<<
-def:$**
-out:$@
<<

cygwin1.exp cygwin1.lib: cygwin1.def fork.obj cygwin2.lib
    link -lib @<<
-def:$**
-out:cygwin1.lib
<<

cygwin1.dll: fork.obj cygwin2.lib cygwin1.lib cygwin1.exp
    link @<<
-debug
$**
-out:$@
-noentry
-dll
-opt:ref,icf
kernel32.lib
<<
