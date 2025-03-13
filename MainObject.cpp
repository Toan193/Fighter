#include "MainObject.h"

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

