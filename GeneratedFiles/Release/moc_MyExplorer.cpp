/****************************************************************************
** Meta object code from reading C++ file 'MyExplorer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyExplorer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyExplorer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyExplorer_t {
    QByteArrayData data[14];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyExplorer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyExplorer_t qt_meta_stringdata_MyExplorer = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MyExplorer"
QT_MOC_LITERAL(1, 11, 8), // "enterDir"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "string"
QT_MOC_LITERAL(4, 28, 6), // "outDir"
QT_MOC_LITERAL(5, 35, 4), // "next"
QT_MOC_LITERAL(6, 40, 8), // "previous"
QT_MOC_LITERAL(7, 49, 12), // "enterDirSlot"
QT_MOC_LITERAL(8, 62, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 74, 10), // "enterPress"
QT_MOC_LITERAL(10, 85, 14), // "updateFileList"
QT_MOC_LITERAL(11, 100, 14), // "acceptFileName"
QT_MOC_LITERAL(12, 115, 9), // "acceptUrl"
QT_MOC_LITERAL(13, 125, 4) // "menu"

    },
    "MyExplorer\0enterDir\0\0string\0outDir\0"
    "next\0previous\0enterDirSlot\0QModelIndex\0"
    "enterPress\0updateFileList\0acceptFileName\0"
    "acceptUrl\0menu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyExplorer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       4,    0,   67,    2, 0x0a /* Public */,
       5,    0,   68,    2, 0x0a /* Public */,
       6,    0,   69,    2, 0x0a /* Public */,
       7,    1,   70,    2, 0x0a /* Public */,
       9,    0,   73,    2, 0x0a /* Public */,
      10,    0,   74,    2, 0x0a /* Public */,
      11,    1,   75,    2, 0x0a /* Public */,
      12,    1,   78,    2, 0x0a /* Public */,
      13,    1,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::Void, QMetaType::QPoint,    2,

       0        // eod
};

void MyExplorer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyExplorer *_t = static_cast<MyExplorer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enterDir((*reinterpret_cast< const string(*)>(_a[1]))); break;
        case 1: _t->outDir(); break;
        case 2: _t->next(); break;
        case 3: _t->previous(); break;
        case 4: _t->enterDirSlot((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->enterPress(); break;
        case 6: _t->updateFileList(); break;
        case 7: _t->acceptFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->acceptUrl((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 9: _t->menu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyExplorer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyExplorer.data,
      qt_meta_data_MyExplorer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyExplorer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyExplorer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyExplorer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MyExplorer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
