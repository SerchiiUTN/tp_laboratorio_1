#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
    int option;
    int retorno;
    LinkedList* listaEmpleados = NULL;

    listaEmpleados = controller_InitEmployeeList(listaEmpleados);


	printf("--Nomina de Empleados--\n\n");

    do
    {

    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    	printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
		printf("3. Alta de empleado\n");
		printf("4. Modificar datos de empleado\n");
		printf("5. Baja de empleado\n");
		printf("6. Listar empleados\n");
		printf("7. Ordenar empleados\n");
		printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
		printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
		printf("0. Salir\n\n");

    	retorno = utn_PedirEntero(&option, "Ingrese una opción: ","",0,9,0);

    	printf("\n");

        if (retorno == 1)
        {
            switch(option)
            {
                case 1:
                    retorno = controller_loadFromText("data.csv", listaEmpleados);

                    if(retorno == 0)
                    {
                    	printf("Se ha cargado el archivo de texto\n");
                    }

                    break;

                case 2:
                	retorno = controller_loadFromBinary("data.bin", listaEmpleados);

                    if(retorno == 0)
                    {
                    	printf("Se ha cargado el archivo binario\n");
                    }

                	break;

                case 3:
                	retorno = controller_addEmployee(listaEmpleados);

                    if(retorno == 0)
                    {
                    	printf("Se cargo el empleado.\n");
                    }

                	break;

                case 4:
                	retorno = controller_editEmployee(listaEmpleados);

                    if(retorno == 0)
                    {
                    	printf("Empleado modificado.\n");
                    }
                    else
                    {
                    	if(retorno == -1)
                    	{
                    		printf("No se ha podido modificar el empleado\n");
                    	}
                    	else
                    	{
                    		printf("Se ha cancelado el proceso.\n");
                    	}
                    }

                	break;

                case 5:
                	retorno = controller_removeEmployee(listaEmpleados);

                    if(retorno == 0)
                    {
                    	printf("Se ha eliminado al empleado.\n");
                    }
                    else
                    {
                    	if(retorno == -1)
                    	{
                        	printf("No se ha podido eliminar al empleado\n");
                    	}
                    	else
                    	{
                    		printf("Se ha cancelado el proceso.\n");
                    	}
                    }

                	break;

                case 6:
                	retorno = controller_ListEmployee(listaEmpleados);

                    if(retorno != 0)
                    {
                    	printf("No se pudo listar\n");
                    }

                	break;

                case 7:
                	retorno = controller_sortEmployee(listaEmpleados);

                    if(retorno == 0)
                    {
                    	printf("Se han ordenado a los empleados\n");
                    }
                    else
                    {
                    	printf("Fallo el proceso\n");
                    }

                	break;

                case 8:
                	retorno = controller_saveAsText("data.csv", listaEmpleados);

                    if(retorno == 0)
                    {
                    	printf("Se guardaron los cambios en el archivo de texto\n");
                    }
                    else
                    {
                    	printf("Todo lo que podia fallar, falló\n");
                    }

                	break;

                case 9:
                	retorno = controller_saveAsBinary("data.bin", listaEmpleados);

                    if(retorno == 0)
                    {
                    	printf("Se guardaron los cambios en el archivo binario\n");
                    }
                    else
                    {
                    	printf("Todo lo que podia fallar, falló\n");
                    }

                	break;

                case 0:
                	printf("¡Hasta Luego!\n");

                	ll_deleteLinkedList(listaEmpleados);

                	break;

                default:
                	printf("Opcion incorrecta, intente nuevamente.\n");
                	break;
            }
        }
        else
        {
        	printf("Debe ingresar solo numeros\n");
        }

        printf("\n");

    }while(option != 0);

    return 0;
}
