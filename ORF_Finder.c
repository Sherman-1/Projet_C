#include <stdio.h>
#include <string.h>
#include <stddef.h>
#define SIZE_MAX 1000

int main() {

    char sequence[100] = "AAAAUG_______________AUU_AUG________________________AUUU______";
    int i, k;
    int n = 0;
    int boolean_stop;


    typedef struct OpenReadingFrame {

        int start;
        int stop;
        int length;

    } OpenReadingFrame;

    OpenReadingFrame ORF_trouves[100] = {0}; 

    for ( i = 0; i < 42; i++) {

        if ( sequence[i] == 'A' && sequence[i+1] == 'U' && sequence[i+2] == 'G' ) { 

            ORF_trouves[n].start = i;
            printf("Un codon start a ete trouve en position %d\n",ORF_trouves[n].start);
            boolean_stop = 0;
            k = i+3;

            do {

                if ( sequence[k] && sequence[k+1] && sequence[k+2]) {

                    printf("%d",k);

                    if ( sequence[k] == 'A' && sequence[k+1] == 'U' && sequence[k+2] == 'U') {

                        ORF_trouves[n].stop = k;
                        printf("Un codon stop a ete trouve en position %d\n",ORF_trouves[n].stop);

                        ORF_trouves[n].length = (ORF_trouves[n].stop+3) - ORF_trouves[n].start;

                        printf("Une ORF de taille %d a ete trouvee\n",ORF_trouves[n].length);
                        boolean_stop = 1;

                        n += 1;
                        
                    }
                    k += 3;

                }

                else {

                    break;
                }
                
            } while ( boolean_stop == 0 );

        }
    }

    printf("%d\n",n);
    printf("Le plus grand reading frame est de taille %d\n",ORF_trouves[n-1].length);
    return 0;
    
}
