  
set(TEST_NAME BalancedParenthesesTests)

add_executable(${TEST_NAME})

target_sources(${TEST_NAME} PRIVATE BalancedParenthesesTests.cpp)

#target_link_libraries(${TEST_NAME} src gtest gtest_main)
target_link_libraries(${TEST_NAME} gtest gtest_main)

target_compile_features(${TEST_NAME} PRIVATE cxx_std_17)