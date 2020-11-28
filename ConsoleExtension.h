#ifndef __CONSOLE_EXTENSION__
#define __CONSOLE_EXTENSION__

void ClearConsole(); // Vide la console en entier.
void SetCursorPosition(int line, int column); // Modifie la position du curseur sur la console.
void SetConsoleTextColor(int foreground, int background); // Modifie la couleur présente sur la console.
void ClearConsoleLine(int line, int column); // Vide la ligne en console ayant pour coordonnées (line,column).
void ClearConsoleCharacters(int line, int column, int amountCharacteres); // Vide 'n' caractere sur la console a la pos (line, column).
void ClearConsoleLines(int line, int column, int iteration); // Vide les lignes en consoles de la premiere(pos = line,column) jusqua la premiere + iteration
int GetCursorPosition(char component); // Obtient les position (x ou y) actuelle sur la console .
void DisplayErrorMessage(int millisecondes, char * message); // Affiche un message d'erreur sur la console x millisecondes et l'efface.

/*
0 : Noir
1 : Bleu foncé
2 : Vert foncé
3 : Turquoise
4 : Rouge foncé
5 : Violet
6 : Vert caca d'oie
7 : Gris clair
8 : Gris foncé
9 : Bleu fluo
10 : Vert fluo
11 : Turquoise
12 : Rouge fluo
13 : Violet 2
14 : Jaune
15 : Blanc
*/

#endif

