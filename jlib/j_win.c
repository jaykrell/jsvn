#include "j.h"
#include <windows.h>
#include <dciman.h>

C_ASSERT(jk_field_size(jk_display_t, Win.DciSurface) == sizeof(DCISURFACEINFO));

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

void
jk_win_cleanup_display(
	jk_display_t* d
	)
{
	if (d->Win.Valid.DciSurface)
	{
		DCIDestroy((DCISURFACEINFO*) d->Win.DciSurface);
	}
	if (d->Win.Valid.DciProvider)
	{
		DCICloseProvider(d->Win.DciProvider);
	}
	jk_zero_memory(&d->Win.Valid, sizeof(d->Win.Valid));
}

long
jk_win_get_main_display(
	jk_display_t* d
	)
{
	long er = -1;
	
	jk_win_cleanup_display(d);
	d->Win.DciProvider = DCIOpenProvider();
	if (!d->Win.DciProvider)
		goto Exit;

	er = 0;
Exit:
	if (er != 0)
	{
		jk_win_cleanup_display(d);
	}
	return er;
}

