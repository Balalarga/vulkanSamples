TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt


win32{
LIBS += -lmingw32

INCLUDEPATH += "D:\Development\Libs\Cpp\SDL2-2.0.12\x86_64-w64-mingw32\include"
LIBS += -L"D:\Development\Libs\Cpp\SDL2-2.0.12\x86_64-w64-mingw32\lib"

INCLUDEPATH += "C:\VulkanSDK\1.2.154.1\Include"
LIBS += -L"C:\VulkanSDK\1.2.154.1\Lib"
}

LIBS += -lSDL2main -lSDL2
LIBS += -lvulkan


SOURCES += \
        game.cpp \
        main.cpp \
        videosystem.cpp \
        vulkanwindow.cpp

HEADERS += \
    game.h \
    videosystem.h \
    vulkanwindow.h
