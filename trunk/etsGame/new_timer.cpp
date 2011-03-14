#include <QTimer>
#include <QMouseEvent>
#include "new_timer.h"

Timer::Timer(QObject *_parent, int count)
{
    connect(this, SIGNAL(timeout()), this, SLOT(inc()));
    createActions();
    this->setInterval(500);
    this->setObjectName(QString::number(count));
    this->setParent(_parent);
}

void Timer::inc()
{
        // Code to increment the count goes here (Program 3: movement code)
}

void Timer::on_object_clicked(QMouseEvent *event)
{
        // What should happen when someone left clicks on the button?
}

void Timer::decelerate()
{
        // Code to slow down count
}

void Timer::accelerate()
{
        // Code to speed up count
}

void Timer::createActions()
{
        // Put code here to initialize the actions you need for the drop down menu
}

