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
    void clip(SDL_Renderer* renderer);
protected:
    SDL_Rect desRect;
    SDL_Rect Rec; // Rect để làm clip
    SDL_Texture* object;
};


#endif // BASE_OBJECT_H_
