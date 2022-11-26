/*
 * controller.c
 *
 *  Created on: 25 Nov 2022
 *      Author: Julian
 */

#include "controller.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "peliculas.h"
#include "callbacks.h"

int controller_cargarDesdeTexto(char *path, LinkedList *pArrayList) {
	int rtn = 0;

	FILE *pFile = fopen(path, "r");

	if (path != NULL && pArrayList != NULL) {
		if (pFile == NULL) {
			puts("\nERROR. No es posible abrir el archivo");
		} else {
			if (ll_isEmpty(pArrayList)) {
				if (parser_cargarDesdeTexto(pFile, pArrayList)) {
					printf("\nJugadores cargados con exito");
					rtn = 1;
				} else {
					puts("\nERROR. Ocurrio un error al cargar el archivo");
				}
			} else {
				rtn = -1;
				puts("\nLa lista no esta vacia.");
			}
		}
	}

	fclose(pFile);
	return rtn;
}

int controller_listarPeliculas(LinkedList *this) {
	int rtn = 0;

	int arrayTam;
	eMovie *pPelicula;
	eMovie auxPelicula;

	if (this != NULL) {
		arrayTam = ll_len(this);
		if (arrayTam != -1) {
			puts(
					"\n==============================================================================================================");
			printf("| %-5s  | %-30s | %-30s | %-8s |\n", "ID", "TITULO",
					"GENERO", "RATING");
			puts(
					"==============================================================================================================");

			for (int i = 0; i < arrayTam; i++) {
				pPelicula = (eMovie*) ll_get(this, i);

				if (pPelicula != NULL) {
					pel_getRating(pPelicula, &auxPelicula.rating);
					pel_getId(pPelicula, &auxPelicula.id);
					pel_getGenero(pPelicula, auxPelicula.genero);
					pel_getTitulo(pPelicula, auxPelicula.titulo);

					printf("| %-5d  | %-30s | %-30s | %-8d |\n", auxPelicula.id,
							auxPelicula.titulo, auxPelicula.genero,
							auxPelicula.rating);
					rtn = 1;
				}
			}
		}
	}

	return rtn;
}

int controller_asignarRating(LinkedList *this) {
	int rtn = 0;
	void (*pFunc)(void *element);

	if (this != NULL) {
		pFunc = callbackMap;
		this = ll_map(this, pFunc);
		rtn = 1;
	}

	controller_listarPeliculas(this);

	return rtn;
}

int controller_asignarGenero(LinkedList *this) {
	int rtn = 0;
	void (*pFunc)(void *element);

	if (this != NULL) {
		pFunc = callbackMapGeneros;
		this = ll_map(this, pFunc);
		rtn = 1;
	}

	return rtn;
}

int controller_guardarPeliculasModoTexto(char *path, LinkedList *pArrayList) {
	int rtn = 0;
	FILE *pFile;
	int tamArray;
	int i;
	eMovie auxPelicula;
	eMovie *pPelicula = NULL;
	if (path != NULL && pArrayList != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			fprintf(pFile, "id,titulo,genero,rating\n");
			tamArray = ll_len(pArrayList);
			for (i = 0; i < tamArray; i++) {
				pPelicula = (eMovie*) ll_get(pArrayList, i);
				if (pPelicula != NULL) {
					if (!(pel_getId(pPelicula, &auxPelicula.id)
							&& pel_getTitulo(pPelicula, auxPelicula.titulo)
							&& pel_getGenero(pPelicula, auxPelicula.genero)
							&& pel_getRating(pPelicula, &auxPelicula.rating))) {
						pPelicula = NULL;
						pel_delete(pPelicula);
						printf(
								"\nOcurrio un error el guardar daots en el archivo");
						break;
					} else {
						fprintf(pFile, "%d,%s,%s,%d\n", auxPelicula.id,
								auxPelicula.titulo, auxPelicula.genero,
								auxPelicula.rating);
						rtn = 1;
					}
				}
			}
		}
	}
	fclose(pFile);
	return rtn;
}

int controller_listaFiltradaPorGenero(LinkedList *this, int generoSeleccionado,
		char *path) {
	int rtn = 0;
	LinkedList *listaFiltrada = ll_newLinkedList();
	int (*pFunc)(void*);

	if (this != NULL) {
		switch (generoSeleccionado) {
		case 1:
			pFunc = callbackFilterDrama;
			break;
		case 2:
			pFunc = callbackFilterComedia;
			break;
		case 3:
			pFunc = callbackFilterAccion;
			break;
		case 4:
			pFunc = callbackFilterTerror;
			break;
		}

		listaFiltrada = ll_filter(this, pFunc);
	}

	if (controller_guardarPeliculasModoTexto(path, listaFiltrada)) {
		rtn = 1;
	}

	return rtn;
}

int controller_ordenarPeliculas(LinkedList *this) {
	int rtn = 0;
	int (*pFunc)(void*, void*);

	if (this != NULL) {
		pFunc = callbackOrdenarPorGenero;
		ll_sort(this, pFunc, 0);
		rtn = 1;
	}
	return rtn;
}

