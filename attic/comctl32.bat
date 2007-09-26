@REM
@REM JayKrell
@REM May 15, 2004
@REM Make comctl32.lib for use with cm3
@REM  using http://msdn.microsoft.com/visualc/vctoolkit2003/.
@REM

call :clean

echo>>comctl32.def EXPORTS
echo>>comctl32.def  ImageList_ReplaceIcon
echo>>comctl32.def  ImageList_Remove
echo>>comctl32.def  ImageList_GetIcon
echo>>comctl32.def  ImageList_LoadImageA

echo>>comctl32.c void __stdcall ImageList_ReplaceIcon(int a,int b,int c) { }
echo>>comctl32.c void __stdcall ImageList_Remove(int a,int b) { }
echo>>comctl32.c void __stdcall ImageList_GetIcon(int a,int b,int c) { }
echo>>comctl32.c void __stdcall ImageList_LoadImageA(int a,int b,int c,int d,int e,int f,int g) { }

cl -nologo -LD comctl32.c -link -noentry -nod -def:comctl32.def

call :my_del \cm3\lib\comctl32.lib
copy comctl32.lib \cm3\lib

call :clean

goto :end

:clean
call :my_del comctl32.c comctl32.def comctl32.lib comctl32.obj comctl32.dll comctl32.exp
goto :end

:my_del
if (%1) == () goto :end
if exist %1 del %1
shift
goto :my_del

:end
