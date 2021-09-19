/*
 * Funciones.h
 *
 *  Created on: 18 sep. 2021
 *      Author: Sergio
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void menu(void);

int PedirEntero(char mensaje[]);
int SumarNumeros(int numeroUno, int numeroDos);
int RestarNumeros(int numeroUno, int numeroDos);
float DividirNumeros(int numeroUno, int numeroDos);
int MultiplicarNumeros(int numeroUno, int numeroDos);
int Factorial(int numero);

#endif /* FUNCIONES_H_ */
