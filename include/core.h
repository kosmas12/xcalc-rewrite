#ifndef XCALC_REWRITE_CORE_H
#define XCALC_REWRITE_CORE_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WIDTH 640
#define HEIGHT 480

void InitSDL(SDL_Window **window, SDL_Renderer **renderer);
void InitTTF(TTF_Font **font, SDL_Window **window, SDL_Renderer **renderer);
void showBootupText(TTF_Font **font, SDL_Renderer **renderer);
void Init(SDL_Window **window, SDL_Renderer **renderer, TTF_Font **font);


#endif //XCALC_REWRITE_CORE_H
