TEMPLATE = app
TARGET = videowidget

QT += multimedia multimediawidgets
QT += xml

SOURCES += \
    welcome.cpp \
    project.cpp \
    projectmanager.cpp \
    main.cpp \
    welcomeaddproject.cpp

FORMS += \
    welcome.ui \
    welcomeaddproject.ui

HEADERS += \
    welcome.h \
    project.h \
    projectmanager.h \
    welcomeaddproject.h

target.path = $$[QT_INSTALL_EXAMPLES]/multimediawidgets/videowidget
INSTALLS += target
