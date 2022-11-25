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

int controller_cargarDesdeTexto(char *path, LinkedList *pArrayList);

int controller_listarPeliculas(LinkedList *this);

int controller_asignarRating(LinkedList *this);

void controller_callbackMap(void *this);

int controller_asignarGenero(LinkedList *this);

int controller_listaFiltradaPorGenero(LinkedList *this, int generoSeleccionado,
		char *path);

int controller_guardarPeliculasModoTexto(char *path, LinkedList *pArrayList);

int controller_callbackFilterDrama(void *this);
int controller_callbackFilterTerror(void *this);
int controller_callbackFilterAccion(void *this);
int controller_callbackFilterComedia(void *this);

int controller_ordenarPeliculas(LinkedList *this);

#endif /* CONTROLLER_H_ */
