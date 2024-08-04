#include "../inc/functions.h"
#include "../inc/constants.h"
#include "../inc/player.h"
#include "../inc/map.h"

void movePlayer(float moveSpeed, float rotSpeed)
{

    const Uint8* state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_W]) {
        if (worldMap[(int)(player.x + player.dirX * moveSpeed)][(int)player.y] == 0) player.x += player.dirX * moveSpeed;
        if (worldMap[(int)player.x][(int)(player.y + player.dirY * moveSpeed)] == 0) player.y += player.dirY * moveSpeed;
    }
    if (state[SDL_SCANCODE_S]) {
        if (worldMap[(int)(player.x - player.dirX * moveSpeed)][(int)player.y] == 0) player.x -= player.dirX * moveSpeed;
        if (worldMap[(int)player.x][(int)(player.y - player.dirY * moveSpeed)] == 0) player.y -= player.dirY * moveSpeed;
    }
    if (state[SDL_SCANCODE_A]) {
        float oldDirX = player.dirX;
        player.dirX = player.dirX * cos(rotSpeed) - player.dirY * sin(rotSpeed);
        player.dirY = oldDirX * sin(rotSpeed) + player.dirY * cos(rotSpeed);
        float oldPlaneX = player.planeX;
        player.planeX = player.planeX * cos(rotSpeed) - player.planeY * sin(rotSpeed);
        player.planeY = oldPlaneX * sin(rotSpeed) + player.planeY * cos(rotSpeed);
    }
    if(state[SDL_SCANCODE_D]) {
        float oldDirX = player.dirX;
        player.dirX = player.dirX * cos(-rotSpeed) - player.dirY * sin(-rotSpeed);
        player.dirY = oldDirX * sin(-rotSpeed) + player.dirY * cos(-rotSpeed);
        float oldPlaneX = player.planeX;
        player.planeX = player.planeX * cos(-rotSpeed) - player.planeY * sin(-rotSpeed);
        player.planeY = oldPlaneX * sin(-rotSpeed) + player.planeY * cos(-rotSpeed);
    }
}