#ifndef BULLET_OBJECT_H
#define BULLET_OBJECT_H

#include "CommonFunc.h"
#include "BaseObject.h"
#include <vector>

class BulletObject : public BaseObject
{
public:
    BulletObject();
    BulletObject(int x, int y);
    ~BulletObject();
    void update();
    bool isActive;
};


#endif // BULLET_OBJECT_H

