set(SRC 
	demo.c
)
include_directories(${CMAKE_SOURCE_DIR}/GTTClient)
add_executable(generic_demo ${SRC})
target_link_libraries(generic_demo GTTClient)