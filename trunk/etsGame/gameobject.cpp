#include "gameobject.h"

gameObject::gameObject(QObject *parent, int myCount, gameObjectType tp, QWidget *w, int dir) :
    QObject(parent)
{
    QWidget *wdgt = dynamic_cast<QWidget*>(parent);
    label = new QLabel(wdgt);
    label->setObjectName("L" + QString::number(myCount));
    this->setType(tp);
    this->setDirection(dir);
    this->label->stackUnder(w);
    this->label->show();
}

void gameObject::setSprite(QPixmap p) {
    sprite = p;
    label->setPixmap(sprite);
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
