cmake_minimum_required(VERSION 3.18)
project(NumberNamesKata)

# Load FetchContent module.
include(FetchContent)

# Declare GoogleTest as the content to fetch
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.10.0
)

# Fetch GoogleTest and make targets available
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

# Process the two subdirectories of the project
add_subdirectory(src)
add_subdirectory(tests)