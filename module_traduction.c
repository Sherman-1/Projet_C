#include "utils.h"
#include "module_traduction.h"


void traduction(){

  //l'utilisateur a choisit le module de traduction
  printf("Vous avez sélectionné : Traduction \n");

  //on demande a l'utilisateur le nom du fichier qu'il veut lire
  char path_input[100];
  printf("quel est le nom du fichier que vous voulez lire \n");
  scanf("%s", path_input);
  printf("\n");

  //Recherche de la taille de la séquence
  int taille_fasta = 0;
  taille(path_input, &taille_fasta);

  //on extrait la séquence
  char sequence[taille_fasta];
  extract_sequence(path_input, sequence, taille_fasta);

  int i=0;
  int y=0;

  //booléen : verification qu'on a bien une séquence ARN
  bool Arn = false;
  //int taille_sequence = strlen(sequence); //necessaire pour le Whiles

  FILE* op=fopen("séquence_traduite.txt","w");

for (y=0;y<taille_fasta;y++){
  if (sequence[y]=='T'){
    Arn = false;
  }
  else{
    Arn = true;
  }
}

if(Arn == false){
  printf("Ce n'est pas une séquence ARN, recommencez");
  // si la condition est fausse, on arrete le programme et l'utilisateur doit recommencer
}
else{
//si la condition est bonne, on démarre la traduction
    int compteur = 0;
//on met un compteur pour revenir à la ligne tous les 80 caractères
  do{

    if (sequence[i]=='U'){
      if(sequence[i+1]=='U'){
        if(sequence[i+2]=='U'){
          char aa[]="F";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="F";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="L";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="L";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
      else if(sequence[i+1]=='C'){
        if(sequence[i+2]=='U'){
          char aa[]="S";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="S";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="S";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="S";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
      else if(sequence[i+1]=='A'){
        if(sequence[i+2]=='U'){
          char aa[]="Y";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Y";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Stop";
          fprintf(op, "%s",aa);
          compteur = compteur +4;
        }
        else{
          char aa[]="Stop";
          fprintf(op,"%s",aa);
          compteur = compteur +4;
        }
      }
      else if(sequence[i+1]=='G'){
        if(sequence[i+2]=='U'){
          char aa[]="C";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="C";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Stop";
          fprintf(op, "%s",aa);
          compteur = compteur +4;
        }
        else{
          char aa[]="W";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
    }
    else if (sequence[i]=='C'){
      if(sequence[i+1]=='U'){
        if(sequence[i+2]=='U'){
          char aa[]="L";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="L";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="L";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="L";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
      else if(sequence[i+1]=='C'){
        if(sequence[i+2]=='U'){
          char aa[]="P";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="P";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="P";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="P";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
      else if(sequence[i+1]=='A'){
        if(sequence[i+2]=='U'){
          char aa[]="H";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="H";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Q";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="Q";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
      else if(sequence[i+1]=='G'){
        if(sequence[i+2]=='U'){
          char aa[]="R";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="R";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="R";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="R";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
    }
    else if (sequence[i]=='A'){
      if(sequence[i+1]=='U'){
        if(sequence[i+2]=='U'){
          char aa[]="I";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="I";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="I";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="M";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
      else if(sequence[i+1]=='C'){
        if(sequence[i+2]=='U'){
          char aa[]="T";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="T";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="T";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="T";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
      else if(sequence[i+1]=='A'){
        if(sequence[i+2]=='U'){
          char aa[]="N";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="N";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="K";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="K";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
      else if(sequence[i+1]=='G'){
        if(sequence[i+2]=='U'){
          char aa[]="S";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="S";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="R";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="R";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
    }
    else if(sequence[i]=='G'){
      if(sequence[i+1]=='U'){
        if(sequence[i+2]=='U'){
          char aa[]="V";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="V";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="V";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="V";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
      else if(sequence[i+1]=='C'){
        if(sequence[i+2]=='U'){
          char aa[]="A";
          fprintf(op,"%s",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="A";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="A";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="A";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
      else if(sequence[i+1]=='A'){
        if(sequence[i+2]=='U'){
          char aa[]="D";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="D";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="E";
          fprintf(op, "%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="E";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
      else if(sequence[i+1]=='G'){
        if(sequence[i+2]=='U'){
          char aa[]="G";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='C'){
          char aa[]="G";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else if (sequence[i+2]=='A'){
          char aa[]="G";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
        else{
          char aa[]="G";
          fprintf(op,"%s",aa);
          compteur = compteur +1;
        }
      }
    }
    i = i+3;
    if (compteur == 80){
      fprintf(op,"\n");
      compteur = 0;
    }
  }
  while(i<taille_fasta);
}
  fclose(op);

}
