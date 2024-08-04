#include "../inc/constants.h"
#include "../inc/player.h"
#include "../inc/map.h"

void renderMiniMap(SDL_Renderer* renderer)
{
    // Loop through the world map and draw each tile
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            SDL_Rect tileRect = {
                .x = x * MINIMAP_TILE_SIZE,
                .y = y * MINIMAP_TILE_SIZE,
                .w = MINIMAP_TILE_SIZE,
                .h = MINIMAP_TILE_SIZE
            };

            switch(worldMap[x][y])
            {
                case 1: SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); break; // Red
                case 2: SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); break; // Green
                case 3: SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); break; // Blue
                case 4: SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255); break; // White
                case 5: SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); break; // Yellow
                default: SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); break; // Yellow
            }

            SDL_RenderFillRect(renderer, &tileRect);
        }
    }

    // Draw the player on the mini-mapsd
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // Yellow for the player
    SDL_Rect playerRect = {
        .x = player.x * MINIMAP_TILE_SIZE - MINIMAP_PLAYER_SIZE / 2,
        .y = player.y * MINIMAP_TILE_SIZE - MINIMAP_PLAYER_SIZE / 2,
        .w = MINIMAP_PLAYER_SIZE,
        .h = MINIMAP_PLAYER_SIZE
    };
    SDL_RenderFillRect(renderer, &playerRect);
}
