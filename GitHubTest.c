#include <stdio.h>
#include <stdlib.h>


int main() {


    FILE* fp = fopen("test.txt", "w");
    if (!fp) {
        printf("L’ouverture a  ́echou ́e.\n");
        exit(EXIT_FAILURE); 

    }

    fprintf(fp, "Bonjour c'est un test");

    fclose(fp);

}