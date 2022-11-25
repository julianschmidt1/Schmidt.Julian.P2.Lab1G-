/*
 * inputs.h
 *
 *  Created on: 5 Nov 2022
 *      Author: Julian
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Solicita un numero decimal al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);

/// \brief Solicita una cadena de caracteres
///
/// \param cadena Puntero al espacio en memoria en donde se almacenara el resultado
/// \param longitud longitud de la cadena
/// \return retorna 0 si se pudo guardar la cadena, y 0 si ocurrio un error
int getString(char *cadena, int longitud);

/// \brief Evalua una cadena, comprobando que los caracteres son apropiados para un nombre / nombre de usuario convencional
///
/// \param cadena Puntero al espacio en memoria en donde se almacenara el resultado
/// \param longitud longitud de la cadena
/// \return Retorna 1 en caso de exito, y 0 en caso de error
int esNombre(char *cadena, int longitud);

/// \brief Funcion que muestra un mensaje y permite la carga de una cadena de caracteres validada
///
/// \param mensaje Mensaje a mostrar al usuario
/// \param mensajeError Mensaje en caso de error
/// \param reintentos Cantidad de veces en que el usuario puede reingresar el valor en caso de error
/// \param longitud longitud de la cadena
/// \param pResultado Puntero al espacio en memoria en donde se almacenara el resultado
/// \return retorna 0 en caso de exito y -1 en caso de error
int utn_getString(char *mensaje, char *mensajeError, int reintentos,
		int longitud, char *pResultado);

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 1 si se obtuvo el numero y 0 si no
 */
int utn_getNumeroDecimal(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

#endif /* INPUTS_H_ */
