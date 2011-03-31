/****************************************************************************
** Meta object code from reading C++ file 'etsgame.h'
**
** Created: Wed Mar 30 23:22:24 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../etsgame.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'etsgame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_etsGame[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      43,    8,    8,    8, 0x08,
      70,    8,    8,    8, 0x08,
     102,    8,    8,    8, 0x08,
     134,    8,    8,    8, 0x08,
     166,    8,    8,    8, 0x08,
     198,    8,    8,    8, 0x08,
     230,    8,    8,    8, 0x08,
     262,    8,    8,    8, 0x08,
     294,    8,    8,    8, 0x08,
     326,    8,    8,    8, 0x08,
     358,    8,    8,    8, 0x08,
     389,    8,    8,    8, 0x08,
     421,    8,    8,    8, 0x08,
     455,    8,    8,    8, 0x08,
     485,    8,    8,    8, 0x08,
     511,    8,    8,    8, 0x08,
     539,    8,    8,    8, 0x08,
     548,  546,    8,    8, 0x08,
     574,    8,    8,    8, 0x08,
     586,    8,    8,    8, 0x08,
     597,    8,    8,    8, 0x08,
     608,    8,    8,    8, 0x08,
     615,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_etsGame[] = {
    "etsGame\0\0on_actionCheat_Mode_toggled(bool)\0"
    "on_actionPause_triggered()\0"
    "on_action1600_x_900_triggered()\0"
    "on_action1440_x_900_triggered()\0"
    "on_action1360_x_768_triggered()\0"
    "on_action1280_x_800_triggered()\0"
    "on_action1280_x_768_triggered()\0"
    "on_action1280_x_720_triggered()\0"
    "on_action1280_x_700_triggered()\0"
    "on_action1152_x_824_triggered()\0"
    "on_action1024_x_768_triggered()\0"
    "on_action800_x_600_triggered()\0"
    "on_actionFullscreen_triggered()\0"
    "on_actionChange_Level_triggered()\0"
    "on_actionNew_Game_triggered()\0"
    "keyPressEvent(QKeyEvent*)\0"
    "keyReleaseEvent(QKeyEvent*)\0tick()\0,\0"
    "changeResolution(int,int)\0updateAir()\0"
    "clearAll()\0gameOver()\0save()\0load()\0"
};

const QMetaObject etsGame::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_etsGame,
      qt_meta_data_etsGame, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &etsGame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *etsGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *etsGame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_etsGame))
        return static_cast<void*>(const_cast< etsGame*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int etsGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionCheat_Mode_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: on_actionPause_triggered(); break;
        case 2: on_action1600_x_900_triggered(); break;
        case 3: on_action1440_x_900_triggered(); break;
        case 4: on_action1360_x_768_triggered(); break;
        case 5: on_action1280_x_800_triggered(); break;
        case 6: on_action1280_x_768_triggered(); break;
        case 7: on_action1280_x_720_triggered(); break;
        case 8: on_action1280_x_700_triggered(); break;
        case 9: on_action1152_x_824_triggered(); break;
        case 10: on_action1024_x_768_triggered(); break;
        case 11: on_action800_x_600_triggered(); break;
        case 12: on_actionFullscreen_triggered(); break;
        case 13: on_actionChange_Level_triggered(); break;
        case 14: on_actionNew_Game_triggered(); break;
        case 15: keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 16: keyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 17: tick(); break;
        case 18: changeResolution((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: updateAir(); break;
        case 20: clearAll(); break;
        case 21: gameOver(); break;
        case 22: save(); break;
        case 23: load(); break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
