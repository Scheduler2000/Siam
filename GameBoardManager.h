#ifndef __GAME_BOARD_MANAGER__
#define __GAME_BOARD_MANAGER__
#include "Coordinates.h"

int CellsTributsAreEmpty(char *tribut); // Détermine si la tribut éléphant ou rhinoceros est vide.
char *GetBattlegroundCell(Game siam, Coordinates coord); // Obtient la case d'un champs de bataille de coordonnées coord.

#endif
