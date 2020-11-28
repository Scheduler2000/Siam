#include "PartyHandler.h"
#include "GameBoard.h"
#include "GameHandler.h"
#include "Player.h"

void InitializePartyIA(Game *siam)
{
    DefinePlayer(&(siam->elephant));
    DefineIA(&(siam->rhinoceros));
    siam->round = 2; // Le premier tour commence a 2 pour pouvoir mainier aisément l'operateur %
    siam->fightType = PlayerVsIA;
    DrawGameBoard(*siam);
    PlayGame(siam);
}

void InitializePartyMultiplayer(Game *siam)
{
    DefinePlayer(&(siam->elephant));
    DefinePlayer(&(siam->rhinoceros));
    siam->round = 2; // Le premier tour commence a 2 pour pouvoir mainier aisément l'operateur %
    siam->fightType = PlayerVsPlayer;
    DrawGameBoard(*siam);
    PlayGame(siam);
}

void LoadParty(char backupName)
{


}
