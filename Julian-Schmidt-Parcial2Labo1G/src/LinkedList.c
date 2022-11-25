#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList *this, int nodeIndex); //NO SE TOCA WACHIN
static int addNode(LinkedList *this, int nodeIndex, void *pElement); //NO SE TOCAN

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {
	LinkedList *this = NULL;

	this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL) {
		this->pFirstNode = NULL;
		this->size = 0;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList *this) {
	int rtn = -1;
	if (this != NULL) {
		rtn = this->size;
	}
	return rtn;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList *this, int nodeIndex) {
	Node *pNodo = NULL;
	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) {
		pNodo = this->pFirstNode;

		while (nodeIndex > 0) {
			pNodo = pNodo->pNextNode;
			nodeIndex--;
		}

	}
	return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList *this, int nodeIndex) //NO SE TOCA WACHIN
{
	return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	int rtn = -1;
	Node *nuevoNodo = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) {
		nuevoNodo = (Node*) malloc(sizeof(Node));
		if (nuevoNodo != NULL) {
			nuevoNodo->pElement = pElement;
			nuevoNodo->pNextNode = getNode(this, nodeIndex);
			if (nodeIndex == 0) {
				this->pFirstNode = nuevoNodo;
			} else {
				(getNode(this, nodeIndex - 1))->pNextNode = nuevoNodo;
			}
			this->size++;
			rtn = 0;
		}
	}
	return rtn;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement) {
	int rtn = -1;
	if (this != NULL) {
		if (!addNode(this, ll_len(this), pElement)) {
			rtn = 0;
		}
	}
	return rtn;
}

/** \Devuelve el elemento guardado en la lista en el indice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList *this, int index) {
	void *rtn = NULL;
	if (this != NULL && index >= 0 && index < ll_len(this)) {
		if (getNode(this, index) != NULL) {
			rtn = (getNode(this, index))->pElement;
		}
	}
	return rtn;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList *this, int index, void *pElement) {
	int rtn = -1;
	if (this != NULL && index >= 0 && index < ll_len(this)) {
		if (ll_len(this) == index) {
			if (!ll_add(this, pElement)) {
				rtn = 0;
			}
		} else {
			getNode(this, index)->pElement = pElement;
			rtn = 0;
		}
	}
	return rtn;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index) {
	int rtn = -1;
	Node *auxNode = NULL;
	Node *prevNode;
	if (this != NULL && index >= 0 && index < ll_len(this)) {
		auxNode = getNode(this, index);
		if (index == 0) {
			this->pFirstNode = auxNode->pNextNode;
		} else {
			prevNode = getNode(this, index - 1);
			prevNode->pNextNode = auxNode->pNextNode;
		}
		free(auxNode);
		this->size--;
		rtn = 0;
	}
	return rtn;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this) {
	int rtn = -1;
	if (this != NULL) {
		while (ll_len(this) != 0) {
			ll_remove(this, 0);
		}
		rtn = 0;
	}
	return rtn;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList *this) {
	int rtn = -1;
	if (!ll_clear(this)) {
		free(this);
		rtn = 0;
	}
	return rtn;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement) {
	int rtn = -1;
	if (this != NULL) {
		int tam = ll_len(this);
		for (int i = 0; i < tam; i++) {
			if (ll_get(this, i) == pElement) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList *this) {
	int rtn = -1;
	if (this != NULL) {
		rtn = 1;
		if (ll_len(this) > 0) {
			rtn = 0;
		}
	}
	return rtn;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList *this, int index, void *pElement) {
	return addNode(this, index, pElement);
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList *this, int index) {
	void *rtn = NULL;
	if (this != NULL && index >= 0 && index < ll_len(this)) {
		rtn = ll_get(this, index);
		ll_remove(this, index);
	}
	return rtn;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList *this, void *pElement) {
	int rtn = -1;
	if (this != NULL) {
		rtn = 0;
		if (ll_indexOf(this, pElement) != -1) {
			rtn = 1;
		}
	}
	return rtn;
}

/** \brief  Determina si todos los elementos de la lista (this2)
 estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
 ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
 ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int rtn = -1;
	int tam;
	if (this != NULL && this2 != NULL) {
		tam = ll_len(this2);
		rtn = 1;
		for (int i = 0; i < tam; i++) {
			if (!ll_contains(this, ll_get(this2, i))) {
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 o (si el indice from es menor a 0 o mayor al len de la lista)
 o (si el indice to es menor o igual a from o mayor al len de la lista)
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	if (this != NULL && from >= 0 && from < ll_len(this) && to > from
			&& to <= ll_len(this)) {
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL) {
			for (int i = from; i < to; i++) {
				ll_add(cloneArray, ll_get(this, i));
			}
		}
	}
	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList *this) {
	return ll_subList(this, 0, ll_len(this));
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 ( 0) Si ok
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int rtn = -1;
	int tam;
	int i;
	int j;
	void *auxPrimerIndice = NULL;
	void *auxSegundoIndice = NULL;
	void *aux = NULL;
	if (this != NULL && pFunc != NULL && order >= 0 && order <= 1) {
		tam = ll_len(this);
		for (i = 0; i < tam - 1; i++) {
			for (j = i + 1; j < tam; j++) {
				auxPrimerIndice = ll_get(this, i);
				auxSegundoIndice = ll_get(this, j);
				if ((pFunc(auxPrimerIndice, auxSegundoIndice) > 0 && order)
						|| (pFunc(auxPrimerIndice, auxSegundoIndice) < 0
								&& !order)) {
					aux = auxPrimerIndice;
					ll_set(this, i, auxSegundoIndice);
					ll_set(this, j, aux);
				}
			}
		}
		rtn = 0;
	}
	return rtn;
}

/// \brief Filtra los elementos que cumplan con el criterio
///
/// \param this Puntero a la lista
/// \param pFunc (*pFunc) puntero a la funcion criterio
/// \return Retorna la LinkedList filtrada en caso de exito y NULL en caso de un error
LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void*)) {
	void *pAux = NULL;
	int tam;
	LinkedList *listaFiltrada = NULL;

	if (this != NULL && pFunc != NULL) {
		listaFiltrada = ll_newLinkedList();
		if (listaFiltrada != NULL) {
			tam = ll_len(this);
			for (int i = 0; i < tam; i++) {
				pAux = ll_get(this, i);
				if (pFunc(pAux)) {
					if (ll_add(listaFiltrada, pAux)) {
						ll_deleteLinkedList(listaFiltrada);
						listaFiltrada = NULL;
						break;
					}
				}
			}
		}
	}

	return listaFiltrada;
}

LinkedList* ll_map(LinkedList *this, void (*pFunc)(void *element)) {
	int lenList;
	void *auxElement;

	if (this != NULL && pFunc != NULL) {
		lenList = ll_len(this);
		if (lenList > 0) {
			for (int i = 0; i < lenList; i++) {
				auxElement = ll_get(this, i);
				if (auxElement != NULL) {
					pFunc(auxElement);
				}
			}

		}

	}

	return this;
}

