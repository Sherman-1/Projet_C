#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void taille(const char* path_input, int* taille_fasta);
void extract_sequence(const char* path_input, char* sequence,int taille_fasta);
