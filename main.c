#include "train.h"

int main()
{

//intialisation de la liste:
liste list=NULL;
Wagon wag;
int choix,num,trouv;
char nomf[15]="train.txt";
//Menu
do{
        do{
            printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("Taper:  \n");
            printf("1-->Ajouter une locomotive en tête du train\n");
            printf("2-->Ajouter un wagon à la queue du train\n");
            printf("3-->Rechercher un wagon donné par son numéro\n");
            printf("4-->Afficher le train\n");
            printf("5-->supprimer les  wagons dont l’état est en panne\n");
            printf("6-->Ajouter un wagon après le numéro du wagon\n");
            printf("7-->Enregistrer un historique \n");
         printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\n ** Donner votre choix ** :\n");
            scanf("%d",&choix);
        }while(choix<0||choix>7);
switch(choix){

case 1://ajouter locom
    saisirWagon(list,&wag);
    if(strcmp(wag.type,"locomotive")==0)
        list=ajout_locom(list,wag);
    else printf("\nImpossible d'ajouter! C'est un wagon");
    // Sauveagrde dans un fichier
    Enregistrer_hist(list,nomf);
    break;
case 2://ajouter wag
    saisirWagon(list,&wag);
    if(strcmp(wag.type,"wagon")==0)
        list=ajout_wagon(list,wag);
    else printf("\nImpossible d'ajouter! C'est une locomtive");
    // Sauveagrde dans un fichier
    Enregistrer_hist(list,nomf);
    break;
case 3: printf("\n Donner le num de wagon à chercher: ");
    scanf("%d",&num);
    trouv=chercher_wagon(list,num);
    break;
case 4: afficher_train(list);
    break;
case 5:list=supprim_wagons(list);
    // Sauveagrde dans un fichier
    Enregistrer_hist(list,nomf);
    break;
case 6: printf("\nDonner le num du wagon");
    scanf("%d",&num);
    //verifier existence du num
    if(chercher_wagon(list,num)!=-1){
     // Saisie du nouveau wagon
     saisirWagon(list,&wag);
            //verifier type de wagon
        list=ajout_suivant(list,num,wag);
    }
    // Sauveagrde dans un fichier
    Enregistrer_hist(list,nomf);
    break;
/*case 7:// Sauveagrde dans un fichier
    Enregistrer_hist(list);
    break;*/

}
}while(choix!=0);

return 0;
}
