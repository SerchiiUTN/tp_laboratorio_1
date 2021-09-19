/*
 * Funciones.c
 *
 *  Created on: 18 sep. 2021
 *      Author: Sergio
 */
#include "Funciones.h"

void menu(void)
{
	int opcion;
	int primerOperando;
	int segundoOperando;
	int flagOperandoUno;
	int flagOperandoDos;
	int flagCalculos;
	int suma;
	int resta;
	int multiplicacion;
	float division;
	int factorialA;
	int factorialB;



	flagOperandoUno = 0;
	flagOperandoDos = 0;
	flagCalculos = 0;



	do
	{
		if(flagOperandoUno == 0)
		{
			printf("1. Ingresar 1er operando (A=x)\n");
		}
		else
		{
			printf("1. Ingresar 1er operando (A=%d)\n",primerOperando);
		}
		if(flagOperandoDos == 0)
		{
			printf("2. Ingresar 2do operando (B=y)\n");
		}
		else
		{
			printf("2. Ingresar 2do operando (B=%d)\n",segundoOperando);
		}

		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);
		switch (opcion)
		{
		case 1:
			flagOperandoUno = 1;
			flagCalculos = 0;
			primerOperando = PedirEntero("Ingrese el 1er operando: ");

			break;
		case 2:
			flagOperandoDos = 1;
			flagCalculos = 0;
			segundoOperando = PedirEntero("Ingrese el 2do operando: ");

			break;
		case 3:
			if(flagOperandoUno == 0 || flagOperandoDos == 0)
			{
				printf("Ingrese ambos operandos antes de calcular\n");
			}
			else
			{
				printf("Realizando operaciones...\n");
				suma = SumarNumeros(primerOperando, segundoOperando);
				resta = RestarNumeros(primerOperando, segundoOperando);
				division = DividirNumeros(primerOperando, segundoOperando);
				multiplicacion = MultiplicarNumeros(primerOperando, segundoOperando);
				factorialA = Factorial(primerOperando);
				factorialB = Factorial(segundoOperando);
				flagCalculos = 1;
			}

			break;
		case 4:
			if(flagCalculos == 0)
			{
				printf("Realice los calculos antes de mostrarlos\n");
			}
			else
			{
				printf("\nResultados :\n\n");
				printf("a) El resultado de %d+%d es: %d\n",primerOperando,segundoOperando,suma);
				printf("b) El resultado de %d-%d es: %d\n",primerOperando,segundoOperando,resta);

				if(division == 0)
				{
					printf("No se puede dividir por cero\n");
				}
				else
				{
					printf("c) El resultado de %d/%d es: %.2f\n",primerOperando,segundoOperando,division);
				}

				printf("d) El resultado de %d*%d es: %d\n",primerOperando,segundoOperando,multiplicacion);

				if(primerOperando > 12)
				{
					printf("e) El resultado del factorial de A excede el permitido (12!)\n");
				}
				else
				{
					if(factorialA == 0)
					{
						printf("e) No se puede sacar el factorial de un numero negativo (%d)\n",primerOperando);
					}
					else
					{
						printf("e) El factorial de A (%d) es: %d\n",primerOperando,factorialA);
					}

				}

				if(segundoOperando > 12)
				{
					printf("Y El resultado del factorial de B excede el permitido (12!)\n\n");
				}
				else
				{
					if(factorialB == 0)
					{
						printf("Y No se puede sacar el factorial de un numero negativo (%d)\n\n",segundoOperando);
					}
					else
					{
						printf("Y el factorial de B (%d) es: %d\n\n",segundoOperando,factorialB);
					}

				}
			}

			break;
		case 5:
			printf("¡Hasta pronto!");
			break;
		default:
			printf("Opcion incorrecta. Intente nuevamente");
			break;
		}

	} while (opcion != 5);
}


int PedirEntero(char mensaje[])
{
    int numero;

    printf("%s",mensaje);
    scanf("%d",&numero);

    return numero;
}


int SumarNumeros(int numeroUno, int numeroDos)
{
	int resultado;

	resultado = numeroUno + numeroDos;


	return resultado;
}

int RestarNumeros(int numeroUno, int numeroDos)
{
	int resultado;

	resultado = numeroUno - numeroDos;


	return resultado;
}

int MultiplicarNumeros(int numeroUno, int numeroDos)
{
	int resultado;

	resultado = numeroUno * numeroDos;


	return resultado;
}

float DividirNumeros(int numeroUno, int numeroDos)
{
	float resultado;

	if(numeroUno == 0 || numeroDos == 0)
	{
		resultado = 0;
	}
	else
	{
		resultado = (float)numeroUno / numeroDos;
	}

	return resultado;
}

int Factorial(int numero)
{
	int factorial;
	int i;

	if(numero < 0)
	{
		factorial = 0;
	}
	else
	{
		factorial = 1;

		if(numero > 0)
		{
			for(i = numero; i > 0; i--)
			{
				factorial *= i;
			}
		}
	}

	return factorial;
}
