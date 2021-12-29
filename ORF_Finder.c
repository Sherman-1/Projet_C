#include <stdio.h>
#include <string.h>
#include <stddef.h>
#define SIZE_MAX 1000

int main() {

    char sequence[100] = "AUGAA";
    int i, k;
    int number_ORF = 0;
    int longest_ORF;
    int boolean_stop;


    typedef struct OpenReadingFrame {

        int start;
        int stop;
        int length;

    } OpenReadingFrame;

    OpenReadingFrame ORF_trouves[100] = {0};

    for ( i = 0; i < 42; i++) {

        if ( sequence[i] == 'A' && sequence[i+1] == 'T' && sequence[i+2] == 'G' ) {

            ORF_trouves[number_ORF].start = i;
            printf("Un codon start a ete trouve en position %d\n",ORF_trouves[number_ORF].start+1);
            boolean_stop = 0;
            k = i+3;

            do {

                if ( sequence[k] && sequence[k+1] && sequence[k+2]) {

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

                    if ( sequence[k] == 'T' && sequence[k+1] == 'A' && sequence[k+2] == 'G') {

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

                    if ( sequence[k] == 'T' && sequence[k+1] == 'A' && sequence[k+2] == 'A') {

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

            } while ( boolean_stop == 0 );

        }
    }

    printf("Le plus grand reading frame est de taille %d\n",ORF_trouves[longest_ORF].length);
    return 0;

}
