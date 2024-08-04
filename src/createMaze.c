#include "../inc/map.h"

void createMaze()
{
    int rows = sizeof(worldMap) / sizeof(worldMap[0]);
    int cols = sizeof(worldMap[0]) / sizeof(worldMap[0][0]);
    int colors[] = {2,3,4};

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
        if(worldMap[i][j] == 0)
        {
            if(rand() % 100 < 20)
            {
                worldMap[i][j] = colors[rand() % 3];
            }
        }
        }
    }
    worldMap[rand() % rows][rand() % cols] = 5;
}