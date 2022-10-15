cmake_minimum_required(VERSION 3.23)
project(Downloads)

set(CMAKE_CXX_STANDARD 20)

add_executable(Downloads main.cpp HashMap.cpp User.cpp Meal.cpp Restaurant.cpp Entity.cpp FOMS.cpp defaultFiles.cpp)
