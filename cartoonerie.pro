TEMPLATE = app
TARGET = videowidget

QT += multimedia multimediawidgets

SOURCES += \
    welcome.cpp \
    main.cpp

FORMS += \
    welcome.ui

HEADERS += \
    welcome.h

target.path = $$[QT_INSTALL_EXAMPLES]/multimediawidgets/videowidget
INSTALLS += target

QT+=widgets
