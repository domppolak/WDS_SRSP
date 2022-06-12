#include "object_scene.hh"


ObjectScene::ObjectScene(QWidget *parent)
    : QWidget(parent)
{
    _scene = new Scene;

}

ObjectScene::~ObjectScene()
{
    delete _scene;
}
