project(Ml_Graph)

add_library(Ml_Graph graph.cpp edge.cpp)

target_include_directories(Ml_Graph PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")