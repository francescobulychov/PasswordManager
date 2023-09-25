TEMPLATE = app
TARGET = "Password Manager"
QT = core gui

LIBS += -Lopenssl -lssl -lcrypto
INCLUDEPATH += openssl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    core/xml/XmlReaderVisitor.cpp \
    core/xml/XmlStream.cpp \
    core/xml/XmlWriterVisitor.cpp \
    gui/AddItemVisitor.cpp \
    gui/AddItemWidget.cpp \
    gui/EditItemVisitor.cpp \
    gui/EditItemWidget.cpp \
    gui/InfoItemVisitor.cpp \
    gui/InfoItemWidget.cpp \
    gui/MainWindow.cpp \
    main.cpp \
    core/AbstractItem.cpp \
    core/Login.cpp \
    core/Card.cpp \
    core/Note.cpp \
    utils/Container.cpp \
    utils/Cryptography.cpp \
    utils/base64.cpp

HEADERS += \
    core/AbstractItem.h \
    core/Login.h \
    core/Card.h \
    core/Note.h \
    core/IVisitor.h \
    core/IConstVisitor.h \
    core/xml/XmlReaderVisitor.h \
    core/xml/XmlStream.h \
    core/xml/XmlWriterVisitor.h \
    gui/AddItemVisitor.h \
    gui/AddItemWidget.h \
    gui/EditItemVisitor.h \
    gui/EditItemWidget.h \
    gui/InfoItemVisitor.h \
    gui/InfoItemWidget.h \
    gui/MainWindow.h \
    utils/Container.h \
    utils/Cryptography.h \
    utils/base64.h

RESOURCES += \
    resources.qrc

