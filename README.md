# Display Driver

This project provides a modular, reusable C-based driver and rendering system for SPI-based LCD displays (specifically the ST7789), intended for use on embedded Linux systems such as the Raspberry Pi.

It supports:

- **ST7789 LCD driver** with RGB565 frame rendering
- **FreeType font rendering** using UTF-8 strings
- **Image loading** via stb_image with RGB565 scaling
- **Framebuffer and text buffer support**
- **Optional boot splash screen with fallback error messaging**
- **Unit testing** using Unity and Meson
- **Cross-compilation** and `rsync` deployment to Raspberry Pi
- **Documentation** via Doxygen + Sphinx + Breathe

## Getting Started

```bash
./build.sh setup      # Configure Meson
./build.sh build      # Compile the project
./build.sh test       # Run unit tests
./build.sh install    # Install binary and assets
./build.sh cross      # Cross-compile for Raspberry Pi
./build.sh deploy     # Deploy to a Raspberry Pi using rsync
```

## Documentation

To build developer and API documentation:

```bash
doxygen Doxyfile
cd doc/sphinx
make html
```

## Auto-Start at Boot

To run the display driver automatically at boot:

```bash
sudo cp display.service /etc/systemd/system/
sudo systemctl daemon-reexec
sudo systemctl enable display.service
```

