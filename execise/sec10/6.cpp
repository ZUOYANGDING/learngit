#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	vector<int> v;
	int a;
	while(cin>>a)
		v.push_back(a);
	for(auto& i : v){
		auto k=[&i] ()->bool{
			if(i==0)
				return true;
			else if(i<0){
				i*=-1;
				while(i!=0)
					i--;
			}else{
				while(i!=0)
					i--;
			}
		};
		if(k())
			cout<<"this is 0"<<endl;
		else
			cout<<"this is not 0"<<endl;
	}
	for(auto&i : v)
		cout<<i<<endl;
	return 0;
}



