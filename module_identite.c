#include "utils.h"
#include "module_identite.h"

/*Le module identité a pour but de comparer de séquence protéique de la même taille
et d'afficher en sortie une séquence identité qui montrera les différences entre les
deux séquences en insérant des "-" qui correspondent a des gaps. Il sera également afficher
en sortie le porucentage d'identité entre les deux séquences ainsi que la proportion
d'acide aminé en commun*/


void identite(){

  //L'utilisateur a choisit le module identité

  printf("Vous avez séletionné : Cacule du score d'identité entre deux séquence \n");

  //on initialise les chaines de caractère contenant les voies des fichiers à lire
  char path_input_1[PATH_INPUT_MAX_SIZE];
  char path_input_2[PATH_INPUT_MAX_SIZE];

  //on lui demande les fichiers qu'il veut comparer
  printf("vous avez besoin de deux fichiers \n");
  printf("Le premier : \n");

  //on fait un première appel pour connaitre le nom du premier fichier
  get_path_user(path_input_1),

  printf("le second : \n");

  //on fait un deuxième appel pour connaitre le nom du deuxième fichier
  get_path_user(path_input_2);

  //on cherche la taille des séquences qu'on va comparer et non elles doivent être de la même taille :

  int taille_sequence_1=0;
  int taille_sequence_2=0;

  //on cherche la taille de la sequence 1
  taille(path_input_1, &taille_sequence_1);

  //on cherche la taille de la séquence 2
  taille(path_input_2, &taille_sequence_2);


  //on initialise les séquences avec les tailles précedemment determinées
  char sequence1[taille_sequence_1];
  char sequence2[taille_sequence_2];

  //on récupère les séquences des fichiers de l'utilisateur
  extract_sequence(path_input_1, sequence1);
  extract_sequence(path_input_2, sequence2);

  /*On ajoute un \0 pour terminer les chaînes de caractère afin d'évter des erreurs
  d'affichage*/

  sequence1[taille_sequence_1]='\0';
  sequence2[taille_sequence_2-1]='\0';

  /*on initialise un booléen pour verifier que les tailles des deux séquences
  sont égales*/

  bool taille = false;

  if (taille_sequence_1 != taille_sequence_2-1){

    /*on enlève -1 à la taille de la deuxième car cette dernière ne provient pas
    des précédent modules mais est apporté de façon externe donc le format peut
    différer quelque peu*/

    taille = false; //tailles différentes
  }
  else{

    taille = true; //tailles égales
  }

  //si le booléen est vrais, on démarre le module
  if(taille == true){


  /* Pour chaque acide aminé, on regarde s'ils sont les mêmes dans les deux séquences
  ou non : dans le cas d'une différence un "-" pour indiquer le gap sinon l'acide aminé
  sera conservé dans la séquence identité*/

  //initialisation les éléments pour la création de la séquence identité

    int taille_sequence_identite = 0;
    taille_sequence_identite = taille_sequence_1;
    char sequence_identite[taille_sequence_identite];

  //initialisation des éléments de la boucle

    int i=0,compteur=0;
    double identite=0, compteur_identite =0;

    do{
      if (sequence1[i]==sequence2[i]){

        /*si les acides aminés sont les mêmes, la séquence identité prend l'acide
        aminé en question à la position i*/

        sequence_identite[i] = sequence1[i];
        compteur_identite++;
      }
      else{

        //si les acides aminés sont différenes, il y aura un "-" à la position i
        sequence_identite[i] = '-';
      }
      i++;
      compteur++;
    }
    while (compteur != taille_sequence_identite);
    /*la boucle tourne tant que le nombre de tour est différent de la taille de
    la séquence*/


    //on termine la séquence identité par un \0
    sequence_identite[taille_sequence_identite]='\0';

    /* En sortie, est affiché :
    - le pourcentage d'indentité des deux séquences
    - les deux séquences qu'on compare
    - la séquence identité*/

    identite = (compteur_identite/taille_sequence_identite)*100;
    printf("\n");
    printf("Identité de séquence : %lf/%d, soit %lf pourcent \n\n",compteur_identite,taille_sequence_identite, identite);
    printf("seq1 %s \n\n", sequence1);
    printf("seq2 %s \n\n", sequence2);
    printf("-id- %s \n", sequence_identite);

  }
  else{

    /*si les deux tailles dont différentes, on revoit un message d'erreur et
     l'utilisateur doit relancez le logiciel*/

    printf("Les tailles de vos séquences sont différentes, recommencez \n");

    /*on affche la taille des deux séquences pour montrer a l'utilsateur
    la différence de taille entre les deux fichiers*/

    printf("taille sequence 1 : %d \n", taille_sequence_1);
    printf("taille sequence 2 : %d \n", taille_sequence_2);

  }
}
