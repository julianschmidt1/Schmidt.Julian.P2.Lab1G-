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

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int retorna 1 en caso de exito, 0 en caso de error y -1 en caso de que la lista tenga datos
 *
 */
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
		pFunc = controller_callbackMap;
		this = ll_map(this, pFunc);
		rtn = 1;
	}

	controller_listarPeliculas(this);

	return rtn;
}

void controller_callbackMap(void *this) {
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

void controller_callbackMapGeneros(void *this) {
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

int controller_asignarGenero(LinkedList *this) {
	int rtn = 0;
	void (*pFunc)(void *element);

	if (this != NULL) {
		pFunc = controller_callbackMapGeneros;
		this = ll_map(this, pFunc);
		rtn = 1;
	}

	return rtn;
}

int controller_callbackFilterDrama(void *this) {
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

int controller_callbackFilterTerror(void *this) {
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

int controller_callbackFilterAccion(void *this) {
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

int controller_callbackFilterComedia(void *this) {
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

/** \brief Guarda los datos de los peliculas en el archivo jugadores.csv (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListSeleccion LinkedList* array de selecciones
 * \return int retorna 1 en caso de exito y 0 en caso de error
 *
 */
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
			pFunc = controller_callbackFilterDrama;
			break;
		case 2:
			pFunc = controller_callbackFilterComedia;
			break;
		case 3:
			pFunc = controller_callbackFilterAccion;
			break;
		case 4:
			pFunc = controller_callbackFilterTerror;
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
		pFunc = pel_ordenarPorGenero;
		ll_sort(this, pFunc, 1);
		rtn = 1;
	}
	return rtn;
}

