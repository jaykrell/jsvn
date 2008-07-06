import os
import os.path
import os
from os.path import join, getsize
import re

re1 = re.compile("(^.+)-[0-9][0-9][0-9](\.(?:zip|tgz|txt|README|txt~))$")

for root, dirs, files in os.walk("."):
    for name in files:
        match = re1.search(name)
        if match:
            name0 = match.group(1) + match.group(2)
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
