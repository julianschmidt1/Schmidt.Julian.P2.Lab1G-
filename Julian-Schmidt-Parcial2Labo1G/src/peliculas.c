/*
 * peliculas.c
 *
 *  Created on: 25 Nov 2022
 *      Author: Julian
 */

#include "peliculas.h"
#include <stdio.h>
#include <stdlib.h>

eMovie* pel_new() {
	eMovie *pPelicula = (eMovie*) malloc(sizeof(eMovie));

	return pPelicula;
}

eMovie* pel_newParametros(char *idStr, char *tituloStr, char *generoStr,
		char *ratingStr) {

	eMovie *pPelicula = pel_new();

	if (pPelicula != NULL && idStr != NULL && tituloStr != NULL
			&& generoStr != NULL && ratingStr != NULL) {
		if (!(pel_setId(pPelicula, atoi(idStr))
				&& pel_setTitulo(pPelicula, tituloStr)
				&& pel_setGenero(pPelicula, generoStr)
				&& pel_setRating(pPelicula, atoi(ratingStr)))) {
			free(pPelicula);
			pPelicula = NULL;
		}
	} else {
		puts("\nOcurrio un error.");
	}
	return pPelicula;
}

int pel_setTitulo(eMovie *this, char *titulo) {
	int rtn = 0;

	if (this != NULL && titulo != NULL && strlen(titulo) <= TITULO_CHARS) {
		strcpy(this->titulo, titulo);
		rtn = 1;
	} else {
		puts("\nTITULO INVALIDO.");
	}

	return rtn;
}

int pel_setId(eMovie *this, int id) {
	int rtn = 0;

	if (this != NULL) {
		this->id = id;
		rtn = 1;
	}

	return rtn;
}

int pel_setRating(eMovie *this, int rating) {
	int rtn = 0;

	if (this != NULL) {
		this->rating = rating;
		rtn = 1;
	}

	return rtn;
}

int pel_setGenero(eMovie *this, char *genero) {
	int rtn = 0;

	if (this != NULL && genero != NULL && strlen(genero) <= TITULO_CHARS) {
		strcpy(this->genero, genero);
		rtn = 1;
	} else {
		puts("\nGENERO INVALIDO.");
	}

	return rtn;
}

void pel_delete(eMovie *this) {
	free(this);
}

int pel_getId(eMovie *this, int *id) {
	int rtn = 0;
	if (this != NULL && id != NULL) {
		*id = this->id;
		rtn = 1;
	}
	return rtn;
}

int pel_getTitulo(eMovie *this, char *titulo) {
	int rtn = 0;
	if (this != NULL && titulo != NULL) {
		strcpy(titulo, this->titulo);
		rtn = 1;
	}
	return rtn;
}

int pel_getGenero(eMovie *this, char *genero) {
	int rtn = 0;
	if (this != NULL && genero != NULL) {
		strcpy(genero, this->genero);
		rtn = 1;
	}
	return rtn;
}

int pel_getRating(eMovie *this, int *rating) {
	int rtn = 0;
	if (this != NULL && rating != NULL) {
		*rating = this->rating;
		rtn = 1;
	}
	return rtn;
}

