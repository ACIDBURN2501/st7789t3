#ifndef FREETYPE_TEXT_H
#define FREETYPE_TEXT_H

#include <stdint.h>

/**
 * @file freetype_text.h
 * @brief Renders UTF-8 strings to an RGB565 text buffer using FreeType
 */

#define TEXT_BUF_W 240U
#define TEXT_BUF_H 40U

extern uint16_t text_buf[TEXT_BUF_W * TEXT_BUF_H];

/**
 * @brief Render a UTF-8 string to an off-screen RGB565 text buffer.
 */
void render_text_to_buffer(const char *text, uint16_t fg, uint16_t bg);

/**
 * @brief Draw the current contents of the text buffer to screen.
 */
void draw_text_buffer(uint16_t x, uint16_t y);

#endif /* FREETYPE_TEXT_H */