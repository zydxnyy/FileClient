/****************************************************************************
** Meta object code from reading C++ file 'fileItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../fileItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileItem_t {
    QByteArrayData data[10];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileItem_t qt_meta_stringdata_FileItem = {
    {
QT_MOC_LITERAL(0, 0, 8), // "FileItem"
QT_MOC_LITERAL(1, 9, 12), // "update_speed"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "update_pb"
QT_MOC_LITERAL(4, 33, 8), // "complete"
QT_MOC_LITERAL(5, 42, 4), // "done"
QT_MOC_LITERAL(6, 47, 9), // "FileItem*"
QT_MOC_LITERAL(7, 57, 17), // "update_speed_slot"
QT_MOC_LITERAL(8, 75, 14), // "update_pb_slot"
QT_MOC_LITERAL(9, 90, 13) // "complete_slot"

    },
    "FileItem\0update_speed\0\0update_pb\0"
    "complete\0done\0FileItem*\0update_speed_slot\0"
    "update_pb_slot\0complete_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       4,    1,   55,    2, 0x06 /* Public */,
       5,    2,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   63,    2, 0x0a /* Public */,
       8,    1,   66,    2, 0x0a /* Public */,
       9,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Int, QMetaType::Double,    2,
    QMetaType::Int, QMetaType::Int,    2,
    QMetaType::Int, QMetaType::Int,    2,
    QMetaType::Int, 0x80000000 | 6, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Int, QMetaType::Double,    2,
    QMetaType::Int, QMetaType::Int,    2,
    QMetaType::Int, QMetaType::Int,    2,

       0        // eod
};

void FileItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileItem *_t = static_cast<FileItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->update_speed((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->update_pb((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->complete((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->done((*reinterpret_cast< FileItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->update_speed_slot((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->update_pb_slot((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->complete_slot((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FileItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = int (FileItem::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileItem::update_speed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = int (FileItem::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileItem::update_pb)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = int (FileItem::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileItem::complete)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = int (FileItem::*)(FileItem * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileItem::done)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FileItem.data,
      qt_meta_data_FileItem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FileItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileItem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FileItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
int FileItem::update_speed(double _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int FileItem::update_pb(int _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
int FileItem::complete(int _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}

// SIGNAL 3
int FileItem::done(FileItem * _t1, int _t2)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
