#ifndef __PLAYER__
#define __PLAYER__

typedef struct Player
{
    char name[21]; // nom de maximum 20 caract�res . (name[21] = \0)
    double gameTime;
} Player;

void DefinePlayer(Player *player); // D�finit un joueur avec son nom et son score initialis� � 0.
void DefineIA(Player *player); // D�finit le joueur IA lors d'une partie Player vs IA.
#endif
