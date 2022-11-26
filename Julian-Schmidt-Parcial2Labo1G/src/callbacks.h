/*
 * callbacks.h
 *
 *  Created on: 25 Nov 2022
 *      Author: Julian
 */

#ifndef CALLBACKS_H_
#define CALLBACKS_H_

int callbackFilterDrama(void *this);
int callbackFilterTerror(void *this);
int callbackFilterAccion(void *this);
int callbackFilterComedia(void *this);
void callbackMap(void *this);
void callbackMapGeneros(void *this);
int callbackOrdenarPorGenero(void *pPrimerPelicula, void *pSegundoPelicula);

#endif /* CALLBACKS_H_ */
