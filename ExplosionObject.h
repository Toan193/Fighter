#ifndef EXPLOSION_OBJECT_H
#define EXPLOSION_OBJECT_H

#include "BaseObject.h"
#include "CommonFunc.h"

const int EXP_HEIGHT = 165;
const int EXP_WIDTH = 165;

class ExplosionObject : public BaseObject
{
public:
    ExplosionObject();
    ~ExplosionObject();
    void set_exp_clip();
private:
    SDL_Rect clip_exp[4];
    int frame;
};

#endif // EXPLOSION_OBJECT_H
