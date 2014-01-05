/****************************************************************************
** Meta object code from reading C++ file 'FakeMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FakeMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FakeMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FakeMenu_t {
    QByteArrayData data[10];
    char stringdata[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FakeMenu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FakeMenu_t qt_meta_stringdata_FakeMenu = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 10),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 11),
QT_MOC_LITERAL(4, 33, 15),
QT_MOC_LITERAL(5, 49, 17),
QT_MOC_LITERAL(6, 67, 5),
QT_MOC_LITERAL(7, 73, 20),
QT_MOC_LITERAL(8, 94, 11),
QT_MOC_LITERAL(9, 106, 14)
    },
    "FakeMenu\0serverStop\0\0serverStart\0"
    "handleInputRead\0handleOutputWrite\0"
    "bytes\0readPendingDatagrams\0clicConnect\0"
    "clicDisconnect\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FakeMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x05,
       3,    0,   50,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x08,
       5,    1,   52,    2, 0x08,
       7,    0,   55,    2, 0x08,
       8,    0,   56,    2, 0x08,
       9,    0,   57,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FakeMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FakeMenu *_t = static_cast<FakeMenu *>(_o);
        switch (_id) {
        case 0: _t->serverStop(); break;
        case 1: _t->serverStart(); break;
        case 2: _t->handleInputRead(); break;
        case 3: _t->handleOutputWrite((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->readPendingDatagrams(); break;
        case 5: _t->clicConnect(); break;
        case 6: _t->clicDisconnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FakeMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FakeMenu::serverStop)) {
                *result = 0;
            }
        }
        {
            typedef void (FakeMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FakeMenu::serverStart)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject FakeMenu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FakeMenu.data,
      qt_meta_data_FakeMenu,  qt_static_metacall, 0, 0}
};


const QMetaObject *FakeMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FakeMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FakeMenu.stringdata))
        return static_cast<void*>(const_cast< FakeMenu*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FakeMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FakeMenu::serverStop()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FakeMenu::serverStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
