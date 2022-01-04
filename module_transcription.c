#include "utils.h"
#include "module_transcription.h"

void transcription(){

  //L'utilisateur a choisit le module de transcription
  printf("Vous avez sélectionné : Transcription \n");

  //on initialise la chaine de caractère contenant la voie du fichier
  char path_input[PATH_INPUT_MAX_SIZE];

  printf("quel est le nom du fichier que vous voulez lire \n");
  scanf("%s", path_input); //nom du fichier test = test_fasta (fichier cours sans la première ligne)
  //on ne peut mettre que le nom du fichier et non tout le chemin
  printf("\n");

  //on cherche la taille de la séquence

  int taille_fasta = 0;
  taille(path_input, &taille_fasta);

  //on initialise la chaine de caractère et on extrait la séquence

  char sequence[taille_fasta];
  extract_sequence(path_input, sequence);


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


  FILE* op= fopen("séquence_transcrite.txt","w");

  //CHECK de la taille de la séquence
  int taille_sequence=strlen(sequence);

  if(taille_sequence%3==0){
    printf("La taille de la séquence est bonne \n");
    taille[0] = 'T'; // Vrais si la taille est divisible par 3
  }
  else{
    printf("La taille de la séquence n'est pas bonne \n");
  }

  int compteur = 0;

  //si les conditions sont remplis on fait la transcription
  // on réalise le changement de base
	
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
  } //on obtient dans un nouveaux fichier le brin transcris d'ARN
  else{
    printf("Redonnez une séquence correcte \n");
    // si la séquence est pas bonne = message d'erreur et on doit recommencer le programme
    // a mettre sous un while pour ne pas avoir a redemarrer le programme
  }

}
