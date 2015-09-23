#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main(){
	vector<int> v;
	string s1;
	list<string> l;
	string s2;
	int a;
	getline(cin, s2);
	while(cin>>a>>s1){
		v.push_back(a);
		l.push_back(s1);
	}
	string test1="word";
	int test2=9;
	char test3='a';
	auto result1=count(v.begin(), v.end(), test2);
	auto result2=count(l.begin(), l.end(), test1);
	auto result3=count(s2.begin(), s2.end(), test3);
	cout<<"The string "<<test1<<" occured in list "<<result2<<" times"<<endl;
	cout<<"The int value "<<test2<<" occured in vector "<<result1<<" times"<<endl;
	cout<<"The char "<<test3<<" occured in string "<<result3<<" times"<<endl;
	return 0;
}
