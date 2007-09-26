/*
#include "ApplicationServices/ApplicationServices.h"
#include <ApplicationServices/ApplicationServices.h>
#include "ApplicationServices/QD/Quickdraw.h"
*/
#include "j.h"
#if defined(JK_CC_MPW_CPLUS)
#define volatile /* nothing */
#endif
#include "Quickdraw.h"
#undef volatile

static
long
jk_macos_release_display(
	jk_display_t* d
	)
{
	long err = 0;
	jk_display_t e = { 0 };
	*d = e;
	return err;
}

static
long
jk_macos_display_update_metadata(
	jk_display_t *d
	)
{
	const GDHandle gdh = (GDHandle) d->opaque_handle;
	const GDPtr gdp = *gdh;
	const PixMapHandle pmh = gdp->gdPMap;
	const PixMapPtr pmp = *pmh;
	const Rect r = pmp->bounds;
	long err = 0;
	unsigned bits_per_pixel;
	unsigned bits_per_pixel_even_rounded_up;
	unsigned bits_per_pixel_even_rounded_down;
	
	err = jk_convert_long_to_unsigned_int(pmp->packSize, &d->macos.packing_size);
    if (err < 0)
        goto exit;
	
	d->base_address = (unsigned char*) pmp->baseAddr;
	d->height = ((r.bottom > r.top) ? (r.bottom - r.top) : (r.top - r.bottom));
	d->width = ((r.right > r.left) ? (r.right - r.left) : (r.left - r.right));
	bits_per_pixel = pmp->pixelSize;
	d->bytes_per_row = (0x7FFF & pmp->rowBytes);
	
	d->macos.pixmap_version = pmp->pmVersion;
	d->macos.packing_format = pmp->packType;
	d->macos.packing_size = 0;
	d->macos.pixel_type = pmp->pixelType;
	d->macos.components_per_pixel = pmp->cmpCount;
	d->macos.bits_per_component = pmp->cmpSize;
	d->macos.pixel_format = pmp->pixelFormat;

	d->bits_per_pixel = bits_per_pixel;
	bits_per_pixel_even_rounded_up = ((bits_per_pixel + 1) & ~1U);
	bits_per_pixel_even_rounded_down = (bits_per_pixel & ~1U);
	d->bits_per_pixel_even_rounded_up  = bits_per_pixel_even_rounded_up;
	d->bits_per_pixel_even_rounded_down = bits_per_pixel_even_rounded_down;
	d->bits_per_pixel_even_rounded_up_div_8 = (bits_per_pixel_even_rounded_up / 8);
	d->bits_per_pixel_even_rounded_down_div_8 = (bits_per_pixel_even_rounded_down / 8);
	d->bits_per_pixel_even_rounded_up_mod_8 = (bits_per_pixel_even_rounded_up % 8);
	d->bits_per_pixel_even_rounded_down_mod_8 = (bits_per_pixel_even_rounded_down % 8);

    err = 0;
exit:
    return err;
}

static
long
jk_macos_display_begin_access(
	jk_display_t *d
	)
{
	return jk_macos_display_update_metadata(d);
}

static
long
jk_macos_display_end_access(
	jk_display_t *d
	)
{
	long err = 0;
	jk_unused(d);
	return err;
}

long
jk_macos_get_main_display(
	jk_display_t *d
	)
{
	jk_display_t e = { 0 };
	long err = 0;

	e.opaque_handle = GetMainDevice();	
	e.is_macos = 1;
	e.is_local = 1;
	e.is_buffer_available = 1;
	e.is_rectangular = 1;
	e.is_windowed = 1;
	e.begin_access = &jk_macos_display_begin_access;
	e.end_access = &jk_macos_display_end_access;
	e.release = &jk_macos_release_display;
	
	err = jk_macos_display_update_metadata(&e);
    if (err < 0)
        goto exit;

	*d = e;

    err = 0;
exit:
    return err;
}
