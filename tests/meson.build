bash_program = find_program('bash')

test(
  'lunatris-test',
  bash_program,
  args: [
    join_paths(root_dir, 'tests', 'test.sh'),
    'from-meson',
  ],
)
