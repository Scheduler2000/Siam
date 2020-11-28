#ifndef __FIGHT_MANAGER__
#define __FIGHT_MANAGER__
#include "GameHandler.h"
#include "Coordinates.h"

typedef enum Animal
{
    Elephant = 'E',
    Rhinoceros = 'R'
}Animal;

typedef enum FightAction
{
    EnterAnimalAction = '1',
    MoveToFreeCellAction = '2',
    ChangeDirectionAction = '3',
    TakeOutAnimalAction = '4',
    MoveWithPushAction = '5'
}FightAction;

int OpenFightMenu(Game *siam); // Ouvre le menu de combat avec les différentes action realisable en jeu et renvoie si le tour s'est effectué correctement.
static void EnterAnimalToBattleground(Game *siam,Coordinates position, Direction orientation); // Entrer un animal sur le plateau de jeu.
static void TakeOutAnimalToBattleground(Game *siam, Coordinates position); // Sort un animal du plateau de jeu vers sa tribut.
static void MoveToFreeCell(Game *siam, Coordinates position); // Deplace un animal sur une case libre adjacente selon son orientation.
static void ChangeDirection(Game *siam, Coordinates position, Direction orientation); // Change l'orientation d'un animal sur le plateau de jeu.
static void MoveWithPush(Game *siam, Coordinates position); // Deplace un animal en tentant une pousée sur l'adversaire.
static int StrengthCalculation(Game siam, Coordinates animalCell);// Calcul la force de l'animal effectuant la poussée et ses adversaires.
static Animal GetCurrentAnimal(int gameRound); // Obtient le joueur actuel et retourne les pions qu'il manipulent.

#endif
