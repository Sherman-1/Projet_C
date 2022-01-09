#include "utils.h"
#include "module_transcription.h"

/* Le module de transcription sert a transformé les thymines en uraciles.
L'utilisateur fournit un fichier contenant une séquence codante c'est à dire
avec un ATG en début de séquence et un codont STOP à la fin. De plus la séquence
doit avoir un format bien définis c'est a dire que ça taille doit être un multiple
de 3 (necessaire pour la traduction). En sortie, on enregistre la séquence transrite
dans un nouveau fichier */

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

  char sequence_codante[taille_fasta];
  extract_sequence(path_input, sequence_codante);

  printf("%s\n", sequence_codante);

  // Booléens de vérification :
  // pour la taille(%3) + codon START au début

  char codant[] = "F";
  char taille[] = "F";

  int i=0;

  //CHECK du codon start
  if(sequence_codante[0]=='A' && sequence_codante[1]=='T' && sequence_codante[2]=='G'){
    printf("La séquence contient bien un codon START \n");
    codant[0] = 'T'; //Vrais si les trois premieres base correspondent a un ATG
  }
  else{
    printf("La séquence ne commence pas par un codon START \n");
  }


  //CHECK de la taille de la séquence
  int taille_sequence=strlen(sequence_codante);

  if((strlen(sequence_codante)-1)%3==0){
    printf("La taille de la séquence est bonne \n");
    taille[0] = 'T'; // Vrais si la taille est divisible par 3
  }
  else{
    printf("La taille de la séquence n'est pas bonne \n");
  }

  //si les conditions sont remplis on fait la transcription
  // on réalise le changement de base

  if(codant[0]=='T' && taille[0]=='T'){

    char sequence_ARN[taille_sequence];

    for (i=0;i<taille_sequence;i++){

      if (sequence_codante[i]=='T'){
        sequence_ARN[i]='U';

      }
      else if (sequence_codante[i]=='A'){
        sequence_ARN[i]='A';

      }
      else if (sequence_codante[i]=='G'){
        sequence_ARN[i]='G';

      }
      else if (sequence_codante[i]=='C'){
        sequence_ARN[i]='C';
      }
      else{
        sequence_ARN[i]='\0';
      }
    }



  printf("%s \n", sequence_ARN);

  //on demande la nom du fichier de sauvegarde
  char path_output[PATH_INPUT_MAX_SIZE];
  printf("\nVeuillez entrer le nom du fichier dans lequel s'écrira la séquence transcrite\n");
  scanf("%s",path_output);

  //on enregistre le fichier
  save_sequence(path_output,sequence_ARN);

  }

  else{
    printf("Redonnez une séquence correcte \n");
    // si la séquence est pas bonne = message d'erreur et on doit recommencer le programme

  }
}
