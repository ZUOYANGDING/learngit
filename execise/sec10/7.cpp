#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool check_size(const string&, string::size_type);

int main(){
	vector<int> v;
	int a;
	string s;
	cin>>s;
	cin.ignore(1000, '\n');
	while(cin>>a)
		v.push_back(a);
	auto index=find_if(v.begin(), v.end(), bind(check_size, s,  placeholders::_1));
	auto index1=v.end()-index;
	cout<<index1<<endl;
	int b=3;
	return 0;
}

bool check_size(const string& s, string::size_type a){
	return s.size()<a;
}
