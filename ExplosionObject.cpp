#include "ExplosionObject.h"

ExplosionObject::ExplosionObject()
{
    frame = 0;
}

ExplosionObject::~ExplosionObject()
{

}

void ExplosionObject::set_exp_clip()
{
    clip_exp[0].x = 0;
    clip_exp[0].y = 0;
    clip_exp[0].w = EXP_WIDTH;
    clip_exp[0].h = EXP_HEIGHT;

    clip_exp[1].x = EXP_WIDTH;
    clip_exp[1].y = 0;
    clip_exp[1].w = EXP_WIDTH;
    clip_exp[1].h = EXP_HEIGHT;

    clip_exp[2].x = 2 * EXP_WIDTH;
    clip_exp[2].y = 0;
    clip_exp[2].w = EXP_WIDTH;
    clip_exp[2].h = EXP_HEIGHT;

    clip_exp[3].x = 3 * EXP_WIDTH;
    clip_exp[3].y = 0;
    clip_exp[3].w = EXP_WIDTH;
    clip_exp[3].h = EXP_HEIGHT;
}


