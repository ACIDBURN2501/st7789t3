project('display_driver', 'c', version: '0.1', default_options: ['c_std=c11','freetype2:harfbuzz=disabled','freetype2:brotli=disabled'])

# External dependencies from wrap
freetype_dep = dependency('freetype2', required: true)
zlib_dep = dependency('zlib', required: true)
stb_dep = dependency('stb', required: true)

# Include the Unity subproject
unit_subproject = subproject('unity')
unity_dependency = unit_subproject.get_variable('unity_dep')
unity_gen_runner = unit_subproject.get_variable('gen_test_runner')

# Local includes (project and vendored)
inc = include_directories('include')

# Source files
src_files = files(
  'src/main.c',
  'src/st7789.c',
  'src/gfx.c',
  'src/freetype_text.c',
  'src/display_init.c',
  'src/image_loader.c',
  'src/lcd_driver.c'
)

# Executable target
executable('display_driver', src_files,
  include_directories: inc,
  dependencies: [freetype_dep, zlib_dep, stb_dep],
  install: true
)

# Install assets
install_subdir('assets', install_dir: get_option('datadir') / 'display_driver')

# Install public headers
install_headers(
  'include/lcd_driver.h',
  'include/st7789.h',
  'include/freetype_text.h',
  'include/gfx.h',
  'include/image_loader.h',
  subdir: 'display_driver'
)

# Add test suite
subdir('tests')
