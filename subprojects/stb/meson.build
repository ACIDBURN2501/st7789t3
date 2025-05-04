project('stb', 'c', version: '2.30.0')

stb_dep = declare_dependency(
  include_directories: include_directories('.')
)

meson.override_dependency('stb', stb_dep)
