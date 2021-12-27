#include "utils.h"
#include "module_identite.h"

void identite(){

  printf("Vous avez séletionné : Cacule du score d'identité entre deux séquence \n");
  char path_input_1[100];
  char path_input_2[100];
  printf("vous avez besoin de deux fichiers \n");
  printf("Quel est le nom du premier fichier \n");
  scanf("%s", path_input_1);
  printf("Quel est le nom du deuxième fichier \n");
  scanf("%s", path_input_2);

  //on cherche la taille des séquences qu'on va comparer et non elles doivent être de la même taille
  int taille_sequence_1=0;
  taille(path_input_1, &taille_sequence_1);

  int taille_sequence_2=0;
  taille(path_input_2, &taille_sequence_2);

  char sequence1[taille_sequence_1];
  char sequence2[taille_sequence_2];

  extract_sequence(path_input_1, sequence1, taille_sequence_1);
  extract_sequence(path_input_2, sequence2, taille_sequence_2);

  bool taille = false;

  if (taille_sequence_1 != taille_sequence_2){
    taille = false;
  }
  else{
    taille = true;
  }

  if(taille == true){
    int taille_sequence_identite = 0;
    taille_sequence_identite = taille_sequence_1;


  //on initialise la sequence identité
  char sequence_identite[taille_sequence_identite];

  //initialisation des éléments pour la création de la séquence identité
  int i=0,compteur=0;
  double identite=0, compteur_identite =0;
  //ici, on complète la séquence identité en fonction des deux séquences
  do{
    if (sequence1[i]==sequence2[i]){

      sequence_identite[i] = sequence1[i];
      compteur_identite++;
    }
    else{
      sequence_identite[i] = '-';
    }
    i++;
    compteur++;
  }
  while (compteur != taille_sequence_identite);

  sequence1[taille_sequence_1]='\0';
  sequence2[taille_sequence_2]='\0';

  // on sort le pourcentage d'indentité des deux séquences + les deux séquences qu'on compare + la séquence identité
  identite = (compteur_identite/taille_sequence_identite)*100;
  printf("\n");
  printf("Identité de séquence : %lf/%d, soit %lf pourcent \n\n",compteur_identite,taille_sequence_identite, identite);
  printf("seq1 %s \n\n", sequence1);
  printf("seq2 %s \n\n", sequence2);
  printf("-id- %s \n", sequence_identite);
  }
  else{
    printf("Les tailles de vos séquences sont différentes, recommencez \n");
  //à mettre sous un while pour qu'il redemande la condition si elle n'est pas remplis
  }
}
