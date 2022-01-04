#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE_MAX 200

void save_sequence(const char* path_output, const char* sequence) {

    int i;
    FILE* fichier = fopen(path_output,"w");


    if ( !fichier) {

        printf("L'ouverture du fichier a échoué. \n");
        exit(EXIT_FAILURE);
    }

    int k = 0;
         
    for ( i = 0; i < strlen(sequence); i++) {
        if (k == 80) {

            fputc('\n',fichier);
            k = 0;
        }
        fputc(sequence[i],fichier);
        k++;
    }
}

int main() {

  char sequence[600] = "NEGENFENFJZENFLKZENFEZNFKEZNFKJEZNFKJEZNFKJEZNFJKENFJKEZNF2NZFJEZFZENFIZBEUFNOZEFBUIEZNFEBZIFHNEZFBHEZFEZIHFBZEFHEZJFHEZ";

  save_sequence("output_test.fasta",sequence);

  return 0;
}

  

