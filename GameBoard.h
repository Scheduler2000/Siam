#ifndef __GAME_BOARD__
#define __GAME_BOARD__


typedef struct GameBoard
{
    char Battleground[5][10];
    char ElephantTribut[5];
    char RhinocerosTribut[5];
} GameBoard;

void DrawGameBoard(); // Affiche le tableau de jeu sur la console.
void DrawGameInformation(); // Affiche les informations de jeu prope au joueur entrain de jouer.
static void DrawBattleground(); // Affiche l'interface graphique du tableau "Battleground".
static void DrawRhinocerosTribut(); // Affiche l'interface graphique du tableau "RhinocerosTribut".
static void DrawElephantTribut(); // Affiche l'interface graphique du tableau "ElephantTribut".

void InitializeGameBoard(GameBoard *gameBoard); // Remplit l'ensemble des tableaux de jeux.
static void InitializeBattleground(char battleground[5][10]); // Remplit le tableau "Battleground".
static void InitializeElephantTribut(char *elephantTribut); // Remplit le tableau "ElephantTribut".
static void InitializeRhinocerosTribut(char *rhinocerosTribut);// Remplit le tableau "RhinocerosTribut".

#endif
