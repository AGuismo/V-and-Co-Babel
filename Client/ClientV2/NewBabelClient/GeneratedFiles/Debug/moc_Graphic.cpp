/****************************************************************************
** Meta object code from reading C++ file 'Graphic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Graphic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Graphic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Graphic_t {
    QByteArrayData data[13];
    char stringdata[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Graphic_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Graphic_t qt_meta_stringdata_Graphic = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 27),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 25),
QT_MOC_LITERAL(4, 63, 14),
QT_MOC_LITERAL(5, 78, 11),
QT_MOC_LITERAL(6, 90, 9),
QT_MOC_LITERAL(7, 100, 18),
QT_MOC_LITERAL(8, 119, 4),
QT_MOC_LITERAL(9, 124, 12),
QT_MOC_LITERAL(10, 137, 5),
QT_MOC_LITERAL(11, 143, 12),
QT_MOC_LITERAL(12, 156, 8)
    },
    "Graphic\0on_connect_window_triggered\0"
    "\0on_login_window_triggered\0on_try_connect\0"
    "std::string\0ipAddress\0unsigned short int\0"
    "port\0on_try_login\0login\0std::string&\0"
    "password\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Graphic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a,
       3,    0,   35,    2, 0x0a,
       4,    2,   36,    2, 0x0a,
       9,    2,   41,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 11,   10,   12,

       0        // eod
};

void Graphic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Graphic *_t = static_cast<Graphic *>(_o);
        switch (_id) {
        case 0: _t->on_connect_window_triggered(); break;
        case 1: _t->on_login_window_triggered(); break;
        case 2: _t->on_try_connect((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< unsigned short int(*)>(_a[2]))); break;
        case 3: _t->on_try_login((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Graphic::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Graphic.data,
      qt_meta_data_Graphic,  qt_static_metacall, 0, 0}
};


const QMetaObject *Graphic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Graphic::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Graphic.stringdata))
        return static_cast<void*>(const_cast< Graphic*>(this));
    if (!strcmp(_clname, "AGraphic"))
        return static_cast< AGraphic*>(const_cast< Graphic*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Graphic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
