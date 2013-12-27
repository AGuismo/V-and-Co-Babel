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
    QByteArrayData data[23];
    char stringdata[401];
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
QT_MOC_LITERAL(4, 63, 26),
QT_MOC_LITERAL(5, 90, 34),
QT_MOC_LITERAL(6, 125, 34),
QT_MOC_LITERAL(7, 160, 38),
QT_MOC_LITERAL(8, 199, 14),
QT_MOC_LITERAL(9, 214, 11),
QT_MOC_LITERAL(10, 226, 9),
QT_MOC_LITERAL(11, 236, 18),
QT_MOC_LITERAL(12, 255, 4),
QT_MOC_LITERAL(13, 260, 12),
QT_MOC_LITERAL(14, 273, 5),
QT_MOC_LITERAL(15, 279, 8),
QT_MOC_LITERAL(16, 288, 13),
QT_MOC_LITERAL(17, 302, 13),
QT_MOC_LITERAL(18, 316, 22),
QT_MOC_LITERAL(19, 339, 15),
QT_MOC_LITERAL(20, 355, 11),
QT_MOC_LITERAL(21, 367, 21),
QT_MOC_LITERAL(22, 389, 10)
    },
    "Graphic\0on_connect_window_triggered\0"
    "\0on_login_window_triggered\0"
    "on_logout_window_triggered\0"
    "on_create_account_window_triggered\0"
    "on_delete_account_window_triggered\0"
    "on_account_management_window_triggered\0"
    "on_try_connect\0std::string\0ipAddress\0"
    "unsigned short int\0port\0on_try_login\0"
    "login\0password\0on_try_create\0on_try_delete\0"
    "on_try_change_password\0currentPassword\0"
    "newPassword\0on_try_change_privacy\0"
    "newPrivacy\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Graphic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a,
       3,    0,   75,    2, 0x0a,
       4,    0,   76,    2, 0x0a,
       5,    0,   77,    2, 0x0a,
       6,    0,   78,    2, 0x0a,
       7,    0,   79,    2, 0x0a,
       8,    2,   80,    2, 0x0a,
      13,    2,   85,    2, 0x0a,
      16,    2,   90,    2, 0x0a,
      17,    2,   95,    2, 0x0a,
      18,    2,  100,    2, 0x0a,
      21,    1,  105,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11,   10,   12,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,   14,   15,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,   14,   15,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,   14,   15,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,   19,   20,
    QMetaType::Void, QMetaType::Bool,   22,

       0        // eod
};

void Graphic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Graphic *_t = static_cast<Graphic *>(_o);
        switch (_id) {
        case 0: _t->on_connect_window_triggered(); break;
        case 1: _t->on_login_window_triggered(); break;
        case 2: _t->on_logout_window_triggered(); break;
        case 3: _t->on_create_account_window_triggered(); break;
        case 4: _t->on_delete_account_window_triggered(); break;
        case 5: _t->on_account_management_window_triggered(); break;
        case 6: _t->on_try_connect((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< unsigned short int(*)>(_a[2]))); break;
        case 7: _t->on_try_login((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 8: _t->on_try_create((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 9: _t->on_try_delete((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 10: _t->on_try_change_password((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 11: _t->on_try_change_privacy((*reinterpret_cast< bool(*)>(_a[1]))); break;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
