/*
 * parser.c
 *
 *  Created on: 25 Nov 2022
 *      Author: Julian
 */

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

//cambiar
#include "peliculas.h"

int parser_cargarDesdeTexto(FILE *pFile, LinkedList *pArrayList) {
	int rtn = 0;

	char buffer[4][150];
	eMovie *pPelicula;

	if (pFile != NULL && pArrayList != NULL) {
		// Cargamos cabecera
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],
				buffer[2], buffer[3]);

		do {
			// Cargamos datos
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],
					buffer[1], buffer[2], buffer[3]) < 4) {
				break;
			} else {
				pPelicula = pel_newParametros(buffer[0], buffer[1], buffer[2],
						buffer[3]);
				if (pPelicula == NULL) {
					break;
				} else {
					ll_add(pArrayList, (eMovie*) pPelicula);
					rtn = 1;
				}
			}
		} while (feof(pFile) == 0);
	}

	return rtn;
}
