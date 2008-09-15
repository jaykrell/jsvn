#include "j.h"
#include <windows.h>
#include <dciman.h>

/*C_ASSERT(jk_field_size(jk_display_t, Win.DciSurfaceStorage) == sizeof(DCISURFACEINFO));*/

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

static
void
jk_win_cleanup_display(
	jk_display_t* d
	)
{
	if (d->Win.DciSurface)
		DCIDestroy(d->Win.DciSurface);
	if (d->Win.DciProvider)
		DCICloseProvider(d->Win.DciProvider);
	jk_zero_memory(d, sizeof(*d));
}

static
long
jk_win_display_begin_access(
	jk_display_t *d
	)
{
	DCIBeginAccess(d->Win.DciSurface);
	d->


	void* opaque_handle;
	d->base_address;
	d->height;
	d->width;
	d->bytes_per_row;
	d->bits_per_pixel;
	d->bits_per_pixel_even_rounded_up;
	d->bits_per_pixel_even_rounded_down;
	d->bits_per_pixel_even_rounded_up_div_8;
	d->bits_per_pixel_even_rounded_down_div_8;
	jk_display_plot_bit_t plot_bit[8];
	d->bits_per_pixel_even_rounded_up_mod_8 : 3;
	d->bits_per_pixel_even_rounded_down_mod_8 : 3;
	d->is_macos  = 0;
	d->is_macosx  = 0;
	d->is_win32  = 1;
	d->is_network  = 0;
	d->is_local = 1;
	d->is_windowed = 0;
	d->is_rectangular  = 0;
	d->is_full_screen = 1;
	d->is_buffer_available = 1;
	void* cache;
	long (*cleanup)(jk_display_t* display);
	long (*begin_access)(jk_display_t* display);
	long (*end_access)(jk_display_t* display);
}

static
long
jk_win_display_end_access(
	jk_display_t *d
	)
{
	DCIEndAccess(d->Win.DciSurface);
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
	er = DCICreatePrimary(d->Win.DciProvider, &d->Win.DciSurface);
	if (er != 0)
		goto Exit;

	e.is_macos = 0;
	e.is_local = 1;
	e.is_buffer_available = 1;
	e.is_rectangular = 1;
	e.is_windowed = 1;
	e.begin_access = &jk_win_display_begin_access;
	e.end_access = &jk_win_display_end_access;
	e.cleanup = &jk_win_cleanup_display;

	er = 0;
Exit:
	if (er != 0)
	{
		jk_win_cleanup_display(d);
		er = - labs(er);
	}
	return er;
}

