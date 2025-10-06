add_test( HelloTest.BasicAssertions /home/gerard/Documents/COS214/project/COS214-Project-Repo/build/g_test [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties( HelloTest.BasicAssertions PROPERTIES WORKING_DIRECTORY /home/gerard/Documents/COS214/project/COS214-Project-Repo/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( g_test_TESTS HelloTest.BasicAssertions)
