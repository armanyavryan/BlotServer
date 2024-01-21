QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets svg svgwidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Card/Card.cpp \
    Components/Loading.cpp \
    Components/Progress.cpp \
    Controllers/MainController.cpp \
    Controllers/TcpClient.cpp \
    Pages/ConnectingPage.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Card/Card.h \
    Components/Loading.h \
    Components/Progress.h \
    Controllers/MainController.h \
    Controllers/ResponseDataParser.h \
    Controllers/TcpClient.h \
    Pages/ConnectingPage.h \
    SharedData.h \
    mainwindow.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Assets.qrc
