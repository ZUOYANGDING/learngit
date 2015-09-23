#include <iostream>
#include <forward_list>
#include <string>
using namespace std;
void match_insert(forward_list<string>& f, string& a, string& b){
	auto index0=f.before_begin();
	int signal=0;
	for(auto index1=f.begin(); index1!=f.end(); ++index1){
		if(*index1==a){
			index1=f.insert_after(index1, b);
			signal=1;
		}
		index0=index1;
	}
	if (signal==0)
		f.insert_after(index0, b);
}

int main(){
	forward_list<string> f;
	string a, b, c;
	cin>>a;
	cin.ignore(10000, '\n');
	cin>>b;
	cin.ignore(10000, '\n');
	while(cin>>c)
		f.push_front(c);
	match_insert(f, a, b);
	for(auto i: f)
		cout<<i<<" ";
	cout<<endl;
	return 0;

}
