/*
    This file is part of XCalc-Rewrite - Rewrite of the XCalc calculator for PC and Xbox from absolute scratch
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
#include "include/core.h"

int main() {
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font *font;

    Init(&window, &renderer, &font);

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
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
