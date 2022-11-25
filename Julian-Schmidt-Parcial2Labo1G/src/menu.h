/*
 * menu.h
 *
 *  Created on: 5 Nov 2022
 *      Author: Julian
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

/// \brief Funcion que muestra la interfaz de un menu
///
/// \param titulo Cabecera a mostrar
/// \param opciones opciones enumeradas a seleccionar
/// \param mensajeError mensaje a mostrar en caso de error
/// \param min valor minimo aceptado como opcion
/// \param max valor maximo aceptado como opcion
/// \return Retorna la opcion seleccionada en caso de exito y 0 en caso de error
int menu_opciones(char *titulo, char *opciones, char *mensajeError, int min,
		int max);

/// \brief Funcion que muestra un menu de confirmacion
///
/// \param titulo Mensaje a mostrar
/// \param mensajeError Mensaje ante caso de error
/// \param valorConfirmacion puntero al valor que determina la confirmacion
/// \return Retorna 1 en caso de exito, 0 en caso de que algun puntero sea invalido, y -1 si la opcion es incorrecta
int menu_confirmar(char *titulo, char *mensajeError, int *valorConfirmacion);

/// \brief Muestra posiciones disponibles validadas
///
void menu_mostrarPosiciones(void);

#endif /* MENU_H_ */
