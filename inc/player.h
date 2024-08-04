#ifndef PLAYER_H
#define PLAYER_H

typedef struct 
{
    float x,y;
    float dirX, dirY;
    float planeX, planeY;

} Player;

Player player = {22,12,-1,0,0,0.66};

#endif