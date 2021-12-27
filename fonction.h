#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void taille(const char* path_input, int* taille_fasta);
void extract_sequence(const char* path_input, char* sequence,int taille_fasta);
void transcription(const char* path_input);
void traduction(const char* path_input);
void identite(const char* path_input_1, const char* path_input_2);
void simi_pola(const char* path_input_1,const char* path_input_2);
