/****************************************************************************
** Meta object code from reading C++ file 'Picaria.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Picaria/Picaria.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Picaria.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Picaria_t {
    QByteArrayData data[22];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Picaria_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Picaria_t qt_meta_stringdata_Picaria = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Picaria"
QT_MOC_LITERAL(1, 8, 11), // "modeChanged"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "Picaria::Mode"
QT_MOC_LITERAL(4, 35, 4), // "mode"
QT_MOC_LITERAL(5, 40, 4), // "play"
QT_MOC_LITERAL(6, 45, 2), // "id"
QT_MOC_LITERAL(7, 48, 5), // "reset"
QT_MOC_LITERAL(8, 54, 9), // "showAbout"
QT_MOC_LITERAL(9, 64, 10), // "updateMode"
QT_MOC_LITERAL(10, 75, 8), // "QAction*"
QT_MOC_LITERAL(11, 84, 6), // "action"
QT_MOC_LITERAL(12, 91, 15), // "updateStatusBar"
QT_MOC_LITERAL(13, 107, 4), // "Mode"
QT_MOC_LITERAL(14, 112, 9), // "NineHoles"
QT_MOC_LITERAL(15, 122, 13), // "ThirteenHoles"
QT_MOC_LITERAL(16, 136, 6), // "Player"
QT_MOC_LITERAL(17, 143, 9), // "RedPlayer"
QT_MOC_LITERAL(18, 153, 10), // "BluePlayer"
QT_MOC_LITERAL(19, 164, 5), // "Phase"
QT_MOC_LITERAL(20, 170, 9), // "DropPhase"
QT_MOC_LITERAL(21, 180, 9) // "MovePhase"

    },
    "Picaria\0modeChanged\0\0Picaria::Mode\0"
    "mode\0play\0id\0reset\0showAbout\0updateMode\0"
    "QAction*\0action\0updateStatusBar\0Mode\0"
    "NineHoles\0ThirteenHoles\0Player\0RedPlayer\0"
    "BluePlayer\0Phase\0DropPhase\0MovePhase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Picaria[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   56, // properties
       3,   60, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,
       9,    1,   52,    2, 0x08 /* Private */,
      12,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,

 // properties: name, type, flags
       4, 0x80000000 | 3, 0x0049510b,

 // properties: notify_signal_id
       0,

 // enums: name, alias, flags, count, data
      13,   13, 0x0,    2,   75,
      16,   16, 0x0,    2,   79,
      19,   19, 0x0,    2,   83,

 // enum data: key, value
      14, uint(Picaria::NineHoles),
      15, uint(Picaria::ThirteenHoles),
      17, uint(Picaria::RedPlayer),
      18, uint(Picaria::BluePlayer),
      20, uint(Picaria::DropPhase),
      21, uint(Picaria::MovePhase),

       0        // eod
};

void Picaria::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Picaria *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modeChanged((*reinterpret_cast< Picaria::Mode(*)>(_a[1]))); break;
        case 1: _t->play((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->reset(); break;
        case 3: _t->showAbout(); break;
        case 4: _t->updateMode((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 5: _t->updateStatusBar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Picaria::*)(Picaria::Mode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Picaria::modeChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Picaria *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Picaria::Mode*>(_v) = _t->mode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Picaria *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMode(*reinterpret_cast< Picaria::Mode*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Picaria::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Picaria.data,
    qt_meta_data_Picaria,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Picaria::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Picaria::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Picaria.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Picaria::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Picaria::modeChanged(Picaria::Mode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
