import subprocess
import string
import re
import sys

re1 = re.compile("^\\s+\\d+\\s+[0-9a-fA-F]+\\s+[0-9a-fA-F]+\\s+(\\S+)")
re2 = re.compile("^([^@]+)@(\\d+)$")

start = False

cygwin1def = file("cygwin1.def", "w")
cygwin2def = file("cygwin2.def", "w")
cygwin2c = file("cygwin2.c", "w")

cygwin1def.write("EXPORTS\n")
#cygwin1def.write(" fork\n vfork = fork\n _fork = fork\n _vfork = fork\n")
cygwin2def.write("EXPORTS\n")
cygwin2c.write("void __cdecl F(void) { }\n")

myfunctions = dict().fromkeys(map(lambda a: a.rstrip(), file("functions.txt").readlines()))
#print("'" + myfunctions.keys()[1] + "'")
#sys.exit(1)

for line in subprocess.Popen("link -dump -exports \\\\cygwin\\\\\\bin\\\\cygwin1.dll", shell=True, stdout=subprocess.PIPE).stdout.readlines():
    line = re.sub("  +", " ", line)
    if not start:
        if line.lower().find("ordinal hint RVA name".lower()) == -1:
            start = True
            continue
    m = re1.match(line)
    if not m:
        continue
    function = m.group(1)
    #print("'" + function + "'")
    #sys.exit(1)
    if function in myfunctions:
        #print(function)
        #sys.exit(1)
        cygwin1def.write(" cyg" + function + " = cygwin2." + function + "\n")
        continue
    convention = "__cdecl"
    name = function
    signature = "void"
    if function.find("@") == -1:
        #cygwin2c.write("__declspec(dllexport) void " + convention + " " + name + "(" + signature + ") { }\n")
        cygwin1def.write(" " + function + " = cygwin2." + function + "\n")
        cygwin2def.write(" " + name + " = F\n")
        continue
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
    #cygwin2c.write("__declspec(dllexport) void " + convention + " " + name + "(" + signature + ") { }\n")
    cygwin1def.write(" " + function + " = cygwin2." + function + "\n")
    cygwin2def.write(" " + function + " =  F\n")
