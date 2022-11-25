/*
 * menu.c
 *
 *  Created on: 5 Nov 2022
 *      Author: Julian
 */

#include "menu.h"

int menu_opciones(char *titulo, char *opciones, char *mensajeError, int min,
		int max) {
	int rtn = 0;
	int opcion;

	if (titulo != NULL && opciones != NULL && min > 0 && min < max) {
		printf("%s", titulo);
		printf("%s", opciones);

		if (utn_getNumero(&opcion, "\nIngrese la opcion: ", mensajeError, min,
				max, 1)) {
			rtn = opcion;
		}
	}

	return rtn;
}

int menu_confirmar(char *titulo, char *mensajeError, int *valorConfirmacion) {
	int rtn = 0;
	int auxConfirmacion;

	if (titulo != NULL && mensajeError != NULL) {
		utn_getNumero(&auxConfirmacion, titulo, mensajeError, 0, 1, 1);
		if (auxConfirmacion == 0 || auxConfirmacion == 1) {
			*valorConfirmacion = auxConfirmacion;
			rtn = 1;
		} else {
			rtn = -1;
		}

	}

	return rtn;
}

void menu_mostrarPosiciones(void) {
	puts(
			"\n POSICIONES:\n- DEFENSA CENTRAL\n- PORTERO\n- LATERAL IZQUIERDO\n- LATERAL DERECHO\n- PIVOTE\n- MEDIOCENTRO\n- EXTREMO IZQUIERDO\n- EXTREMO DERECHO\n- MEDIAPUNTA\n- DELANTERO CENTRO\n- MEDIOCENTRO OFENSIVO\n- INTERIOR DERECHO\n- INTERIOR IZQUIERDO\n");
}
