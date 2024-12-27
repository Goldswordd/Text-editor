cmake_minimum_required(VERSION 3.5)

project(QtExample)

set(CMAKE_CXX_STANDARD 17)

# Tìm thư viện Qt5
find_package(Qt5Widgets REQUIRED)

# Liệt kê các file nguồn
set(SOURCES
    main.cpp
    MainWindow.cpp
)

# Tạo meta-object code từ header chứa Q_OBJECT
set(HEADERS
    MainWindow.h
)

qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

# Tạo file thực thi
add_executable(QtExample ${SOURCES} ${MOC_SOURCES})
target_link_libraries(QtExample Qt5::Widgets)
