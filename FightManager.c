#include "FightManager.h"
#include "InputManager.h"
#include "GameHandler.h"
#include "ConsoleExtension.h"

int OpenFightMenu(Game *siam)
{

    int errorCount = 0;
    int i = 0;
    char c[5][2] = {' '};

    int result = 1;
    SetCursorPosition(30,15);
    SetConsoleTextColor(4,0);
    printf("[Jeux] : ");
    SetConsoleTextColor(15,0);
    printf("Menu de combat : ");
    char choice = ' ';
    for (i = 0; i < 5; i++) // Affichage du menu sur la console
    {
        SetConsoleTextColor(i + 2, 0);
        switch (i + 1)
        {
        case 1:
            SetCursorPosition(30,15+i+1);
            printf("\t %d . Entrer un de ses animaux sur le plateau.", i + 1);
            break;
        case 2:
            SetCursorPosition(30,15+i+1);
            printf("\t %d . Se deplacer sur une case libre.", i + 1);
            break;
        case 3:
            SetCursorPosition(30,15+i+1);
            printf("\t %d . Changer l'orientation de son animal sans changer de case.", i + 1);
            break;
        case 4:
            SetCursorPosition(30,15+i+1);
            printf("\t %d . Sortir un de ses animaux disposes sur une case exterieure.", i + 1);
            break;
        case 5:
            SetCursorPosition(30,15+i+1);
            printf("\t %d . Se deplacer en poussant d'autres pions disposes sur le plateau\n.", i + 1);
            break;
        }
    }
    do // Blindage et demande du menu souhaité.
    {
        Coordinates coord;
        Coordinates newCoord;
        Animal currentAnimal = GetCurrentAnimal(siam->round);
        Direction orientation;
        int cellIsAvailable = 0;
        SetConsoleTextColor(15,0);
        choice = getchar();
        switch(choice)
        {

        case EnterAnimalAction:
            ClearConsoleLines(0,21,errorCount + 1);
            if(currentAnimal == Elephant && CellsTributsAreEmpty(siam->gameBoard.ElephantTribut) ||
               currentAnimal == Rhinoceros && CellsTributsAreEmpty(siam->gameBoard.RhinocerosTribut))
            {
                DisplayErrorMessage(1200,"Votre tribut d'animal est vide.");
                result = 0;
                continue;
            }
            do
            {
                coord = AskCoordinates();
                if(coord.column == -1) // coord.colum == -1 => CHOICE R (revenir en arriere). rcf AskCoordinates().
                    return 0;
                cellIsAvailable = (IsOutsideCell(coord) == 1 && IsFreeCell(*siam,coord) == 1) ? 1 : 0;
                if(IsFreeCell(*siam,coord) == 0)
                    DisplayErrorMessage(1200,"Cette case n'est pas disponible.");
            }
            while(!cellIsAvailable);
            orientation = AskDirection();
            EnterAnimalToBattleground(siam,coord,orientation);
            break;

        case MoveToFreeCellAction:
            ClearConsoleLines(0,21,errorCount + 1);
            if(BattlegroundIsEmpty(*siam,currentAnimal))
            {
                DisplayErrorMessage(1200,"Vous n'avez aucun animal sur le champ de bataille.");
                result = 0;
                continue;
            }
            else
            {
                do
                {
                    coord = AskCoordinates();
                    if(coord.column == -1)
                        return 0;
                    char *orientation = GetBattlegroundCell(siam,coord) + 1;
                    newCoord = GetAdjacentCell(*siam,coord,*orientation);
                    cellIsAvailable =  (IsFreeCell(*siam,coord) == 0 && IsMountainCell(*siam,coord) == 0 && *GetBattlegroundCell(siam,coord) == currentAnimal) ? 1 : 0;
                    if(!cellIsAvailable)
                        DisplayErrorMessage(1200,"Cette case du plateau de jeu n'est pas disponible.");
                }
                while(!cellIsAvailable);
                if(!IsFreeCell(*siam,newCoord))
                {
                    DisplayErrorMessage(1800,"La future case n'est pas disponible, ou vous devez pousser pour y acceder.");
                    result = 0;
                    continue;
                }
                MoveToFreeCell(siam,coord);
            }
            break;

        case ChangeDirectionAction:
            ClearConsoleLines(0,21,errorCount + 1);
            if(BattlegroundIsEmpty(*siam, currentAnimal))
            {
                DisplayErrorMessage(1200,"Vous n'avez aucun animal sur le champ de bataille.");
                result = 0;
                continue;
            }
            else
            {
                do
                {
                    coord = AskCoordinates();
                    if(coord.column == -1)
                        return 0;
                    cellIsAvailable =  (IsFreeCell(*siam,coord) == 0 && IsMountainCell(*siam,coord) == 0 && *GetBattlegroundCell(siam,coord) == GetCurrentAnimal(siam->round)) ? 1 : 0;
                    orientation = AskDirection();
                    if(!cellIsAvailable)
                        DisplayErrorMessage(1200,"Cette case du plateau de jeu n'est pas disponible.");
                }
                while(!cellIsAvailable);
                ChangeDirection(siam,coord,orientation);
            }
            break;

        case TakeOutAnimalAction:
            ClearConsoleLines(0,21,errorCount + 1);
            if(BattlegroundIsEmpty(*siam, currentAnimal))
            {
                DisplayErrorMessage(1200,"Vous n' avez aucun animal sur le champ de bataille.");
                result = 0;
                continue;
            }
            else
            {
                do
                {
                    coord = AskCoordinates();
                    if(coord.column == -1)
                        return 0;
                    cellIsAvailable =  (IsFreeCell(*siam,coord) == 0 && IsMountainCell(*siam,coord) == 0 && *GetBattlegroundCell(siam,coord) == GetCurrentAnimal(siam->round)) ? 1 : 0;
                    if(!cellIsAvailable)
                        DisplayErrorMessage(1200,"Cette case du plateau de jeu n'est pas disponible.");
                }
                while(!cellIsAvailable);
                if(!IsOutsideCell(coord))
                {
                    DisplayErrorMessage(1200,"Vous n'etes pas sur une case exterieure.");
                    result = 0;
                    continue;
                }
                TakeOutAnimalToBattleground(siam,coord);
            }
            break;

        case MoveWithPushAction:
            coord  = AskCoordinates();
            if(coord.column == -1)
                return 0;
            int p = StrengthCalculation(*siam,coord);
            if(p == 1)
                printf("Vous pouvez push vos enemy.");
            break;
        case '\n':
            choice =0;
            errorCount++;
            break;
        default:
            SetConsoleTextColor(4,0);
            printf("[Erreur] : Numero de menu incorrect ...\n");
            choice = 0;
            errorCount++;
            break;

        }
    }
    while(choice == 0);
    return result;
}
static void EnterAnimalToBattleground(Game *siam, Coordinates coord, Direction orientation)
{
    int gameRound = siam->round;
    int i = 0;
    char *elephantTribut = siam->gameBoard.ElephantTribut;
    char *rhinocerosTribut = siam->gameBoard.RhinocerosTribut;
    char  *animalCell =  GetBattlegroundCell(siam,coord);
    char *animalDirection = animalCell+1;
    COORD cellTributCoord;
    COORD newCell = GetCellConsolePosition('A' + coord.line, coord.column);
    Animal currentPlayer = GetCurrentAnimal(gameRound);

    switch(currentPlayer)
    {
    case Elephant:
        if(IsFreeCell(*siam,coord))
        {
            for(i = 0; i < 5; i++)
            {
                if(elephantTribut[i] == 'E')
                {
                    elephantTribut[i] = '_';
                    cellTributCoord = GetTributCellPosition('E',i+1);
                    break;
                }
            }
            *animalCell = 'E';
            *animalDirection = orientation;
        }
        break;
    case Rhinoceros:
        if(IsFreeCell(*siam,coord))
        {
            for(i = 0; i < 5; i++)
            {
                if(rhinocerosTribut[i] == 'R')
                {
                    rhinocerosTribut[i] = '_';
                    cellTributCoord = GetTributCellPosition('R',i+1);
                    break;
                }
            }
            *animalCell = 'R';
            *animalDirection = orientation;
        }
        break;
    }
    MoveTo(cellTributCoord,newCell,orientation);
}
static void ChangeDirection(Game *siam, Coordinates position, Direction orientation)
{
    char *direction = GetBattlegroundCell(siam,position) + 1;
    COORD cellPosition = GetCellConsolePosition('A' + position.line,position.column);
    *direction = orientation;
    MoveTo(cellPosition,cellPosition,orientation);
}
static void TakeOutAnimalToBattleground(Game *siam,Coordinates position)
{
    char *animalCell = GetBattlegroundCell(siam,position);
    char *animalDirection = animalCell + 1;
    char *elephantTribut = siam->gameBoard.ElephantTribut;
    char *rhinocerosTribut = siam->gameBoard.RhinocerosTribut;
    int i = 0;
    COORD cell = GetCellConsolePosition('A' + position.line,position.column);
    COORD cellTributCoord;
    Animal currentAnimal = GetCurrentAnimal(siam->round);

    switch(currentAnimal)
    {
    case Elephant:
        for(i = 0; i < 5; i++)
        {
            if(elephantTribut[i] == '_')
            {
                elephantTribut[i] = 'E';
                cellTributCoord = GetTributCellPosition('E', i + 1);
                break;
            }
            MoveTo(cell,cellTributCoord,Right);
        }
        break;
    case Rhinoceros:
        for(i = 0; i < 5; i++)
        {
            if(rhinocerosTribut[i] == '_')
            {
                rhinocerosTribut[i] = 'R';
                cellTributCoord = GetTributCellPosition('R', i + 1);
                break;
            }
        }
        MoveTo(cell,cellTributCoord,Left);
        break;
    }
    *animalCell = 'A';
    *animalDirection = 'D';
}
static void MoveToFreeCell(Game *siam, Coordinates position)
{
    char *animalCell = GetBattlegroundCell(siam,position);
    char *animalDirection = animalCell + 1;
    Coordinates newPosition = GetAdjacentCell(*siam,position,*animalDirection);
    char *newAnimalCell = GetBattlegroundCell(siam,newPosition);
    char *newAnimalDirection = newAnimalCell + 1;
    Animal currentAnimal = GetCurrentAnimal(siam->round);
    COORD cell = GetCellConsolePosition('A' + position.line,position.column);
    COORD newCell = GetCellConsolePosition('A' + newPosition.line,newPosition.column);

    switch(currentAnimal)
    {
    case Rhinoceros:
        *newAnimalCell = 'R';
        break;
    case Elephant:
        *newAnimalCell = 'E';
        break;
    }
    *newAnimalDirection = *animalDirection;
    *animalCell = 'A';
    *animalDirection = 'D';
    MoveTo(cell,newCell,*newAnimalDirection);
}
static void MoveWithPush(Game *siam, Coordinates position)
{
    char *animalCell = GetBattlegroundCell(siam,position);
    char *animalOrientation = animalCell + 1;
    char adjacentCells[5][2];
    int i = 0;
    GetAdjacentCells(*siam,position,*animalOrientation,adjacentCells);
    while(adjacentCells[i][0] == 'A' || adjacentCells[i][1] == 'A' || adjacentCells[i][0] == 'R' || adjacentCells[i][1] == 'R' ||
            adjacentCells[i][0] == 'M' ||  adjacentCells[i][1] == 'M'  ||
            adjacentCells[i][0] == '_' || adjacentCells[i][1] == '_')
        i++;
    if(StrengthCalculation(*siam,position))
    {
        PushMove(*siam,position,*animalOrientation,i);
    }
}
static int StrengthCalculation(Game siam,Coordinates animalCell)
{
    char adjacentCells[5][2];
    double strenghtAnimal = 1;
    double strenghtEnemy = 0;
    int i = 0;
    int j = 0;
    char *animal = GetBattlegroundCell(&siam,animalCell);
    char *animalOrientation = animal + 1;
    char ennemyOrientation = ' ';
    char ennemyEntity = ' ';
    GetAdjacentCells(siam,animalCell,*animalOrientation,adjacentCells);

    for(i; i < 5; i++)
    {
        ennemyEntity = adjacentCells[i][0];
        ennemyOrientation = adjacentCells[i][1];
        if(*animal == ennemyEntity && *animalOrientation == ennemyOrientation)
            strenghtAnimal += 1 ;
        else if (*animal != ennemyEntity)
        {
            if(ennemyOrientation == *animalOrientation)
                strenghtAnimal += 1;
            else if(DirectionsAreOpposed(*animalOrientation,ennemyOrientation))
                strenghtEnemy += 1;
            else if(ennemyEntity == 'M')
                strenghtEnemy += 0.9;
        }
    }

    return strenghtAnimal > strenghtEnemy ? 1 : 0;
}
static Animal GetCurrentAnimal(int gameRound)
{
    Animal animal;
    if(gameRound % 2 == 0)
        animal = Elephant;
    else
        animal = Rhinoceros;
    return animal;
}


