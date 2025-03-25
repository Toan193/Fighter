#include <windows.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"
#include "BaseObject.h"
#include "MainObject.h"
#include "BulletObject.h"
#include "ExplosionObject.h"

const char* WINDOW_TITLE = "Fighter";
const char* bground_file = "bground.png";
const char* air_force_file = "air_force.png";
const char* air_force_and_shield_file = "";
const Uint8* state = SDL_GetKeyboardState(NULL);
SDL_Event e;

std::vector<ThreatObject*> asteroid_list;
std::vector<BulletObject*> bullet_list;

using namespace std;


int main(int argc, char *argv[])
{
    SDL_Window* window;

    // khởi tạo ảnh nền
    BaseObject bg;
    SDL_Renderer *renderer = bg.setRenderer(window);
    bg.loadImg("bground.png", renderer);

    // khởi tạo nhân vật chính
    MainObject Fighter;
    Fighter.loadImg("air_force.png", renderer);

    // Khởi tạo thiên thạch
    MainObject threat;
    threat.create_asteroid(renderer, asteroid_list);

    // khởi tạo đạn
    BulletObject bullet;


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
        // tạo đạn
        if (state[SDL_SCANCODE_SPACE]) {
            Fighter.nap_dan(renderer, bullet_list);
        }

        // clip nền
        SDL_RenderClear(renderer);
        bg.clip(renderer);

        // nhân vật chính
        Fighter.show(renderer);

        // thiên thạch
        threat.show_asteroid(renderer, asteroid_list);

        // bắn đạn
        Fighter.shoot(renderer, bullet_list);
        Fighter.reloadBullet();

        // các va chạm
        bool CollisionFighterAndThreat = false;
        bool CollisionBulletAndThreat = false;
        for (unsigned int i = 0; i < number_of_threat; i++)
        {
            ThreatObject* asteroid = asteroid_list.at(i);

            if ( asteroid != nullptr )
            {
                // kiểm tra va chạm fighter và threat
                CollisionFighterAndThreat = SDLCommonFunc::collision_check(asteroid->get_rect(), Fighter.get_rect());
                /*if (CollisionFighterAndThreat)
                {
                    Sleep(3000);
                    bg.QuitSDL(renderer, window);
                    SDL_Quit();
                }*/

                // kiểm tra va chạm đạn của nhân vật chính và threat
                for (unsigned int i = 0; i < bullet_list.size(); i++)
                {
                    BulletObject* bullet = bullet_list.at(i);
                    if (bullet != nullptr)
                    {
                        CollisionBulletAndThreat = SDLCommonFunc::collision_check(asteroid->get_rect(), bullet->get_rect());
                        if (CollisionBulletAndThreat)
                        {
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
        SDL_Delay(20);

    }

    bg.QuitSDL(renderer, window);
    SDL_Quit();
    return 0;
}




