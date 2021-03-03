  
set(TEST_NAME PrintDiamondTests)

add_executable(${TEST_NAME})

target_sources(${TEST_NAME} PRIVATE DiamondPrinterTests.cpp)

target_link_libraries(${TEST_NAME} PrintDiamond gtest gtest_main)

target_compile_features(${TEST_NAME} PRIVATE cxx_std_17)