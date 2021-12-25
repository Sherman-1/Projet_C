#include "fonction.h"

int main(){

  int reponse = 0;
  char path_input[100];
  printf("Que voulez faire, donnez le chiffre correspondant ? \n");
  printf("1-Recherche de la séquence codante la plus longue \n");
  printf("2-Transcription \n");
  printf("3-Traduction \n");
  printf("4-Cacule du score d'identité entre deux séquence \n");
  printf("5-Calcul du score de similarité de polarité entre deux séquences protéiques \n");
  scanf("%d", &reponse);
  printf("\n");

  if (reponse == 1){
    printf("Vous avez sélectionné : Rechercher la séquence codante la plus longue \n");
    printf("Malheureusement, ce service est encore indisponible");
  }
  else if (reponse == 2){
    printf("Vous aavez sélectionné : Transcription \n");

    printf("quel est le nom du fichier que vous voulez lire \n");
    scanf("%s", path_input); //nom du fichier test = test_fasta (fichier cours sans la première ligne)
    //on ne peut mettre que le nom du fichier et non tout le chemin
    printf("\n");

    transcription(path_input);
  }
  else if(reponse == 3){
    printf("Vous avez sélectionné : Traduction \n");

    printf("quel est le nom du fichier que vous voulez lire \n");
    scanf("%s", path_input);
    printf("\n");

    traduction(path_input);
  }

  return 0;

}
