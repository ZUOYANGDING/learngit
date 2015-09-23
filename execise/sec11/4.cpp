#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

int main(){
	string name;
	map<string, vector<string>> m;
	for(int i=0; i!=5; ++i){
		string family, child;
		vector<string> temp;
		getline(cin, name);
		auto index=find(name.begin(), name.end(), ' ');
		family={name.begin(), index};
		child={++index, name.end()};
		temp.push_back(child);
		auto r=m.insert(pair<string, vector<string>>(family, temp));
		if(!r.second)
			(r.first->second).push_back(child);
	}
	for(auto& i : m){
		cout<<"Family name: "<<i.first<<"\n";
		cout<<"Children name: "<<" ";
		for(auto& j : i.second)
			cout<<j<<" ";
		cout<<"\n";
	}
	return 0;
}

