cmake_minimum_required(VERSION 3.13)  
project(practica8)              
set(CMAKE_CXX_STANDARD 14)    
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


set(SOURCE_FILES practica8.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(practica8 ${SOURCE_FILES})


# Link your application with OpenCV libraries
target_link_libraries(practica8 ${OpenCV_LIBS})
