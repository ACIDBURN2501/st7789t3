# tests/meson.build

test_src = files(
  'test_display.c'
)

unity_dep = dependency('unity', required: true)
driver_dep = dependency('display_driver', required: true)

test_exe = executable('test_display_driver',
  test_src,
  include_directories: include_directories('../include'),
  dependencies: [unity_dep, driver_dep],
  install: false
)

test('unit', test_exe)

