#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <cmath>
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"

void game_index(SDL_Renderer* renderer, TTF_Font* font, const int &number_bullet, const int &score, const int &BestScore)
{
    // hiển thị lượng đạn còn lại
    SDL_Texture* textureOfBulletImage = SDLCommonFunc::loadTexture("Image/bullet.png", renderer);
    SDL_Rect bullet_rect = {SCREEN_WIDTH - 70, 0, 30, 30};
    SDL_RenderCopy(renderer, textureOfBulletImage, NULL, &bullet_rect);

    SDL_Color color = {255, 255, 255};
    std::string number_bullet_string = std::to_string(number_bullet);
    int lenText = number_bullet_string.length();
    SDL_Surface* surfaceOfNumberBullet = TTF_RenderText_Blended(font, number_bullet_string.c_str(), color);
    SDL_Texture* TextureOfNumberBullet = SDL_CreateTextureFromSurface(renderer, surfaceOfNumberBullet);
    SDL_Rect number_bullet_font_rect = {SCREEN_WIDTH - 35, 7, 12*lenText, 20};
    SDL_RenderCopy(renderer, TextureOfNumberBullet, NULL, &number_bullet_font_rect);

    SDL_DestroyTexture(textureOfBulletImage);
    SDL_DestroyTexture(TextureOfNumberBullet);
    SDL_FreeSurface(surfaceOfNumberBullet);


    // hiển thị "SCORE"
    SDL_Surface* surfaceOfScoreText = TTF_RenderText_Blended(font, "SCORE :", color);
    SDL_Texture* TextureOfScoreText = SDL_CreateTextureFromSurface(renderer, surfaceOfScoreText);
    SDL_Rect scoreText_font_rect = {5, 10, 75, 20};
    SDL_RenderCopy(renderer, TextureOfScoreText, NULL, &scoreText_font_rect);

    std::string score_string = std::to_string(score);
    lenText = score_string.length();
    SDL_Surface* surfaceOfScore = TTF_RenderText_Blended(font, score_string.c_str(), color);
    SDL_Texture* TextureOfScore = SDL_CreateTextureFromSurface(renderer, surfaceOfScore);
    SDL_Rect score_font_rect = {85, 10, 12*lenText, 20};
    SDL_RenderCopy(renderer, TextureOfScore, NULL, &score_font_rect);

    SDL_DestroyTexture(TextureOfScoreText);
    SDL_DestroyTexture(TextureOfScore);
    SDL_FreeSurface(surfaceOfScoreText);
    SDL_FreeSurface(surfaceOfScore);

    // hiển thị "Best Score"
    SDL_Surface* surfaceOfBestScoreText = TTF_RenderText_Blended(font, "BEST SCORE :", color);
    SDL_Texture* TextureOfBestScoreText = SDL_CreateTextureFromSurface(renderer, surfaceOfBestScoreText);
    SDL_Rect BestScoreText_font_rect = {5, 40, 140, 20};
    SDL_RenderCopy(renderer, TextureOfBestScoreText, NULL, &BestScoreText_font_rect);

    std::string BestScore_string = std::to_string(BestScore);
    lenText = BestScore_string.length();
    SDL_Surface* surfaceOfBestScore = TTF_RenderText_Blended(font, BestScore_string.c_str(), color);
    SDL_Texture* TextureOfBestScore = SDL_CreateTextureFromSurface(renderer, surfaceOfBestScore);
    SDL_Rect BestScore_font_rect = {150, 40, 12*lenText, 20};
    SDL_RenderCopy(renderer, TextureOfBestScore, NULL, &BestScore_font_rect);

    SDL_DestroyTexture(TextureOfBestScoreText);
    SDL_DestroyTexture(TextureOfBestScore);
    SDL_FreeSurface(surfaceOfBestScoreText);
    SDL_FreeSurface(surfaceOfBestScore);
}

void clock(SDL_Renderer* renderer, TTF_Font* font, const Uint32 &startTime, const int &number_bullet)
{
    SDL_Texture* texture = SDLCommonFunc::loadTexture("Image/clock.png", renderer);
    SDL_Rect rect = {SCREEN_WIDTH - 70, 50, 30, 30};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    int time_left;
    if (number_bullet == 0)
    {
        Uint32 currentTime = SDL_GetTicks();
        time_left = ceil((reload_time - (currentTime - startTime))/1000.0);
    } else time_left = 0;
    std::string timeLeft = std::to_string(time_left);
    SDL_Color color = {255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Blended(font, timeLeft.c_str(), color);
    SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rectText = {SCREEN_WIDTH - 35, 57, 14, 20};
    SDL_RenderCopy(renderer, textureText, NULL, &rectText);

    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(textureText);
    SDL_FreeSurface(surface);
}

void inter_flash(SDL_Renderer* renderer, TTF_Font* font, const int &score, int &count_flash, int &point)
{
    SDL_Texture* texture = SDLCommonFunc::loadTexture("Image/Flash.png", renderer);
    SDL_Rect rect = {SCREEN_WIDTH - 150, 3, 32, 32};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    if (score - point == 5 && count_flash < 5)
    {
        ++count_flash;
        point = score;
    } else if (count_flash == 5) {
        point = score;
    }

    std::string countFlash = std::to_string(count_flash);
    SDL_Color color = {255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Blended(font, countFlash.c_str(), color);
    SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rectText = {SCREEN_WIDTH - 110, 7, 14, 20};
    SDL_RenderCopy(renderer, textureText, NULL, &rectText);

    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(textureText);
    SDL_FreeSurface(surface);
}

void showGameOver(SDL_Renderer* renderer, TTF_Font* font1, TTF_Font* font, bool& restart) {
    SDL_Color white = {255, 255, 255};
    SDL_Color red = {255, 0, 0};

    SDL_Surface* Surface1 = TTF_RenderText_Solid(font1, "Game Over", red);
    SDL_Surface* Surface2 = TTF_RenderText_Solid(font, "Do you want to play again? (Y/N)", white);

    SDL_Texture* text1 = SDL_CreateTextureFromSurface(renderer, Surface1);
    SDL_Texture* text2 = SDL_CreateTextureFromSurface(renderer, Surface2);

    int w1, h1, w2, h2;
    SDL_QueryTexture(text1, NULL, NULL, &w1, &h1);
    SDL_QueryTexture(text2, NULL, NULL, &w2, &h2);

    SDL_Rect des1 = {480, 300, w1 , h1};
    SDL_Rect des2 = {400, 350, w2 + 70, h2 + 10};

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, text1, NULL, &des1);
    SDL_RenderCopy(renderer, text2, NULL, &des2);
    SDL_RenderPresent(renderer);

    SDL_Event e;
    bool waiting = true;
    while (waiting) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                waiting = false;
                restart = false;
            }
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_y) {
                    restart = true;
                    waiting = false;
                }
                if (e.key.keysym.sym == SDLK_n) {
                    restart = false;
                    waiting = false;
                }
            }
        }
    }

    SDL_FreeSurface(Surface1);
    SDL_FreeSurface(Surface2);
    SDL_DestroyTexture(text1);
    SDL_DestroyTexture(text2);
}
#endif // INTERFACE_H
