/****************************************************************************
** Meta object code from reading C++ file 'ydplayermainwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../UPlayer/ydplayermainwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ydplayermainwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
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
struct qt_meta_stringdata_CLASSYDPlayerMainWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSYDPlayerMainWidgetENDCLASS = QtMocHelpers::stringData(
    "YDPlayerMainWidget",
    "t_replay",
    "",
    "resizeEvent",
    "QResizeEvent*",
    "e",
    "eventFilter",
    "obj",
    "QEvent*",
    "event",
    "play",
    "stop",
    "onExit",
    "slotPlayerStarted",
    "slotPlayerStoped",
    "slotPlayerError",
    "QMediaPlayer::Error",
    "slotMediaStatusChanged",
    "QMediaPlayer::MediaStatus",
    "slotPlayerStatusChanged",
    "QMediaPlayer::State",
    "slotMuteChanged",
    "slotVolumeChanged",
    "slotPositionChange",
    "pos",
    "on_btnOpenFile_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSYDPlayerMainWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    1 /* Private */,
       3,    1,  105,    2, 0x08,    2 /* Private */,
       6,    2,  108,    2, 0x08,    4 /* Private */,
      10,    0,  113,    2, 0x08,    7 /* Private */,
      11,    0,  114,    2, 0x08,    8 /* Private */,
      12,    0,  115,    2, 0x0a,    9 /* Public */,
      13,    0,  116,    2, 0x08,   10 /* Private */,
      14,    0,  117,    2, 0x08,   11 /* Private */,
      15,    1,  118,    2, 0x08,   12 /* Private */,
      17,    1,  121,    2, 0x08,   14 /* Private */,
      19,    1,  124,    2, 0x08,   16 /* Private */,
      21,    1,  127,    2, 0x08,   18 /* Private */,
      22,    1,  130,    2, 0x08,   20 /* Private */,
      23,    1,  133,    2, 0x08,   22 /* Private */,
      25,    0,  136,    2, 0x08,   24 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::LongLong,   24,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject YDPlayerMainWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSYDPlayerMainWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSYDPlayerMainWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSYDPlayerMainWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<YDPlayerMainWidget, std::true_type>,
        // method 't_replay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resizeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>,
        // method 'eventFilter'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QEvent *, std::false_type>,
        // method 'play'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onExit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotPlayerStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotPlayerStoped'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotPlayerError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::Error, std::false_type>,
        // method 'slotMediaStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::MediaStatus, std::false_type>,
        // method 'slotPlayerStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::State, std::false_type>,
        // method 'slotMuteChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'slotVolumeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotPositionChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'on_btnOpenFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void YDPlayerMainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<YDPlayerMainWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->t_replay(); break;
        case 1: _t->resizeEvent((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        case 2: { bool _r = _t->eventFilter((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->play(); break;
        case 4: _t->stop(); break;
        case 5: _t->onExit(); break;
        case 6: _t->slotPlayerStarted(); break;
        case 7: _t->slotPlayerStoped(); break;
        case 8: _t->slotPlayerError((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::Error>>(_a[1]))); break;
        case 9: _t->slotMediaStatusChanged((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::MediaStatus>>(_a[1]))); break;
        case 10: _t->slotPlayerStatusChanged((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::State>>(_a[1]))); break;
        case 11: _t->slotMuteChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->slotVolumeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->slotPositionChange((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 14: _t->on_btnOpenFile_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *YDPlayerMainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YDPlayerMainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSYDPlayerMainWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int YDPlayerMainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
