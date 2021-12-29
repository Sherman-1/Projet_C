#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE_MAX 10000

void extract_sequence(const char* path_input, char* sequence) {

    char buffer[SIZE_MAX]; // Variable tampon pour accueillir le fichier brut
    int i = 0;

    FILE* fichier = fopen(path_input,"r");
    if (! fichier ) {
      printf ( " L'ouverture a échouée\n Veuillez spécifier un chemin d'accès valide pour le fichier\n" ) ;
      exit ( EXIT_FAILURE ) ;
    }


    // Tant que le caractère EOF n'est pas atteint, on déplace le curseur fgetc le long du fichier
    // Le contenu du fichier est versé dans buffer[]
    while (! feof(fichier)) {
        int currentChar = fgetc(fichier);
        buffer[i] = currentChar;
        i++;
    }

    fclose(fichier);

    /*
    ______________________________________

    Seconde partie du code, ici on nettoie buffer
    pour transférer son contenu dans la variable appelée
    par la procédure
    On retire en premier la ligne header du FASTA
    ______________________________________
    */

    // Tant que le premier retour à la ligne n'est pas atteint, on incrémente i depuis 0

    i = 0;
    do {
      i++;
    } while ( buffer[i] != '\n');


    i += 1;       // i prend la valeur de la position du premier caractère
                  // apparaissant juste après le premier retour chariot

    int k, n = 0; // Variables de comptage


    // On parcourt buffer[] à l'aide de k, on ajoute son contenu
    // dans sequence si celui ci est différent d'un retour à la ligne


    for ( k = i ; k < strlen(buffer); k++) {

      if (buffer[k] != '\n') {

        sequence[n] = buffer[k];
        n++;

      }
    }

    /* Pour une raison inconnue, la lecture de fichier implique
    que la chaine buffer[] se termine toujours par un caractère
    spécial, on le supprime donc en le remplaçant par \0 */

    sequence[strlen(sequence)-1] = '\0';
}


// Fonction obsolète car les consignes autorisent de définir une SIZE_MAX de 10000
size_t taille_fasta(const char* path_input) {

    FILE* fichier;
    fichier = fopen(path_input,"r");
    fseek(fichier,0L, SEEK_END);
    size_t a = ftell(fichier);
    rewind(fichier);
    return(a);
}

int main() {

  char sequence[SIZE_MAX];
  extract_sequence("/home/sherman/Bureau/Dossier_Tests/test.fasta",sequence);
  return 0;

}
