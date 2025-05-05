/**
 * @file image_loader.c
 * @brief Load and scale images using stb_image to RGB565 format.
 */
#define STB_IMAGE_IMPLEMENTATION

#include "../subprojects/stb/stb_image.h"

#include "../include/image_loader.h"

int
image_load_rgb565(const char *path, uint16_t *out_buf, int dst_w, int dst_h)
{
        int w, h, channels;
        unsigned char *data =
            stbi_load(path, &w, &h, &channels, 3); // force RGB
        if (!data || !out_buf || out_buf == NULL) {
                return -1;
        }

        for (int y = 0; y < dst_h; ++y) {
                int src_y = y * h / dst_h;
                for (int x = 0; x < dst_w; ++x) {
                        int src_x = x * w / dst_w;
                        int idx = (src_y * w + src_x) * 3;
                        uint8_t r = data[idx + 0];
                        uint8_t g = data[idx + 1];
                        uint8_t b = data[idx + 2];
                        uint16_t rgb565 =
                            ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);
                        out_buf[y * dst_w + x] = rgb565;
                }
        }

        stbi_image_free(data);
        return 0;
}
