#include "CommonFunc.h"
void SDLCommonFunc::logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

SDL_Window* SDLCommonFunc::initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) SDLCommonFunc::logErrorAndExit("SDL_Init", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow("Fighter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) SDLCommonFunc::logErrorAndExit("CreateWindow", SDL_GetError());

    // khởi tạo SDL_IMAGE
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) SDLCommonFunc::logErrorAndExit( "SDL_image error:", IMG_GetError());
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) SDLCommonFunc::logErrorAndExit( "SDL_mixer  error:", IMG_GetError());
    // khởi tạo SDL_tff
    if (TTF_Init() < 0) SDLCommonFunc::logErrorAndExit( "SDL_ttf  error:", IMG_GetError());
    return window;
}

SDL_Renderer* SDLCommonFunc::createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) SDLCommonFunc::logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    return renderer;
}

SDL_Texture* SDLCommonFunc::loadTexture(const char *filename, SDL_Renderer* renderer)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
	if (texture == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

	return texture;
}

bool SDLCommonFunc::collision_check(const SDL_Rect& object1, const SDL_Rect& object2)
{
    int left_a = object1.x + 5;
    int right_a = object1.x + object1.w - 5;
    int top_a = object1.y + 30;
    int bottom_a = object1.y + object1.h - 5;

    int left_b = object2.x + 10;
    int right_b = object2.x + object2.w - 10;
    int top_b = object2.y + 10;
    int bottom_b = object2.y + object2.h - 10;

    if (right_a < left_b || right_b < left_a || bottom_a < top_b || bottom_b < top_a) {
        return false;
    }
    return true;
}



