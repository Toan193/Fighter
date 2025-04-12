#ifndef EXPLOSION_OBJECT_H
#define EXPLOSION_OBJECT_H

#include <vector>
#include "BaseObject.h"
#include "CommonFunc.h"

const int EXP_HEIGHT = 165;
const int EXP_WIDTH = 150;

class ExplosionObject : public BaseObject
{
public:
    ExplosionObject();
    ~ExplosionObject();
    void set_frame(const int &fr)
    {
        frame = fr;
    }
    void set_exp_clip();
    void show_clip_exp(SDL_Renderer* renderer);
private:
    int frame;
    SDL_Rect clip_exp[8];
};

#endif // EXPLOSION_OBJECT_H
