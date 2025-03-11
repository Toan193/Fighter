#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "initialize.h"
#include "CommonFunc.h"

const char* WINDOW_TITLE = "Fighter";
const char* bground_file = "bground.png";
const char* air_force_file = "air_force.png";
const char* air_force_and_shield_file = "";

SDL_Window* window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *background = NULL;
SDL_Event g_even;

using namespace std;


int main(int argc, char *argv[])
{
    window = SDLCommonFunc::initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    renderer = SDLCommonFunc::createRenderer(window);
    background = SDLCommonFunc::loadTexture(bground_file, renderer);

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //renderTexture(air_force, 0, 0, renderer);
        //SDL_RenderPresent( renderer );


        // Vẽ background
        SDL_Rect destRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
        SDL_RenderCopy(renderer, background, NULL, &destRect);

        SDL_RenderPresent(renderer);

        //di chuyển máy bay


    }


    SDL_DestroyTexture( background );
    background = NULL;

    quitSDL(window, renderer);
    return 0;
}




