QT = core

INCLUDEPATH += /usr/include/bsoncxx/v_noabi/
INCLUDEPATH += /usr/include/mongocxx/v_noabi/
INCLUDEPATH += /usr/include


LIBS += -L/usr/local/lib -lmongocxx -lbsoncxx
LIBS += -lcurl

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    json.hpp \
    sites.h
