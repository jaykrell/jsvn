import os
import os.path
import os
from os.path import join, getsize
import re

re1 = re.compile("(^.+)-0[0-9][0-9](\.(?:zip|tgz|txt|README|txt~))$")

for Root, Dirs, Files in os.walk("."):
    for Name in Files:
        Match = re1.search(Name)
        if Match:
            print(Name)
            Name0 = Match.group(1) + Match.group(2)
            Path = os.path.join(Root, Name)
            Path0 = os.path.join(Root, Name0)
            if Name0 in Files:
                Contents0 = file(Path0).read()
                Contents = file(Path).read()
                if Contents0 == Contents:
                    os.system("fc " + Path + " " + Path0)
                    print("del " + Path)
                    os.unlink(Path)
                else:
                    print("rem " + Path0)
            else:
                print("ren " + Path + " " + Name0)
                os.rename(Path, Path0)
