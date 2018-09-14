/****************************************************************************
** Meta object code from reading C++ file 'LocalExplorer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LocalExplorer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LocalExplorer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LocalExplorer_t {
    QByteArrayData data[15];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LocalExplorer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LocalExplorer_t qt_meta_stringdata_LocalExplorer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "LocalExplorer"
QT_MOC_LITERAL(1, 14, 16), // "dragFileDownload"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 6), // "string"
QT_MOC_LITERAL(4, 39, 14), // "menuFileUpload"
QT_MOC_LITERAL(5, 54, 16), // "indexChangedSlot"
QT_MOC_LITERAL(6, 71, 14), // "acceptFileName"
QT_MOC_LITERAL(7, 86, 9), // "acceptUrl"
QT_MOC_LITERAL(8, 96, 4), // "menu"
QT_MOC_LITERAL(9, 101, 12), // "enterDirSlot"
QT_MOC_LITERAL(10, 114, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 126, 10), // "uploadFile"
QT_MOC_LITERAL(12, 137, 8), // "openFile"
QT_MOC_LITERAL(13, 146, 7), // "delFile"
QT_MOC_LITERAL(14, 154, 12) // "openProperty"

    },
    "LocalExplorer\0dragFileDownload\0\0string\0"
    "menuFileUpload\0indexChangedSlot\0"
    "acceptFileName\0acceptUrl\0menu\0"
    "enterDirSlot\0QModelIndex\0uploadFile\0"
    "openFile\0delFile\0openProperty"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LocalExplorer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   75,    2, 0x0a /* Public */,
       6,    1,   78,    2, 0x0a /* Public */,
       7,    1,   81,    2, 0x0a /* Public */,
       8,    1,   84,    2, 0x0a /* Public */,
       9,    1,   87,    2, 0x0a /* Public */,
      11,    1,   90,    2, 0x0a /* Public */,
      12,    1,   93,    2, 0x0a /* Public */,
      13,    1,   96,    2, 0x0a /* Public */,
      14,    1,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Int, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void LocalExplorer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LocalExplorer *_t = static_cast<LocalExplorer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dragFileDownload((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->menuFileUpload((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: { int _r = _t->indexChangedSlot((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->acceptFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->acceptUrl((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 5: _t->menu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->enterDirSlot((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 7: _t->uploadFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->openFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->delFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->openProperty((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LocalExplorer::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LocalExplorer::dragFileDownload)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LocalExplorer::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LocalExplorer::menuFileUpload)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LocalExplorer::staticMetaObject = {
    { &MyExplorer::staticMetaObject, qt_meta_stringdata_LocalExplorer.data,
      qt_meta_data_LocalExplorer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LocalExplorer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LocalExplorer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LocalExplorer.stringdata0))
        return static_cast<void*>(this);
    return MyExplorer::qt_metacast(_clname);
}

int LocalExplorer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyExplorer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void LocalExplorer::dragFileDownload(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LocalExplorer::menuFileUpload(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
