#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
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
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;

		for(int i = 0; i < nodeIndex;i++)
		{
			if(pNode->pNextNode == NULL)
			{
				break;
			}

			pNode = pNode->pNextNode;
		}

	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;
    Node* pNuevoNode;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	pNuevoNode = (Node*) malloc(sizeof(Node));

    	if(pNuevoNode != NULL)
    	{
    		pNuevoNode->pElement = pElement;

    		if(nodeIndex == 0)
			{
    			pNuevoNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNuevoNode;
				returnAux = 0;

			}
			else
			{
				pNode = getNode(this,nodeIndex-1);
				if(pNode != NULL)
				{
					pNuevoNode->pNextNode = pNode->pNextNode;
					pNode->pNextNode = pNuevoNode;
					returnAux = 0;
				}

			}

    		this->size++;
    	}

    }

    return returnAux;
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
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this,ll_len(this),pElement);
    }

    return returnAux;
}

/** \brief Obtiene un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this,index);

    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    	}
    }

    return returnAux;
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
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this,index);

		if(pNode != NULL)
		{
			pNode->pElement = pElement;

			returnAux = 0;
		}

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode;
	Node* pAux;

	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		pNode = getNode(this,index);

		if(index != 0)
		{
			pAux = getNode(this,index-1);

			if(pNode != NULL && pAux != NULL)
			{
				pAux ->pNextNode = pNode ->pNextNode;
				free(pNode);
				this->size--;
				returnAux = 0;
			}

		}
		else
		{
			if(pNode != NULL)
			{
				this->pFirstNode = pNode->pNextNode;
				free(pNode);
				this->size--;
				returnAux = 0;
			}
		}
	}


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;



    if(this != NULL)
    {
    	len = ll_len(this);

    	if(len != -1)
    	{
    		while(len != 0)
			{
				ll_remove(this, len-1);
				len--;
			}

			returnAux = 0;
    	}


    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    int rta;

    if(this != NULL)
    {
    	rta = ll_clear(this);

    	if(rta != -1)
    	{
    		free(this);

    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    void* pElementAux;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(len != -1)
    	{
    		for(int i = 0; i < len; i++)
    		{
    			pElementAux = ll_get(this,i);

    			if(pElementAux == pElement)
    			{
    				returnAux = i;
    				break;
    			}

    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;

    	if(ll_len(this) == 0)
    	{
    		returnAux = 1;
    	}

    }

    return returnAux;
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
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	returnAux = addNode(this,index,pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this,index);

    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    		ll_remove(this,index);
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;

    if(this != NULL)
    {
    	index = ll_indexOf(this, pElement);

    	returnAux = 0;

    	if(index != -1)
    	{
    		returnAux = 1;
    	}

    }

    return returnAux;
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
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElement;
    int valida;
    int len;

    if(this != NULL && this2 != NULL)
    {
    	len = ll_len(this2);

    	if(len != -1)
    	{
    		returnAux = 1;

    		for(int i = 0; i < len; i++)
    		{
    			pElement = ll_get(this2, i);
    			valida = ll_contains(this,pElement);

    			if(valida != 1)
    			{
    				returnAux = 0;
    				break;
    			}

    		}

    	}

    }

    return returnAux;
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
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;

    if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for(int i = from; i < to; i++)
    		{
    			pElement = ll_get(this,i);

    			ll_add(cloneArray,pElement);

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
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(len != -1)
    	{
    		cloneArray = this;

    		if(len > 0)
    		{
    			cloneArray = ll_subList(this,0,len);
    		}
    	}
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElement;
    void* pElement2;
    int len;
    int valida;

    if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
        len = ll_len(this);
        if(len != -1)
        {
            if(order == 0)
            {
                for(int i = 0; i < len - 1; i++)
                {
                    for(int j = i+1; j < len; j++)
                    {
                        pElement = ll_get(this,i);
                        pElement2 = ll_get(this,j);

                        valida = pFunc(pElement,pElement2);

                        if(valida == -1)
                        {
                            ll_set(this, i, pElement2);
                            ll_set(this, j, pElement);
                        }
                    }
                }
            }
            else if (order == 1)
            {
                for(int i = 0; i < len - 1; i++)
                {
                    for(int j = i+1; j < len; j++)
                    {
                        pElement = ll_get(this,i);
                        pElement2 = ll_get(this,j);

                        valida = pFunc(pElement,pElement2);

                        if(valida == 1)
                        {
                            ll_set(this, i, pElement2);
                            ll_set(this, j, pElement);
                        }
                    }
                }
            }

            returnAux = 0;
        }
    }

    return returnAux;


}
