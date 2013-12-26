/****************************************************************************
** Meta object code from reading C++ file 'CreateAccountWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CreateAccountWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateAccountWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateAccountWindow_t {
    QByteArrayData data[8];
    char stringdata[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CreateAccountWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CreateAccountWindow_t qt_meta_stringdata_CreateAccountWindow = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 18),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 11),
QT_MOC_LITERAL(4, 52, 5),
QT_MOC_LITERAL(5, 58, 8),
QT_MOC_LITERAL(6, 67, 23),
QT_MOC_LITERAL(7, 91, 32)
    },
    "CreateAccountWindow\0create_account_try\0"
    "\0std::string\0login\0password\0"
    "on_close_button_clicked\0"
    "on_create_account_button_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateAccountWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   34,    2, 0x0a,
       7,    0,   35,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateAccountWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateAccountWindow *_t = static_cast<CreateAccountWindow *>(_o);
        switch (_id) {
        case 0: _t->create_account_try((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 1: _t->on_close_button_clicked(); break;
        case 2: _t->on_create_account_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateAccountWindow::*_t)(const std::string & , const std::string & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateAccountWindow::create_account_try)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CreateAccountWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateAccountWindow.data,
      qt_meta_data_CreateAccountWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *CreateAccountWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateAccountWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CreateAccountWindow.stringdata))
        return static_cast<void*>(const_cast< CreateAccountWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateAccountWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CreateAccountWindow::create_account_try(const std::string & _t1, const std::string & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
