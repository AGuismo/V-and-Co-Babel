/****************************************************************************
** Meta object code from reading C++ file 'AccountManagementWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AccountManagementWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AccountManagementWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AccountManagementWindow_t {
    QByteArrayData data[11];
    char stringdata[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AccountManagementWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AccountManagementWindow_t qt_meta_stringdata_AccountManagementWindow = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 19),
QT_MOC_LITERAL(2, 44, 0),
QT_MOC_LITERAL(3, 45, 11),
QT_MOC_LITERAL(4, 57, 14),
QT_MOC_LITERAL(5, 72, 11),
QT_MOC_LITERAL(6, 84, 18),
QT_MOC_LITERAL(7, 103, 10),
QT_MOC_LITERAL(8, 114, 23),
QT_MOC_LITERAL(9, 138, 33),
QT_MOC_LITERAL(10, 172, 32)
    },
    "AccountManagementWindow\0change_password_try\0"
    "\0std::string\0curentPassword\0newPassword\0"
    "change_privacy_try\0newPrivacy\0"
    "on_close_button_clicked\0"
    "on_change_password_button_clicked\0"
    "on_change_privacy_button_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccountManagementWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x05,
       6,    1,   44,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       8,    0,   47,    2, 0x0a,
       9,    0,   48,    2, 0x0a,
      10,    0,   49,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, QMetaType::Bool,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AccountManagementWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AccountManagementWindow *_t = static_cast<AccountManagementWindow *>(_o);
        switch (_id) {
        case 0: _t->change_password_try((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 1: _t->change_privacy_try((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_close_button_clicked(); break;
        case 3: _t->on_change_password_button_clicked(); break;
        case 4: _t->on_change_privacy_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AccountManagementWindow::*_t)(const std::string & , const std::string & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AccountManagementWindow::change_password_try)) {
                *result = 0;
            }
        }
        {
            typedef void (AccountManagementWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AccountManagementWindow::change_privacy_try)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject AccountManagementWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AccountManagementWindow.data,
      qt_meta_data_AccountManagementWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *AccountManagementWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountManagementWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AccountManagementWindow.stringdata))
        return static_cast<void*>(const_cast< AccountManagementWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int AccountManagementWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AccountManagementWindow::change_password_try(const std::string & _t1, const std::string & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AccountManagementWindow::change_privacy_try(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
