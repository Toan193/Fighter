#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"

void game_index(SDL_Renderer* renderer, const int &number_bullet, const int &score, const int &BestScore)
{
    SDL_Texture* textureOfBulletImage = SDLCommonFunc::loadTexture("Image/bullet.png", renderer);
    SDL_Rect bullet_rect = {SCREEN_WIDTH - 70, 0, 30, 30};
    SDL_RenderCopy(renderer, textureOfBulletImage, NULL, &bullet_rect);

    SDL_Color color = {255, 255, 255};
    TTF_Font* font = TTF_OpenFont("Font/cs_regular.ttf", 18);
    std::string number_bullet_string = std::to_string(number_bullet);
    SDL_Surface* surfaceOfNumberBullet = TTF_RenderText_Blended(font, number_bullet_string.c_str(), color);
    SDL_Texture* TextureOfNumberBullet = SDL_CreateTextureFromSurface(renderer, surfaceOfNumberBullet);
    SDL_Rect number_bullet_font_rect = {SCREEN_WIDTH - 35, 7, 17, 20};
    SDL_FreeSurface(surfaceOfNumberBullet);
    SDL_RenderCopy(renderer, TextureOfNumberBullet, NULL, &number_bullet_font_rect);

    // hiển thị "SCORE"
    SDL_Surface* surfaceOfScoreText = TTF_RenderText_Blended(font, "SCORE :", color);
    SDL_Texture* TextureOfScoreText = SDL_CreateTextureFromSurface(renderer, surfaceOfScoreText);
    SDL_Rect scoreText_font_rect = {5, 10, 75, 20};
    SDL_FreeSurface(surfaceOfScoreText);
    SDL_RenderCopy(renderer, TextureOfScoreText, NULL, &scoreText_font_rect);

    std::string score_string = std::to_string(score);
    SDL_Surface* surfaceOfScore = TTF_RenderText_Blended(font, score_string.c_str(), color);
    SDL_Texture* TextureOfScore = SDL_CreateTextureFromSurface(renderer, surfaceOfScore);
    SDL_Rect score_font_rect = {85, 10, 20, 20};
    SDL_FreeSurface(surfaceOfScore);
    SDL_RenderCopy(renderer, TextureOfScore, NULL, &score_font_rect);

    // hiển thị "Best Score"
    SDL_Surface* surfaceOfBestScoreText = TTF_RenderText_Blended(font, "BEST SCORE :", color);
    SDL_Texture* TextureOfBestScoreText = SDL_CreateTextureFromSurface(renderer, surfaceOfBestScoreText);
    SDL_Rect BestScoreText_font_rect = {5, 40, 140, 20};
    SDL_FreeSurface(surfaceOfBestScoreText);
    SDL_RenderCopy(renderer, TextureOfBestScoreText, NULL, &BestScoreText_font_rect);

    std::string BestScore_string = std::to_string(BestScore);
    SDL_Surface* surfaceOfBestScore = TTF_RenderText_Blended(font, BestScore_string.c_str(), color);
    SDL_Texture* TextureOfBestScore = SDL_CreateTextureFromSurface(renderer, surfaceOfBestScore);
    SDL_Rect BestScore_font_rect = {150, 40, 20, 20};
    SDL_FreeSurface(surfaceOfBestScore);
    SDL_RenderCopy(renderer, TextureOfBestScore, NULL, &BestScore_font_rect);
}

#endif // INTERFACE_H
