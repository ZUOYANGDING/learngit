#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	vector<string> v;
	string s;
	while(cin>>s)
		v.push_back(s);
	float sum;
	for(auto i : v)
		sum+=stof(i);
	cout<<sum<<endl;
	return 0;
}
