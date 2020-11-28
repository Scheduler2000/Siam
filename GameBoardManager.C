#include "GameBoardManager.h"

char * GetBattlegroundCell(Game siam, Coordinates coord)
{
    return &(siam.gameBoard.Battleground[coord.line][coord.column]);
}
int CellsTributsAreEmpty(char *tribut)
{
    int i = 0;
    int result = 1;
    for(i; i < 5; i++)
        if(tribut != '_')
            result = 0;
    return result;
}
