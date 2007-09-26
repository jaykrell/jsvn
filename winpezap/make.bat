rem for Open Watcom

del winpezap.exe
del winpezap.obj
del winpezap.dos
wcl winpezap.c
del winpezap.obj
ren winpezap.exe winpezap.dos
wcl386 winpezap.c -"option stub=winpezap.dos"
