#include "GameMenu.h"
#include "ConsoleExtension.h"
#include "GameHandler.h"
#include "PartyHandler.h"

void OpenGameMenu(Game siam)
{
    char choice = ' ';
    int i = 0;
    ClearConsole();
    SetCursorPosition(10,1);
    SetConsoleTextColor(1,0);
    printf("   _____ _  ");
    SetCursorPosition(10,2);
    printf("  / ___/(_)___ _____ ___ ");
    SetConsoleTextColor(15,0);
    SetCursorPosition(10,3);
    printf("  \\__ \\/ / __ `/ __ `__ \\");
    SetCursorPosition(10,4);
    printf(" ___/ / / /_/ / / / / / / ");
    SetConsoleTextColor(4,0);
    SetCursorPosition(10,5);
    printf("/____/_/\\____/_/ /_/ /_/\n\n");

    for (i = 0; i < 5; i++) // Affichage du menu sur la console
    {
        SetConsoleTextColor(i + 2, 0);
        switch (i + 1)
        {
        case 1:
            printf("\t %d . Nouvelle partie en mode multijoueur.\n", i + 1);
            break;
        case 2:
            printf("\t %d . Nouvelle partie contre l'ordinateur.\n", i + 1);
            break;
        case 3:
            printf("\t %d . Charger la derniere partie de jeu.\n", i + 1);
            break;
        case 4:
            printf("\t %d . Afficher les regles et commandes de Siam.\n", i + 1);
            break;
        case 5:
            printf("\t %d . Quitter le jeu.\n", i + 1);
            break;
        }
    }
    do // Blindage et demande du menu souhaité
    {
        SetConsoleTextColor(15,0);
        choice = getchar();
        switch(choice)
        {
        case '1':
            InitializePartyMultiplayer(&siam);
            break;
        case '2':
            InitializePartyIA(&siam);
            break;
        case '3':
            break;
        case '4':
            system("start http://jeuxstrategieter.free.fr/Siam_complet.php");
            printf("Alors, quel est donc votre choix ?\n");
            break;
        case '5':
            exit(0);
            break;
        case '\n':
            choice =0;
            break;
        default:
            SetConsoleTextColor(4,0);
            printf("[Erreur] : Numero de menu incorrect ...\n");
            choice = 0;
            break;
        }
    }
    while(choice == 0 || choice == '4');
}
