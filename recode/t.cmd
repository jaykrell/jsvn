

mkdir t\1
mkdir t\2
echo > t\1\3
echo > t\1\4
echo > t\2\5
echo > t\2\6
copy %windir%\system32\kernel32.dll t
copy %windir%\system32\shell32.dll t\1
copy %windir%\system32\user32.dll t\2

del *.tar.gz
del *.tar.bz2
del *.tgz
del *.tbz
del *.zip

zip -rDX t1.zip t
tar vcfj t2.tbz t
tar vcfz t3.tgz t
tar vcfz t4.tar.gz t
tar vcfj t5.tar.bz2 t
