cmake_minimum_required(VERSION 3.16)

project(Qt6QuickMongoDB VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_OUTPUT_PLUGIN_DIRECTORY   ${CMAKE_PREFIX_PATH}/qml/QtQuick/MongoDB)
set(QT_LIB_OUTPUT_DIRECTORY  ${CMAKE_PREFIX_PATH}/lib)

find_package(Qt6 6.2 REQUIRED COMPONENTS BuildInternals Core Gui Qml Quick )
add_subdirectory(mongo-c-driver)

file(MAKE_DIRECTORY ${QT_QML_OUTPUT_PLUGIN_DIRECTORY})

#add_subdirectory(libmongocrypt)
qt_add_library(Qt6QuickMongoDB SHARED)

qt_add_qml_module(Qt6QuickMongoDB
    OUTPUT_DIRECTORY ${QT_QML_OUTPUT_PLUGIN_DIRECTORY}
    URI QtQuick.MongoDB
    VERSION 1.0
    SOURCES
    mongodb.cpp
    mongodb.h
)

target_include_directories(Qt6QuickMongoDB SYSTEM
    PRIVATE
    ${Qt6Quick3D_PRIVATE_INCLUDE_DIRS}

)

target_compile_definitions(Qt6QuickMongoDB
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_directories(Qt6QuickMongoDB
    PRIVATE ${CMAKE_PREFIX_PATH}/plugins/mongodb)
target_link_libraries(Qt6QuickMongoDB
    PRIVATE Qt6::Quick bson-1.0 mongoc-1.0)

target_include_directories(Qt6QuickMongoDB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(Qt6QuickMongoDB PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${QT_LIB_OUTPUT_DIRECTORY}
)
