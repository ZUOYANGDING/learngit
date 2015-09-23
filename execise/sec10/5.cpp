#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

void biggies(vector<string>&, vector<string>::size_type);
void elim_dup(vector<string>&);

int main(){
	vector<string> v;
	string s;
	vector<string>::size_type sz;
	cin>>sz;
	cin.ignore(INT_MAX, '\n');
	while(cin>>s)
		v.push_back(s);
	biggies(v, sz);
	return 0;
}

void elim_dup(vector<string>& v){
	sort(v.begin(), v.end());
	auto index=unique(v.begin(), v.end());
	v.erase(index, v.end());
	stable_sort(v.begin(), v.end(), [](const string& a, const string& b){return a.size()>b.size();});
}


void biggies(vector<string>& v, vector<string>::size_type sz){
	elim_dup(v);
	auto index=partition(v.begin(), v.end(), [sz](const string& s){return s.size()>=sz;});
	for(auto i=v.begin(); i!=index; i++)
		cout<<*i<<" ";
	cout<<endl;
}
