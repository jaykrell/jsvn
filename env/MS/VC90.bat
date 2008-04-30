@call %SystemDrive%\dev2\j\env\clearenv

@echo on

set VS90COMNTOOLS=%SystemDrive%\msdev\90\Common7\Tools\
call %SystemDrive%\msdev\90\VC\vcvarsall.bat x86

@rem reset errorlevel
@dir > nul

@Title VC90
