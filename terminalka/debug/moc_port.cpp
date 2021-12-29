/****************************************************************************
** Meta object code from reading C++ file 'port.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../port.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'port.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Port_t {
    const uint offsetsAndSize[44];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Port_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Port_t qt_meta_stringdata_Port = {
    {
QT_MOC_LITERAL(0, 4), // "Port"
QT_MOC_LITERAL(5, 13), // "finished_Port"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 6), // "error_"
QT_MOC_LITERAL(27, 3), // "err"
QT_MOC_LITERAL(31, 7), // "outPort"
QT_MOC_LITERAL(39, 4), // "data"
QT_MOC_LITERAL(44, 14), // "DisconnectPort"
QT_MOC_LITERAL(59, 11), // "ConnectPort"
QT_MOC_LITERAL(71, 19), // "Write_Settings_Port"
QT_MOC_LITERAL(91, 4), // "name"
QT_MOC_LITERAL(96, 8), // "baudrate"
QT_MOC_LITERAL(105, 8), // "DataBits"
QT_MOC_LITERAL(114, 6), // "Parity"
QT_MOC_LITERAL(121, 8), // "StopBits"
QT_MOC_LITERAL(130, 11), // "FlowControl"
QT_MOC_LITERAL(142, 12), // "process_Port"
QT_MOC_LITERAL(155, 11), // "WriteToPort"
QT_MOC_LITERAL(167, 10), // "ReadInPort"
QT_MOC_LITERAL(178, 11), // "handleError"
QT_MOC_LITERAL(190, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(219, 5) // "error"

    },
    "Port\0finished_Port\0\0error_\0err\0outPort\0"
    "data\0DisconnectPort\0ConnectPort\0"
    "Write_Settings_Port\0name\0baudrate\0"
    "DataBits\0Parity\0StopBits\0FlowControl\0"
    "process_Port\0WriteToPort\0ReadInPort\0"
    "handleError\0QSerialPort::SerialPortError\0"
    "error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Port[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,
       3,    1,   75,    2, 0x06,    2 /* Public */,
       5,    1,   78,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   81,    2, 0x0a,    6 /* Public */,
       8,    0,   82,    2, 0x0a,    7 /* Public */,
       9,    6,   83,    2, 0x0a,    8 /* Public */,
      16,    0,   96,    2, 0x0a,   15 /* Public */,
      17,    1,   97,    2, 0x0a,   16 /* Public */,
      18,    0,  100,    2, 0x0a,   18 /* Public */,
      19,    1,  101,    2, 0x08,   19 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   10,   11,   12,   13,   14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,

       0        // eod
};

void Port::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Port *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finished_Port(); break;
        case 1: _t->error_((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->outPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->DisconnectPort(); break;
        case 4: _t->ConnectPort(); break;
        case 5: _t->Write_Settings_Port((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 6: _t->process_Port(); break;
        case 7: _t->WriteToPort((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->ReadInPort(); break;
        case 9: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Port::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Port::finished_Port)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Port::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Port::error_)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Port::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Port::outPort)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Port::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Port.offsetsAndSize,
    qt_meta_data_Port,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Port_t
, QtPrivate::TypeAndForceComplete<Port, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSerialPort::SerialPortError, std::false_type>


>,
    nullptr
} };


const QMetaObject *Port::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Port::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Port.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Port::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Port::finished_Port()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Port::error_(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Port::outPort(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
