/****************************************************************************
** Meta object code from reading C++ file 'debug_window.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "debug_window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'debug_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DebugWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      30,   12,   12,   12, 0x08,
      38,   12,   12,   12, 0x08,
      50,   12,   12,   12, 0x08,
      58,   12,   12,   12, 0x08,
      73,   12,   12,   12, 0x08,
      87,   12,   12,   12, 0x08,
     105,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DebugWindow[] = {
    "DebugWindow\0\0breakHighlight()\0pStep()\0"
    "pContinue()\0pNext()\0errorConfirm()\0"
    "showInspect()\0setInspectValue()\0quit()\0"
};

void DebugWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DebugWindow *_t = static_cast<DebugWindow *>(_o);
        switch (_id) {
        case 0: _t->breakHighlight(); break;
        case 1: _t->pStep(); break;
        case 2: _t->pContinue(); break;
        case 3: _t->pNext(); break;
        case 4: _t->errorConfirm(); break;
        case 5: _t->showInspect(); break;
        case 6: _t->setInspectValue(); break;
        case 7: _t->quit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DebugWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DebugWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DebugWindow,
      qt_meta_data_DebugWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DebugWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DebugWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DebugWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DebugWindow))
        return static_cast<void*>(const_cast< DebugWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int DebugWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
