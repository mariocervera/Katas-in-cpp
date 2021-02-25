  
set(TEST_NAME PrimeFactorsTests)

add_executable(${TEST_NAME})

target_sources(${TEST_NAME} PRIVATE PrimeFactorsTests.cpp)

target_link_libraries(${TEST_NAME} PrimeFactors gtest gtest_main)

target_compile_features(${TEST_NAME} PRIVATE cxx_std_17)