#include <iostream>
//#include <vector>
#include <map>
#include <utility>
#include <string>

using namespace std;

int main(){
	map<string, size_t> m;
	string word;
	while(cin>>word){
		auto r=m.insert(pair<string, size_t>(word, 1));
		if (!r.second)
			++((r.first)->second);
	}
	for(auto& i : m)
		cout<<i.first<<" occurs "<<i.second<<(i.second>1 ? " times" : " time")<<endl;
	return 0;
}
