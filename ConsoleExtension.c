#include <stdio.h>
#include "ConsoleExtension.h"
#include <windows.h>

void ClearConsole()
{
    system("cls");
}

void ClearConsoleLine(int line, int column)
{
    int currentLine = GetCursorPosition('x');
    int currentColumn = GetCursorPosition('y');
    SetCursorPosition(line,column);
    printf("                                                                                                                       ");
    SetCursorPosition(currentLine,currentColumn);
}
void ClearConsoleCharacters(int line, int column, int amountCharacteres)
{
     int i = 0;
     int currentLine = GetCursorPosition('x');
     int currentColumn = GetCursorPosition('y');
     SetCursorPosition(line,column);
     for(i; i < amountCharacteres; i++)
        printf(" ");
     SetCursorPosition(currentLine,currentColumn);
}
void ClearConsoleLines(int line, int column, int iteration)
{
    int i =0;
    for(i; i < iteration; i++)
        ClearConsoleLine(line,column + i);
}
void SetCursorPosition(int line, int column)
{
    COORD position;
    position.X = line;
    position.Y = column;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}


void SetConsoleTextColor(int foreground, int background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  background * 16 + foreground);
}

int GetCursorPosition(char component)
{
    CONSOLE_SCREEN_BUFFER_INFO screenInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);
    int pos = 0;
    switch(component)
    {
    case 'x':
        pos = screenInfo.dwCursorPosition.X;
        break;
    case 'y':
        pos = screenInfo.dwCursorPosition.Y;
        break;
    default:
        pos = -1;
        break;
    }
    return pos;
}

void DisplayErrorMessage(int millisecondes, char * message)
{
    int posX = GetCursorPosition('x');
    int posY = GetCursorPosition('y');
    SetConsoleTextColor(4,0);
    printf("[Erreur] : ");
    SetConsoleTextColor(15,0);
    printf("%s",message);
    Sleep(millisecondes);
    ClearConsoleLine(posX,posY);
}
