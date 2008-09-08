#
# cygwin2.dll -- renamed cygwin1.dll
# cygwin3.dll -- pure forwarder .dll to cygwin2.dll
#  with every function prepended with "cygwin3_"
# cygwin1.dll -- implements fork/vfork/exec, and links to cygwin3.dll
#
#

import subprocess
import string
import re
import sys
import os

re1 = re.compile("^\\s+\\d+\\s+[0-9a-fA-F]+\\s+[0-9a-fA-F]+\\s+(\\S+)\\s*$")
re2 = re.compile("^([^@]+)@(\\d+)$")
re3 = re.compile("^\\s+\\d+\\s+[0-9a-fA-F]+\\s+(\\S+) \\([0-9a-fA-F]+\\)\\s*$")
re4 = None

start = False

cygwin1def = file("cygwin1.def", "w")
cygwin2def = file("cygwin2.def", "w")
cygwin3def = file("cygwin3.def", "w")
cygwin1c = file("cygwin1.c", "w")
cygwin2c = file("cygwin2.c", "w")
cygwin3c = file("cygwin3.c", "w")

cygwin1c.write("""
__declspec(dllimport) int __stdcall IsDebuggerPresent(void);
__declspec(dllimport) void __stdcall DebugBreak(void);
__declspec(dllimport) void __stdcall OutputDebugStringA(const char*);

static void Hook(const char* a)
{
    if (IsDebuggerPresent())
        OutputDebugStringA(a);
    /* fprintf(stderr, \"hook: %s\\n\", a); */
}
""")

cygwin1def.write("EXPORTS\n")
cygwin2def.write("EXPORTS\n")
cygwin3def.write("EXPORTS\n")
cygwin2c.write("void __cdecl F(void) { }\n")
cygwin3c.write("void __cdecl F(void) { }\n")

myfunctions = dict().fromkeys(map(lambda a: a.rstrip(), file("functions.txt").readlines()))
#print("'" + myfunctions.keys()[1] + "'")
#sys.exit(1)

def IsHookable(a):
    return False
    return (((a.find("exec") != -1)
    or (a.find("spawn") != -1)
    or (a.find("read") != -1)
    or (a.find("get") != -1)
    or (a.find("write") != -1)
    or (a.find("open") != -1)
    or (a.find("fork") != -1)
    or True)
    and ((a.find("cyg") == -1)
        and (a.find("arg") == -1)
        and (a.find("ctype") == -1)
        and (a.find("print") == -1)
        and (a.find("errno") == -1)
        and (a.find("mb_cur_max") == -1)
        and (a.find("dlfork") == -1)
        and (a.find("dlopen") == -1)
        and (a.find("getc") == -1)
        and (a.find("alloca") == -1)
        and (a.find("setjmp") == -1)
        and (a.find("longjump") == -1)
        and (a.find("memset") == -1)
        and (a.find("dll_entry") == -1)
        and (a.find("dll_crt") == -1)
        and (a.find("fork") == -1)
        and (a.find("main") == -1)
        and (a.find("nan") == -1)
        and (a.find("progname") == -1)
        and (a.find("malloc") == -1) # noisy
        and (a.find("strlen") == -1) # noisy
        and (a.find("mbrlen") == -1) # noisy
        and (a.find("strchr") == -1) # noisy
        and (a.find("memcpy") == -1) # noisy
        and (a.find("putchar") == -1) # noisy
        and (a.find("strcpy") == -1) # noisy
        and (a.find("strcmp") == -1) # noisy
        and (a.find("strcoll") == -1) # noisy
        and (a.find("strdup") == -1) # noisy
        and (a.find("free") == -1) # noisy
        and (a.find("realloc") == -1) # noisy
        and (a.find("readdir") == -1) # noisy
        and (a.find("impure_ptr") == -1)
        and (a.find("_opt") == -1)
        and (a.find("opt") != 0)
        ))

realcygwindll = "\\cygwin\\bin\\cygwin1.dll"
realcygwindll = "\\cygwin.1\\bin\\cygwin2.dll"
realcygwindll = "\\cygwin\\bin\\cygwin2.dll"
if os.name == "posix":
    realcygwindll = realcygwindll.replace("\\", "\\\\")
command = "link -dump -exports " + realcygwindll

print(command)
lines = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE).stdout.readlines()
for line in lines:
    line = re.sub("  +", " ", line)
    line = re.sub(" = .+$", "", line)
    if not start:
        if line.lower().find("ordinal hint RVA name".lower()) != -1:
            start = True
            re4 = re1
        if line.lower().find("ordinal hint name".lower()) != -1:
            start = True
            re4 = re3
        #print("2:" + line)
        continue
    m = re4.match(line)
    if not m:
        #print("1:" + line)
        continue
    function = m.group(1)
    #print("'" + function + "'")
    #continue
    #sys.exit(1)

    cygwin3def.write(" cygwin3_" + function + " = cygwin2." + function + "\n")

    convention = "__cdecl"
    name = function
    signature = "void"
    if function.find("@") == -1:
        #cygwin2c.write("void " + convention + " " + name + "(" + signature + ") { }\n")
        cygwin2def.write(" " + name + " = F\n")

    else:
        convention = "__stdcall"
        m = re2.match(name)
        name = m.group(1)
        bytes = int(m.group(2))
        if bytes == 0:
            signature = "void"
        else:
            signature = ""
            while bytes != 0:
                signature += "int a" + str(bytes)
                bytes -= 4
                if bytes != 0:
                    signature += ","
        cygwin2def.write(" " + function + " = F\n")

    if function in myfunctions:
        continue

    if not IsHookable(function):
        cygwin1c.write("/* skipping " + function + "*/\n")
        cygwin1def.write(" " + function + " = cygwin3.cygwin3_" + function + " PRIVATE\n")
    else:
        cygwin1def.write(" " + function + " PRIVATE\n")
        cygwin1c.write("void* " + convention + " cygwin3_" + name + "(" + signature + ");\n")
        cygwin1c.write(""
+ "__declspec(naked) void* " + convention + " " + name + "(" + signature + ")\n"
+ "{\n"
+ "    Hook(\"" + name + "\\n\");\n"
+ "    __asm jmp cygwin3_" + name + "\n"
+ "}\n"
);
