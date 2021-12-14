#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void extract_sequence(const char* path_input, char* sequence,int taille_fasta) {

    char sequence[taille_fasta];
    
    FILE* fichier = fopen(path_input,"r");

    while (! feof(fichier)) {
        int currentChar = fgetc(fichier);
        sequence[i] = currentChar;
        i++;
    }
    fclose(fichier);
    printf("%s\n",sequence);
    
}

int taille_fasta(const char* path_input) {

    FILE* fichier;
    fichier = fopen(path_input,"r"); 
    fseek(fichier,0L, SEEK_END);
    int a = ftell(fichier);
    rewind(f);
    return(a);
}
