#include "MainObject.h"
#include "BaseObject.h"
#include "BulletObject.h"
#include <algorithm>
#include <cmath>
#include <SDL_mixer.h>

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
        bullet->loadImg("Image/bullet.png", renderer);
        bullet_list.push_back(bullet);
        --bulletsLeft;
        if (bulletsLeft == 0 ) {
        lastReloadTime = SDL_GetTicks();
        }
    }
}

void MainObject::shoot(SDL_Renderer* renderer, std::vector<BulletObject*>& bullet_list)
{
    for (int i = 0; i < (int)bullet_list.size(); i++) {
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
void MainObject::reloadBullet(int &numberOfBullet)
{
    if (bulletsLeft == 0 && SDL_GetTicks() - lastReloadTime >= reload_time) {
        bulletsLeft = bullet_max;
        if (numberOfBullet == 0) numberOfBullet = bullet_max;
    }
}

void MainObject::create_asteroid(SDL_Renderer* renderer, std::vector<ThreatObject*>& asteroids)
{

    for (int i = 0; i < number_of_threat; i++) {
        ThreatObject* asteroid = new ThreatObject();
        asteroid->loadImg("Image/Threat.png", renderer);
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

// hàm các bổ trợ
void MainObject::flash(const bool &is_left, const bool &is_right, const bool &is_up, const bool &is_down)
{
    int left = 0, right = 0, up = 0, down = 0;
    int dis = distance_flash*0.70710678;
    if (is_right)
    {
        if (is_up)
        {
            right = dis;
            up = -dis;
        }
        if (is_down)
        {
            right = dis;
            down = dis;
        }
        if (!is_up && !is_down) right = distance_flash;
    } else {
        if (is_up) up = -distance_flash;
        if (is_down) down = distance_flash;
    }
    if (is_left)
    {
        if (is_up)
        {
            left = -dis;
            up = -dis;
        }
        if (is_down)
        {
            left = -dis;
            down = dis;
        }
        if (!is_up && !is_down) left = -distance_flash;
    }
    desRect.x += left + right;
    if (desRect.x >= SCREEN_WIDTH - PLAYER_WIDTH) desRect.x = SCREEN_WIDTH - PLAYER_WIDTH;
    if (desRect.x <= 0) desRect.x = 0;
    desRect.y += up + down;
    if (desRect.y >= SCREEN_HEIGHT - PLAYER_HEIGHT) desRect.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
    if (desRect.y <= 0) desRect.y = 0;
}


