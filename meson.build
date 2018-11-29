##############
## Lunatris ##
##############

# Declare the project
project(
  'lunatris',
  'c',
  'cpp',
  default_options : [
    'c_std=gnu11',
    '-std=gnu++11',
  ]
)

c_compiler = meson.get_compiler('c')
root_dir = meson.source_root()

##############################
## Dependencies/Subprojects ##
##############################

# create subprojects directory
run_command('mkdir', '-p', join_paths(root_dir, 'subprojects'))

wrap_file = {
  'gtest': [ '1.7.0', 'googletest-release-1.7.0' ],
}

foreach name, content : wrap_file
  r = run_command(join_paths(root_dir,
                             'tools',
                             'subproject_prerequisite.sh'),
                  name, content[0], content[1])
  if r.returncode() != 0
    error('subproject_prerequisite.sh')
  endif
endforeach

gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')

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

#############
## Modules ##
#############

# Common source for all tests.
common_path = join_paths('tests', 'unit', 'common')
subdir(common_path)
common_test_inc = include_directories(common_path)

# List of modules.
modules = [
  'wall',
  'eval',
]

# Add sources and unit tests for each module.
foreach module : modules
  subdir(join_paths('src', module))
  subdir(join_paths('tests', 'unit', module))
endforeach

##################
## Coding Style ##
##################

run_target(
  'check-coding-style',
  command: [
    join_paths(root_dir, 'tools', 'coding_style', 'check.sh'),
  ]
)
