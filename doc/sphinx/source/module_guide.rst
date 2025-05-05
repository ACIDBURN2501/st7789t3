Developer Module Guide
=======================

This document explains the purpose and design intent of each module in the `st7789t3_driver` library.
It serves as a reference for contributors who want to extend, maintain, or build on top of the codebase.

Module Overview
---------------

The driver is organized into modular layers, each responsible for a specific function in the graphics stack:

+----------------------+------------------------------+---------------------------------------------+
| Module               | Responsibility               | Notes                                       |
+======================+==============================+=============================================+
| st7789t3_driver      | Unified public API           | What users include and call directly        |
+----------------------+------------------------------+---------------------------------------------+
| st7789               | SPI LCD controller backend   | Low-level hardware interface (internal)     |
+----------------------+------------------------------+---------------------------------------------+
| gfx                  | Software framebuffer drawing | Pixel/rect/text drawing into RAM buffers    |
+----------------------+------------------------------+---------------------------------------------+
| freetype_text        | UTF-8 text rendering         | Renders text to buffer using FreeType       |
+----------------------+------------------------------+---------------------------------------------+
| image_loader         | PNG/BMP loading              | Uses stb_image to decode into RGB565 buffers|
+----------------------+------------------------------+---------------------------------------------+

Module Responsibilities & Extension Examples
--------------------------------------------

st7789t3_driver (Public API)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
High-level user-facing API that wraps and simplifies access to other modules.

Example Functions:
  - ``st7789t3_init(int spi_fd, int gpio_dc, int gpio_rst)``
  - ``st7789t3_show_splash(const char *path)``
  - ``st7789t3_show_text(const char *msg, uint16_t fg, uint16_t bg)``
  - ``st7789t3_draw_centered_label(...)``
  - ``st7789t3_clear(...)``

st7789 (Display Controller)
~~~~~~~~~~~~~~~~~~~~~~~~~~~
Handles raw SPI interaction and command/data sequences for the ST7789T3 controller.

Example Functions:
  - ``st7789_init(...)``
  - ``st7789_draw_buffer_area(...)``
  - ``st7789_sleep(bool enable)``
  - ``st7789_invert_colors(bool enable)``

gfx (Framebuffer Drawing)
~~~~~~~~~~~~~~~~~~~~~~~~~
Provides simple drawing tools to modify `uint16_t *` buffers in RAM.

Example Functions:
  - ``gfx_fill_rect(...)``
  - ``gfx_draw_pixel(...)``
  - ``gfx_draw_line(...)``
  - ``gfx_draw_box(...)``

freetype_text (Text Rendering)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Uses FreeType to rasterize UTF-8 strings into buffers.

Example Functions:
  - ``render_text_to_buffer(...)``
  - ``draw_text_buffer(...)``
  - ``freetype_set_font(...)``
  - ``render_multiline_text(...)``

image_loader (Image Decoding)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Loads PNG or BMP images into RGB565 pixel buffers for the LCD.

Example Functions:
  - ``image_load_rgb565(...)``
  - ``image_load_rgb565_region(...)``
  - ``image_validate(...)``

Contributor Guidelines
----------------------

- Only `st7789t3_driver.h` should be used by external projects.
- `st7789.[c/h]` should remain internal.
- Maintain consistent naming and argument styles across modules.
- Use Doxygen comments for all public functions.
- Add unit tests to the `tests/` folder using Unity.