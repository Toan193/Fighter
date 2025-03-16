#include "MainObject.h"
#include "BaseObject.h"
#include "BulletObject.h"
#include <algorithm>

MainObject::MainObject()
{
    // Tọa độ đối tượng chính
    desRect.x = BEGIN_PLAYER_X;
    desRect.y = BEGIN_PLAYER_Y;
    desRect.w = PLAYER_WIDTH;
    desRect.h = PLAYER_HEIGHT;
}

MainObject::~MainObject()
{

}

//di chuyển nhân vật
void MainObject::turnLeft()
{
    desRect.x -= speed;
}
void MainObject::turnRight()
{
    desRect.x += speed;
}
void MainObject::turnUp()
{
    desRect.y -= speed;
}
void MainObject::turnDown()
{
    desRect.y += speed;
}

void MainObject::nap_dan(SDL_Renderer* renderer)
{
    BulletObject* bullet = new BulletObject(this->desRect.x , desRect.ycc );
    bullet->loadImg("bullet.png", renderer);
    bullet_list.push_back(bullet);
}

void MainObject::shoot(SDL_Renderer* renderer)
{
    for (int i = 0; i < bullet_list.size(); i++) {
        BulletObject* bullet = bullet_list.at(i);
        if (bullet != NULL) {
            if (bullet->isActive == true) {
                bullet->update();
                bullet->show(renderer);
            } else {
                bullet_list.erase(bullet_list.begin() + i);
                if (bullet != NULL) {
                    delete bullet;
                    bullet = NULL;
                }
            }
        }
    }
}

