#ifndef ANIMATIONSETTINGS_H
#define ANIMATIONSETTINGS_H

struct AnimationSettings
{
   int sceneHeight;
   int sceneWidth;
   int speed;

   AnimationSettings(int height, int width, int speed)
   : sceneHeight(height)
   , sceneWidth(width)
   , speed(speed) {}
};

#endif // ANIMATIONSETTINGS_H
