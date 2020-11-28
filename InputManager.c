#include "InputManager.h"

Coordinates AskCoordinates()
{
    Coordinates coord;
    char cColumn = ' ';
    char cLine = ' ';
    int line = 0;
    int column = 0;
    char validation = ' ';
    int errorCount = 0;
    do
    {
        SetCursorPosition(2,23);
        SetConsoleTextColor(4,0);
        printf("[Jeux] : ");
        SetConsoleTextColor(15,0);
        printf("Veuillez entrer le numero de la colonne (Taper 'R' pour revenir en arriere) ");
        SetConsoleTextColor(6,0);
        printf("[1 | 2 | 3 | 4 | 5]\n");
        do // Blindage et demande colonne souhaitée.
        {
            SetConsoleTextColor(15,0);
            cColumn = getchar();
            switch(cColumn)
            {
            case '1':
                column = 0;
                break;
            case '2':
                column = 2;
                break;
            case '3':
                column = 4;
                break;
            case '4':
                column = 6;
                break;
            case '5':
                column = 8;
                break;
            case '\n':
                cColumn = ' ';
                errorCount++;
                break;
            case 'R':
                column = -1;
                break;
            default:
                SetConsoleTextColor(4,0);
                printf("[Erreur] : Numero de colonne inconnue ...\n");
                cColumn = ' ';
                errorCount++;
                break;
            }
        }
        while(cColumn == ' ');
        ClearConsoleLines(0,23,errorCount+1);
        if(column == -1)
            break;
        errorCount = 0;
        SetCursorPosition(2,23);
        SetConsoleTextColor(4,0);
        printf("[Jeux] : ");
        SetConsoleTextColor(15,0);
        printf("Veuillez entrer la lettre de la ligne ");
        SetConsoleTextColor(6,0);
        printf("[A | B | C | D | E]\n");
        do // Blindage et demande de la ligne souhaitée.
        {
            SetConsoleTextColor(15,0);
            cLine = getchar();
            switch(cLine)
            {
            case 'A':
                line = 0;
                break;
            case 'B':
                line = 1;
                break;
            case 'C':
                line = 2;
                break;
            case 'D':
                line = 3;
                break;
            case 'E':
                line = 4;
                break;
            case '\n':
                cLine = ' ';
                errorCount++;
                break;
            default:
                SetConsoleTextColor(4,0);
                printf("[Erreur] : Lettre de colonne inconnue ...\n");
                cLine = ' ';
                errorCount++;
                break;
            }
        }
        while(cLine == ' ');
        ClearConsoleLines(0,23,errorCount+1);
        errorCount = 0;
        SetCursorPosition(2,23);
        printf("[Jeux] : ");
        SetConsoleTextColor(15,0);
        printf("Les coordonnees de la case voulue sont donc ");
        SetConsoleTextColor(6,0);
        printf("[%c;%c]\n",cLine,cColumn);
        printf("Oui -> O\nNon -> N\n");
        do // Blindage et demande si les coordonnées sont celles voulues.
        {
            SetConsoleTextColor(15,0);
            validation = getchar();
            switch(validation)
            {
            case 'O':
            case 'N':
                break;
            case '\n':
                validation = ' ';
                errorCount++;
                break;
            default:
                SetConsoleTextColor(4,0);
                printf("[Erreur] : Entree incorrect ...\n");
                validation = ' ';
                errorCount++;
                break;
            }
        }
        while(validation == ' ');
        ClearConsoleLines(0,23,errorCount+3);
    }
    while(validation != 'O');
    coord.column = column;
    coord.line = line;
    return coord;
}

Direction AskDirection()
{
    Direction direction;
    char orientation = ' ';
    char validation = ' ';
    int errorCount = 0;
    do
    {
        SetCursorPosition(2,23);
        SetConsoleTextColor(4,0);
        printf("[Jeux] : ");
        SetConsoleTextColor(15,0);
        printf("Veuillez entrer l'orientation voulue ");
        SetConsoleTextColor(6,0);
        printf("[H | B | G | D]\n");
        do // Blindage et demande orientation souhaitée.
        {
            SetConsoleTextColor(15,0);
            orientation = getchar();
            switch(orientation)
            {
            case 'H':
                direction = Top;
                break;
            case 'B':
                direction = Down;
                break;
            case 'G':
                direction = Left;
                break;
            case 'D':
                direction = Right;
                break;
            case '\n':
                orientation = ' ';
                errorCount++;
                break;
            default:
                SetConsoleTextColor(4,0);
                printf("[Erreur] : Orientation inexistante ...\n");
                orientation = ' ';
                errorCount++;
                break;
            }
        }
        while(orientation == ' ');
        ClearConsoleLines(0,23,errorCount+1);
        errorCount = 0;
        SetCursorPosition(2,23);
        SetConsoleTextColor(4,0);
        printf("[Jeux] : ");
        SetConsoleTextColor(15,0);
        printf("L'orientation de votre animal est donc la suivante ");
        SetConsoleTextColor(6,0);
        printf("[ %c ]\n",orientation);
        printf("Oui -> O\nNon -> N\n");
        do // Blindage et demande si l'orientation est celle voulue.
        {
            SetConsoleTextColor(15,0);
            validation = getchar();
            switch(validation)
            {
            case 'O':
            case 'N':
                break;
            case '\n':
                validation = ' ';
                errorCount++;
                break;
            default:
                SetConsoleTextColor(4,0);
                printf("[Erreur] : Entree incorrect ...\n");
                validation = ' ';
                errorCount++;
                break;
            }
        }
        while(validation == ' ');
        ClearConsoleLines(0,23,errorCount+3);
    }
    while(validation != 'O');
    return direction;
}
