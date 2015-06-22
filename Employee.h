#include <iostream>
#define MAX_NAME 40
#define MIN_Wage 10.25
using namespace std;
class Employee{
	int no;
	char *name;
	double rate;
public:
	Employee ();
	Employee(int n, const char *nm);
	Employee(int n, const char* nm, double r);
	Employee(const Employee& a);
	Employee& operator = (const Employee&);
	friend bool operator>(const Employee& a, const Employee& b);
	friend istream& operator>>(istream& is, Employee& employee);
	friend ostream& operator<<(ostream& os, const Employee& employee);
	void read(istream&is);
	void display(ostream&os) const;
	~Employee();
};
	