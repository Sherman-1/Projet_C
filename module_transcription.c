#include "utils.h"
#include "module_transcription.h"

void transcription(){

  printf("Vous avez sélectionné : Transcription \n");
  char path_input[100];

  printf("quel est le nom du fichier que vous voulez lire \n");
  scanf("%s", path_input); //nom du fichier test = test_fasta (fichier cours sans la première ligne)
  //on ne peut mettre que le nom du fichier et non tout le chemin
  printf("\n");

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
        compteur = compteur +1;
      }
      else if (sequence[i]=='A'){
        fprintf(op,"U");
        compteur = compteur +1;
      }
      else if (sequence[i]=='G'){
        fprintf(op,"C");
        compteur = compteur +1;
      }
      else if (sequence[i]=='C'){
        fprintf(op,"G");
        compteur = compteur +1;
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
