#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char dict[][4][50] = {
    {"air", "rue", "sage", "ciel"},
    {"maison", "cuisine", "voiture", "fenetre"},
    {"supermarche", "ingenieur", "ascenseur", "automobile"}
};

void drawHangman(int);
void playHangmanWithDifficulty(int);
void playHangman();
void rulesOfTheGame();

void rulesOfTheGame() {
    printf("Les règles sont assez simples chers joueurs : \n");
    printf("\n1. Vous devez donner le niveau de difficulté désiré.");
    printf("\n2. Vous devez deviner le mot en suivant les tirets.");
    printf("\n3. Commencez par les voyelles.");
    printf("\n");
}

void drawHangman(int tentatives) {
    switch (tentatives) {
        case 6:
            printf("\n");
            printf("  ______\n");
            printf("  |/   |\n");
            printf("  |    \n");
            printf("  |    \n");
            printf("  |    \n");
            printf("  |    \n");
            printf("  |______    \n");
            break;
        case 5:
            printf("\n");
            printf("  ______\n");
            printf("  |/   |\n");
            printf("  |    |\n");
            printf("  |    O\n");
            printf("  |    \n");
            printf("  |    \n");
            printf("  |______    \n");
            break;
        case 4:
            printf("\n");
            printf("  ______\n");
            printf("  |/   |\n");
            printf("  |    |\n");
            printf("  |    O\n");
            printf("  |   / \n");
            printf("  |    \n");
            printf("  |______\n");
            break;
        case 3:
            printf("\n");
            printf("  ______\n");
            printf("  |/   |\n");
            printf("  |    |\n");
            printf("  |    O\n");
            printf("  |   /|\\ \n");
            printf("  |    \n");
            printf("  |______\n");
            break;
        case 2:
            printf("\n");
            printf("  ______\n");
            printf("  |/   |\n");
            printf("  |    |\n");
            printf("  |    O\n");
            printf("  |   /|\\ \n");
            printf("  |    |\n");
            printf("  |______    \n");
            break;
        case 1:
            printf("\n");
            printf("  ______\n");
            printf("  |/   |\n");
            printf("  |    |\n");
            printf("  |    O\n");
            printf("  |   /|\\ \n");
            printf("  |   /|\n");
            printf("  |______    \n");
            break;
        case 0:
            printf("\n");
            printf("  ______\n");
            printf("  |/   |\n");
            printf("  |    |\n");
            printf("  |    O\n");
            printf("  |   /|\\ \n");
            printf("  |   /|\\ \n");
            printf("  |______    \n");
            break;
        default:
            break;
    }
}

void playHangman() {
    int difficulte;
    printf ("\n\n");
    do {
        printf("Donnez le niveau de difficulté entre 1 et 3 : ");
        scanf("%d", &difficulte);
        printf("\n");
    } while (difficulte < 1 || difficulte > 3);
    playHangmanWithDifficulty(difficulte);
}

void playHangmanWithDifficulty(int difficulte) {
    int index = rand() % 4;

    char motADeviner[50];
    strcpy(motADeviner, dict[difficulte - 1][index]);

    int taille = strlen(motADeviner);

    int indexes[taille];

    int i;
    for (i = 0; i < taille; i++) {
        indexes[i] = 0;
    }

    int nbrCaracteresTrouves = 0;

    int tentatives = 7;

    char charSaisi;
    printf("\n");
    printf("\n");
    printf("Le mot à deviner contient %d lettres.\n", taille);

    for (i = 0; i < taille; i++) {
        printf("_ ");
    }

    printf("\n\n");

    while (tentatives > 0 && nbrCaracteresTrouves < taille) {
        printf("Veuillez entrer un caractère : ");
        scanf(" %c", &charSaisi);

        int charTrouve = 0;
        for (i = 0; i < taille; i++) {
            if (motADeviner[i] == charSaisi) {
                indexes[i] = 1;
                charTrouve = 1;
                nbrCaracteresTrouves++;
            }
        }

        if (charTrouve == 1) {
            printf("Bravo, %c existe.\n", charSaisi);
        } else {
            printf("Malheureusement, %c n'existe pas. Réessayez.\n", charSaisi);
            tentatives--;
            drawHangman(tentatives);
        }

        printf("\n");

        for (i = 0; i < taille; i++) {
            if (indexes[i] == 1) {
                printf(" %c ", motADeviner[i]);
            } else {
                printf("_ ");
            }
        }

        printf("\n");

        printf("Il vous reste %d tentatives.\n", tentatives);
        printf("\n");
    }

    if (nbrCaracteresTrouves == taille) {
        printf("Vous avez gagné !\n");
    } else {
        printf("Vous avez perdu ! Le mot à deviner était : %s\n", motADeviner);
    }

    int reponse;

    do {
        printf("Voulez-vous rejouer ? Si oui, tapez 1, sinon tapez 0\n");
        scanf("%d", &reponse);
    } while (reponse != 1 && reponse != 0);

    if (reponse == 1) {
        playHangman();
    } else {
        return;
    }
}

int main() {
    srand(time(NULL));
    rulesOfTheGame();
    playHangman();
    return 0;
}


