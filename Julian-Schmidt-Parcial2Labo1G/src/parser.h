/*
 * parser.h
 *
 *  Created on: 25 Nov 2022
 *      Author: Julian
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/// \brief Funcion que guarda un LinkedList en un archivo de texto
///
/// \param pFile Puntero a archivo
/// \param pArrayList Listado a guardar
/// \return retorna 1 en caso de exito y 0 en caso de error
int parser_cargarDesdeTexto(FILE *pFile, LinkedList *pArrayList);

#endif /* PARSER_H_ */
