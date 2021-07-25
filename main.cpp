/*
    XCalc-Rewrite - Rewrite of the XCalc calculator for PC and Xbox from absolute scratch
    Copyright (C) 2021 Kosmas Raptis

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void Init(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font) {
     if (SDL_Init(SDL_INIT_VIDEO) != 0) {
         std::cout << "Couldn't initialize SDL. Reason: " << SDL_GetError() << std::endl;
         exit(1);
     }

    if (TTF_Init() != 0) {
        std::cout << "Couldn't initialize SDL_ttf. Reason: " << TTF_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    font = TTF_OpenFont("Roboto-Regular.ttf", 23);
    if(!font) {
        std::cout << "Couldn't open font. Reason: " << TTF_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow("XCalc-Rewrite",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              640, 480,
                              SDL_WINDOW_SHOWN);

    if(!window) {
        std::cout << "Couldn't create window. Reason: " << SDL_GetError() << std::endl;
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    if(!renderer) {
        std::cout << "Couldn't create renderer. Reason: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

    SDL_SetRenderDrawColor(renderer, 76, 11, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font *font;

    Init(window, renderer, font);

    SDL_Event event;

    bool exited = false;

    while(!exited) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                exited = true;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
