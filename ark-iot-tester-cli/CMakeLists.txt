cmake_minimum_required(VERSION 3.2.2)

project(Ark-IoT-Tester-CLI C CXX)
set(CMAKE_CXX_STANDARD 17)

set(SRC_FILES 
    repo_manager.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} stdc++fs )

