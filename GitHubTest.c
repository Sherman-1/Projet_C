#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(int argc, char *argv[]) 
{
    FILE* fichier = NULL;
    int caractereActuel = 0, i = 0;
    char sequence[2000];

 
    fichier = fopen("test.txt", "r");
 
    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%d", caractereActuel); // On l'affiche
            sequence[i] = caractereActuel;
            i++;

        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
 
        printf("%s",sequence);
        fclose(fichier);
    }
 
    return 0;
}