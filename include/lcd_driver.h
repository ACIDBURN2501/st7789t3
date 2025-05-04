#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file lcd_driver.h
 * @brief Unified API for initializing and drawing to the ST7789 LCD display
 */

/**
 * @brief Initialize the LCD display
 * 
 * @param spi_fd File descriptor for open SPI device (e.g., /dev/spidev1.0)
 * @param gpio_dc GPIO pin for D/C (data/command) control
 * @param gpio_rst GPIO pin for LCD reset
 * @return 0 on success, negative on failure
 */
int lcd_init(int spi_fd, int gpio_dc, int gpio_rst);

/**
 * @brief Display a splash image scaled to screen
 * 
 * @param path Path to an image file (e.g. PNG) on the filesystem
 * @return 0 on success, negative on failure
 */
int lcd_show_splash(const char *path);

/**
 * @brief Display an error message on a black screen
 * 
 * @param msg The string to render centered on the screen
 */
void lcd_show_text(const char *msg, uint16_t fg, uint16_t bg);

#ifdef __cplusplus
}
#endif

#endif /* LCD_DRIVER_H */