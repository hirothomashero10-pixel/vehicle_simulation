cmake_minimum_required(VERSION 3.16)

project(vehicle_simulation LANGUAGES CXX)

add_executable(
    vehicle_simulation_v23
    src/main.cpp
    src/vehicle.cpp
)

target_include_directories(
    vehicle_simulation_v23
    PRIVATE
    include
)

target_compile_features(
    vehicle_simulation_v23
    PRIVATE
    cxx_std_17
)

target_compile_options(
    vehicle_simulation_v23
    PRIVATE
    -Wall               #よくある問題を広く警告
    -Wextra             #さらに追加の警告
    -Wpedantic           #C++標準から外れた書き方も厳しく確認
)