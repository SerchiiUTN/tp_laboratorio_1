#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	char idStr[100];
	char nombreStr[128];
	char horasTrabajadasStr[100];
	char sueldoStr[100];
	int rta;
	Employee* employee;
	retorno = -1;

	if (pFile != NULL && pArrayListEmployee != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
	    while(!feof(pFile)) {
	    	rta = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
	    	if (rta != 4) {
	    		retorno = -1;
	    		break;
	    	}
			employee = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
			if (employee == NULL) {
				retorno = -1;
				break;
			}
			retorno = ll_add(pArrayListEmployee, employee);
			if (retorno != 0) {
				employee_delete(employee);
				retorno = -1;
				break;
			}
	    }
	}

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	int rta;
	Employee* pEmpleado;
	retorno = -1;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
	    while(!feof(pFile)) {
	    	pEmpleado = employee_new();
	    	if (pEmpleado == NULL) {
	    		retorno = -1;
	    		break;
	    	}
	    	rta = fread(pEmpleado, sizeof(Employee), 1, pFile);

	    	if (rta != 1)
	    	{
	    		if (feof(pFile))
	    		{
	    			retorno = 0;
	    		}
	    		else
	    		{
		    		retorno = -1;
	    		}
	    		break;
	    	}
	    	retorno = ll_add(pArrayListEmployee, pEmpleado);

	    	if(retorno != 0)
	    	{
	    		employee_delete(pEmpleado);
	    		break;
	    	}
	    }
	}

    return retorno;
}

int parser_LoadIDFromText()
{
	int id;
	char idChar[9];
	FILE *fUltimoId;

	id = -1;

	fUltimoId = fopen("ultimo id.txt", "r");

	if(fUltimoId != NULL)
	{
		strcpy(idChar, fgets(idChar, 9, fUltimoId));

		if(idChar != NULL)
		{
			id = atoi(idChar);
		}
		fclose(fUltimoId);
	}

	return id;

}
