/*
 * callbacks.c
 *
 *  Created on: 25 Nov 2022
 *      Author: Julian
 */

#include "callbacks.h"
#include "peliculas.h"
#include <stdio.h>
#include <stdlib.h>

int callbackFilterDrama(void *this) {
	int rtn = 0;
	eMovie *auxPelicula;
	char auxGenero[30];

	if (this != NULL) {
		auxPelicula = (eMovie*) this;
		pel_getGenero(auxPelicula, auxGenero);
		if (!stricmp("drama", auxGenero)) {
			rtn = 1;
		}
	}

	return rtn;
}

int callbackFilterTerror(void *this) {
	int rtn = 0;
	eMovie *auxPelicula;
	char auxGenero[30];

	if (this != NULL) {
		auxPelicula = (eMovie*) this;
		pel_getGenero(auxPelicula, auxGenero);
		if (!stricmp("terror", auxGenero)) {
			rtn = 1;
		}
	}

	return rtn;
}

int callbackFilterAccion(void *this) {
	int rtn = 0;
	eMovie *auxPelicula;
	char auxGenero[30];

	if (this != NULL) {
		auxPelicula = (eMovie*) this;
		pel_getGenero(auxPelicula, auxGenero);
		if (!stricmp("accion", auxGenero)) {
			rtn = 1;
		}
	}

	return rtn;
}

int callbackFilterComedia(void *this) {
	int rtn = 0;
	eMovie *auxPelicula;
	char auxGenero[30];

	if (this != NULL) {
		auxPelicula = (eMovie*) this;
		pel_getGenero(auxPelicula, auxGenero);
		if (!stricmp("comedia", auxGenero)) {
			rtn = 1;
		}
	}

	return rtn;
}

void callbackMap(void *this) {
	eMovie *pelicula;
	int min = 1;
	int max = 10;
	int numeroRandom;
	if (this != NULL) {
		pelicula = (eMovie*) this;
		// Profe estoy tratando esto como un int porque hay un error al intentar usar % con flotantes, me puse a investigar dice que use uan funcion fmod, pero no quiero perder tiempo y no la conozco
		numeroRandom = rand() % (max - min + 1) + min;
		pel_setRating(pelicula, numeroRandom);
	}
}

void callbackMapGeneros(void *this) {
	eMovie *pelicula;
	int min = 1;
	int max = 4;
	int numeroRandom;
	char auxGenero[30];
	if (this != NULL) {
		pelicula = (eMovie*) this;
		numeroRandom = rand() % (max - min + 1) + min;
		switch (numeroRandom) {
		case 1:
			strcpy(auxGenero, "Drama");
			break;
		case 2:
			strcpy(auxGenero, "Comedia");
			break;
		case 3:
			strcpy(auxGenero, "Accion");
			break;
		case 4:
			strcpy(auxGenero, "Terror");
			break;
		}
		pel_setGenero(pelicula, auxGenero);
	}
}

int callbackOrdenarPorGenero(void *pPrimerPelicula, void *pSegundoPelicula) {
	int rtn = 0;
	eMovie *auxPrimerPelicula;
	eMovie *auxSegundoPelicula;
	char generoPrimerPelicula[15];
	char generoSegundoPelicula[15];
	int resultadoOrdenamiento;
	int ratingPrimerPelicula;
	int ratingSegundaPelicula;
	int resultadoOrdenamientoRating;

	if (pPrimerPelicula != NULL && pSegundoPelicula != NULL) {
		auxPrimerPelicula = (eMovie*) pPrimerPelicula;
		auxSegundoPelicula = (eMovie*) pSegundoPelicula;
		if (pel_getGenero(auxPrimerPelicula, generoPrimerPelicula)
				&& pel_getGenero(auxSegundoPelicula, generoSegundoPelicula)
				&& pel_getRating(auxPrimerPelicula, &ratingPrimerPelicula)
				&& pel_getRating(auxSegundoPelicula, &ratingSegundaPelicula)) {
			resultadoOrdenamiento = stricmp(generoPrimerPelicula,
					generoSegundoPelicula);
			resultadoOrdenamientoRating = ratingPrimerPelicula
					< ratingSegundaPelicula;

			if (resultadoOrdenamiento > 0) {
				rtn = 1;
			} else {
				if (resultadoOrdenamiento < 0
						|| (resultadoOrdenamiento == 0
								&& resultadoOrdenamientoRating)) {
					rtn = -1;
				}
			}
		}
	}
	return rtn;
}

