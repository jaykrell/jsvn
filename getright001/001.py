import os
import os.path
import os
from os.path import join, getsize
import re

re1 = re.compile("-[0-9][0-9][0-9].zip$")

for root, dirs, files in os.walk("."):
    for name in files:
        if re1.search(name):
            name0 = name[:len(name) - 8] + ".zip"
            if name0 in files:
                name = os.path.join(root, name)
                name0 = os.path.join(root, name0)
                contents0 = file(name0).read()
                contents = file(name).read()
                if contents0 == contents:
                    os.system("fc " + name + " " + name0)
                    print("del " + name)
                    os.unlink(name)
                else:
                    print("rem " + name0)
