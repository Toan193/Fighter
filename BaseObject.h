#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_
#include "CommonFunc.h"

class BaseObject
{
public:
    BaseObject(); //Constructer
    ~BaseObject(); //Hàm hủy
    void show(SDL_Renderer* renderer);
    void loadImg(const char* file_name, SDL_Renderer *renderer);
    SDL_Renderer* setRenderer();
    void clip(SDL_Renderer* renderer, SDL_Rect rec);
protected:
    SDL_Rect desRect;
    SDL_Texture* object;
};


#endif // BASE_OBJECT_H_
