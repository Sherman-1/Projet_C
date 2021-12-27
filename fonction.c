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



void identite(const char* path_input_1, const char* path_input_2){


  //on cherche la taille des séquences qu'on va comparer et non elles doivent être de la même taille
  int taille_sequence_1=0;
  taille(path_input_1, &taille_sequence_1);

  int taille_sequence_2=0;
  taille(path_input_2, &taille_sequence_2);

  char sequence1[taille_sequence_1];
  char sequence2[taille_sequence_2];

  extract_sequence(path_input_1, sequence1, taille_sequence_1);
  extract_sequence(path_input_2, sequence2, taille_sequence_2);

  bool taille = false;

  if (taille_sequence_1 != taille_sequence_2){
    taille = false;
  }
  else{
    taille = true;
  }

  if(taille == true){
    int taille_sequence_identite = 0;
    taille_sequence_identite = taille_sequence_1;


  //on initialise la sequence identité
  char sequence_identite[taille_sequence_identite];

  //initialisation des éléments pour la création de la séquence identité
  int i=0,compteur=0;
  double identite=0, compteur_identite =0;
  //ici, on complète la séquence identité en fonction des deux séquences
  do{
    if (sequence1[i]==sequence2[i]){

      sequence_identite[i] = sequence1[i];
      compteur_identite++;
    }
    else{
      sequence_identite[i] = '-';
    }
    i++;
    compteur++;
  }
  while (compteur != taille_sequence_identite);

  sequence1[taille_sequence_1]='\0';
  sequence2[taille_sequence_2]='\0';

  // on sort le pourcentage d'indentité des deux séquences + les deux séquences qu'on compare + la séquence identité
  identite = (compteur_identite/taille_sequence_identite)*100;
  printf("\n");
  printf("Identité de séquence : %lf/%d, soit %lf pourcent \n\n",compteur_identite,taille_sequence_identite, identite);
  printf("seq1 %s \n\n", sequence1);
  printf("seq2 %s \n\n", sequence2);
  printf("-id- %s \n", sequence_identite);
  }
  else{
    printf("Les tailles de vos séquences sont différentes, recommencez \n");
  //à mettre sous un while pour qu'il redemande la condition si elle n'est pas remplis
  }
}


void simi_pola(const char* path_input_1,const char* path_input_2){

  int taille_sequence_1=0;
  taille(path_input_1, &taille_sequence_1);

  int taille_sequence_2=0;
  taille(path_input_2, &taille_sequence_2);

  char sequence1[taille_sequence_1];
  char sequence2[taille_sequence_2];

  extract_sequence(path_input_1, sequence1, taille_sequence_1);
  sequence1[taille_sequence_1]='\0';
  extract_sequence(path_input_2, sequence2, taille_sequence_2);
  sequence2[taille_sequence_2]='\0';

  printf("\n");

  if (taille_sequence_1 != taille_sequence_2){
    printf("Vos séquences n'ont pas la même taille recommencez");

  }
  else{

    int taille_sequence_pola = taille_sequence_1;
    int i=0;
    int caract_1 =0;
    int caract_2 =0;

    char seq_polarite[taille_sequence_pola];

    for (i=0;i<=taille_sequence_pola-2;i++){

      if (sequence1[i] == 'F' ||sequence1[i] == 'A' ||sequence1[i] == 'L' ||sequence1[i] == 'I' ||sequence1[i] == 'M' ||sequence1[i] == 'W' ||sequence1[i] == 'P' ||sequence1[i] == 'G' ||sequence1[i] == 'V'){
        caract_1 = caract_1 +10;
      }
      else if (sequence1[i] == 'C' ||sequence1[i] == 'Y' ||sequence1[i] == 'T' ||sequence1[i] == 'S' ||sequence1[i] == 'N' ||sequence1[i] == 'Q' ||sequence1[i] == 'H' ||sequence1[i] == 'K' ||sequence1[i] == 'R'||sequence1[i] == 'D'||sequence1[i] == 'E'){
        caract_1 = caract_1 -10;
      }
      else{
        caract_1 = 0;
      }


      if (sequence2[i] == 'F' ||sequence2[i] == 'A' ||sequence2[i] == 'L' ||sequence2[i] == 'I' ||sequence2[i] == 'M' ||sequence2[i] == 'W' ||sequence2[i] == 'P' ||sequence2[i] == 'G' ||sequence2[i] == 'V'){
        caract_2 = caract_2 +10;
      }
      else if (sequence2[i] == 'C' ||sequence2[i] == 'Y' ||sequence2[i] == 'T' ||sequence2[i] == 'S' ||sequence2[i] == 'N' ||sequence2[i] == 'Q' ||sequence2[i] == 'H' ||sequence2[i] == 'K' ||sequence2[i] == 'R'||sequence2[i] == 'D'||sequence2[i] == 'E'){
        caract_2 = caract_2 -10;
      }
      else{
        caract_2 = 0;
      }


      if(caract_1 == 10 && caract_2 == 10){
        seq_polarite[i]='1';
      }
      else if (caract_1 == -10 && caract_2 == -10){
        seq_polarite[i]= '0';
      }
      else{
        seq_polarite[i] = '-';
      }
      if(i == taille_sequence_1){
        seq_polarite[i] = '\0';
      }
      caract_1 = 0;
      caract_2 = 0;
    }
    seq_polarite[taille_sequence_pola-1]='\0';

    printf("0: hydrophiles, 1:hydrophobes, -:différents \n\n");
    printf("%s \n", sequence1);
    printf("%s \n", sequence2);
    printf("%s \n", seq_polarite);
  }
}
