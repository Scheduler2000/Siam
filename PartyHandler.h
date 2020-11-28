#ifndef __PARTY_HANDLER__
#define __PARTY_HANDLER__
#include "GameBoard.h"
#include "GameHandler.h"

void InitializePartyMultiplayer(Game *siam); // Initialise et lance une nouvelle partie pvp.
void InitializePartyIA(Game *siam); // Initialise et lance une nouvelle partie contre l'IA.
void LoadParty(char backupName); // Charge une sauvegarde du nom de "backupName".
#endif
