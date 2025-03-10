#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "initialize.h"
#include "CommonFunc.h"

const char* WINDOW_TITLE = "Fighter";
const char* bground_file = "bground.png";
const char* air_force_file = "air_force.png";
const char* air_force_and_shield_file = "";


using namespace std;


int main(int argc, char *argv[])
{
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);

    SDL_Texture* background = loadTexture(bground_file, renderer);
    SDL_Texture* air_force = loadTexture(air_force_file, renderer);

    //tạo animation máy bay

    int bgY = 0;

    // Vòng lặp chính
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        renderTexture(air_force, 0, 0, renderer);
        SDL_RenderPresent( renderer );

        SDL_RenderClear(renderer);

        // Vẽ background
        SDL_Rect destRect = { 0, bgY, SCREEN_WIDTH, SCREEN_HEIGHT };
        SDL_RenderCopy(renderer, background, NULL, &destRect);

        SDL_RenderPresent(renderer);

        //di chuyển máy bay


    }


    SDL_DestroyTexture( background );
    background = NULL;

    quitSDL(window, renderer);
    return 0;
}




