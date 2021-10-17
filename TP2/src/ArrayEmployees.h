/*
 * eEmployee.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Sergio
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include "utn.h"
#define EMPTY 0
#define FULL 1

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;


/// @fn int initEmployees(Employee*, int)
/// @brief Para indicar que todas las posiciones del array están vacías,
/// 		esta función pone la bandera (isEmpty) en EMPTY en todas las
/// 		posiciones del array
///
/// @param list -> Puntero al array de Empleados
/// @param len -> Tamaño del array
/// @return Retorna -1 (Error) o 0 (OK)
int initEmployees(Employee* list, int len);

/// @fn int VerificarListaEmpleados(Employee[], int)
/// @brief Verifica si la lista de empleados esta vacia
///
/// @param lista -> Array de empleados
/// @param tam -> Tamaño del array
/// @return Retorna 1 si encontro al menos un empleado, sino 0
int VerificarListaEmpleados(Employee lista[], int tam);

/// @fn int BuscarPrimerEspacioLibre(Employee*, int)
/// @brief Verifica si hay un espacio libre en el array
///
/// @param lista -> Array de empleados
/// @param tam -> Tamaño del array
/// @return Retorna 1 si encontro espacio, sino 0
int BuscarPrimerEspacioLibre(Employee* lista, int tam);

/// @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
/// @brief Agrega en un array de empleados existente los valores recibidos
/// 		como parámetro en la primer posición libre.
///
/// @param list -> Puntero al array de Empleados
/// @param len -> Tamaño del array
/// @param id -> ID del Empleado
/// @param name -> Nombre del empleado
/// @param lastName -> Apellido del empleado
/// @param salary -> Salario del empleado
/// @param sector -> Sector
/// @return Retorna -1 (Error) o 0 (OK)
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/// @fn int AgregarEmpleado(Employee*, int, int*)
/// @brief Pide los datos de un empleado y si encuentra lugar
/// 		en el array lo agrega
///
/// @param lista -> Array de empleados
/// @param tam -> tamaño del array
/// @param ultimoID -> Ultimo ID ingresado
/// @return Retorna 1 si pudo agregarlo, sino 0
int AgregarEmpleado(Employee* lista, int tam, int* ultimoID);

/// @fn int findEmployeeById(Employee*, int, int)
/// @brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
///
/// @param list -> Puntero al array de Empleados
/// @param len -> Tamaño del array
/// @param id -> ID del Empleado
/// @return Retorna -1 (Error) o indice del empleado
int findEmployeeById(Employee* list, int len,int id);

/// @fn int removeEmployee(Employee*, int, int)
/// @brief Elimina de manera lógica (isEmpty Flag en 1) un
/// 		empleado recibiendo como parámetro su Id.
///
/// @param list -> Puntero al array de Empleados
/// @param len -> Tamaño del array
/// @param id -> ID del Empleado
/// @return Retorna -1 (Error) o 0 (OK)
int removeEmployee(Employee* list, int len, int id);

/// @fn int EliminarEmpleado(Employee*, int)
/// @brief Pide el ID de un empleado y si lo encuentra lo elimina
///
/// @param lista -> Array de empleados
/// @param tam -> Tamaño del array
/// @return Retorna 1 si pudo eliminarlo y 0 sino pudo
int EliminarEmpleado(Employee* lista, int tam);

/// @fn int ModificarEmpleado(Employee*, int)
/// @brief Busca un empleado por id y permite modificar un campo
///
/// @param lista -> Array de empleados
/// @param tam -> Tamaño del array
/// @return Retorna 1 (OK), 0 (No pudo modificar) o -1 (Operacion cancelada)
int ModificarEmpleado(Employee* lista, int tam);

/// @fn int sortEmployees(Employee*, int, int)
/// @brief Ordena el array de empleados por apellido
/// 		y sector de manera ascendente o descendente.
///
/// @param list -> Puntero al array de Empleados
/// @param len -> Tamaño del array
/// @param order -> 1 (Orden Ascendente), 0 (Orden Descendente)
/// @return Retorna 0 (OK) o -1 (Error)
int sortEmployees(Employee* list, int len, int order);

/// @fn int MostrarUnEmpleado(Employee)
/// @brief Imprime un empleado por consola
///
/// @param empleado -> Estructura del empleado
/// @return Retorna 1 si pudo mostrarlo o 0 si no
int MostrarUnEmpleado(Employee empleado);

/// @fn int printEmployees(Employee*, int)
/// @brief Imprime el array de empleados de forma encolumnada.
///
/// @param list -> Puntero al array de Empleados
/// @param length -> Tamaño del array
/// @return Retorna 0 (OK) o -1 (Error)
int printEmployees(Employee* list, int length);

/// @fn int OrdenarEmpleados(Employee*, int)
/// @brief Consulta de que manera quiere ordenar la lista de empleados
/// 		y la ordena
///
/// @param lista -> Array de empleados
/// @param tam -> Tamaño del array
/// @return Retorna 1 si pudo ordenar, sino retorna 0
int OrdenarEmpleados(Employee* lista, int tam);

/// @fn int InformarTotalPromedioYSalariosMasAltos(Employee*, int)
/// @brief Informa el total de los salarios, salario promedio y
/// 		los empleados que superan el promedio
///
/// @param lista -> Array de empleados
/// @param tam -> Tamaño del array
/// @return Retorna 0 si no pudo informar, -1 (total = 0) o 1 si pudo hacerlo
int InformarTotalPromedioYSalariosMasAltos(Employee* lista, int tam);

#endif /* ARRAYEMPLOYEES_H_ */
