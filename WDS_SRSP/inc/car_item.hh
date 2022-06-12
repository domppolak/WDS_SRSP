#ifndef CAR_ITEM_HH
#define CAR_ITEM_HH

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QGraphicsScene>
#include "memsdata.hh"

class CarItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CarItem();

    void resetPosition();
    void move(moveData data);

public slots:
    void onMoveCar();
    void onStopCar();

private:
    bool _stopCar;
};

#endif // CAR_ITEM_HH
