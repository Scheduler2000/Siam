#ifndef __COORDINATES__
#define __COORDINATES__
#include "GameHandler.h"
#include <windows.h>

typedef struct Coordinates
{
    int column;
    int line;
}Coordinates;
typedef enum Direction
{
    Top = 'h',
    Down = 'b',
    Right = 'd',
    Left = 'g'
}Direction;

int DirectionsAreOpposed(Direction animal, Direction Enemy); // Détermine si deux directions sont opposée.
Direction GetDirectionOpposed(Direction animal); // Obtient la diretcion opposée.
int IsOutsideCell(Coordinates coord); // Détermine si la case sélectionnée est une case exterieure ou non .
int IsFreeCell(Game siam, Coordinates coord); // Détermine si la case sélectionnée est vide ou non.
int BattlegroundIsEmpty(Game siam, char animal); // Détermine si le champs de bataille est vide .
int CellsTributsAreEmpty(char *tribut); // Détermine si la tribut éléphant ou rhinoceros est vide.
int IsMountainCell(Game siam, Coordinates coord); // Détermine si la case sélectionnée est celle d'une montagne ou non.
Coordinates GetAdjacentCell(Game siam, Coordinates cell, Direction orientation); // Obtient la case adjacente a la case passée en parametre selon l'orientation.
void GetAdjacentCells(Game siam,Coordinates cell,Direction orientation, char dest[5][2]); // Obtient les cellules adjacente a la case passée en param.
char *GetBattlegroundCell(Game *siam, Coordinates coord); // Obtient la case d'un champs de bataille de coordonnées coord.
COORD GetCellConsolePosition(char line, int column); // Obtient la position sur la console de la case rentrée en paramètre
COORD GetTributCellPosition(char animal, int cell); // Obtient la position (x,y) sur la console d'une case d'une tribut E ou R

#endif
