#include "scene.hh"
#include <QBrush>
#include <ctime>
Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
    srand(time(NULL));

}

Scene::~Scene()
{

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
    _road = new RoadItem(100, 0);
    addItem(_road);
}


void Scene::newDataArrived(rawData data)
{
    moveData move;
    move.X = data.X/100;
    move.Y = data.Y/100;
    _mainCar->move(move);
}

void Scene::startTimer()
{

}

void Scene::stopTimer()
{

}

void Scene::startAnimation()
{
    _road->startAnimation();
    emit moveCar();
}

void Scene::stopAnimation()
{
    _road->stopRoad();
    emit stopCar();
}

void Scene::resetScene()
{
    removeItem(_road);
    removeItem(_mainCar);
    delete _road;
    delete _mainCar;
    addRoad();
    addCar();
}

