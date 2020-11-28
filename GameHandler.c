#include "GameHandler.h"
#include "GameBoard.h"
#include "FightManager.h"

void PlayGame(Game *siam)
{
    int rnd = 0;
    InitializeGameBoard(&(siam->gameBoard));
    DrawGameInformation(*siam);
    switch(siam->fightType)
    {
    case PlayerVsPlayer:
        do
        {
            rnd = OpenFightMenu(siam);
            if(rnd == 1)
                NextRound(siam);
        }while(GameOver(*siam));
        break;
    case PlayerVsIA:
        break;
    }
}
void NextRound(Game *siam)
{
    siam->round++;
    DrawGameInformation(*siam);
}

int GameOver(Game siam)
{
    int result = 0;
    if(siam.gameBoard.Battleground[0][0] ='W')
        result = 1;
    return result;
}
