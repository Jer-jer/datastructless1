#ifndef EMPLOYEE_H
#define EMPLOYEE_H


typedef char String[20];

typedef struct {
	int idNumber;
	String name;
	String gender;
	float totalHoursWorked;
} HourlyEmployee, *EmployeeList;

typedef struct {
	EmployeeList employees;
	int count;
	int max;
} List;

HourlyEmployee newEmployee(int idNumber, String name, String gender, float totalHoursWorked);
void displayEmployee(HourlyEmployee employee);

void initList(List *list);
void addEmployee(List *list, HourlyEmployee emp); // Use insert rear
void displayEmployeeList(List list);
List getFemaleEmployees(List list);

#endif

