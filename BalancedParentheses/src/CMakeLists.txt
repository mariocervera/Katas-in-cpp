
set(SRC_LIBRARY_NAME BalancedParentheses)

add_library(${SRC_LIBRARY_NAME})

target_sources(${SRC_LIBRARY_NAME} PRIVATE BalancedParentheses.cpp)

target_include_directories(${SRC_LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})