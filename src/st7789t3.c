/**
 * @file st7789t3.c
 * @brief ST7789 display driver implementation
 */

#include "../include/st7789t3.h"

void
st7789t3_init(int spi_fd, int gpio_dc, int gpio_rst)
{
}
void
st7789t3_draw_pixel(uint16_t x, uint16_t y, uint16_t color)
{
}
void
st7789t3_fill_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
                   uint16_t color)
{
}
int
st7789t3_draw_buffer_area(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
                          const uint16_t *pixels)
{
        return 0;
}
