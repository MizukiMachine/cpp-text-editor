cmake_minimum_required(VERSION 3.10)

# vcpkgのツールチェーンファイルを設定
set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(SimpleTextEditor)

# C++17を使用
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# wxWidgetsの設定
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# ソースファイルの設定
set(SOURCES
    src/main.cpp
)

# Windowsの場合、WinMainエントリーポイントを使用
if(WIN32)
    add_executable(SimpleTextEditor WIN32 ${SOURCES})
else()
    add_executable(SimpleTextEditor ${SOURCES})
endif()

# wxWidgetsをリンク
target_link_libraries(SimpleTextEditor PRIVATE ${wxWidgets_LIBRARIES})

# インクルードディレクトリの設定
target_include_directories(SimpleTextEditor PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
