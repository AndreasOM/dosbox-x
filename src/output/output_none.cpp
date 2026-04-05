#include "dosbox.h"

#include <stdlib.h>
#include <string.h>

#include "sdlmain.h"
#include "render.h"
#include "video.h"

#include <output/output_none.h>

static uint8_t* none_buffer = nullptr;
static Bitu none_pitch = 0;

void OUTPUT_NONE_Initialize()
{
}

void OUTPUT_NONE_Select()
{
    sdl.desktop.want_type = SCREEN_NONE;
    render.aspectOffload = false;
}

Bitu OUTPUT_NONE_GetBestMode(Bitu flags)
{
    (void)flags;
    return GFX_CAN_32 | GFX_SCALING;
}

Bitu OUTPUT_NONE_SetSize()
{
    sdl.clip.x = 0;
    sdl.clip.y = 0;
    sdl.clip.w = sdl.draw.width;
    sdl.clip.h = sdl.draw.height;

    Bitu needed = (Bitu)sdl.draw.width * (Bitu)sdl.draw.height * 4u;
    if (none_buffer)
        free(none_buffer);
    none_buffer = (uint8_t*)malloc(needed);
    if (!none_buffer)
        return 0;
    memset(none_buffer, 0, needed);
    none_pitch = sdl.draw.width * 4u;

    sdl.active = true;

    return GFX_CAN_32 | GFX_SCALING;
}

bool OUTPUT_NONE_StartUpdate(uint8_t* &pixels, Bitu &pitch)
{
    if (!none_buffer)
        return false;

    pixels = none_buffer;
    pitch = none_pitch;
    sdl.updating = true;
    return true;
}

void OUTPUT_NONE_EndUpdate(const uint16_t *changedLines)
{
    (void)changedLines;
    sdl.updating = false;
}

void OUTPUT_NONE_Shutdown()
{
    if (none_buffer) {
        free(none_buffer);
        none_buffer = nullptr;
    }
    none_pitch = 0;
}
