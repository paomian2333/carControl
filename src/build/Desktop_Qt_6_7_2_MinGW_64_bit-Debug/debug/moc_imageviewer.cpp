/****************************************************************************
** Meta object code from reading C++ file 'imageviewer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../imageviewer.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageviewer.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSImageViewerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSImageViewerENDCLASS = QtMocHelpers::stringData(
    "ImageViewer",
    "on_selectHomeDir_clicked",
    "",
    "on_selectImageFile_clicked",
    "on_readPrevImage_clicked",
    "on_readNextImage_clicked",
    "on_refreshImage_clicked",
    "on_rotateImage_clicked",
    "on_flipImage_clicked",
    "on_zoomInImage_clicked",
    "on_zoomOutImage_clicked",
    "on_extendImage_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSImageViewerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    0,   81,    2, 0x08,    8 /* Private */,
      10,    0,   82,    2, 0x08,    9 /* Private */,
      11,    0,   83,    2, 0x08,   10 /* Private */,

 // slots: parameters
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

Q_CONSTINIT const QMetaObject ImageViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSImageViewerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSImageViewerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSImageViewerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ImageViewer, std::true_type>,
        // method 'on_selectHomeDir_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_selectImageFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_readPrevImage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_readNextImage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_refreshImage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotateImage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_flipImage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_zoomInImage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_zoomOutImage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_extendImage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ImageViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageViewer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_selectHomeDir_clicked(); break;
        case 1: _t->on_selectImageFile_clicked(); break;
        case 2: _t->on_readPrevImage_clicked(); break;
        case 3: _t->on_readNextImage_clicked(); break;
        case 4: _t->on_refreshImage_clicked(); break;
        case 5: _t->on_rotateImage_clicked(); break;
        case 6: _t->on_flipImage_clicked(); break;
        case 7: _t->on_zoomInImage_clicked(); break;
        case 8: _t->on_zoomOutImage_clicked(); break;
        case 9: _t->on_extendImage_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *ImageViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSImageViewerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ImageViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
