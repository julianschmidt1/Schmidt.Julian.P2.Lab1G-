/*
 * callbacks.h
 *
 *  Created on: 25 Nov 2022
 *      Author: Julian
 */

#ifndef CALLBACKS_H_
#define CALLBACKS_H_

/// \brief Callback que filtra peliculas por genero drama
///
/// \param this Puntero a pelicula
/// \return 1 (EXITO) o 0 (ERROR / no coincidencia)
int callbackFilterDrama(void *this);

/// \brief Callback que filtra peliculas por genero terror
///
/// \param this Puntero a pelicula
/// \return 1 (EXITO) o 0 (ERROR / no coincidencia)
int callbackFilterTerror(void *this);

/// \brief Callback que filtra peliculas por genero accion
///
/// \param this Puntero a pelicula
/// \return 1 (EXITO) o 0 (ERROR / no coincidencia)
int callbackFilterAccion(void *this);

/// \brief Callback que filtra peliculas por genero comedia
///
/// \param this Puntero a pelicula
/// \return 1 (EXITO) o 0 (ERROR / no coincidencia)
int callbackFilterComedia(void *this);

/// \brief Callback que asigna valor aleatorio de rating
///
/// \param this puntero a elemento
void callbackMap(void *this);

/// \brief  Callback que asigna valor aleatorio de genero en base a un numero
///
/// \param this puntero a elemento
void callbackMapGeneros(void *this);

/// \brief Funcion que devuelve un valor dependiendo de el orden de las peliculas, con criterio por genero y luego por rating
///
/// \param pPrimerPelicula puntero a pelicula
/// \param pSegundoPelicula puntero a pelicula
/// \return Retorna 1 en caso de estar ordenados, -1 en caso de desordenados, y 0 en caso de igualdad o error
int callbackOrdenarPorGenero(void *pPrimerPelicula, void *pSegundoPelicula);

#endif /* CALLBACKS_H_ */
