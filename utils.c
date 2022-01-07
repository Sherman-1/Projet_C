#include "utils.h"

void extract_sequence(const char* path_input, char* sequence) {

    char buffer[SIZE_MAX]; // Variable tampon pour accueillir le fichier brut temporairement
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


  /*  ______________________________________

    Seconde partie du code, on traite le buffer
    en fonction de la nature du fichier d'origine.
    ______________________________________*/



    // DANS LE CAS OU FORMAT FASTA

    // Si le fichier est au format fasta, on retire la première ligne
    // On ne traite pas le cas d'un fichier MultiFasta

    if (buffer[0] == '>') {

      // Tant que le premier retour à la ligne n'est pas atteint, on incrémente i depuis 0

      i = 0;
      do {
        i++;
      } while ( buffer[i] != '\n');


      i += 1;       // i prend désormais la valeur de la position du caractère
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
    }

    // DANS LE CAS OU NON FORMAT FASTA

    // Si le fichier n'est pas au format fasta ( module 6 )
    // On transfère buffer[] dans sequence[] sans modification

    else {

      int k;
      for ( k = 0; k < strlen(buffer); k++) {
        sequence[k] = buffer[k];
      }
    }

    //Pour une raison inconnue, la lecture de fichier implique
    //que la chaine buffer[] se termine toujours par un caractère
    //spécial, on le supprime donc en le remplaçant par \0

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

void taille(const char* path_input, int* taille_fasta) {

    FILE* openfile= fopen(path_input, "r");

    while(fgetc(openfile) != EOF)
      (*taille_fasta) ++;

    fclose(openfile);
}

void save_sequence(const char* path_output, char* sequence) {

    int i;
    FILE* fichier = fopen(path_output,"w");


    // Verification de la bonne ouverture du fichier
    if (! fichier) {

        printf("L'ouverture du fichier a échoué. \n");
        exit(EXIT_FAILURE);
    }


    // Bloc de code où on inscrit dans le fichier la séquence entrée dans la
    // procédure. Retour à la ligne dès que 80 caractères sont ajoutés.

    int k = 0;
         // k sert de compteur réinitialisable pour le nombre de caractère ajouté.
    for ( i = 0; i < strlen(sequence); i++) {
        if (k == 80) {

            fputc('\n',fichier);
            k = 0;
        }

        fputc(sequence[i],fichier);
        k++;
    }
}


// Obsolète pour le moment
void get_path_user(char* path_input) {


		printf("Entrez ici votre chemin d'accès au fichier FASTA \n");
		printf("Si le fichier à lire n'est pas dans le répertoire courant,\n");
		printf("veuillez utiliser le chemin absolu vers le fichier\n");

  	scanf("%s",path_input);

  	FILE* fichier = fopen(path_input,"r");
  	if ( !fichier ) {

  	printf("\nLe chemin spécifié ne permet pas l'ouverture du fichier\n");
  	printf("Le programme va maintenant se fermer \n");
  }
}
