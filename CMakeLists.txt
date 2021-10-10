cmake_minimum_required (VERSION 3.19)

project (ttslite)

set(BIN_NAME "mainApp")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json 3.2.0 REQUIRED)

add_subdirectory(src/tts)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG -Wl,--no-as-needed -ldl -pthread -fpermissive")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/tts/include)

add_executable(${BIN_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main/main.cpp)

target_link_libraries(${BIN_NAME} tensorflow-lite ttslite nlohmann_json::nlohmann_json -ldl -lm -lpthread -lrt -latomic)
