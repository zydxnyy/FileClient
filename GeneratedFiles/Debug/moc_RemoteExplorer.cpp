/****************************************************************************
** Meta object code from reading C++ file 'RemoteExplorer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RemoteExplorer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RemoteExplorer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RemoteExplorer_t {
    QByteArrayData data[16];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemoteExplorer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemoteExplorer_t qt_meta_stringdata_RemoteExplorer = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RemoteExplorer"
QT_MOC_LITERAL(1, 15, 14), // "dragFileUpload"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6), // "string"
QT_MOC_LITERAL(4, 38, 13), // "dragUrlUpload"
QT_MOC_LITERAL(5, 52, 8), // "takeFile"
QT_MOC_LITERAL(6, 61, 16), // "menuFileDownload"
QT_MOC_LITERAL(7, 78, 14), // "acceptFileName"
QT_MOC_LITERAL(8, 93, 9), // "acceptUrl"
QT_MOC_LITERAL(9, 103, 4), // "menu"
QT_MOC_LITERAL(10, 108, 7), // "delFile"
QT_MOC_LITERAL(11, 116, 12), // "downloadFile"
QT_MOC_LITERAL(12, 129, 12), // "openProperty"
QT_MOC_LITERAL(13, 142, 11), // "getFileList"
QT_MOC_LITERAL(14, 154, 10), // "getProject"
QT_MOC_LITERAL(15, 165, 5) // "Proj*"

    },
    "RemoteExplorer\0dragFileUpload\0\0string\0"
    "dragUrlUpload\0takeFile\0menuFileDownload\0"
    "acceptFileName\0acceptUrl\0menu\0delFile\0"
    "downloadFile\0openProperty\0getFileList\0"
    "getProject\0Proj*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemoteExplorer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       5,    2,   80,    2, 0x06 /* Public */,
       6,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   88,    2, 0x0a /* Public */,
       8,    1,   91,    2, 0x0a /* Public */,
       9,    1,   94,    2, 0x0a /* Public */,
      10,    1,   97,    2, 0x0a /* Public */,
      11,    1,  100,    2, 0x0a /* Public */,
      12,    1,  103,    2, 0x0a /* Public */,
      13,    0,  106,    2, 0x0a /* Public */,
      14,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    0x80000000 | 15,

       0        // eod
};

void RemoteExplorer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RemoteExplorer *_t = static_cast<RemoteExplorer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dragFileUpload((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->dragUrlUpload((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 2: _t->takeFile((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 3: _t->menuFileDownload((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 4: _t->acceptFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->acceptUrl((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 6: _t->menu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->delFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->downloadFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->openProperty((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->getFileList(); break;
        case 11: { Proj* _r = _t->getProject();
            if (_a[0]) *reinterpret_cast< Proj**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RemoteExplorer::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteExplorer::dragFileUpload)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RemoteExplorer::*)(QUrl );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteExplorer::dragUrlUpload)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RemoteExplorer::*)(string , string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteExplorer::takeFile)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RemoteExplorer::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteExplorer::menuFileDownload)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RemoteExplorer::staticMetaObject = {
    { &MyExplorer::staticMetaObject, qt_meta_stringdata_RemoteExplorer.data,
      qt_meta_data_RemoteExplorer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RemoteExplorer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemoteExplorer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RemoteExplorer.stringdata0))
        return static_cast<void*>(this);
    return MyExplorer::qt_metacast(_clname);
}

int RemoteExplorer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyExplorer::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void RemoteExplorer::dragFileUpload(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RemoteExplorer::dragUrlUpload(QUrl _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RemoteExplorer::takeFile(string _t1, string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RemoteExplorer::menuFileDownload(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
