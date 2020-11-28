#include "Displacement.h"
#include "ConsoleExtension.h"
#include "Coordinates.h"
#include <windows.h>

void MoveTo(COORD cell, COORD newCell, char direction)
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    char ch = ' ';
    DWORD read;
    ReadConsoleOutputCharacter(screen, &ch,1,cell,&read);
    ClearConsoleCharacters(cell.X,cell.Y,2);
    SetCursorPosition(newCell.X,newCell.Y);
    switch(ch)
    {
    case 'E':
        SetConsoleTextColor(5,0);
        break;
    case 'R':
        SetConsoleTextColor(12,0);
        break;
    case 'M':
        SetConsoleTextColor(6,0);
        break;
    }
    printf("%c",ch);
    SetConsoleTextColor(14,0);
    printf("%c",direction);
    SetConsoleTextColor(15,0);
    SetCursorPosition(0,20);
}
void PushMove(Game siam,Coordinates cell,char direction, int NbrAnimal)
{
    Coordinates adjCell;
    COORD oldCell;
    COORD lastCell;
    int i = 0;

        for(i; i < NbrAnimal; i++)
        {
            adjCell = GetAdjacentCell(siam,cell,direction);
            oldCell = GetCellConsolePosition('A' + cell.line, cell.column);
            lastCell = GetCellConsolePosition('A' + adjCell.line,adjCell.column);
            cell.line = adjCell.line;
            cell.column = adjCell.column;
        }
        for(i = NbrAnimal; i > 0; i--)
        {
            MoveTo(oldCell,lastCell,direction);
            adjCell = GetAdjacentCell(siam,cell,GetDirectionOpposed(direction));
            lastCell = GetCellConsolePosition('A' + cell.line, cell.column);
            oldCell = GetCellConsolePosition('A' + adjCell.line,adjCell.column);
            cell.line = adjCell.line;
            cell.column = adjCell.column;
        }
}
void Reorient(COORD cell, char newOrientation)
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    char ch = ' ';
    DWORD read;
    ReadConsoleOutputCharacter(screen, &ch,1,cell,&read);
    ClearConsoleCharacters(cell.X,cell.Y+1,1);
}
