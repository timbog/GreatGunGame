/****************************************************************************
** Meta object code from reading C++ file 'gun.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gun.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gun.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_gun__Gun_t {
    QByteArrayData data[8];
    char stringdata[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_gun__Gun_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_gun__Gun_t qt_meta_stringdata_gun__Gun = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 8),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 5),
QT_MOC_LITERAL(4, 25, 8),
QT_MOC_LITERAL(5, 34, 5),
QT_MOC_LITERAL(6, 40, 13),
QT_MOC_LITERAL(7, 54, 10)
    },
    "gun::Gun\0setAngle\0\0angle\0setPower\0"
    "value\0rotationAngle\0powerLevel\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gun__Gun[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a,
       4,    1,   37,    2, 0x0a,
       6,    0,   40,    2, 0x0a,
       7,    0,   41,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void gun::Gun::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Gun *_t = static_cast<Gun *>(_o);
        switch (_id) {
        case 0: _t->setAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setPower((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { int _r = _t->rotationAngle();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->powerLevel();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject gun::Gun::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_gun__Gun.data,
      qt_meta_data_gun__Gun,  qt_static_metacall, 0, 0}
};


const QMetaObject *gun::Gun::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gun::Gun::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gun__Gun.stringdata))
        return static_cast<void*>(const_cast< Gun*>(this));
    return QObject::qt_metacast(_clname);
}

int gun::Gun::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
