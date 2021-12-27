#include "fonction.h"

int main(){

  int reponse = 0;

  printf("Que voulez faire, donnez le chiffre correspondant ? \n");
  printf("1-Recherche de la séquence codante la plus longue \n");
  printf("2-Transcription \n");
  printf("3-Traduction \n");
  printf("4-Cacule du score d'identité entre deux séquence \n");
  printf("5-Calcul du score de similarité de polarité entre deux séquences protéiques \n");
  printf("6-Recherche séquence consensus issue d’un résultat d’alignement multiple \n");
  printf("7-Recherche de la plus grande sous-chaîne de polarité commune à 2 séquences \n");
  scanf("%d", &reponse);
  printf("\n");

  if (reponse == 1){
    printf("Vous avez sélectionné : Rechercher la séquence codante la plus longue \n");

    printf("Malheureusement, ce service est encore indisponible \n");
  }
  else if (reponse == 2){
    printf("Vous avez sélectionné : Transcription \n");
    char path_input[100];

    printf("quel est le nom du fichier que vous voulez lire \n");
    scanf("%s", path_input); //nom du fichier test = test_fasta (fichier cours sans la première ligne)
    //on ne peut mettre que le nom du fichier et non tout le chemin
    printf("\n");

    transcription(path_input);
  }
  else if(reponse == 3){
    printf("Vous avez sélectionné : Traduction \n");
    char path_input[100];

    printf("quel est le nom du fichier que vous voulez lire \n");
    scanf("%s", path_input);
    printf("\n");

    traduction(path_input);
  }
  else if(reponse == 4){
    printf("Vous avez séletionné : Cacule du score d'identité entre deux séquence \n");
    char path_input_1[100];
    char path_input_2[100];
    printf("vous avez besoin de deux fichiers \n");
    printf("Quel est le nom du premier fichier \n");
    scanf("%s", path_input_1);
    printf("Quel est le nom du deuxième fichier \n");
    scanf("%s", path_input_2);

    identite(path_input_1,path_input_2);
  }
  else if(reponse == 5){
    printf("Vous avez séletionné : Calcul du score de similarité de polarité entre deux séquences protéiques \n");
    char path_input_1[100];
    char path_input_2[100];
    printf("Vous avez besoin de deux fichiers \n");
    printf("Quel est le nom du premier fichier \n");
    scanf("%s", path_input_1);
    printf("Quel est le nom du deuxième fichier \n");
    scanf("%s", path_input_2);

    simi_pola(path_input_1,path_input_2);
  }
  else if(reponse == 6){
    printf("Vous avez sélectionné : Recherche séquence consensus issue d’un résultat d’alignement multiple \n");
    printf("Malheureusement, ce service est encore indisponible \n");
  }
  else if(reponse ==7){
    printf("Vous avez séletionné : Recherche de la plus grande sous-chaîne de polarité commune à 2 séquences \n");
    printf("Malheureusement, ce service est encore indisponible \n");
  }
  else{
    printf("Vous n'avez sélectionné aucun service \n");
  }
  return 0;

}
