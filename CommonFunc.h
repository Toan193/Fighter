#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;
const int PLAYER_WIDTH = 335;
const int PLAYER_HEIGHT = 745;
const int BEGIN_PLAYER_X = 350;
const int BEGIN_PLAYER_Y = -10;
const int speed_bg = 2;
const int speed = 5;

namespace SDLCommonFunc
{
    //hàm báo lỗi
    void logErrorAndExit(const char* msg, const char* error);
    //khai báo
    SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    // tạo renderer
    SDL_Renderer* createRenderer(SDL_Window* window);
    //hàm thoát
    void quitSDL(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture);
    SDL_Renderer* createRenderer(SDL_Window* window);
    void renderTexture(SDL_Texture *texture, int x, int y, SDL_Renderer* renderer);
    SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer);


}

#endif // COMMON_FUNCTION_H_
