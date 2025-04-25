#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_TH

#include "CommonFunc.h"
#include "BaseObject.h"
#include "BulletObject.h"
#include "ThreatObject.h"
#include <vector>


class MainObject : public BaseObject
{
public:
    int bulletsLeft = bullet_max;
    MainObject();
    ~MainObject();
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();
    void delete_fighter();
    void nap_dan(SDL_Renderer* renderer, std::vector<BulletObject*>& bullet_list);
    void shoot(SDL_Renderer* renderer, std::vector<BulletObject*>& bullet_list);
    void reloadBullet(int &numberOfBullet);
    void create_asteroid(SDL_Renderer* renderer, std::vector<ThreatObject*>& asteroids);
    void show_asteroid(SDL_Renderer* renderer, std::vector<ThreatObject*>& asteroids);
    void flash(const bool &is_left, const bool &is_right, const bool &is_up, const bool &is_down);
    Uint32 lastReloadTime = 0;
};


#endif // MAIN_OBJECT_H_
