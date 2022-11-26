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

/// \brief Constructor por defecto de pelicula
///
/// \return retorna puntero a pelicula
eMovie* pel_new();

/// \brief Constructor por parametros de pelicula
///
/// \param idStr id en forma de char
/// \param tituloStr titulo en forma de char
/// \param generoStr genero en forma de char
/// \param ratingStr rating en forma de char
/// \return
eMovie* pel_newParametros(char *idStr, char *tituloStr, char *generoStr,
		char *ratingStr);

/// \brief Destructor de pelicula
///
/// \param this Puntero a pelicula
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
