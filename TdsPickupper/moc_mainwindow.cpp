/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Jul 3 11:27:33 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      28,   11,   11,   11, 0x08,
      52,   11,   11,   11, 0x08,
      83,   70,   11,   11, 0x08,
      99,   93,   11,   11, 0x08,
     129,   93,   11,   11, 0x08,
     161,   93,   11,   11, 0x08,
     192,   93,   11,   11, 0x08,
     223,   93,   11,   11, 0x08,
     256,   93,   11,   11, 0x08,
     294,  288,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0OpenMovieFile()\0"
    "ExportMaskedMovieFile()\0ExportAsMmmFile()\0"
    "frame_number\0Show(int)\0value\0"
    "ChangeThreshold1RedLower(int)\0"
    "ChangeThreshold1GreenLower(int)\0"
    "ChangeThreshold1BlueLower(int)\0"
    "ChangeThreshold1RedHigher(int)\0"
    "ChangeThreshold1GreenHigher(int)\0"
    "ChangeThreshold1BlueHigher(int)\0index\0"
    "ChangeThresholdFilter(int)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->OpenMovieFile(); break;
        case 1: _t->ExportMaskedMovieFile(); break;
        case 2: _t->ExportAsMmmFile(); break;
        case 3: _t->Show((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ChangeThreshold1RedLower((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->ChangeThreshold1GreenLower((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->ChangeThreshold1BlueLower((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->ChangeThreshold1RedHigher((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->ChangeThreshold1GreenHigher((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->ChangeThreshold1BlueHigher((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->ChangeThresholdFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
