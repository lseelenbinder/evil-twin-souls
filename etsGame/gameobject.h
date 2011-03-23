#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QTimer>
#include <QPixmap>

class gameObject : public QObject
{
    Q_OBJECT

public:
    explicit gameObject(QObject *parent = 0);

private:
    QPixmap sprite;

signals:

public slots:
    void collision(gameObject*, int type);

};

#endif // GAMEOBJECT_H
