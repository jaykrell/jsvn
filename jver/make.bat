rem for Open Watcom

del jver.exe
del jver.obj
del jver.dos
wcl jver.c
del jver.obj
ren jver.exe jver.dos
wcl386 jver.c -"option stub=jver.dos"
