#include "fonction.h"

void taille(const char* path_input, int* taille_fasta) {

    FILE* openfile= fopen(path_input, "r");

    while(fgetc(openfile) != EOF)
      (*taille_fasta) ++;

    fclose(openfile);
}


void extract_sequence(const char* path_input, char* sequence,int taille_fasta) {

  int i=0;

  FILE* fichier = fopen(path_input,"r");

  while (! feof(fichier)) {
      int currentChar = fgetc(fichier);
      sequence[i] = currentChar;
      i++;
  }
  fclose(fichier);
  //printf("%s\n",sequence);
  //on compte les retours à la ligne alors qu'il faudrait pas

}


void transcription(const char* path_input){

  int taille_fasta = 0;
  taille(path_input, &taille_fasta);

  //printf("%d \n", taille_fasta);
  char sequence[taille_fasta];

  extract_sequence(path_input, sequence, taille_fasta);


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
    printf("La séquence ne commence pas par un codon START \n");
  }


  FILE* op= fopen("séquence_transcrite.txt","w");

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

  int compteur = 0;
  //si les conditions sont remplis on fait la transcription
  if(codant[0]=='T' && taille[0]=='T'){
    for (i=0;i<taille_sequence;i++){
      if (sequence[i]=='T'){
        fprintf(op,"A");
        compteur ++;
      }
      else if (sequence[i]=='A'){
        fprintf(op,"U");
        compteur ++;
      }
      else if (sequence[i]=='G'){
        fprintf(op,"C");
        compteur ++;
      }
      else if (sequence[i]=='C'){
        fprintf(op,"G");
        compteur ++;
      }
      else{
        compteur ++;
      }

      if (compteur == 80){
        fprintf(op,"\n");
        compteur = 0;
      }
    }
  }
  else{
    printf("Redonnez une séquence correcte \n");
  }

}
