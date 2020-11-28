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

int DirectionsAreOpposed(Direction animal, Direction Enemy); // D�termine si deux directions sont oppos�e.
Direction GetDirectionOpposed(Direction animal); // Obtient la diretcion oppos�e.
int IsOutsideCell(Coordinates coord); // D�termine si la case s�lectionn�e est une case exterieure ou non .
int IsFreeCell(Game siam, Coordinates coord); // D�termine si la case s�lectionn�e est vide ou non.
int BattlegroundIsEmpty(Game siam, char animal); // D�termine si le champs de bataille est vide .
int CellsTributsAreEmpty(char *tribut); // D�termine si la tribut �l�phant ou rhinoceros est vide.
int IsMountainCell(Game siam, Coordinates coord); // D�termine si la case s�lectionn�e est celle d'une montagne ou non.
Coordinates GetAdjacentCell(Game siam, Coordinates cell, Direction orientation); // Obtient la case adjacente a la case pass�e en parametre selon l'orientation.
void GetAdjacentCells(Game siam,Coordinates cell,Direction orientation, char dest[5][2]); // Obtient les cellules adjacente a la case pass�e en param.
char *GetBattlegroundCell(Game *siam, Coordinates coord); // Obtient la case d'un champs de bataille de coordonn�es coord.
COORD GetCellConsolePosition(char line, int column); // Obtient la position sur la console de la case rentr�e en param�tre
COORD GetTributCellPosition(char animal, int cell); // Obtient la position (x,y) sur la console d'une case d'une tribut E ou R

#endif
