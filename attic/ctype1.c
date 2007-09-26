#include <stdio.h>
#include <ctype.h>
int
main(
	)
{
	int ch;
	int i = 0;
	int pass = 0;
	for (pass = 0 ; pass != 3 ; ++pass)
	{
		for (ch = -128 ; ch != 256 ; ++ch)
		{
			if (ch >= 'A' && ch <= 'Z')
			{
				if (pass == 0)
					i += printf("case /*%c*/0x%x:", ch, ch & 0xff);
			}
			else if (ch >= 'a' && ch <= 'z')
			{
				if (pass == 1)
					i += printf("case /*%c*/0x%x:", ch, ch & 0xff);
			}
			else
			{
				if (pass == 2)
					if (isprint(ch))
						i += printf("case /*%c*/0x%x:", ch, ch & 0xff);
					else
						i += printf("case 0x%x:", ch & 0xff);
			}
			if (i > 90)
			{
				i = 0;
				printf("\n");
			}
		}
	}
	printf("\n");
	return 0;
}

