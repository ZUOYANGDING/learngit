#include <iostream>
#include <string>

using namespace std;

class Employee{
	public:
		Employee(){
			id=increment++;
		}
		Employee(const string& s) : name(s) {
			id=increment++;
		}
		Employee(const Employee& em){
			name=em.name;
			id=increment++;
		}
		void print(ostream&);
		~Employee()=default;
	private:
		string name;
		int id;
		static int increment;
};
void Employee::print(ostream& os){
	os<<"The name is "<<name<<endl;
	os<<"The ID is "<<id<<endl;
}
int Employee::increment=0;
int main(){
	Employee A;
	Employee B("wang");
	Employee C(B);
	A.print(cout);
	B.print(cout);
	C.print(cout);
	return 0;
}
