#include "car_item.hh"
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>

CarItem::CarItem()
{
    _stopCar = false;
    setPixmap(QPixmap(":/car/img/models/car.png"));
    setScale(0.3);
    resetPosition();
    qDebug() << "Car created";
}

void CarItem::resetPosition()
{
    setPos(235, 300);
    setFlag(QGraphicsItem :: ItemIsFocusable);
    setFocus();
}

void CarItem::move(moveData data)
{
    if(!_stopCar){
        if((pos().x() + data.X) > 0 && (pos().x() + 150 + data.X) < 740){
            setPos(x()+data.X, y());
        }
        if((pos().x() + data.X <= 0)){
            setPos(0, y());
        }
        if((pos().x() + 150 + data.X) >= 740){
            setPos(740-155, y());
        }
        qDebug() << "Car move";
    }
}

void CarItem::onStopCar()
{
    _stopCar = true;
}

void CarItem::onMoveCar()
{
    _stopCar = false;
}


