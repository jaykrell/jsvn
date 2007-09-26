rem for Open Watcom

del hexdump.exe
del hexdump.obj
del hexdump.dos
wcl hexdump.c
del hexdump.obj
ren hexdump.exe hexdump.dos
wcl386 hexdump.c -"option stub=hexdump.dos"
