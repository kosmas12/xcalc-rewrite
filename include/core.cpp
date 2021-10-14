#include "core.h"

void InitSDL(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Couldn't initialize SDL. Reason: " << SDL_GetError() << std::endl;
        exit(1);
    }

    *window = SDL_CreateWindow("XCalc-Rewrite",
                               SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               WIDTH, HEIGHT,
                               SDL_WINDOW_SHOWN);

    if(!*window) {
        std::cout << "Couldn't create window. Reason: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_SOFTWARE);

    if(!*renderer) {
        std::cout << "Couldn't create renderer. Reason: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(*window);
        SDL_Quit();
        exit(1);
    }
}

void InitTTF(TTF_Font **font, SDL_Window **window, SDL_Renderer **renderer) {
    if (TTF_Init() != 0) {
        std::cout << "Couldn't initialize SDL_ttf. Reason: " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        SDL_Quit();
    }

    *font = TTF_OpenFont("Roboto-Regular.ttf", 18);
    if(!*font) {
        std::cout << "Couldn't open font. Reason: " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }
}

void showBootupText(TTF_Font **font, SDL_Renderer **renderer) {
    SDL_Surface *bootupTextSurface = TTF_RenderText_Blended_Wrapped(*font,
                                                                    "Welcome to XCalc-Rewrite!\n"
                                                                    "Copyright 2021 Kosmas Raptis\n"
                                                                    "This program comes with ABSOLUTELY NO WARRANTY;\n"
                                                                    "This is free software, and you are welcome to redistribute it\n"
                                                                    "under certain conditions; see COPYING for details.\n",
                                                                    {255, 255, 255, 255}, WIDTH);

    SDL_Texture *bootupTextTexture = SDL_CreateTextureFromSurface(*renderer, bootupTextSurface);

    SDL_Rect destRect = {40, 40, bootupTextSurface->w, bootupTextSurface->h};
    SDL_FreeSurface(bootupTextSurface);

    SDL_RenderCopy(*renderer, bootupTextTexture, nullptr, &destRect);
    SDL_DestroyTexture(bootupTextTexture);

    SDL_RenderPresent(*renderer);
}

void Init(SDL_Window **window, SDL_Renderer **renderer, TTF_Font **font) {
    InitSDL(window, renderer);
    InitTTF(font, window, renderer);

    SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
    SDL_RenderClear(*renderer);

    showBootupText(font, renderer);
}
