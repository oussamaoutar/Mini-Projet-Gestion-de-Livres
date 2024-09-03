#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500

int count = 0;
char titres[MAX][40];
char auteurs[MAX][40];
float prix[MAX];
int quantites[MAX];

void ajouterLivreMenu();
void afficherAllLivres();
void searchLivreParTitreMenu();
void MAJQteLivreMenu();
void supprimerLivreMenu();
void menuPrincipal();
void afficherTotalLivresEnStock();

void ajouterLivreMenu() {
    printf("Saisir le titre du livre : ");
    scanf(" %[^\n]s", &titres[count]);
    printf("Saisir l'auteur du livre : ");
    scanf(" %[^\n]s", &auteurs[count]);
    printf("Saisir le prix du livre : ");
    scanf("%f", &prix[count]);
    printf("Saisir le quantite du livre : ");
    scanf("%d", &quantites[count]);
    count++;

    printf("Livre ajouté avec succès\n");
    menuPrincipal();
}

void menuPrincipal() {
    int choix;

    printf("******************* Système de Gestion de Stock *******************\n");
    printf("Choisissez un chiffre :\n");
    printf("1. Ajouter un livre au stock.\n");
    printf("2. Afficher tous les livres disponibles.\n");
    printf("3. Rechercher un livre par son titre. \n");
    printf("4. Mettre à jour la quantité d'un livre. \n");
    printf("5. Supprimer un livre du stock. \n");
    printf("6. Afficher le nombre total de livres en stock. \n");
    printf("7. Quitter\n");
    scanf("%d", &choix);
    switch(choix) {
        case 1 : ajouterLivreMenu(); break;
        case 2 : afficherAllLivres(); break;
        case 3 : searchLivreParTitreMenu(); break;
        case 4 : MAJQteLivreMenu(); break;
        case 5 : supprimerLivreMenu(); break;
        case 6 : afficherTotalLivresEnStock(); break;
        case 7 : exit;
    }
}

void afficherAllLivres() {
    int i, choix;

    printf("# | Titre | Auteur | Prix | Quantité\n");
    for(i=0; i<count; i++) {
        printf("%d |  %s |  %s | %f | %d \n", count, titres[i], auteurs[i], prix[i], quantites[i]);
    }
    printf("1. Revenir au Menu Principal.\n2. Quitter");
    scanf("%d", &choix);
    if(choix == 1) menuPrincipal();
    else exit;
}

void searchLivreParTitreMenu() {
    char titre[200];
    int indiceLivreTrouve, choix;
    printf("Donner le titre du livre : ");
    scanf(" %[^\n]s", titre);
    for(int i=0; i<count; i++) {
        if(strcmp(titres[i], titre) == 0) {
            indiceLivreTrouve = i;
            break;
        } else {
            printf("Livre Non Trouvé !");
        }
    }
    printf("%d |  %s |  %s | %f | %d \n", count, titres[indiceLivreTrouve], auteurs[indiceLivreTrouve], prix[indiceLivreTrouve], quantites[indiceLivreTrouve]);
    printf("Voulez-vous chercher un autre livre ? Tapper 1.\nTapper 2 Pour Revenir au Menu Principal\nAutre Pour Quitter.");
    scanf("%d", &choix);
    switch(choix) {
        case 1 : searchLivreParTitreMenu(); break;
        case 2 : menuPrincipal(); break;
        default : exit; break;
    }
}

void MAJQteLivreMenu() {
    char titre[200];
    int indiceLivre, choix, nvQte;
    printf("Donner le titre du livre : ");
    scanf(" %[^\n]s", titre);
    for(int i=0; i<count; i++) {
        if(strcmp(titres[i], titre) == 0) {
            printf("Donner la nouvelle quantité : ");
            scanf("%d", &nvQte);
            quantites[i] = nvQte;
            printf("Quantité modifiée");
            break;
        } else {
            printf("Livre non trouvé !");
        }
    }
    printf("Voulez-vous modifier la quantité d'un autre livre ? Tapper 1.\nTapper 2 Pour Revenir au Menu Principal\nAutre Pour Quitter.");
    scanf("%d", &choix);
    switch(choix) {
        case 1 : MAJQteLivreMenu(); break;
        case 2 : menuPrincipal(); break;
        default : exit; break;
    }
}

void supprimerLivreMenu() {
    char titre[200];
    int indiceLivre, choix;
    printf("Donner le titre du livre que vous voulez supprimer : ");
    scanf(" %[^\n]s", titre);
    for(int i=0; i<count; i++) {
        if(strcmp(titres[i], titre) == 0) {
            indiceLivre = i;
            for(int j=indiceLivre; j<count; j++) {
                titres[j][40] = titres[j+1];
                auteurs[j][40] = auteurs[j+1];
                prix[j] = prix[j+1];
                quantites[j] = quantites[j+1];
                count--;
            }
            printf("Livre Supprimé !");
            break;
        } else {
            printf("Livre non trouvé !");
        }
    }
    printf("\n1. Revenir au Menu Principal.\n2. Quitter");
    scanf("%d", &choix);
    if(choix == 1) menuPrincipal();
    else exit;

}

void afficherTotalLivresEnStock() {
    int countEnStock = 0, choix;
    for(int i=0; i<count; i++) {
        if(quantites[i]>0) countEnStock++;
    }
    printf("La somme des livres en stock est : %d", countEnStock);
    printf("\n1. Revenir au Menu Principal.\n2. Quitter");
    scanf("%d", &choix);
    if(choix == 1) menuPrincipal();
    else exit;
}
    
int main() {
    menuPrincipal();

    return 0;
}