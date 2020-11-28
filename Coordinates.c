#include "Coordinates.h"
#include "ConsoleExtension.h"
#include "FightManager.h"
#include <math.h>

int DirectionsAreOpposed(Direction animal, Direction Enemy)
{
    int result = 0;
    if((animal == Top && Enemy == Down )|| (animal == Down && Enemy == Top))
        result = 1;
    else if ((animal == Right && Enemy == Left) || (animal == Left && Enemy == Right))
        result = 1;
    return result;
}
int IsOutsideCell(Coordinates coord)
{
    int result = 0;
    if(coord.line == 0 || coord.line == 4)
        result = 1;
    else if (coord.column == 0 || coord.column == 8)
        result = 1;
    else
        DisplayErrorMessage(1200,"La case voulue n'est pas une case exterieure...");
    return result;
}
Direction GetDirectionOpposed(Direction animal)
{
    Direction result;
    switch(animal)
    {
    case Top:
        result = Down;
        break;
    case Down:
        result = Top;
        break;
    case Left:
        result = Right;
        break;
    case Right:
        result = Left;
        break;
    }
    return result;
}
int IsFreeCell(Game siam,Coordinates coord)
{
    char cell = *(GetBattlegroundCell(&siam,coord));
    return (cell == 'A') ? 1 : 0;
}
int IsMountainCell(Game siam, Coordinates coord)
{
    char cell = *(GetBattlegroundCell(&siam,coord));
    return cell == 'M' ? 1 : 0;
}
char * GetBattlegroundCell(Game *siam, Coordinates coord)
{
    return &(siam->gameBoard.Battleground[coord.line][coord.column]);
}
int BattlegroundIsEmpty(Game siam, char animal)
{
    int result = 1;
    int i = 0;
    int j = 0;
    for(i; i < 5; i++)
        for(j = 0; j< 10; j++)
            if(siam.gameBoard.Battleground[i][j] == animal)
                result = 0;
    return result;
}
int CellsTributsAreEmpty(char *tribut)
{
    int i = 0;
    int result = 1;
    for(i; i < 5; i++)
        if(tribut[i] != '_')
            result = 0;
    return result;
}
Coordinates GetAdjacentCell(Game siam, Coordinates cell, Direction orientation)
{
    Coordinates result;
    switch(orientation)
    {
    case Top:
        if(cell.line == 0)
        {
            result.line = -1;
            result.column = -1;
        }
        else
        {
            result.line = cell.line-1;
            result.column = cell.column;
        }
        break;
    case Down:
        if(cell.line == 4)
        {
            result.line = -1;
            result.column = -1;
        }
        else
        {
            result.line = cell.line+1;
            result.column = cell.column;
        }
        break;
    case Left:
        if(cell.column == 0)
        {
            result.line = -1;
            result.column = -1;
        }
        else
        {
            result.line = cell.line;
            result.column = cell.column - 2;
        }
        break;
    case Right:
        if(cell.column == 8)
        {
            result.line = -1;
            result.column = -1;
        }
        else
        {
            result.line = cell.line;
            result.column = cell.column + 2;
        }
        break;
    }
    return result;
}
void GetAdjacentCells(Game siam,Coordinates cell,Direction orientation, char dest[5][2])
{
    char adjacentCells[5][2] = {'_'}; // [animal|montage + orientation][case]
    char *battlegroundCell;
    int i = 0;
    switch(orientation)
    {
    case Top:
        if(cell.line != 0)
        {
            while(cell.line > 0)
            {
                Coordinates adjacentCell = GetAdjacentCell(siam,cell,Top);
                battlegroundCell = GetBattlegroundCell(&siam,adjacentCell);
                adjacentCells[i][0] = *battlegroundCell;
                adjacentCells[i][1] = *(battlegroundCell + 1);
                cell.line--;
                i++;
            }
        }
        break;
    case Down:
        if(cell.line != 4)
        {
            while(cell.line < 4)
            {
                Coordinates adjacentCell = GetAdjacentCell(siam,cell,Down);
                battlegroundCell = GetBattlegroundCell(&siam,adjacentCell);
                adjacentCells[i][0] = *battlegroundCell;
                adjacentCells[i][1] = *(battlegroundCell + 1);
                cell.line++;
                i++;
            }
        }
        break;
    case Left:
        if(cell.column != 0)
        {
            while(cell.column > 0)
            {
                Coordinates adjacentCell = GetAdjacentCell(siam,cell,Left);
                battlegroundCell = GetBattlegroundCell(&siam,adjacentCell);
                adjacentCells[i][0] = *battlegroundCell;
                adjacentCells[i][1] = *(battlegroundCell + 1);
                cell.column -= 2;
                i++;
            }
        }
        break;
    case Right:
        if(cell.column != 8)
        {
            while(cell.column < 8)
            {
                Coordinates adjacentCell = GetAdjacentCell(siam,cell,Right);
                battlegroundCell = GetBattlegroundCell(&siam,adjacentCell);
                adjacentCells[i][0] = *battlegroundCell;
                adjacentCells[i][1] = *(battlegroundCell + 1);
                cell.column += 2;
                i++;
            }
        }
        break;
    }
    strcpy(dest,adjacentCells);
}
COORD GetCellConsolePosition(char line, int column)
{
    COORD pos;
    pos.X =  ceil(column / 2.0) * 5 + 47;
    pos.Y = (line - 'A') * 2 + 4; // Calcul expliqué dans le rapport avec la grille détaillée des coord. Un = Up + (n-p)r
    return pos;
}

COORD GetTributCellPosition(char animal, int cell)
{
    COORD coord;
    coord.Y = (cell - 1) * 2 + 4; // Calcul expliqué dans le rapport avec la grille détaillée des coord. Un = Up + (n-p)r
    switch(animal)
    {
    case 'E':
        coord.X = 32;
        break;
    case 'R':
        coord.X = 82;
        break;
    }
    return coord;
}
