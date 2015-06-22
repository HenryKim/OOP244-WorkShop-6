#include <iostream>
#include <iomanip>
#include <cstring>
#include "Employee.h"
using namespace std;

Employee::Employee(){
	no=0;
	name=NULL;
	rate = MIN_Wage;
}//Safe Empty State

Employee::Employee(int n, const char* nm){
	Employee temp(n, nm, MIN_Wage);
	*this= temp;

}

Employee::Employee(int n, const char* nm, double r){
	if (n > 0 && nm[0] != '\0' && r >= MIN_Wage) {
		name = new char [strlen(nm) +1 ]; // dynamic memory allocation
		no = n ;
		strcpy (name,nm); 
		rate= r ;
	}
	else{
		Employee empty;
		*this = empty;
	}
}

Employee::Employee(const Employee& a){
	name = NULL;
	*this = a;
}//copy constructor;

Employee& Employee::operator = (const Employee& a){
		if (a.no > 0 && a.name[0] != '\0' && a.rate >= MIN_Wage){
				delete [] name;
				no = a.no;
				name = new char [strlen(a.name) +1];
				strcpy(name,a.name);
				rate=a.rate;
				}
		return *this;
}//copy constructor operator =;

bool operator>(const Employee& a, const Employee& b) {
	Employee x = a, y = b;
	if(strcmp(x.name,y.name)>0){//is after compare if value of a > b than return true;
		return true;
	}
	return false;
}//comparing
	istream& operator>>(istream& is, Employee& employee){
		employee.read(is);
	return is;  
}

void Employee :: read(istream& red){
		name = new char [1000];
		int flag =1;
		cout<<"ID :";
		red >> no;
		do{
		cout<<"Rate :";
		red>>rate;
		if(rate >=MIN_Wage){
			flag--;
		}
		else{
			cout<<"your rate is lower than minimum wage please enter again"<<endl;
		}
		}while(flag == 1);
		cout<<"Name: ";
		red.ignore(2000,'\n');
		red.getline(name,40);
}

ostream& operator<<(ostream& os, const Employee& employee){
	employee.display(os);
	return os;
}//out put;

void Employee::display(ostream& os) const{
	if (no > 0 && name[0] != '\0' && rate >= MIN_Wage) {
		os <<no<<"    "<<rate<<"  "<<name<<endl;
	}
	else{
			os << "no data available" << endl;

		}
}
Employee::~Employee(){
	if(name != NULL){
		delete [] name;
	}
}