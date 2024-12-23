cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" 
    CACHE STRING "Vcpkg toolchain file")

project(SimpleTextEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(wxWidgets CONFIG REQUIRED)

# インクルードディレクトリの追加
include_directories(${PROJECT_SOURCE_DIR}/include)

# ソースファイルの設定
set(SOURCES
    src/main.cpp
    src/MainFrame.cpp
)

if(WIN32)
    add_executable(SimpleTextEditor WIN32 ${SOURCES})
else()
    add_executable(SimpleTextEditor ${SOURCES})
endif()

target_link_libraries(SimpleTextEditor PRIVATE wx::core wx::base)

if(MSVC)
    add_compile_options(/utf-8)
endif()
