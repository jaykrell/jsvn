rem for Open Watcom

del jcompare.exe
del jcompare.obj
del jcompare.dos
wcl jcompare.c
del jcompare.obj
ren jcompare.exe jcompare.dos
wcl386 jcompare.c -"option stub=jcompare.dos"
