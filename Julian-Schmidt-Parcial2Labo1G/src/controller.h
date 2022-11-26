/*
 * controller.h
 *
 *  Created on: 25 Nov 2022
 *      Author: Julian
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "parser.h"

/** \brief Carga los datos desde el archivo (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int retorna 1 en caso de exito, 0 en caso de error y -1 en caso de que la lista tenga datos
 *
 */
int controller_cargarDesdeTexto(char *path, LinkedList *pArrayList);

/// \brief Listado de peliculas
///
/// \param this Lista a mostrar
/// \return Retorna 1 en caso de exito y 0 en caso de error
int controller_listarPeliculas(LinkedList *this);

/// \brief Funcion que llama a map para asignar un rating aleatorio a la estructura pelicula
///
/// \param this Puntero a pelicula
/// \return Retorna 1 en caso de exito y 0 en caso de error
int controller_asignarRating(LinkedList *this);

/// \brief Funcion que llama a map para asignar un genero aleatorio a la estructura pelicula
///
/// \param this Puntero a pelicula
/// \return retorna 1 en caso de exito y 0 en caso de error
int controller_asignarGenero(LinkedList *this);

/// \brief Crea un nuevo listado en base al criterio de filtrado seleccionado
///
/// \param this Lista de peliculas
/// \param generoSeleccionado valor entero que determina genero
/// \param path ruta al archivo
/// \return retorna 1 en caso de poder crear el archivo filtrado y 0 en caso de error
int controller_listaFiltradaPorGenero(LinkedList *this, int generoSeleccionado,
		char *path);

/** \brief Guarda los datos de los peliculas en el archivo(modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListSeleccion LinkedList*
 * \return int retorna 1 en caso de exito y 0 en caso de error
 *
 */
int controller_guardarPeliculasModoTexto(char *path, LinkedList *pArrayList);

/// \brief Funcion que ordena peliculas por el criterio descendente
///
/// \param this lista de peliculas
/// \return retorna 1 en caso de exito y 0 en caso de error
int controller_ordenarPeliculas(LinkedList *this);

#endif /* CONTROLLER_H_ */
