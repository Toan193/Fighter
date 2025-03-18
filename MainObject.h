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

    MainObject();
    ~MainObject();
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();
    void nap_dan(SDL_Renderer* renderer);
    void shoot(SDL_Renderer* renderer);
    void reloadBullet();
    void create_asteroid(SDL_Renderer* renderer);
    void show_asteroid(SDL_Renderer* renderer);
    int bulletsLeft = bullet_max;
private:
    std::vector<BulletObject*> bullet_list;
    std::vector<ThreatObject*> asteroids;
    Uint32 lastReloadTime = 0;
};


#endif // MAIN_OBJECT_H_
