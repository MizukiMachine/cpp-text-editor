cmake_minimum_required(VERSION 3.10)
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

# 実行ファイルの生成
add_executable(SimpleTextEditor ${SOURCES})

# wxWidgetsをリンク
target_link_libraries(SimpleTextEditor PRIVATE ${wxWidgets_LIBRARIES})

# インクルードディレクトリの設定
target_include_directories(SimpleTextEditor PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
