#include "scene.hh"
#include <QBrush>
#include <ctime>
Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
    srand(time(NULL));
    _constSpeed = false;
    _simulationON = false;
}

Scene::~Scene()
{
    delete _road;
    delete _mainCar;
}

void Scene::addCar()
{
    _mainCar = new CarItem();
    addItem(_mainCar);
    connect(this, SIGNAL(moveCar()), _mainCar, SLOT(onMoveCar()));
    connect(this, SIGNAL(stopCar()), _mainCar, SLOT(onStopCar()));
}

void Scene::addRoad()
{
    _road = new RoadItem;
    addItem(_road);
    connect(this, SIGNAL(startRoad()), _road, SLOT(startAnimation()));
    connect(this, SIGNAL(stopRoad()), _road, SLOT(stopAnimation()));
}


void Scene::newDataArrived(rawData data)
{
    if(_simulationON){
        moveData move;
        move.X = data.X/100;
        move.Y = data.Y;
        _mainCar->move(move);
        if(!_constSpeed){
            _road->speedChanged(move);
        }
    }
}

void Scene::startSimulation()
{
    _simulationON = true;
    emit moveCar();
    emit startRoad();
}

void Scene::stopSimulation()
{
    _simulationON = false;
    emit stopCar();
    emit stopRoad();
}

void Scene::resetSimulation()
{
    _simulationON = false;
    removeItem(_road);
    removeItem(_mainCar);
    delete _road;
    delete _mainCar;
    addRoad();
    addCar();
}

void Scene::onConstSpeed()
{
    this->_constSpeed = true;
}

void Scene::onVariableSpeed()
{
    this->_constSpeed = false;
}

void Scene::setCarSpeed(const int &speed)
{
    qDebug() << "Test " << speed;
    _road->setSpeed(speed);
}

int Scene::getCarSpeed() const
{
    return _road->getSpeed();
}

bool Scene::getConstSpeedState() const
{
    return this->_constSpeed;
}

