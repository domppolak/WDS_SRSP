#include "road_item.hh"


RoadItem::RoadItem()
{
    _speed = MIN_SPEED;
    setPixmap(QPixmap(":/road/img/road/road5.png"));
    setPos(100, -600);
    setFlag(QGraphicsItem :: ItemIsFocusable);
    setFocus();
    isVisible();
    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(move()));
}

RoadItem::~RoadItem()
{
    delete _timer;
}


void RoadItem::setSpeed(const int &speed)
{
    int tmp = speed;
    if(speed > MAX_SPEED){
        tmp = MAX_SPEED;
    }
    if(speed < MIN_SPEED){
        tmp = MIN_SPEED;
    }
    this->_speed = tmp;
}

int RoadItem::getSpeed() const
{
    return this->_speed;
}

void RoadItem::move()
{
    setPos(x(), y()+_speed);
    if(y() > -250){
        setPos(x(), -600);
    }
}

void RoadItem::startAnimation()
{
    _timer->start(25);
}

void RoadItem::stopAnimation()
{
    _timer->stop();
}

void RoadItem::speedChanged(moveData data)
{
    qDebug() << "Predkosc zmieniona: " << getSpeed();
    if( data.Y < -350){
        setSpeed(getSpeed() - 1);
    }
    if(data.Y > 350){
        setSpeed(getSpeed() + 1);
    }
}
