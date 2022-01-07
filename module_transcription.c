#include "utils.h"
#include "module_transcription.h"

void transcription(){

  //L'utilisateur a choisit le module de transcription
  printf("Vous avez sélectionné : Transcription \n");

  //on initialise la chaine de caractère contenant la voie du fichier
  char path_input[PATH_INPUT_MAX_SIZE];

  get_path_user(path_input);

  printf("\n");

  //on cherche la taille de la séquence

  int taille_fasta = 0;
  taille(path_input, &taille_fasta);

  //on initialise la chaine de caractère et on extrait la séquence

  char sequence[taille_fasta];
  extract_sequence(path_input, sequence);

  printf("%s\n", sequence);

  // Booléens de vérification :
  // pour la taille(%3) + codon START au début

  char codant[] = "F";
  char taille[] = "F";

  int i=0;

  //CHECK du codon start
  if(sequence[0]=='A' && sequence[1]=='T' && sequence[2]=='G'){
    printf("La séquence contient bien un codon START \n");
    codant[0] = 'T'; //Vrais si les trois premieres base correspondent a un ATG
  }
  else{
    printf("La séquence ne commence pas par un codon START \n");
  }


  //CHECK de la taille de la séquence
  int taille_sequence=strlen(sequence);

  if((strlen(sequence)-1)%3==0){
    printf("La taille de la séquence est bonne \n");
    taille[0] = 'T'; // Vrais si la taille est divisible par 3
  }
  else{
    printf("La taille de la séquence n'est pas bonne \n");
  }

  char sequence_transcrite[taille_sequence];

  //si les conditions sont remplis on fait la transcription
  // on réalise le changement de base

  if(codant[0]=='T' && taille[0]=='T'){
    for (i=0;i<taille_sequence;i++){
      if (sequence[i]=='\0'){
        i++;
      }
      else if (sequence[i]=='T'){
        sequence_transcrite[i]='A';

      }
      else if (sequence[i]=='A'){
        sequence_transcrite[i]='U';

      }
      else if (sequence[i]=='G'){
        sequence_transcrite[i]='C';

      }
      else{
        sequence_transcrite[i]='G';
      }
    }


  printf("%s \n", sequence_transcrite);

  char path_output[PATH_INPUT_MAX_SIZE];
  printf("\nVeuillez entrer le nom du fichier dans lequel s'écrira la séquence transcrite\n");
  scanf("%s",path_output);
  save_sequence(path_output,sequence_transcrite);
  }
   //on obtient dans un nouveaux fichier le brin transcris d'ARN
  else{
    printf("Redonnez une séquence correcte \n");
    // si la séquence est pas bonne = message d'erreur et on doit recommencer le programme
    // a mettre sous un while pour ne pas avoir a redemarrer le programme
  }
}
