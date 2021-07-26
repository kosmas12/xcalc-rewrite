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
