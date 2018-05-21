cmake_minimum_required(VERSION 2.8.3)
project(cubic_bezier_interpolation_curve)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)
 
catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  src/cubic_bezier_interpolation_curve
)

file(GLOB bezier_cpps 
	src/main.cpp 
	src/visualization.cpp
	src/cubic_bezier_interpolation_curve/*.cpp
)

add_executable(bezier_node ${bezier_cpps})
add_dependencies(bezier_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(bezier_node
  ${catkin_LIBRARIES}
)
