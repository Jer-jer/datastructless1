#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

HourlyEmployee newEmployee(int idNumber, String name, String gender, float totalHoursWorked){
	HourlyEmployee he;
	
	he.idNumber = idNumber;
	strcpy(he.name, name);
	strcpy(he.gender, gender);
	he.totalHoursWorked = totalHoursWorked;
	
	return he;
}
void displayEmployee(HourlyEmployee employee){
	printf("ID: %d\n", employee.idNumber);
	printf("NAME: %s\n", employee.name);
	printf("GENDER: %s\n", employee.gender);
	printf("HOURS WORKED: %.2f\n", employee.totalHoursWorked);
}

void initList(List *list){
	list->max = 2;
	list->employees = malloc(sizeof(HourlyEmployee) * list->max);
	list->count = 0;
}
void addEmployee(List *list, HourlyEmployee emp){
	if(list->count == list->max) {
		list->employees = realloc(list->employees, sizeof(HourlyEmployee) * list->max * 2);
		
		if(list->employees == NULL){
			printf("Something went wrong.\n");
		}else {
			list->max *= 2;
		}
	}

	list->employees[(list->count)++] = emp;
} // Use insert rear
void displayEmployeeList(List list){
	printf("%10s | %30s | %10s\n", "ID", "NAME", "GENDER");
	
	for(int i = 0; i < list.count; i++) {
		printf("%10d | %30s | %10s\n", list.employees[i].idNumber, list.employees[i].name, list.employees[i].gender);
	}
	
	printf("END OF LIST\n\n");
}
List getFemaleEmployees(List list){
	List femaleEmployees;
	initList(&femaleEmployees);
	
	for(int i = 0; i < list.max; i++){
		if(!strcmp(list.employees[i].gender, "female")){
			addEmployee(&femaleEmployees, newEmployee(list.employees[i].idNumber, list.employees[i].name, list.employees[i].gender, list.employees[i].totalHoursWorked));
		}
	}
	
	return femaleEmployees;
}


