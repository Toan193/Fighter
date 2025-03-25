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
    if (desRect.x > 0) {
        desRect.x -= speed;
    }
}
void MainObject::turnRight()
{
    if (desRect. x < SCREEN_WIDTH - PLAYER_WIDTH) {
        desRect.x += speed;
    }
}
void MainObject::turnUp()
{
    if (desRect.y > 0) {
        desRect.y -= speed;
    }
}
void MainObject::turnDown()
{
    if (desRect.y < SCREEN_HEIGHT - PLAYER_HEIGHT) {
        desRect.y += speed;
    }
}

void MainObject::nap_dan(SDL_Renderer* renderer, std::vector<BulletObject*>& bullet_list)
{
    if (bulletsLeft > 0) {
        BulletObject* bullet = new BulletObject(this->desRect.x , desRect.y );
        bullet->loadImg("bullet.png", renderer);
        bullet_list.push_back(bullet);
        --bulletsLeft;
        if (bulletsLeft == 0 ) {
        lastReloadTime = SDL_GetTicks();
        }
    }
}

void MainObject::shoot(SDL_Renderer* renderer, std::vector<BulletObject*>& bullet_list)
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

// tải lại dạn sau 3s hết đạn
void MainObject::reloadBullet()
{
    if (bulletsLeft == 0 && SDL_GetTicks() - lastReloadTime >= reload_time) {
        bulletsLeft = bullet_max;
    }
}

void MainObject::create_asteroid(SDL_Renderer* renderer, std::vector<ThreatObject*>& asteroids)
{

    for (int i = 0; i < number_of_threat; i++) {
        ThreatObject* asteroid = new ThreatObject();
        asteroid->loadImg("Threat.png", renderer);
        asteroids.push_back(asteroid);
    }
}

void MainObject::show_asteroid(SDL_Renderer* renderer, std::vector<ThreatObject*>& asteroids)
{
    for (int i = 0; i < number_of_threat; i++) {
        ThreatObject* asteroid = asteroids.at(i);
        if (asteroid != NULL) {
            asteroid->update_asteroid();
            asteroid->show(renderer);
        }
    }
}



