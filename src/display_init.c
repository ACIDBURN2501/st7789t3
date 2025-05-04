/**
 * @file display_init.c
 * @brief Display splash screen and fallback text rendering.
 */
#include "../include/freetype_text.h"
#include "../include/image_loader.h"
#include "../include/st7789.h"

#define SCREEN_W   ST7789_WIDTH
#define SCREEN_H   ST7789_HEIGHT
#define TEXT_BUF_W 240u
#define TEXT_BUF_H 40u

static uint16_t splash_buf[SCREEN_W * SCREEN_H];
extern uint16_t text_buf[TEXT_BUF_W * TEXT_BUF_H];

void
display_show_splash(const char *path)
{
        int ok = image_load_rgb565(path, splash_buf, SCREEN_W, SCREEN_H);
        if (ok == 0) {
                st7789_draw_buffer_area(0, 0, SCREEN_W, SCREEN_H, splash_buf);
        } else {
                // fallback: black background
                st7789_fill_rect(0, 0, SCREEN_W, SCREEN_H, 0x0000);

                // render error message into text buffer
                render_text_to_buffer("Failed to load image", 0xFFFF, 0x0000);
                draw_text_buffer((SCREEN_W - TEXT_BUF_W) / 2,
                                 SCREEN_H / 2 - TEXT_BUF_H / 2);
        }
}
