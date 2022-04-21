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
    while (!thunderEngine.shouldExit()) {
        std::cout << "Enter a mathematical expression: ";
        std::cout.flush();
        getline(std::cin, thunderEngine.mathExpression);
        double result = thunderEngine.evaluateMathExpression();
        if (thunderEngine.hasErrored()) {
            std::cout << thunderEngine.getInfoMessage() << std::endl;
        }
        else {
            std::cout << result << std::endl;
        }
    }

}
