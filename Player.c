#include "Player.h"
#include "ConsoleExtension.h"
#include "windows.h"

void DefinePlayer(Player *player)
{
    ClearConsole();
    SetCursorPosition(0,0);
    SetConsoleTextColor(4,0);
    printf("[Jeux] : ");
    SetConsoleTextColor(15,0);
    printf("Veuillez entrer votre pseudo de jeu.\n");
    scanf("%s",&(player->name));
    ClearConsole();
    SetConsoleTextColor(4,0);
    printf("[Jeux] : ");
    SetConsoleTextColor(15,0);
    printf("Le joueur %s est definit avec succes :D ",player->name);
    Sleep(1400);
    player->gameTime = 0;
}

void DefineIA(Player *player)
{
    strcpy(player->name,"Ordinateur");
    player->gameTime = 0;
}
