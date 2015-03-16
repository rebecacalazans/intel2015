add_subdirectory(base)
add_subdirectory(utils)
add_subdirectory(core)

add_executable(intel main.cpp)
target_link_libraries(intel intel_utils)
