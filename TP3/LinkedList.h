/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); //crea una nueva linkedlist
int ll_len(LinkedList* this); //Devuelve el largo del linkedlist
Node* test_getNode(LinkedList* this, int nodeIndex); //
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement); //Agrega un elemento al linkedlist
void* ll_get(LinkedList* this, int index); //Obtiene un elemento del linkedlist
int ll_set(LinkedList* this, int index,void* pElement); //Modifica un elemento
int ll_remove(LinkedList* this,int index); // Elimina un elemento de la lista
int ll_clear(LinkedList* this); // Elimina todos los elementos de la lista
int ll_deleteLinkedList(LinkedList* this); // Elimina la lista
int ll_indexOf(LinkedList* this, void* pElement); //Busca un elemento y devuelve el indice
int ll_isEmpty(LinkedList* this); // Verifica si la lista esta vacia
int ll_push(LinkedList* this, int index, void* pElement); // Agrega un elemento dentro de la lista
void* ll_pop(LinkedList* this,int index); // Extrae el elemento de la lista
int ll_contains(LinkedList* this, void* pElement); // Verifica si contiene un elemento en una lista
int ll_containsAll(LinkedList* this,LinkedList* this2); // Verifica si una lista contiene los elementos de otra
LinkedList* ll_subList(LinkedList* this,int from,int to); // Crea una lista com parte de otra
LinkedList* ll_clone(LinkedList* this); // Clona una lista
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); // Ordena una lista por un criterio
