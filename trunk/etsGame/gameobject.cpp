#include "gameobject.h"
#include "etsgame.h"
#include <QPixmap>

gameObject::gameObject(QObject *parent, int myCount, gameObjectType tp, QWidget *w, int dir, int scX, int scY) :
    QObject(parent)
{
    QWidget *wdgt = dynamic_cast<QWidget*>(parent);
    label = new QLabel(wdgt);
    label->setObjectName("L" + QString::number(myCount));
    this->setType(tp);
    setSprite();
    int objX = wdgt->width();
    int objY = rand() % (wdgt->height()-15-this->label->pixmap()->height()) + 15;
    this->setDirection(dir);
    this->label->stackUnder(w);
    this->label->show();
    this->label->setGeometry(objX,objY,this->label->pixmap()->width(),this->label->pixmap()->height());
}

void gameObject::setSprite() {
    switch (type) {
    case FISH:
        label->setPixmap(*((etsGame*)this->parent())->fishImage);
        break;
    case BUBBLE:
        label->setPixmap(*((etsGame*)this->parent())->bubbleImage);
        break;
    case SHARK:
        label->setPixmap(*((etsGame*)this->parent())->sharkImage);
        break;
    default:
        break;
    }
    label->setGeometry(label->x(),label->y(),label->pixmap()->width(),label->pixmap()->height());
}

int gameObject::getDirection(){
    return direction;
}

void gameObject::setDirection(int newD) {
    direction = newD;
}

void gameObject::setType(gameObjectType newT) {
    type = newT;
}

gameObjectType gameObject::getType() {
    return type;
}
