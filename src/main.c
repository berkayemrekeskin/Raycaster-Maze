#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "../inc/constants.h"
#include "../inc/map.h"
#include "../inc/player.h"
#include "../inc/functions.h"
#include "renderFrame.c"
#include "movePlayer.c"
#include "createMaze.c"

int main(int argc, char* argv[])
{
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Could not init SDL: %s\n", SDL_GetError());
        return 1;
    }
    
    SDL_Window* window = SDL_CreateWindow("BEK_RayCasting", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if(!window) {
        fprintf(stderr, "Window could not created! %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(!renderer) {
        fprintf(stderr, "Renderer could not created! %s\n", SDL_GetError());
        return 1;
    }

    int running = 1;
    double time = 0;
    double oldTime = 0;
    createMaze();

    SDL_Event event;

    while(running)
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
        const Uint8* state = SDL_GetKeyboardState(NULL);
        oldTime = time;
        time = SDL_GetTicks();
        double frameTime = (time - oldTime) / 1000.0;
        double moveSpeed = frameTime * 5.0;
        double rotSpeed = frameTime * 3.0;

        movePlayer(moveSpeed, rotSpeed);
        
        SDL_RenderClear(renderer);
        renderFrame(renderer);
        SDL_RenderPresent(renderer);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}