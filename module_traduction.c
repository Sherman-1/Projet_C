#include "utils.h"
#include "module_traduction.h"

/* Le module traduction a pour but de traduire l'ARNm en une séquence protéique
composé d'acide aminé. L'utilisateur fournis un fichier contenant une sequence
ARN et le module va traduire chaque codon (3 bases par 3 bases) et faire
correspondre une lettre correspondant à un acide aminé précis. En sortis,
l'utilisateur doit chosir un fichier dans lequel il veut que la séquence protéique
soit affiché*/

void traduction(){

  printf("Vous avez choisit le module : Traduction \n");

  // on définit le nom du fichier qui sera lu
  char path_input[100];
  get_path_user(path_input);

  //on détermine la taille du fichier
  int taille_sequence = 0;
  taille(path_input,&taille_sequence);

  //on extrait les données du fcihier
  char sequence[taille_sequence];
  extract_sequence(path_input,sequence);


  /* On a un booléen de vérification qui permet de verifier qu'il s'agisse
  bien d'une séquence ARN et qu'il n'y est pas de Thymine dans la séquence (T)
  si le booléens reste faux alors la traduction n'est pas réalisé*/


  bool Arn = false;
  int y=0;


  FILE* op=fopen(path_input,"r");

  for (y=0;y<taille_sequence;y++){
    if (sequence[y]=='T'){
      Arn = false;
    }
    else{
      Arn = true;

    }
  }

  fclose(op);

  if(Arn == false){
    printf("Ce n'est pas une séquence à ARN, recommencez \n");

    /* si le boolée = false on arrete le programme et l'utilisateur
    doit relancer le programme et recommencer */
  }
  else{
    // si le booléen = true alors la traduction se fera

    printf("C'est bien une sequence à ARN \n");

    /* La traduction est réalisée en prenant la base à la position i ainsi que
    que les bases a la position i+1 et i+2 de cette façon on obtient un codon
    et on avance de trois en trois jusqu'à dépasser la taille du fichier.
    Les codons sont ensuite un à un mis sous toutes les combinaisons possibe
    d'acide aminé jusqu'à trouver la bonne combinaison qui est ensuite
    enregistrée dans une séquence temporaire qui sera utilisée lors de la
    sauvegarde dans un fichier*/

    int i = 0;
    char sequence_traduite[taille_sequence/3];
    int compteur = 0;


    do{

    if (sequence[i]=='U'){
      if(sequence[i+1]=='U'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='F';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='F';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='L';

        }
        else{
          sequence_traduite[compteur]='L';

        }
      }
      else if(sequence[i+1]=='C'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='S';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='S';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='S';

        }
        else{
          sequence_traduite[compteur]='S';

        }
      }
      else if(sequence[i+1]=='A'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='Y';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='M';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='\0';

        }
        else{
          sequence_traduite[compteur]='\0';

        }
      }
      else if(sequence[i+1]=='G'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='C';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='C';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='\0';

        }
        else{
          sequence_traduite[compteur]='W';

        }
      }
    }
    else if (sequence[i]=='C'){
      if(sequence[i+1]=='U'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='L';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='L';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='L';

        }
        else{
          sequence_traduite[compteur]='L';

        }
      }
      else if(sequence[i+1]=='C'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='P';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='P';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='P';

        }
        else{
          sequence_traduite[compteur]='P';

        }
      }
      else if(sequence[i+1]=='A'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='H';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='H';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='Q';

        }
        else{
          sequence_traduite[compteur]='Q';

        }
      }
      else if(sequence[i+1]=='G'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='R';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='R';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='R';

        }
        else{
          sequence_traduite[compteur]='R';

        }
      }
    }
    else if (sequence[i]=='A'){
      if(sequence[i+1]=='U'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='I';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='I';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='I';

        }
        else{
          sequence_traduite[compteur]='M';

        }
      }
      else if(sequence[i+1]=='C'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='T';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='T';

        }
          else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='T';

        }
        else{
          sequence_traduite[compteur]='T';

        }
      }
      else if(sequence[i+1]=='A'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='N';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='N';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='K';

        }
        else{
          sequence_traduite[compteur]='K';

        }
      }
      else if(sequence[i+1]=='G'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='S';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='S';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='R';

        }
        else{
          sequence_traduite[compteur]='R';

        }
      }
    }
    else if(sequence[i]=='G'){
      if(sequence[i+1]=='U'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='V';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='V';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='V';

        }
        else{
          sequence_traduite[compteur]='V';

        }
      }
      else if(sequence[i+1]=='C'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='A';


        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='A';


        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='A';

        }
        else{
          sequence_traduite[compteur]='A';

        }
      }
      else if(sequence[i+1]=='A'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='D';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='D';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='E';

        }
        else{
          sequence_traduite[compteur]='E';

        }
      }
      else if(sequence[i+1]=='G'){
        if(sequence[i+2]=='U'){
          sequence_traduite[compteur]='G';

        }
        else if (sequence[i+2]=='C'){
          sequence_traduite[compteur]='G';

        }
        else if (sequence[i+2]=='A'){
          sequence_traduite[compteur]='G';

        }
        else{
          sequence_traduite[compteur]='G';

        }
      }
    }
  i = i +3 ;
  compteur ++;
  }
    while(i<taille_sequence);

    printf("%s \n", sequence_traduite);

    //on demande a l'utilisateur le nom du fichier de sortie
    char path_output[100];
    printf("Quel est le nom du fichier en sortie \n");
    scanf("%s",path_output);

    //sauvegarde de la séquence de traduction
    save_sequence(path_output,sequence_traduite);
  }
}
