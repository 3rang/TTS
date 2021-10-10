project (tts)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_NAME "ttslite")

SET(CMAKE_CXX_COMPILER "g++")

SET(CMAKE_CXX_FLAGS "-O3 -fPIC -DNDEBUG -Wl,--no-as-needed -ldl -pthread -fpermissive")

file(GLOB TTS_INC "${CMAKE_CURRENT_SOURCE_DIR}/include")

include_directories(${TTS_INC})

file(GLOB TTS_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(${LIB_NAME} SHARED ${TTS_SRC})

target_link_libraries(${LIB_NAME} tensorflow-lite)

install(TARGETS ${LIB_NAME} LIBRARY DESTINATION /usr/lib)
