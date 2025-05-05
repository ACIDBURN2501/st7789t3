project('st7789t3_driver', 'c',
  version: '0.1',
  default_options: [
    'c_std=c11',
    'freetype2:harfbuzz=disabled',
    'freetype2:brotli=disabled'
  ]
)

cc = meson.get_compiler('c')

# External dependencies (via subprojects or system)
freetype_dep = dependency('freetype2', required: true)
zlib_dep = dependency('zlib', required: true)
stb_dep = dependency('stb', required: true)
math_dep = cc.find_library('m', required: true)

# Include directories
inc = include_directories('include')

# Source files
src_files = files(
  'src/st7789t3_driver.c',
  'src/st7789t3.c',
  'src/freetype_text.c',
  'src/gfx.c',
  'src/image_loader.c'
)

# Build static library
st7789t3_driver = library('st7789t3_driver', src_files,
  include_directories: inc,
  dependencies: [freetype_dep, zlib_dep, stb_dep, math_dep],
  install: true
)

# Install public headers
install_headers(
  'include/st7789t3_driver.h',
  'include/freetype_text.h',
  'include/gfx.h',
  'include/image_loader.h',
  subdir: 'st7789t3_driver'
)

# Declare dependency for subproject use
st7789t3_driver_dep = declare_dependency(
  include_directories: inc,
  dependencies: [freetype_dep, zlib_dep, stb_dep, math_dep],
  link_with: st7789t3_driver
)
meson.override_dependency('display_driver', st7789t3_driver_dep)

# Install assets
install_subdir('assets', install_dir: get_option('datadir') / 'st7789t3_driver')

# Add unit tests
subdir('tests')

