#include "BaseObject.h"
#include "CommonFunc.h"

BaseObject::BaseObject()
{
    desRect.x = 0;
    desRect.y = 0;
    desRect.w = SCREEN_WIDTH;
    desRect.h = SCREEN_HEIGHT;

    Rec.x = 0;
    Rec.y = -SCREEN_HEIGHT;
    Rec.w = SCREEN_WIDTH;
    Rec.h = SCREEN_HEIGHT;

    object = NULL;
}

BaseObject::~BaseObject()
{
    if (object != NULL )
    {
        SDL_DestroyTexture(object);
    }
}

SDL_Renderer* BaseObject::setRenderer()
{
    SDL_Window* window = SDLCommonFunc::initSDL(SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer *renderer = SDLCommonFunc::createRenderer(window);
    return renderer;
}

void BaseObject::loadImg(const char* file_name, SDL_Renderer* renderer)
{
    object = SDLCommonFunc::loadTexture(file_name, renderer);
}

void BaseObject::show(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, object, NULL, &desRect);
}

void BaseObject::clip(SDL_Renderer* renderer)
{
    desRect.y += speed_bg;
    Rec.y += speed_bg;
    if (desRect.y >= SCREEN_HEIGHT) {
        desRect.y = Rec.y - SCREEN_HEIGHT;
    }
    if (Rec.y >= SCREEN_HEIGHT) {
        Rec.y = desRect.y - SCREEN_HEIGHT;
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, object, NULL, &desRect);
    SDL_RenderCopy(renderer, object, NULL, &Rec);
}
