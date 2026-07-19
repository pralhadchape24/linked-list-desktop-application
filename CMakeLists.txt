cmake_minimum_required(VERSION 3.16)

project(FinalLinkedList)

set(CMAKE_CXX_STANDARD 17)

# Auto-generate moc, uic, rcc files
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(FinalLinkedList
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    linkedlist.cpp
    linkedlist.h
)

target_link_libraries(FinalLinkedList
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
