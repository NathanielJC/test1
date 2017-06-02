SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)
project("test1")

add_definitions(-DUNICODE -DWIN32 -D_SCL_SECURE_NO_WARNINGS -DWINDOWS)

SET (MY_OUT_BIN_PATH ${PROJECT_BINARY_DIR}) 

SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin) 
SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)
find_package(Qt5Widgets)

include_directories(${Qt5Core_INCLUDES})
include_directories(${Qt5Widgets_INCLUDES})

add_definitions(${Qt5Core_DEFINITIONS})
add_definitions(${Qt5Widgets_DEFINITIONS})

set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS "${Qt5Core_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS "/EHa /Zc:wchar_t")
QT5_ADD_RESOURCES(RESOURCES  imit_inf.qrc)

set(HEADERS gui.h AbWidg.h AbSetDialog.h ExSetDialog.h Imitation_List.h Dialog_val.h Action_CD.h Save_Class.h message.h Contr.h BV.h Imit_ab.h State.h BV_ot_do_class.h)
set(SOURCES  main.cpp gui.cpp AbWidg.cpp AbSetDialog.cpp ExSetDialog.cpp Imitation_List.cpp Dialog_val.cpp Action_CD.cpp Save_Class.cpp message.cpp Contr.cpp BV.cpp Imit_ab.cpp State.cpp BV_ot_do_class.cpp)         

add_executable(test1 WIN32 ${HEADERS} ${SOURCES} ${RESOURCES})
target_link_libraries(test1 ${Qt5Widgets_LIBRARIES} ${Qt5Core_LIBRARIES})

qt5_use_modules(test1 Core Widgets)

