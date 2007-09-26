!include configure.make

TARGETNAME=hardlink_identical_files
TARGETEXT=exe
TARGET=$(TARGETNAME).$(TARGETEXT)

all: $(TARGETNAME).exe
    
clean:
    -del _configure* 2>nul
    -del *.obj *.pdb *.ilk $(TARGET) $(TARGET).manifest none 2>nul

$(TARGETNAME).exe : $(TARGETNAME).obj

$(TARGETNAME).obj : $(TARGETNAME).cpp _configure* Makefile
    -del $@ *.pdb 2>nul
    cl /c /MD /W4 /WX /Z7 \
!if $(CL_SUPPORTS_GX) 
        /GX \
!else
        /EHsc \
!endif
        $(TARGETNAME).cpp \

$(TARGET) : $(TARGETNAME).obj _configure* Makefile
    -del $@ $(@R).pdb $@.manifest $(@R).ilk none 2>nul

    link \
        $(TARGETNAME).obj \
		msvcrt.lib \
        /incremental:no \
        $(LINK_OPT_ICF) \
        $(LINK_PDB_NONE) \
        $(LINK_PDBPATH_NONE) \
        /debug \

    if exist none ren none $(@R).pdb
