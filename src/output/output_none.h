#include "dosbox.h"

#ifndef DOSBOX_OUTPUT_NONE_H
#define DOSBOX_OUTPUT_NONE_H

// output API
void OUTPUT_NONE_Initialize();
void OUTPUT_NONE_Select();
Bitu OUTPUT_NONE_GetBestMode(Bitu flags);
Bitu OUTPUT_NONE_SetSize();
bool OUTPUT_NONE_StartUpdate(uint8_t* &pixels, Bitu &pitch);
void OUTPUT_NONE_EndUpdate(const uint16_t *changedLines);
void OUTPUT_NONE_Shutdown();

#endif /*DOSBOX_OUTPUT_NONE_H*/
