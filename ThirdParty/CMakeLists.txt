cmake_minimum_required(VERSION 3.6)
project(ThirdParty)

add_library(${PROJECT_NAME} STATIC
    imgui/imgui.cpp
    imgui/imgui.h
    imgui/imgui_draw.cpp
    imgui/imgui_internal.h
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    # imgui-SFML
    imgui-SFML/imgui-SFML.h
    imgui-SFML/imconfig-SFML.h
    imgui-SFML/imgui-SFML.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/imgui ${CMAKE_CURRENT_SOURCE_DIR}/imgui-SFML)

add_subdirectory(SFML)
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-window sfml-graphics sfml-audio)
