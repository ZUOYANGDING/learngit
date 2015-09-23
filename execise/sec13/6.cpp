#include <iostream>
#include <string>
#include <memory>

using namespace std;

class HasPtr{
	public:
		HasPtr(const string&, int);
		HasPtr(const HasPtr&);
		HasPtr& operator=(const HasPtr&);
		void print(ostream&);
		~HasPtr();
	private:
		string* str;
		int i;
		size_t* count;
};
HasPtr::HasPtr(const string& s, int a){
	str=new string(s);
	i=a;
	count=new size_t(1);
}
HasPtr::HasPtr(const HasPtr& temp){
	if(str!=NULL && *count==1){
		delete str;
		delete count;
		str=NULL;
		count=NULL;
	}else if(str!=NULL && *count>1)
		--(*count);
	str=temp.str;
	++(*temp.count);
	count=temp.count;
	i=temp.i;
}
HasPtr& HasPtr::operator=(const HasPtr& temp){
	if(str!=NULL && *count==1){
		delete str;
		delete count;
		str==NULL;
		count==NULL;
	}else if(str!=NULL && *count>1)
		--(*count);
	str=temp.str;
	i=temp.i;
	++(*temp.count);
	count=temp.count;
	return *this;
}
HasPtr::~HasPtr(){
	if(count!=NULL && --(*count)==0){ //must be --(*count)==0, if use (*count)>=1,
									//pointers in h1 or h4 will be free two times
		delete str;
		delete count;
		str=NULL;
		count=NULL;
	}
}
void HasPtr::print(ostream& os){
	os<<*str<<endl;
	os<<i<<endl;
	os<<*count<<endl;
}

int main(){
	int a, b, c;
	a=1; b=2; c=3;
	HasPtr h1("I have a dream", a);
	HasPtr h2("I do not have a dream", b);
	HasPtr h3("I really do not have a good dream", c);
	cout<<"The original value:\n"<<endl;
	h1.print(cout);
	h2.print(cout);
	h3.print(cout);
	HasPtr h4(h1);
	h2=h3;
	cout<<"The new value:\n"<<endl;
	h1.print(cout);
	h2.print(cout);
	h3.print(cout);
	h4.print(cout);
	return 0;
}

