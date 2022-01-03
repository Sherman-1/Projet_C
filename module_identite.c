#include "utils.h"
#include "module_identite.h"

void identite(){

  //L'utilisateur a choisis le module identité

  printf("Vous avez séletionné : Cacule du score d'identité entre deux séquence \n");

  //on initialise les chaines de caractère contenant les voies des fichiers à lire
  char path_input_1[100];
  char path_input_2[100];

  //on lui demande les fichiers qu'il veut comparer
  printf("vous avez besoin de deux fichiers \n");
  printf("Quel est le nom du premier fichier \n");
  scanf("%s", path_input_1);
  printf("Quel est le nom du deuxième fichier \n");
  scanf("%s", path_input_2);

  //on cherche la taille des séquences qu'on va comparer et non elles doivent être de la même taille
  int taille_sequence_1=0;
  //on cherche la taille de la sequence 1
  taille(path_input_1, &taille_sequence_1);

  int taille_sequence_2=0;
  //on cherche la taille de la séquence 2
  taille(path_input_2, &taille_sequence_2);

  //on initialise les séquences avec la taille précedemment determiné
  char sequence1[taille_sequence_1];
  char sequence2[taille_sequence_2];

  //on récupère les séquences des fichiers de l'utilisateur
  extract_sequence(path_input_1, sequence1);
  extract_sequence(path_input_2, sequence2);

  //on initialise un booléen pour verifier que les tailles des deux séquences
  //sont égales
  bool taille = false;

  if (taille_sequence_1 != taille_sequence_2){
    taille = false;
  }
  else{
    taille = true;
  }

  //si le booléen est vrais, on démarre le module
  if(taille == true){
    int taille_sequence_identite = 0;
    taille_sequence_identite = taille_sequence_1;


  //on initialise la sequence identité
  char sequence_identite[taille_sequence_identite];

  //initialisation des éléments pour la création de la séquence identité
  int i=0,compteur=0;
  double identite=0, compteur_identite =0;
  //ici, on complète la séquence identité en fonction des deux séquences
  do{
    if (sequence1[i]==sequence2[i]){

      //si les bases sont les mêmes, la séquence identité prend cette base
      //a la position i
      sequence_identite[i] = sequence1[i];
      compteur_identite++;
    }
    else{

      //si les bases sont différenes, il y aura un - a la position i
      sequence_identite[i] = '-';
    }
    i++;
    compteur++;
  }
  while (compteur != taille_sequence_identite); //la boucle tourne tant que le nombre de tour
  //est différent de la taille de la séquence

  //on rajoute '\0' pour terminer les chaînes de caractère
  //on peut peut être le faire dans le extract sequence directement
  sequence1[taille_sequence_1]='\0';
  sequence2[taille_sequence_2]='\0';

  // on sort le pourcentage d'indentité des deux séquences + les deux séquences qu'on compare + la séquence identité
  identite = (compteur_identite/taille_sequence_identite)*100;
  printf("\n");
  printf("Identité de séquence : %lf/%d, soit %lf pourcent \n\n",compteur_identite,taille_sequence_identite, identite);
  printf("seq1 %s \n\n", sequence1);
  printf("seq2 %s \n\n", sequence2);
  printf("-id- %s \n", sequence_identite);
  }
  else{
    //si les deux tailles dont différentes, on revoit un message d'erreur et l'utilisateur doit relancez le logiciel
    printf("Les tailles de vos séquences sont différentes, recommencez \n");

    //mettre le tout sous un while avec la taille pour redemander des fichiers correctes au lieu de devoir relancer le programme

  }
}
