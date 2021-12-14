#include <stdio.h>
#include <string.h>


int main(){

  // Ici utiliser les procédures d'extraction de séquence

  // Exemple de séquence codante
  char sequence[]="ATGATTTTCCCTGAGCCAGGG";

  // Booléens de vérification
  char codant[] = "F";
  char taille[] = "F";

  int i=0;

  //CHECk du codon start
  if(sequence[0]=='A' && sequence[1]=='T' && sequence[2]=='G'){
    printf("La séquence contient bien un codon START \n");
    codant[0] = 'T';
  }
  else{
    printf("La séquence ne contient pas de codon START \n");
  }



  //CHECK de la taille de la séquence
  int taille_sequence=strlen(sequence);

  if(taille_sequence%3==0){
    printf("La taille de la séquence est bonne \n");
    taille[0] = 'T';
  }
  else{
    printf("La taille de la séquence n'est pas bonne \n");
    taille[0] = 'F';
  }

  //si les conditions sont remplis on fait la transcription
  if(codant[0]=='T' && taille[0]=='T'){
    for (i=0;i<taille_sequence;i++){
      if (sequence[i]=='T'){
        sequence[i]='A';
      }else if (sequence[i]=='A'){
        sequence[i]='U';
      }else if (sequence[i]=='G'){
        sequence[i]='C';
      }
      else{
        sequence[i]='G';
      }
    }

  printf("%s\n", sequence);
  }
  else{
    printf("Redonnez une séquence correcte \n");
  }

  return 0;
}
