#ifndef __GAME_HANDLER__
#define __GAME_HANDLER__
#include "GameBoard.h"
#include "Player.h"

typedef enum FightType
{
    PlayerVsPlayer,
    PlayerVsIA
} FightType;

typedef struct Game
{
    GameBoard gameBoard;
    Player elephant;
    Player rhinoceros;
    FightType fightType;
    int round; // Repr�sente le tour de jeu.
} Game;

void PlayGame(Game *siam); // Lance la partie de jeu selon le mode de jeu.
int  GameOver(Game siam); // D�termine si la partie est termin�e.
void NextRound(Game *siam); // Lance le tour suivant.


#endif
