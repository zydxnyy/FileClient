/****************************************************************************
** Meta object code from reading C++ file 'TaskWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TaskWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TaskWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TaskWidget_t {
    QByteArrayData data[18];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TaskWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TaskWidget_t qt_meta_stringdata_TaskWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TaskWidget"
QT_MOC_LITERAL(1, 11, 13), // "appendHistory"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "QString&"
QT_MOC_LITERAL(4, 35, 13), // "updateFileDir"
QT_MOC_LITERAL(5, 49, 1), // "s"
QT_MOC_LITERAL(6, 51, 7), // "MyFile*"
QT_MOC_LITERAL(7, 59, 1), // "f"
QT_MOC_LITERAL(8, 61, 13), // "addUploadTask"
QT_MOC_LITERAL(9, 75, 6), // "string"
QT_MOC_LITERAL(10, 82, 4), // "path"
QT_MOC_LITERAL(11, 87, 8), // "projName"
QT_MOC_LITERAL(12, 96, 15), // "addDownloadTask"
QT_MOC_LITERAL(13, 112, 8), // "filename"
QT_MOC_LITERAL(14, 121, 8), // "doneSlot"
QT_MOC_LITERAL(15, 130, 9), // "TaskItem*"
QT_MOC_LITERAL(16, 140, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(17, 157, 6) // "status"

    },
    "TaskWidget\0appendHistory\0\0QString&\0"
    "updateFileDir\0s\0MyFile*\0f\0addUploadTask\0"
    "string\0path\0projName\0addDownloadTask\0"
    "filename\0doneSlot\0TaskItem*\0"
    "QListWidgetItem*\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaskWidget[] = {

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
       4,    2,   52,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x26 /* Public | MethodCloned */,
       4,    0,   60,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   61,    2, 0x0a /* Public */,
      12,    3,   66,    2, 0x0a /* Public */,
      14,    3,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    5,    7,
    QMetaType::Void, 0x80000000 | 3,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,   10,   11,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9,   11,   13,   10,
    QMetaType::Int, 0x80000000 | 15, 0x80000000 | 16, QMetaType::Int,    2,    2,   17,

       0        // eod
};

void TaskWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TaskWidget *_t = static_cast<TaskWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->appendHistory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->updateFileDir((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< MyFile*(*)>(_a[2]))); break;
        case 2: _t->updateFileDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->updateFileDir(); break;
        case 4: _t->addUploadTask((*reinterpret_cast< const string(*)>(_a[1])),(*reinterpret_cast< const string(*)>(_a[2]))); break;
        case 5: _t->addDownloadTask((*reinterpret_cast< const string(*)>(_a[1])),(*reinterpret_cast< const string(*)>(_a[2])),(*reinterpret_cast< const string(*)>(_a[3]))); break;
        case 6: { int _r = _t->doneSlot((*reinterpret_cast< TaskItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
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
            using _t = void (TaskWidget::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskWidget::appendHistory)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TaskWidget::*)(QString & , MyFile * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskWidget::updateFileDir)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TaskWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TaskWidget.data,
      qt_meta_data_TaskWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TaskWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaskWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TaskWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TaskWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TaskWidget::appendHistory(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TaskWidget::updateFileDir(QString & _t1, MyFile * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
