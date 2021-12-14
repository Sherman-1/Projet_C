void extract_sequence(const char* path_input, char* sequence,int taille_fasta) {

    char sequence[taille_fasta];
    
    FILE* fichier = fopen(path_input,"r");

    while (! feof(fichier)) {
        int currentChar = fgetc(fichier);
        sequence[i] = currentChar;
        i++;
    }
    fclose(fichier);
    printf("%s\n",sequence);
    
}
