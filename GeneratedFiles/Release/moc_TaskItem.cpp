/****************************************************************************
** Meta object code from reading C++ file 'TaskItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TaskItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TaskItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TaskItem_t {
    QByteArrayData data[16];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TaskItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TaskItem_t qt_meta_stringdata_TaskItem = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TaskItem"
QT_MOC_LITERAL(1, 9, 12), // "update_speed"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "update_pb"
QT_MOC_LITERAL(4, 33, 8), // "complete"
QT_MOC_LITERAL(5, 42, 14), // "updateFilesize"
QT_MOC_LITERAL(6, 57, 6), // "size_t"
QT_MOC_LITERAL(7, 64, 4), // "done"
QT_MOC_LITERAL(8, 69, 9), // "TaskItem*"
QT_MOC_LITERAL(9, 79, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 96, 17), // "update_speed_slot"
QT_MOC_LITERAL(11, 114, 14), // "update_pb_slot"
QT_MOC_LITERAL(12, 129, 13), // "complete_slot"
QT_MOC_LITERAL(13, 143, 10), // "toggleSlot"
QT_MOC_LITERAL(14, 154, 8), // "stopSlot"
QT_MOC_LITERAL(15, 163, 18) // "updateFilesizeSlot"

    },
    "TaskItem\0update_speed\0\0update_pb\0"
    "complete\0updateFilesize\0size_t\0done\0"
    "TaskItem*\0QListWidgetItem*\0update_speed_slot\0"
    "update_pb_slot\0complete_slot\0toggleSlot\0"
    "stopSlot\0updateFilesizeSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaskItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       3,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       5,    1,   80,    2, 0x06 /* Public */,
       7,    3,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   90,    2, 0x0a /* Public */,
      11,    1,   95,    2, 0x0a /* Public */,
      12,    1,   98,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    1,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Int, QMetaType::Double, QMetaType::Int,    2,    2,
    QMetaType::Int, QMetaType::Int,    2,
    QMetaType::Int, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Int, 0x80000000 | 8, 0x80000000 | 9, QMetaType::Int,    2,    2,    2,

 // slots: parameters
    QMetaType::Int, QMetaType::Double, QMetaType::Int,    2,    2,
    QMetaType::Int, QMetaType::Int,    2,
    QMetaType::Int, QMetaType::Int,    2,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void TaskItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TaskItem *_t = static_cast<TaskItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->update_speed((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->update_pb((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->complete((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->updateFilesize((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 4: { int _r = _t->done((*reinterpret_cast< TaskItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->update_speed_slot((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->update_pb_slot((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->complete_slot((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->toggleSlot();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->stopSlot();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->updateFilesizeSlot((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TaskItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = int (TaskItem::*)(double , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskItem::update_speed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = int (TaskItem::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskItem::update_pb)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = int (TaskItem::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskItem::complete)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TaskItem::*)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskItem::updateFilesize)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = int (TaskItem::*)(TaskItem * , QListWidgetItem * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskItem::done)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TaskItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TaskItem.data,
      qt_meta_data_TaskItem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TaskItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaskItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TaskItem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TaskItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
int TaskItem::update_speed(double _t1, int _t2)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int TaskItem::update_pb(int _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
int TaskItem::complete(int _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}

// SIGNAL 3
void TaskItem::updateFilesize(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
int TaskItem::done(TaskItem * _t1, QListWidgetItem * _t2, int _t3)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
