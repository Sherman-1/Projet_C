#include "utils.h"
#include "module_identite.h"
#include "module_transcription.h"
#include "module_traduction.h"
#include "module_simi_pola.h"
#include "module_ORF.h"

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

    orf();
  }
  else if (reponse == 2){

    transcription();
  }
  else if(reponse == 3){

    traduction();
  }
  else if(reponse == 4){
    identite();
  }
  else if(reponse == 5){
    simi_pola();
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
