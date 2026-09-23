cmake_minimum_required(VERSION 3.16)

project(vehicle_simulation LANGUAGES CXX)

# 実行ファイル名をここで一括管理
set(TARGET_NAME vehicle_simulation_v27)

add_executable(
    ${TARGET_NAME}
    src/main.cpp
    src/vehicle.cpp
)

target_include_directories(
    ${TARGET_NAME}
    PRIVATE
    include
)

target_compile_features(
    ${TARGET_NAME}
    PRIVATE
    cxx_std_20
)

target_compile_options(
    ${TARGET_NAME}
    PRIVATE
    -Wall               #よくある問題を広く警告
    -Wextra             #さらに追加の警告
    -Wpedantic           #C++標準から外れた書き方も厳しく確認
)