#include <iostream>

using namespace std;
int main(){
	size_t v1=42;
	auto f2=[&v1]{return v1;};
	auto j=f2();
	cout<<j<<endl;
	return 0;
}

