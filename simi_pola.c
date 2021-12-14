#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int caract = 0;

int main(){

  char seq1[] = "LCLLGPSDPPTSQVSTGMCHHPSLNLP";
  char seq2[] = "MLLLEPRGSPTADETQGLHKAASLRAP";

  int taille_seq1 = strlen(seq1);
  int taille_seq2 = strlen(seq2);

  if (taille_seq1 != taille_seq2){
    printf("Vos séquences n'ont pas la même taille recommencez");

    //rappeler les void
  }
  else{

    int taille_sequence = strlen(seq1);
    int i=0;

    char seq_polarite[taille_sequence];

    for (i=0;i<=taille_sequence;i++){

      if (seq1[i] == 'F' ||seq1[i] == 'A' ||seq1[i] == 'L' ||seq1[i] == 'I' ||seq1[i] == 'M' ||seq1[i] == 'W' ||seq1[i] == 'P' ||seq1[i] == 'G' ||seq1[i] == 'V'){
        caract = caract +1;
      }
      else if (seq1[i] == 'C' ||seq1[i] == 'Y' ||seq1[i] == 'T' ||seq1[i] == 'S' ||seq1[i] == 'N' ||seq1[i] == 'Q' ||seq1[i] == 'H' ||seq1[i] == 'K' ||seq1[i] == 'R'||seq1[i] == 'D'||seq1[i] == 'E'){
        caract = caract -1;
      }
      else{
        caract = 0;
      }
      if (seq2[i] == 'F' ||seq1[i] == 'A' ||seq1[i] == 'L' ||seq1[i] == 'I' ||seq1[i] == 'M' ||seq1[i] == 'W' ||seq1[i] == 'P' ||seq1[i] == 'G' ||seq1[i] == 'V'){
        caract = caract +1;
      }
      else if (seq2[i] == 'C' ||seq1[i] == 'Y' ||seq1[i] == 'T' ||seq1[i] == 'S' ||seq1[i] == 'N' ||seq1[i] == 'Q' ||seq1[i] == 'H' ||seq1[i] == 'K' ||seq1[i] == 'R'||seq1[i] == 'D'||seq1[i] == 'E'){
        caract = caract -1;
      }
      else{
        caract = 0;
      }

      if(caract == -2){
        seq_polarite[i]='-';
      }
      else if (caract == 2){
        seq_polarite[i]= '1';
      }
      else{
        seq_polarite[i] = '0';
      }
      if(i == taille_sequence){
        seq_polarite[i] = '\0';
      }
    }
    printf("0: hydrophiles, 1:hydrophobes, -:différents \n");
    printf("%s \n", seq1);
    printf("%s \n", seq2);
    printf("%s \n", seq_polarite);
  }
  return 0;
}
