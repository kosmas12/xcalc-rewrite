#include <iostream>
/*
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "include/core.h"
*/
#include "include/thunderengine.h"

int main() {
/*
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
*/

    ThunderEngine thunderEngine;
    getline(std::cin, thunderEngine.mathExpression);
    std::cout << thunderEngine.evaluateMathExpression() << std::endl;

}
