/*
 * inputs.c
 *
 *  Created on: 5 Nov 2022
 *      Author: Julian
 */

#include "inputs.h"

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 si la cadena es numerica y 0 si no lo es
 */
static int esNumerica(char *cadena);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int *pResultado);

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int myGets(char *cadena, int longitud);

/**
 * \brief Verifica si la cadena ingresada es un numero decimal
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 si la cadena es un numero decimal y 0 si no lo es
 */
static int esNumeroDecimal(char *cadena);

/**
 * \brief Verifica si la cadena ingresada es decimal
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero decimal y -1 (ERROR) si no
 *
 */
static int getFloat(float *pResultado);

/// \brief Funcion que solicita la carga al usuario y valida que sea un nombre / nombre de usuario aceptable
///
/// \param pResultado Puntero al espacio en memoria en donde se almacenara el resultado
/// \param longitud longitud de la cadena
/// \return Retorna 0 en caso de exito y -1 en caso de error
static int getNombre(char *pResultado, int longitud);

int myGets(char *cadena, int longitud) {
	int rtn;
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		rtn = 0;
	}
	return rtn;
}

static int getInt(int *pResultado) {
	int rtn = 0;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			rtn = 1;
		}
	}
	return rtn;
}

static int getFloat(float *pResultado) {
	int rtn = 0;
	char buffer[64];

	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumeroDecimal(buffer)) {

			for (int i = 0; i < sizeof(buffer); i++) {
				if (buffer[i] == ',') {
					buffer[i] = '.';
				}
			}

			*pResultado = atof(buffer);
			rtn = 1;
		}
	}
	fflush(stdin); //Windows
	return rtn;
}

static int esNumeroDecimal(char *cadena) {
	int rtn = 1;
	int i = 0;
	int contadorPuntosComas = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] == '.' || cadena[i] == ',') {
				contadorPuntosComas++;
			}
			if (cadena[i] < ',' || cadena[i] > '9' || cadena[i] == '-'
					|| cadena[i] == '/' || cadena[0] < '0' || cadena[0] > '9'
					|| contadorPuntosComas > 1) {
				rtn = 0;
				break;
			}
			i++;
		}
	}
	return rtn;
}

static int esNumerica(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int utn_getNumeroDecimal(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {
	float bufferFloat;
	int rtn = 0;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 1) {
			if (bufferFloat >= minimo && bufferFloat <= maximo) {
				*pResultado = bufferFloat;
				rtn = 1;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return rtn;
}

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int bufferInt;
	int rtn = 0;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 1) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				rtn = 1;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return rtn;
}

int getString(char *cadena, int longitud) {
	int retorno = -1;
	char bufferString[4096];

	if (cadena != NULL && longitud > 0) {
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

static int getNombre(char *pResultado, int longitud) {
	int retorno = -1;
	char buffer[4096];

	if (pResultado != NULL) {
		if (getString(buffer, sizeof(buffer)) == 0
				&& esNombre(buffer, sizeof(buffer))
				&& strnlen(buffer, sizeof(buffer)) < longitud) {
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

int esNombre(char *cadena, int longitud) {
	int i = 0;
	int retorno = 1;

	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')
					&& (cadena[i] != ' ' || cadena[0] == ' ')) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getString(char *mensaje, char *mensajeError, int reintentos,
		int longitud, char *pResultado) {
	char bufferString[4096];
	int retorno = -1;
	while (reintentos >= 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getNombre(bufferString, sizeof(bufferString)) == 0
				&& strnlen(bufferString, sizeof(bufferString)) < longitud
				&& strlen(bufferString) > 0) {
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}
