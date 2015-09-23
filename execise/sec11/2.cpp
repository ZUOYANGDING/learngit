#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int main(){
	string s;
	int a;
	pair<string, int> p;
	vector<pair<string, int>> v;
	for(int i=0; i!=10; i++){
		cin>>s>>a;
		p={s, a};
		v.push_back(p);
	}
	for(auto& i : v)
		cout<<i.first<<" "<<i.second<<endl;
	return 0;
}
