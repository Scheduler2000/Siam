#ifndef __DISPLACEMENT__
#define __DISPLACEMENT__
#include "GameHandler.h"
#include <windows.h>
#include "Coordinates.h"

void MoveTo(COORD cell, COORD newCell, char direction); // Gère le deplacement sur l'UI(console) d'un pion, d'une case à l'autre.
void PushMove(Game siam,Coordinates cell,char direction, int nbrAnimal); // Gere le deplacement suite a un push de l'adversaire.
void Reorient(COORD cell, char newOrientation); // Change l'orientation d'un pion sur le terrrain de jeu.

#endif
