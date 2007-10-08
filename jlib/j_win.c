#include "j.h"
#include <windows.h>

long
jk_getlastwin32error(
	void
	)
{
	long e = GetLastError();
	if (e == 0)
		e = 1;
	else if (e > 0)
		e = -e;
	return e;
}

long
jk_win_get_main_display(
	jk_display_t* d
	)
{
	long er = 0;
	HDC hdcProvider = NULL;
	
	hdcProvider = DCIOpenProvider();
	if (hdcProvider == NULL)
		goto Exit;

Exit:
	if (er != 0)
	{
		if (hdcProvider != NULL)
		{
			DCICloseProvider(hdcProvider);
		}
	}
}

