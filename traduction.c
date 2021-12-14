#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//le code fonctionne pour une séquence donnée, il n'y a pas la condition de retour a la
//ligne au bout de 80 caractères, ni le CHECK pour verifier que c'est bien une séquence ARN
// et pas ADN

int main(){
  char sequence[]="AUGAUUUUCCCUGAGCCAGGG";
  int i=0;
  int y=0;
  bool Arn = false;
  int taille_sequence = strlen(sequence); //necessaire pour le Whiles

  FILE* op=fopen("sequence_proteique.txt","w");

for (y=0;y<taille_sequence;y++){
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

  do{

    if (sequence[i]=='U'){
      if(sequence[i+1]=='U'){
        if(sequence[i+2]=='U'){
          char aa[]="Phe";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Phe";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Leu";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Leu";
          fprintf(op,"%s \t",aa);
        }
      }
      else if(sequence[i+1]=='C'){
        if(sequence[i+2]=='U'){
          char aa[]="Ser";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Ser";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Ser";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Ser";
          fprintf(op,"%s \t",aa);
        }
      }
      else if(sequence[i+1]=='A'){
        if(sequence[i+2]=='U'){
          char aa[]="Tyr";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Tyr";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Stop";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Stop";
          fprintf(op,"%s \t",aa);
        }
      }
      else if(sequence[i+2]=='G'){
        if(sequence[i+2]=='U'){
          char aa[]="Cys";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Cys";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Stop";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Cys";
          fprintf(op,"%s \t",aa);
        }
      }
    }
    else if (sequence[i]=='C'){
      if(sequence[i+1]=='U'){
        if(sequence[i+2]=='U'){
          char aa[]="Leu";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Leu";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Leu";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Leu";
          fprintf(op,"%s \t",aa);
        }
      }
      else if(sequence[i+1]=='C'){
        if(sequence[i+2]=='U'){
          char aa[]="Pro";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Pro";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Pro";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Pro";
          fprintf(op,"%s \t",aa);
        }
      }
      else if(sequence[i+1]=='A'){
        if(sequence[i+2]=='U'){
          char aa[]="His";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="His";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Gln";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Gln";
          fprintf(op,"%s \t",aa);
        }
      }
      else if(sequence[i+2]=='G'){
        if(sequence[i+2]=='U'){
          char aa[]="Arg";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Arg";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Arg";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Arg";
          fprintf(op,"%s \t",aa);
        }
      }
    }
    else if (sequence[i]=='A'){
      if(sequence[i+1]=='U'){
        if(sequence[i+2]=='U'){
          char aa[]="Ile";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Ile";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Ile";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Met";
          fprintf(op,"%s \t",aa);
        }
      }
      else if(sequence[i+1]=='C'){
        if(sequence[i+2]=='U'){
          char aa[]="Thr";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Thr";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Thr";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Thr";
          fprintf(op,"%s \t",aa);
        }
      }
      else if(sequence[i+1]=='A'){
        if(sequence[i+2]=='U'){
          char aa[]="Asp";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Asp";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Lys";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Lys";
          fprintf(op,"%s \t",aa);
        }
      }
      else if(sequence[i+2]=='G'){
        if(sequence[i+2]=='U'){
          char aa[]="Ser";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Ser";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Arg";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Arg";
          fprintf(op,"%s \t",aa);
        }
      }
    }
    else if(sequence[i]=='G'){
      if(sequence[i+1]=='U'){
        if(sequence[i+2]=='U'){
          char aa[]="Val";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Val";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Val";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Val";
          fprintf(op,"%s \t",aa);
        }
      }
      else if(sequence[i+1]=='C'){
        if(sequence[i+2]=='U'){
          char aa[]="Ala";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Ala";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Ala";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Ala";
          fprintf(op,"%s \t",aa);
        }
      }
      else if(sequence[i+1]=='A'){
        if(sequence[i+2]=='U'){
          char aa[]="Asp";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Asp";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Glu";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Glu";
          fprintf(op,"%s \t",aa);
        }
      }
      else if(sequence[i+2]=='G'){
        if(sequence[i+2]=='U'){
          char aa[]="Gly";
          fprintf(op,"%s \t",aa);
        }
        else if (sequence[i+2]=='C'){
          char aa[]="Gly";
          fprintf(op,"%s\t",aa);
        }
        else if (sequence[i+2]=='A'){
          char aa[]="Gly";
          fprintf(op, "%s \t",aa);
        }
        else{
          char aa[]="Gly";
          fprintf(op,"%s \t",aa);
        }
      }
    }
    i = i+3;
  }
  while(i<taille_sequence);
}
  fclose(op);
}
