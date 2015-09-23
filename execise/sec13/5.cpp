#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Hasptr{
	public:
		Hasptr(const string& s, int i);
		Hasptr(const Hasptr&);
		Hasptr& operator=(const Hasptr&);
		~Hasptr();
	void print(ostream&);
	private:
		string* ps;
		int i;
};
Hasptr::Hasptr(const string& s, int a){
	//auto temp=new string(s);
	//ps=temp;
	ps=new string(s);
	i=a;
}
Hasptr::Hasptr(const Hasptr& h){
	//auto temp=new string(*h.ps);
	//ps=temp;
	ps=new string(*h.ps);
	i=h.i;
}
Hasptr& Hasptr::operator=(const Hasptr& h){
	if(ps!=NULL)
		delete ps;
	//auto temp=new string(*h.ps);
	//ps=temp;
	ps=new string(*h.ps);
	i=h.i;
	return *this;
}
Hasptr::~Hasptr(){
	delete ps;
}
void Hasptr::print(ostream& os){
	os<<*ps<<endl;
	os<<i<<endl;
}

int main(){
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int a=0, b=1;
	Hasptr A(s1, a);
	Hasptr B(s2, b);
	A.print(cout);
	B.print(cout);
	A=B;
	A.print(cout);
	return 0;
}
