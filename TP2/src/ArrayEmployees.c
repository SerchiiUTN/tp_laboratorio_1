/*
 * eEmployee.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Sergio
 */

#include "ArrayEmployees.h"



int initEmployees(Employee* list, int len)
{
	int retorno;
	int i;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = EMPTY;
		}
		retorno = 0;
	}


	return retorno;
}

int VerificarListaEmpleados(Employee lista[], int tam)
{
	int retorno;

	retorno = 0;

	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == FULL)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int BuscarPrimerEspacioLibre(Employee* lista, int tam)
{
	int index;
	int i;

	index = -1;

	if(lista != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == EMPTY)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno;
	int index;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		index = BuscarPrimerEspacioLibre(list, len);

		if(index != -1)
		{
			list[index].id = id;
			strcpy(list[index].name, name);
			strcpy(list[index].lastName, lastName);
			list[index].salary = salary;
			list[index].sector = sector;
			list[index].isEmpty = FULL;
			retorno = 0;
		}
	}

	return retorno;
}

int AgregarEmpleado(Employee* lista, int tam, int* ultimoID)
{
	int retorno;
	int idAux;
	int retornoAuxiliar;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;

	retorno = 0;
	idAux = *ultimoID;

	if
	(
		lista != NULL && tam > 0 &&
		utn_PedirNombreOApellido(nombre, sizeof(nombre), "Ingrese el nombre del empleado : ", "Error, intente nuevamente", 2) == 1 &&
		utn_PedirNombreOApellido(apellido, sizeof(apellido), "Ingrese el apellido del empleado : ", "Error, intente nuevamente", 2) == 1 &&
		utn_PedirFlotante(&salario, "Ingrese el salario del empleado : ", "El valor ingresado no es valido", 0, 1000000, 2) == 1 &&
		utn_PedirEntero(&sector, "Ingrese el numero del sector del empleado : ", "El valor ingresado no es valido", 0, 10000, 2) == 1
	)
	{
		idAux++;
		retornoAuxiliar = addEmployee(lista, tam, idAux, nombre, apellido, salario, sector);

		if(retornoAuxiliar == 0)
		{
			*ultimoID = idAux;
			retorno = 1;
		}
	}


	return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int index;
	int i;

	index = -1;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].id == id && list[i].isEmpty == FULL)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno;
	int index;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		index = findEmployeeById(list, len, id);

		if(index != -1)
		{
			list[index].isEmpty = EMPTY;
			retorno = 0;
		}
	}

	return retorno;
}

int EliminarEmpleado(Employee* lista, int tam)
{
	int retorno;
	int id;

	retorno = 0;

	if(lista != NULL && tam > 0 && utn_PedirEntero(&id, "Ingrese el ID del empleado que desea eliminar : ", "El valor ingresado es incorrecto", 1, tam, 2) == 1)
	{
		if(removeEmployee(lista, tam, id) == 0)
		{
			retorno = 1;
		}
	}

	return retorno;
}

int ModificarEmpleado(Employee* lista, int tam)
{
	int retorno;
	int index;
	int id;
	int opcion;

	retorno = 0;

	if(lista != NULL && tam > 0 && utn_PedirEntero(&id, "Ingrese el ID del empleado que desea modificar : ", "El valor ingresado es incorrecto", 1, tam, 2) == 1)
	{
		index = findEmployeeById(lista, tam, id);

		if(index != -1)
		{
			printf("\n¿Que desea modificar?\n1 - Nombre\n2 - Apellido\n3 - Salario\n4 - Sector\n0 - Cancelar\n");

			if(utn_PedirEntero(&opcion, "Elija una opcion : ", "La opcion ingresada es incorrecta", 0, 4, 2) == 1)
			{
				switch(opcion)
				{
					case 1:
						if(utn_PedirNombreOApellido(lista[index].name, sizeof(lista[index].name), "Ingrese el nombre del empleado : ", "Error, intente nuevamente", 2) == 1)
						{
							retorno = 1;
						}
					break;
					case 2:
						if(utn_PedirNombreOApellido(lista[index].lastName, sizeof(lista[index].lastName), "Ingrese el apellido del empleado : ", "Error, intente nuevamente", 2) == 1)
						{
							retorno = 1;
						}
					break;
					case 3:
						if(utn_PedirFlotante(&lista[index].salary, "Ingrese el salario del empleado : ", "El valor ingresado no es valido", 0, 1000000, 2) == 1)
						{
							retorno = 1;
						}
					break;
					case 4:
						if(utn_PedirEntero(&lista[index].sector, "Ingrese el numero del sector del empleado : ", "El valor ingresado no es valido", 0, 10000, 2) == 1)
						{
							retorno = 1;
						}
					break;
					case 0:
						retorno = -1;
					break;

				}
			}
		}
	}

	return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	int retorno;
	Employee auxiliar;
	int i;
	int j;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len-1; i++)
		{
			for(j = i+1; j < len; j++)
			{
				if(order == 1)
				{
					if
					(
						list[i].lastName > list[j].lastName ||
						(
							list[i].lastName == list[j].lastName &&
							list[i].lastName > list[j].lastName
						)
					)
					{
						auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
					retorno = 0;
					}
				}

				if(order == 2)
				{
					if
					(
						list[i].lastName < list[j].lastName ||
						(
							list[i].lastName == list[j].lastName &&
							list[i].lastName < list[j].lastName
						)
					)
					{
						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
						retorno = 0;
					}
				}


			}
		}
	}

	return retorno;
}

int MostrarUnEmpleado(Employee empleado)
{
	int retorno;

	retorno = 0;

	if(empleado.isEmpty == FULL)
	{
		printf("%-4d | %-32s | %-32s | %10.2f | %d \n",empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);
		retorno = 1;
	}

	return retorno;
}


int printEmployees(Employee* list, int length)
{
	int retorno;

	retorno = -1;

	if(list != NULL && length > 0)
	{
		printf("\nEmpleados activos: \n");
		printf("N°   | Nombre  \t  \t  \t \t| Apellido\t \t \t   |   Salario  | Sector\n");
		printf("-----+----------------------------------+----------------------------------+------------+---------\n");
		for(int i = 0; i < length; i++)
		{
			if(list[i].isEmpty == FULL)
			{
				MostrarUnEmpleado(list[i]);
			}

		}
		retorno = 0;
	}

	return retorno;
}
