##############
## Lunatris ##
##############

# Declare the project
project(
  'lunatris',
  'c',
  default_options : [
    'c_std=gnu11',
  ]
)

c_compiler = meson.get_compiler('c')
root_dir = meson.source_root()

###################
## Configuration ##
###################

conf_data = configuration_data()

conf_data.set('LUNATRIS_VERSION', '"1.0"')

configure_file(
  output : 'lunatris_config.h',
  configuration : conf_data
)

############################
## Flags compilation/link ##
############################

common_args = meson.get_compiler('c').get_supported_arguments([
  '-Wall',
  '-Werror',
  '-D_GNU_SOURCE',
  '-march=native',
  '-Wbool-compare',
  '-Wformat-security',
  '-Winit-self',
  '-Wlogical-op',
  '-Wtrampolines',
  '-Wmissing-format-attribute',
  '-Wno-error=deprecated-declarations',
  '-Wno-format-zero-length',
  '-pipe',
  '-g3',
  '-pthread',
  '-fstack-protector',
  '-funwind-tables',
  '-fasynchronous-unwind-tables',
  '-fstack-protector-strong',
  '-fno-common',
  '-Wshadow',
  '-Wmissing-declarations',
  '-Wpointer-arith',
  '-Wformat=2',
  '-mpclmul',
  '-msse4.1',
])

#############
## Include ##
#############

# Global namespace: #include <lunatris/...>
lunatris_inc = include_directories('include', '.')

############
## Source ##
############

subdir('src')

###########
## Tests ##
###########

subdir('tests')
