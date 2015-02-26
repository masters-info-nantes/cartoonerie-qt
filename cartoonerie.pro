TEMPLATE = app
TARGET = videowidget

QT += multimedia multimediawidgets
QT += xml

SOURCES += \
    welcome.cpp \
    project.cpp \
    projectmanager.cpp \
    main.cpp \
    welcomeaddproject.cpp \
    welcomeproject.cpp \
    editor.cpp \
    drawzone.cpp \
    imagewidget.cpp \
    stackwidget.cpp

FORMS += \
    welcome.ui \
    welcomeaddproject.ui \
    welcomeproject.ui \
    editor.ui

HEADERS += \
    welcome.h \
    project.h \
    projectmanager.h \
    welcomeaddproject.h \
    welcomeproject.h \
    editor.h \
    drawzone.h \
    imagewidget.h \
    stackwidget.h

OTHER_FILES +=

RESOURCES += \
    resources.qrc
