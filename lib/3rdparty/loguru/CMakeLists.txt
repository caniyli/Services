project(loguru)               # Create project "simple_ex
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 st

file( GLOB SRCS *.cpp *.h *.hpp )

add_library(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} PUBLIC -lpthread)

