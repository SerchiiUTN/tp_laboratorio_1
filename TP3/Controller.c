#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Employee.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	int respuesta;
	FILE* pArchivo;
	retorno = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		retorno = 0;
		if(ll_isEmpty(pArrayListEmployee) == 0)
		{
			retorno = utn_PedirEntero(&respuesta, "ATENCION: Hay un archivo de empleados creado. ¿Desea sobreescribirla?\n1. Si\n2.No\nRespuesta: ", "Dato no valido.", 1, 2, 5);
			if (retorno == 1 && respuesta == 1)
			{
				ll_clear(pArrayListEmployee);
				retorno = 0;
			} else {
				retorno = -1;
			}
		}

		if (retorno == 0) {
			pArchivo = fopen(path, "r");
			if (pArchivo != NULL) {
				retorno = parser_EmployeeFromText(pArchivo, pArrayListEmployee);
				if (retorno == -1 && ll_isEmpty(pArrayListEmployee) == 0) {
					ll_clear(pArrayListEmployee);
				}
			} else {
				retorno = -1;
				printf("Archivo no encontrado.");
			}
		    fclose(pArchivo);
		}

	}

    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	int respuesta;
	FILE* pArchivo;
	retorno = -1;

	if (path != NULL && pArrayListEmployee != NULL) {
		retorno = 0;
		if (ll_isEmpty(pArrayListEmployee) == 0) {
			retorno = utn_PedirEntero(&respuesta, "ATENCION: Hay un archivo de empleados creado. ¿Desea sobreescribirla?\n1. Si\n2.No\nRespuesta: ", "Dato no valido.", 1, 2, 5);
			if (retorno == 1 && respuesta == 1) {
				ll_clear(pArrayListEmployee);
				retorno = 0;
			} else {
				retorno = -1;
			}
		}

		if (retorno == 0) {
			pArchivo = fopen(path, "rb");
			if (pArchivo != NULL) {
				retorno = parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
				if (retorno == -1 && ll_isEmpty(pArrayListEmployee) == 0) {
					ll_clear(pArrayListEmployee);
				}
			} else {
				retorno = -1;
				printf("Archivo no encontrado.");
			}
		    fclose(pArchivo);
		}

	}

    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int ultimoId;
	Employee* pEmpleado;
	retorno = -1;

	if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
	{
		ultimoId = parser_LoadIDFromText();

		if(ultimoId != -1)
		{
			pEmpleado = employee_AddNewEmployee(ultimoId);

			if(pEmpleado != NULL)
			{
				retorno = ll_add(pArrayListEmployee, pEmpleado);

				if(retorno == 0)
				{
					employee_saveID(ultimoId);

				}
				else
				{
					employee_delete(pEmpleado);
				}
			}
		}
	}
	else
	{
		printf("Primero debe abrir la lista de empleados");
	}

    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int id;
	Employee* pEmpleado;
	Employee* pAux;
	retorno = -1;

	if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
	{
		employee_listEmployees(pArrayListEmployee);

		printf("\n");

		retorno = utn_PedirEntero(&id, "Ingrese el ID del empleado a modificar: ","Dato incorrecto",1,2000000,2);
		if(retorno == 1)
		{
			pEmpleado = employee_findEmployeeById(pArrayListEmployee, id);
			if (pEmpleado != NULL) {
				printf("----Empleado a modificar----\n");
				printf("ID   - Nombre                          - HorasTrabajadas - Sueldo\n");
				employee_showEmployee(pEmpleado);

				pAux = employee_copyEmployeeToEmployeeAux(pEmpleado);

				if(pAux != NULL)
				{
					retorno = employee_editEmployee(pArrayListEmployee, pEmpleado, pAux);

					if (retorno == -1 || retorno == -2) {
						employee_delete(pAux);
						if(retorno == -1)
						{
							printf("No se pudo modificar el empleado correctamente.");
						}
					}
				}
				else
				{
					retorno = -1;
				}
			}
			else
			{
				printf("Empleado a modificar no encontrado.");
				retorno = -1;
			}
		} else {
			retorno = -1;
		}
	} else {
		printf("Primero debe abrir la lista de empleados");
	}

    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int index;
	int id;
	Employee* pEmpleado;
	retorno = -1;

	if (pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
	{
		employee_listEmployees(pArrayListEmployee);
		printf("\n");
		retorno = utn_PedirEntero(&id, "Ingrese el ID del empleado a remover: ","Dato incorrecto",1,20000000,2);
		if(retorno == 1)
		{
			pEmpleado = employee_findEmployeeById(pArrayListEmployee, id);
			if (pEmpleado != NULL)
			{
				index = ll_indexOf(pArrayListEmployee, pEmpleado);
				retorno = employee_removeEmployee(pArrayListEmployee, pEmpleado, index);
			}
			else
			{
				printf("No se encontro al empleado");
				retorno = -1;
			}
		}
		else
		{
			retorno = -1;
		}
	}
	else
	{
		printf("Asegurese de haber cargado el archivo en la lista. ");
	}

    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = -1;

	if (pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0) {
		retorno = employee_listEmployees(pArrayListEmployee);
	} else {
		printf("Primero debe abrir la lista de empleados");
	}

    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int opc;
	int order;
	retorno = -1;

	if (pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0) {
		printf("¿Qué tipo de ordenamiento desea realizar?\n1- Ordenar por nombre\n2- Ordenar por ID\n");

		retorno = utn_PedirEntero(&opc, "Ingrese el criterio de ordenamiento: ", "ERROR. Ingrese el criterio de ordenamiento: ", 1, 2, 5);

		if(retorno == 1)
		{
			printf("\nElija el modo de orden:\n1- Ascendente\n0- Descendente\n");
			retorno = utn_PedirEntero(&order, "Ingrese un orden: ", "Dato no valido, intente nuevamente", 0, 1, 5);
			if (retorno == 1)
			{
				printf("\nAguarde por favor...\n");
				if (opc == 1)
				{
					retorno = ll_sort(pArrayListEmployee, employee_CompareByName, order);
				}
				else
				{
					retorno = ll_sort(pArrayListEmployee, employee_CompareById, order);
				}
			}
			else
			{
				retorno = -1;
			}
		}
		else
		{
			retorno = -1;
		}
	}
	else
	{
		printf("Asegurese de haber cargado el archivo en la lista.");
	}

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pArch;
	retorno = -1;

	if (pArrayListEmployee != NULL && path != NULL && ll_isEmpty(pArrayListEmployee) == 0) {
		pArch = fopen(path, "w");
		if (pArch != NULL)
		{
			retorno = employee_addEmployeesToTextFile(pArch, pArrayListEmployee);
			fclose(pArch);
		}
	}
	else
	{
		printf("Asegurese de haber cargado el archivo en la lista. ");
	}

    return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE *pArch;
	retorno = -1;

	if (pArrayListEmployee != NULL && path != NULL && ll_isEmpty(pArrayListEmployee) == 0)
	{
		pArch = fopen(path, "wb");
		if (pArch != NULL)
		{
			retorno = employee_addEmployeesToBinaryFile(pArch, pArrayListEmployee);
			fclose(pArch);
		}
	}
	else
	{
		printf("Asegurese de haber cargado el archivo en la lista. ");
	}

    return retorno;
}

LinkedList* controller_InitEmployeeList(LinkedList* this)
{
	FILE *ultimoId;
	int len;

	this = ll_newLinkedList();
	if(this != NULL)
	{
		len = ll_len(this);
		ultimoId = fopen("ultimo id.txt", "w");
		fprintf(ultimoId, "%d", len);
		fclose(ultimoId);
	}


	return this;
}
