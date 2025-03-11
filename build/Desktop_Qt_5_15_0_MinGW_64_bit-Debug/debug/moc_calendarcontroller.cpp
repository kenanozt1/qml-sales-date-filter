/****************************************************************************
** Meta object code from reading C++ file 'calendarcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../calendarcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendarcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalendarController_t {
    QByteArrayData data[22];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalendarController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalendarController_t qt_meta_stringdata_CalendarController = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CalendarController"
QT_MOC_LITERAL(1, 19, 12), // "getBeginDate"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 12), // "setBeginDate"
QT_MOC_LITERAL(4, 46, 4), // "date"
QT_MOC_LITERAL(5, 51, 10), // "getEndDate"
QT_MOC_LITERAL(6, 62, 10), // "setEndDate"
QT_MOC_LITERAL(7, 73, 14), // "getReceiptInfo"
QT_MOC_LITERAL(8, 88, 18), // "QList<QStringList>"
QT_MOC_LITERAL(9, 107, 13), // "getOneReceipt"
QT_MOC_LITERAL(10, 121, 14), // "QList<QString>"
QT_MOC_LITERAL(11, 136, 2), // "ID"
QT_MOC_LITERAL(12, 139, 19), // "setSortQueryReceipt"
QT_MOC_LITERAL(13, 159, 4), // "sort"
QT_MOC_LITERAL(14, 164, 19), // "getSortQueryReceipt"
QT_MOC_LITERAL(15, 184, 14), // "setCurrentPage"
QT_MOC_LITERAL(16, 199, 7), // "current"
QT_MOC_LITERAL(17, 207, 14), // "getCurrentPage"
QT_MOC_LITERAL(18, 222, 12), // "setLimitSize"
QT_MOC_LITERAL(19, 235, 5), // "limit"
QT_MOC_LITERAL(20, 241, 12), // "getLimitSize"
QT_MOC_LITERAL(21, 254, 18) // "getTotalQueryCount"

    },
    "CalendarController\0getBeginDate\0\0"
    "setBeginDate\0date\0getEndDate\0setEndDate\0"
    "getReceiptInfo\0QList<QStringList>\0"
    "getOneReceipt\0QList<QString>\0ID\0"
    "setSortQueryReceipt\0sort\0getSortQueryReceipt\0"
    "setCurrentPage\0current\0getCurrentPage\0"
    "setLimitSize\0limit\0getLimitSize\0"
    "getTotalQueryCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalendarController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x02 /* Public */,
       3,    1,   80,    2, 0x02 /* Public */,
       5,    0,   83,    2, 0x02 /* Public */,
       6,    1,   84,    2, 0x02 /* Public */,
       7,    0,   87,    2, 0x02 /* Public */,
       9,    1,   88,    2, 0x02 /* Public */,
      12,    1,   91,    2, 0x02 /* Public */,
      14,    0,   94,    2, 0x02 /* Public */,
      15,    1,   95,    2, 0x02 /* Public */,
      17,    0,   98,    2, 0x02 /* Public */,
      18,    1,   99,    2, 0x02 /* Public */,
      20,    0,  102,    2, 0x02 /* Public */,
      21,    0,  103,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QDate,
    QMetaType::Void, QMetaType::QDate,    4,
    QMetaType::QDate,
    QMetaType::Void, QMetaType::QDate,    4,
    0x80000000 | 8,
    0x80000000 | 10, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void CalendarController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalendarController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QDate _r = _t->getBeginDate();
            if (_a[0]) *reinterpret_cast< QDate*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->setBeginDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 2: { QDate _r = _t->getEndDate();
            if (_a[0]) *reinterpret_cast< QDate*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->setEndDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 4: { QList<QStringList> _r = _t->getReceiptInfo();
            if (_a[0]) *reinterpret_cast< QList<QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 5: { QList<QString> _r = _t->getOneReceipt((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setSortQueryReceipt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: { QString _r = _t->getSortQueryReceipt();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setCurrentPage((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 9: { qint32 _r = _t->getCurrentPage();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->setLimitSize((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 11: { qint32 _r = _t->getLimitSize();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        case 12: { qint32 _r = _t->getTotalQueryCount();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CalendarController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CalendarController.data,
    qt_meta_data_CalendarController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CalendarController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalendarController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalendarController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CalendarController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
