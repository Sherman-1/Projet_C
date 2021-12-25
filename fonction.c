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



void traduction(const char* path_input){
  //char sequence[]="AUGAUUUUCCCUGAGCCAGGG";

  int taille_fasta = 0;
  taille(path_input, &taille_fasta);

  //printf("%d \n", taille_fasta);
  char sequence[taille_fasta];

  extract_sequence(path_input, sequence, taille_fasta);

  int i=0;
  int y=0;
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
}
else{

    int compteur = 0;

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
