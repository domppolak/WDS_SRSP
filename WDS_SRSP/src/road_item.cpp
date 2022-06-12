#include "road_item.hh"

RoadItem::RoadItem(qreal newX, qreal newY)
{
    setPixmap(QPixmap(":/road/img/road/road5.png"));
    setPos(newX, newY);
    setFlag(QGraphicsItem :: ItemStacksBehindParent);
    //setFocus();
    yAnimation = new QPropertyAnimation(this, "y", this);
    yAnimation->setStartValue(-1000);
    yAnimation->setEndValue(1000);
    yAnimation->setEasingCurve(QEasingCurve::Linear);
    yAnimation->setDuration(2000);
    yAnimation->setLoopCount(-1);

}

qreal RoadItem::y() const
{
    return m_y;
}

void RoadItem::setY(qreal _y)
{
    this->m_y = _y;
    setPos(QPointF(x(), y()) + QPointF(0, _y));
}

void RoadItem::setRestartPos(){
    if(yAnimation->endValue() == 500){
         setPos(100, 0);
    }

}
void RoadItem::stopRoad()
{
    yAnimation->stop();
}

void RoadItem::startAnimation()
{
    yAnimation->start();
}

