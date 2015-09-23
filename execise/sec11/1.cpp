#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	//vector<string> child;
	map<string, vector<string>> m;
	string name;
	for(int i=0; i!=5; i++){
		getline(cin, name);
		auto index=find(name.begin(), name.end(), ' ');
		string family(name.begin(), index);
		string c_name(++index, name.end());
		m[family].push_back(c_name);
	}
	for(auto& i : m){
		cout<<"Family name: "<<i.first<<"\n";
		cout<<"Children name: ";
		for(auto& j : i.second)
			cout<<j<<" ";
		cout<<"\n";
	}
	return 0;
}

