@echo off

setlocal

del imagehlp.def
echo LIBRARY imagehlp > imagehlp.def
echo EXPORTS >> imagehlp.def
for /f "tokens=1,2" %%a in (imagehlp.txt) do  echo  _%%a@%%b = %%a >> imagehlp.def
implib imagehlp.lib imagehlp.def
rem del imagehlp.def
goto :eof
