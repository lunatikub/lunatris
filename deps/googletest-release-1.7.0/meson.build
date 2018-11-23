project('gtest', 'cpp', default_options : ['cpp_std=c++11'])

run_command('autoreconf', '-fvi')

conf_data = configuration_data()
configure_file(
  input: 'build-aux/config.h.in',
  output: 'config.h',
  configuration: conf_data
)

gtest_inc = include_directories('.', 'build-aux', 'include')
gtest_files = files('src/gtest-all.cc')

thread_dep = dependency('threads')

cc = meson.get_compiler('cpp')
m_dep = cc.find_library('m', required : false)

gtest_lib = static_library(
  'gtest',
  gtest_files,
  include_directories: gtest_inc,
  dependencies: [
    thread_dep,
    m_dep
  ]
)

gtest_dep = declare_dependency(
  link_with: gtest_lib,
  include_directories: gtest_inc,
  dependencies: [
    thread_dep,
    m_dep
  ]
)
