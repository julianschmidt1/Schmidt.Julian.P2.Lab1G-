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

int controller_listarPeliculas(LinkedList *this);

int controller_asignarRating(LinkedList *this);

int controller_asignarGenero(LinkedList *this);

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

int controller_ordenarPeliculas(LinkedList *this);

#endif /* CONTROLLER_H_ */
