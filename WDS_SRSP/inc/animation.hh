#ifndef ANIMATION_HH
#define ANIMATION_HH

#include <QWidget>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "memsdata.hh"
#include "animationsettings.hh"


class Animation : public QGraphicsView
{
    Q_OBJECT

public:
    Animation(QWidget *parent = nullptr);

private:
    void setupScene();

    QGraphicsScene *_scene;
    AnimationSettings *_animationSettings;
};

#endif // ANIMATION_HH
