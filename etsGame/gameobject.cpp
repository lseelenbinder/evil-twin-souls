#include "gameobject.h"
#include <QPixmap>

gameObject::gameObject(QObject *parent, int myCount, gameObjectType tp, QWidget *w, int dir) :
    QObject(parent)
{
    QWidget *wdgt = dynamic_cast<QWidget*>(parent);
    label = new QLabel(wdgt);
    label->setObjectName("L" + QString::number(myCount));
    this->setType(tp);
    switch (tp) {
    case FISH:
        this->setSprite(QPixmap("images/shark.png"));
        break;
    case BUBBLE:
        this->setSprite(QPixmap("images/bubble.png"));
        break;
    default:
        break;
    }
    int objX = wdgt->width();
    int objY = rand() % (wdgt->height()-15-this->sprite.height()) + 15;
    this->setDirection(dir);
    this->label->stackUnder(w);
    this->label->show();
    this->label->setGeometry(objX,objY,this->sprite.width(),this->sprite.height());
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
