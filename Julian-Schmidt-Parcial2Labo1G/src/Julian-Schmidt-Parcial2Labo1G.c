/*
 ============================================================================
 Name        : Julian-Schmidt-Parcial2Labo1G.c
 Author      : Julián Schmidt
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "menu.h"
#include "inputs.h"
#include "controller.h"
#include "time.h"

int main(void) {
	setbuf(stdout, NULL);
	srand(time(NULL));
	LinkedList *listaPeliculas = ll_newLinkedList();
	int menuPrincipal;
	char nombreArchivo[30];
	int generoSeleccionado;

	do {
		menuPrincipal = menu_opciones(
				"\n\n ------- PARCIAL 2 LABORATORIO  ------- \n",
				"\n1. CARGAR ARCHIVO"
						"\n2. IMPRIMIR LISTA"
						"\n3. ASIGNAR RATING"
						"\n4. ASIGNAR GENERO"
						"\n5. FILTRAR POR GENERO"
						"\n6. ORDENAR PELICULAS"
						"\n7. GUARDAR PELICULAS"
						"\n8. SALIR", "\nOpcion invalida. Ingrese la opcion: ",
				1, 11);

		switch (menuPrincipal) {
		case 1:

			if (utn_getString("\nIngrese el nombre del archivo: ",
					"\nNombre invalido. ", 1, 30, nombreArchivo) == 0) {
				strcat(nombreArchivo, ".csv");
				controller_cargarDesdeTexto(nombreArchivo, listaPeliculas);
			}
			break;
		case 2:
			if (!ll_isEmpty(listaPeliculas)) {
				controller_listarPeliculas(listaPeliculas);
			} else {
				puts("\n la lista esta vacia");
			}
			break;
		case 3:
			if (!ll_isEmpty(listaPeliculas)) {
				controller_asignarRating(listaPeliculas);
			} else {
				puts("\n la lista esta vacia");
			}
			break;
		case 4:
			if (!ll_isEmpty(listaPeliculas)) {
				controller_asignarGenero(listaPeliculas);
			} else {
				puts("\n la lista esta vacia");
			}
			break;
		case 5:
			if (utn_getNumero(&generoSeleccionado,
					"\nIngrese la opcion de genero: (1. Drama | 2. Comedia | 3. Accion | 4. Terror",
					"\nOpcion invalida", 1, 4, 1)) {
				controller_listaFiltradaPorGenero(listaPeliculas,
						generoSeleccionado, "peliculasFiltradas.csv");
			}
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		}

	} while (menuPrincipal != 8);

	return EXIT_SUCCESS;
}
