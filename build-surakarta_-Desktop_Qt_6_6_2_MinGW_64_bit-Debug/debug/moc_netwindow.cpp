/****************************************************************************
** Meta object code from reading C++ file 'netwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../surakarta_/netwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'netwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSnetwindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSnetwindowENDCLASS = QtMocHelpers::stringData(
    "netwindow",
    "connected_successfully",
    "",
    "connectToServer",
    "disconnectFromServer",
    "sendMessage",
    "receiveMessage",
    "NetworkData",
    "on_BlackrBtn_clicked",
    "checked",
    "on_WhiterBtn_clicked",
    "on_applyGame_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSnetwindowENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[10];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[21];
    char stringdata5[12];
    char stringdata6[15];
    char stringdata7[12];
    char stringdata8[21];
    char stringdata9[8];
    char stringdata10[21];
    char stringdata11[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSnetwindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSnetwindowENDCLASS_t qt_meta_stringdata_CLASSnetwindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "netwindow"
        QT_MOC_LITERAL(10, 22),  // "connected_successfully"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 15),  // "connectToServer"
        QT_MOC_LITERAL(50, 20),  // "disconnectFromServer"
        QT_MOC_LITERAL(71, 11),  // "sendMessage"
        QT_MOC_LITERAL(83, 14),  // "receiveMessage"
        QT_MOC_LITERAL(98, 11),  // "NetworkData"
        QT_MOC_LITERAL(110, 20),  // "on_BlackrBtn_clicked"
        QT_MOC_LITERAL(131, 7),  // "checked"
        QT_MOC_LITERAL(139, 20),  // "on_WhiterBtn_clicked"
        QT_MOC_LITERAL(160, 20)   // "on_applyGame_clicked"
    },
    "netwindow",
    "connected_successfully",
    "",
    "connectToServer",
    "disconnectFromServer",
    "sendMessage",
    "receiveMessage",
    "NetworkData",
    "on_BlackrBtn_clicked",
    "checked",
    "on_WhiterBtn_clicked",
    "on_applyGame_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSnetwindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    1,   66,    2, 0x08,    5 /* Private */,
       8,    1,   69,    2, 0x08,    7 /* Private */,
      10,    1,   72,    2, 0x08,    9 /* Private */,
      11,    0,   75,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject netwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<Widget::staticMetaObject>(),
    qt_meta_stringdata_CLASSnetwindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSnetwindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSnetwindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<netwindow, std::true_type>,
        // method 'connected_successfully'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectToServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnectFromServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'receiveMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<NetworkData, std::false_type>,
        // method 'on_BlackrBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_WhiterBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_applyGame_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void netwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<netwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connected_successfully(); break;
        case 1: _t->connectToServer(); break;
        case 2: _t->disconnectFromServer(); break;
        case 3: _t->sendMessage(); break;
        case 4: _t->receiveMessage((*reinterpret_cast< std::add_pointer_t<NetworkData>>(_a[1]))); break;
        case 5: _t->on_BlackrBtn_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->on_WhiterBtn_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->on_applyGame_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *netwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *netwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSnetwindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return Widget::qt_metacast(_clname);
}

int netwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
