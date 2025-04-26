#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_
#include "CommonFunc.h"

class BaseObject
{
public:
    BaseObject(); //Constructer
    ~BaseObject(); //Hàm hủy
    SDL_Renderer* setRenderer(SDL_Window* window);
    SDL_Rect get_rect() const
    {
        return desRect;
    }
    void setRect(const int &x, const int &y)
    {
        desRect.x = x;
        desRect.y = y;
    }
    void loadImg(const char* file_name, SDL_Renderer *renderer);
    void show(SDL_Renderer* renderer);
    void clip(SDL_Renderer* renderer);
    void QuitSDL(SDL_Renderer* &renderer, SDL_Window* &window);
protected:
    SDL_Rect desRect;
    SDL_Rect Rec; // Rect để làm clip background
    SDL_Texture* object;
};


#endif // BASE_OBJECT_H_
