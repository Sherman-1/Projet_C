#include "utils.h"
#include <stdio.h>
#include <string.h>

/* Extract_sequence extraie la séquence FASTA d'un fichier pour la stocker dans une variable char */


void taille(const char* path_input, int* taille_fasta) {

    FILE* openfile= fopen(path_input, "r");

    while(fgetc(openfile) != EOF)
      (*taille_fasta) ++;

    fclose(openfile);

    char buffer[taille_fasta];
    printf("%ld\n",strlen(buffer));
    FILE* fichier = fopen(path_input,"r");
    int i = 0;

    while (! feof(fichier)) {

        int currentChar = fgetc(fichier);

        buffer[i] = currentChar;
        printf("%c\n",buffer[i]); // Print de vérification

        i++;

    } // problème de core dump avec cette version du code au dessus
    // A la fin soit l'execution stoppe à cause d'un pb mémoire
    // Soit le dernier caractère inséré dans le tampon est non trivial
    // peut pas être ouvert par un log. traitement texte

    fclose(fichier);

    i = 0;
    while (buffer[i]!='\n') {
        i++;
    }

    printf("%s\n",buffer);


    int j, k = 0;

    for ( j = i+1; buffer[j]!='\0';j++) {

        if ( buffer[j]!='\n' ) {

            sequence[k] = buffer[j];
            k++;
        }
    }

    //printf("%s\n",sequence);

}

void save_sequence(const char* path_output, char* sequence) {

    FILE* openfile = fopen(path_output, "w");

    fprintf(openfile,"%s", sequence);


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


    FILE* fichier;
    fichier = fopen(path_input,"r");
    fseek(fichier,0L, SEEK_END);
    int a = ftell(fichier);
    rewind(fichier);
    return(a);
}

int main() {


    char path_fichier[50];
    printf("Enter file name\n");
    scanf("%s",path_fichier);

    int taille_seq_fasta =taille_fasta(path_fichier);
    char sequence[taille_seq_fasta];



    extract_sequence(path_fichier,sequence,taille_seq_fasta);
    save_sequence("test2.fasta",sequence);

    return(0);

}
