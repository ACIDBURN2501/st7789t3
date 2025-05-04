#ifndef GFX_H
#define GFX_H

#include <stdint.h>

/**
 * @file gfx.h
 * @brief Basic drawing primitives like rectangles and text
 */

#define GFX_FONT_WIDTH  (6u)
#define GFX_FONT_HEIGHT (8u)

/**
 * @brief Draw a character at (x, y) using 6x8 font.
 */
void gfx_draw_char(uint16_t x, uint16_t y, char c, uint16_t fg, uint16_t bg);

/**
 * @brief Draw a null-terminated string.
 */
void gfx_draw_text(uint16_t x, uint16_t y, const char *text, uint16_t fg,
                   uint16_t bg);

/**
 * @brief Draw a filled rectangle.
 */
void gfx_fill_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
                   uint16_t color);

#endif /* GFX_H */
