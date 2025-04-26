#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;
const int PLAYER_WIDTH = 80;
const int PLAYER_HEIGHT = 90;
const int THREAT_SIZE = 100;
const int BEGIN_PLAYER_X = 500;
const int BEGIN_PLAYER_Y = 600;
const int speed_bg = 1;
const int speed_bullet = 8;
const int speed = 6;
const int speed_threat_max = 6;
const int speed_threat_min = 4;
const int number_of_threat = 20;
const int reload_time = 3000;
const int bullet_max = 15;
const int distance_flash = 130;

namespace SDLCommonFunc
{
    //hàm báo lỗi
    void logErrorAndExit(const char* msg, const char* error);
    //khai báo
    SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    // tạo renderer
    SDL_Renderer* createRenderer(SDL_Window* window);
    SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer);
    bool collision_check(const SDL_Rect& rec1, const SDL_Rect& rec2);
}

#endif // COMMON_FUNCTION_H_
