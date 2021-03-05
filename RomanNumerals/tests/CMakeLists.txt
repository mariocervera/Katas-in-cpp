  
set(TEST_NAME RomanNumeralsConverterTests)

add_executable(${TEST_NAME})

target_sources(${TEST_NAME} PRIVATE RomanNumeralsConverterTests.cpp)

target_link_libraries(${TEST_NAME} RomanNumerals gtest gtest_main)

target_compile_features(${TEST_NAME} PRIVATE cxx_std_17)