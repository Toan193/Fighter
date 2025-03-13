#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_TH

#include "CommonFunc.h"
#include "BaseObject.h"
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

};


#endif // MAIN_OBJECT_H_
