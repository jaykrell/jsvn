!include configure.make

TARGETNAME=hardlink_identical_files2
TARGETEXT=exe
TARGET=$(TARGETNAME).$(TARGETEXT)

all: $(TARGETNAME).exe
    
clean:
    -del _configure* *.obj *.pdb *.ilk *.exe *.exe.manifest none 2>nul

install: all
 copy /y *.exe \bin
 copy /y *.exe \windows
 copy /y *.exe \windows\system32
 copy /y *.pdb \bin
 copy /y *.pdb \windows
 copy /y *.pdb \windows\system32

$(TARGETNAME).exe : hardlink_identical_files.obj

hardlink_identical_files.obj : hardlink_identical_files.cpp _configure* Makefile
    -del $@ *.pdb 2>nul
    cl /c /MT /W4 /WX /Z7 \
!if $(CL_SUPPORTS_GX) 
        /GX \
!else
        /EHsc \
!endif
        hardlink_identical_files.cpp \

$(TARGET) : hardlink_identical_files.obj _configure* Makefile
    -del $@ $(@R).pdb $@.manifest $(@R).ilk none 2>nul
    link \
        hardlink_identical_files.obj \
        /incremental:no \
        $(LINK_OPT_ICF) \
        $(LINK_PDB_NONE) \
        $(LINK_PDBPATH_NONE) \
        /debug \
        /out:$@
    if exist $@.manifest mt /nologo /manifest $@.manifest /outputresource:$@;1
    if exist $@.manifest del $@.manifest
    if exist none ren none $(@R).pdb
