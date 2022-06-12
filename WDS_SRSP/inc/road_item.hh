#ifndef ROAD_ITEM_HH
#define ROAD_ITEM_HH

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QGraphicsScene>

class RoadItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal y READ y WRITE setY);

public:
    RoadItem(qreal newX, qreal newY);
    qreal y() const;
    void setY(qreal _y);
    void stopRoad();
    void startAnimation();

public slots:
    void setRestartPos();
private:
    QPropertyAnimation * yAnimation;
    qreal m_y;


};
#endif // ROAD_ITEM_HH
