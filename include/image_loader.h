#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <stdint.h>

/**
 * Loads an image from file and converts it to RGB565.
 * The image will be scaled to fit dst_w × dst_h.
 *
 * @param path Path to the input image file (PNG, JPG, etc.)
 * @param out_buf Output buffer (must be dst_w × dst_h in size)
 * @param dst_w Destination width (e.g., ST7789_WIDTH)
 * @param dst_h Destination height
 * @return 0 on success, -1 on failure
 */
int image_load_rgb565(const char *path, uint16_t *out_buf, int dst_w,
                      int dst_h);

#endif /* IMAGE_LOADER_H */