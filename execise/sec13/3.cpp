#include <iostream>
#include <string>
using namespace std;

class numbered{
	public:
		numbered(){}
		numbered(string& s) : mysn(s){}
		numbered(const numbered& num){mysn=num.mysn;}
		numbered& operator=(const numbered& num){
			//mysn=num.mysn;
			mysn="do not have a dream";
			return *this;
		}
		void print(ostream& os){
			os<<mysn<<endl;
			return;
		}
	private:
		string mysn;
};

void f(numbered s){
	s.print(cout);
}

int main (){
	string s;
	getline(cin, s);
	numbered a(s);
	numbered b, c;
	b=a;
	c=a;
	f(a); f(b); f(c);
	return 0;
}

