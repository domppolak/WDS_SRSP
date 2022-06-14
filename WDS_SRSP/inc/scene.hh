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
    void setCarSpeed(const int &speed);
    int getCarSpeed() const;
    bool getConstSpeedState() const;
    bool getSimulationState() const;
    void setSimulationState(const bool &state);
signals:
    void moveCar();
    void stopCar();
    void stopRoad();
    void startRoad();
    void carSpeedChanged(moveData data);

private slots:
    void newDataArrived(rawData data);

public slots:
    void startSimulation();
    void stopSimulation();
    void resetSimulation();
    void onConstSpeed();
    void onVariableSpeed();

private:
    bool _simulationON;
    bool _constSpeed;

    CarItem *_mainCar;
    RoadItem *_road;
};

#endif // SCENE_HH
