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

/// \brief Getter de id
///
/// \param this Puntero a pelicula
/// \param id variable que almacena id
/// \return retorna 1 en caso de exito y 0 en caso de error
int pel_getId(eMovie *this, int *id);

/// \brief Getter de titulo
///
/// \param this Puntero a pelicula
/// \param titulo variable que almacena titulo
/// \return retorna 1 en caso de exito y 0 en caso de error
int pel_getTitulo(eMovie *this, char *titulo);

/// \brief Getter de genero
///
/// \param this Puntero a pelicula
/// \param genero variable que almacena genero
/// \return retorna 1 en caso de exito y 0 en caso de error
int pel_getGenero(eMovie *this, char *genero);

/// \brief Getter de rating
///
/// \param this Puntero a pelicula
/// \param rating variable que almacena rating
/// \return retorna 1 en caso de exito y 0 en caso de error
int pel_getRating(eMovie *this, int *rating);

/// \brief Setter de titulo
///
/// \param this puntero a pelicula
/// \param titulo valor de titulo a cargar
/// \return retorna 1 en caso de exito y 0 en caso de error
int pel_setTitulo(eMovie *this, char *titulo);

/// \brief Setter de id
///
/// \param this puntero a pelicula
/// \param id valor de id a cargar
/// \return retorna 1 en caso de exito y 0 en caso de error
int pel_setId(eMovie *this, int id);

/// \brief Setter de rating
///
/// \param this puntero a pelicula
/// \param rating valor de rating a cargar
/// \return retorna 1 en caso de exito y 0 en caso de error
int pel_setRating(eMovie *this, int rating);

/// \brief Setter de genero
///
/// \param this puntero a pelicula
/// \param genero valor de genero a cargar
/// \return retorna 1 en caso de exito y 0 en caso de error
int pel_setGenero(eMovie *this, char *genero);

#endif /* eMovieS_H_ */
