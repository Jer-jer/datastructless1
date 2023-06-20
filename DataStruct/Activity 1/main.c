#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

int main(int argc, char *argv[]) {
	List empList, femaleList;
	
	initList(&empList);
	displayEmployeeList(empList);
	
	addEmployee(&empList, newEmployee(1001, "Maria Dela Cruz", "female", 40.00f));
	addEmployee(&empList, newEmployee(1020, "Sabrinah Yap", "female", 80.00f));
	addEmployee(&empList, newEmployee(1001, "Noel Tagpuno", "male", 50.5f));
	
	addEmployee(&empList, newEmployee(1001, "Maria Dela Cruz", "male", 40.00f));
	addEmployee(&empList, newEmployee(1020, "Sabrinah Yap", "female", 80.00f));
	addEmployee(&empList, newEmployee(1001, "Noel Tagpuno", "female", 50.5f));
	displayEmployeeList(empList);
	
	femaleList = getFemaleEmployees(empList);
	printf("Female Employees: \n");
	displayEmployeeList(femaleList);
	return 0;
}
