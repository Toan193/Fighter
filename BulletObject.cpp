#include "BulletObject.h"

BulletObject::BulletObject(int x, int y)
{
    // Tọa độ đạn ban đầu
    desRect.x = x + 30;
    desRect.y = y - 20;
    desRect.w = 21;
    desRect.h = 23;
    isActive = true;
}

BulletObject::BulletObject()
{

}

BulletObject::~BulletObject()
{

}

void BulletObject::update()
{
    desRect.y -= speed_bullet;
    if (desRect.y < 0) isActive = false;
}

void BulletObject::delete_bullet(SDL_Texture* &texture)
{
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture == nullptr;
    }
}


