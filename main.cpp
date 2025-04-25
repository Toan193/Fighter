#include <windows.h>
#include <iostream>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "CommonFunc.h"
#include "BaseObject.h"
#include "MainObject.h"
#include "BulletObject.h"
#include "ExplosionObject.h"
#include "Interface.h"
using namespace std;

const char* WINDOW_TITLE = "Fighter";
const Uint8* state = SDL_GetKeyboardState(NULL);
SDL_Event e;

std::vector<ThreatObject*> asteroid_list;
std::vector<BulletObject*> bullet_list;

int game();

int main(int argc, char *argv[])
{
    game();
    return 0;
}

int game()
{
    SDL_Window* window;

    bool restart = false;
    // khởi tạo ảnh nền
    BaseObject bg;
    SDL_Renderer *renderer = bg.setRenderer(window);
    bg.loadImg("Image/bground.png", renderer);

    // khởi tạo nhân vật chính
    MainObject Fighter;
    Fighter.loadImg("Image/air_force.png", renderer);

    // Khởi tạo thiên thạch
    MainObject threat;
    threat.create_asteroid(renderer, asteroid_list);

    // khởi tạo đạn
    BulletObject bullet;

    // biến dùng để tạo vụ nổ
    ExplosionObject exp_main;
    exp_main.loadImg("Image/explosion.png", renderer);
    exp_main.set_exp_clip();

    // Biến dùng cho các bổ trợ
    bool is_left,is_right, is_up, is_down;
    bool flash_active = false;
    int count_flash = 0;
    int point = 0;

    // các biến tạo âm thanh
    Mix_AllocateChannels(16);
    Mix_Chunk* shot_sound = Mix_LoadWAV("Sound/shot_sound.wav");
    Mix_Chunk* exp_sound = Mix_LoadWAV("Sound/Explosion.wav");

    // các dữ liệu của game
    int numberOfBullet = bullet_max;
    int score = 0;
    int BestScore;
    std::ifstream in_file("DataFile.txt");
    in_file >> BestScore;
    in_file.close();
    TTF_Font* font = TTF_OpenFont("Font/cs_regular.ttf", 18);
    TTF_Font* font1 = TTF_OpenFont("Font/Sddystopiandemo-GO7xa.ttf", 24);

    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }

            // nhấn space để nạp đạn
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                if (numberOfBullet > 0) numberOfBullet--;
                Fighter.nap_dan(renderer, bullet_list);

                // tạo âm thanh bắn súng
                if (Fighter.bulletsLeft > 0)
                {
                    Mix_PlayChannel(-1, shot_sound, 0);
                }
            }

            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_c && count_flash > 0) flash_active = true;
        }

        // clip nền
        SDL_RenderClear(renderer);
        bg.clip(renderer);

        // nhân vật chính
        Fighter.show(renderer);

        is_left = false, is_right = false, is_up = false, is_down = false;
        // di chuyển nhân vật
        if (state[SDL_SCANCODE_UP]) {
            Fighter.turnUp();
            is_up = true;
        }
        if (state[SDL_SCANCODE_DOWN]) {
            Fighter.turnDown();
            is_down = true;
        }
        if (state[SDL_SCANCODE_LEFT]) {
            Fighter.turnLeft();
            is_left = true;
        }
        if (state[SDL_SCANCODE_RIGHT]) {
            Fighter.turnRight();
            is_right = true;
        }
        if (flash_active && count_flash > 0) {
            Fighter.flash(is_left, is_right, is_up, is_down);
            flash_active = false;
            --count_flash;
            point = score;
        }

        // thiên thạch
        threat.show_asteroid(renderer, asteroid_list);

        // bắn đạn
        Fighter.shoot(renderer, bullet_list);
        Fighter.reloadBullet(numberOfBullet); // hồi lại đạn sau 3s

        // giao diện game
        game_index(renderer, font, numberOfBullet, score, BestScore);
        clock(renderer, font, Fighter.lastReloadTime, numberOfBullet);
        inter_flash(renderer, font, score, count_flash, point);

        // xử lí các va chạm
        bool CollisionFighterAndThreat = false;
        bool CollisionBulletAndThreat = false;
        for (unsigned int i = 0; i < number_of_threat; i++)
        {
            ThreatObject* asteroid = asteroid_list.at(i);

            if ( asteroid != nullptr )
            {
                // kiểm tra va chạm fighter và threat
                CollisionFighterAndThreat = SDLCommonFunc::collision_check(asteroid->get_rect(), Fighter.get_rect());
                if (CollisionFighterAndThreat)
                {
                    for (int i = 0; i < 8; ++i)
                    {
                        int x_pos = Fighter.get_rect().x - 0.5*PLAYER_WIDTH;
                        int y_pos = Fighter.get_rect().y - 0.5*PLAYER_HEIGHT;

                        exp_main.set_frame(i);
                        exp_main.setRect(x_pos, y_pos);
                        exp_main.show_clip_exp(renderer);
                        Mix_PlayChannel(-1, exp_sound, 0);
                    }
                    asteroid->delete_asteroid();
                    Fighter.delete_fighter();
                    SDL_Delay(100);
                    showGameOver(renderer, font1, font, restart);
                    quit = true;
                }

                // kiểm tra va chạm đạn và threat
                for (unsigned int i = 0; i < bullet_list.size(); i++)
                {
                    BulletObject* bullet = bullet_list.at(i);
                    if (bullet != nullptr)
                    {
                        CollisionBulletAndThreat = SDLCommonFunc::collision_check(asteroid->get_rect(), bullet->get_rect());
                        if (CollisionBulletAndThreat)
                        {
                            ++score;
                            if (score > BestScore) BestScore = score;

                            // tạo vụ nổ
                            for (int i = 0; i < 8; ++i)
                            {
                                int x_pos = asteroid->get_rect().x ;
                                int y_pos = asteroid->get_rect().y ;

                                exp_main.set_frame(i);
                                exp_main.setRect(x_pos, y_pos);
                                exp_main.show_clip_exp(renderer);
                                Mix_PlayChannel(-1, exp_sound, 0);
                            }

                            // xóa viên đạn
                            bullet_list.erase(bullet_list.begin() + i);
                            if (bullet != nullptr)
                            {
                                delete bullet;
                                bullet = nullptr;
                            }

                            // xóa threat
                            asteroid->delete_asteroid();
                        }
                    }
                }
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    std::ofstream out_file("DataFile.txt");
    out_file << BestScore;
    out_file.close();

    bullet_list.clear();
    asteroid_list.clear();
    TTF_CloseFont(font);
    Mix_FreeChunk(shot_sound);
    Mix_FreeChunk(exp_sound);
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
    bg.QuitSDL(renderer, window);
    if (restart) game();
    return 0;
}



