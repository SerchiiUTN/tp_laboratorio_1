/*
 * parser.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Sergio
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


int parser_LoadIDFromText();

#endif /* PARSER_H_ */
