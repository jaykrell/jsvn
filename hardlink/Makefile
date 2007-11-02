.SUFFIXES: .c .cpp .exe

all: hardlink.exe

install: all
 copy /y *.exe \bin
 copy /y *.exe \windows
 copy /y *.exe \windows\system32
 copy /y *.pdb \bin
 copy /y *.pdb \windows
 copy /y *.pdb \windows\system32

clean:
 del hardlink.exe.manifest vc*pdb hardlink.exe *.obj *.pdb *.opt *.ncb *.map *.dsp *.dsw

.cpp.exe:
 cl /DDYNAMIC_LINK_CREATEHARDLINK /MD /Z7 /GX $< /link /incremental:no /entry:Entry /subsystem:console shell32.lib kernel32.lib msvcrt.lib /opt:ref /nod /merge:.rdata=.text
 if exist $@.manifest mt /nologo /manifest $@.manifest /outputresource:$@;1
 if exist $@.manifest del $@.manifest

.c.exe:
 cl /DDYNAMIC_LINK_CREATEHARDLINK /MD /Z7 /GX $< /link /incremental:no /entry:Entry /subsystem:console shell32.lib kernel32.lib msvcrt.lib /opt:ref /nod /merge:.rdata=.text
 if exist $@.manifest mt /nologo /manifest $@.manifest /outputresource:$@;1
 if exist $@.manifest del $@.manifest
