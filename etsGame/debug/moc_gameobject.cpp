/****************************************************************************
** Meta object code from reading C++ file 'gameobject.h'
**
** Created: Mon 28. Mar 19:57:21 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gameobject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_gameObject[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_gameObject[] = {
    "gameObject\0"
};

const QMetaObject gameObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_gameObject,
      qt_meta_data_gameObject, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &gameObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *gameObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *gameObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gameObject))
        return static_cast<void*>(const_cast< gameObject*>(this));
    return QObject::qt_metacast(_clname);
}

int gameObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
