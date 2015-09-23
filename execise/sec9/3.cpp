#include <iostream>
#include <string>
//#include <cctype>
using namespace std;

int main(){
	string s("ab2c3d7R4E6");
	string s1("1234567890");
	string s2(s);
	string::size_type pos=0;
	string::size_type c=0;
	while((pos=s.find_first_of(s1, pos))!=string::npos && pos<s.size()){
		cout<<"found the number at index "<<pos<<" the number is "<<s[pos]<<endl;
		s2.erase(pos-c, 1);
		++pos;
		++c;
	}
	pos=0;
	while((pos=s.find_first_not_of(s1, pos))!=string::npos && pos<s.size()){
		cout<<"found the alpha at index "<<pos<<" the aplha is "<<s[pos]<<endl;
		++pos;
	}
	cout<<s2<<endl;
	return 0;
}
