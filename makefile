CC = gcc
CFLAGS = -Wall

all: projet_C

projet_C: utils.o module_identite.o module_transcription.o module_traduction.o module_simi_pola.o main.o
	$(CC) main.o utils.o module_identite.o module_transcription.o module_traduction.o module_simi_pola.o -o projet_C

utils.o: utils.c utils.h
	$(CC) -c utils.c $(CFLAGS)

module_identite.o: module_identite.c module_identite.h utils.h
	$(CC) -c module_identite.c $(CFLAGS)

module_transcription.o: module_transcription.c module_transcription.h utils.h
	$(CC) -c  module_transcription.c $(CFLAGS)

module_traduction.o: module_traduction.c module_traduction.h utils.h
	$(CC) -c module_traduction.c $(CFLAGS)

module_simi_pola.o: module_simi_pola.c module_simi_pola.h utils.h
	$(CC) -c module_simi_pola.c $(CFLAGS)

main.o: main.c utils.h module_identite.h module_transcription.h
	$(CC) -c main.c $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f projet_C
