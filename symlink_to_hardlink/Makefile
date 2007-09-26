.SUFFIXES: .cpp .exe

all: symlink_to_hardlink.exe

.cpp.exe:
 cl /MT /Z7 /GX $< /link /incremental:no
