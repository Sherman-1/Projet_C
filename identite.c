#include <stdio.h>
#include <string.h>

//il nous reste a integrer la procédure d'appels de fichier
//et de séquence et de mettre tout sous un while pour redemander
//à l'utilisateur si les fichiers ne sont pas bon.

int main(){

  //séquence codante demandé a l'utilisateur à remplacer par les procédure d'appel de séquence
  char sequence1[]="ATGATACATCCCAAGTGAGAACTGCCCCATAAATCCAGAAAACCACATTGCTATCTTAAGTCCCTAAGTTTGGGGCTTATTTGTTCCACAGCAACAGGTAACTGGAACAGAGGGCAAGCCTG";
  char sequence2[]="ATGCATTCCGATCCTCATCACAATTCTTTGACTGAAGGCCGGGCGTGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCTGAGGCGGGTGGATCACCTGAGGTCAGGAGTTCGAGACC";

  //on cherche la taille des séquences qu'on va comparer et non elles doivent être de la même taille
  int taille_sequence1=strlen(sequence1);
  int taille_sequence2=strlen(sequence2);

  char taille[] = "T";

  if (taille_sequence1 != taille_sequence2){
    taille[0] = 'F';
  }
  else{
    taille[0] = 'T';
  }

  if(taille[0] == 'T'){
    int taille_sequence_identite = 0;
    taille_sequence_identite = taille_sequence1;


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

  // on sort le pourcentage d'indentité des deux séquences + les deux séquences qu'on compare + la séquence identité
  identite = (compteur_identite/taille_sequence_identite)*100;
  printf("%f \n", identite);
  printf("Identité de séquence : %lf/%d, soit %lf pourcent \n\n",compteur_identite,taille_sequence_identite, identite);
  printf("seq1 %s \n\n", sequence1);
  printf("seq2 %s \n\n", sequence2);
  printf("-id- %s \n", sequence_identite);
}
else{
  printf("Les tailles de vos séquences sont différentes, recommencez \n");
  //à mettre sous un while pour qu'il redemande la condition si elle n'est pas remplis
}

  return 0;

}
