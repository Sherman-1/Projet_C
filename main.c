#include "fonction.h"

int main(){

  int reponse = 0;
  char path_input[100];
  printf("Que voulez faire, donnez le chiffre correspondant ? (1-Transcription, 2-Traduction, 3-identite, 4-similarité polarité) \n");
  scanf("%d", &reponse);
  printf("\n");

  if (reponse == 1){
    printf("Vous allez faire une Transcription \n");

    printf("quel est le nom du fichier que vous voulez lire \n");
    scanf("%s", path_input); //nom du fichier test = test_fasta (fichier cours sans la première ligne)
    //on ne peut mettre que le nom du fichier et non tout le chemin
    printf("\n");

    transcription(path_input);
  }
  return 0;

}
