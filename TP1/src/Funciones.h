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

/// @fn void menu(void)
/// @brief Menu principal de la calculadora
///
void menu(void);

/// @fn int PedirEntero(char[])
/// @brief Pide un entero y lo retorna
/// @param mensaje Mensaje que muestra a la hora de pedir el numero
/// @return Retorna el entero ingresado
int PedirEntero(char mensaje[]);

/// @fn int SumarNumeros(int, int)
/// @brief Suma dos enteros y retorna un entero
///
/// @param numeroUno Primer entero a sumar
/// @param numeroDos Segundo entero a sumar
/// @return Retorna el resultado de la suma entre el primer y segundo entero
int SumarNumeros(int numeroUno, int numeroDos);

/// @fn int RestarNumeros(int, int)
/// @brief Resta dos enteros y retorna un entero
///
/// @param numeroUno Primer entero a restar
/// @param numeroDos Segundo entero a restar
/// @return Retorna el resultado de la resta entre el primer y segundo entero
int RestarNumeros(int numeroUno, int numeroDos);

/// @fn float DividirNumeros(int, int)
/// @brief Divide entre dos enteros y retorna el resultado, si alguno de los enteros es 0 retorna 0
///
/// @param numeroUno Ingresa el dividendo
/// @param numeroDos Ingresa el divisor
/// @return Retorna el resultado de la division, si alguno de los numeros es 0 retorna 0
float DividirNumeros(int numeroUno, int numeroDos);

/// @fn int MultiplicarNumeros(int, int)
/// @brief Multiplica dos enteros y retorna el resultado
///
/// @param numeroUno Primer factor
/// @param numeroDos Segundo factor
/// @return Devuelve el resultado entre los dos factores
int MultiplicarNumeros(int numeroUno, int numeroDos);

/// @fn int Factorial(int)
/// @brief Calcula el factorial de un entero y retorna el resultado, si el numero es negativo retorna 0
///
/// @param numero Numero a factorizar
/// @return Resultado del factorial, si el numero es negativo retorna 0
int Factorial(int numero);

#endif /* FUNCIONES_H_ */
