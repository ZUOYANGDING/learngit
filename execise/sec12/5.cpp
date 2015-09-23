#include <iostream>
#include <string>
#include <memory>
#include <string.h>
using namespace std;

int main(){
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	string s3=s1+s2;
	size_t a=s3.size();
	char* s=new char[a];
	for(size_t i=0; i!=a; ++i)
		s[i]=s3[i];
	for(size_t i=0; i!=a; ++i)
		cout<<s[i];
	cout<<endl;
	delete []s;
	return 0;
}
