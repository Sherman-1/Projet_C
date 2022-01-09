#include "utils.h"
#include "module_ORF.h"


/* Le module ORF a pour objectif de trouver la séquence codante la plus longue
dans un fichier fasta que l'urilsateur aura choisi. En sortie, sera afficher
la taille de la séquence codante, sa position dans le fichier, ainsi le brin sur
lequel elle a été trouvé*/

void orf() {

    printf("\nVous avez sélectionné : Rechercher la séquence codante la plus longue \n");

    printf("Bienvenue dans le module de recherche de cadre ouvert de lecture.\n"
            "Veuillez préciser un chemin d'accès vers un fichier au format fasta.\n"
            "Y sera recherché le plus grand cadre ouvert de lecture depuis un codon\n"
            "ATG vers un des trois codons STOP, dans les 6 cadres possibles offerts\n"
            "par la séquence fournie.\n\n");


    //on demande en entré le nom du fichier de l'utilisateur
    char path_input[PATH_INPUT_MAX_SIZE];
    int taille_sequence = 0;

    get_path_user(path_input);

    printf("\n");

    //on détermine la taille du fichier fournis
    taille(path_input, &taille_sequence);

    char sequence[taille_sequence];

    //on extrait les données du fichier dans une séquence
    extract_sequence(path_input, sequence);
		printf("Taille sequence input : %ld\n",strlen(sequence));




    int i, k; // Compteurs
    int boolean_stop;

		// On stocke dans cette structure les informations
		// de chaque ORF trouvé

    typedef struct OpenReadingFrame {

        int start;
        int stop;
        int length;

    } OpenReadingFrame;

		// On déclare un tableau de cette structure pour conserver les positions de tous les ORF trouvés

    OpenReadingFrame ORF_trouves[1000] = {0};

		// Garde en mémoire si l'ORF le plus long est sur le brin sens ou antisens
		// A la fin du code, 0 voudra dire brin sens, 1 brin antisens 
		int sens_antisens = -1;

		// Compteur permettant de parcourir ORF_trouves[]
		int number_ORF = 0;

		// Commpteur permettant de garder en mémoire l'indice de l'ORF le plus long
		int longest_ORF;



	// Recherche de l'ORF le plus long dans le brin sens

    for ( i = 0; i < strlen(sequence); i++) { // On cherche de 1 en 1 dans sequence[]
        if ( sequence[i] == 'A' && sequence[i+1] == 'T' && sequence[i+2] == 'G' ) { // La présence d'un codon START

            ORF_trouves[number_ORF].start = i; // Si START, on indique sa position

            boolean_stop = 0; // Permet de maintenir la boucle do while
            k = i+3; // k représente ici la position du codon juste après START

            do { // Recherche du codon stop dans le cadre de lecture du codon START trouvé

                if ( sequence[k+2]) { // Si la séquence continue jusqu'à l'indice k+2 on continue de chercher, on évite les lectures hors bornes

                    if ( sequence[k] == 'T' && sequence[k+1] == 'G' && sequence[k+2] == 'A') { // Si un des codons STOP est trouvé

                        ORF_trouves[number_ORF].stop = k; // Si STOP on indique sa position
                        ORF_trouves[number_ORF].length = (ORF_trouves[number_ORF].stop) - ORF_trouves[number_ORF].start+3; // On caclule la longueur de l'ORF


												// Si la longueur de l'ORF présentement trouvé est plus grande que la longueur du précédent
												// On affecte à longest_ORF l'indice courant de number_ORF, pour garder sa position en mémoire

                        if ( ORF_trouves[number_ORF].length > ORF_trouves[number_ORF-1].length) {

                            longest_ORF = number_ORF;
														sens_antisens = 0; // On indique également si il se situe sur le brin sens ou antisens

                        }


                        number_ORF += 1; // Si un STOP est trouvé, on passe au ORF_trouves[] suivant
                        boolean_stop = 1; // Puis on sort de la boucle WHILE en se servant du booleen



                    }

                    else if ( sequence[k] == 'T' && sequence[k+1] == 'A' && sequence[k+2] == 'G') { // Meme chose avec le second codon STOP

                        ORF_trouves[number_ORF].stop = k;
                        ORF_trouves[number_ORF].length = (ORF_trouves[number_ORF].stop) - ORF_trouves[number_ORF].start+3;


                        if ( ORF_trouves[number_ORF].length > ORF_trouves[number_ORF-1].length) {

                            longest_ORF = number_ORF;
														sens_antisens = 0;

                        }


                        number_ORF += 1;
                        boolean_stop = 1;

                    }

                    else if ( sequence[k] == 'T' && sequence[k+1] == 'A' && sequence[k+2] == 'A') { // Meme chose avec le troisieme codon STOP

                        ORF_trouves[number_ORF].stop = k;
                        ORF_trouves[number_ORF].length = (ORF_trouves[number_ORF].stop) - ORF_trouves[number_ORF].start+3;

                        if ( ORF_trouves[number_ORF].length > ORF_trouves[number_ORF-1].length) {

                            longest_ORF = number_ORF;
														sens_antisens = 0;

                        }

                        number_ORF += 1;
                        boolean_stop = 1;

                    }

                    k += 3; // k est incrémenté de 3 pour rester sur le cadre de lecture en cours

                }

                else {

										// Si sequence[k+2] n'existe pas, on sort de la boucle while en laissant
										// ORF_trouves[number_ORF].stop et ORF_trouves[number_ORF].length = 0
                    break;
                }

            } while ( boolean_stop == 0 ); // Tant qu'un codon n'a pas été trouvé, on parcourt sequence[]

        }
    }

		if ( number_ORF == 0 ) {

			sens_antisens = 1; // Si aucun ORF n'a été trouvé dans le brin sens, on passe la mémoire à 1

		}


    // Bloc de code où on complémente puis inverse la séquence pour 6 cadres lecture au total

    // Brin complément

    char complement[SIZE_MAX];
    int complement_compteur = 0;
    for ( i = 0; i < strlen(sequence); i++) {

        if ( sequence[i] == 'A') {
            complement[complement_compteur] = 'T';
                        complement_compteur++;
        }

                else if ( sequence[i] == 'T') {

            complement[complement_compteur] = 'A';
                        complement_compteur++;
        }

        else if ( sequence[i] == 'G') {

            complement[complement_compteur] = 'C';
                        complement_compteur++;
        }

        else if ( sequence[i] == 'C') {
            complement[complement_compteur] = 'G';
                        complement_compteur++;
        }
    }


    // Inversion du complément pour chercher l'ORF dans le bon
    // sens de lecture du brin d'ADN complémentaire

    int m;
		int n = strlen(complement);
    char currentChar;

    for (m = 0; m<n/2; m++) {

        currentChar = complement[m];
        complement[m] = complement[n-m-1]; // -1 Car on ne veut pas bouger le \O
        complement[n-m-1] = currentChar;

    }

	// Recherche de l'ORF la plus longue dans le reverse complement ( complement[] )

    for ( i = 0; i < strlen(complement); i++) {

        if ( complement[i] == 'A' && complement[i+1] == 'T' && complement[i+2] == 'G' ) {

            ORF_trouves[number_ORF].start = i;
            boolean_stop = 0;
            k = i+3;

            do { // Recherche du codon stop dans le cadre de lecture du codon START trouvé

                if ( complement[k+2]) {

                    if ( complement[k] == 'T' && complement[k+1] == 'G' && complement[k+2] == 'A') {

                        ORF_trouves[number_ORF].stop = k;
                        ORF_trouves[number_ORF].length = (ORF_trouves[number_ORF].stop) - ORF_trouves[number_ORF].start+3;


                        if ( ORF_trouves[number_ORF].length > ORF_trouves[number_ORF-1].length) {

                            longest_ORF = number_ORF;
                            sens_antisens = 1;

                        }

                        number_ORF += 1;
                        boolean_stop = 1;

                    }

                    else if ( complement[k] == 'T' && complement[k+1] == 'A' && complement[k+2] == 'G') {

                        ORF_trouves[number_ORF].stop = k;
                        ORF_trouves[number_ORF].length = (ORF_trouves[number_ORF].stop) - ORF_trouves[number_ORF].start+3;

                        if ( ORF_trouves[number_ORF].length > ORF_trouves[number_ORF-1].length) {

                            longest_ORF = number_ORF;
                            sens_antisens = 1;

                        }


                        number_ORF += 1;
                        boolean_stop = 1;



                    }

                    else if ( complement[k] == 'T' && complement[k+1] == 'A' && complement[k+2] == 'A') {

                        ORF_trouves[number_ORF].stop = k;
                        ORF_trouves[number_ORF].length = (ORF_trouves[number_ORF].stop) - ORF_trouves[number_ORF].start+3;

                        if ( ORF_trouves[number_ORF].length > ORF_trouves[number_ORF-1].length) {

                            longest_ORF = number_ORF;
                            sens_antisens = 1;

                        }


                        number_ORF += 1;
                        boolean_stop = 1;

                    }

                    k += 3;

                }

                else {

                    break;
                }

            } while ( boolean_stop == 0 ); // Tant qu'un codon n'a pas été trouvé, on parcourt complement[]

        }
    }

		if ( number_ORF == 0 ) {

				sens_antisens = -1; // Si là encore aucun ORF n'a été trouvé, on repasse la mémoire à son état neutre de départ.

		}


		// Dernier bloc de code où on charge l'ORF la plus longue
		// Dans une séquence qui sera utilisée pour obtenir le
		// résultat sous forme de fichier

		char orf_final[SIZE_MAX]; // On entre dans un CHAR l'ORF de plus longue taille
		int compteur_final = 0;
		char path_output[PATH_INPUT_MAX_SIZE];

		if ( sens_antisens == 0 ) { // Si l'ORF est sur le brin sens on cherche dans sequence[]
			for ( i = ORF_trouves[longest_ORF].start; i < ORF_trouves[longest_ORF].stop+3; i++) {

				orf_final[compteur_final] = sequence[i];
				compteur_final++;
			}

			printf("La longueur de l'ORF finale est : %ld\n",strlen(orf_final));

			printf("\nL'ORF le plus long a été trouvé sur le brin sens, sa séquence va maintenant etre sauvegardee dans un fichier de sortie");
			printf("\nVeuillez entrer le nom du fichier dans lequel s'écrira votre ORF trouvee\n");
			scanf("%s",path_output);
			save_sequence(path_output,orf_final);
		}

		else if ( sens_antisens == 1 ) { // Si l'ORF est sur le brin antisens on cherche dans complement[]
			for ( i = ORF_trouves[longest_ORF].start; i < ORF_trouves[longest_ORF].stop+3; i++) {

				orf_final[compteur_final] = complement[i];
				compteur_final++;

			}

			printf("La longueur de l'ORF finale est : %ld\n",strlen(orf_final));

			printf("\nL'ORF le plus long a été trouvé sur le brin antisens, sa séquence va maintenant etre sauvegardee dans un fichier de sortie");
			printf("\nVeuillez entrer le nom du fichier dans lequel s'écrira votre ORF trouvee\n");
			scanf("%s",path_output);
			save_sequence(path_output,orf_final);
		}

		else if ( sens_antisens == -1)  {

				printf("\nAucun ORF n'a ete trouve, le programme va désormais s'arrêter.\n\n");
		}

}
