TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "D:\Development\Libs\Cpp\SDL2-2.0.12\x86_64-w64-mingw32\include"
LIBS += -L"D:\Development\Libs\Cpp\SDL2-2.0.12\x86_64-w64-mingw32\lib"
LIBS += -lmingw32 -lSDL2main -lSDL2

INCLUDEPATH += "C:\VulkanSDK\1.2.154.1\Include"
LIBS += -L"C:\VulkanSDK\1.2.154.1\Lib"
LIBS += -lvulkan



SOURCES += \
        game.cpp \
        main.cpp \
        vulkanWindow.cpp \
        vulkancore.cpp

HEADERS += \
    game.h \
    vulkanWindow.h \
    vulkancore.h
