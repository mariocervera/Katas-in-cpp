  
set(TEST_NAME CombinedNumberTests)

add_executable(${TEST_NAME})

target_sources(${TEST_NAME} PRIVATE CombinedNumberTests.cpp)

target_link_libraries(${TEST_NAME} CombinedNumber gtest gtest_main)

target_compile_features(${TEST_NAME} PRIVATE cxx_std_17)