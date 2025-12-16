/****************************************************************************
** Meta object code from reading C++ file 'DailyPlannerApp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.16)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../header/application/DailyPlannerApp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DailyPlannerApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.16. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DailyPlannerApp_t {
    QByteArrayData data[10];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DailyPlannerApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DailyPlannerApp_t qt_meta_stringdata_DailyPlannerApp = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DailyPlannerApp"
QT_MOC_LITERAL(1, 16, 7), // "addTask"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 18), // "showAllTasksWindow"
QT_MOC_LITERAL(4, 44, 8), // "saveData"
QT_MOC_LITERAL(5, 53, 8), // "loadData"
QT_MOC_LITERAL(6, 62, 7), // "nextDay"
QT_MOC_LITERAL(7, 70, 7), // "prevDay"
QT_MOC_LITERAL(8, 78, 13), // "updateDisplay"
QT_MOC_LITERAL(9, 92, 14) // "onTasksUpdated"

    },
    "DailyPlannerApp\0addTask\0\0showAllTasksWindow\0"
    "saveData\0loadData\0nextDay\0prevDay\0"
    "updateDisplay\0onTasksUpdated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DailyPlannerApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
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

void DailyPlannerApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DailyPlannerApp *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addTask(); break;
        case 1: _t->showAllTasksWindow(); break;
        case 2: _t->saveData(); break;
        case 3: _t->loadData(); break;
        case 4: _t->nextDay(); break;
        case 5: _t->prevDay(); break;
        case 6: _t->updateDisplay(); break;
        case 7: _t->onTasksUpdated(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject DailyPlannerApp::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_DailyPlannerApp.data,
    qt_meta_data_DailyPlannerApp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DailyPlannerApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DailyPlannerApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DailyPlannerApp.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DailyPlannerApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
