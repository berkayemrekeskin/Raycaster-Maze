#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SDL2/SDL.h>

void renderFrame(SDL_Renderer* renderer);
void movePlayer(float moveSpeed, float rotSpeed);
void createMaze();

#endif