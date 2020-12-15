QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admin_authorization.cpp \
    admin_menu.cpp \
    admin_registration.cpp \
    administrator_check.cpp \
    book_output.cpp \
    book_window.cpp \
    change_info.cpp \
    client.cpp \
    client_cabinet.cpp \
    database_book.cpp \
    database_excursion.cpp \
    database_people_amount.cpp \
    date.cpp \
    excursion.cpp \
    excursion_main_info.cpp \
    exursion_output.cpp \
    exursion_show.cpp \
    finded_exursinsions.cpp \
    headband.cpp \
    imaginary_mouse_client.cpp \
    information.cpp \
    main.cpp \
    authorization_window.cpp \
    main_exciursion_info.cpp \
    question.cpp \
    registration_window.cpp \
    review.cpp \
    user.cpp

HEADERS += \
    admin.h \
    admin_authorization.h \
    admin_menu.h \
    admin_registration.h \
    administrator_check.h \
    authorization_window.h \
    book_output.h \
    book_window.h \
    change_info.h \
    client.h \
    client_cabinet.h \
    database_book.h \
    database_excursion.h \
    database_people_amount.h \
    date.h \
    excursion.h \
    excursion_main_info.h \
    exursion_output.h \
    exursion_show.h \
    finded_exursinsions.h \
    headband.h \
    headers.h \
    imaginary_mouse_client.h \
    information.h \
    main_exciursion_info.h \
    question.h \
    registration_window.h \
    review.h \
    user.h

FORMS += \
    admin_authorization.ui \
    admin_menu.ui \
    admin_registration.ui \
    administrator_check.ui \
    authorization_window.ui \
    book_output.ui \
    book_window.ui \
    change_info.ui \
    client_cabinet.ui \
    database_book.ui \
    database_excursion.ui \
    database_people_amount.ui \
    exursion_output.ui \
    exursion_show.ui \
    finded_exursinsions.ui \
    headband.ui \
    imaginary_mouse_client.ui \
    information.ui \
    question.ui \
    registration_window.ui \
    review.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recourse.qrc
