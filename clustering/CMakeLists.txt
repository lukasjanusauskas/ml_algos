cmake_minimum_required(VERSION 3.5)
project(clustering)

set(SOURCE_FILES
	read_csv.cpp
	kmeans.cpp
	main.cpp)


find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Python3_LIBRARIES})