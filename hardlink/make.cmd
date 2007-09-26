cl /DDYNAMIC_LINK_CREATEHARDLINK /MT /Z7 /GX hardlink.c /link /incremental:no /entry:Entry /subsystem:console shell32.lib kernel32.lib msvcrt.lib /opt:ref /nod /merge:.rdata=.text
