#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void judge_l(vector<string>&);
bool judge_s(const string&);
int main(){
	vector<string> v;
	string s;
	while(cin>>s)
		v.push_back(s);
	judge_l(v);
	for(auto& i : v)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}

void judge_l(vector<string>& v){
	auto index=partition(v.begin(), v.end(), judge_s);
	v.erase(index, v.end());
}

bool judge_s(const string& s){
	return s.size()>=5;
}
