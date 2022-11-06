cmake_minimum_required(VERSION 3.5)
project(MergeSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main/MergeSortAlgorithm.cpp
        src/main/MergeSortAlgorithm.h
)

add_executable(MergeSort src/main/main.cpp ${SOURCE_FILES})

# Testing flags
option(BUILD_TESTING "build unit tests" ON)

if(BUILD_TESTING)

    enable_testing() #Enables testing via command : make test

    include(FetchContent)

    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG release-1.12.1
    )

    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_subdirectory(src/test)
endif()