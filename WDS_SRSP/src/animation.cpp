#include "animation.hh"

Animation::Animation(QWidget *parent)
{
    _animationSettings = new AnimationSettings(750, 500, 10);
    _scene = new QGraphicsScene(this);

    setupScene();
}

void Animation::setupScene()
{
    _scene->setSceneRect(0,0, _animationSettings->sceneWidth, _animationSettings->sceneHeight);
    setBackgroundBrush(Qt::gray);
    setScene(_scene);
}
