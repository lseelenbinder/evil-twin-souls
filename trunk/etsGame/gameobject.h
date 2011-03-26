#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QTimer>
#include <QPixmap>

enum gameObjectTypes {FISH, BUBBLE, BULLET};

class gameObject : public QObject
{
    Q_OBJECT

public:
    explicit gameObject(QObject *parent = 0);
    void setSprite(QPixmap*);
    int getDirection();
    void setDirection(int);

private:
    QPixmap* sprite;
    int type;
    QTimer* t;
    int direction;

signals:

};

#endif // GAMEOBJECT_H
