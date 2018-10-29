/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[414];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "mousePress"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 36, 5), // "event"
QT_MOC_LITERAL(5, 42, 19), // "on_action_triggered"
QT_MOC_LITERAL(6, 62, 21), // "on_action_2_triggered"
QT_MOC_LITERAL(7, 84, 21), // "on_action_3_triggered"
QT_MOC_LITERAL(8, 106, 21), // "on_action_4_triggered"
QT_MOC_LITERAL(9, 128, 21), // "on_action_5_triggered"
QT_MOC_LITERAL(10, 150, 21), // "on_action_7_triggered"
QT_MOC_LITERAL(11, 172, 21), // "on_action_8_triggered"
QT_MOC_LITERAL(12, 194, 21), // "on_action_9_triggered"
QT_MOC_LITERAL(13, 216, 22), // "on_action_11_triggered"
QT_MOC_LITERAL(14, 239, 22), // "on_action_10_triggered"
QT_MOC_LITERAL(15, 262, 33), // "on_doubleSpinBox1_editingFini..."
QT_MOC_LITERAL(16, 296, 22), // "on_action_12_triggered"
QT_MOC_LITERAL(17, 319, 25), // "on_action_delta_triggered"
QT_MOC_LITERAL(18, 345, 22), // "on_action_13_triggered"
QT_MOC_LITERAL(19, 368, 22), // "on_action_18_triggered"
QT_MOC_LITERAL(20, 391, 22) // "on_action_20_triggered"

    },
    "MainWindow\0mousePress\0\0QMouseEvent*\0"
    "event\0on_action_triggered\0"
    "on_action_2_triggered\0on_action_3_triggered\0"
    "on_action_4_triggered\0on_action_5_triggered\0"
    "on_action_7_triggered\0on_action_8_triggered\0"
    "on_action_9_triggered\0on_action_11_triggered\0"
    "on_action_10_triggered\0"
    "on_doubleSpinBox1_editingFinished\0"
    "on_action_12_triggered\0on_action_delta_triggered\0"
    "on_action_13_triggered\0on_action_18_triggered\0"
    "on_action_20_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,
      19,    0,  116,    2, 0x08 /* Private */,
      20,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->on_action_triggered(); break;
        case 2: _t->on_action_2_triggered(); break;
        case 3: _t->on_action_3_triggered(); break;
        case 4: _t->on_action_4_triggered(); break;
        case 5: _t->on_action_5_triggered(); break;
        case 6: _t->on_action_7_triggered(); break;
        case 7: _t->on_action_8_triggered(); break;
        case 8: _t->on_action_9_triggered(); break;
        case 9: _t->on_action_11_triggered(); break;
        case 10: _t->on_action_10_triggered(); break;
        case 11: _t->on_doubleSpinBox1_editingFinished(); break;
        case 12: _t->on_action_12_triggered(); break;
        case 13: _t->on_action_delta_triggered(); break;
        case 14: _t->on_action_13_triggered(); break;
        case 15: _t->on_action_18_triggered(); break;
        case 16: _t->on_action_20_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
