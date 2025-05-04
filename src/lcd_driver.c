/**
 * @file lcd_driver.c
 * @brief Unified public API layer for ST7789 LCD
 */
#include "lcd_driver.h"
#include "st7789.h"
#include "image_loader.h"
#include "freetype_text.h"

#define LCD_W ST7789_WIDTH
#define LCD_H ST7789_HEIGHT
#define TEXT_W TEXT_BUF_W
#define TEXT_H TEXT_BUF_H

static uint16_t lcd_buf[LCD_W * LCD_H];
extern uint16_t text_buf[TEXT_W * TEXT_H];

int lcd_init(int spi_fd, int gpio_dc, int gpio_rst)
{
    st7789_init(spi_fd, gpio_dc, gpio_rst);
    return 0;
}

int lcd_show_splash(const char *path)
{
    int res = image_load_rgb565(path, lcd_buf, LCD_W, LCD_H);
    if (res == 0) {
        st7789_draw_buffer_area(0, 0, LCD_W, LCD_H, lcd_buf);
    }
    return res;
}

void lcd_show_text(const char *msg, uint16_t fg, uint16_t bg)
{
    st7789_fill_rect(0, 0, LCD_W, LCD_H, bg);
    render_text_to_buffer(msg, fg, bg);
    draw_text_buffer((LCD_W - TEXT_W) / 2, (LCD_H - TEXT_H) / 2);
}