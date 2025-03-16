#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"
#include "BaseObject.h"
#include "MainObject.h"
#include "BulletObject.h"

const char* WINDOW_TITLE = "Fighter";
const char* bground_file = "bground.png";
const char* air_force_file = "air_force.png";
const char* air_force_and_shield_file = "";
const Uint8* state = SDL_GetKeyboardState(NULL);
SDL_Event e;

using namespace std;


int main(int argc, char *argv[])
{
    // khởi tạo ảnh nền
    BaseObject bg;
    SDL_Renderer *renderer = bg.setRenderer();
    bg.loadImg("bground.png", renderer);

    // khởi tạo nhân vật chính
    MainObject Fighter;
    Fighter.loadImg("air_force.png", renderer);

    // khởi tạo đạn
    BulletObject bullet;
    bullet.loadImg("bullet (1).png", renderer);

    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }
        }

        // di chuyển nhân vật
        if (state[SDL_SCANCODE_UP]) {
            Fighter.turnUp();
        }
        if (state[SDL_SCANCODE_DOWN]) {
            Fighter.turnDown();
        }
        if (state[SDL_SCANCODE_LEFT]) {
            Fighter.turnLeft();
        }
        if (state[SDL_SCANCODE_RIGHT]) {
            Fighter.turnRight();
        }
        // cập nhật vị trí đạn
        if (state[SDL_SCANCODE_SPACE]) {
            Fighter.nap_dan(renderer);
        }

        // clip nền
        SDL_RenderClear(renderer);
        bg.clip(renderer);

        // nhân vật chính và bắn đạn
        Fighter.show(renderer);

        // bắn
        Fighter.shoot(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(20);

    }


    //SDL_DestroyTexture( background );
    //background = NULL;

    //SDLCommonFunc::quitSDL(window, renderer, background);
    return 0;
}




