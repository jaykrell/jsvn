rem for Open Watcom

del jsize.exe
del jsize.obj
del jsize.dos
wcl jsize.c
del jsize.obj
ren jsize.exe jsize.dos
wcl386 jsize.c -"option stub=jsize.dos"
