#ifndef __PLAYER__
#define __PLAYER__

typedef struct Player
{
    char name[21]; // nom de maximum 20 caractères . (name[21] = \0)
    double gameTime;
} Player;

void DefinePlayer(Player *player); // Définit un joueur avec son nom et son score initialisé à 0.
void DefineIA(Player *player); // Définit le joueur IA lors d'une partie Player vs IA.
#endif
