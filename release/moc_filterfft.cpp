/****************************************************************************
** Meta object code from reading C++ file 'filterfft.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../filterfft.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filterfft.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FilterFFT_t {
    QByteArrayData data[22];
    char stringdata0[313];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterFFT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterFFT_t qt_meta_stringdata_FilterFFT = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FilterFFT"
QT_MOC_LITERAL(1, 10, 27), // "on_pushButton_close_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 3), // "DFT"
QT_MOC_LITERAL(4, 43, 14), // "QList<double>&"
QT_MOC_LITERAL(5, 58, 1), // "x"
QT_MOC_LITERAL(6, 60, 1), // "y"
QT_MOC_LITERAL(7, 62, 4), // "iDFT"
QT_MOC_LITERAL(8, 67, 28), // "QList<std::complex<double> >"
QT_MOC_LITERAL(9, 96, 1), // "f"
QT_MOC_LITERAL(10, 98, 10), // "mousePress"
QT_MOC_LITERAL(11, 109, 12), // "QMouseEvent*"
QT_MOC_LITERAL(12, 122, 5), // "event"
QT_MOC_LITERAL(13, 128, 19), // "histogramMouseMoved"
QT_MOC_LITERAL(14, 148, 11), // "spanMouseUp"
QT_MOC_LITERAL(15, 160, 10), // "mouseEvent"
QT_MOC_LITERAL(16, 171, 29), // "on_pushButton_saveTxt_clicked"
QT_MOC_LITERAL(17, 201, 28), // "on_Slider_level_valueChanged"
QT_MOC_LITERAL(18, 230, 5), // "value"
QT_MOC_LITERAL(19, 236, 27), // "on_Slider_sens_valueChanged"
QT_MOC_LITERAL(20, 264, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(21, 286, 26) // "on_SliderSpan_valueChanged"

    },
    "FilterFFT\0on_pushButton_close_clicked\0"
    "\0DFT\0QList<double>&\0x\0y\0iDFT\0"
    "QList<std::complex<double> >\0f\0"
    "mousePress\0QMouseEvent*\0event\0"
    "histogramMouseMoved\0spanMouseUp\0"
    "mouseEvent\0on_pushButton_saveTxt_clicked\0"
    "on_Slider_level_valueChanged\0value\0"
    "on_Slider_sens_valueChanged\0"
    "on_pushButton_clicked\0on_SliderSpan_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterFFT[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    2,   70,    2, 0x08 /* Private */,
       7,    2,   75,    2, 0x08 /* Private */,
      10,    1,   80,    2, 0x08 /* Private */,
      13,    1,   83,    2, 0x08 /* Private */,
      14,    1,   86,    2, 0x08 /* Private */,
      16,    0,   89,    2, 0x08 /* Private */,
      17,    1,   90,    2, 0x08 /* Private */,
      19,    1,   93,    2, 0x08 /* Private */,
      20,    0,   96,    2, 0x08 /* Private */,
      21,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 8,    5,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void FilterFFT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilterFFT *_t = static_cast<FilterFFT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_close_clicked(); break;
        case 1: _t->DFT((*reinterpret_cast< QList<double>(*)>(_a[1])),(*reinterpret_cast< QList<double>(*)>(_a[2]))); break;
        case 2: _t->iDFT((*reinterpret_cast< QList<double>(*)>(_a[1])),(*reinterpret_cast< QList<std::complex<double> >(*)>(_a[2]))); break;
        case 3: _t->mousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->histogramMouseMoved((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->spanMouseUp((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_saveTxt_clicked(); break;
        case 7: _t->on_Slider_level_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_Slider_sens_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_SliderSpan_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject FilterFFT::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FilterFFT.data,
      qt_meta_data_FilterFFT,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FilterFFT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterFFT::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FilterFFT.stringdata0))
        return static_cast<void*>(const_cast< FilterFFT*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FilterFFT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
