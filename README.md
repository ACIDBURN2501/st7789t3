# st7789t3_driver (WIP)

A reusable C driver library for the ST7789T3 SPI LCD display, designed for embedded Linux platforms like the Raspberry Pi CM4. It supports:

- Initialization of the ST7789T3 display
- Rendering RGB565 pixel buffers
- Text rendering using FreeType
- Image rendering (PNG) via stb_image
- Framebuffer-style drawing via `gfx`

## 📦 Integration

### Option 1: As a Meson Subproject

Add this project as a subproject in your `subprojects/` directory:

```
project_root/
├── subprojects/
│   └── st7789t3_driver/
```

Then in your `meson.build`:
```meson
st7789t3_dep = dependency('st7789t3_driver')
```

And in your C code:
```c
#include <st7789t3_driver.h>

st7789t3_init(spi_fd, gpio_dc, gpio_rst);
st7789t3_show_splash("/boot/splash.png");
st7789t3_show_text("Booting...", 0xFFFF, 0x0000);
```

### Option 2: Install System-Wide

Install the library and headers:
```bash
sudo ninja -C build install
```

Use `pkg-config` to link:
```bash
pkg-config --cflags --libs st7789t3_driver
```

Then compile:
```bash
gcc main.c $(pkg-config --cflags --libs st7789t3_driver)
```

## ✅ Dependencies

- FreeType (via wrap or `libfreetype6-dev`)
- zlib (for PNG decompression)
- stb_image (vendored as subproject)
- Unity (for tests, optional)

## 🧪 Tests

Run unit tests:
```bash
meson setup build
meson test -C build
```

## 📚 Documentation

See `doc/sphinx/source/index.rst` for user and API documentation.
Build docs:
```bash
cd doc/sphinx
make html
```
