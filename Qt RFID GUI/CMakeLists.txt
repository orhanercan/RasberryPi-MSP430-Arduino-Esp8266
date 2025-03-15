cmake_minimum_required(VERSION 3.16)
project(RFIDHTTP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)

# Network modülünü eklediğinizden emin olun
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

file(GLOB SOURCES
    "main.cpp"
    "mainwindow.cpp"
    "mainwindow.h"
    "mainwindow.ui"
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(RFIDHTTP
        MANUAL_FINALIZATION
        ${SOURCES}
    )
else()
    add_executable(RFIDHTTP ${SOURCES})
endif()

# Network kütüphanesini bağlayın
target_link_libraries(RFIDHTTP PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(RFIDHTTP)
endif()
