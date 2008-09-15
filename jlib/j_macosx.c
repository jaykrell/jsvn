
#include "j.h"

#if 0

/*
include "ApplicationServices/ApplicationServices.h"
include <ApplicationServices/ApplicationServices.h>
include "/System/Library/Frameworks/ApplicationServices.framework/Frameworks/CoreGraphics.framework/Headers/CoreGraphics.h"
*/
#include <ApplicationServices/ApplicationServices.h>

static
void
jk_macosx_cleanup_display(
	jk_display_t* d
	)
{
	jk_display_t e = { 0 };

	CGPaletteRelease(d->macosx.palette);
	*d = e;
}

long
jk_macosx_get_main_display(
	jk_display_t *d
	)
{
	CGDirectDisplayID id = CGMainDisplayID();
	jk_display_t e = { 0 };

	e.opaque_handle = id;
	e.base_address = (unsigned char*)CGDisplayBaseAddress(id);
	e.height = CGDisplayPixelsHigh(id);
	e.width = CGDisplayPixelsWide(id);
	e.bits_per_pixel = CGDisplayBitsPerPixel(id);
	e.bytes_per_row = CGDisplayBytesPerRow(id);

	e.macosx.bits_per_sample = CGDisplayBitsPerSample(id);
	e.macosx.samples_per_pixel = CGDisplaySamplesPerPixel(id);
	e.macosx.can_set_palette = CGDisplayCanSetPalette(id);
	*d = e;
	
	return 0;
}

#else

static
void
jk_macosx_cleanup_display(
	jk_display_t* d
	)
{
	jk_display_t e = { 0 };
	*d = e;
}

long
jk_macosx_get_main_display(
	jk_display_t* d
	)
{
	jk_display_t e = { 0 };
	*d = e;
	return -1;
}

void
jk_get_mouse_state(
	jk_mouse_state_t* m
	)
{
	jk_unused(m);
}

void
jk_get_keyboard_state(
	jk_keyboard_state_t* k
	)
{
	jk_unused(k);
}


#endif
