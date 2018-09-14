/****************************************************************************
** Meta object code from reading C++ file 'FileClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FileClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileClient_t {
    QByteArrayData data[11];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileClient_t qt_meta_stringdata_FileClient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FileClient"
QT_MOC_LITERAL(1, 11, 13), // "updateFileDir"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "QString&"
QT_MOC_LITERAL(4, 35, 7), // "MyFile*"
QT_MOC_LITERAL(5, 43, 12), // "get_projects"
QT_MOC_LITERAL(6, 56, 8), // "takeFile"
QT_MOC_LITERAL(7, 65, 6), // "string"
QT_MOC_LITERAL(8, 72, 7), // "refresh"
QT_MOC_LITERAL(9, 80, 8), // "reVerify"
QT_MOC_LITERAL(10, 89, 10) // "switchUser"

    },
    "FileClient\0updateFileDir\0\0QString&\0"
    "MyFile*\0get_projects\0takeFile\0string\0"
    "refresh\0reVerify\0switchUser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x0a /* Public */,
       5,    0,   49,    2, 0x0a /* Public */,
       6,    2,   50,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,
       9,    0,   56,    2, 0x0a /* Public */,
      10,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FileClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileClient *_t = static_cast<FileClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateFileDir((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< MyFile*(*)>(_a[2]))); break;
        case 1: { int _r = _t->get_projects();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->takeFile((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 3: _t->refresh(); break;
        case 4: _t->reVerify(); break;
        case 5: _t->switchUser(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileClient::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FileClient.data,
      qt_meta_data_FileClient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FileClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileClient.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FileClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
