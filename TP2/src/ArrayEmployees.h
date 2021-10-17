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

/// @fn int sortEmployees(Employee*, int, int)
/// @brief Ordena el array de empleados por apellido
/// 		y sector de manera ascendente o descendente.
///
/// @param list -> Puntero al array de Empleados
/// @param len -> Tamaño del array
/// @param order -> 1 (Orden Ascendente), 0 (Orden Descendente)
/// @return Retorna 0 (OK) o -1 (Error)
int sortEmployees(Employee* list, int len, int order);

/// @fn int printEmployees(Employee*, int)
/// @brief Imprime el array de empleados de forma encolumnada.
///
/// @param list -> Puntero al array de Empleados
/// @param length -> Tamaño del array
/// @return Retorna 0 (OK) o -1 (Error)
int printEmployees(Employee* list, int length);

#endif /* ARRAYEMPLOYEES_H_ */
