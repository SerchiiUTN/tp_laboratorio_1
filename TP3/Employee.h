#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#include "utn.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


Employee* employee_new();


void employee_delete(Employee* pEmpleado);


int employee_setId(Employee* this,int id);


int employee_getId(Employee* this,int* id);


int employee_setNombre(Employee* this,char* nombre);


int employee_getNombre(Employee* this,char* nombre);


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


int employee_setSueldo(Employee* this,int sueldo);


int employee_getSueldo(Employee* this,int* sueldo);


Employee* employee_setEmployee(Employee* employee, int id, char* nombre, int horasTrabajadas, int sueldo);


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


void employee_showEmployee(Employee* employee);


Employee* employee_findEmployeeById(LinkedList* this, int id);


int employee_addEmployeesToTextFile(FILE* pArch, LinkedList* pArrayListEmployee);


int employee_addEmployeesToBinaryFile(FILE* pArch, LinkedList* pArrayListEmployee);


int employee_listEmployees(LinkedList* pArrayListEmployee);


int employee_saveID(int id);


int employee_CompareByName(void* pEmp1, void* pEmp2);


int employee_CompareById(void* pEmp1, void* pEmp2);


Employee* employee_AddNewEmployee(int ultimoId);

int employee_editEmployee(LinkedList* pArrayListEmployee, Employee* pEmp, Employee* pAux);

int employee_Options();

int employee_removeEmployee(LinkedList* pArrayListEmployee, Employee* employee, int index);

Employee* employee_copyEmployeeToEmployeeAux(Employee* employee);

#endif // employee_H_INCLUDED
