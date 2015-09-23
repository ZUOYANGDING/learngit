#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void eli_dup(vector<string>&);
bool is_longer(const string&, const string&);
int main(){
	vector<string> v;
	string s;
	while(cin>>s)
		v.push_back(s);
	eli_dup(v);
	stable_sort(v.begin(), v.end(), is_longer);
	for(auto& i: v)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}

void eli_dup(vector<string>& v){
	sort(v.begin(), v.end());
	auto dup=unique(v.begin(), v.end());
	v.erase(dup, v.end());
}

bool is_longer(const string& s1, const string& s2){
	return s1.size()>s2.size();
}
