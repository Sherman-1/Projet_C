#include "utils.h"
#include "module_simi_pola.h"

/* Le module simi pola a pour but de caculer le score de similarité de polarité
entre deux séquences protéiques. Pour cela, l'utilisateur founit deux fichiers
de même taille comteant des acides aminés. Le module compare les séquences entre
elle et définit une séquence polarité.*/

void simi_pola(){

  //l'utilsateur a choisit le module simi pola
  printf("Vous avez séletionné : Calcul du score de similarité de polarité entre deux séquences protéiques \n");

  //on demande le chemin des fichiers qu'il veut comparer
  char path_input_1[100];
  char path_input_2[100];

  printf("Vous avez besoin de deux fichiers \n");
  printf("Le premier : \n");

  //un premier appel pour le premier fichier
  get_path_user(path_input_1);

  printf("Le deuxième : \n");

  //un deuxième appel pour le deuxième fichier
  get_path_user(path_input_2);


  //on détermine la taille des fichiers donnés
  int taille_sequence_1=0;
  taille(path_input_1, &taille_sequence_1);

  int taille_sequence_2=0;
  taille(path_input_2, &taille_sequence_2);


  //on extrait les séquences des fichiers donnés
  char sequence1[taille_sequence_1];
  char sequence2[taille_sequence_2];

  extract_sequence(path_input_1, sequence1);
  sequence1[taille_sequence_1]='\0';
  extract_sequence(path_input_2, sequence2);
  sequence2[taille_sequence_2]='\0';

  printf("\n");


  /* On compare la taille des deux fichiers, si ces derniers étaient différents
  la comparaison ne serait pas réalisée*/


  if (taille_sequence_1 != taille_sequence_2-1){
     /* -1 car la deuxième séquence a été faite
    / à la main et est donc différente de la taille de la séquence 1*/

    printf("Vos séquences n'ont pas la même taille recommencez \n");
    printf("taille sequence 1 : %d \n", taille_sequence_1);
    printf("taille sequence 2 : %d \n", taille_sequence_2);

  }
  else{

    //si la taille des deux séquences est identique on demarre la comparaison
    int taille_sequence_pola = taille_sequence_1;
    int i=0;
    int caract_1 =0;
    int caract_2 =0;

    char seq_polarite[taille_sequence_pola];

    /* En fonction des AA comparés, le caract va prendre une valeur en fonction des deux séquences
        si la valeur de caract est identique pour les deux séquences
          ==> 1 sera affiché si c'est des AA hydrophobes
          ==> 0 sera affiché si c'est des AA hydrophiles
        si la valeur de caract est différent ==> - sera affiché */


    for (i=0;i<=taille_sequence_pola-1;i++){

      if (sequence1[i] == 'F' ||sequence1[i] == 'A' ||sequence1[i] == 'L' ||sequence1[i] == 'I' ||sequence1[i] == 'M' ||sequence1[i] == 'W' ||sequence1[i] == 'P' ||sequence1[i] == 'G' ||sequence1[i] == 'V'){
        caract_1 = caract_1 +10;
      }
      else if (sequence1[i] == 'C' ||sequence1[i] == 'Y' ||sequence1[i] == 'T' ||sequence1[i] == 'S' ||sequence1[i] == 'N' ||sequence1[i] == 'Q' ||sequence1[i] == 'H' ||sequence1[i] == 'K' ||sequence1[i] == 'R'||sequence1[i] == 'D'||sequence1[i] == 'E'){
        caract_1 = caract_1 -10;
      }
      else{
        caract_1 = 0;
      }


      if (sequence2[i] == 'F' ||sequence2[i] == 'A' ||sequence2[i] == 'L' ||sequence2[i] == 'I' ||sequence2[i] == 'M' ||sequence2[i] == 'W' ||sequence2[i] == 'P' ||sequence2[i] == 'G' ||sequence2[i] == 'V'){
        caract_2 = caract_2 +10;
      }
      else if (sequence2[i] == 'C' ||sequence2[i] == 'Y' ||sequence2[i] == 'T' ||sequence2[i] == 'S' ||sequence2[i] == 'N' ||sequence2[i] == 'Q' ||sequence2[i] == 'H' ||sequence2[i] == 'K' ||sequence2[i] == 'R'||sequence2[i] == 'D'||sequence2[i] == 'E'){
        caract_2 = caract_2 -10;
      }
      else{
        caract_2 = 0;
      }


      if(caract_1 == 10 && caract_2 == 10){
        seq_polarite[i]='1';
      }
      else if (caract_1 == -10 && caract_2 == -10){
        seq_polarite[i]= '0';
      }
      else{
        seq_polarite[i] = '-';
      }
      if(i == taille_sequence_1){
        seq_polarite[i] = '\0';
      }
      caract_1 = 0;
      caract_2 = 0;
    }
    seq_polarite[taille_sequence_pola]='\0';

    //Affichage de la séquence de polarité
    printf("0: hydrophiles, 1:hydrophobes, -:différents \n\n");
    printf("%s \n", sequence1);
    printf("%s \n", sequence2);
    printf("%s \n", seq_polarite);
  }
}
