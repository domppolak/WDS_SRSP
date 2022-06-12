#ifndef SCENE_HH
#define SCENE_HH

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QSequentialAnimationGroup>
#include "car_item.hh"
#include "road_item.hh"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    ~Scene();

    void addCar();
    void addRoad();
    void startSimulation();
    void startAnimation();
    void stopAnimation();
    void resetScene();

signals:
    void moveCar();
    void stopCar();

private slots:
    void newDataArrived(rawData data);

private:

    QTimer *_timer;
    QTimer *_carTimer;

    bool _simulationON;
    CarItem *_mainCar;
    RoadItem *_road;
    RoadItem *_road1;

    void startTimer();
    void stopTimer();
    void freeze();
};

#endif // SCENE_HH
