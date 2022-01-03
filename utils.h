#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE_MAX 10000
#define PATH_INPUT_MAX_SIZE 100


void taille(const char* path_input, int* taille_fasta);
void extract_sequence(const char* path_input, char* sequence);
void get_path_user(char* path_input);
void save_sequence(const char* path_output, char* sequence) ;
