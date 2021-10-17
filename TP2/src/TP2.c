/*
 ============================================================================
 Name        : TP2.c
 Author      : Ledesma Sergio
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo Practico N°2 - Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TAMEMPLEADOS 100

//define isEmpty
#define EMPTY 0
#define FULL 1



int main(void) {
	setbuf(stdout,NULL);
	Employee empleados[TAMEMPLEADOS];
	int retornoAuxiliar;
	int ultimoEmpleado;
	int opcion;

	ultimoEmpleado = 0;

	initEmployees(empleados, TAMEMPLEADOS);



	printf("/*****ABM Empleados*****/\n\n");

	do
	{
		opcion = -1;

		printf("1 - Agregar un nuevo empleado\n");
		printf("2 - Modificar un empleado\n");
		printf("3 - Eliminar un empleado\n");
		printf("4 - Informes\n");
		printf("0 - Salir\n\n");

		utn_PedirEntero(&opcion,"Escoja una opcion: ","Opcion incorrecta, ingrese una opcion valida\n",0,4,0);

		switch(opcion)
		{
			case 1:
				retornoAuxiliar = AgregarEmpleado(empleados,TAMEMPLEADOS,&ultimoEmpleado);

				if(retornoAuxiliar == 0)
				{
					printf("\nNo se pudo ingresar el empleado\n\n");
				}
				else
				{
					printf("\nEl empleado se ingreso correctamente\n\n");
				}
			break;
			case 2:
				if(VerificarListaEmpleados(empleados, TAMEMPLEADOS) != 1)
				{
					printf("\nNo hay empleados cargados\n\n");
				}
				else
				{
					retornoAuxiliar = printEmployees(empleados, TAMEMPLEADOS);

					if(retornoAuxiliar == 0)
					{
						retornoAuxiliar = ModificarEmpleado(empleados, TAMEMPLEADOS);

						if(retornoAuxiliar == 0)
						{
							printf("\nNo se pudieron realizar cambios\n\n");
						}
						else
						{
							if(retornoAuxiliar == -1)
							{
								printf("\nLa operacion fue cancelada\n\n");
							}
							else
							{
								printf("\nSe modifico exitosamente\n\n");
							}
						}
					}
				}
			break;
			case 3:
				if(VerificarListaEmpleados(empleados, TAMEMPLEADOS) != 1)
				{
					printf("\nNo hay empleados cargados\n\n");
				}
				else
				{
					retornoAuxiliar = printEmployees(empleados, TAMEMPLEADOS);

					if(retornoAuxiliar == 0)
					{
						retornoAuxiliar = EliminarEmpleado(empleados, TAMEMPLEADOS);

						if(retornoAuxiliar == 0)
						{
							printf("\nNo se pudo eliminar al empleado\n\n");
						}
						else
						{
							printf("\nEl empleado fue eliminado\n\n");
						}
					}
				}
			break;
			case 4:
				if(VerificarListaEmpleados(empleados, TAMEMPLEADOS) != 1)
				{
					printf("\nNo hay empleados cargados\n\n");
				}
				else
				{
					printf("\nInformes : \n");
					printf("1 - Ordenar empleados por Apellido y Sector\n");
					printf("2 - Informes de salarios (Total, promedio y cuantos superan el promedio\n");
					printf("3 - Cancelar\n\n");

					utn_PedirEntero(&opcion,"Escoja una opcion: ","Opcion incorrecta, ingrese una opcion valida\n",1,3,0);

					switch(opcion)
					{
						case 1:
							retornoAuxiliar = OrdenarEmpleados(empleados, TAMEMPLEADOS);

							if(retornoAuxiliar == 0)
							{
								printf("\nNo se pudo ordenar a los empleados\n\n");
							}
							else
							{
								printf("\nLista Ordenada : \n");
								printEmployees(empleados, TAMEMPLEADOS);
							}
						break;
						case 2:
							retornoAuxiliar = InformarTotalPromedioYSalariosMasAltos(empleados, TAMEMPLEADOS);

							if(retornoAuxiliar == 0)
							{
								printf("\nNo se pudo realizar el informe\n\n");
							}
							else
							{
								if(retornoAuxiliar == -1)
								{
									printf("\nLos empleados trabajan gratis (o en negro)\n\n");
								}
							}
						break;
						case 3:
							printf("\nOperacion Cancelada\n\n");
						break;
					}
				}

			break;
			case 0:
				printf("\n¡Hasta luego!\n\n");
			break;
		}

	}while(opcion != 0);


	return EXIT_SUCCESS;
}
