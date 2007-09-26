TARGETNAME=fileids
TARGETEXT=exe
TARGET=$(TARGETNAME).$(TARGETEXT)

.SUFFIXES: .cpp .exe

all: $(TARGETNAME).exe

clean:
 -del *.obj *.pdb *.ilk $(TARGET) $(TARGET).manifest $(TARGETNAME).pdb 2>nul

.cpp.exe:
 -del *.obj *.pdb *.ilk $(TARGET) $(TARGET).manifest $(TARGETNAME).pdb 2>nul
 cl /MD /Z7 /GX $< /link /incremental:no
