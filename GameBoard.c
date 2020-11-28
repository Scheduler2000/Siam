#include "GameBoard.h"
#include "ConsoleExtension.h"
#include "GameHandler.h"

void DrawGameBoard()
{
    ClearConsole();
    SetCursorPosition(0,0);
    SetConsoleTextColor(4,0);
    printf("[Jeux] : ");
    SetConsoleTextColor(15,0);
    printf("Le royaume de Siam vous souhaites bon courage :D");
    DrawElephantTribut();
    DrawRhinocerosTribut();
    DrawBattleground();
}
void DrawGameInformation(Game siam)
{
    int i = 0;
    for(i; i < 15; i++)
    {
        ClearConsoleCharacters(86,1 + i,45);
    }
    if(siam.round % 2 == 0) // si le tour de jeu est paire, alors c'est au joueur des élephants de jouer.
    {
        SetCursorPosition(86,1);
        printf("      _            _                 _");
        SetCursorPosition(86,2);
        printf("     | |          | |               | |");
        SetCursorPosition(86,3);
        SetConsoleTextColor(15,0);
        printf("  ___| | ___ _ __ | |__   __ _ _ __ | |_ ");
        SetCursorPosition(86,4);
        printf(" / _ \\ |/ _ \\ '_ \\| '_ \\ / _` | '_ \\| __|"),
               SetCursorPosition(86,5);
        printf(" | __/ |  __/ |_) | | | | (_| | | | | |_ ");
        SetCursorPosition(86,6);
        SetConsoleTextColor(4,0);
        printf(" \\___|_|\\___| .__/|_| |_|\\__,_|_| |_|\\__|");
        SetCursorPosition(86,7);
        printf("            | | ");
        SetCursorPosition(86,8);
        printf("            |_| ");
        SetCursorPosition(87, 10);
        SetConsoleTextColor(15,0);
        printf("Nom du joueur : ");
        SetConsoleTextColor(10,0);
        printf("%s",siam.elephant.name);
        SetCursorPosition(87, 11);
        SetConsoleTextColor(15,0);
        printf("Temps de jeu  : ");
        SetConsoleTextColor(14,0);
        printf("%d ",siam.elephant.gameTime);
    }
    else  // si le tour de jeu est impaire, alors c'est au joueur des rhinoceros de jouer.
    {
        SetCursorPosition(86,1);
        SetConsoleTextColor(10,0);
        printf("       _     _ ");
        SetCursorPosition(86,2);
        printf("  _ __| |__ (_)_ __   ___ ");
        SetCursorPosition(86,3);
        SetConsoleTextColor(15,0);
        printf(" | '__| '_ \\| | '_ \\ / _ \\ ");
        SetCursorPosition(86,4);
        printf(" | |  | | | | | | | | (_) | ");
        SetConsoleTextColor(14,0);
        SetCursorPosition(86,5);
        printf(" |_|  |_| |_|_|_| |_|\\___/ ");
        SetCursorPosition(87, 10);
        SetConsoleTextColor(15,0);
        printf("Nom du joueur : ");
        SetConsoleTextColor(10,0);
        printf("%s",siam.rhinoceros.name);
        SetCursorPosition(87, 11);
        SetConsoleTextColor(15,0);
        printf("Temps de jeu  : ");
        SetConsoleTextColor(14,0);
        printf("%s ",siam.rhinoceros.gameTime);
    }
}
static void DrawBattleground()
{
    int i = 0;
    SetCursorPosition(45,2);
    printf("  1    2    3    4    5"); // Affiche les coordonnées de l'axe (Ox <=> colonne) du champs de bataille.
    SetCursorPosition(45,3);
    for(i; i < 12; i++) // Affichage de la grille du champ de bataille
    {
        if( ((i+1) % 2 == 0) )
            printf("+----+----+----+----+----+");
        else
            printf("|    |    |    |    |    |");
        SetCursorPosition(45,(3+i));
    }
    for(i = 0; i < 3; i++) // Affiche les montagnes sur le champ de bataille.
    {
        SetCursorPosition(57,(6+(2*i)) );
        SetConsoleTextColor(6,0);
        printf("Û"); // Û = table des caracteres > police terminale > représente une montagne.
    }
    SetConsoleTextColor(15,0);
    for(i = 0; i < 5; i++) // Affiche les coordonnées de l'axe (Oy <=> ligne) du champs de bataille.
    {
        SetCursorPosition(43,4+2*i);
        printf("%c",'A'+ i);
    }
}
static void DrawRhinocerosTribut()
{
    SetCursorPosition(80,3);
    int i = 0;
    for(i; i < 12; i++)
    {
        if( ((i+1) % 2 == 0) )
            printf("+----+");
        else
            printf("|    |");
        SetCursorPosition(80,(3+i));
    }
    for(i = 0; i < 5; i++)
    {
        SetCursorPosition(82,(4+(2*i) ));
        SetConsoleTextColor(12,0);
        printf("R");
        SetConsoleTextColor(14,0);
        printf("g");
    }
    SetConsoleTextColor(15,0);
}
static void DrawElephantTribut()
{
    SetCursorPosition(30,3);
    int i = 0;
    for(i; i < 12; i++)
    {
        if( ((i+1) % 2 == 0) )
            printf("+----+");
        else
            printf("|    |");
        SetCursorPosition(30,(3+i));
    }
    for(i = 0; i < 5; i++)
    {
        SetCursorPosition(32,(4+(2*i) ));
        SetConsoleTextColor(5,0);
        printf("E");
        SetConsoleTextColor(14,0);
        printf("d");
    }
    SetConsoleTextColor(15,0);
}


void InitializeGameBoard(GameBoard *gameBoard)
{
    InitializeElephantTribut(gameBoard->ElephantTribut);
    InitializeRhinocerosTribut(gameBoard->RhinocerosTribut);
    InitializeBattleground(gameBoard->Battleground);
}
static void InitializeBattleground(char battleground[5][10])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if(j == 4 && (i == 1 || i == 2 || i == 3))
                battleground[i][j] = 'M';
            else
            {
                if((j+1) % 2 == 0 && battleground[i][j-1] != 'M')
                    battleground[i][j] = 'D';
                else
                {
                    if(battleground[i][j-1] != 'M')
                        battleground[i][j] = 'A';
                    else
                        battleground[i][j] = '_';
                }
            }
        }
    }
}
    static void InitializeElephantTribut(char *elephantTribut)
    {
        int i = 0;
        for(i; i <5; i++)
            elephantTribut[i]='E';
    }
    static void InitializeRhinocerosTribut(char *rhinocerosTribut)
    {
        int i = 0;
        for (i; i < 5; i++)
            rhinocerosTribut[i] = 'R';
    }

