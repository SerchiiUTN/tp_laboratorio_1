/*
 * utn.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Sergio
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/// @fn int myGets(char[], int, char[])
/// @brief  Guarda un texto ingresado por el usuario
///
/// @param cadena -> String donde se guarda el texto
/// @param tam -> Largo del string
/// @param mensaje -> Mensaje que se muestra al usuario antes de ingresar el texto
/// @return -> Devuelve 1 si pudo copiar el texto, sino devuelve 0
int myGets(char cadena[],int tam,char mensaje[]);

/// @fn int esNumerica(char[])
/// @brief Verifica si una cadena es numerica
///
/// @param cadena -> Cadena a verificar
/// @return -> Retorna 1 si la cadena esta compuesta por numeros, sino retorna 0
int esNumerica(char cadena[]);


/// @fn int esFlotante(char[])
/// @brief Verifica si una cadena es float
///
/// @param cadena -> Cadena a verificar
/// @return -> Retorna 1 si la cadena es un float, sino retorna 0
int esFlotante(char cadena[]);

/// @fn int esNombreOApellido(char[])
/// @brief Verifica si una cadena es un nombre o apellido
///
/// @param cadena -> Cadena a verificar
/// @return -> Retorna 1 (OK) o 0 (No es un nombre/apellido)
int esNombreOApellido(char cadena[]);

/// @fn int esCuit(char[])
/// @brief Verifica si la cadena es un CUIT
///
/// @param cadena -> Cadena a verificar
/// @return -> Retorna 1 si es un CUIT, sino retorna 0
int esCuit(char cadena[]);

/// @fn int ConvertirNombreOApellido(char[])
/// @brief Convierte el texto en Propel Case
///
/// @param cadena -> Cadena a convertir
/// @return -> Retorna 1 (OK) o 0 (No pudo convervir el texto)
int ConvertirNombreOApellido(char cadena[]);

/// @fn int getInt(int*, char[])
/// @brief Pide un texto ingresado por el usuario y si es numerico lo guarda
/// 	   en un entero
///
/// @param numero -> Direccion de memoria donde guardara el numero
/// @param mensaje -> Mensaje a mostrar a la hora de pedir el numero
/// @return -> Retorna 1 si pudo guardar el numero, sino retorna 0
int getInt(int* numero, char mensaje[]);

/// @fn int getFloat(float*, char[])
/// @brief Pide un float que guarda en una cadena, valida si es un numero flotante
/// 	   y de ser asi lo guarda en un float
///
/// @param flotante -> Direccion de memoria donde se guardara el flotante
/// @param mensaje -> Mensaje a mostrar al pedir el valor
/// @return -> Retorna 1 si pudo guardar el numero, sino retorna 0
int getFloat(float* flotante, char mensaje[]);

/// @fn int getString(char[], int, char[])
/// @brief Pide un texto al usuario y si es valido lo guarda en una cadena
///
/// @param string -> Cadena donde se guardara el texto
/// @param tam -> Tamaño de la cadena
/// @param mensaje -> Mensaje a mostrar al pedir el texto
/// @return -> Retorna 1 si se pudo guardar el texto, sino retorna 0
int getString(char string[], int tam,char mensaje[]);

/// @fn int getNombreOApellido(char[], int, char[])
/// @brief Pide un nombre o apellido y si es valido lo guarda en la cadena
///
/// @param cadena -> Cadena a guardar el texto
/// @param tam -> Tamaño de la cadena
/// @param mensaje -> Mensaje a mostrar al pedir el texto
/// @return -> Retorna 1 (OK) o 0 (No pudo guardar el nombre)
int getNombreOApellido(char cadena[], int tam, char mensaje[]);

/// @fn int getCuit(char[], int, char[])
/// @brief Pide un CUIT al usuario y si es valido lo guarda en una cadena
///
/// @param cadena -> Cadena donde se guardara el cuit
/// @param tam -> Tamaño de la cadena
/// @param mensaje -> Mensaje a mostrar al pedir el valor
/// @return -> Retorna 1 si se pudo guardar el CUIT, sino retorna 0
int getCuit(char cadena[], int tam, char mensaje[]);

/// @fn int PedirEntero(int*, char[], char[], int, int, int)
/// @brief Pide un numero al usuario, valida si es numerico y
/// 	   si esta dentro de los parametros lo guarda en un int
///
/// @param numero -> Direccion de memoria donde guardara el entero
/// @param mensaje -> Mensaje a mostrar al pedir el entero
/// @param error -> Mensaje a mostrar si el valor es incorrecto
/// @param minimo -> Valor minimo que puede tener el entero
/// @param maximo -> Valor maximo que puede tener el entero
/// @param reintentos -> Cantidad de reintentos para ingresar el valor
/// @return -> Retorna 1 si pudo guardar el entero, sino retorna 0
int utn_PedirEntero(int* numero, char mensaje[], char error[], int minimo, int maximo, int reintentos);

/// @fn int PedirFlotante(float*, char[], char[], int, int, int)
/// @brief Pide un numero al usuario, valida si es flotante y
/// 	   si esta dentro de los parametros lo guarda en un float
///
/// @param flotante -> Direccion de memoria donde guardara el flotante
/// @param mensaje -> Mensaje a mostrar a pedir el flotante
/// @param error -> Mensaje a mostrar si el valor es incorrecto
/// @param minimo -> Valor minimo que puede tener el flotante
/// @param maximo -> Valor maximo que puede tener el flotante
/// @param reintentos -> Cantidad de reintentos para ingresar el valor
/// @return -> Retorna 1 si pudo guardar el flotante, sino retorna 0
int utn_PedirFlotante(float* flotante, char mensaje[], char error[], float minimo, float maximo, int reintentos);

/// @fn int PedirTexto(char[], int, char[], char[], int)
/// @brief Pide un texto al usuario y si puede validarlo lo guarda en una cadena
///
/// @param texto -> Cadena donde se guardara el texto
/// @param tam -> Tamaño de la cadena
/// @param mensaje -> Mensaje a mostrar al pedir el texto
/// @param error -> Mensaje a mostrar si el valor es incorrecto
/// @param reintentos -> Cantidad de reintentos para ingresar el valor
/// @return -> Retorna 1 si se guardo sin problemas, -1 si el valor ingresado
/// 		   es mayor al largo de la cadena o 0 si no pudo guardar el texto
int utn_PedirTexto(char texto[],int tam, char mensaje[], char error[], int reintentos);

/// @fn int utn_PedirNombreOApellido(char[], int, char[], char[], int)
/// @brief Pide un nombre o apellido, valida que sean caracteres y
/// 		los convierte
///
/// @param texto -> Cadena donde se guarda el nombre o apellido
/// @param tam -> Tamaño de la cadena
/// @param mensaje -> Mensaje a mostrar al pedir el texto
/// @param error -> Mensaje de error si el valor no es correcto
/// @param reintentos -> Cantidad de reintentos
/// @return -> Retorna 1 (OK), 0 (No se pudo guardar) o -1 (El valor
/// 			ingresado supera el largo de la cadena)
int utn_PedirNombreOApellido(char texto[],int tam, char mensaje[], char error[], int reintentos);

/// @fn int utn_PedirCuit(char[], int, char[], char[], int)
/// @brief Pide un CUIT al usuario y si puede validarlo lo guarda en una cadena
///
/// @param cuit -> Cadena donde se guardara el cuit
/// @param tam -> Tamaño de la cadena
/// @param mensaje -> Mensaje a mostrar al pedir el cuit
/// @param error -> Mensaje a mostrar si el valor es incorrecto
/// @param reintentos -> Cantidad de reintentos para ingresar el valor
/// @return -> Retorna 1 si se guardo sin problemas, -1 si el valor ingresado
/// 		   es mayor al largo de la cadena o 0 si no pudo guardar el cuit
int utn_PedirCuit(char cuit[], int tam, char mensaje[], char error[], int reintentos);

#endif /* UTN_H_ */
