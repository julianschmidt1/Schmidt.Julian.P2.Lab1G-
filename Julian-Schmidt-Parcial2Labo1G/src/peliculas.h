/*
 * eMovies.h
 *
 *  Created on: 25 Nov 2022
 *      Author: Julian
 */

#ifndef eMovieS_H_
#define eMovieS_H_
#define TITULO_CHARS 50

#include <string.h>

typedef struct {
	int id;
	char titulo[50];
	char genero[50];
	int rating;
} eMovie;

eMovie* pel_new();
eMovie* pel_newParametros(char *idStr, char *tituloStr, char *generoStr,
		char *ratingStr);

void pel_delete(eMovie *this);

int pel_getId(eMovie *this, int *id);
int pel_getTitulo(eMovie *this, char *titulo);
int pel_getGenero(eMovie *this, char *genero);
int pel_getRating(eMovie *this, int *rating);

int pel_setTitulo(eMovie *this, char *titulo);
int pel_setId(eMovie *this, int id);
int pel_setRating(eMovie *this, int rating);
int pel_setGenero(eMovie *this, char *genero);

#endif /* eMovieS_H_ */
