cmake_minimum_required(VERSION 3.10)

# Set the project name. This is not the executable program's name!
project(graphical_template)

# Try to find a locally installed raylib, but don't quit on fail
find_package(raylib 5.5 QUIET)

# This code downloads raylib into a directory called _deps and adds it as a subdirectory, compiling it with the program when running the build command
include(FetchContent)
if (NOT raylib_FOUND)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
        DOWNLOAD_EXTRACT_TIMESTAMP True #This option is not required but suppresses a warning
    )
    FetchContent_MakeAvailable(raylib)
endif()

# We don't want raylib's examples built. This option is picked up by raylib's CMakeLists.txt
set(RLIMGUI_SRC rlImGui/rlImGui.cpp)
set(IMGUI_SRC imgui/imgui.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/imgui_demo.cpp )

# Here, the executable is declared with its sources. "main", or "main.exe" on windows will be the program's name
add_executable(main "src/main.cpp" ${IMGUI_SRC} ${RLIMGUI_SRC})

# Link raylib to main
target_link_libraries(main 
    raylib
)

target_include_directories(main PRIVATE ${raylib_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/imgui ${CMAKE_SOURCE_DIR}/rlImGui )