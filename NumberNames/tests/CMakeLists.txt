  
set(TEST_NAME NumberNamesTests)

add_executable(${TEST_NAME})

target_sources(${TEST_NAME} PRIVATE NumberNamesTests.cpp)

target_link_libraries(${TEST_NAME} NumberNames gtest gtest_main)

target_compile_features(${TEST_NAME} PRIVATE cxx_std_17)