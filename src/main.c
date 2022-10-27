#include <stdio.h>
#include "SDL2/SDL.h"

int main(int arc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow(
        "Chip-8 Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 320,
        SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);
    while (1)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT){
                goto out;
            }
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_Rect rectangle;
        rectangle.x = 0;
        rectangle.y = 0;
        rectangle.w = 40;
        rectangle.h = 40;
        SDL_RenderFillRect(renderer, &rectangle);
        SDL_RenderPresent(renderer);
    }
out:
    SDL_DestroyWindow(window);
    return 0;
}