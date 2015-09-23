#include <iostream>
#include <vector>

using namespace std;

struct X{
	X(){cout<<"X()"<<endl;}
	X(const X&){cout<<"X(const X&)"<<endl;}
	X& operator=(const X&){
		cout<<"X& operator=(const X&)"<<endl;
		return *this;
	}
	~X(){cout<<"~X()"<<endl;}
};

void foo(const X& cx, X bx, const X& dx){
	vector<X> v;
	v.reserve(3);//prereserve space for the elements, without this line, vector need to resize
				 //everytime, which means from the second time of push_back, constructor need
				 //to be called, and after push_back, the destructor also need to be called.
				 //which can be seen with the following code
	//cout<<"first push back"<<endl;
	v.push_back(cx);
	//cout<<"second push back"<<endl;
	v.push_back(bx);
	//cout<<"third push back"<<endl;
	v.push_back(dx);
}

int main(){
	X* x1=new X;
	X x2, x3;
	x2=*x1;
	x3=*x1;
	foo(*x1, x2, x3);
	delete x1;
	return 0;
}
