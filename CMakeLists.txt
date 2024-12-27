cmake_minimum_required(VERSION 3.5)

project(Ttext)

set(CMAKE_CXX_STANDARD 17)

# Add Qt5 Library
find_package(Qt5Widgets REQUIRED)

# setup source
set(SOURCES
    main.cpp
    MainWindow.cpp
)

# create meta-object code from header include Q_OBJECT
set(HEADERS
    MainWindow.h
)

qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

# Create executable file
add_executable(Ttext ${SOURCES} ${MOC_SOURCES})
target_link_libraries(Ttext Qt5::Widgets)
