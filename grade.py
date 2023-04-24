
from gggg import *

a = Assignment(21, 10)
s = State(a)

horizontal_rule()

s.reject_if_missing_contributors()
s.reject_if_starter_contributors()

s.reject_unless_files_exist(['algorithms.hpp',
                             'algorithms.cpp',
                             'algorithms_test.cpp',
                             'Makefile'])

s.reject_if_file_changed('gggg.py',
                         'bd4e67df83605c23d5dc30d3048c61fa85b79baf17e4b0f618feb76bb6bda20f')

s.reject_if_file_unchanged('algorithms.cpp',
                           'ad39fc589cbca74b63387b60bbfdd8bdf665cc8be26b33de315c236a4ab6fe3a')

s.reject_if_file_changed('algorithms.hpp',
                         '8da4e8c83cade9548386aef6b7d970729cc6d57f9b31cd4722b3fd4c91c8734f')

s.reject_if_file_changed('algorithms_test.cpp',
                         'f24228ae53763f03bb44e144211d86f653ef1df42853ada447a45ea96b4694ca')

s.reject_unless_command_succeeds(['make', 'clean', 'test'])

s.string_removed_test('TODO comments removed', 3, 'TODO', ['algorithms.cpp'])

s.gtest_run('algorithms_test')
s.gtest_suite_test('find_dip_trivial_cases', 3)
s.gtest_suite_test('find_dip_nontrivial_cases', 3)
s.gtest_suite_test('longest_balanced_span_trivial_cases', 3)
s.gtest_suite_test('longest_balanced_span_nontrivial_cases', 3)
s.gtest_suite_test('telegraph_style_trivial_cases', 3)
s.gtest_suite_test('telegraph_style_trivial_cases', 3)

s.summarize()
