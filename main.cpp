#include <iostream>
#include <SDL2/SDL.h>

void Init(SDL_Window *window, SDL_Renderer *renderer) {
     if (SDL_Init(SDL_INIT_VIDEO) != 0) {
         std::cout << "Couldn't initialize SDL. Reason: " << SDL_GetError() << std::endl;
         exit(1);
     }


    window = SDL_CreateWindow("XCalc-Rewrite",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              640, 480,
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    SDL_SetRenderDrawColor(renderer, 76, 11, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

}

int main() {
    SDL_Window *window;
    SDL_Renderer *renderer;

    Init(window, renderer);

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
