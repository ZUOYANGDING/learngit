#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<string, vector<string>> PAIR;

bool compare_fun(PAIR& a, PAIR& b){
	return (*(a.second.begin()))[0]<(*(b.second.begin()))[0];
}

int main(){
	multimap<string, vector<string>> mul;
	string line;
	for(int i=0; i!=5; i++){
		getline(cin, line);
		string author, work;
		vector<string> temp;
		auto index=find(line.begin(), line.end(), ' ');
		author={line.begin(), index};
		work={++index, line.end()};
		temp.push_back(work);
		mul.insert(PAIR(author, temp));
	}
	
	vector<PAIR> p;
	for(auto i=mul.begin(); i!=mul.end(); i++)
		p.push_back(*i);
	auto index=p.begin();
	while(index!=p.end()){
		auto index1=index;
		while(((*index1).first==(*index).first) && (index1!=p.end()))
			index1++;
		sort(index, index1, compare_fun);
		index=index1;
	}
	/*
	//the previous execise
	string target;
	cout<<"print the target name:"<<endl;
	getline(cin, target);
	auto signal=mul.equal_range(target);
	if (signal.first==signal.second)
		cout<<"There is not author "<<target<<endl;
	else
		mul.erase(signal.first, signal.second);
	for(auto& i : mul){
		cout<<"Author: "<<i.first<<"\n";
		cout<<"work: ";
		for(auto& j : i.second)
			cout<<j<<" ";
		cout<<"\n";
	}*/
	for(auto& i : p){
		cout<<"Author: "<<i.first<<"\n";
		cout<<"works: ";
		for(auto& j : i.second)
			cout<<j<<" ";
		cout<<"\n";
	}
	return 0;
}
