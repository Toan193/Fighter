#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"

void logErrorAndExit(const char* msg, const char* error);
SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE);
SDL_Renderer* createRenderer(SDL_Window* window);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
void renderTexture(SDL_Texture *texture, int x, int y, SDL_Renderer* renderer);
SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer);



#endif // INITIALIZE_H
