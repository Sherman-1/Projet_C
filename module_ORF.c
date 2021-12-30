#include <stdio.h>
#include <string.h>
#include <stddef.h>
#define SIZE_MAX 10000

int main() {

    char sequence[SIZE_MAX];

    printf("Bienvenue dans le module de recherche de cadre ouvert de lecture.\n
            Veuillez préciser un chemin d'accès vers un fichier au format fasta.\n
            Y sera recherché le plus grand cadre ouvert de lecture depuis un codon\n
            ATG vers un des trois codons STOP, dans les 6 cadres possibles offerts\n
            par la séquence fournie.\n\n");


    // Mettre procédure d'appel de chemin de fichier //





    // extract_sequence(path_input,sequence);


    int i, k;
    int number_ORF = 0;
    int longest_ORF;
    int boolean_stop;


    typedef struct OpenReadingFrame {

        int start;
        int stop;
        int length;

    } OpenReadingFrame;

    OpenReadingFrame ORF_trouves[30] = {0};

    for ( i = 0; i < strlen(sequence); i++) {

        if ( sequence[i] == 'A' && sequence[i+1] == 'T' && sequence[i+2] == 'G' ) {

            ORF_trouves[number_ORF].start = i;
            printf("Un codon start a ete trouve en position %d\n",ORF_trouves[number_ORF].start+1);
            boolean_stop = 0;
            k = i+3;

            do { // Recherche du codon stop dans le cadre de lecture du codon START trouvé

                if ( sequence[k+2]) {

                    if ( sequence[k] == 'T' && sequence[k+1] == 'G' && sequence[k+2] == 'A') {

                        ORF_trouves[number_ORF].stop = k;
                        printf("Un codon stop a ete trouve en position %d\n",ORF_trouves[number_ORF].stop+1);

                        ORF_trouves[number_ORF].length = (ORF_trouves[number_ORF].stop) - ORF_trouves[number_ORF].start+3;

                        printf("Une ORF de taille %d a ete trouvee\n",ORF_trouves[number_ORF].length);


                        if ( ORF_trouves[number_ORF].length > ORF_trouves[number_ORF-1].length) {

                            longest_ORF = number_ORF;
                        }


                        number_ORF += 1;
                        boolean_stop = 1;



                    }

                    else if ( sequence[k] == 'T' && sequence[k+1] == 'A' && sequence[k+2] == 'G') {

                        ORF_trouves[number_ORF].stop = k;
                        printf("Un codon stop a ete trouve en position %d\n",ORF_trouves[number_ORF].stop+1);

                        ORF_trouves[number_ORF].length = (ORF_trouves[number_ORF].stop) - ORF_trouves[number_ORF].start+3;

                        printf("Une ORF de taille %d a ete trouvee\n",ORF_trouves[number_ORF].length);


                        if ( ORF_trouves[number_ORF].length > ORF_trouves[number_ORF-1].length) {

                            longest_ORF = number_ORF;
                        }


                        number_ORF += 1;
                        boolean_stop = 1;



                    }

                    else if ( sequence[k] == 'T' && sequence[k+1] == 'A' && sequence[k+2] == 'A') {

                        ORF_trouves[number_ORF].stop = k;
                        printf("Un codon stop a ete trouve en position %d\n",ORF_trouves[number_ORF].stop+1);

                        ORF_trouves[number_ORF].length = (ORF_trouves[number_ORF].stop) - ORF_trouves[number_ORF].start+3;

                        printf("Une ORF de taille %d a ete trouvee\n",ORF_trouves[number_ORF].length);


                        if ( ORF_trouves[number_ORF].length > ORF_trouves[number_ORF-1].length) {

                            longest_ORF = number_ORF;
                        }


                        number_ORF += 1;
                        boolean_stop = 1;

                    }

                    k += 3;

                }

                else {

                    break;
                }

            } while ( boolean_stop == 0 ); // Tant qu'un codon n'a pas été trouvé, on parcourt sequence[]

        }
    }


    // Bloc de code où on transcrit puis inverse la séquence pour 6 cadres lecture

    int m, n = strlen(sequence);
    char currentChar;

    for (m = 0; m<n/2; m++) {

        currentChar = sequence[m];
        sequence[m] = sequence[n-m-1];
        sequence[n-m-1] = currentChar;

    }


    // Reste conserver ORF le plus long et stocker sa séquence puis l'imprimer dans fichier output


    printf("%s\n",sequence);
    return 0;

}
