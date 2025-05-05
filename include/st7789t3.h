#ifndef ST7789_H
#define ST7789_H

#include <stdint.h>
#include <unistd.h>

/**
 * @file st7789.h
 * @brief ST7789 display driver interface
 */

#define ST7789_WIDTH  240
#define ST7789_HEIGHT 320

/**
 * @brief Initialize the ST7789 display.
 *
 * @param spi_fd File descriptor for SPI device
 * @param gpio_dc GPIO pin number for data/command
 * @param gpio_rst GPIO pin number for reset
 */
void st7789_init(int spi_fd, int gpio_dc, int gpio_rst);

/**
 * @brief Draw a pixel on the screen.
 */
void st7789_draw_pixel(uint16_t x, uint16_t y, uint16_t color);

/**
 * @brief Fill a rectangle with a solid color.
 */
void st7789_fill_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
                      uint16_t color);

/**
 * @brief Draw a raw RGB565 pixel buffer to the screen.
 */
int st7789_draw_buffer_area(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
                            const uint16_t *pixels);

#endif /* ST7789_H */