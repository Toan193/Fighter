#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_TH

#include "CommonFunc.h"
#include "BaseObject.h"
#include "BulletObject.h"
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

private:
    std::vector<BulletObject*> bullet_list;
};


#endif // MAIN_OBJECT_H_
