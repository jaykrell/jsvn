del 2>nul ^
critsecexe.exe ^
critsecdll.lib ^
critsecdll.obj ^
critsecexe.obj ^
critsecdll.dll.manifest ^
critsecexe.exe.manifest ^
critsecdll.exp ^
critsecdll.dll

cl /MD /LD /W4 /WX critsecdll.c critsecdll.def
cl /MD /W4 /WX critsecexe.c critsecdll.lib

del 2>nul ^
critsecdll.lib ^
critsecdll.obj ^
critsecexe.obj ^
critsecdll.dll.manifest ^
critsecdll.exp ^
