#include "Employee.h"


Employee *employee_new()
{
	Employee* pEmpleado;

	pEmpleado = (Employee*) malloc(sizeof(Employee));

    return pEmpleado;
}



void employee_delete(Employee* pEmpleado)
{
	if(pEmpleado != NULL)
	{
		free(pEmpleado);
	}
}


int employee_setId(Employee* this, int id)
{
    int returnAux = 0;

    if (id >= 0 && this != NULL)
    {
        this->id = id;
        returnAux = 1;
    }
    return returnAux;
}

int employee_getId(Employee* this,int* id)
{
	int returnAux = 0;

	if (id != NULL && this != NULL)
	{
		*id = this->id;
		returnAux = 1;
	}
	return returnAux;
}


int employee_setNombre(Employee* this,char* nombre)
{
	int returnAux = 0;

	if (strlen(nombre) > 0 && this != NULL)
	{
		strncpy(this->nombre, nombre, 50);

		returnAux = 1;
	}
	return returnAux;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int returnAux = 0;

	if (strlen(this->nombre) > 0 && this != NULL)
	{
		strncpy(nombre, this->nombre, 50) ;

		returnAux = 1;
	}
	return returnAux;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int returnAux = 0;

	if(this != NULL)
	{
		if (horasTrabajadas>= 0 && horasTrabajadas<500)
		{
			this->horasTrabajadas = horasTrabajadas;
			returnAux = 1;
		}
		else
		{
			printf("\n\nEl dato ingresado es incorrecto\n\n");
		}
	}
	return returnAux;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int returnAux = 0;

	if (horasTrabajadas != NULL && this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		returnAux = 1;
	}
	return returnAux;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int returnAux = 0;

	if (sueldo> 0  && this != NULL)
	{
		this->sueldo = sueldo;
		returnAux = 1;
	}
	return returnAux;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int returnAux = 0;

	if (sueldo != NULL && this != NULL)
	{
		*sueldo = this->sueldo;
		returnAux = 1;
	}
	return returnAux;
}

Employee* employee_setEmployee(Employee* employee, int id, char* nombre, int horasTrabajadas, int sueldo)
{
	if(employee != NULL && id > 0 && nombre != NULL && horasTrabajadas >= 0 && sueldo >= 0)
	{
		employee_setId(employee,id);
		employee_setNombre(employee,nombre);
		employee_setHorasTrabajadas(employee,horasTrabajadas);
		employee_setSueldo(employee,sueldo);
	}


	return employee;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	int idAux;
    int horasTrabajadasAux;
    int sueldoAux;
    Employee* pEmployee = employee_new();


    if(pEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
    	idAux = atoi(idStr);
        employee_setId(pEmployee, idAux);

        employee_setNombre(pEmployee, nombreStr);

        horasTrabajadasAux = atoi(horasTrabajadasStr);
        employee_setHorasTrabajadas(pEmployee, horasTrabajadasAux);

        sueldoAux = atoi(sueldoStr);
        employee_setSueldo(pEmployee,sueldoAux);
    }
    return pEmployee;
}

void employee_showEmployee(Employee* employee)
{
	int id;
	int sueldo;
	int horas;
	char nombre[32];

	if (employee != NULL)
	{
		employee_getId(employee, &id);

		employee_getNombre(employee, nombre);

		employee_getHorasTrabajadas(employee, &horas);

		employee_getSueldo(employee, &sueldo);

		printf("%-5d - %-32s - %-5d - %d \n", id, nombre, horas, sueldo);

	}

}


Employee* employee_findEmployeeById(LinkedList* this, int id)
{
	Employee* pEmpleado;

	pEmpleado = NULL;

	if(this != NULL)
	{
		pEmpleado = (Employee*) ll_get(this,id);
	}

	return pEmpleado;
}

int employee_addEmployeesToTextFile(FILE* pArch, LinkedList* pArrayListEmployee)
{
	int retorno;
	int i;
	int id;
	char nombre[128];
	int sueldo;
	int horas;
	int len;
	Employee* employee;
	retorno = -1;

	if(pArch != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		fprintf(pArch, "id,nombre,horasTrabajadas,sueldo\n");

		for(i = 0; i < len; i++)
		{
			employee = (Employee*) ll_get(pArrayListEmployee, i);
			if (employee == NULL)
			{
				break;
			}

			employee_getId(employee, &id);
			employee_getNombre(employee, nombre);
			employee_getHorasTrabajadas(employee, &horas);
			employee_getSueldo(employee, &sueldo);
			fprintf(pArch, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
		}

		if(i == len)
		{
			retorno = 0;
		}

	}

	return retorno;
}

int employee_addEmployeesToBinaryFile(FILE* pArch, LinkedList* pArrayListEmployee)
{
	int retorno;
	int len;
	int i;
	Employee* pEmpleado;

	retorno = -1;

	if(pArch != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		for(i = 0; i < len; i++)
		{
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

			if (pEmpleado == NULL)
			{
				break;
			}

			fwrite(pEmpleado, sizeof(Employee), 1, pArch);
		}

		if (i == len)
		{
			retorno = 0;
		}

	}

	return retorno;
}

int employee_listEmployees(LinkedList* pArrayListEmployee)
{
	int retorno;
	int i;
	int len;
	Employee* pEmpleado;

	retorno = -1;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		printf("ID-Nombre-HorasTrabajadas-Sueldo\n\n");

		for(i = 0; i < len; i++)
		{
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

			if (pEmpleado == NULL)
			{
				break;
			}

			employee_showEmployee(pEmpleado);
		}

		if (i == len)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int employee_saveID(int id)
{
	int retorno;
	retorno = 0;
	id++;

	FILE *ultimoId;
	ultimoId = fopen("ultimo id.txt", "w");
	retorno = fprintf(ultimoId, "%d", id);
	fclose(ultimoId);

	return retorno;
}

int employee_CompareByName(void* pEmp1, void* pEmp2)
{
	int retorno;
	Employee* pEmpleado1;
	Employee* pEmpleado2;
	char nombre1[128];
	char nombre2[128];
	retorno = -2;

	if (pEmp1 != NULL && pEmp2 != NULL)
	{
		pEmpleado1 = (Employee*) pEmp1;
		pEmpleado2 = (Employee*) pEmp2;

		employee_getNombre(pEmpleado1, nombre1);
		employee_getNombre(pEmpleado2, nombre2);

		retorno = strcmp(nombre1, nombre2);
	}

	return retorno;
}

int employee_CompareById(void* pEmp1, void* pEmp2)
{
	int retorno;
	int idUno;
	int idDos;
	Employee* pEmpleado1;
	Employee* pEmpleado2;
	pEmpleado1 = (Employee*) pEmp1;
	pEmpleado2 = (Employee*) pEmp2;
	retorno = -2;

	if(pEmp1 != NULL && pEmp2 != NULL)
	{
		pEmpleado1 = (Employee*) pEmp1;
		pEmpleado2 = (Employee*) pEmp2;

		employee_getId(pEmpleado1, &idUno);
		employee_getId(pEmpleado2, &idDos);

		if(idUno > idDos)
		{
			retorno = 1;
		}
		else
		{
			if(idUno < idDos)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}



Employee* employee_AddNewEmployee(int ultimoId)
{
	Employee* pEmpleado;
	int horasAux;
	int sueldoAux;
	char nombre[32];

	pEmpleado = (Employee*) malloc(sizeof(Employee));

	if(
			pEmpleado != NULL 	&& 		ultimoId > 0																				&&
			utn_PedirEntero(&horasAux,"Ingrese las horas trabajadas: ","Error, el dato es incorrecto",0,20000000,2) == 1 			&&
			utn_PedirEntero(&sueldoAux,"Ingrese el sueldo del empleado: ","El valor ingresado es incorrecto",0,20000000,2) == 1 	&&
			utn_PedirNombreOApellido(nombre,sizeof(nombre),"Ingrese el nombre del empleado: ","El dato ingresado es incorrecto",2) == 1
		)
	{
		employee_setEmployee(pEmpleado, ultimoId, nombre, horasAux, sueldoAux);
	}


	return pEmpleado;
}



//----------------------------------


int employee_editEmployee(LinkedList* pArrayListEmployee, Employee* pEmp, Employee* pAux)
{
	int retorno;
	int opcion;
	char nombre[128];
	int auxInt;
	int confirmacion;
	retorno = -1;

	if (pArrayListEmployee != NULL && pEmp != NULL && pAux != NULL) {
		opcion = employee_Options();

		switch(opcion) {
		case 1:
			retorno = utn_PedirNombreOApellido(nombre, sizeof(nombre), "Ingrese el nuevo nombre del empleado: ", "ERROR. Ingrese el nuevo nombre del empleado: ", 2);
			if (retorno == 1) {
				employee_setNombre(pAux, nombre);
			}
			break;
		case 2:
			retorno = utn_PedirEntero(&auxInt, "Ingrese la nueva cantidad de horas trabajadas: ", "ERROR. Ingrese la nueva cantidad de horas trabajadas (mayor que 0): ", 0, 20000000, 2);
			if (retorno == 1) {
				retorno = employee_setHorasTrabajadas(pAux, auxInt);
			}
			break;
		case 3:
			retorno = utn_PedirEntero(&auxInt, "Ingrese el nuevo sueldo del trabajador (entero): ","ERROR. Ingrese el nuevo sueldo del trabajador (entero y mayor que cero): ", 1, 20000000, 2);
			if (retorno == 1) {
				retorno = employee_setSueldo(pAux, auxInt);
			}
			break;
		}

		if (retorno == 1) {
			retorno = utn_PedirEntero(&confirmacion, "¿Seguro que desea realizar esta modificacion?\n1.Si\n2.No\nRespuesta: ", "ERROR.",1,2, 2);
			if (retorno == 1 && confirmacion == 1)
			{
				auxInt = ll_indexOf(pArrayListEmployee, pEmp);
				retorno = ll_set(pArrayListEmployee, auxInt, pEmp);
			} else {
				if (confirmacion == 2) {
					retorno = -2;
				} else {
					retorno = -1;
				}
			}
		} else {
			retorno = -1;
		}
	}

	return retorno;
}

int employee_Options()
{
	int retorno;
	int opcion;

	printf("Elija que desea modificar:\n1- Nombre\n2- Horas trabajadas\n3- Sueldo\n");

	retorno = utn_PedirEntero(&opcion, "Ingrese una opcion : ", "Incorrecto, intente nuevamente ", 1, 3, 2);

	if(retorno == 0)
	{
		opcion = 0;
	}

	return opcion;
}

int employee_removeEmployee(LinkedList* pArrayListEmployee, Employee* employee, int index)
{
	int retorno;
	int confirmacion;
	retorno = -1;

	if (pArrayListEmployee != NULL && employee != NULL) {
		printf("--Empleado a eliminar--\n");
		printf("ID   - Nombre                          - HorasTrabajadas - Sueldo\n");
		employee_showEmployee(employee);
		retorno = utn_PedirEntero(&confirmacion, "¿Seguro que desea realizar esta modificacion?\n1.Si\n2.No\nRespuesta: ", "ERROR.",1,2, 2);
		if(retorno == 1 && confirmacion == 1)
		{
			retorno = ll_remove(pArrayListEmployee, index);
		}
		else
		{
			if (confirmacion == 2)
			{
				retorno = -2;
			}
			else
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

Employee* employee_copyEmployeeToEmployeeAux(Employee* employee)
{
	char nombre[128];
	int id;
	int horasTrabajadas;
	int sueldo;
	Employee* pAux;

	pAux = NULL;

	if (employee != NULL)
	{
		pAux = employee_new();
		if (pAux != NULL)
		{
			employee_getId(employee, &id);
			employee_getNombre(employee, nombre);
			employee_getHorasTrabajadas(employee, &horasTrabajadas);
			employee_getSueldo(employee, &sueldo);

			employee_setId(pAux, id);
			employee_setNombre(pAux, nombre);
			employee_setHorasTrabajadas(pAux, horasTrabajadas);
			employee_setSueldo(pAux, sueldo);
		}
	}

	return pAux;
}
