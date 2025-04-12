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

    clip_exp[4].x = 4 * EXP_WIDTH;
    clip_exp[4].y = 0;
    clip_exp[4].w = EXP_WIDTH;
    clip_exp[4].h = EXP_HEIGHT;

    clip_exp[5].x = 5 * EXP_WIDTH;
    clip_exp[5].y = 0;
    clip_exp[5].w = EXP_WIDTH;
    clip_exp[5].h = EXP_HEIGHT;

    clip_exp[6].x = 6* EXP_WIDTH;
    clip_exp[6].y = 0;
    clip_exp[6].w = EXP_WIDTH;
    clip_exp[6].h = EXP_HEIGHT;

    clip_exp[7].x = 7* EXP_WIDTH;
    clip_exp[7].y = 0;
    clip_exp[7].w = EXP_WIDTH;
    clip_exp[7].h = EXP_HEIGHT;
}

void ExplosionObject::show_clip_exp(SDL_Renderer* renderer)
{
    SDL_Rect* current_clip = &clip_exp[frame];
    SDL_Rect render_quad = { desRect.x, desRect.y, EXP_WIDTH, EXP_HEIGHT};
    if (current_clip != NULL)
    {
        render_quad.w = current_clip->w;
        render_quad.h = current_clip->h;
    }
    SDL_RenderCopy(renderer, object, current_clip, &render_quad);
}


