rem for Open Watcom

del jcopy.exe
del jcopy.obj
del jcopy.dos
wcl jcopy.c
del jcopy.obj
ren jcopy.exe jcopy.dos
wcl386 jcopy.c -"option stub=jcopy.dos"
