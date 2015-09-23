#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

int main(){
	vector<string> v;
	string s;
	while(cin>>s)
		v.push_back(s);
	size_t a=v.size();
	allocator<string> alloc;
	auto p=alloc.allocate(a);
	auto q=uninitialized_copy(v.begin(), v.end(), p);
	for(size_t i=0; i!=a; ++i)
		cout<<*(p+i)<<endl;
	while(q!=p)
		alloc.destroy(--q);
	alloc.deallocate(p, a);
	return 0;
}
	
