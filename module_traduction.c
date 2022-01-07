#include "utils.h"
#include "module_traduction.h"


void traduction(){

  printf("Vous avez choisit le module : Traduction \n");

  char path_input[100];

  get_path_user(path_input);

  int taille_sequence = 0;

  taille(path_input,&taille_sequence);

  char sequence[taille_sequence];

  extract_sequence(path_input,sequence);


  bool Arn = false;
  int y=0;
  //int taille_sequence = strlen(sequence); //necessaire pour le Whiles

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
    // si la condition est fausse, on arrete le programme et l'utilisateur doit recommencer
  }
  else{

    printf("C'est bien une sequence à ARN \n");

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

    char path_output[100];

    printf("Quel est le nom du fichier en sortie \n");
    scanf("%s",path_output);

    save_sequence(path_output,sequence_traduite);
  }
}
