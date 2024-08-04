#include "../inc/functions.h"
#include "../inc/constants.h"
#include "../inc/player.h"
#include "../inc/map.h"

void renderFrame(SDL_Renderer* renderer)
{   

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);


    for(int x = 0; x < SCREEN_WIDTH; x++)
    {
        float cameraX = 2 * x / (float)SCREEN_WIDTH - 1;
        float rayDirX = player.dirX + player.planeX * cameraX;
        float rayDirY = player.dirY + player.planeY * cameraX;
        
        int mapX = (int)player.x;
        int mapY = (int)player.y;

        float sideDistX;
        float sideDistY;

        float deltaDistX = fabs(1 / rayDirX);
        float deltaDistY = fabs(1 / rayDirY);
        float perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if(rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (player.x - mapX) * deltaDistX;
        }
        else 
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player.x) * deltaDistX;
        }
        if(rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (player.y - mapY) * deltaDistY;
        }
        else 
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player.y) * deltaDistY;
        }
        
        while(hit == 0)
        {
            if(sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else 
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if(worldMap[mapX][mapY] > 0)
                hit = 1;
        }

        if(side == 0)
            perpWallDist = (mapX - player.x + (1 - stepX) / 2) / rayDirX;
        else 
            perpWallDist = (mapY - player.y + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if(drawStart < 0) 
            drawStart = 0;
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if(drawEnd >= SCREEN_HEIGHT)
            drawEnd = SCREEN_HEIGHT - 1;

        SDL_Color color;
        switch(worldMap[mapX][mapY])
        {
            case 1: color = (SDL_Color){255, 0, 0, 255}; break;
            case 2: color = (SDL_Color){0, 255, 0, 255}; break;
            case 3: color = (SDL_Color){0, 0, 255, 255}; break;
            case 4: color = (SDL_Color){255, 255, 255, 255}; break;
            default: color = (SDL_Color){255, 255, 0, 255}; break;
        }
        
        if(side == 1)
        {
            color.r /= 2;
            color.g /= 2;
            color.b /= 2;
        }

        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);
    }
}
