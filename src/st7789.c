/**
 * @file st7789.c
 * @brief ST7789 display driver implementation
 */

#include "../include/st7789.h"

void
st7789_init(int spi_fd, int gpio_dc, int gpio_rst)
{
}
void
st7789_draw_pixel(uint16_t x, uint16_t y, uint16_t color)
{
}
void
st7789_fill_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
}
int
st7789_draw_buffer_area(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
                        const uint16_t *pixels)
{
        return 0;
}
