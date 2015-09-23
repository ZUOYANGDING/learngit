#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

int main(){
	int a;
	list<int> l;
	while(cin>>a)
		l.push_front(a);
	auto index=find(l.crbegin(), l.crend(), 0);
	for(auto it=(--index.base()); it!=l.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
	return 0;
}
