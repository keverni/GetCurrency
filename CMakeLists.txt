cmake_minimum_required(VERSION 3.16)

project(GetCurrency VERSION 1.0)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(UI_PATH ${CMAKE_CURRENT_SOURCE_DIR}/UI)
set(LOGIC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Logic)

find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    main.cpp
    ${UI_PATH}/GetDollarUI.ui
    ${UI_PATH}/GetDollarUI.h
    ${UI_PATH}/GetDollarUI.cpp
    ${LOGIC_PATH}/ExchangeRate.h
    ${LOGIC_PATH}/ExchangeRate.cpp
)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        cpr::cpr
        nlohmann_json::nlohmann_json
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${LOGIC_PATH}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

