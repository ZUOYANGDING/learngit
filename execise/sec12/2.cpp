#include <iostream>
#include <vector>
#include <memory>
using namespace std;

shared_ptr<vector<int>> create(){
	return make_shared<vector<int>>();
}

void print(shared_ptr<vector<int>> v){
	for(auto i : *v)
		cout<<i<<endl;
}

int main(){
	shared_ptr<vector<int>> v=create();
	int a;
	while(cin>>a)
		(*v).push_back(a);
	print(v);
	//delete v;
	return 0;
}
